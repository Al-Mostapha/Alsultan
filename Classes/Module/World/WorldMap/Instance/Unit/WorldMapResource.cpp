#include "WorldMapResource.h"
#include "Base/Base.create.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Building/Building.Logic.h"
#include "Base/Utils/MeshNode.h"
#include "Base/Common/Common.Func.h"

void WorldMapResource::Ctor()
{
  IWorldMapInstance::Ctor();
  _InitUI();
  _InitData();
}


void WorldMapResource::_InitData(){}

void WorldMapResource::_InitUI(){
  _ResourceImage = GDisplay::Get()->NewSprite("Map_build_food.png");
  this->addChild(_ResourceImage, -1);
  _ImageLevel = GDisplay::Get()->NewSprite("icon_map_reslevel.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint.x + 30, _CenterPoint.y - 25));
  //self.image_level:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  this->addChild(_ImageLevel, 1);
  GBase::RCreateLabelParm lParm;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "1";
  lParm._FontSize = 14;
  _ResourceLevelLabel = GBase::DCreateLabel(lParm);
  _ResourceLevelLabel->setAnchorPoint(Vec2(0.5, 0.5));
  _ResourceLevelLabel->setSkewY(25);
  _ResourceLevelLabel->setPosition(Vec2(_CenterPoint.x + 38, _CenterPoint.y - 23));
  this->addChild(_ResourceLevelLabel, 1);
  // self.resourceLevelLabel:setGroupID(worldMapDefine.GROU_ID.group_text)
  _OccupyIcon = GDisplay::Get()->NewSprite("icon_map_res_me.png");
  _OccupyIcon->setAnchorPoint(Vec2(0.5, 0));
  _OccupyIcon->setVisible(false);
  this->addChild(_OccupyIcon, 2);
  // self.occupyIcon:setGroupID(worldMapDefine.GROU_ID.group_protect)
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect(true);
  _ImageProtect->setScale(0.5);
  _ImageProtect->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y + 40));
  addChild(_ImageProtect, 1);
}

void WorldMapResource::AddCacheBefore(){
  _OccupyIcon->setVisible(false);
  _ImageProtect->setVisible(false);
  RemoveParticleNode();
}

void WorldMapResource::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){
  //self.resourceImage:setGroupID(groupID)
}

void WorldMapResource::InitInstanceData(int32 pResourceID, void *pResourceData, int32 ObjID){
  auto lData = (RResourceInitData*)pResourceData;
  _ResourceClassID = pResourceID;
  auto lImageName = WorldMapDefine::Get()->GetResourceImageName(_ResourceClassID);
  _ResourceType = WorldMapDefine::Get()->GetResourceTypeID(_ResourceClassID);
  _ResourceLevel = WorldMapDefine::Get()->GetResourceLevel(_ResourceClassID);
  _InstanceLevel = _ResourceLevel;
  _ResourceLevelLabel->setString(std::to_string(_ResourceLevel));
  _ResourceImage->setSpriteFrame(lImageName);
  UpdateData(*lData);
}

void WorldMapResource::UpdateData(const RResourceInitData &pData){
  _PlayerID = pData._PlayerID;
  _PlayerName = pData._PlayerName;
  _LeagueName = pData._LeagueName;
  _SourceID = pData._SourceID;
  UpdateEmojiByData(pData._OwnerUid, pData._Emoji);
  _CurrentSourceNum = pData._CurrentSourceNum;
  if(pData._LvBgColor == EMapResourceLvBgColorDef::Normal)
    _ImageLevel->setSpriteFrame("icon_map_reslevel.png");
  else if(pData._LvBgColor == EMapResourceLvBgColorDef::Silver)
    _ImageLevel->setSpriteFrame("icon_map_silvery.png");
  else if(pData._LvBgColor == EMapResourceLvBgColorDef::Gold)
    _ImageLevel->setSpriteFrame("icon_map_gold.png");

  _IsSafe = pData._IsSafe;
  if(_PlayerID > 0)
    SetBeOccupyed();
  else
    CancelBeOccupyed();
  UpdateSafeState();
  UpdateParticleNode();
  UpdateAllianceCounterAtkEffect(nullptr);
}

void WorldMapResource::OnMessageListener(){
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", CC_CALLBACK_1(WorldMapResource::UpdateAllianceCounter, this));
}

void WorldMapResource::UpdateAllianceCounter(EventCustom *pEvent){
  if(!pEvent)
    return;
  if(!pEvent->getUserData())
    return;
  auto lData = (GPair<EGreenPointNoticeType, int32>*)pEvent->getUserData();
  if(lData->First == EGreenPointNoticeType::COUNTER_SYS)
    UpdateAllianceCounterAtkEffect(nullptr);
}

void WorldMapResource::UpdateSafeState(){
  _ImageProtect->setVisible(_IsSafe);
}

