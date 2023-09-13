#include "WorldMapFortress.h"
#include "Global/Global.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Alliance.Read.h"
#include "Base/Common/Common.Func.h"
#include "Base/Utils/XTransition.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/City/City.Ctrl.h"

void WorldMapFortress::Ctor() {
  AddFortressEffect();
  _InitUI();
  _InitData();
}

void WorldMapFortress::_InitData(){}

void WorldMapFortress::_InitUI(){
  _ModelImage = GDisplay::Get()->NewSprite("Map_build_fort.png");
  _ModelImage->setPosition(Vec2(0, 45));
  addChild(_ModelImage, -1);
  
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  _ImageProtect->setScale(0.7f);
  _ImageProtect->setPosition(Vec2(_CenterPoint + Vec2(0, 150)));
  addChild(_ImageProtect, 1);
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(Vec2(_CenterPoint + Vec2(-147, -10)));
  _ImageLeagueFlag->setVisible(INIT_FALSE);
  addChild(_ImageLeagueFlag, 1);
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)

  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageLeagueName->setPosition(Vec2(_CenterPoint + Vec2(0, -35)));
  _ImageLeagueName->setVisible(INIT_FALSE);
  addChild(_ImageLeagueName, 1);
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "leagueName";
  lParam._FontSize = 20;
  
  _TextLeagueName = GBase::DCreateLabel(lParam);
  _TextLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextLeagueName->setPosition(Vec2(_CenterPoint + Vec2(0, -35)));
  _TextLeagueName->setVisible(INIT_FALSE);
  addChild(_TextLeagueName, 1);
  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)

  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImagePlayerName->setPosition(Vec2(_CenterPoint + Vec2(0, -80)));
  _ImagePlayerName->setVisible(INIT_FALSE);
  addChild(_ImagePlayerName, 1);
  // self.image_player_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  lParam._Text = "playerName";
  _TextPlayerName = GBase::DCreateLabel(lParam);
  _TextPlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextPlayerName->setPosition(Vec2(_CenterPoint + Vec2(0, -80)));
  _TextPlayerName->setVisible(INIT_FALSE);
  addChild(_TextPlayerName, 1);
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
}

void WorldMapFortress::OnMessageListener() {}

void WorldMapFortress::AddCacheBefore() {
  _ImageProtect->setVisible(false);
}

void WorldMapFortress::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.modelImage:setGroupID(groupID)
}

void WorldMapFortress::InitInstanceData(int32 pSiteClassID, void *pData, int32 pObjID) {
  if(!pData) return;
  auto lData = static_cast<RWorldMapFortressInit *>(pData);
  InitInstanceData(pSiteClassID, *lData, pObjID);
}

void WorldMapFortress::InitInstanceData(int32 pSiteClassID, const RWorldMapFortressInit &pFortress, int32 pObjData){
  UpdateData(pFortress);
}

void WorldMapFortress::UpdateData(const RWorldMapFortressInit &pFortress){
  _PlayerID = pFortress._PlayerID;
  _PlayerName = pFortress._PlayerName;
  _LeagueID = pFortress._LeagueID;
  _SourceID = pFortress._SourceKid;
  _LeagueName = pFortress._LeagueName;
  _LeagueAbbrName = pFortress._LeagueAbbrName;
  _LeagueFlag = pFortress._LeagueFlag;
  _BattleState = pFortress._Status;
  _ModelState = pFortress._ModelState;
  _WarStatus = pFortress._WarStatus;
  _KingStatus = pFortress._KingStatus;
  UpdateEmojiByData(pFortress._PlayerID , pFortress._EmojiID);
  UpdatePlayerInfo();
  UpdateSafeState();
  UpdateBattleState();
  UpdateModelState();
}

void WorldMapFortress::UpdatePlayerInfo(){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(_LeagueID > 0){
    auto lSelfSourceID  = LordInfoCtrl::Get()->GetMapSourceKid();
    if(_SourceID > 0 && lSelfSourceID != _SourceID){
      _TextLeagueName->setColor(Color3B(200, 0, 0));
      _TextPlayerName->setColor(Color3B(200, 0, 0));
    } else if(_LeagueID == lSelfLeagueID){
      auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
      _TextLeagueName->setColor(lNameColor);
      _TextPlayerName->setColor(lNameColor);
    } else {
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
      lTextName += "#" + std::to_string(_SourceID);
    }
    _TextLeagueName->setString(_LeagueName);
  }else{
    _ImageLeagueFlag->setVisible(false);
    _ImageLeagueName->setVisible(false);
    _TextLeagueName->setVisible(false);
    _ImagePlayerName->setVisible(false);
    _TextPlayerName->setVisible(false);
  }
}

void WorldMapFortress::UpdateSafeState(){
  if(_WarStatus == EKingdomWarStatusType::inWar){
    _ImageProtect->setVisible(false);
  } else {
    _ImageProtect->setVisible(true);
  }
}

void WorldMapFortress::UpdateBattleState(){
  UpdateFireEffect(_BattleState);
}

void WorldMapFortress::AddFortressEffect(){

  GVector<RCreatEffctParam> lParam(3);
  lParam[0]._PList = "et_flame1_display.plist";
  lParam[0]._Pos = Vec2(33.78f, 41.28f);
  lParam[0]._Scale = Vec2(1.5f, 1.5f);
  lParam[1]._PList = "et_flame2_display.plist";
  lParam[1]._Pos = Vec2(34.25f, 70.5f);
  lParam[1]._Scale = Vec2(2.5f, 2.5f);
  lParam[2]._PList = "et_flame3_display.plist";
  lParam[2]._Pos = Vec2(36.07f, 106.15f);

  auto lFire_1 = GBase::DCreateEffectNode(lParam);
  lFire_1->setScale(0.45f);
  lFire_1->setRotation(15);
  lFire_1->setPosition(Vec2(-80, 130));
  addChild(lFire_1, 2);
  
  auto lFire_2 = GBase::DCreateEffectNode(lParam);
  lFire_2->setScale(0.35f);
  lFire_2->setRotation(15);
  lFire_2->setPosition(Vec2(80, 22));
  addChild(lFire_2, 2);

  auto lQizhi = GDisplay::Get()->NewSprite("ysqz_01.png");
  lQizhi->setPosition(Vec2(118, 150));
  addChild(lQizhi, 2);
  auto lFrames = GDisplay::Get()->NewFrames("ysqz_%.2d.png", 1, 8);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 1.0f / lFrames.size());
  XTransition::Get()->PlayAnimationForever(lQizhi, lAnimation);
}

GVector<RButtonTypeArray> WorldMapFortress::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(pIsSelfKingdom && lSelfLeagueID > 0 && _WarStatus == EKingdomWarStatusType::inWar){
    if(_LeagueID == 0){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSelfLeagueID > 0){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
      }
    }else if(_LeagueID == lSelfLeagueID){
      if(std::get<0>(CheckHasArmy())){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
      }
      if(CanHasEmojiOperator()){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shibingYuabzhu});
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSelfLeagueID > 0){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::zuduiYuanzhu});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::buDuiXiangqing});
    } else{
      lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
      auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
      if(lHaveHall && lSelfLeagueID > 0){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
      }
      auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
      if(lTowerLv > 1){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
      }
    }
  }
  lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
  return lButtonTypeArray;
}

void WorldMapFortress::PlayClickSound() {
  GBase::PlaySound("innerbuildsound", 119);
}