#include "WorldMapTroopInstance.h"
#include "Base/Utils/Utils3D.h"
#include "Module/Player/Player.Top.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/WorldMap.Util.h"

WorldMapTroopInstance* WorldMapTroopInstance::Create(Size pSize)
{
  auto lTarget = GDisplay::Get()->NewNode() ;
  lTarget->setContentSize(pSize);
  lTarget->setAnchorPoint(Vec2(0.5, 0.5));
  lTarget->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
  auto lView = CreateBaseView(pSize, false, lTarget);
  lView->Ctor();
  return lView;
}

void WorldMapTroopInstance::Ctor()
{
  UIBaseView::Ctor();
  setVisible(false);
  setAnchorPoint(Vec2(0.5, 0.5));
  _SoliderNode = GDisplay::Get()->NewNode();
  _SoliderNode->retain();
}

void WorldMapTroopInstance::InitData(
  Vec2 pBeginPoint, Vec2 pEndPoint, Vec2 pBeginTilePoint,
  Vec2 pEndTilePoint, RMoveLineArmyData pData){
  _BeginPoint = pBeginPoint;
  _EndPoint = pEndPoint;
  _BeginTilePoint = pBeginTilePoint;
  _EndTilePoint = pEndTilePoint;
  _ArmyData = pData;
};

void WorldMapTroopInstance::BeginMove(float pDelayTime, bool pUpdate){
  auto lDistanceX = _EndPoint.x - _BeginPoint.x;
  auto lDistanceY = _EndPoint.y - _BeginPoint.y;
  auto lTime = 0;
  auto lDistancePrecent = 0.f;
  auto lCurrentPoint = _BeginPoint;
  auto lIsBegin = false;
  auto lIsAddFirst = false;

  
  GVector<LRMoveData> lMoveDataArray;
  for(auto lV : _MoveTimeSpan){
    _TotalMoveTime += lV._Time;
    lTime += lV._Time;
    if(!lIsBegin && lTime >= _CurrentMoveTime){
      auto lCurrentPointX = _BeginPoint.x + lDistanceX * lDistancePrecent + lDistanceX * lV._DistancePrecent * ((_CurrentMoveTime - (lTime - lV._Time)) / lV._Time);
      auto lCurrentPointY = _BeginPoint.y + lDistanceY * lDistancePrecent + lDistanceY * lV._DistancePrecent * ((_CurrentMoveTime - (lTime - lV._Time)) / lV._Time);
      auto lCurrentPoint = Vec2(lCurrentPointX, lCurrentPointY);
      lIsBegin = true;
      lIsAddFirst = true;
      lDistancePrecent += lV._DistancePrecent;
      LRMoveData lMoveData;
      lMoveData._Point = Vec2(_BeginPoint.x + lDistanceX * lDistancePrecent, _BeginPoint.y + lDistanceY * lDistancePrecent);
      lMoveData._Time = lV._Time - _CurrentMoveTime;
      lMoveDataArray.push_back(lMoveData);
      lDistancePrecent -= lV._DistancePrecent;
    }
    
    lDistancePrecent += lV._DistancePrecent;
    if(lIsAddFirst)
      lIsAddFirst = false;
    else if(lIsBegin){
      LRMoveData lMoveData;
      lMoveData._Point = Vec2(_BeginPoint.x + lDistanceX * lDistancePrecent, _BeginPoint.y + lDistanceY * lDistancePrecent);
      lMoveData._Time = lV._Time;
      lMoveDataArray.push_back(lMoveData);
    }
  }
  
  auto lLeftMoveTime = _TotalMoveTime - _CurrentMoveTime;
  if(!pUpdate){
    setPosition(lCurrentPoint);
  }
  
  Vector<FiniteTimeAction*> lActionsArray;
  auto iii = 0;
  for(auto iMoveData : lMoveDataArray){
    if(iMoveData._Time > 0){
      Vec2 lPrePoint;
      if(iii == 0){
        lPrePoint = Vec2(getPositionX(), getPositionY());
      }else{
        lPrePoint = lMoveDataArray[iii - 1]._Point;
      }
      
      lActionsArray.pushBack(CallFunc::create([=](){
        runAction(MoveTo::create(iMoveData._Time, iMoveData._Point));
        auto lDistance = lPrePoint.distance(iMoveData._Point);
        auto lSpeed = lDistance / iMoveData._Time;
        _MoveLine->UpdateMoveLineSpeed(lSpeed);
      }));
      lActionsArray.pushBack(DelayTime::create(iMoveData._Time));
    }
  }
  lActionsArray.pushBack(DelayTime::create(10));
  lActionsArray.pushBack(CallFunc::create([=](){
    FinishWork(0);
  }));
  
  auto lActions = Sequence::create(lActionsArray);
  stopAllActions();
  if (lActions)
    runAction(lActions);
}

