#include "WorldMapDrumAndVuln.h"
#include "Global/Global.h"

#include "Module/City/City.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"

void WorldMapDrumAndVuln::Ctor() {
  _TreasureImg = GDisplay::Get()->NewSprite("Map_build_vulnerary.png");
  addChild(_TreasureImg, -1);
  _OccupyIcon = GDisplay::Get()->NewSprite("icon_map_res_me.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(INIT_FALSE);
  addChild(_OccupyIcon, 2);
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  RemoveFireEffect(0);
}

void WorldMapDrumAndVuln::_InitData(){}

void WorldMapDrumAndVuln::OnMessageListener() {}

void WorldMapDrumAndVuln::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.treasureImg:setGroupID(groupID)
}

void WorldMapDrumAndVuln::InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) {
  _ResourceClassID = pClass;
  if(_ResourceClassID == 4302) {
    _TreasureImg->setSpriteFrame("Map_build_vulnerary.png");
    _TreasureImg->setPosition(Vec2(0, 10));
  } else {
    _TreasureImg->setSpriteFrame("Map_build_warDrum.png");
    _TreasureImg->setPosition(Vec2(-30, 30));
  }
  if(!pObjData) {
    return;
  }
  UpdateData(*(RWorldMapDrumAndVulnInit *)pObjData);
}

void WorldMapDrumAndVuln::UpdateData( const RWorldMapDrumAndVulnInit &pData){
  _PlayerID = pData._PlayerID;
  _PlayerName = pData._PlayerName;
  _LeagueID = pData._LeagueID;
  _LeagueName = pData._LeagueName;
  _SourceID = pData._SourceKid;
  
  UpdateFireEffect(_TreasureState);
  UpdateEmojiByData(pData._PlayerID, pData._EmojiID);
  if(_PlayerID > 0 ){
    SetBeOccupyed();
  } else {
    CancelBeOccupyed();
  }
}

GTuple<UIBasePanel *, bool, Node*>  WorldMapDrumAndVuln::OnClickInstance(Node *pNode) {
  auto lBuildLvl = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Castle);
  auto lResourceLevelLimit = WorldMapDefine::Get()->GetResourceCastleLv(_ResourceClassID);
  if(lBuildLvl < lResourceLevelLimit){
    auto lLimitString = Translate::i18n("common_text_497", 
      {{"Level", std::to_string(lResourceLevelLimit)}});
    GBase::DShowMsgTip(lLimitString);
    return {nullptr, false, nullptr};
  }
  PlayClickSound();
  return OnShowWorldMapTip(pNode);
}

void  WorldMapDrumAndVuln::SetBeOccupyed(){
  _IsBeOccupyed = true;
  _OccupyIcon->setVisible(true);
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lOccupyIconName = "icon_map_res_me.png";

  if(lSelfPlayerID == _PlayerID){
    lOccupyIconName = "icon_map_res_me.png";
  }else if(lSelfLeagueID == _LeagueID){
    lOccupyIconName = "icon_map_res_alliance.png";
  }else{
    auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
    if(lAllianceRelationType == EMapAllianceRelationType::ALLY){
      lOccupyIconName = "icon_map_res_bund.png";
    }else if(lAllianceRelationType == EMapAllianceRelationType::FRIENDLY){
      lOccupyIconName = "icon_map_res_friend.png";
    }else if(lAllianceRelationType == EMapAllianceRelationType::ENEMY){
      lOccupyIconName = "icon_map_res_enemy.png";
    }

    if(_SourceID > 0){
      auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
      if(_SourceID != lSelfSourceID){
        lOccupyIconName = "icon_map_res_others.png";
      }
    }
  }
  _OccupyIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOccupyIconName));
}

void  WorldMapDrumAndVuln::CancelBeOccupyed(){
  _IsBeOccupyed = false;
  _OccupyIcon->setVisible(false);
}

GString  WorldMapDrumAndVuln::GetFavoriteName() {
  return WorldMapDefine::Get()->GetWarTreasureBuildingName(_ResourceClassID);
}

void WorldMapDrumAndVuln::PlayClickSound() {
  GBase::PlaySound("worldmap", 5);
}

GVector<RButtonTypeArray> WorldMapDrumAndVuln::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) {
  
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  
  if(_PlayerID <= 0){
    if(lSelfLeagueID > 0){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::zhanLing});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
    }
  } else if(pIsSelfKingdom){
    if(_PlayerID == lSelfPlayerID){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      if(CanHasEmojiOperator(lSelfPlayerID)){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
      }
    } else if(lSelfLeagueID > 0 && lSelfLeagueID == _LeagueID){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    } else {
      lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
      if(lTowerLv > 1){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    }
  } else {
    lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
  }

  lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
  return lButtonTypeArray;
}

void  WorldMapDrumAndVuln::AddCacheBefore() {}
