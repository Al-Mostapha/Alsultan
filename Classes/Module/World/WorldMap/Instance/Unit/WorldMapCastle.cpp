#include "WorldMapCastle.h"
#include "Engine/Base/UI/XUILabel.h"
#include "Base/Common/Common.Func.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Building/Config/PalaceInfo.Read.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/UI/Panel/World/Kingdom/City/UIWorldMapKingdomCityState.View.h"
#include "Module/City/City.Ctrl.h"

void WorldMapCastle::Ctor(){
  _InitUI();
  _InitData();
}

void WorldMapCastle::_InitData(){
  _PlayerID = 0;
  _PlayerName = "";
  _LeagueID = 0;
  _LeagueName = "";
  _LeagueFlag = 1;
  _WarStatus = EKingdomWarStatusType::close;
  _KingStatus = EKingStatus::None;
  _CastleState = EMapObjStateTypeDef::Free;
  _EmojiID = 0;
}


void WorldMapCastle::_InitUI(){
  _BgImage = GDisplay::Get()->NewSprite("Map_King_castle_01.png");
  _BgImage->setAnchorPoint(Vec2(0.52f, 0.39f));
  addChild(_BgImage, -1);
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtect();
  _ImageProtect->setScale(1.8f);
  _ImageProtect->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y + 70));
  addChild(_ImageProtect, 1);
  _ImageState = GDisplay::Get()->NewScale9Sprite("frame_protect_bubble_01.png", {0, 0}, Size(200, 120), Rect(50, 20, 3, 3));
  _ImageState->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y + 325));
  addChild(_ImageState, 1);
  _ImageState->setVisible(false);
  auto lSizeState = _ImageState->getContentSize();
  auto lImageLine = GDisplay::Get()->NewSprite("frame_protect_line_01.png");
  lImageLine->setAnchorPoint(Vec2(0.5f, 0.5f));
  lImageLine->setPosition(Vec2(lSizeState.width / 2, lSizeState.height / 2 + 15));
  lImageLine->setScaleX(2);
  _ImageState->addChild(lImageLine);
  
  _TextStateTitle = ui::Text::create();
  _TextStateTitle->setFontSize(20);
  _TextStateTitle->setColor(Color3B(200, 0, 0));
  _ImageState->addChild(_TextStateTitle, 1);
  _TextStateTitle->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextStateTitle->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _TextStateTitle->setTextVerticalAlignment(TextVAlignment::CENTER);
  _TextStateTitle->setPosition(Vec2(lSizeState.width / 2, lSizeState.height / 2 + 35));
  _TextStateTitle->setTextAreaSize(Size(160, 40));
  _TextStateTitle->setContentSize(Size(160, 40));
  _TextStateTitle->ignoreContentAdaptWithSize(false);

  UIFontLabelParam lLabelParam;
  lLabelParam._UILabelType = GBase::EUILabelType::TTF;
  lLabelParam._Text = "00:00:00";
  lLabelParam._FontSize = 20;
  _TextStateTime = UITimerLabel::DCreateTimerLabel(XUILabel::Create<Label>(lLabelParam));
  _TextStateTime->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextStateTime->setPosition(Vec2(lSizeState.width / 2, lSizeState.height / 2 - 10));
  _ImageState->addChild(_TextStateTime, 1);
  _TextStateTime->SetTimeEndListener([]() {});
  _ImageReady = GDisplay::Get()->NewScale9Sprite("title_main_build.png", {0, 0}, Size(450, 45));
  _ImageReady->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y - 250));
  addChild(_ImageReady, 1);
  _ImageReady->setVisible(false);
  auto lSizeReady = _ImageReady->getContentSize();
  UIFontLabelParam lTextReadyParam;
  lTextReadyParam._UILabelType = GBase::EUILabelType::TTF;
  lTextReadyParam._Text = Translate::i18n("common_text_1445");
  lTextReadyParam._FontSize = 16;
  _TextReady = XUILabel::Create<Label>(lTextReadyParam);
  _TextReady->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextReady->setPosition(Vec2(lSizeReady.width / 2, lSizeReady.height / 2));
  _TextReady->setColor(Color3B(200, 200, 0));
  _ImageReady->addChild(_TextReady, 1);
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true));
  _ImageLeagueFlag->setScale(0.3f);
  _ImageLeagueFlag->setPosition(Vec2(_CenterPoint.x - 147, _CenterPoint.y - 10));
  _ImageLeagueFlag->setVisible(false);
  addChild(_ImageLeagueFlag, 1);
  // self.image_LeagueFlag:setGroupID(worldMapDefine.GROU_ID.group_flag)
  _ImageLeagueName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImageLeagueName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 35));
  _ImageLeagueName->setVisible(false);
  addChild(_ImageLeagueName, 1);
  // self.image_league_name:setGroupID(worldMapDefine.GROU_ID.group_level_build)
  GBase::RCreateLabelParm lTextLeagueNameParam;
  lTextLeagueNameParam._UILabelType = GBase::EUILabelType::TTF;
  lTextLeagueNameParam._Text = "leagueName";
  lTextLeagueNameParam._FontSize = 20;
  _TextLeagueName = GBase::DCreateLabel(lTextLeagueNameParam);
  _TextLeagueName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextLeagueName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 35));
  _TextLeagueName->setVisible(false);
  addChild(_TextLeagueName, 1);
  // self.text_league_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
  _ImagePlayerName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImagePlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _ImagePlayerName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  _ImagePlayerName->setVisible(false);
  addChild(_ImagePlayerName, 1);
  GBase::RCreateLabelParm lTextPlayerNameParam;
  lTextPlayerNameParam._UILabelType = GBase::EUILabelType::TTF;
  lTextPlayerNameParam._Text = "playerName";
  lTextPlayerNameParam._FontSize = 20;
  _TextPlayerName = GBase::DCreateLabel(lTextPlayerNameParam);
  _TextPlayerName->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TextPlayerName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  _TextPlayerName->setVisible(false);
  addChild(_TextPlayerName, 1);
  // self.text_player_Name:setGroupID(worldMapDefine.GROU_ID.group_text)
}

