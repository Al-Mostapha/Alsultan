#include "WorldMapCommandHallNpc.h"
#include "Base/Utils/XTransition.h"
#include "Module/City/City.Ctrl.h"
#include "Module/City/CityBuilding/CommandHall/CommandHall.Util.h"
#include "Module/City/CityBuilding/CommandHall/CommandHall.Read.h"

void WorldMapCommandHallNpc::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapCommandHallNpc::_InitData(){
  // self.statue = gMapObjStateTypeDef.gMapObjStateTypeFree
  // self.framesNumber = 16
  // self.framesTimes = 0.06666666666666667
  // self.taskID = 0
  // self.imgNameAngle = nil
  // self.isFlipX = nil
}

void WorldMapCommandHallNpc::_InitUI(){
  _NpcImage = GDisplay::Get()->NewSprite("bhmt_dj_ws.png");
  addChild(_NpcImage, -1);
  _TaskNode = CommandHallUtil::Get()->CreateTaskNode();
  addChild(_TaskNode);
  _TaskNode->setPosition(_CenterPoint + Vec2(0, 70));
  _TaskNode->setScale(0.75f);
}

void WorldMapCommandHallNpc::OnMessageListener() {}

void WorldMapCommandHallNpc::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {}

void WorldMapCommandHallNpc::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID) {
  if(!pObjData) return;
  auto lData = (RUnitCommandHallNpcInit *)pObjData;

  _TaskIndex = lData->_TaskIndex;
  if(lData->_TaskID != ECommandHallTaskType::None){
    _TaskID = lData->_TaskID;
    _TaskNode->SetTaskID(_TaskID);
    
    auto lTaskType = CommandHallRead::Get()->GetTaskType(_TaskID);
    _ImgName = CommandHallRead::Get()->GetTaskNpcResource(lTaskType);

    if(_ImgName.find(".png") != GString::npos){
      _IsBuild = true;
      _NpcImage->setSpriteFrame(_ImgName);
    }else{
      _IsBuild = false;
      _NpcImage->setSpriteFrame(_ImgName + "_dj_ws_01.png");
    }

    if(lTaskType == ECommandHallTaskType::RESCUE_TASK){
      _NpcImage->setPosition(-10, 0);
      _NpcImage->setScale(0.8f);
    }else if(lTaskType == ECommandHallTaskType::SNIPE_HUNTER_TASK){
      _NpcImage->setPosition(-10, 30);
    }

    if(lTaskType == ECommandHallTaskType::RESCUE_TASK){
      _TaskNode->setPosition(Vec2(0, 80));
    }else if(lTaskType == ECommandHallTaskType::REBEL_ARMY_PIONEER_TASK){
      _TaskNode->setPosition(Vec2(0, 90));
    }
  }
  
  _IsFlipX = lData->_IsFlipX;
  UpdateData(*lData);
}

void WorldMapCommandHallNpc::PlayClickSound() {}

void WorldMapCommandHallNpc::AddCacheBefore() {}

void WorldMapCommandHallNpc::UpdateData( const RUnitCommandHallNpcInit &pData){
  _Statue = pData._Statue;
  UpdateStatue();
}

void WorldMapCommandHallNpc::UpdateStatue(){
  if(_IsBuild) return;
  if(_Statue == EMapObjStateTypeDef::Free){
    DoStandingAnimation();
  }else if(_Statue == EMapObjStateTypeDef::HurtDie){
    DoDieingAnimation();
  }
}

void WorldMapCommandHallNpc::DoStandingAnimation(){
  DoStopAllActions();
  auto lFrames = GDisplay::Get()->NewFrames((_ImgName + "_dj_ws_%02d.png").c_str(), 1, _FramesNumber);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
  XTransition::Get()->PlayAnimationForever(_NpcImage, lAnimation);
  _NpcImage->setFlippedX(_IsFlipX);
}

