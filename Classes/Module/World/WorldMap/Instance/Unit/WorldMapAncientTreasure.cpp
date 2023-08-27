#include "WorldMapAncientTreasure.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Activity/AncientTreasure/AncientTreasure.Type.h"
#include "Module/Player/Player.Top.h"
#include "Module/City/City.Ctrl.h"

void WorldMapAncientTreasure::Ctor() {
  _InitUI();
  _InitData();
}

void WorldMapAncientTreasure::_InitData(){
  _TreasureState = EATBuildingStatus::AT_EXPLORE;
}

void WorldMapAncientTreasure::_InitUI(){
  
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(_CenterPoint.x - 147, _CenterPoint.y - 10);
  _ImageLeagueFlag->setVisible(false);
  addChild(_ImageLeagueFlag, 1);
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImageLeagueName->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 35);
  _ImageLeagueName->setVisible(false);
  addChild(_ImageLeagueName, 1);
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  GBase::RCreateLabelParm lParm;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "leagueName";
  lParm._FontSize = 20;
  
  _TextLeagueName = GBase::DCreateLabel(lParm);
  _TextLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextLeagueName->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 35);
  _TextLeagueName->setVisible(false);
  addChild(_TextLeagueName, 1);

  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImagePlayerName->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 80);
  _ImagePlayerName->setVisible(false);
  addChild(_ImagePlayerName, 1);

  lParm._Text = "playerName";
  _TextPlayerName = GBase::DCreateLabel(lParm);
  _TextPlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextPlayerName->setPosition(_CenterPoint.x - 0, _CenterPoint.y - 80);
  _TextPlayerName->setVisible(false);
  addChild(_TextPlayerName, 1);
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
 _TreasureImg = GDisplay::Get()->NewSprite("Map_build_sgmk.png");
  addChild(_TreasureImg, -1);
  _EtNode = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/ancientTreasureEffect.csb").First;
  GBase::DMixtureGLONEByParent(_EtNode);
  addChild(_EtNode, 1);
}

void WorldMapAncientTreasure::OnMessageListener() {}

void WorldMapAncientTreasure::AddCacheBefore() {}

void WorldMapAncientTreasure::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.treasureImg:setGroupID(groupID)
}

void WorldMapAncientTreasure::InitInstanceData(const RAncientTreasureInitData &pData){
  _Pos = GetTilePoint();
  _BuildID = pData._BuildID;
  UpdateData(pData);
}

void WorldMapAncientTreasure::UpdateData(const RAncientTreasureInitData &pTreasureData){

  auto lIsOccupy = false;
  if(_LeagueID > 0 && _LeagueID != pTreasureData._AID){
    lIsOccupy = true;
  }

  _PlayerID = pTreasureData._PlayerID;
  _PlayerName = pTreasureData._PlayerName;
  _LeagueID = pTreasureData._AID;
  _LeagueName = pTreasureData._LeagueName;
  _LeagueAbbrName = pTreasureData._LeagueAbbrName;
  _BuildType = pTreasureData._BuildType;
  _TreasureState = pTreasureData._BuildStatus;

  UpdateEmojiByData(pTreasureData._OwnerID, pTreasureData._EmojiID);
  UpdatePlayerInfo();
  static RMessageServerAncientTreasureUpdate lMessage;
  lMessage._Instance = this;
  lMessage._IsOccupy = lIsOccupy;
  GBase::DSendMessage("MESSAGE_SERVER_ANCIENT_TREASURE_UPDATE", &lMessage);
}

void WorldMapAncientTreasure::UpdatePlayerInfo(){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(_LeagueID > 0 && _PlayerID > 0){
    if(_LeagueID == lSelfLeagueID){
      auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
      _TextLeagueName->setColor(lNameColor);
      _TextPlayerName->setColor(lNameColor);
    }else{
      auto lARelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
      auto lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lARelationType);
      _TextLeagueName->setColor(lNameColor);
      _TextPlayerName->setColor(lNameColor);
    }
    
    _ImageLeagueFlag->setVisible(true);
    _ImageLeagueName->setVisible(true);
    _TextLeagueName->setVisible(true);
    _ImagePlayerName->setVisible(true);
    _TextPlayerName->setVisible(true);

    if(!AllianceRead::Get()->GetFlagIcon(_LeagueFlag).empty())
      _TextLeagueName->setString(_LeagueName);
    auto lTextName = _PlayerName;
    if(_LeagueID > 0 && !_LeagueAbbrName.empty()){
      lTextName = Translate::i18n("common_text_186", {{"abbr", _LeagueAbbrName}, {"name", _PlayerName}});
    }
    _TextPlayerName->setString(lTextName);
  }else{
    _ImageLeagueFlag->setVisible(false);
    _ImageLeagueName->setVisible(false);
    _TextLeagueName ->setVisible(false);
    _ImagePlayerName->setVisible(false);
    _TextPlayerName ->setVisible(false);
  }
}

GString WorldMapAncientTreasure::GetFavoriteName(){
  return Translate::i18n("AncienTreasure_buildname_01");
}

void WorldMapAncientTreasure::PlayClickSound() {
  GBase::PlaySound("worldmap", 5);
}

GVector<RButtonTypeArray> WorldMapAncientTreasure::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  if(pIsSelfKingdom){
    if(lSelfLeagueID == 0 || GBase::DGetCastleLv() < 6){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
      return lButtonTypeArray;
    }
    
    auto lRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
    if(lRelationType == EMapAllianceRelationType::ALLY){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
      return lButtonTypeArray;
    }

    if(_TreasureState == EATBuildingStatus::AT_EXPLORE){
      if(lSelfLeagueID > 0 && _LeagueID == lSelfLeagueID){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::tanmingmibao});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
    }else if(_TreasureState == EATBuildingStatus::AT_MINNING){
      if(lSelfLeagueID > 0 && _LeagueID == lSelfLeagueID || _LeagueID == 0){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::wajuexiangqing});
        auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
        if(lHaveHall){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::zuduiwajue});
        }
        lButtonTypeArray.push_back({EWorldMapTipButtonType::wajue});
      }else{
        RButtonTypeArray lButtonType;
        lButtonType._ButtonType = EWorldMapTipButtonType::gongJi;
        lButtonType._Extra._DispatchType = EWorldMapTipButtonType::zhanLing;
        lButtonTypeArray.push_back(lButtonType);
        if(_LeagueID > 0){
          auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
          if(lTowerLv > 1){
            lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
          }
        }
        
        auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
        if(lHaveHall){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
        }
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
    }
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
  }
  return lButtonTypeArray;
}