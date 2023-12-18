#include "WorldMapBattery.h"
#include "Engine/OS.h"
#include "Base/Base.create.h"
#include "Base/Math/Math.Base.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/WorldMap.Func.h"
#include "Module/Building/Config/PalaceInfo.Read.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Base/Utils/XTransition.h"
#include "Base/Common/Common.Func.h"
#include "Module/City/City.Ctrl.h"

void WorldMapBattery::Ctor() {
  _BulletZOrder = GMath::Floor(Vec2(1200, 1200).distance(Vec2(0, 0))) + 5;
  _InitUI();
  _InitData();
}

void WorldMapBattery::_InitData(){

}

void WorldMapBattery::_InitUI(){

  _NodeMode = GDisplay::Get()->NewNode();
  _BaseImage = GDisplay::Get()->NewSprite("paotai_base.png");
  _ModelImage = GDisplay::Get()->NewSprite("paotai_dj_n_01.png");
  _ModelImageMask = GDisplay::Get()->NewSprite("map_battery_mask_14.png");
  
  addChild(_NodeMode, -1);
  _NodeMode->addChild(_BaseImage, -1);
  _NodeMode->addChild(_ModelImage, -1);
  _ModelImageMask->setPosition(Vec2(65, 55));
  _NodeMode->addChild(_ModelImageMask, -1);
  
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  _ImageProtect->setScale(1);
  _ImageProtect->setPosition(_CenterPoint + Vec2(0, 80));
  addChild(_ImageProtect, 1);

  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(_CenterPoint - Vec2(147, 10));
  _ImageLeagueFlag->setVisible(false);
  addChild(_ImageLeagueFlag, 1);
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  
  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageLeagueName->setPosition(_CenterPoint - Vec2(0, 35));
  _ImageLeagueName->setVisible(false);
  addChild(_ImageLeagueName, 1);
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  
  static GBase::RCreateLabelParm lParm;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "leagueName";
  lParm._FontSize = 20;
  _TextLeagueName = GBase::DCreateLabel(lParm);
  _TextLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextLeagueName->setPosition(_CenterPoint - Vec2(0, 35));
  _TextLeagueName->setVisible(false);
  addChild(_TextLeagueName, 1);
  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  
  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImagePlayerName->setPosition(_CenterPoint - Vec2(0, 80));
  _ImagePlayerName->setVisible(false);
  addChild(_ImagePlayerName, 1);
  // self.image_player_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  
  lParm._Text = "playerName";
  _TextPlayerName = GBase::DCreateLabel(lParm);
  _TextPlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextPlayerName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  _TextPlayerName->setVisible(false);
  addChild(_TextPlayerName, 1);
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
}

void WorldMapBattery::OnMessageListener() {}

void WorldMapBattery::AddCacheBefore() {
  _ModelImage->stopAllActions();
  _ModelImage->setFlippedX(false);
  _ImageProtect->setVisible(false);
}

void WorldMapBattery::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.nodeMode:setGroupID(groupID)
  // self.nodeMode:setGroupAuto(true)
}

EKWBattery WorldMapBattery::GetSiteClassID(){
  return _SiteClassID;
}

void WorldMapBattery::InitInstanceData(int32 pSiteClassID, void *pBatteryData, int32 pObjData) {
  auto lBatteryData = (RWorldBatteryInitData *)pBatteryData;
  InitInstanceData(static_cast<EKWBattery>(pSiteClassID), *lBatteryData, pObjData);
}

void WorldMapBattery::InitInstanceData(
  EKWBattery pSiteClassID, const RWorldBatteryInitData &pBatteryData, 
  int32 pObjID) {
    
  _SiteClassID = static_cast<EKWBattery>(pObjID);
  _ShowTilePoint = GetTilePoint();
  _WorldCenterPoint = Vec2(600, 600);
  
  auto lWorldMapView = dynamic_cast<WorldMapView*>(GBase::DCurrentSceneShowView("worldMapView"));
  if(lWorldMapView) {
    _ShowTilePoint = lWorldMapView->GetPointWithTile(_ShowTilePoint);
    _WorldCenterPoint = lWorldMapView->GetPointWithTile(_WorldCenterPoint);
  }
  
  auto lImg = PalaceInfoRead::Get()->GetBatteryImg(_SiteClassID);
  if(!lImg.empty()){
    _BaseImage->setSpriteFrame(lImg);
    if(_SiteClassID == EKWBattery::NORTH){
      _NodeMode->setPosition(Vec2(-50, 50));
      _ModelImage->setVisible(false);
      _ModelImageMask->setVisible(false);
    }else if(_SiteClassID == EKWBattery::SOUTH){
      _NodeMode->setPosition(Vec2(-61, 98));
      _ModelImage->setVisible(false);
      _ModelImageMask->setVisible(false);
    }else if( _SiteClassID == EKWBattery::EAST){
      _NodeMode->setPosition(Vec2(-67, 23));
      _ModelImage->setVisible(true);
      _ModelImage->setSpriteFrame("fytp_dj_w_001.png");
      _ModelImage->setPosition(Vec2(50, 86));
      _ModelImage->setFlippedX(true);
      _ModelImageMask->setVisible(true);
    }else if(_SiteClassID == EKWBattery::WEST){
      _NodeMode->setPosition(Vec2(-59, 12));
      _ModelImage->setVisible(true);
      _ModelImage->setSpriteFrame("fytn_dj_w_001.png");
      _ModelImage->setPosition(Vec2(60, 100));
      _ModelImageMask->setVisible(false);
    }
  }
  UpdateData(pBatteryData);
}