void WorldMapCastle::OnMessageListener(){
}

void WorldMapCastle::AddCacheBefore(){
  _ImageProtect->setVisible(false);
  _TextStateTime->RemoveTime();
  RemoveSkinEffect();
  _BgImage->setSpriteFrame("Map_King_castle_01.png");
}

void WorldMapCastle::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){
  // self.bgImage:setGroupID(groupID)
}

void WorldMapCastle::InitInstanceData(const RWorldCastleInitData &pData){
  // self:updateData(castleData)
  UpdateData(pData);
}

void WorldMapCastle::UpdateData(const RWorldCastleInitData &pData){
  _BgImage->setPositionX(0);
  if(pData._Model){
    auto lCastleImg = PalaceInfoRead::Get()->GetImg(pData._Model.value());
    if(!lCastleImg.empty()){
      _BgImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lCastleImg.c_str()));
      if(WorldMapUtil::Get()->_CastleModelCfg.Contains(pData._Model.value())){
        _BgImage->setPositionX(WorldMapUtil::Get()->_CastleModelCfg[pData._Model.value()]);
      }
      
      if(pData._Model.value() == 7){
        AddSkinEffect();
      }else{
        RemoveSkinEffect();
      }
      if(pData._Model.value() == 11){
        AddRamadanCeremonyEffect(pData._Model.value());
      }else{
        RemoveRamadanCeremonyEffect(pData._Model.value());
      }
      if(pData._Model.value() == 12){
        AddRamadanCeremonyEffect(pData._Model.value());
      }else{
        RemoveRamadanCeremonyEffect(pData._Model.value());
      }
    }
  }
  
  _PlayerID = pData._PlayerID;
  _PlayerName = pData._PlayerName;
  _LeagueID = pData._LeagueID;
  _IsSelfIn = pData._IsSelfIn;
  _SourceID = pData._SourceKid;
  _LeagueName = pData._LeagueName;
  _LeagueAbbrName = pData._LeagueAbbrName;
  _LeagueFlag = pData._LeagueFlag;

  bool lUpdateStatue = false;
  if(pData._WarStatus){
    lUpdateStatue = true;
    _WarStatus = pData._WarStatus.value();
  }
  if(pData._KingStatus){
    _KingStatus = pData._KingStatus.value();
  }
  if(pData._ShowWarStatusTime){
    lUpdateStatue = true;
    _ShowWarStatusTime = pData._ShowWarStatusTime.value();
  }
  if(pData._WarStatusEndTime){
    lUpdateStatue = true;
    //_WarStatusTime = WorldMapUtil::Get()->GetWarStatusTime(pData);
  }
  if(pData._Status){
    _CastleState = pData._Status.value();
  }
  UpdateEmojiByData(pData._OwnerId, pData._EmojiId);
  UpdatePlayerInfo();
  if(lUpdateStatue)
    UpdateSafeState();
  UpdateCastleState();
}

