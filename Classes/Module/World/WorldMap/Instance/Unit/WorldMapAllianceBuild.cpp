#include "WorldMapAllianceBuild.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/AllianceBuild/UIWorldMapAllianceBuild.ProgressBar.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/Boss/UIWorldMapBoss.ProgressBar.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Pet/AlliancePet.Read.h"
#include "Module/Guild/Pet/AlliancePet.Ctrl.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Base/Utils/XTransition.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Engine/Base/UI/XUILabel.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapTilesRolygon.h"
#include "Module/City/City.Ctrl.h"

void WorldMapAllianceBuild::Ctor(){
  _ModelImage = GDisplay::Get()->NewSprite("Map_build_unionpalace.png");
  _ModelImage->setPosition(Vec2(0, 30));
  addChild(_ModelImage, -1);
  _BattleState = EMapObjStateTypeDef::Free;
  _ModelState = EMapObjStateTypeDef::Free;
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(_CenterPoint.x, _CenterPoint.y - 10);
  _ImageLeagueFlag->setVisible(false);
  addChild(_ImageLeagueFlag, 1);
  //   self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImageLeagueName->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 60));
  _ImageLeagueName->setVisible(false);
  addChild(_ImageLeagueName, 1);
  static GBase::RCreateLabelParm lParm;
  lParm._Text = "leagueName";
  lParm._FontSize = 20;
  lParm._UILabelType = GBase::EUILabelType::TTF;
  _TextLeagueName = GBase::DCreateLabel(lParm);
  _TextLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextLeagueName->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 60));
  _TextLeagueName->setVisible(false);
  addChild(_TextLeagueName, 1);
  //   self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImagePlayerName->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 80));
  _ImagePlayerName->setVisible(false);
  addChild(_ImagePlayerName, 1);
  lParm._Text = "playerName";
  _TextPlayerName = GBase::DCreateLabel(lParm);
  _TextPlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextPlayerName->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 80));
  _TextPlayerName->setVisible(false);
  addChild(_TextPlayerName, 1);
  //   self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ProgressBar = UIWorldMapAllianceBuildProgressBar::Create();
  _ProgressBar->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 85));
  _ProgressBar->setAnchorPoint(Vec2(0.5f, 0.5f));
  addChild(_ProgressBar, 1);
  _ProgressBar->setVisible(false);
  _ProgressBarPet = UIWorldMapBossProgressBar::Create();
  _ProgressBarPet->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 35));
  _ProgressBarPet->setAnchorPoint(Vec2(0.5f, 0.5f));
  addChild(_ProgressBarPet, 1);
  _ProgressBarPet->setVisible(false);
}

void WorldMapAllianceBuild::OnMessageListener(){
  GBase::DAddMessage(this, "MESSAGE_SERVER_WORLD_MAP_FORBID_MAP_OBJ_WAR", CC_CALLBACK_1(WorldMapAllianceBuild::UpdateForbidMapObjWarSatusData, this));
}

void WorldMapAllianceBuild::AddCacheBefore(){}

void WorldMapAllianceBuild::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){
  // self.modelImage:setGroupID(groupID)
}

void WorldMapAllianceBuild::UpdateForbidMapObjWarSatusData(EventCustom *pEvent){
  auto lBeginTime = KingdomMapCtrl::Get()->GetForbidMapObjWarBeginTime(EMapObjTypeDef::mapObjTypeAllianceBuild);
  stopAllActions();
  if(lBeginTime > 0){
    runAction(
      Sequence::create(
        DelayTime::create(lBeginTime), 
        CallFunc::create([this](){
          UpdateForbidMapObjWarSatusData(nullptr);
        }),
        nullptr
      )
    );
  }else{
    auto lLeftTime = KingdomMapCtrl::Get()->GetForbidMapObjWarLeftTime(EMapObjTypeDef::mapObjTypeAllianceBuild);
    UpdateStopBattleTime(lLeftTime);
  }
}

void WorldMapAllianceBuild::SetBuildSize(int32 pSize, float pRadioation){
  _Size = pSize;
  _Radioation = pRadioation;
}

void WorldMapAllianceBuild::InitInstanceData(int32 pBuildClassID, void *pData, int32 pObjID){
  auto lData = (RWorldAllianceBuildInitData *)pData;
  InitInstanceData((EMapAllianceBuildType)pBuildClassID, *lData);
}