void WorldMapTroopInstance::BeginWork(){
  setPosition(_EndPoint);
  _MoveLine->setVisible(false);
  if(_LodNode)
    _LodNode->setVisible(false);
  
  static RRemoveTroopTipData sRemoveTroopTipData;
  sRemoveTroopTipData._MoveLineID = _MoveLineID;
  sRemoveTroopTipData._MapMoveToTilePoint = _EndTilePoint;
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_TROOPTIP", &sRemoveTroopTipData);
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_TROOPBINDINGPANEL");
  stopAllActions();
}

void WorldMapTroopInstance::FinishWork(float pDelayTime){
  static RRemoveTroopTipData sRemoveTroopTipData;
  sRemoveTroopTipData._MoveLineID = _MoveLineID;
  sRemoveTroopTipData._MapMoveToTilePoint = _EndTilePoint;
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_TROOPTIP", &sRemoveTroopTipData);
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_TROOPBINDINGPANEL");
  static GTuple<int32, float> sTuple;
  sTuple = GTuple<int32, float>(_MoveLineID, pDelayTime);
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_MOVELINE", &sTuple);
}

GTuple<GVector<LRMoveData>, float> WorldMapTroopInstance::GetMapMoveDataArray(){
  auto lDistanceX = _EndPoint.x - _BeginPoint.x;
  auto lDistanceY = _EndPoint.y - _BeginPoint.y;
  auto lCurrentPoint = getPosition();
  auto lCurrentDistancePrecent = 1.f;
  if(lDistanceX != 0){
    lCurrentDistancePrecent = (lCurrentPoint.x - _BeginPoint.x) / lDistanceX;
  }else if(lDistanceY != 0){
    lCurrentDistancePrecent = (lCurrentPoint.y - _BeginPoint.y) / lDistanceY;
  }
  
  bool lIsBegin = false;
  bool lIsAddFirst = false;
  float lDistancePrecent = 0.f;
  Vec2 lPreSpanPoint = lCurrentPoint;
  Vec2 lCurrentSpanPoint;
  float lLeftTime = 0.f;
  GVector<LRMoveData> lMoveDataArray;
  for(auto lV : _MoveTimeSpan){
    lDistancePrecent += lV._DistancePrecent;
    if(!lIsBegin && lCurrentDistancePrecent <= lDistancePrecent){
      lIsBegin = true;
      lIsAddFirst = true;
    }
    
    if(lIsBegin){
      lCurrentPoint.x = _BeginPoint.x + lDistanceX * lDistancePrecent;
      lCurrentPoint.y = _BeginPoint.y + lDistanceY * lDistancePrecent;
      auto lMoveTime = lV._Time;
      if(lIsAddFirst){
        lIsAddFirst = false;
        lMoveTime = lV._Time * (lDistancePrecent - lCurrentDistancePrecent) / lV._DistancePrecent;
      }

      LRMoveData lMoveData;
      lMoveData._Point = lPreSpanPoint - lCurrentPoint;
      lMoveData._Time = lMoveTime;
      lMoveDataArray.push_back(lMoveData);
      lPreSpanPoint = lCurrentPoint;
      lLeftTime += lMoveTime;
    }
  }
  return {lMoveDataArray, lLeftTime};
}

void WorldMapTroopInstance::ViewOnClick(Ref *pSender, Widget::TouchEventType type){
  if(type == Widget::TouchEventType::ENDED)
    OnMovelineClick();
}

void WorldMapTroopInstance::SetUserData(const RMoveLineUserData &pData){
  _UserData = pData;
  _PlayerID = pData._PlayerID;
  _IsMainQueue = pData._IsMainQueue;
  _IsRecall = pData._IsRecall;
  _IsLegendLord = pData._IsLegendLord;
  _IsLegendLordForSep = pData._IsLegendLordForSep;
  _EffectId = pData._EffectId;
  _HasJoin = pData._HasJoin;
  _LeagueID = pData._LeagueID;
  _MoveLineType = pData._MoveLineType;
  _MoveLineColor = pData._MoveLineColor;
  _MoveLineModel = pData._MoveLineModel;
  _MarchArmyEffectId = pData._MarchArmyEffectId;
  _Emoji = pData._Emoji;
  _MatrixState = pData._MatrixState;
  _OrgQueueId = pData._OrgQueueId;
  _ToObjectType = pData._ToObjectType;
  if(_EffectId != EWorldMapCastleEffectID::None){
    _IsKing = _EffectId == EWorldMapCastleEffectID::King_Troop_ID;
  }

  if(pData._CommandHallTaskType != ECommandHallTaskType::None){
    _CommandHallTaskType = pData._CommandHallTaskType;
  }
}