void WorldMapBattery::UpdateData(const RWorldBatteryInitData &pBatteryData){

  _PlayerID = pBatteryData._PlayerID;
  _PlayerName = pBatteryData._PlayerName;
  _LeagueID = pBatteryData._LeagueID;
  _SourceID = pBatteryData._SourceKid;
  _LeagueName = pBatteryData._LeagueName;
  _LeagueAbbrName = pBatteryData._LeagueAbbrName;
  _LeagueFlag = pBatteryData._LeagueFlag;
  _BatteryState = pBatteryData._Status;
  _ModelState = pBatteryData._ModelState;
  if(pBatteryData._Damage > 0){
    _AllHurtNum = pBatteryData._Damage;
    _HurtCount = 4;
  }
  _WarStatus = pBatteryData._WarStatus;
  _KingStatus = pBatteryData._KingStatus;
  UpdateEmojiByData(pBatteryData._PlayerID, pBatteryData._EmojiID);
  UpdatePlayerInfo();
  UpdateSafeState();
  UpdateBatteryState();
  UpdateModelState();
}

void WorldMapBattery::UpdatePlayerInfo(){

  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(_LeagueID > 0){
    auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
    if(_SourceID > 0 && lSelfSourceID != _SourceID){
      _TextLeagueName->setColor(Color3B(200, 0, 0));
      _TextPlayerName->setColor(Color3B(200, 0, 0));
    }else if(_LeagueID == lSelfLeagueID){
      auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
      _TextLeagueName->setColor(lNameColor);
      _TextPlayerName->setColor(lNameColor);
    }else{
      auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
      auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
      _TextLeagueName->setColor(lNameColor);
      _TextPlayerName->setColor(lNameColor);
    }
    
    _ImageLeagueFlag->setVisible(true);
    _ImageLeagueName->setVisible(true);
    _TextLeagueName->setVisible(true);
    _ImagePlayerName->setVisible(true);
    _TextPlayerName->setVisible(true);
    
    auto lFlagIcon = AllianceRead::Get()->GetFlagIcon(_LeagueFlag);
    if(!lFlagIcon.empty()){
      _ImageLeagueFlag->setSpriteFrame(lFlagIcon);
    }
    _TextLeagueName->setString(_LeagueName);

    auto lTextName = _PlayerName;
    if(_LeagueID > 0 && !_LeagueAbbrName.empty()){
      lTextName = Translate::i18n("common_text_186", {
        {"abbr", _LeagueAbbrName},
        {"name", _PlayerName}
      });
    }
    
    if(_SourceID > 0 && lSelfSourceID != _SourceID){
      lTextName = lTextName + "#" + std::to_string(_SourceID);
    }
    _TextPlayerName->setString(lTextName);
  }else{
    _ImageLeagueFlag->setVisible(false);
    _ImageLeagueName->setVisible(false);
    _TextLeagueName->setVisible(false);
    _ImagePlayerName->setVisible(false);
    _TextPlayerName->setVisible(false);
  }
}

void WorldMapBattery::UpdateSafeState(){
  if(_WarStatus == EKingdomWarStatusType::inWar){
    _ImageProtect->setVisible(false);
  }else{
    _ImageProtect->setVisible(true);
  }
}

void WorldMapBattery::UpdateBatteryState(){
  UpdateFireEffect(_BatteryState);
}

void WorldMapBattery::UpdateModelState(){
  if(_ModelState == EMapObjStateTypeDef::Fighting && 
    (_SiteClassID == EKWBattery::WEST || _SiteClassID == EKWBattery::EAST)){
    DoFightingAnimation();
  }
}