void WorldMapCommandHallNpc::DoDieingAnimation(){
  DoStopAllActions();
  auto lFrames = GDisplay::Get()->NewFrames((_ImgName + "_sw_ws_%02d.png").c_str(), 1, _FramesNumber);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, _FramesTimes);
  XTransition::Get()->PlayAnimationOnce(
    _NpcImage, lAnimation, false, 
    CC_CALLBACK_0(WorldMapCommandHallNpc::FinishedAfterDead, this), 0);
}

void WorldMapCommandHallNpc::FinishedAfterDead(){
  auto lSeq = Sequence::create(
    DelayTime::create(1),
    CallFunc::create([this](){
      GBase::DSendMessage( "MESSAGE_COMMANDHALL_NPC_UPDATE"/*
      {
        // msg = "MESSAGE_COMMANDHALL_NPC_UPDATE",
        // msgType = gMapSyncMsgType.REMOVE_MAPOBJ,
        // data = {instance = self}
      }**/);
    }),
    nullptr
  );
  runAction(lSeq);
}

void WorldMapCommandHallNpc::DoStopAllActions(){
  _NpcImage->stopAllActions();
}

void WorldMapCommandHallNpc::AddFireEffect(GTime pTimeEffect, const RUnitCommandHallNpcInit &pData){
  auto lFacePoint = CityCtrl::Get()->GetCurCityPos();
  BeginAttack(lFacePoint);
  auto lSeq = Sequence::create(
    DelayTime::create(pTimeEffect),
    CallFunc::create([this, pData](){
      UpdateData(pData);
    }),
    nullptr
  );
  _NpcImage->runAction(lSeq);
}

void WorldMapCommandHallNpc::BeginAttack(Vec2 pFacePoint){
  // local worldMapView = SoraDCurrentSceneShowView("worldMapView")
  // if worldMapView then
  //   facePoint = worldMapView:getPointWithTile(facePoint)
  // end
  // local pointX, pointY = self:getPosition()
  // local beginPoint = cc.p(pointX, pointY)
  // local endPoint = facePoint
  // local rotation, fightingImgNameAngle, isFlipX = worldMapFunction.getMonsterImgAngel(beginPoint, endPoint)
  // self.npcImage:setFlippedX(isFlipX)
  // self.fightingFrames = display.newFrames(self.imgName .. "_gj_" .. fightingImgNameAngle .. "_%02d.png", 1, self.framesNumber)
  // self:doStopAllActions()
  // self:doFightingAnimation()
  // SoraDPlaySound("worldmap", 3)
}

void WorldMapCommandHallNpc::DoFightingAnimation(){
  // local animation = display.newAnimation(self.fightingFrames, self.framesTimes)
  // self.npcImage:playAnimationOnce(animation, false, function()
  //   self:doFightingAnimation()
  // end)
}

GTuple<UIBasePanel *, bool, Node*> WorldMapCommandHallNpc::OnClickInstance(Node *pNode) {
  //   local kingdomMapCell = kingdomMapCtrl:getKingdomMapCell()
  // if kingdomMapCell:hasFromUserCommandHallQueue(self.taskIndex, nil) then
  //   SoraDShowMsgTip(i18n("commandhall_text_74"))
  //   return nil, false
  // end
  // local taskType = commandHallRead.getTaskType(self.taskID)
  // if taskType == gCommandHallTaskType.SNIPE_HUNTER_TASK and kingdomMapCell:hasFromUserCommandHallQueue(nil, taskType) then
  //   SoraDShowMsgTip(i18n("commandhall_text_77"))
  //   return nil, false
  // end
  // local selectShowPanel = include("worldMapCommandHallNpcView").new(self)
  // selectShowPanel:setAnchorPoint(cc.p(0.5, 0))
  // selectShowPanel:setPosition(cc.p(display.width / 2, display.iPhoneXBottom))
  // selectShowPanel:setTilePoint(cc.p(self.tilePoint.x, self.tilePoint.y))
  // selectShowPanel:initData(self)
  // selectShowPanel:upateInfoPanel(self.taskID, self.taskIndex)
  // selectShowPanel:show()
  // return selectShowPanel, true
}

uint32 WorldMapCommandHallNpc::GetTaskIndex(){
  return _TaskIndex;
}