void WorldMapTroopInstance::SetMoveTimeData(const RMoveTimeData &pData){
  if(pData._MoveTimeSpan.size())
    _MoveTimeSpan = pData._MoveTimeSpan;
  if(pData._CurrentMoveTime){
    _CurrentMoveTime = pData._CurrentMoveTime;
    if(_CurrentMoveTime < 0)
      _CurrentMoveTime = 0;
  }
}

void WorldMapTroopInstance::SetMoveLineColor(EMapMoveLineColor pColor){
  if(pColor == EMapMoveLineColor::None)
    return;
  _MoveLineColor = pColor;
  _MoveLine->SetMoveLineColor(_MoveLineColor);
  if(_SoldierLod){
    auto lColor = WorldMapDefine::Get()->GetMoveLineColor(_MoveLineColor);
    _SoldierLod->setColor(lColor);
  }
}

void WorldMapTroopInstance::SetMatrixState(EMapMoveLineStatusType pState, float pDelayTime, bool pUpdate){
  _MatrixState = pState;
  if(_MatrixState == EMapMoveLineStatusType::Moving){
    BeginMove(pDelayTime, pUpdate);
  }
  else if(_MatrixState == EMapMoveLineStatusType::Working){
    BeginWork();
  }
  else if(_MatrixState == EMapMoveLineStatusType::Finished){
    FinishWork(pDelayTime);
  }
}

bool WorldMapTroopInstance::CheckClickMoveLine(Vec2 pPos){
  if(_UserData._IsNOClick)
    return false;
  if(!isVisible())
    return false;
    
  if(!_ClickRect){
    auto lSwitchWidth = 0;
    auto lSwitchHeight = 0;
    auto lSize = GetTroopContentSize();
    if(WorldMapUtil::Get()->IsTroopPriority() && lSize.width < 200){
      lSwitchWidth = 50;
      lSwitchHeight = 50;
    }
    _ClickRect = Rect(0, 0, lSize.width + lSwitchWidth, lSize.height + lSwitchHeight);
  }
  
  auto lPosNode = GBase::ConvertTouchToNodeSpace2DOr3D(_SoliderNode, pPos);
  if(_ClickRect->containsPoint(Vec2(lPosNode.value().x, lPosNode.value().y))){
    GBase::PlaySound("worldmap", 4);
    OnMovelineClick();
    return true;
  }
  return false;
}

void WorldMapTroopInstance::OnMovelineClick(){
  GBase::DSendMessage("MESSAGE_WORLD_MAP_SHOW_TROOPTIP", &_MoveLineID);
}

void WorldMapTroopInstance::ToggleClickPriority(){
  if(_ClickRect)
    _ClickRect = {};
}

void WorldMapTroopInstance::InitCheckVisible(){
  auto lSize = GetTroopContentSize();
  auto lOffset = lSize.width + 50;
  _Rect = Rect(-lOffset, -lOffset, GDisplay::Get()->width + 2 * lOffset, GDisplay::Get()->height + 2 * lOffset);
  _CurTimerNum = 0;
  _CurTimerMax = 1;
  UpdateCheckVisible();
}

void WorldMapTroopInstance::UpdateCheckVisible(){
  _CurTimerNum++;
  if(_CurTimerNum >= _CurTimerMax){
    auto lPosWorld = convertToWorldSpace(Vec2(0, 0));
    auto lIsVisible = _Rect.containsPoint(lPosWorld);
    SetSoliderVisible(lIsVisible);
    _CurTimerNum = 0;
  }
}

void WorldMapTroopInstance::SetSoliderVisible(bool pIsVisible){
  auto lIsRunning = _SoliderNode->isRunning();
  if(pIsVisible == lIsRunning)
    return;
  if(pIsVisible){
    if(!lIsRunning){
      if(!_SoliderNode->getParent()){
        addChild(_SoliderNode);
      }
      _CurTimerMax = 30;
      _CurTimerNum = 0;
    }
  }else if(lIsRunning){
    _SoliderNode->removeFromParentAndCleanup(false);
    _CurTimerMax = 10;
    _CurTimerNum = 0;
  }
}