void WorldMapAllianceBuild::InitInstanceData(EMapAllianceBuildType pBuildClassID, const RWorldAllianceBuildInitData &pData){
  _BuildClassID = pBuildClassID;
  auto lBuildinfo = WorldMapDefine::Get()->GetAllianceBuildInfo(_BuildClassID);
  if(lBuildinfo){
    SetBuildSize(lBuildinfo->_Size, lBuildinfo->_Radioation);
    _ModelImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lBuildinfo->_Image.c_str()));
  }
  UpdateData(pData);
}

EMapAllianceBuildType WorldMapAllianceBuild::GetBuildClassID(){
  return _BuildClassID;
}

int32 WorldMapAllianceBuild::GetBuildID(){
  return _BuildID;
}

void WorldMapAllianceBuild::UpdateData(const RWorldAllianceBuildInitData &pData){

  _PlayerID = pData._PlayerID;
  _PlayerName = pData._PlayerName;
  _LeagueID = pData._LeagueID;
  _LeagueName = pData._LeagueName;
  _LeagueAbbrName = pData._LeagueAbbrName;
  _LeagueFlag = pData._LeagueFlag;

  if(pData._Status == EMapObjStateTypeDef::Free && _BattleState == EMapObjStateTypeDef::Working){
    //   SoraDSendMessage({
    //     msg = "MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL",
    //     relatedTilePoints = {
    //       self.tilePoint
    //     }
    //   })
  }

  _BattleState = pData._Status;
  _ModelState = pData._ModelState;
  _WarStatus = pData._WarStatus;
  _KingStatus = pData._KingStatus;
  _BuildID = pData._ID;
  _BeastData = pData._Beast;
  _ColorID = pData._ColorID;

  UpdatePlayerInfo();
  UpdateBattleState();
  UpdateProcessBar(pData);
  UpdateForbidMapObjWarSatusData(nullptr);
  if(_BuildClassID == EMapAllianceBuildType::Altar){
    UpdateBeastInfo();
  }
}

void WorldMapAllianceBuild::UpdateBeastInfo(){
  if(!_BeastData)
    return;
  
  auto lState = _BeastData->_Status;
  if(lState == EAlliancePetState::CALL){
    if(_PetSingle){
      _PetSingle->setVisible(false);
    }
  }else{
    auto lPetType = _BeastData->_Type;
    if(!_PetSingle){
      _PetSingle = CreatePetSingle(lPetType);
    }else{
      _PetSingle->setVisible(true);
      _PetSingle->InitData(lPetType);
    }
  }
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnAid();
  if(lSelfLeagueID == _LeagueID){
    CloseAlliancePetEffect();
    if(lState == EAlliancePetState::TRIAL){
      _ProgressBarPet->SetPercent(_BeastData->_LeftLife);
      SetTrialEffectDown();
      SetTrialEffectUp();
    }else if(lState == EAlliancePetState::BLESS){
      SetBlessEffectDown();
      SetBlessEffectUp();
      _ProgressBarPet->setVisible(false);
    }else{
      _ProgressBarPet->setVisible(false);
    }
  }
}

WorldMapAllianceBuild::PetSprite *WorldMapAllianceBuild::PetSprite::Create(const GString &pSpriteName){
  auto lSprite = WorldMapAllianceBuild::PetSprite::create();
  lSprite->initWithSpriteFrameName(pSpriteName);
  return lSprite;
}

void WorldMapAllianceBuild::PetSprite::InitData(int32 pPetType){
  RWorldMapAlliancePetOffset lOffsetData;
  if(AlliancePetRead::_WorldMapPetOffset.Contains(pPetType))
    lOffsetData = AlliancePetRead::_WorldMapPetOffset[pPetType];
  else{

  }

  if(lOffsetData._Position != Vec2::ZERO){
    setPosition(lOffsetData._Position);
    setScale(lOffsetData._Scale);
  }
  auto lImgName = AlliancePetRead::Get()->GetWorldMapModel(pPetType);
  auto lFrames = GDisplay::Get()->NewFrames((lImgName + "_ws_0%d.png").c_str(), 1, 8);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 0.15f);
  stopAllActions();
  XTransition::Get()->PlayAnimationForever(this, lAnimation);
}

