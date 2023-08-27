#include "WorldMapAllianceResource.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"

void WorldMapAllianceResource::Ctor(){
  _InitUI();
  _InitData();
}

void WorldMapAllianceResource::_InitData(){

}

void WorldMapAllianceResource::_InitUI(){
  
  _OccupyIcon = GDisplay::Get()->NewSprite("icon_map_res_me.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(false);
  addChild(_OccupyIcon, 2);
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  _ResourceImage = GDisplay::Get()->NewSprite("alliance_mineral_nongtian.png");
  addChild(_ResourceImage, -1);
  _ImageName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  addChild(_ImageName, 1);
  // self.image_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  GBase::RCreateLabelParm lParm;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "allianceResource";
  lParm._FontSize = 20;
  _TextName = GBase::DCreateLabel(lParm);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  addChild(_TextName, 2);
  // self.text_Name:setGroupID(worldMapDefine.GROU_ID.group_text)

}

void WorldMapAllianceResource::OnMessageListener() {}

void WorldMapAllianceResource::AddCacheBefore() {}

void WorldMapAllianceResource::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) {
  // self.resourceImage:setGroupID(groupID)
}

void WorldMapAllianceResource::InitInstanceData(int32 pResourceClassID, const RAllianceResourceInitData &pData){
  _ResourceClassID = pResourceClassID;
  _ResourceType = WorldMapDefine::Get()->GetAllianceResourceType(pResourceClassID);
  auto lImageName = WorldMapDefine::Get()->GetAllianceResourceImageName(pResourceClassID);
  _ResourceImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lImageName.c_str()));
  UpdateData(pData);
}

void WorldMapAllianceResource::UpdateData(const RAllianceResourceInitData &pData){
  
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lResourceName = WorldMapDefine::Get()->GetAllianceResourceName(_ResourceClassID);

  if(pData._Level){
    _ResourceLevel = pData._Level;
    _InstanceLevel = _ResourceLevel;
  }
  _LeagueID = pData._LeagueID;
  if(_LeagueID == 0){
    _LeagueName = "";
  }
  
  _LeagueName = pData._LeagueName;
  if(_IsSelfIn){
    _IsSelfIn = *pData._IsSelfIn;
  }else{
    _IsSelfIn = CheckIsSelfIn();

  }

  _AllianceResourceState = pData._Status;
  _LeftTime = pData._LeftTime;
  _SuperRes = pData;
  _OccupyIcon->setVisible(_IsSelfIn);
  if(_AllianceResourceState == EMapObjStateTypeDef::Working){
    _TextName->setString("(" + _LeagueName + ")" + lResourceName + "(" + "common_text_2139" + ")");
  }else{
    _TextName->setString("(" + _LeagueName + ")" + lResourceName + "(" + "common_text_830" + ")");
  }
  
  if(_LeagueID > 0){
    auto lNameColor = Color3B(0, 200, 200);
    if(_LeagueID == lSelfLeagueID){
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
    }else{
      auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
      auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
      auto lIsMatchKingdom = ConquestWarCtrl::Get()->IsMatchKingdom(lSelfSourceID, _KingdomID);
      if(lIsMatchKingdom){
        lAllianceRelationType = EMapAllianceRelationType::ENEMY;
      }
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
    }
    _TextName->setColor(lNameColor);
  }else{
    _TextName->setColor(Color3B(200, 200, 200));
  }
}

GString WorldMapAllianceResource::GetFavoriteName(){
  GString lFavoriteName;
  if(!_LeagueName.empty()){
    lFavoriteName = Translate::i18n("common_text_186", {
      {"abbr", _LeagueName},
      {"name", WorldMapDefine::Get()->GetAllianceResourceName(_ResourceClassID)}
    });
  }else{
    lFavoriteName = WorldMapDefine::Get()->GetAllianceResourceName(_ResourceClassID);
  }
  return lFavoriteName;
}

void WorldMapAllianceResource::PlayClickSound() {
  auto lSId = (int32)WorldMapDefine::Get()->GetAllianceResourceType(_ResourceClassID) + 1;
  if(lSId == 1){
    GBase::PlaySound("worldmap", 6);
  }else{
    GBase::PlaySound("innerbuildsound", 199 + lSId);
  }
}

int32 WorldMapAllianceResource::GetBuildPoint(){
  auto lBuildPoint = 0;
  if(_SuperRes){
    auto lSurPlusPoint = _SuperRes->_SurplusPoint;
    if(_SuperRes->_BuildSpeed > 0 && _SuperRes->_BuildSpeedTime > 0){
      lSurPlusPoint = 
        _SuperRes->_SurplusPoint - _SuperRes->_BuildSpeed * 
        (GOS::Get()->GetTime() - _SuperRes->_BuildSpeedTime);
    }
    lBuildPoint = GMath::Floor(_SuperRes->_TotalPoint - lSurPlusPoint);
  }
  return lBuildPoint;
}

GVector<RButtonTypeArray> WorldMapAllianceResource::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
  
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lIsInWarKingdom = false;
  if(ConquestWarCtrl::Get()->IsPlayerConquestWarMigration()){
    lIsInWarKingdom = true;
  }

  if(lSelfLeagueID > 0 && _LeagueID  == lSelfLeagueID){
    if(_IsSelfIn){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui, !lIsInWarKingdom});
    }else if(_AllianceResourceState == EMapObjStateTypeDef::Free){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::caiji, !lIsInWarKingdom});
    }else if(_AllianceResourceState == EMapObjStateTypeDef::Working){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::jianzao, !lIsInWarKingdom});
    }
    lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanxiangqing, !lIsInWarKingdom});
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
  }
  return lButtonTypeArray;
}

bool WorldMapAllianceResource::CheckIsSelfIn(){
  
  // if kingdomMapCtrl.kingdomMapCell:hasMyQueueToMapObj(self.instanceID, gMapMoveLineServerType.moveLineTypeSuperResource, gMapMoveLineStatusType.moveLineStatusTypeWorking) then
  //   return true
  // end
  return false;
}