void WorldMapTroopInstance::onExit(){
  ui::Layout::onExit();
  RemoveSoliderNode();
}

void WorldMapTroopInstance::RemoveSoliderNode(){
  if(_SoliderNode){
    if(!_SoliderNode->getParent())
      _SoliderNode->removeFromParentAndCleanup(false);
    _SoliderNode = nullptr;
  }
}

void WorldMapTroopInstance::SetEmojiID(int32 pEmojiID){
  _EmojiID = pEmojiID;
  if(_EmojiID && _EmojiID > 0){
    ShowEmoji(_EmojiID);
  }else if(_EmojiID == 0){
    HideEmoji();
  }
}

bool WorldMapTroopInstance::IsHasEmoji(){
  return _EmojiID > 0;
}

bool WorldMapTroopInstance::CanHasEmojiOperator(int32 pPlayerID){
  if(!pPlayerID){
    pPlayerID = PlayerTop::Get()->GetPlayerID();
  }
  return _PlayerID == pPlayerID;
}

void WorldMapTroopInstance::ShowEmoji(int32 pEmojiID){
  AddEmoji(pEmojiID);
}

void WorldMapTroopInstance::AddEmoji(int32 pEmojiID, GOpt<Vec2> pPos){
  if(!_WorldMapEmoji){
    _WorldMapEmoji = UIWorldMapEmoji::Create();
    if(!pPos){
      auto lSize = GetTroopContentSize();
      pPos = Vec2(lSize.width * 0.5, lSize.height * 0.5);
    }
    _WorldMapEmoji->setPosition(pPos.value());
    if(GGlobal::Get()->gEnableWorldMap3D)
      _WorldMapEmoji->setRotation3D(GGlobal::Get()->gWorldMapRotation3DBack);
    else 
      _WorldMapEmoji->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
    addChild(_WorldMapEmoji, 9);
    //   self.worldMapEmoji:setGroupID(GROU_ID.group_moveline_particle)
    //   self.worldMapEmoji:setGroupAuto(true)
    _WorldMapEmoji->SetEmoji(pEmojiID);
    _WorldMapEmoji->ShowAction(true);
  }else{
    _WorldMapEmoji->SetEmoji(pEmojiID);
    _WorldMapEmoji->ShowAction(true);
  }
}

void WorldMapTroopInstance::HideEmoji(){
  if(!_WorldMapEmoji)
    return;
  auto lSeq = Sequence::create(
    CallFunc::create([=](){
      _WorldMapEmoji->HideAction();
    }),
    DelayTime::create(1),
    CallFunc::create([=](){
      _WorldMapEmoji->removeFromParent();
      _WorldMapEmoji = nullptr;
    }),
    nullptr
  );
  _WorldMapEmoji->runAction(lSeq);
}

void WorldMapTroopInstance::UpdateModelState(float pScale){
  if(_IsLod && !_LodNode){
    CreateTroopIcon(pScale);
    SwitchMoveLineModel(_IsLod);
  }
}

void WorldMapTroopInstance::CreateTroopIcon(float pScale){
  if(_LodNode)
    return;
  _LodNode = Sprite::create("lod_marchingQueue.png");
  addChild(_LodNode, 10);
  _SoldierLod = _LodNode;
  if(_MoveLineColor != EMapMoveLineColor::None){
    auto lColor = WorldMapDefine::Get()->GetMoveLineColor(_MoveLineColor);
    _SoldierLod->setColor(lColor);
  }
  if(pScale)
    _LodNode->setScale(pScale);
  // sprite:setGroupID(GROU_ID.group_moveline_lodicon)
}

bool WorldMapTroopInstance::SwitchMoveLineModel(bool pIsLod, bool pForce){
  _IsLod = pIsLod;
  if(_IsLod){
    _SoliderNode->setVisible(false);
    if(_LodNode){
      if(pForce){
        CreateTroopIcon();
        _LodNode->setVisible(true);
      }else {
        return true;
      }
    }else{
      _LodNode->setVisible(true);
    }
  }else{
    _SoliderNode->setVisible(true);
    if(_LodNode){
      _LodNode->setVisible(false);
    }
  }
  return false;
}

bool WorldMapTroopInstance::IsSelfTroop(int32 pPlayerID){
  if(_HasJoin)
    return true;
  if(!pPlayerID)
    pPlayerID = PlayerTop::Get()->GetPlayerID();
  return _PlayerID == pPlayerID;
}