WorldMapAllianceBuild::PetSprite *WorldMapAllianceBuild::CreatePetSingle(int32 pPetType){
  auto lPetSingle = PetSprite::Create("ma_ws_01.png");
  addChild(lPetSingle, 0);
  // petSingle:setGroupID(worldMapDefine.GROU_ID.group_alliance_pet)
  lPetSingle->InitData(pPetType);
  return lPetSingle;
}

void WorldMapAllianceBuild::SetBlessEffectDown(){
  if(_EffectNodeDown){
    _EffectNodeDown->removeFromParent();
    _EffectNodeDown = nullptr;
  }
  
  _EffectNodeDown = GBase::DCreateAnimation("UiParts/MainUi/Alliance/Pet/jitan_down.csb").First;
  _EffectNodeDown->setPosition(Vec2(14, -13));
  _EffectNodeDown->setScale(1.3f);
  addChild(_EffectNodeDown, -1);
  for(int32 iii = 1; iii <= 4; iii++){
    auto lName = StringUtils::format("Sprite_%d", iii);
    auto lSp = GBase::DGetChildByName<Sprite *>(_EffectNodeDown, lName.c_str());
    if (lSp)
    {
      if(lSp->isOpacityModifyRGB()){
        lSp->setBlendFunc({GL_ONE, GL_ONE});
      }else{
        lSp->setBlendFunc(BlendFunc::ADDITIVE);
      }
    }
    
  }
}

void WorldMapAllianceBuild::SetBlessEffectUp(){
  if(_EffectNodeUp){
    _EffectNodeUp->removeFromParent();
    _EffectNodeUp = nullptr;
  }
  
  _EffectNodeUp = GBase::DCreateAnimation("UiParts/MainUi/Alliance/Pet/jitan_up.csb").First;
  _EffectNodeUp->setPosition(Vec2(14, -13));
  _EffectNodeUp->setScale(1.3f);
  addChild(_EffectNodeUp, 0);
  // effectNode:setGroupID(worldMapDefine.GROU_ID.group_alliance_pet)
  // effectNode:setGroupAuto(true)
  for(auto iii = 1; iii <= 10; iii++){
    auto lName = StringUtils::format("Sprite_%d", iii);
    auto lSp = GBase::DGetChildByName<Sprite *>(_EffectNodeUp, lName.c_str());
    if (lSp)
    {
      if(lSp->isOpacityModifyRGB()){
        lSp->setBlendFunc({GL_ONE, GL_ONE});
      }else{
        lSp->setBlendFunc(BlendFunc::ADDITIVE);
      }
    }
    
  }
}

void WorldMapAllianceBuild::SetTrialEffectDown(){
  
  if(_EffectNodeDown){
    _EffectNodeDown->removeFromParent();
    _EffectNodeDown = nullptr;
  }
  
  _EffectNodeDown = GBase::DCreateAnimation("UiParts/MainUi/Alliance/Pet/shilian_down.csb").First;
  _EffectNodeDown->setPosition(Vec2(10, -10));
  _EffectNodeDown->setScale(1.4f);
  addChild(_EffectNodeDown, -1);
  // effectNode:setGroupID(worldMapDefine.GROU_ID.group_alliance_pet)
  // effectNode:setGroupAuto(true)
  for(auto lV : {"Sprite_3_0"}){
    auto lSp = GBase::DGetChildByName<Sprite *>(_EffectNodeDown, lV);
    if(lSp){
      if(lSp->isOpacityModifyRGB()){
        lSp->setBlendFunc({GL_ONE, GL_ONE});
      }else{
        lSp->setBlendFunc(BlendFunc::ADDITIVE);
      }
    }
  }
}

void WorldMapAllianceBuild::SetTrialEffectUp(){
  
  if(_EffectNodeUp){
    _EffectNodeUp->removeFromParent();
    _EffectNodeUp = nullptr;
  }
  
  _EffectNodeUp = GBase::DCreateAnimation("UiParts/MainUi/Alliance/Pet/shilian_up.csb").First;
  _EffectNodeUp->setPosition(Vec2(10, -10));
  _EffectNodeUp->setScale(1.4f);
  addChild(_EffectNodeUp, 0);
  // effectNode:setGroupID(worldMapDefine.GROU_ID.group_alliance_pet)
  // effectNode:setGroupAuto(true)
  for(auto lV : {"Sprite_3"}){
    auto lSp = GBase::DGetChildByName<Sprite *>(_EffectNodeDown, lV);
    if(lSp){
      if(lSp->isOpacityModifyRGB()){
        lSp->setBlendFunc({GL_ONE, GL_ONE});
      }else{
        lSp->setBlendFunc(BlendFunc::ADDITIVE);
      }
    }
  }
}