GString WorldMapBattery::GetAnimationKey(){
  if(_SiteClassID == EKWBattery::EAST){
    return "fytp";
  }else if(_SiteClassID == EKWBattery::WEST){
    return "fytn";
  }
  return "paotai";
}

void WorldMapBattery::DoFreeAnimation(){
  _ModelImage->stopAllActions();
  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(3));
  lActionsArray.pushBack(CallFunc::create([this](){
    auto lKey = GetAnimationKey();
    auto lFrames = GDisplay::Get()->NewFrames((lKey + "_dj_w_%.3d.png").c_str(), 1, 24);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.1f);
    XTransition::Get()->PlayAnimationOnce(_ModelImage, lAnimation, false, [this](){
      DoFreeAnimation();
    }, 0);
  }));
  auto lAction = XTransition::Get()->Sequence_(lActionsArray);
  _ModelImage->runAction(lAction);
}

void WorldMapBattery::UpdateShot(int32 pDamage){
  _AllHurtNum = pDamage;
  _HurtCount = 4;
  if(_SiteClassID == EKWBattery::WEST || _SiteClassID == EKWBattery::EAST){
    DoFightingAnimation();
  }
}

void WorldMapBattery::DoFightingAnimation(){
  if(_HurtCount <= 0){
    DoFreeAnimation();
  }else{
    DoFightingAnimation_Imp();
  }
}

