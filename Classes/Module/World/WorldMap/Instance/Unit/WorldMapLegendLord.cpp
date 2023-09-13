#include "Global/Global.h"
#include "WorldMapLegendLord.h"
#include "Base/Common/CommonCheck.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldWar/LegendLord/Hegemon.Read.h"
#include "Module/World/WorldWar/LegendLord/LegendLordWar.Ctrl.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/LegendLord/UIWorldMapLegendLord.ProgressBar.h"

void WorldMapLegendLord::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapLegendLord::_InitData(){

}

void WorldMapLegendLord::_InitBuildBg(){
  _BgImage = GDisplay::Get()->NewNode();
  _BgImage->setPosition(_CenterPoint - Vec2(0, 10));
  addChild(_BgImage, -1);
  _ImageBg = GDisplay::Get()->NewSprite("LegendaryKing_palace.png");
  _ImageBg->setPosition(Vec2(-95, 120));
  _BgImage->addChild(_ImageBg, 1);
}

void WorldMapLegendLord::_InitUI(){
  _InitBuildBg();
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  addChild(_ImageProtect, 1);
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3);
  _ImageLeagueFlag->setPosition(_CenterPoint + Vec2(-147, 30));
  _ImageLeagueFlag->setVisible(INIT_FALSE);
  addChild(_ImageLeagueFlag, 1);
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  _ImageBuildName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageBuildName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageBuildName->setPosition(_CenterPoint + Vec2(0, -150));
  addChild(_ImageBuildName, 1);
  // self.image_build_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  GBase::RCreateLabelParm lParam;
  lParam._UILabelType = GBase::EUILabelType::TTF;
  lParam._Text = "playerName";
  lParam._FontSize = 20;
  _TextBuildName = GBase::DCreateLabel(lParam);
  _TextBuildName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextBuildName->setPosition(_CenterPoint + Vec2(0, -150));
  addChild(_TextBuildName, 1);
  // self.text_build_name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageLeagueName->setPosition(_CenterPoint + Vec2(0, 25));
  _ImageLeagueName->setVisible(INIT_FALSE);
  addChild(_ImageLeagueName, 1);
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)

  lParam._Text = "leagueName";
  _TextLeagueName = GBase::DCreateLabel(lParam);
  _TextLeagueName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextLeagueName->setPosition(_CenterPoint + Vec2(0, 25));
  _TextLeagueName->setVisible(INIT_FALSE);
  addChild(_TextLeagueName, 1);
  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImagePlayerName->setPosition(_CenterPoint + Vec2(0, -30));
  _ImagePlayerName->setVisible(INIT_FALSE);
  addChild(_ImagePlayerName, 1);
  // self.image_player_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  
  lParam._Text = "playerName";
  _TextPlayerName = GBase::DCreateLabel(lParam);
  _TextPlayerName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextPlayerName->setPosition(_CenterPoint + Vec2(0, -30));
  _TextPlayerName->setVisible(INIT_FALSE);
  addChild(_TextPlayerName, 1);
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ProgressBar = UIWorldMapLegendLordProgressBar::Create();
  _ProgressBar->setPosition(_CenterPoint + Vec2(0, -75));
  _ProgressBar->setAnchorPoint(Vec2(0.5, 0.5));
  addChild(_ProgressBar, 1);
  _ProgressBar->setVisible(INIT_FALSE);
}

int32 WorldMapLegendLord::GetSiteClassID(){
  return _SiteClassID;
}

void WorldMapLegendLord::OnMessageListener() {}

void WorldMapLegendLord::AddCacheBefore() {
  _ImageProtect->setVisible(false);
}

void WorldMapLegendLord::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.bgImage:setGroupID(groupID)
  // self.bgImage:setGroupAuto(true)
}


void WorldMapLegendLord::InitInstanceData(int32 pSiteClassID, void *pBatteryData, int32 pObjData) {
  auto lData = static_cast<RLegendLordInitData*>(pBatteryData);
  InitInstanceData(pSiteClassID, *lData, pObjData);
}

void WorldMapLegendLord::InitInstanceData(int32 pSiteClassID, const RLegendLordInitData &pSiteData, int32 pObjID){
  _SiteClassID = pObjID;
  if(_SiteClassID){
    auto lBuildName = HegemonRead::Get()->GetName(_SiteClassID);
    _TextBuildName->setString(lBuildName);
    _ProgressBar->SetBuildID(_SiteClassID);
    auto lImgName = HegemonRead::Get()->GetImage(_SiteClassID);
    _ImageBg->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lImgName.c_str()));

    if(HegemonRead::Get()->IsLegendLordBuilding(_SiteClassID)){
      _ImageBg->setPosition(Vec2(-95, 120));
      _ImageProtect->setScale(2.1);
      _ImageProtect->setPosition(_CenterPoint + Vec2(0, 225));
      if(!GBase::CommonCheck::Get()->LegendLord ){
        _TextBuildName->setVisible(false);
        _ImageBuildName->setVisible(false);
      }
    }else{
      _ImageBg->setPosition(Vec2(10, 120));
      _ImageProtect->setScale(1.5);
      _ImageProtect->setPosition(_CenterPoint + Vec2(0, 175));
    }
  }
  UpdateData(pSiteData);
}