void WorldMapAllianceBuild::CloseAlliancePetEffect(){

  if(_EffectNodeUp){
    _EffectNodeUp->removeFromParent();
    _EffectNodeUp = nullptr;
  }

  if(_EffectNodeDown){
    _EffectNodeDown->removeFromParent();
    _EffectNodeDown = nullptr;
  }

}

Color3B WorldMapAllianceBuild::GetTerritoryColor(){
  if(_ColorID > 0){
    return AllianceRead::Get()->GetTerritoryColor(_ColorID);
  }
}

void WorldMapAllianceBuild::UpdatePlayerInfo(){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnAid();
  if(_LeagueID > 0){
    auto lNameColor = Color3B(0, 200, 200);
    if(_LeagueID == lSelfLeagueID){
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
      if(_ColorID > 0){
        _RolygonColor = GetTerritoryColor();
      }else{
        _RolygonColor = lNameColor;
      }
    } else {
      EMapAllianceRelationType lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
      if(lAllianceRelationType == EMapAllianceRelationType::None)
        lAllianceRelationType = EMapAllianceRelationType::NORMAL;
      auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
      auto lIsMatchKingdom = ConquestWarCtrl::Get()->IsMatchKingdom(lSelfSourceID, _KingdomID);

      if(lIsMatchKingdom)
        lAllianceRelationType = EMapAllianceRelationType::ENEMY;
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
      if(
        (lAllianceRelationType == EMapAllianceRelationType::SELF 
        || lAllianceRelationType == EMapAllianceRelationType::NORMAL)
        && _ColorID > 0){
          _RolygonColor = GetTerritoryColor();
      }else{
        _RolygonColor = lNameColor;
      }
    }
    
    _TextLeagueName->setColor(lNameColor);
    _TextPlayerName->setColor(lNameColor);
    _ImageLeagueName->setVisible(true);
    _TextLeagueName->setVisible(true);

    if(_BuildClassID == EMapAllianceBuildType::Flag){
      _ImageLeagueFlag->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y + 45));
      _ImageLeagueFlag->setVisible(true);
      _ImageLeagueFlag->setScale(0.5f);
      _ModelImage->setScale(1.5f);
      _TextLeagueName->setString(_LeagueAbbrName);
      if(_BattleState == EMapObjStateTypeDef::Working){
        _TextLeagueName->setString(
          Translate::i18n(
            "alliance_stronghold_text_118",
            {{"name", _LeagueAbbrName}} 
          )
        );
      }
    }else{
      auto lBuildName = AllianceRead::Get()->GetBuildName(_BuildClassID);
      _TextLeagueName->setString("(" + _LeagueAbbrName + ")" + lBuildName );
      if(_BattleState == EMapObjStateTypeDef::Working){
        _TextLeagueName->setString(
          Translate::i18n(
            "alliance_stronghold_text_119",
            {{"abbr", _LeagueAbbrName}, {"name", lBuildName}}
          )
        );
      }
    }
    if(AllianceRead::Get()->GetFlagIcon(_LeagueFlag) != ""){
      _ImageLeagueFlag->setSpriteFrame(AllianceRead::Get()->GetFlagIcon(_LeagueFlag));
    }
    if(_BuildClassID == EMapAllianceBuildType::Altar){
      UpdateBeastInfo();
    }
  }

}

void WorldMapAllianceBuild::UpdateBattleState(){
    UpdateFireEffect(_BattleState);
}

void WorldMapAllianceBuild::UpdateProcessBar(const RWorldAllianceBuildInitData &pData){
  if(pData._Wall){
    auto lHurtStatus = _BattleState == EMapObjStateTypeDef::HurtDie;
    _ProgressBar->setVisible(true);
    _ProgressBar->InitData(pData, lHurtStatus);
  }
}