void WorldMapBattery::DoFightingAnimation_Imp(){

  _ModelImage->stopAllActions();
  // math.randomseed(tostring(os.time()):reverse():sub(1, 6))
  GMath::Randomseed(GOS::Get()->GetTime());
  auto lRadius = GMath::Random(-100, 100);
  auto lAngle = GMath::Random(-180, 180);
  auto lRadian = GMath::Angle2Radian(lAngle);
  auto lRotation = 0;
  GString lFightingImgNameAngle = "w";
  bool __ = false;
  std::tie(lRotation, lFightingImgNameAngle, __) = WorldMapFunction::Get()->GetBatteryImgAngel(_ShowTilePoint, _WorldCenterPoint);
  
  int32 lChangeX = 0, lChangeY = 0, lPaojiX = 0, lPaojiY = 0;
  bool lIsLeft = false;

  if(lRotation >= -45 && lRotation < 45){
    lChangeX = 50;
    lChangeY = 125;
    lPaojiX = -25;
    lPaojiY = -10;
  }else if(lRotation >= -135 && lRotation < -45){
    lChangeX = 0;
    lChangeY = 150;
    lPaojiX = -10;
    lPaojiY = -35;
  }else if(lRotation >= 45 && lRotation < 135){
    lChangeX = 0;
    lChangeY = -10;
    lPaojiX = -10;
    lPaojiY = 50;
  }else{
    lChangeX = -100;
    lChangeY = 75;
    lPaojiX = 32;
    lPaojiY = 0;
    lIsLeft = true;
  }
  
  auto lDelayTime = 1.5f;
  if(_SiteClassID == EKWBattery::EAST){
    lDelayTime = 1.8f;
  }
  
  auto lBeginPointX = _ShowTilePoint.x + lChangeX;
  auto lBeginPointY = _ShowTilePoint.y + lChangeY;
  auto lEndPointX = _WorldCenterPoint.x + lRadius * GMath::Cos(lRadian);
  auto lEndPointY = _WorldCenterPoint.y + lRadius * GMath::Sin(lRadian);

  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(1));
  lActionsArray.pushBack(CallFunc::create([this](){
    auto lKey = GetAnimationKey();
    auto lFrames = GDisplay::Get()->NewFrames((lKey + "_gj_w_%.3d.png").c_str(), 1, 24);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.1f);
    XTransition::Get()->PlayAnimationOnce(_ModelImage, lAnimation, false, [this](){
      DoFightingAnimation();
    }, 0);
  }));

  lActionsArray.pushBack(DelayTime::create(lDelayTime));
  lActionsArray.pushBack(CallFunc::create([=](){
    auto lParNode = CreatePaojiEffect(lFightingImgNameAngle, lIsLeft);
    if(lParNode){
      lParNode->setPosition(Vec2(lBeginPointX + lPaojiX, lBeginPointY + lPaojiY));
      lParNode->setLocalZOrder(getLocalZOrder());
      getParent()->addChild(lParNode);
    }
  }));

  auto lEndCallFunc = [](Vec2 pPos, Node *pParent, int32 pZOrder, int32 pHurtNum){
    GVector<RCreatEffctParam> lEndEffectParam(2);
    lEndEffectParam[0]._PList = "et_kaichang_explosion_01.plist";
    lEndEffectParam[0]._Pos = Vec2::ZERO;
    lEndEffectParam[0]._Scale = Vec2::ONE;
    lEndEffectParam[0]._PosType = ParticleSystem::PositionType::RELATIVE;
    lEndEffectParam[0]._Rotate = 0;
    lEndEffectParam[0]._ZOrder = 0;
    lEndEffectParam[1]._PList = "et_kaichang_explosion_02.plist";
    lEndEffectParam[1]._Pos = Vec2::ZERO;
    lEndEffectParam[1]._Scale = Vec2::ONE;
    lEndEffectParam[1]._PosType = ParticleSystem::PositionType::RELATIVE;
    lEndEffectParam[1]._Rotate = 0;
    lEndEffectParam[1]._ZOrder = 0;

    auto lEndEffectNode = GBase::DCreateEffectNode(lEndEffectParam);
    lEndEffectNode->setPosition(pPos);
    lEndEffectNode->setLocalZOrder(pZOrder);
    Vector<FiniteTimeAction *> lEffectNodeActionsArray;
    lEffectNodeActionsArray.pushBack(DelayTime::create(1));
    lEffectNodeActionsArray.pushBack(CallFunc::create([lEndEffectNode](){
      lEndEffectNode->removeFromParent();
    }));
    auto lEndEffectAction = XTransition::Get()->Sequence_(lEffectNodeActionsArray);
    lEndEffectNode->runAction(lEndEffectAction);
    
    RCreateWaveLabelParam lParam;
    lParam._Color = GDisplay::Get()->COLOR_RED,
    lParam._Pos = pPos;
    lParam._ZOrder = pZOrder;

    GBase::DCreateWaveLabel(
      Translate::i18n("common_text_1527", { {"num" , std::to_string(pHurtNum)} }),
      pParent,  lParam
    );
  };

  auto lCallFunc = [this, lBeginPointX, lBeginPointY, lEndPointX, lEndPointY, lEndCallFunc](){
    //   math.randomseed(tostring(os.time()):reverse():sub(1, 6))
    GMath::Randomseed(GOS::Get()->GetTime());
    auto lHurtNum = 0;
    if(_HurtCount > 1){
      lHurtNum = GMath::Random(0, _AllHurtNum);
    }else if(_HurtCount == 1){
      lHurtNum = _AllHurtNum;
    }
    
    _AllHurtNum = _AllHurtNum - lHurtNum;
    _HurtCount = _HurtCount - 1;
    auto lBulletSprite = CreateEffectFireStone();
    lBulletSprite->setPosition(lBeginPointX, lBeginPointY);
    lBulletSprite->setScale(1);
    getParent()->addChild(lBulletSprite, _BulletZOrder);
    auto lAddParent = getParent();
    WorldMapFunction::Get()->CreateThrowAction(
      lBulletSprite, Vec2(lBeginPointX, lBeginPointY), Vec2(lEndPointX, lEndPointY), 0, 500, 
      [=](){
        lEndCallFunc(Vec2(lEndPointX, lEndPointY), lAddParent, _BulletZOrder, lHurtNum);
      }
    );
  };
  auto lAction = XTransition::Get()->Sequence_(lActionsArray);
  _ModelImage->runAction(lAction);
}

void WorldMapBattery::DoHurtDieAnimation(){}

Node *WorldMapBattery::CreatePaojiEffect(const GString &pFightingImgNameAngle, bool pIsLeft){
  if(_SiteClassID != EKWBattery::EAST){
    return nullptr;
  }
  
  auto lScale = 1.0f;
  auto lRotate = 0.0f;
  auto lMoveScale = 1.0f;
  auto lMovePosX = 0.0f;
  auto lScaleY = 1.0f;

  if(pFightingImgNameAngle == "w"){
    lScale = 0.5f;
    if(pIsLeft){
      lRotate = 20.0f;
    }else{
      lRotate = -20.0f;
      lMoveScale = -1.0f;
    }
  }else if(pFightingImgNameAngle == "n"){
    lScaleY = 0.5f;
    lMovePosX = 15.0f;
    lMoveScale = 1.0f;
  }else if(pFightingImgNameAngle == "s"){
    lMoveScale = 0.0f;
    lMovePosX = 10.0f;
  }

  GVector<RCreatEffctParam> lParam(3);
  lParam[0]._PList = "et_paoji_01.plist";
  lParam[0]._Pos = Vec2(15 * lMoveScale, 0);
  lParam[0]._Scale = Vec2(lMoveScale, 1);
  
  lParam[1]._PList = "et_paoji_02.plist";
  lParam[1]._Pos = Vec2(10 * lMoveScale, 0);
  lParam[1]._Scale = Vec2(lScale, lScaleY);
  lParam[1]._Rotate = lRotate;
  lParam[1]._AutoCull = false;

  lParam[2]._PList = "et_paoji_03.plist";
  lParam[2]._Pos = Vec2(10 + lMovePosX, 0);
  lParam[2]._AutoCull = false;
  
  return GBase::DCreateEffectNode(lParam);
}