void WorldMapCastle::UpdatePlayerInfo(){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  if(_WarStatus == EKingdomWarStatusType::inWar && _LeagueID > 0){
    auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
    if(_SourceID > 0 && _SourceID != lSelfSourceID){
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

void WorldMapCastle::UpdateSafeState(){
  if(_WarStatus == EKingdomWarStatusType::close){
    _ImageReady->setVisible(true);
  }else{
    _ImageReady->setVisible(false);
  }

  if(_ShowWarStatusTime){
    if(_WarStatus == EKingdomWarStatusType::inWar){
      _TextStateTitle->setString(Translate::i18n("common_text_1446"));
      _TextStateTitle->setColor(Color3B(200, 0, 0));
    } else if(_WarStatus == EKingdomWarStatusType::rule){
      _TextStateTitle->setString(Translate::i18n("common_text_690"));
      _TextStateTitle->setColor(Color3B(0, 200, 0));
    } else if(_WarStatus == EKingdomWarStatusType::close){
      _TextStateTitle->setString(Translate::i18n("common_text_1215"));
      _TextStateTitle->setColor(Color3B(0, 200, 0));
    }
    _ImageState->setVisible(true);
    _TextStateTime->BeginTime(_ShowWarStatusTime);
  }else{
    _ImageState->setVisible(false);
  }
  if(_WarStatus == EKingdomWarStatusType::inWar){
    _ImageProtect->setVisible(false);
  }else{
    _ImageProtect->setVisible(true);
  }
}

void WorldMapCastle::UpdateCastleState(){
  UpdateFireEffect(_CastleState);
}

void WorldMapCastle::AddSkinEffect(){
  auto lEtNode = getChildByName("skinBgEffectNode");
  if(lEtNode)
    return;
  lEtNode  = GDisplay::Get()->NewNode();
  lEtNode->setName("skinBgEffectNode");
  lEtNode->setPosition(Vec2(_CenterPoint.x - 16.5f, _CenterPoint.y + 78.5f));
  addChild(lEtNode);
  GVector<RCreatEffctParam> lParam(5);
  lParam[0]._PList = "et_wjcz_01.plist";
  lParam[0]._Pos = Vec2(-211.17f, -67.99f);
  lParam[0]._Scale = Vec2(0.77f, 0.77f);
  lParam[0]._Rotate = 30.34f;
  lParam[1]._PList = "et_wjcz_01.plist";
  lParam[1]._Pos = Vec2(78.45f, 105.31f);
  lParam[1]._Scale = Vec2(0.65f, 0.65f);
  lParam[1]._Rotate = 30.32f;
  lParam[2]._PList = "et_wjcz_01.plist";
  lParam[2]._Pos = Vec2(199.11f, 53.21f);
  lParam[2]._Scale = Vec2(0.65f, 0.65f);
  lParam[2]._Rotate = 30.32f;
  lParam[3]._PList = "et_wjcz_02.plist";
  lParam[3]._Pos = Vec2(-42.61f, -40.76f);
  lParam[3]._Rotate = -22.85f;
  lParam[4]._PList = "et_wjcz_03.plist";
  lParam[4]._Pos = Vec2(-138.56f, 267.45f);
  lParam[4]._Scale = Vec2(1.05f, 1.1f);
  
  auto lParNode = GBase::DCreateEffectNode(lParam);
  lParNode->setPosition(Vec2(20.2f, -13.83f));
  lEtNode->addChild(lParNode);
  GVector<Sprite*> lDhSprites;
  GVector<FiniteTimeAction*> lActions;
  GVector<GPair<GString, Vec2>> lDhConfig(9);
  lDhConfig[0] = {"image_wjcz_01.png", Vec2(70.0f, 143.0f)};
  lDhConfig[1] = {"image_wjcz_03.png", Vec2(-36.0f, -9.0f)};
  lDhConfig[2] = {"image_wjcz_04.png", Vec2(-114.5f, 166.0f)};
  lDhConfig[3] = {"image_wjcz_05.png", Vec2(224.3f, 82.8f)};
  lDhConfig[4] = {"image_wjcz_06.png", Vec2(-266.5f, 60.7f)};
  lDhConfig[5] = {"image_wjcz_07.png", Vec2(63.4f, -59.7f)};
  lDhConfig[6] = {"image_wjcz_08.png", Vec2(94.25f, -121.0f)};
  lDhConfig[7] = {"image_wjcz_09.png", Vec2(221.7f, -79.3f)};
  lDhConfig[8] = {"image_wjcz_10.png", Vec2(218.8f, -86.7f)};

  for(auto lOneConfig : lDhConfig){
    lDhSprites.push_back(GDisplay::Get()->NewSprite(lOneConfig.First));
    lDhSprites.back()->setPosition(lOneConfig.Second);
    lEtNode->addChild(lDhSprites.back());
    auto lSeq = Sequence::create(
      FadeOut::create(1.0f), 
      DelayTime::create(0.2f), 
      FadeIn::create(1.0f), 
      DelayTime::create(0.2f), 
      nullptr
    );
    lActions.push_back(RepeatForever::create(lSeq));
    lDhSprites.back()->runAction(lActions.back());
  }
  
}

void WorldMapCastle::RemoveSkinEffect(){
  if(getChildByName("skinBgEffectNode")){
    removeChildByName("skinBgEffectNode");
  }
}

void WorldMapCastle::AddRamadanCeremonyEffect(int32 pModel){

  if(pModel == 11){
    if(!_EffectNode_11){
      auto lPath = "UiParts/Panel/World/WorldMap/Floor/Effect/ramadanCeremonyCastle_effect_4.csb";
      _EffectNode_11 = GBase::DCreateCSBNode(lPath);
      addChild(_EffectNode_11);
      GBase::DCreateAnimation(lPath, _EffectNode_11, true);
    } else {
      _EffectNode_11->setVisible(true);
    }
    auto lDeltaPosX = Vec2(_BgImage->getContentSize().width * (0.5f - _BgImage->getAnchorPoint().x), _BgImage->getContentSize().height * (0.5f - _BgImage->getAnchorPoint().y));
    _EffectNode_11->setPosition(_BgImage->getPosition() + lDeltaPosX);
  }else if(pModel == 12){
    if(!_EffectNode_12){
      auto lPath = "UiParts/Panel/World/WorldMap/Floor/Effect/ramadanCeremonyCastle_effect_5.csb";
      _EffectNode_12 = GBase::DCreateCSBNode(lPath);
      addChild(_EffectNode_12);
      GBase::DCreateAnimation(lPath, _EffectNode_12, true);
    }else{
      _EffectNode_12->setVisible(true);
    }
    auto lDeltaPosX = Vec2(_BgImage->getContentSize().width * (0.5f - _BgImage->getAnchorPoint().x), _BgImage->getContentSize().height * (0.5f - _BgImage->getAnchorPoint().y));
    _EffectNode_12->setPosition(_BgImage->getPosition() + lDeltaPosX);
  }
}

void WorldMapCastle::RemoveRamadanCeremonyEffect(int32 pModel){
  if(pModel == 11){
    if(_EffectNode_11){
      _EffectNode_11->removeFromParent();
      _EffectNode_11 = nullptr;
    }
  }else if(pModel == 12){
    if(_EffectNode_12){
      _EffectNode_12->removeFromParent();
      _EffectNode_12 = nullptr;
    }
  }
}

GTuple<UIBasePanel *, bool, Node*> WorldMapCastle::OnClickInstance(Node *pNode){
  PlayClickSound();
  if(_WarStatus == EKingdomWarStatusType::close){
    auto lShowRolygon = false;
    auto lPanel = UIWorldMapKingdomCityStateView::Create();
    lPanel->InitView(_WarStatusTime);
    lPanel->Show();
    return {nullptr, lShowRolygon, nullptr};
  }
  return OnShowWorldMapTip(pNode);
}

void WorldMapCastle::PlayClickSound(){
  GBase::PlaySound("worldmap", 18);
}

GVector<RButtonTypeArray> WorldMapCastle::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();

  if(pIsSelfKingdom){
    if(_WarStatus == EKingdomWarStatusType::inWar){
      if(lSelfLeagueID > 0){
        if(_LeagueID == 0){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi});
          auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
          if(lHaveHall && lSelfLeagueID > 0){
            lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan});
          }
        } else if(lSelfLeagueID == _LeagueID){
          if(_IsSelfIn && std::get<0>(CheckHasArmy())){
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
        }else{
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
    }else if(_WarStatus == EKingdomWarStatusType::rule){
      if(_KingStatus == EKingStatus::king){
        lButtonTypeArray.push_back({EWorldMapTipButtonType::guanliWangguo});
        if(CanHasEmojiOperator()){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
        }
      }else{
        lButtonTypeArray.push_back({EWorldMapTipButtonType::guanZhi});
      }
      lButtonTypeArray.push_back({EWorldMapTipButtonType::intetior});
    }
  }else{
    lButtonTypeArray.push_back({EWorldMapTipButtonType::guanZhi});
    lButtonTypeArray.push_back({EWorldMapTipButtonType::intetior});
  }
  lButtonTypeArray.push_back({EWorldMapTipButtonType::zhuangTai});
  return lButtonTypeArray;
}