void WorldMapLegendLord::UpdateData(const RLegendLordInitData &pData){

  if(pData._Occupier){
    _Occupier = pData._Occupier;
    _PlayerID =_Occupier->_PlayerID;
    _PlayerName = _Occupier->_PlayerName;
    _LeagueID = _Occupier->_LeagueID;
    _SourceID = _Occupier->_SourceKid;
    _LeagueName = _Occupier->_LeagueName;
    _LeagueAbbrName = _Occupier->_LeagueAbbrName;
    _LeagueFlag = _Occupier->_LeagueFlag;
    
    if(_Occupier->_CurrOccupyBeginTime && _Occupier->_HistOccupyTotalSecs){
      auto lOccupyTime = LegendLordWarCtrl::Get()->GetLegendOccupyTime(_Occupier->_CurrOccupyBeginTime);
      lOccupyTime += _Occupier->_HistOccupyTotalSecs;
      _IsOccupy = true;
      if(lOccupyTime < 0){
        lOccupyTime = 0;
      }
      UpdateProcessBar();
    }
    
    static RLegendLordOccupierChangedEvArg lArg;
    lArg._BuildID = _SiteClassID;
    lArg._Occupier = _Occupier;
    GBase::DSendMessage("MESSAGE_SERVER_LEGENDLORD_OCCUPIER_CHANGE", &lArg);

  }

  _WarStatus = pData._WarStatus;
  _KingStatus = pData._KingStatus;
  _BuildState = pData._Status;
  _FirstKillReward = pData._FirstKillReward;

  UpdateEmojiByData(pData._PlayerID, pData._EmojiID);
  UpdatePlayerInfo();
  UpdateSafeState();
  UpdateStatus();
}

void WorldMapLegendLord::UpdatePlayerInfo(){
  if(_LeagueID > 0){
    auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
    if(_LeagueID == lSelfLeagueID){
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

    if(_SourceID > 0)
    {
      lTextName += "#" + std::to_string(_SourceID);
    }
    _TextPlayerName->setString(lTextName);
  } else {
    _ImageLeagueFlag->setVisible(false);
    _ImageLeagueName->setVisible(false);
    _TextLeagueName->setVisible(false);
    _ImagePlayerName->setVisible(false);
    _TextPlayerName->setVisible(false);
  }
}

void WorldMapLegendLord::UpdateSafeState(){
  if(_WarStatus == EKingdomWarStatusType::inWar){
    _ImageProtect->setVisible(false);
  }else{
    _ImageProtect->setVisible(true);
  }
}

void WorldMapLegendLord::UpdateStatus(){
  UpdateFireEffect(_BuildState);
}

void WorldMapLegendLord::UpdateProcessBar(){
  if(_IsOccupy && _OccupyTime >= 0){
    _ProgressBar->BeginTime(_OccupyTime);
  }else{
    _ProgressBar->EndTime();
  }
}

void WorldMapLegendLord::PlayClickSound() {
  GBase::PlaySound("innerbuildsound", 101);
}

GVector<RButtonTypeArray> WorldMapLegendLord::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {

  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(pIsSelfKingdom){
    if(_WarStatus == EKingdomWarStatusType::inWar){
      if(lSelfLeagueID > 0){
        if(_LeagueID == 0){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
          auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
          if(lHaveHall)
            lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
          
        } else if(lSelfLeagueID == _LeagueID){
          auto [lHasArmy, lQueueId] = CheckHasArmy();
          // if hasArmy and queueId and (not _G._returnQueueIdList or not _G._returnQueueIdList[queueId]) then
          //   table.insert(buttonTypeArray, {
          //     buttonType = worldMapDefine.worldMapTipButtonType_fanHui
          //   })
          // end

          if(CanHasEmojiOperator())
            lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
          lButtonTypeArray.push_back({EWorldMapTipButtonType::shibingYuabzhu});
          auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
          if(lHaveHall)
            lButtonTypeArray.push_back({EWorldMapTipButtonType::zuduiYuanzhu});
          lButtonTypeArray.push_back({EWorldMapTipButtonType::buDuiXiangqing});
        }else{
          lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
          auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
          if(lHaveHall)
            lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
          auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
          if(lTowerLv > 1){
            lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
          }
        }

        if(_FirstKillReward)
        {
          lButtonTypeArray.push_back({EWorldMapTipButtonType::baoxiang});
        }
      }
    }else if(_WarStatus == EKingdomWarStatusType::rule){

    }
  }else{

  }
  lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
  return lButtonTypeArray;  
}

GString WorldMapLegendLord::GetFavoriteName(){
  return HegemonRead::Get()->GetName(_SiteClassID);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapLegendLord::OnClickInstance(Node *pNode) {
  if(HegemonRead::Get()->IsLegendLordBuilding(_SiteClassID) && !GBase::CommonCheck::Get()->LegendLord){
    return {nullptr, false, nullptr};
  }
  PlayClickSound();
  return OnShowWorldMapTip(pNode);
}