void WorldMapResource::SetBeOccupyed(){

  _IsBeOccupyed = true;
  _OccupyIcon->setVisible(true);
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lOccupyIconName = "icon_map_res_normal.png";
  if(lSelfPlayerID == _PlayerID)
    lOccupyIconName = "icon_map_res_me.png";
  else if(lSelfLeagueID == _LeagueID)
    lOccupyIconName = "icon_map_res_alliance.png";
  else{
    auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
    if(lAllianceRelationType == EMapAllianceRelationType::ALLY)
      lOccupyIconName = "icon_map_res_bund.png";
    else if(lAllianceRelationType == EMapAllianceRelationType::FRIENDLY)
      lOccupyIconName = "icon_map_res_friend.png";
    else if(lAllianceRelationType == EMapAllianceRelationType::ENEMY)
      lOccupyIconName = "icon_map_res_enemy.png";

    if(_SourceID > 0){
      auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
      if(_SourceID != lSelfSourceID)
        lOccupyIconName = "icon_map_res_others.png";
    }
  }
  _OccupyIcon->setSpriteFrame(lOccupyIconName);
}

void WorldMapResource::CancelBeOccupyed(){
  _IsBeOccupyed = false;
  if(_OccupyIcon)
    _OccupyIcon->setVisible(false);
}

GString WorldMapResource::GetFavoriteName(){
  return WorldMapDefine::Get()->GetResourceName(_ResourceClassID);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapResource:: OnClickInstance(Node *pNode){
  auto lBuildLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Castle);
  auto lResourceLevelLimit = WorldMapDefine::Get()->GetResourceCastleLv(_ResourceClassID);
  if(lBuildLv < lResourceLevelLimit){
    auto lLv = std::to_string(lResourceLevelLimit);
    auto lWarLvl = BuildingLogic::Get()->TransFormBuildLvToWarLv(lResourceLevelLimit);
    if(lWarLvl > 0)
      lLv = Translate::i18n("common_text_1948", {{"lv", std::to_string(lWarLvl)}});
    auto lLimitString = Translate::i18n("common_text_497", {{"Level", lLv}});
    GBase::DShowMsgTip(lLimitString);
    return {nullptr, false, nullptr};
  }
  PlayClickSound();
  return OnShowWorldMapTip(pNode);
}

void WorldMapResource::PlayClickSound(){
  auto lSID = WorldMapDefine::Get()->GetResourceTypeID(_ResourceClassID);
  if(lSID == EResourceType::Gold){
    GBase::PlaySound("worldmap", 6);
  }else{
    GBase::PlaySound("innerbuildsound", 199 + static_cast<int32>(lSID));
  }
}

GVector<RButtonTypeArray> WorldMapResource::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){

  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  if(_PlayerID <= 0){
    if(pIsSelfKingdom){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::zhanLing});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
    }
    lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
  } else if(pIsSelfKingdom){
    if(_PlayerID == lSelfPlayerID){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      if(CanHasEmojiOperator(lSelfPlayerID)){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
      }
    }else if(_LeagueID > 0 && _LeagueID == lSelfLeagueID){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    }else{
      lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiangqing});
      auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
      if(lTowerLv > 1)
        lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
    }
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});
  }
  return lButtonTypeArray;
}

void WorldMapResource::UpdateParticleNode(){
  if(_ResourceType == EResourceType::Gold){
    AddParticleNode();
  } else {
    RemoveParticleNode();
  }
}

void WorldMapResource::AddParticleNode(){
  if(_ParticleNode){
    _ParticleNode->removeAllChildren();
  }else{
    _ParticleNode = GDisplay::Get()->NewNode();
    this->addChild(_ParticleNode, 1);
  }

  if(_ParticleNode){
    auto lSprite = GDisplay::Get()->NewSprite("dh_xwxuzhuang_01.png");
    GBase::DMixtureGLONE(lSprite);
    auto lFrames = GDisplay::Get()->NewFrames("dh_xwxuzhuang_%.2d.png", 1, 15);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.1111111111111111f);
    lSprite->setScale(2);
    lSprite->runAction(RepeatForever::create(Animate::create(lAnimation)));
    _ParticleNode->addChild(lSprite);
    lSprite->setAnchorPoint(Vec2(0.5, 0.25));
    lSprite->setOpacity(51);

    static GVector<RCreatEffctParam> lParam(2);
    lParam[0]._PList = "et_cwjinkuang_01.plist";
    lParam[0]._Scale = Vec2(1.5f, 1.5f);
    lParam[1]._PList = "et_cwjinkuang_02.plist";

    auto lEtNode = GBase::DCreateEffectNode(lParam);
    if(lEtNode)
      _ParticleNode->addChild(lEtNode);
  }
}

void WorldMapResource::RemoveParticleNode(){
  if(_ParticleNode)
    _ParticleNode->removeAllChildren();
}