void WorldMapAllianceBuild::UpdateStopBattleTime(GTime pLastTime){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnAid();
  if(_LeagueID == lSelfLeagueID)
    pLastTime = 0;
  if(pLastTime > 0){
    if(!_TextStateTime){
      _ImagePtBg = GDisplay::Get()->NewSprite("frame_map_07.png");
      _ImagePtBg->setAnchorPoint(Vec2(0.5f, 0.5f));
      _ImagePtBg->setContentSize(Size(207, 120));
      _ImagePtBg->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 0));
      addChild(_ImagePtBg, 2);
      //     self.image_pt_bg:setGroupID(worldMapDefine.GROU_ID.group_level_build)
      UIFontLabelParam lParm;
      lParm._Text = Translate::i18n("Battlefield_queue_text_010");
      lParm._FontSize = 20;
      lParm._UILabelType = GBase::EUILabelType::TTF;
      _TextStateDesc = XUILabel::Create(lParm);
      _TextStateDesc->setAnchorPoint(Vec2(0.5f, 0.5f));
      _TextStateDesc->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y + 7));
      addChild(_TextStateDesc, 3);
      //     self.text_StateDesc:setGroupID(worldMapDefine.GROU_ID.group_level_build)
      lParm._Text = "00:00:00";
      auto lLabel = XUILabel::Create(lParm);
      lLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
      lLabel->setPosition(Vec2(_CenterPoint.x, _CenterPoint.y - 16));
      addChild(lLabel, 3);
      //     self.text_StateTime:setGroupID(worldMapDefine.GROU_ID.group_level_build)
      _TextStateTime = UITimerLabel::DCreateTimerLabel(lLabel);
    }
    
    _TextStateTime->RemoveTime();
    _TextStateTime->SetTimeLast([this](auto  pString, auto pTime){
      return Translate::i18n("common_text_4530", {{"time", std::to_string(pTime)}});
    });

    _TextStateTime->SetTimeUpdateListener(CC_CALLBACK_1(WorldMapAllianceBuild::UpdateStopBattleTime, this));
    _TextStateTime->BeginTime(pLastTime);
    _TextStateTime->setVisible(true);
    _ImagePtBg->setVisible(true);
    _TextStateDesc->setVisible(true);
  }
  if(pLastTime <= 0 && _TextStateTime){
    _TextStateTime->RemoveTime();
    _TextStateTime->setVisible(false);
    _ImagePtBg->setVisible(false);
    _TextStateDesc->setVisible(false);
  }
}

GString WorldMapAllianceBuild::GetFavoriteName(){
  auto lFavoriteName = _PlayerName;
  if(_BuildClassID != EMapAllianceBuildType::None){
    auto lAllianceBuild = AllianceRead::Get()->GetBuildName(_BuildClassID);
    auto lAllianceName = _LeagueAbbrName;
    lFavoriteName = Translate::i18n("common_text_186", {{"abbr", lAllianceName}, {"name", lAllianceBuild}});
  }
  return lFavoriteName;
}

void WorldMapAllianceBuild::PlayClickSound(){
  GBase::PlaySound("innerbuildsound", 119);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapAllianceBuild::OnClickInstance(Node *pNode){
  PlayClickSound();
  auto [lSelectShowPanel, lBool, lNode] = OnShowWorldMapTip(pNode);
  auto lTilesRolygon = WorldMapTilesRolygon::Create(_Size + 2 * _Radioation);
  lTilesRolygon->SetRolygonColor(_RolygonColor);
  return {lSelectShowPanel, true, lTilesRolygon};
}

GVector<RButtonTypeArray> WorldMapAllianceBuild::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){

  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnAid();
  if(!pIsSelfKingdom)
    return lButtonTypeArray;
  if(_BuildClassID == EMapAllianceBuildType::Altar){
    if(lSelfLeagueID == _LeagueID){
      auto lState = AlliancePetCtrl::Get()->GetAlliancePetState();
      if(lState == EAlliancePetState::CALL){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::alliancepet_1});
      }else if(lState == EAlliancePetState::DONATE){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::alliancepet_2});
      }else if(lState == EAlliancePetState::TRIAL){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::alliancepet_3});
      }else if(lState == EAlliancePetState::BLESS){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::alliancepet_4});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanxiangqing});
    }else{
      lButtonTypeArray.push_back({EWorldMapTipButtonType::shuoMing});
    }
  } else if(lSelfLeagueID == _LeagueID){
    if(_BattleState == EMapObjStateTypeDef::Working){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::jianzao});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanzhujun});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanxiangqing});
    }else{
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xiefang});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanzhujun});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanxiangqing});
    }
    if(std::get<0>(CheckHasArmy())){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::fanHui});
    }
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
    auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
    if(lHaveHall && _LeagueID > 0){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
    }
    lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha});
  }
  return  lButtonTypeArray;
}