Node *WorldMapBattery::CreateEffectFireStone(){
  if(_SiteClassID == EKWBattery::WEST){
    auto lBulletNode = GDisplay::Get()->NewNode();
    for(int32 i = 0; i < 10; ++i){
      auto lBulletSprite = GDisplay::Get()->NewSprite("icon_battle_jian_4.png");
      auto lRandomPointX = GMath::Random(0, 10);
      auto lRandomPointY = GMath::Random(0, 30);
      lBulletSprite->setPosition(Vec2(lRandomPointX, lRandomPointY));
      lBulletSprite->setScale(1);
      lBulletSprite->setRotation(10);
      lBulletNode->addChild(lBulletSprite, 1);
    }
    
    return lBulletNode;
  }

  GVector<RCreatEffctParam> lParam(6);

  lParam[0]._PList = "et_paoshidan_display_01.plist";
  lParam[0]._Scale = Vec2(0.45f, 0.49f);
  lParam[0]._Rotate = 90;
  lParam[0]._ZOrder = 6;

  lParam[1]._PList = "et_paoshidan_display_02.plist";
  lParam[1]._Scale = Vec2(0.34f, 0.4f);
  lParam[1]._Rotate = 178.36f;
  lParam[1]._ZOrder = 5;
  lParam[1]._Pos = Vec2(-3.04f, -3.04f);
  
  lParam[2]._PList = "et_paoshidan_display_03.plist";
  lParam[2]._Scale = Vec2(0.71f, 0.71f);
  lParam[2]._Rotate = 90;
  lParam[2]._ZOrder = 4;
  lParam[2]._Pos = Vec2(-2.43f, -5.13f);
  
  lParam[3]._PList = "et_paoshidan_display_04.plist";
  lParam[3]._Scale = Vec2(1, 1);
  lParam[3]._Rotate = 90;
  lParam[3]._ZOrder = 3;
  lParam[3]._Pos = Vec2(-2.4f, -2.4f);

  lParam[4]._PList = "et_paoshidan_display_05.plist";
  lParam[4]._Scale = Vec2(1, 1);
  lParam[4]._Rotate = 90;
  lParam[4]._ZOrder = 2;
  lParam[4]._Pos = Vec2(-2, -2);

  lParam[5]._PList = "et_paoshidan_display_06.plist";
  lParam[5]._Scale = Vec2(0.51f, 0.51f);
  lParam[5]._Rotate = 90;
  lParam[5]._ZOrder = 1;

  return GBase::DCreateEffectNode(lParam);
}

void WorldMapBattery::PlayClickSound(){
  GBase::PlaySound("worldmap", 17);
}

GVector<RButtonTypeArray> WorldMapBattery::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSefLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(pIsSelfKingdom && _WarStatus == EKingdomWarStatusType::inWar && lSefLeagueID > 0){
    if(_LeagueID == 0){
      lButtonTypeArray.push_back({ EWorldMapTipButtonType::gongJi });
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSefLeagueID > 0){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::xuanZhan });
      }
    }else if(lSefLeagueID == _LeagueID){
      if(std::get<0>(CheckHasArmy())){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::fanHui });
      }
      if(CanHasEmojiOperator()){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::biaoqingyinzhang });
      }
      lButtonTypeArray.push_back({ EWorldMapTipButtonType::shibingYuabzhu });
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSefLeagueID > 0){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::zuduiYuanzhu });
      }
      lButtonTypeArray.push_back({ EWorldMapTipButtonType::buDuiXiangqing });
    } else {
      lButtonTypeArray.push_back({ EWorldMapTipButtonType::gongJi });
      
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSefLeagueID > 0){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::xuanZhan });
      }
      
      auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
      if(lTowerLv > 1){
        lButtonTypeArray.push_back({ EWorldMapTipButtonType::zhenCha });
      }
    }
  }
  lButtonTypeArray.push_back({ EWorldMapTipButtonType::zhuangTai });
  return lButtonTypeArray;
}