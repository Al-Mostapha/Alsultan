#include "WorldMapBuilding.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapFireWorkEffect.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/Skin/Castle/CastleSkin.Read.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Functions/ServiceFunction.h"

void WorldMapBuilding::Ctor(){
  _InitData();
  _InitUI();
}

void WorldMapBuilding::_InitData(){
  auto lIsShowOfficeIcon = GBase::DConfigGet<bool>("Game:worldMapOfficeIcon:OfficeIcon~bool", true);
  if(!lIsShowOfficeIcon){
    lIsShowOfficeIcon = true;
  }
  auto lIsShowPrisionIcon = GBase::DConfigGet<bool>("Game:castleChangeSetting:PrisonHeroIcon~bool", true);
  if(!lIsShowPrisionIcon){
    lIsShowPrisionIcon = true;
  }
  _IsShowOffice = lIsShowOfficeIcon.value();  
  _IsShowPrision = lIsShowPrisionIcon.value();
}

void WorldMapBuilding::_InitUI(){
  _CityImage = GDisplay::Get()->NewSprite("Castle_lv1_base.png");
  addChild(_CityImage, -1);
  _CitySkin1Image = GDisplay::Get()->NewSprite("Castle_ramadan.png");
  _CitySkin1Image->setVisible(false);
  addChild(_CitySkin1Image, -1);
  _ImageLeagueFlag = GDisplay::Get()->NewSprite(AllianceRead::Get()->GetFlagIcon(_LeagueFlag, true).c_str());
  _ImageLeagueFlag->setScale(0.3);
  _ImageLeagueFlag->setPosition(Vec2(_CenterPoint.x - 147, _CenterPoint.y - 10));
  _ImageLeagueFlag->setVisible(false);
  addChild(_ImageLeagueFlag, 2);
  _ImageCrown = GDisplay::Get()->NewSprite("icon_map_mycastle.png");
  _ImageCrown->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 64));
  _ImageCrown->setVisible(false);
  addChild(_ImageCrown, 4);
  // self.image_crown:setGroupID(GROU_ID.group_protect)
  _ImageZhencha = GDisplay::Get()->NewSprite("icon_spy_01.png");
  _ImageZhencha->setPosition(Vec2(_CenterPoint.x - 80, _CenterPoint.y - 80));
  _ImageZhencha->setVisible(false);
  _ImageZhencha->setScale(0.5);
  addChild(_ImageZhencha, 3);
  // self.image_zhencha:setGroupID(GROU_ID.group_protect)
  _ImageNameBg = GDisplay::Get()->NewSprite("frame_map_18.png");
  _ImageNameBg->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameBg->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 84));
  addChild(_ImageNameBg, 3);
  // self.image_name_bg:setGroupID(GROU_ID.group_level_build)
  _ImageName = GDisplay::Get()->NewSprite("frame_map_07.png");
  _ImageName->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 80));
  addChild(_ImageName, 3);
  // self.image_name:setGroupID(GROU_ID.group_level_build)
  static GBase::RCreateLabelParm lParm;
  lParm.UILabelType = GBase::EUILabelType::TTF;
  lParm.Txt = "";
  lParm.fontSize = 20;
  _TextName = GBase::DCreateLabel(lParm);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 90));
  addChild(_TextName, 4);
  // self.text_Name:setGroupID(GROU_ID.group_text)
  _ImageLevel = GDisplay::Get()->NewSprite("icon_map_reslevel.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint.x + 60, _CenterPoint.y - 50));
  addChild(_ImageLevel, 2);
  lParm.Txt = "1";
  lParm.fontSize = 14;
  _TextLevel = GBase::DCreateLabel(lParm);
  _TextLevel->setAnchorPoint(Vec2(0.5, 0.5));
  _TextLevel->setSkewY(25);
  _TextLevel->setPosition(Vec2(_CenterPoint.x + 68, _CenterPoint.y - 48));
  addChild(_TextLevel, 2);
  // self.text_Level:setGroupID(GROU_ID.group_text)
  _ImageNameBgSkin = GDisplay::Get()->NewSprite("frame_castle_name_01.png");
  _ImageNameBgSkin->setAnchorPoint(Vec2(0.5, 0.5));
  _ImageNameBgSkin->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 78));
  _ImageNameBgSkin->setScale(1);
  addChild(_ImageNameBgSkin, 3);
  _ImageNameBgSkin->setVisible(false);
  _ImageProtect = WorldMapDefine::Get()->CreateWorldMapProtectNew();
  _ImageProtect->setScale(0.7);
  _ImageProtect->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y + 70));
  addChild(_ImageProtect, 4);
  _NecklaceNode = GDisplay::Get()->NewNode();
  _NecklaceIcon = GDisplay::Get()->NewSprite("equip_01_6100111.png");
  _NecklaceIcon->setAnchorPoint(Vec2(0.5, 0.5));
  _NecklaceIcon->setScale(0.5);
  _NecklaceIcon->setName("necklaceIcon");
  _NecklaceNode->addChild(_NecklaceIcon);
  _NecklaceIcon->setPosition(Vec2(0, 0));
  auto lImageName = GDisplay::Get()->NewSprite("frame_map_07.png");
  lImageName->setAnchorPoint(Vec2(0.5, 0.5));
  lImageName->setPosition(Vec2(0, -50));
  _NecklaceNode->addChild(lImageName);
  lParm.Txt = "";
  lParm.fontSize = 14;
  auto lNecklaceName = GBase::DCreateLabel(lParm);
  lNecklaceName->setAnchorPoint(Vec2(0.5, 0.5));
  _NecklaceNode->addChild(lNecklaceName);
  lNecklaceName->setName("necklaceName");
  lNecklaceName->setPosition(0, -50);
  // necklaceName:setGroupID(GROU_ID.group_text)
  _NecklaceNode->setPosition(Vec2(_CenterPoint.x + 0, _CenterPoint.y + 150));
  _NecklaceNode->setVisible(false);
  addChild(_NecklaceNode, 4);
  _BulletNode = GDisplay::Get()->NewNode();
  addChild(_BulletNode, 4);
  _WarLVNode = GDisplay::Get()->NewNode();
  addChild(_WarLVNode);
  _NodeWarLvNode = nullptr;
  _SignNode = GDisplay::Get()->NewNode();
  addChild(_SignNode, 4);
  _SignNode->setPosition(Vec2(_CenterPoint.x + 40, _CenterPoint.y - 0));
  // signNode:setGroupID(GROU_ID.group_sign)
  // signNode:setGroupAuto(true)
  _SignImage = ui::ImageView::create("frame_ssdt_qmk01.png", ui::Widget::TextureResType::PLIST);
  _SignImage->setScale9Enabled(true);
  _SignImage->setCapInsets(Rect(40, 40, 10, 10));
  _SignNode->addChild(_SignImage);
  _SignImage->setOpacity(204);
  _SignText = ui::Text::create();
  _SignText->setColor(Color3B(80, 50, 0));
  _SignText->setAnchorPoint(Vec2(0.5, 0.5));
  _SignNode->addChild(_SignText);
  GBase::DSetTextWidthHeight(_SignText, Size(130, 35));
  _SignText->setPosition(Vec2(0, 12));
  _SignText->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _SignText->setTextVerticalAlignment(TextVAlignment::CENTER);
  _SignText->setFontSize(20);
  RefreshSignShow(false);
}

void WorldMapBuilding::OnMessageListener(){
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_TOGGLE_3D", CC_CALLBACK_1(WorldMapBuilding::Toggle3D, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_ENEMY_CASTLE_EFFECT", CC_CALLBACK_1(WorldMapBuilding::SetWarPlayerInfo, this));
  GBase::DAddMessage(this, "MESSAGE_WALLS_NOTIFY_TRIAL_WARNING", CC_CALLBACK_1(WorldMapBuilding::UpdateWallWarning, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_CASTLE_OFFICEICON", CC_CALLBACK_1(WorldMapBuilding::UpdateOfficeIcon, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_TITLE_SHOW", CC_CALLBACK_1(WorldMapBuilding::UpdateOfficeIcon, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_CASTLE_PRISIONICON", CC_CALLBACK_1(WorldMapBuilding::UpdatePrisionIcon, this));
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", CC_CALLBACK_1(WorldMapBuilding::UpdateAllianceCounter, this));
}

void WorldMapBuilding::RefreshSignShow(bool pIsShow){
  if(!_Signature.empty())
  {
    _SignNode->setVisible(pIsShow);
  }
  else
  {
    _SignNode->setVisible(false);
  }
}

void WorldMapBuilding::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){
  // self.cityImage:setGroupID(groupID)
  // self.cityImage:setGroupAuto(true)
}

bool WorldMapBuilding::IsInAllianceWar(){
  if(_InMapID == 0)
    return false;
  return _InMapID != _KingdomID;
}

void WorldMapBuilding::AddCacheBefore(){
  _CityImage->setPosition(Vec2::ZERO);
  _CityImage->removeAllChildren();
  _CitySkin1Image->removeAllChildren();

  RemoveSkinEffect();
  RemoveWarLvEffect();

  if(_OfficalImage){
    _OfficalImage->setVisible(false);
    _OfficalIcon->removeAllChildren();  
  }
  
  _ImageLeagueFlag->setVisible(false);
  _ImageCrown->setVisible(false);
  _ImageZhencha->setVisible(false);
  _ImageProtect->setVisible(false);

  RemovePyramidProtectEffect();
  RemoveCastleEffect();
  RemoveCastleFireWorkEffect();
  RemoveEnemyCastleEffect();

  if(_FireNodeEx){
    _FireNodeEx->removeFromParent();
    _FireNodeEx = nullptr;
  }
  _MoveCityTime = 0;
  if(_NodeMoveCityTime){
    _NodeMoveCityTime->setVisible(false);
    if(_TxtMoveCityTime){
      _TxtMoveCityTime->RemoveTime();
    }
  }
  if(_TipsNode){
    _TipsNode->removeFromParent();
    _TipsNode = nullptr;
  }
  _WarCamp = 0;
}

void WorldMapBuilding::SetSkinGroupID(EBuildingCastleModel pModel){
  // local cityBuildCastleSkinConfig = include("cityBuildCastleSkinConfig")
  // local skinType = cityBuildCastleSkinConfig.getOwnTexture(model)
  // local groupID = tableCastleTable[skinType]
  // if groupID then
  //   self.citySkin1Image:setGroupID(groupID)
  //   self.citySkin1Image_groupID = groupID
  // end
}

void WorldMapBuilding::InitCityData(const RWorldBuildingInitData &pData){
  // self:updateData(data)
  UpdateData(pData);
}

void WorldMapBuilding::UpdateData(const RWorldBuildingInitData &pData){
  // local selfPlayerID = gametop.playertop_:getPlayerID() or 0
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  // local selfLeagueID = allianceMgr:getOwnTeamID()
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  // self.data = data
  // if data.playerID then
  //   self.playerID = data.playerID
  // end
  _PlayerID = pData._PlayerID;
  // if data.playerName then
  //   self.playerName = data.playerName
  // end
  _PlayerName = pData._PlayerName;
  // if data.playerLevel then
  //   self.playerLevel = data.playerLevel
  // end
  _PlayerLevel = pData._PlayerLevel;
  // if data.inMapId then
  //   self.inMapId = data.inMapId
  // end
  _InMapID = pData._InMapID;
  // if data.hideBattleLev ~= nil then
  //   self.hideBattleLev = data.hideBattleLev
  // end
  _HideBattleLev = pData._HideBattleLev;
  //   if data.official then
  //     self.officialType = data.official
  //   end
  _OfficialType = pData._Official;
  //   if data.worldOfficial then
  //     self.leaguedOfficialType = data.worldOfficial
  //   end
  _LeaguedOfficialType = pData._WorldOfficial;
  //   if data.legendForSepOfficial then
  //     self.kingStarOfficialType = data.legendForSepOfficial
  //   end
  _KingStarOfficialType = pData._LegendForSepOfficial;
  //   if data.hegemonOfficial then
  //     self.hegemonOfficialType = data.hegemonOfficial
  //   end
  _HegemonOfficialType = pData._HegemonOfficialType;
  //   if data.showOfficialType then
  //     self.showOfficialType = data.showOfficialType
  //   end
  _ShowOfficialType = pData._ShowOfficialType;
  //   if data.atlantisOfficialType then
  //     self.atlantisOfficialType = data.atlantisOfficialType
  //   end
  _AtlantisOfficialType = pData._AtlantisOfficialType;
  //   if data.nebulaOfficialID then
  //     self.nebulaOfficialID = data.nebulaOfficialID
  //   end
  _NebulaOfficialID = pData._NebulaOfficialID;
  //   if data.nebulaOfficialID2 then
  //     self.nebulaOfficialID2 = data.nebulaOfficialID2
  //   end
  _NebulaOfficialID2 = pData._NebulaOfficialID2;
  //   self:updateOfficial()
  UpdateOfficial();
  //   self:updateTopShowIcons()
  UpdateTopShowIcons();
  // if data.factionType then
  //   self.factionType = data.factionType
  // end
  _FactionType = pData._FactionType;
  // self:updateEmojiByData(data)
  UpdateEmojiByData(pData._PlayerID, pData._EmojiID);
  // if data.prisonerNum ~= nil then
  //   self.prisonerNum = data.prisonerNum
  //   self:updatePrisoneIn()
  //   self:updateTopShowIcons()
  // end
  if(pData._PrisonerNum){
    _PrisonerNum = pData._PrisonerNum;
    UpdatePrisoneIn();
    UpdateTopShowIcons();
  }
  
  if(pData._Betray){
    _Betray = pData._Betray;
    if(pData._Betray > 0){
      if(ConquestWarCtrl::Get()->GetConquestWarState() == EConquestWarState::OPENING){
        auto lHeadIcon = getChildByName<ui::Button *>("Image_betrayFrm");
        if(!lHeadIcon){
        lHeadIcon = ui::Button::create("icon_alliance_traitor.png", "icon_alliance_traitor.png", "icon_alliance_traitor.png", ui::Widget::TextureResType::PLIST);
        lHeadIcon->setScale(0.5);
        lHeadIcon->setPosition(Vec2(_CenterPoint.x + 100, _CenterPoint.y - 82));
        addChild(lHeadIcon, 2);
        lHeadIcon->setName("Image_betrayFrm");
        lHeadIcon->addClickEventListener([=](Ref *pSender){
          GBase::DShowMsgBox(Translate::i18n("common_text_4144"), Translate::i18n("common_text_204"));
        });
        }
        lHeadIcon->setVisible(true);
      }
    }else{
      auto lHeadIcon = getChildByName<ui::Button *>("Image_betrayFrm");
      if(lHeadIcon){
        lHeadIcon->setVisible(false);
      }
    }
  }
  
  if(pData._CityLevel){
    _CityLevel = pData._CityLevel;
    _InstanceLevel = _CityLevel;
    auto [lIsShowWarLv ,lTextShowLV, lDes] = GBase::DGetBuildWarLv(_CityLevel);
    _IsShowWarLv = lIsShowWarLv;
    if(_IsShowWarLv){
      _ImageLevel->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("icon_main_build_warlv.png"));
      //     self.image_level:setGroupID(0)
      _ImageLevel->setPosition(Vec2(_CenterPoint.x + 90, _CenterPoint.y - 50));
      _TextLevel->setPosition(Vec2(_CenterPoint.x + 110, _CenterPoint.y - 49));
    }else{
      _ImageLevel->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("icon_main_build_lv.png"));
      //     self.image_level:setGroupID(GROU_ID.group_level_build)
      _ImageLevel->setPosition(Vec2(_CenterPoint.x + 60, _CenterPoint.y - 50));
      _TextLevel->setPosition(Vec2(_CenterPoint.x + 80, _CenterPoint.y - 43));
    }
    _TextLevel->setString(lTextShowLV);
    UpdateBuildingImg();
  }

  _LeagueID = pData._LeagueID;
  _LeagueName = pData._LeagueName;
  _LeagueFlag = pData._LeagueFlag;
  _NecklaceID = pData._NecklaceID;
  _WarCamp = pData._Camp;
  if(pData._LeagueID){
    UpdateLeagueInfo();
  }
  _BuildingState = pData._Status;
  _IsSafe = pData._IsSafe;
  if(pData._HasScoutRecord){
    _ImageZhencha->setVisible(true);
  }else{
    _ImageZhencha->setVisible(false);
  }
  _SourceID = pData._SourceKid;
  _SourceKingdomID = pData._KingdomId;
  auto lTextName = _PlayerName;
  if(_LeagueID > 0 && !_LeagueName.empty()){
    lTextName = "(" + _LeagueName + ")" + _PlayerName;
    _TextName->setString(lTextName);
  }
  
  auto lNameColor = GDisplay::Get()->COLOR_WHITE;
  if(_PlayerID == lSelfPlayerID){
    _ImageCrown->setVisible(true);
    lTextName = Translate::i18n("common_text_496");
    _TextName->setPositionY(_CenterPoint.y - 90);
  }else{
    auto lMapClassType = WorldMapWarDef::Get()->GetKingdomMapClassByKingdomId(_KingdomID);
    if(_LeagueID == lSelfLeagueID){
      if(lMapClassType == EKingdomClassType::LegendLord){
        lTextName = SetLendLordPlayerInfo(lTextName);
      }else if(lMapClassType == EKingdomClassType::Radiance && _SourceKingdomID > 0){
        lTextName = lTextName + "#" + std::to_string(_SourceKingdomID);
      }
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(true);
    }else{
      auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(_LeagueID);
      lNameColor = WorldMapDefine::Get()->GetLeagueManorLineColor(false, lAllianceRelationType);
      if(lMapClassType == EKingdomClassType::LegendLord){
        lTextName = SetLendLordPlayerInfo(lTextName);
        if(_SourceKingdomID != _KingdomID){
          lNameColor = Color3B(190, 190, 190);
        }
      }else if(lMapClassType == EKingdomClassType::Radiance){
        if(_SourceKingdomID > 0){
          lTextName = lTextName + "#" + std::to_string(_SourceKingdomID);
        }
      }else{
        if(_SourceID != _KingdomID){
          lNameColor = Color3B(190, 190, 190);
        }
        //       textName = self:setWarPlayerInfo(nil, nil, textName)
        // lTextName = SetWarPlayerInfo(nullptr);
      }
    }
    _TextName->setPositionY(_CenterPoint.y - 82);
  }
  _TextName->setColor(lNameColor);
  _TextName->setString(lTextName);
  _IsCityBgSkin = pData._CastleSkin;
  if(_IsCityBgSkin){
    UpdateBuildingImg();
  }
  
  if(pData._NameBox != 0){
    auto lNameBgSkin = CastleSkinRead::Get()->GetNameFloor(pData._NameBox);
    if(lNameBgSkin.size() > 0){
      _ImageCrown->setVisible(false);
      _ImageName->setVisible(false);
      _ImageNameBg->setVisible(false);
      _ImageNameBgSkin->setVisible(true);
      _ImageNameBgSkin->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lNameBgSkin.c_str()));
      _TextName->setPositionY(_CenterPoint.y - 82);
      if(lNameBgSkin == "frame_castle_name_summer.png"){
        _TextName->setPositionY(_CenterPoint.y - 75);
        _TextName->setColor(Color3B(150, 255, 255));
      }
      if(lNameBgSkin == "frame_castle_name_2021newyear.png"){
        _TextName->setColor(Color3B(187, 240, 255));
      }
      if(lNameBgSkin == "frame_castle_name_soar.png"){
        _TextName->setPositionY(_CenterPoint.y - 92);
      }
      if(lNameBgSkin == "frame_castle_name_icewolf.png"){
        _TextName->setPositionY(_CenterPoint.y - 92);
      }
      if(lNameBgSkin == "frame_castle_name_2022_Ramadan.png"){
        _TextName->setPositionY(_CenterPoint.y - 92);
      }
      if(lNameBgSkin == "frame_castle_name_2022_Corban.png"){
        _TextName->setPositionY(_CenterPoint.y - 92);
      }
    }
  }else{
    _ImageNameBg->setVisible(GBase::DGetCastleWarLv() >= 5);
    _ImageName->setVisible(true);
    _ImageNameBgSkin->setVisible(false);
    _TextName->setPositionY(_CenterPoint.y - 82);
    if(_PlayerID == lSelfPlayerID){
      _ImageCrown->setVisible(true);
      _TextName->setPositionY(_CenterPoint.y - 90);
    }
  }

  if(pData._MoveCityCDEndTime){
    auto lTime = pData._MoveCityCDEndTime - GServiceFunction::Get()->SystemTime();
    if(lTime > 0){
      _MoveCityTime = lTime;
      UpdateMoveTime();
    }else{
      CleanMoveTime();
    }
  }else{
    CleanMoveTime();
  }
  
  UpdateBuildingState();
  UpdateSafeState();
  UpdateWarLvEffect();
  UpdateAllianceCounterAtkEffect(nullptr);

  if(pData._CastleEffect != EWorldMapCastleEffectID::None && pData._CastleEffectStatusEndTime > -1){
    RemoveCastleEffect();
    if(pData._CastleEffect == EWorldMapCastleEffectID::Crystal_Heart)
      CastleLoveEffect();
    else if(pData._CastleEffect == EWorldMapCastleEffectID::Rainbow_castle)
      CastleRainbowEffect();
    else if(pData._CastleEffect == EWorldMapCastleEffectID::Shining_Castle)
      CastleShiningEffect();
    else if(pData._CastleEffect == EWorldMapCastleEffectID::Shining_Castle_2)
      CastleShining2Effect();
    else if(pData._CastleEffect == EWorldMapCastleEffectID::Shining_Castle_3)
      CastleShining3Effect();
    else if(pData._CastleEffect == EWorldMapCastleEffectID::IceWolf_Castle)
      CastleShining4Effect();
  }else{
    RemoveCastleEffect();
  }

  if(pData._SelfCastleEffect != EWorldMapCastleEffectID::None && pData._SelfCastleEffectStatusEndTime > -1){
    RemoveCastleFireWorkEffect();
    auto lLeftTime = pData._SelfCastleEffectStatusEndTime - GServiceFunction::Get()->SystemTime();
    if(
      pData._SelfCastleEffect == EWorldMapCastleEffectID::Flowery_Firework 
      || pData._SelfCastleEffect == EWorldMapCastleEffectID::Victory_Firework 
      || pData._SelfCastleEffect == EWorldMapCastleEffectID::Festival_Firework
      || pData._SelfCastleEffect == EWorldMapCastleEffectID::NewYear_FireWork_2020 
      || pData._SelfCastleEffect == EWorldMapCastleEffectID::NewYear_FireWork_2022 
      || pData._SelfCastleEffect == EWorldMapCastleEffectID::FirewWork_Ceremony){
      _FireWork = WorldMapFireWorkEffect::Create(pData._SelfCastleEffect);
      addChild(_FireWork);
      _FireWork->Play();
      if(_PlayerID == lSelfPlayerID){
        //      self.fireWorkTimeNode = worldMapEffect.createFireTimeNode()
        //      self.fireWorkTimeNode:setPosition(cc.p(self.centerPoint.x - 0, self.centerPoint.y - 120))
        //      self.fireWorkTimeNode:addTo(self, 5)
        //      self.fireWorkTimeNode.init(leftTime)
      }
    }
    if(pData._SelfCastleEffect == EWorldMapCastleEffectID::Snow_Effect && lLeftTime > 0){
      CastleSnowIceEffect();
    }
  }else{
  //  self:removeCastleFireWorkEffect()
  }
  // if castleAppearance then
  //   self:castleSnowIceEffect(self.playerID == selfPlayerID)
  // end
  // if data.attr then
  //   local isAdd = false
  //   for i, v in ipairs(gRangeAttributeList) do
  //     local attr = data.attr[tostring(v)]
  //     if attr then
  //       if self:isNeedShowAttr(v) then
  //         self:sendTileEffectMessage(worldMapLeagueManorUpdateType.leagueManorInstanceAdd, attr.range)
  //         self:checkAllCastleMeteorteEffect(data.attr, false)
  //         isAdd = true
  //       end
  //       break
  //     end
  //   end
  //   if not isAdd then
  //     self:sendTileEffectMessage(worldMapLeagueManorUpdateType.leagueManorInstanceRemove)
  //   end
  // else
  //   self:removeMeteoriteSkillEffect()
  // end
  // if data.signature then
  //   self.signature = data.signature
  //   self.signatureBox = data.signatureBox
  // end
  // self:refreshSignText()
  // self:refreshSkillEffect(data)
  // self:updateBuildStar(data.starLv)
}

void WorldMapBuilding::ShowInstance(bool pShow, int32 pDelayTime){
  // delayTime = delayTime or 0
  // if delayTime > 0 then
  //   local actionsArray = {}
  //   actionsArray[#actionsArray + 1] = cc.DelayTime:create(delayTime)
  //   actionsArray[#actionsArray + 1] = cc.CallFunc:create(function()
  //     self:setVisible(show)
  //   end)
  //   local action = transition.sequence(actionsArray)
  //   self:runAction(action)
  // else
  //   self:setVisible(show)
  // end
  // if not show then
  //   self:sendTileEffectMessage(worldMapLeagueManorUpdateType.leagueManorInstanceRemove)
  //   self:removeInstanceSelf()
  // end
}

void WorldMapBuilding::UpdateLeagueInfo(){
  // if self.warCamp and self.warCamp > 0 then
  //   self.image_LeagueFlag:setVisible(true)
  //   if self.leagueFlag then
  //     local remainsWarRead = include("remainsWarRead")
  //     self.image_LeagueFlag:setSpriteFrame(remainsWarRead.getCampIcon(self.warCamp))
  //     if 1 == self.warCamp then
  //       self.image_LeagueFlag:setScale(0.5)
  //     else
  //       self.image_LeagueFlag:setScale(1)
  //     end
  //   end
  // elseif self.leagueID and 0 < self.leagueID then
  //   self.image_LeagueFlag:setVisible(true)
  //   if self.leagueFlag then
  //     self.image_LeagueFlag:setSpriteFrame(allianceDesRead.getFlagIcon(self.leagueFlag))
  //     self.image_LeagueFlag:setScale(0.3)
  //   end
  // else
  //   self.image_LeagueFlag:setVisible(false)
  // end
}

void WorldMapBuilding::UpdateBuildingImg(){
  //   self.cityImage:removeAllChildren()
  // self.citySkin1Image:removeAllChildren()
  // self:removeSkinEffect()
  // self:removeWarLvEffect()
  // local textShowLV
  // self.isShowWarLv, textShowLV = SoraDGetBuildWarLv(self.cityLevel)
  // if self.isShowWarLv then
  //   self:warLvEffect(textShowLV)
  // end
  // local isWarLV5 = self.isShowWarLv and textShowLV >= 5
  // self.image_name_bg:setVisible(isWarLV5)
  // if self:getChildByName("citySkin1Image_down") then
  //   self:removeChildByName("citySkin1Image_down", true)
  // end
  // if self:getChildByName("dglNode") then
  //   self:removeChildByName("dglNode", true)
  // end
  // if self:getChildByName("castle47effect") then
  //   self:removeChildByName("castle47effect", true)
  // end
  // if self:getChildByName("cscNode") then
  //   self:removeChildByName("cscNode", true)
  // end
  // if self:getChildByName("xlcbfdNode") then
  //   self:removeChildByName("xlcbfdNode", true)
  // end
  // if self:getChildByName("xczwcbNode") then
  //   self:removeChildByName("xczwcbNode", true)
  // end
  // if self:getChildByName("Node_thunder_1") then
  //   self:removeChildByName("Node_thunder_1", true)
  // end
  // if self:getChildByName("Node_thunder_2") then
  //   self:removeChildByName("Node_thunder_2", true)
  // end
  // if self:getChildByName("Node_starfall_1") then
  //   self:removeChildByName("Node_starfall_1", true)
  // end
  // if self:getChildByName("Node_starfall_2") then
  //   self:removeChildByName("Node_starfall_2", true)
  // end
  // if self:getChildByName("Node_starfall_3") then
  //   self:removeChildByName("Node_starfall_3", true)
  // end
  // if self:getChildByName("Node_coffee") then
  //   self:removeChildByName("Node_coffee", true)
  // end
  // if self:getChildByName("Node_sgsl") then
  //   self:removeChildByName("Node_sgsl", true)
  // end
  // if self.isCityBgSkin ~= 0 and not self.node_snowMan then
  //   local castleSkinRead = include("castleSkinRead")
  //   local skinImageName = castleSkinRead.getMapImage(self.isCityBgSkin)
  //   local castleModel = castleSkinRead.getCastleType(self.isCityBgSkin)
  //   if skinImageName and 0 < string.len(skinImageName) then
  //     self.cityImage:setVisible(false)
  //     self.citySkin1Image:setVisible(true)
  //     self.citySkin1Image:setSpriteFrame(display.newSpriteFrame(skinImageName))
  //     self:setSkinGroupID(castleModel)
  //     self.curCityImage = self.citySkin1Image
  //     local skinOffset = castleSkinConfigRead.getSkinOffset(castleModel)
  //     if skinOffset then
  //       self.curCityImage:setPosition(skinOffset)
  //     end
  //     self.curCityImage:setScale(1)
  //     if castleModel == BUILD_CASTLE_MODEL.KINGCOBRA then
  //       self.curCityImage:setScale(0.9)
  //     end
  //     self.imgScale = IMG_PROTECT_SCALE_SKIN
  //     self.imgOffset = IMG_OFFSET_SKIN
  //     self:addSkinEffect(castleModel)
  //     if self.isShowWarLv then
  //       self:setSkinConfig(castleModel, textShowLV)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.THUNDERCLOUD then
  //       self.citySkin1Image:setVisible(false)
  //       if not self:getChildByName("Node_thunder_1") then
  //         local Node_thunder_1, action = SoraDCreatAnimation("Node_thunder_1", nil, false)
  //         Node_thunder_1:setName("Node_thunder_1")
  //         Node_thunder_1:setPosition(0, 100)
  //         Node_thunder_1:addTo(self, 2)
  //         action:setFrameEventCallFunc(function(frameEventName)
  //           local frameEvent = frameEventName:getEvent()
  //           if frameEvent and frameEvent == "toSecond" then
  //             local Node_thunder_2 = SoraDCreatAnimation("Node_thunder_2")
  //             Node_thunder_2:setName("Node_thunder_2")
  //             Node_thunder_2:setPosition(0, 100)
  //             Node_thunder_2:addTo(self, 2)
  //           end
  //         end)
  //       end
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.SEVENTH then
  //       self.citySkin1Image:setVisible(false)
  //       if not self:getChildByName("Node_starfall_1") then
  //         do
  //           local Node_starfall_1, action = SoraDCreatAnimation("Node_starfall_1", nil, false)
  //           Node_starfall_1:setName("Node_starfall_1")
  //           Node_starfall_1:setPosition(0, 50)
  //           Node_starfall_1:addTo(self, -2)
  //           action:setFrameEventCallFunc(function(frameEventName)
  //             local frameEvent = frameEventName:getEvent()
  //             if frameEvent and frameEvent == "toSecond" then
  //               do
  //                 local Node_starfall_2, action2 = SoraDCreatAnimation("Node_starfall_2", nil, false)
  //                 Node_starfall_2:setName("Node_starfall_2")
  //                 if self.citySkin1Image_groupID then
  //                   SoraDGetChildByName(Node_starfall_2, "chengbaozhuangban_01"):setGroupID(self.citySkin1Image_groupID)
  //                 end
  //                 Node_starfall_2:setPosition(0, 80)
  //                 Node_starfall_2:addTo(self, -1)
  //                 action2:setFrameEventCallFunc(function(frameEventName)
  //                   local frameEvent = frameEventName:getEvent()
  //                   if frameEvent and frameEvent == "tothree" then
  //                     local Node_starfall_3, action3 = SoraDCreatAnimation("Node_starfall_3")
  //                     Node_starfall_3:setName("Node_starfall_3")
  //                     Node_starfall_3:setPosition(0, 80)
  //                     Node_starfall_3:addTo(self, -1)
  //                     if self.citySkin1Image_groupID then
  //                       SoraDGetChildByName(Node_starfall_3, "chengbaozhuangban_02"):setGroupID(self.citySkin1Image_groupID)
  //                     end
  //                     Node_starfall_1:setVisible(false)
  //                     Node_starfall_2:setVisible(false)
  //                   end
  //                 end)
  //               end
  //             end
  //           end)
  //         end
  //       end
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.CORBAN2021 then
  //       local Node_coffee = SoraDCreatAnimation("Node_coffee")
  //       Node_coffee:setName("Node_coffee")
  //       Node_coffee:setPosition(0, 100)
  //       Node_coffee:addTo(self, 2)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.HOURGLASS then
  //       local Node_sgsl = SoraDCreatAnimation("Node_sgsl")
  //       Node_sgsl:setName("Node_sgsl")
  //       Node_sgsl:setPosition(-15, -20)
  //       Node_sgsl:addTo(self, 2)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.DEGULA and not self:getChildByName("dglNode") then
  //       local dglNode = SoraDCreatAnimation("degulacbwai")
  //       dglNode:setName("dglNode")
  //       dglNode:setPosition(40, 40)
  //       dglNode:addTo(self, 2)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.ICECASTLE and not self:getChildByName("castle47effect") then
  //       local castle47effect = SoraDCreatAnimation("castle47effect")
  //       castle47effect:setName("castle47effect")
  //       castle47effect:setPosition(-64, 100)
  //       castle47effect:addTo(self, 2)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.CONSTRUCTED and not self:getChildByName("cscNode") then
  //       local cscNode = SoraDCreatAnimation("constructedCastle")
  //       cscNode:setName("cscNode")
  //       cscNode:setPosition(-2, 124)
  //       cscNode:addTo(self, 2)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.KOH2021RAMADAN and not self:getChildByName("xlcbfdNode") then
  //       local xlcbfdNode = SoraDCreatAnimation("animationXLCBFD")
  //       xlcbfdNode:setName("xlcbfdNode")
  //       xlcbfdNode:setPosition(-70, -20)
  //       xlcbfdNode:addTo(self, 1)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.STARKING and not self:getChildByName("xczwcbNode") then
  //       local xczwcbNode = SoraDCreatAnimation("animationXCZWCB")
  //       xczwcbNode:setName("xczwcbNode")
  //       xczwcbNode:setPosition(-65, -40)
  //       xczwcbNode:addTo(self, 1)
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.HALLOWEEN2018 and not self:getChildByName("citySkin1Image_down") then
  //       local sprite = display.newSprite("#Map_castle_Hallowmas2018_01.png")
  //       self:addChild(sprite, -2)
  //       sprite:setPosition(cc.p(-60, 40))
  //       sprite:setName("citySkin1Image_down")
  //       sprite:runAction(cc.RepeatForever:create(cca.seq({
  //         cca.moveBy(0.16666666666666666, 0, -1),
  //         cca.moveBy(1.3333333333333333, 0, -9),
  //         cca.moveBy(0.16666666666666666, 0, -1),
  //         cca.moveBy(0.16666666666666666, 0, 1),
  //         cca.moveBy(1.3333333333333333, 0, 9),
  //         cca.moveBy(0.16666666666666666, 0, 1)
  //       })))
  //       if self.citySkin1Image_groupID then
  //         sprite:setGroupID(self.citySkin1Image_groupID)
  //       end
  //     end
  //     if castleModel == BUILD_CASTLE_MODEL.GOLDENCITY then
  //       self.curCityImage:stopAllActions()
  //       local curPosX = self.curCityImage:getPositionX()
  //       local curPosY = self.curCityImage:getPositionY()
  //       self.curCityImage:runAction(cc.RepeatForever:create(cca.seq({
  //         cca.moveTo(0.03333333333333333, curPosX, curPosY - 0.08),
  //         cca.moveTo(3.3, curPosX, curPosY - 15),
  //         cca.moveTo(3.3, curPosX, curPosY - 0.08),
  //         cca.moveTo(0.03333333333333333, curPosX, curPosY)
  //       })))
  //     else
  //       self.curCityImage:stopAllActions()
  //     end
  //     return
  //   end
  // elseif self.isShowWarLv and (textShowLV == 5 or textShowLV == 10) then
  //   self.imgScale = IMG_PROTECT_SCALE_WAR_10
  //   self.imgOffset = IMG_OFFSET_WAR_10
  // else
  //   self.imgScale = self.isShowWarLv and IMG_PROTECT_SCALE_WAR or IMG_PROTECT_SCALE_DEF
  //   self.imgOffset = self.isShowWarLv and IMG_OFFSET_WAR or IMG_OFFSET_DEF
  // end
  // if not self.node_snowMan then
  //   self.cityImage:setVisible(true)
  //   self.citySkin1Image:setVisible(false)
  //   worldMapDefine.createCityImageWithLevel(self.cityLevel, self.factionType, self.cityImage)
  // end
}

void WorldMapBuilding::UpdateBuildingNecklace(){
  // if self.neckLaceID and worldMapDefine.isInRadiance() then
  //   local equipDesRead = include("equipDesRead")
  //   self.necklaceNode:setVisible(true)
  //   local necklaceIcon = self.necklaceNode:getChildByName("necklaceIcon")
  //   necklaceIcon:setSpriteFrame(equipDesRead.getIcon(self.neckLaceID))
  //   local necklaceName = self.necklaceNode:getChildByName("necklaceName")
  //   necklaceName:setString(equipDesRead.getName(self.neckLaceID))
  // else
  //   self.necklaceNode:setVisible(false)
  // end
}

GString WorldMapBuilding::SetLendLordPlayerInfo(const GString &pName){
  // local textName = name or self.playerName
  // if self.sourceKingdomID and self.sourceKingdomID > 0 then
  //   textName = textName .. "#" .. self.sourceKingdomID
  // end
  // return textName
}

void WorldMapBuilding::UpdateWarLvEffect(){
  // if self.warLVnode then
  //   self.warLVnode:setVisible(not self.hideBattleLev)
  // end
}


void WorldMapBuilding::UpdateAllianceCounter(EventCustom *pEvent){
  // if data and data.type and data.type == GREEN_POINT_NOTICE_TYPE.COUNTER_SYS then
  //   self:updateAllianceCounterAtkEffect()
  // end
}

void WorldMapBuilding::UpdateOfficeIcon(EventCustom *pEvent){
  // if self.officalImage then
  //   local isShow = SoraDConfigGet("Game:worldMapOfficeIcon:OfficeIcon~bool", {byUID = true})
  //   if isShow == nil then
  //     isShow = true
  //   end
  //   if self.node_snowMan then
  //     isShow = false
  //   end
  //   self.isShowOffice = isShow
  //   self:updateOfficial()
  // end
}

void WorldMapBuilding::UpdatePrisionIcon(EventCustom *pEvent){
  // if self.prisoneInIcon then
  //   local isShow = SoraDConfigGet("Game:castleChangeSetting:PrisonHeroIcon~bool", {byUID = true})
  //   if isShow == nil then
  //     isShow = true
  //   end
  //   if self.node_snowMan then
  //     isShow = false
  //   end
  //   self.isShowPrision = isShow
  //   self:updatePrisoneIn()
  // end
}

GString WorldMapBuilding::SetWarPlayerInfo(EventCustom *pEvent){
  // local textName = name or self.playerName
  // local selfSourceID = lordInfoCtrl:getMapSourceKid()
  // local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  // local isMatchKingdom = conquestWarCtrl:isMatchKingdom(selfSourceID, self.kingdomID)
  // if (selfSourceID == self.kingdomID or isMatchKingdom) and selfSourceID ~= self.sourceID then
  //   textName = textName .. "#" .. self.sourceID
  //   self.text_Name:setColor(cc.c3b(200, 0, 0))
  //   local boolWarSmoke = SoraDConfigGet("Game:GameOptionsView:warSmoke~bool")
  //   if boolWarSmoke then
  //     self:addEnemyCastleEffect()
  //   else
  //     self:removeEnemyCastleEffect()
  //   end
  //   self.image_name:setSpriteFrame("frame_castle_name_enemy.png")
  // end
  // return textName
}

void WorldMapBuilding::AddSkinEffect(EBuildingCastleModel pCastleModel){
  // local et_node = self:getChildByName("skinBgEffectNode")
  // if not et_node then
  //   et_node = worldMapDefine.getCastleSkinEffect(castleModel)
  //   et_node:addTo(self, 1)
  // end
}

void WorldMapBuilding::RemoveSkinEffect(){
  // if self:getChildByName("skinBgEffectNode") then
  //   self:removeChildByName("skinBgEffectNode", true)
  // end
}

void WorldMapBuilding::SetSkinConfig(EBuildingCastleModel pCastleModel, int32 pWarLv){
  // local config = castleSkinConfigRead.getSkinWarLvConfig(castleModel, warLv)
  // if config then
  //   self.warLVnode:setScale(config.scale)
  //   self.warLVnode:setPosition(config.offset)
  // else
  //   self.warLVnode:setScale(1)
  //   local data = worldMapDefine.getWarLevelData(warLv)
  //   local offset = data.offset or cc.p(0, 0)
  //   self.warLVnode:setPosition(offset)
  //   if self.curCityImage then
  //     self.curCityImage:setPosition(cc.p(0, 0))
  //   end
  // end
}

void WorldMapBuilding::UpdateBuildingState(){
  // self:updateFireEffect(self.buildingState)
}

void WorldMapBuilding::SetImgProtect(){
  // if self:isSysWarProtect() then
  //   self.image_Protect:setIsGray(true)
  // else
  //   self.image_Protect:setIsGray(false)
  // end
  // self.image_Protect:setVisible(true)
  // self.image_Protect:setScale(self.imgScale)
  // self.image_Protect:setPosition(cc.p(self.centerPoint.x + self.imgOffset.x, self.centerPoint.y + self.imgOffset.y))
}

void WorldMapBuilding::UpdateSafeState(){
  // if self:isInAllianceWar() then
  //   self:setImgProtect()
  //   self:addPyramidProtectEffect()
  // else
  //   self:removePyramidProtectEffect()
  //   if self.isSafe then
  //     self:setImgProtect()
  //   else
  //     self.image_Protect:setVisible(false)
  //   end
  // end
}

void WorldMapBuilding::AddFireEffect(GTime pFireTime ){
  // worldMapInstance.addFireEffect(self, fightTime, data)
  // if data and data.fightingToPointX and data.fightingToPointY then
  //   self.facePoint = cc.p(data.fightingToPointX, data.fightingToPointY)
  // end
  // self:doFightingAnimation()
}

void WorldMapBuilding::DoFightingAnimation(){
  // local x, y = self:getPosition()
  // local beginPoint = cc.p(x, y + 30)
  // local endPoint = self.facePoint
  // local worldMapView = SoraDCurrentSceneShowView("worldMapView")
  // if worldMapView then
  //   endPoint = worldMapView:getPointWithTile(self.facePoint)
  // end
  // local angle = SoraDGetAngleByPos(beginPoint, endPoint)
  // local radius = 80
  // math.randomseed(tostring(os.time()):reverse():sub(1, 6))
  // for _ = 1, self.bulletNum do
  //   local bulletSprite = display.newSprite("#icon_battle_jian_4.png")
  //   local randomPointX = math.random(-20, 20)
  //   local randomPointY = math.random(-20, 20)
  //   local randomAngle = math.random(-50, 50)
  //   local randomDistence = radius + math.random(-30, 30)
  //   local newAngle = angle + randomAngle
  //   local radian = math.angle2radian(newAngle)
  //   local pointX = randomDistence * math.cos(radian)
  //   local pointY = randomDistence * math.sin(radian)
  //   local point1 = cc.p(randomPointX, randomPointY)
  //   local point2 = cc.p(pointX, pointY)
  //   bulletSprite:setPosition(point1)
  //   bulletSprite:setScale(0.5)
  //   self.bulletNode:addChild(bulletSprite, 1)
  //   local delayTime = math.random(0, 5) / 10
  //   worldMapFunction.createThrowAction(bulletSprite, point1, point2, delayTime)
  // end
  // local actionsArray = {}
  // actionsArray[#actionsArray + 1] = cc.DelayTime:create(3)
  // actionsArray[#actionsArray + 1] = cc.CallFunc:create(function()
  //   self:doFightingAnimation()
  // end)
  // local actions = transition.sequence(actionsArray)
  // self.fireNode:runAction(actions)
}

void WorldMapBuilding::CrownUpEffect(Node *pNode){
  // local param = {
  //   [1] = {
  //     plist = "et_castle_officer_01.plist",
  //     scale = 1.1
  //   },
  //   [2] = {
  //     plist = "et_castle_officer_02.plist",
  //     scale = 1.3
  //   }
  // }
  // local parNode = SoraDCreateEffectNode(param)
  // parNode:setPosition(cc.p(node:getContentSize().width / 2, node:getContentSize().height / 2))
  // parNode:addTo(node)
}

void WorldMapBuilding::CrownDownEffect(Node *pNode){
  // local param = {
  //   [1] = {
  //     plist = "et_cwgz_01.plist",
  //     scale = 1.45
  //   }
  // }
  // local parNode = SoraDCreateEffectNode(param)
  // parNode:setPosition(cc.p(node:getContentSize().width / 2, node:getContentSize().height / 2))
  // parNode:addTo(node)
}

Node *WorldMapBuilding::CreateLvEffectNode(int32 pWarLv){
  // local data = worldMapDefine.getWarLevelData(warLv)
  // if not data then
  //   return
  // end
  // local node_warLvNode = display.newNode()
  // local node_bottom = display.newNode()
  // node_bottom:addTo(node_warLvNode, 1)
  // local bottom = data.bottom
  // local bottomImg = bottom.img
  // for _, v in pairs(bottomImg.bg) do
  //   local bg = display.newSprite("#" .. v.png)
  //   bg:setPosition(v.pos)
  //   bg:setGroupID(GROU_ID.group_warLv_base)
  //   bg:addTo(node_bottom, 1)
  // end
  // for _, v in pairs(bottomImg.dh) do
  //   local dh = display.newSprite("#" .. v.png)
  //   dh:setPosition(v.pos)
  //   dh:setGroupID(GROU_ID.group_warLv_base)
  //   SoraDFadeINOUT(dh, {beginOpacity = 0.3, endOpacity = 0.7})
  //   dh:addTo(node_bottom, 2)
  // end
  // if bottom.et then
  //   local et_bottom = SoraDCreateEffectNode(bottom.et)
  //   et_bottom:setGroupID(GROU_ID.group_warLv_base_particle)
  //   et_bottom:setGroupAuto(true)
  //   et_bottom:addTo(node_bottom, 3)
  // end
  // if bottom.scale then
  //   node_bottom:setScale(bottom.scale)
  // end
  // if bottom.offset then
  //   node_bottom:setPosition(bottom.offset)
  // end
  // local top = data.top
  // local node_top = display.newNode()
  // node_top:addTo(node_warLvNode, 2)
  // local topImg = top.img
  // for _, v in pairs(topImg.bg) do
  //   local bg = display.newSprite("#" .. v.png)
  //   bg:setGroupID(GROU_ID.group_warLv_top)
  //   bg:setPosition(v.pos)
  //   bg:addTo(node_top, 1)
  // end
  // for _, v in pairs(topImg.dh) do
  //   local dh = display.newSprite("#" .. v.png)
  //   dh:setPosition(v.pos)
  //   dh:setGroupID(GROU_ID.group_warLv_top)
  //   SoraDFadeINOUT(dh, {beginOpacity = 0.3, endOpacity = 0.7})
  //   dh:addTo(node_top, 2)
  // end
  // if top.et then
  //   local et_top = SoraDCreateEffectNode(top.et)
  //   et_top:setGroupID(GROU_ID.group_warLv_top_particle)
  //   et_top:setGroupAuto(true)
  //   et_top:addTo(node_top, 3)
  // end
  // if top.scale then
  //   node_top:setScale(top.scale)
  // end
  // if top.offset then
  //   node_top:setPosition(top.offset)
  // end
  // local top_sword = data.top_sword
  // local node_top_sword = display.newNode()
  // node_top_sword:addTo(node_top, 2)
  // node_top_sword:setName("node_top_sword")
  // if top_sword then
  //   local topImg = top_sword.img
  //   for _, v in pairs(topImg.bg) do
  //     local bg = display.newSprite("#" .. v.png)
  //     bg:setGroupID(GROU_ID.group_warLv_top)
  //     bg:setPosition(v.pos)
  //     bg:addTo(node_top_sword, 1)
  //   end
  //   for _, v in pairs(topImg.dh) do
  //     local dh = display.newSprite("#" .. v.png)
  //     dh:setPosition(v.pos)
  //     dh:setGroupID(GROU_ID.group_warLv_top)
  //     SoraDFadeINOUT(dh, {beginOpacity = 0.3, endOpacity = 0.7})
  //     dh:addTo(node_top_sword, 2)
  //   end
  //   if top_sword.et then
  //     local et_top = SoraDCreateEffectNode(top_sword.et)
  //     et_top:setGroupID(GROU_ID.group_warLv_top_particle)
  //     et_top:setGroupAuto(true)
  //     et_top:addTo(node_top_sword, 3)
  //   end
  // end
  // local seq = cca.seq({
  //   cca.moveBy(1.5, 0, 5),
  //   cca.moveBy(1.5, 0, -5)
  // })
  // node_top:runAction(cc.RepeatForever:create(seq))
  // if data.moon then
  //   local node_moon = display.newNode()
  //   node_moon:addTo(node_warLvNode, 3)
  //   node_moon:setName("node_moon")
  //   for _, v in pairs(data.moon.img.bg) do
  //     local bg = display.newSprite("#" .. v.png)
  //     bg:setGroupID(GROU_ID.group_warLv_top)
  //     bg:setPosition(v.pos)
  //     bg:addTo(node_moon, 1)
  //   end
  //   for _, v in pairs(data.moon.img.dh) do
  //     local dh = display.newSprite("#" .. v.png)
  //     dh:setPosition(v.pos)
  //     dh:setGroupID(GROU_ID.group_warLv_top)
  //     SoraDFadeINOUT(dh, {beginOpacity = 0.3, endOpacity = 0.7})
  //     dh:addTo(node_moon, 2)
  //   end
  //   if data.moon.et then
  //     local et_top = SoraDCreateEffectNode(data.moon.et)
  //     et_top:setGroupID(GROU_ID.group_warLv_top_particle)
  //     et_top:setGroupAuto(true)
  //     et_top:addTo(node_moon, 3)
  //   end
  //   if warLv == CASTLE_NEX_MAX_WARLV then
  //     local act = cca.seq({
  //       cca.moveBy(0.5833333333333334, 0, -8),
  //       cca.moveBy(0.16666666666666666, 0, 4),
  //       cca.moveBy(0.43333333333333335, 0, 8),
  //       cca.moveBy(0.15, 0, -2),
  //       cca.moveBy(0.5, 0, -8),
  //       cca.moveBy(0.8333333333333334, 0, 6)
  //     })
  //     node_moon:runAction(cc.RepeatForever:create(act))
  //   end
  //   if data.moon.scale then
  //     node_moon:setScale(data.moon.scale)
  //   end
  //   if data.moon.offset then
  //     node_moon:setPosition(data.moon.offset)
  //   end
  // end
  // node_warLvNode:setTag(WAR_LV_BEGIN_TYPE + warLv)
  // return node_warLvNode
}

void WorldMapBuilding::WarLvEffect(int32 pWarLv){
  // if warLv == 0 then
  //   self:removeWarLvEffect()
  //   return
  // end
  // local data = worldMapDefine.getWarLevelData(warLv)
  // if not data then
  //   return
  // end
  // if data.offset then
  //   self.warLVnode:setPosition(data.offset)
  // end
  // local node_warLvNode = instanceCacheMgr.getInstance(WAR_LV_BEGIN_TYPE + warLv)
  // if node_warLvNode then
  //   self.node_warLvNode = node_warLvNode
  //   node_warLvNode:addTo(self.warLVnode)
  //   node_warLvNode:release()
  // else
  //   node_warLvNode = createLvEffectNode(warLv)
  //   if node_warLvNode then
  //     self.node_warLvNode = node_warLvNode
  //     node_warLvNode:addTo(self.warLVnode)
  //   else
  //     print("createLvEffectNode error warLv", warLv)
  //   end
  // end
}

void WorldMapBuilding::RemoveWarLvEffect(){
  // if self.node_warLvNode then
  //   instanceCacheMgr.addNormalNode(self.node_warLvNode)
  //   self.node_warLvNode:removeFromParent(false)
  //   self.node_warLvNode = nil
  // end
  // self.warLVnode:setPosition(POINT_ZERO)
}

void WorldMapBuilding::AddEnemyCastleEffect(){
  // if self:getChildByName("et_node_enemy") then
  //   return  
  // end
  // local param = {
  //   [1] = {
  //     plist = "et_heiwu_display_01.plist",
  //     pos = {x = -8, y = -10}
  //   }
  // }
  // local et_node = SoraDCreateEffectNode(param)
  // et_node:setName("et_node_enemy")
  // et_node:addTo(self)
}

void WorldMapBuilding::RemoveEnemyCastleEffect(){
  // if self:getChildByName("et_node_enemy") then
  //   self:removeChildByName("et_node_enemy", true)
  // end
}

bool WorldMapBuilding::IsNeedShowAttr(EAttributeEnum pAttrType){
  // local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  // local leagueID = self.leagueID or 0
  // for i, v in ipairs(gMeteoriteSkillList) do
  //   print("attrEnum,v", attrEnum, v)
  //   if attrEnum == v then
  //     if selfLeagueID == leagueID then
  //       return true
  //     else
  //       return false
  //     end
  //   end
  // end
  // return true
}

void WorldMapBuilding::CheckAllCastleMeteorteEffect(){
  // local worldMapView = SoraDCurrentSceneShowView("worldMapView")
  // if not worldMapView then
  //   return
  // end
  // local ret = worldMapView:getShowTilesArray()
  // if ret == nil then
  //   return
  // end
  // local selfPoint = self:getTilePoint()
  // for i, v in ipairs(gMeteoriteSkillList) do
  //   local attrValue = attr[tostring(v)]
  //   if attr[tostring(v)] then
  //     local rect = cc.rect(selfPoint.x - attrValue.range, selfPoint.y - attrValue.range, attrValue.range * 2, attrValue.range * 2)
  //     for _, tileInstance in pairs(ret) do
  //       if tileInstance and tileInstance.instanceType == gMapObjTypeDef.mapObjTypePlayer and self.leagueID == tileInstance.leagueID then
  //         local tilePoint = tileInstance:getTilePoint()
  //         if cc.rectContainsPoint(rect, tilePoint) then
  //           tileInstance:addMeteoriteSkillEffect(v)
  //         end
  //       end
  //     end
  //   end
  // end
}

void WorldMapBuilding::AddMeteoriteSkillEffect(EAttributeEnum pAttrType){
  // if atttE == gAttributeEnum.METEOR_MARCH_SPEED_BOOST then
  //   self:removeMeteoriteSkillEffect()
  //   local effectSp = display.newSprite("#dh_chengbaosxzs_01.png")
  //   effectSp:setPosition(cc.p(-15, 50))
  //   effectSp:setScale(2)
  //   effectSp:addTo(self, 1)
  //   local frames = display.newFrames("dh_chengbaosxzs_%.2d.png", 1, 30)
  //   local animation = display.newAnimation(frames, 1 / #frames)
  //   effectSp:playAnimationForever(animation)
  //   effectSp:runAction(cca.seq({
  //     cca.delay(5),
  //     cca.callFunc(function()
  //       self:removeMeteoriteSkillEffect()
  //     end)
  //   }))
  //   self.meteoriteEffect = effectSp
  // else
  //   local effectSp = display.newSprite("#dh_chengbaosxjn_01.png")
  //   effectSp:setPosition(cc.p(-15, 150))
  //   effectSp:setScale(2.5)
  //   effectSp:addTo(self, 1)
  //   local frames = display.newFrames("dh_chengbaosxjn_%.2d.png", 1, 29)
  //   local animation = display.newAnimation(frames, 2 / #frames)
  //   effectSp:playAnimationOnce(animation, {removeSelf = true})
  // end
}

void WorldMapBuilding::RemoveMeteoriteSkillEffect(){
  // if self.meteoriteEffect then
  //   self.meteoriteEffect:removeFromParent()
  //   self.meteoriteEffect = nil
  // end
}

void WorldMapBuilding::CastleLoveEffect(){
  // if self.et_node_love then
  //   return
  // end
  // local param = {
  //   [1] = {
  //     plist = "et_castlelove_02.plist",
  //     pos = {x = 7.32, y = 27.46}
  //   },
  //   [2] = {
  //     plist = "et_castlelove_03.plist",
  //     pos = {x = 18.96, y = -59.42}
  //   },
  //   [3] = {
  //     plist = "et_castlelove_04.plist",
  //     pos = {x = 15.15, y = 10.27},
  //     scale = 2
  //   },
  //   [4] = {
  //     plist = "et_castlelove_01.plist",
  //     pos = {x = 9.99, y = 53.25},
  //     scale = {x = 2.5, y = 4.6}
  //   }
  // }
  // self.et_node_love = SoraDCreateEffectNode(param)
  // self.et_node_love:addTo(self)
}

void WorldMapBuilding::RemoveCastleEffect(){
  // if self.et_node_love then
  //   self.et_node_love:removeFromParent()
  //   self.et_node_love = nil
  // end
  // if self.node_snowMan then
  //   self.node_snowMan:removeFromParent()
  //   self.node_snowMan = nil
  //   self:updateBuildingImg()
  //   self:updateOfficeIcon()
  //   self:updatePrisoneIn()
  // end
  // if self.et_node_rainbow then
  //   self.et_node_rainbow:stopAllActions()
  //   self.et_node_rainbow:removeFromParent()
  //   self.et_node_rainbow = nil
  // end
  // if self.et_node_shining then
  //   self.et_node_shining:removeFromParent()
  //   self.et_node_shining = nil
  // end
  // if self:getChildByName("et_node_rainbow_1") then
  //   self:removeChildByName("et_node_rainbow_1", true)
  // end
  // if self:getChildByName("et_node_rainbow_2") then
  //   self:removeChildByName("et_node_rainbow_2", true)
  // end
}

void WorldMapBuilding::CastleSnowEffect(){
  // if self.node_snowEffect then
  //   return
  // end
  // self.node_snowEffect = display.newNode()
  // self.node_snowEffect:setPosition(-30, 70)
  // self.node_snowEffect:addTo(self, 1)
  // local snowEffect = SoraDCreatAnimation("animationSnowEffect")
  // snowEffect:addTo(self.node_snowEffect)
}

void WorldMapBuilding::CastleSnowIceEffect(bool pIsSelf){
  // if self.node_snowMan then
  //   return
  // end
  // self.node_snowMan = display.newNode()
  // self.node_snowMan:setPosition(0, 0)
  // self.node_snowMan:addTo(self, 1)
  // if isSelf and self.data.castleAppearanceEndTime then
  //   local leftTime = math.max(0, self.data.castleAppearanceEndTime - serviceFunctions.systemTime())
  //   local timeNode = worldMapEffect.createFireTimeNode()
  //   timeNode:setPosition(cc.p(0, -120))
  //   timeNode:addTo(self.node_snowMan, 5)
  //   timeNode.init(leftTime)
  // end
  // self.cityImage:setVisible(false)
  // self.citySkin1Image:setVisible(false)
  // self:updateOfficeIcon()
  // self:updatePrisoneIn()
  // local xueren = display.newSprite("#xuerenzhuangban.png")
  // xueren:setPosition(cc.p(-45, 60))
  // xueren:addTo(self.node_snowMan, 0)
  // local yun = display.newSprite("#yunduozhuangban_001.png")
  // yun:setPosition(cc.p(-15, 100))
  // yun:setBlendFunc(gl.ONE, gl.ONE_MINUS_SRC_COLOR)
  // yun:addTo(self.node_snowMan, 1)
  // local frames = display.newFrames("yunduozhuangban_%.3d.png", 1, 20)
  // local animation = display.newAnimation(frames, 2 / #frames)
  // yun:playAnimationForever(animation)
  // local param = {
  //   [1] = {
  //     plist = "et_xuerenddj_01.plist",
  //     pos = cc.p(119.09, 53.82),
  //     scale = 1.35
  //   },
  //   [2] = {
  //     plist = "et_xuerenddj_01.plist",
  //     pos = cc.p(-37.39, 57.54),
  //     scale = 1.65
  //   },
  //   [3] = {
  //     plist = "et_xuerenddj_02.plist",
  //     pos = cc.p(-70.93, -33.32)
  //   },
  //   [4] = {
  //     plist = "et_xuerenddj_02.plist",
  //     pos = cc.p(-14.11, -89.37)
  //   },
  //   [5] = {
  //     plist = "et_xuerenddj_02.plist",
  //     pos = cc.p(152.46, -19.55)
  //   },
  //   [6] = {
  //     plist = "et_xuerenddj_03.plist",
  //     pos = cc.p(41.9, -46.1),
  //     scale = 1.4237
  //   },
  //   [7] = {
  //     plist = "et_xuerenddj_04.plist",
  //     pos = cc.p(32.99, -36.95),
  //     scale = 1.1245
  //   },
  //   [8] = {
  //     plist = "et_xuerenddj_05.plist",
  //     pos = cc.p(117.46, 54.45),
  //     rotate = 179.07
  //   },
  //   [9] = {
  //     plist = "et_xuerenddj_05.plist",
  //     pos = cc.p(-31.71, 53.92),
  //     scale = 0.8419,
  //     rotate = 179.07
  //   }
  // }
  // local et_node = SoraDCreateEffectNode(param)
  // et_node:setPosition(-45, 45)
  // et_node:addTo(self.node_snowMan, 0)
}

void WorldMapBuilding::CastleShiningEffect(){
  // if self.et_node_shining then
  //   return
  // end
  // self.et_node_shining = display.newNode()
  // self.et_node_shining:setPosition(0, 0)
  // self.et_node_shining:addTo(self)
  // for k, v in pairs(worldMapDefine.castleTwinkleCfg) do
  //   local effectNode = SoraDCreateShaderEffect(v, self.et_node_shining)
  //   if v.rotation and device.platform == "mac" then
  //     effectNode:setRotation3D({
  //       x = 180,
  //       y = -45,
  //       z = 275
  //     })
  //   end
  // end
  // if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //   self.et_node_shining:setScale(1.2)
  // end
}

void WorldMapBuilding::CastleShining2Effect(){
  // if self.et_node_shining then
  //   return
  // end
  // local effect = SoraDCreatAnimation("Node_bxcqcb_effect")
  // effect:addTo(self, 999)
  // effect:setPosition(cc.p(-60, 120))
  // local hideName = SoraDFIsRA() and "Sprite_text_en" or "Sprite_text_ar"
  // SoraDGetChildByName(effect, hideName):setVisible(false)
  // self.et_node_shining = effect
}

void WorldMapBuilding::CastleShining3Effect(){
  // if self.et_node_shining then
  //   return
  // end
  // local effect = SoraDCreatAnimation("animationXLCBCWTX")
  // effect:setName("xlcbtxNode")
  // effect:setPosition(-45, 140)
  // effect:addTo(self, 2)
  // self.et_node_shining = effect
}

void WorldMapBuilding::CastleShining4Effect(){
  // if self.et_node_shining then
  //   return
  // end
  // local effect = SoraDCreatAnimation("animationBYXLCBYHTX")
  // effect:setPosition(-45, 140)
  // effect:addTo(self, 2)
  // self.et_node_shining = effect
}

void WorldMapBuilding::CastleRainbowEffect(){
  // if self.et_node_rainbow then
  //   return
  // end
  // local bPercent = 0
  // local ePercent = 78
  // local actionTime = 2
  // local perFrame = ePercent / (actionTime * 60)
  // local isEffectShow = false
  // self.et_node_rainbow = display.newNode()
  // self.et_node_rainbow:setPosition(cc.p(self.centerPoint.x - 20, self.centerPoint.y + 50))
  // self.et_node_rainbow:addTo(self, 9)
  // local progress_rainbow = display.newProgressTimer("#icon_rainbow.png", display.PROGRESS_TIMER_RADIAL)
  // progress_rainbow:setRotation(-140)
  // progress_rainbow:addTo(self.et_node_rainbow, 9)
  // progress_rainbow:setPercentage(bPercent)
  // local function freeEffect()
  //   local beginPos = cc.p(self.centerPoint.x - 161, self.centerPoint.y - 128.5)
  //   local control_1 = cc.p(self.centerPoint.x - 55.44, self.centerPoint.y + 307.77)
  //   local control_2 = cc.p(self.centerPoint.x + 281, self.centerPoint.y + 393.5)
  //   local endPos = cc.p(self.centerPoint.x + 315.6, self.centerPoint.y + 147.8)
  //   local param = {
  //     [1] = {
  //       plist = "et_caihong_01.plist",
  //       pos = beginPos,
  //       scale = 2.237,
  //       rotate = -18.87,
  //       posType = cc.POSITION_TYPE_FREE
  //     }
  //   }
  //   local et_rainbow = SoraDCreateEffectNode(param)
  //   et_rainbow:setName("et_node_rainbow_2")
  //   et_rainbow:addTo(self, 10)
  //   local seq = cca.seq({
  //     cc.EaseSineIn:create(cc.BezierTo:create(1.6, {
  //       control_1,
  //       control_2,
  //       endPos
  //     })),
  //     cca.callFunc(function()
  //       SoraDStopEffectNode(et_rainbow)
  //     end)
  //   })
  //   et_rainbow:runAction(seq)
  // end
  // local seqRainbow = cca.seq({
  //   cca.spawn({
  //     cca.callFunc(function()
  //       bPercent = 0
  //       progress_rainbow:stopAllActions()
  //       progress_rainbow:setPercentage(bPercent)
  //       local seq = cca.seq({
  //         cca.callFunc(function()
  //           bPercent = bPercent + perFrame
  //           if bPercent <= ePercent then
  //             progress_rainbow:setPercentage(bPercent)
  //           else
  //             progress_rainbow:stopAllActions()
  //           end
  //         end),
  //         cca.delay(0.016666666666666666)
  //       })
  //       progress_rainbow:runAction(cc.RepeatForever:create(seq))
  //     end),
  //     cca.callFunc(freeEffect)
  //   }),
  //   cca.delay(2),
  //   cca.callFunc(function()
  //     if isEffectShow then
  //       return
  //     end
  //     local param = {
  //       [1] = {
  //         plist = "et_caihong_02.plist",
  //         rotate = -22.21,
  //         pos = cc.p(self.centerPoint.x + 19.28, self.centerPoint.y + 24.46)
  //       },
  //       [2] = {
  //         plist = "et_caihong_03.plist",
  //         scale = {x = -0.855, y = 0.876},
  //         rotate = 42.65,
  //         pos = cc.p(self.centerPoint.x + 29, self.centerPoint.y + 76.06)
  //       },
  //       [3] = {
  //         plist = "et_caihong_03.plist",
  //         scale = 2.237,
  //         rotate = -18.87,
  //         pos = cc.p(self.centerPoint.x + 61.85, self.centerPoint.y + 147.93)
  //       }
  //     }
  //     local et_node = SoraDCreateEffectNode(param)
  //     et_node:setName("et_node_rainbow_1")
  //     et_node:addTo(self, 10)
  //     isEffectShow = true
  //   end)
  // })
  // self.et_node_rainbow:runAction(seqRainbow)
}

void WorldMapBuilding::RemoveCastleFireWorkEffect(){
  // if self.fireWork then
  //   self.fireWork:removeFromParent()
  //   self.fireWork = nil
  //   if self.fireWorkTimeNode then
  //     self.fireWorkTimeNode:stopAllActions()
  //     self.fireWorkTimeNode:removeFromParent()
  //     self.fireWorkTimeNode = nil
  //   end
  // end
  // if self.node_snowEffect then
  //   self.node_snowEffect:removeFromParent()
  //   self.node_snowEffect = nil
  // end
}

void WorldMapBuilding::AddPyramidProtectEffect(){
  // local param = {
  //   [1] = {
  //     plist = "et_cjztzc_protect_01.plist",
  //     pos = {x = 0, y = 140},
  //     scale = 2
  //   },
  //   [2] = {
  //     plist = "et_cjztzc_protect_02.plist",
  //     pos = {x = 0, y = 140},
  //     scale = 2
  //   },
  //   [3] = {
  //     plist = "et_cjztzc_protect_03.plist",
  //     pos = {x = 0, y = 140},
  //     scale = 2
  //   },
  //   [4] = {
  //     plist = "et_cjztzc_protect_04.plist",
  //     pos = {x = 0, y = 140},
  //     scale = 2
  //   }
  // }
  // if self.pyramidProtectNode then
  //   SoraDResetEffectNode(self.pyramidProtectNode)
  // else
  //   self.pyramidProtectNode = SoraDCreateEffectNode(param)
  //   self:addChild(self.pyramidProtectNode, 5)
  //   self.pyramidProtectNode:setScale(self.imgScale)
  //   self.pyramidProtectNode:setPosition(self.imgOffset)
  // end
}

void WorldMapBuilding::RemovePyramidProtectEffect(){
  // if self.pyramidProtectNode then
  //   self.pyramidProtectNode:removeFromParent()
  //   self.pyramidProtectNode = nil
  // end
}

GString WorldMapBuilding::GetFavoriteName(){
  // local favoriteName = self.playerName
  // if self.leagueName then
  //   favoriteName = i18n("common_text_186", {
  //     abbr = self.leagueName,
  //     name = self.playerName
  //   })
  // end
  // return favoriteName
}

void WorldMapBuilding::PlayClickSound(){
  // SoraDPlaySound("innerbuildsound", 101)
}

GVector<EWorldMapTipButtonType> WorldMapBuilding::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
  // local buttonTypeArray = {}
  // local selfPlayerID = gametop.playertop_:getPlayerID() or 0
  // local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  // if isSelfKindom then
  //   local playerID = self.playerID or 0
  //   local leagueID = self.leagueID or 0
  //   if selfPlayerID == playerID then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_jinruChengshi
  //     })
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_chengshiZengyi
  //     })
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_decorate
  //     })
  //     if SoraDGetCtrl("exaltedPrivilegeCtrl"):checkPrivilege(gExaltedPrivilegeType.SIGNATURE) then
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_sign
  //       })
  //     end
  //   else
  //     if not isInWar and worldMapDefine.kingdomStatus == gKingStatus.king then
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_renMing
  //       })
  //     end
  //     local isInPyramid = self:isInAllianceWar()
  //     local msgTipsKey
  //     local atlantis = {}
  //     if worldMapDefine.isInAtlantis() then
  //       local atlantisWarUtil = include("atlantisWarUtil")
  //       local ret = atlantisWarUtil.isTouchMarshal(self:getTilePoint())
  //       if ret then
  //         atlantis.isCanZhanling = false
  //         atlantis.isCanZhencha = false
  //         atlantis.zhenchaTips = i18n("atlantiswar_text_0096")
  //         isInPyramid = not atlantis.isCanZhanling
  //         msgTipsKey = atlantis.zhenchaTips
  //       else
  //         atlantis = atlantisWarUtil.checkAreaState(self:getTilePoint())
  //         isInPyramid = not atlantis.isCanZhanling
  //         msgTipsKey = atlantis.clickTips
  //       end
  //     elseif worldMapDefine.isInNebula() then
  //       local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
  //       if nebulaActivityCtrl:getCurRound() <= 3 then
  //         isInPyramid = true
  //         msgTipsKey = i18n("nebula_war_text_0194")
  //       end
  //     end
  //     if selfLeagueID > 0 and selfLeagueID == leagueID then
  //       local worldMapWarDef = include("worldMapWarDef")
  //       if worldMapWarDef.isInWarForbidResourceHelp() then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_ziyuanYuanzhu,
  //           isButtonEnabled = not isInPyramid,
  //           msgTipsKey = msgTipsKey
  //         })
  //       end
  //       if kingdomMapCtrl:hasMyQueue(_G.gMapMoveLineServerType.moveLineTypeMassSlave, nil, nil, self.playerID) then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_jijieBuduiXinxi
  //         })
  //       end
  //       if kingdomMapCtrl:hasArmyHelpQueue2Player(self.playerID, gMapMoveLineStatusType.moveLineStatusTypeWorking) then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_chakanYuanjun
  //         })
  //       else
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_shibingYuabzhu,
  //           isButtonEnabled = not isInPyramid,
  //           msgTipsKey = msgTipsKey
  //         })
  //       end
  //     else
  //       local isEnable = true
  //       local isEnableZhenCha = true
  //       local isEnableGongJi = true
  //       if worldMapDefine.isRadianceKingdomID(self.kingdomID) then
  //         local selfSourceID = lordInfoCtrl:getMapSourceKid()
  //         if self.sourceKingdomID and 0 < self.sourceKingdomID and selfSourceID == self.sourceKingdomID then
  //           isEnable = false
  //           isEnableZhenCha = false
  //           msgTipsKey = i18n("brightWar_text_133")
  //         else
  //           do
  //             local radianceWarUtil = include("radianceWarUtil")
  //             isEnable = radianceWarUtil.isInSelfLeagueManor(self:getTilePoint(), selfLeagueID, 2)
  //             if not isEnable then
  //               function msgTipsKey()
  //                 radianceWarUtil.showGuildToBuild(self:getTilePoint())
  //               end
  //             end
  //           end
  //         end
  //         isEnableGongJi = isEnable
  //       elseif worldMapDefine.isInAtlantis() then
  //         isEnable = atlantis.isCanZhanling
  //         isEnableGongJi = atlantis.isCanZhanling
  //       elseif worldMapDefine.isInNebula() then
  //         local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
  //         if nebulaActivityCtrl:getCurRound() <= 3 then
  //           isEnable = false
  //           isEnableGongJi = false
  //           isEnableZhenCha = false
  //         end
  //       elseif _G.IsArClient then
  //         local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  //         if conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //           local selfSourceID = lordInfoCtrl:getMapSourceKid()
  //           if self.sourceID and 0 < self.sourceID and selfSourceID == self.sourceID then
  //             isEnable = false
  //             msgTipsKey = i18n("common_text_4576")
  //           end
  //         end
  //       end
  //       table.insert(buttonTypeArray, {
  //         buttonType = worldMapDefine.worldMapTipButtonType_gongJi,
  //         isButtonEnabled = isEnableGongJi,
  //         msgTipsKey = msgTipsKey
  //       })
  //       local haveHall = cityCtrl:getBuildCell(BUILDID.HALL_OF_WAR, 0)
  //       if haveHall and selfLeagueID > 0 and self.cityLevel >= CASTLE_LV6_LIMITED then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_xuanZhan,
  //           isButtonEnabled = isEnable,
  //           msgTipsKey = msgTipsKey
  //         })
  //       end
  //       local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
  //       if towerLv >= WATCH_TOWER_SCOUT_MIN_LV and not self.isSafe then
  //         local _msgTipsKey = msgTipsKey
  //         if worldMapDefine.isInAtlantis() then
  //           isEnableZhenCha = atlantis.isCanZhencha
  //           _msgTipsKey = atlantis.zhenchaTips
  //         end
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_zhenCha,
  //           isButtonEnabled = isEnableZhenCha,
  //           msgTipsKey = _msgTipsKey
  //         })
  //       end
  //       local lordSkillModuleAPI = include("lordSkillModuleAPI")
  //       local qianruinfo = lordSkillModuleAPI:getSkillCDData(LORD_SKILL_QIANRU)
  //       if self.isSafe and qianruinfo.isOpened then
  //         table.insert(buttonTypeArray, {
  //           buttonType = worldMapDefine.worldMapTipButtonType_qianru,
  //           isButtonEnabled = not isInPyramid
  //         })
  //       end
  //     end
  //   end
  //   if self:canHasEmojiOperator(selfPlayerID) then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_biaoqingyinzhang
  //     })
  //   end
  // end
  // table.insert(buttonTypeArray, {
  //   buttonType = worldMapDefine.worldMapTipButtonType_yongHuXinxi
  // })
  // if not isInWar then
  //   if 0 >= self.leaguedOfficialType and legendLordCtrl:getIsSelfLegendKing() then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_leaguerenMing
  //     })
  //   end
  //   if 0 >= self.kingStarOfficialType and kingStarCtrl:getIsSelfLegendKing() then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_kingStar_renMing
  //     })
  //   end
  //   if 0 >= self.hegemonOfficialType and hegemonCtrl:getIsSelfHegemon() then
  //     table.insert(buttonTypeArray, {
  //       buttonType = worldMapDefine.worldMapTipButtonType_hegemonrenMing
  //     })
  //   end
  // end
  // if 0 < self.prisonerNum then
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_prisonerIn
  //   })
  // end
  // if worldMapDefine.isRemainsKingdomID(self.kingdomID) and not worldMapDefine.isInRemains() then
  //   table.insert(buttonTypeArray, {
  //     buttonType = worldMapDefine.worldMapTipButtonType_remains_buff
  //   })
  // end
  // return buttonTypeArray
}

void WorldMapBuilding::LazyCreateOfficalImage(){
  // if self.officalImage == nil then
  //   local officalImage = display.newSprite("#frame_king_22.png")
  //   officalImage:setPosition(cc.p(self.centerPoint.x, self.centerPoint.y + 150))
  //   officalImage:setScale(0.75)
  //   officalImage:addTo(self, 5)
  //   local officialImaSize = officalImage:getContentSize()
  //   local officalIcon = display.newSprite("#icon_king.png")
  //   officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //   officalIcon:addTo(officalImage, 2)
  //   self.officalImage = officalImage
  //   self.officalIcon = officalIcon
  // else
  //   self.officalImage:setScale(0.75)
  //   self.officalIcon:setScale(1)
  //   self.officalImage:setVisible(true)
  //   self.officalIcon:removeAllChildren()
  // end
}

void WorldMapBuilding::UpdatePrisoneIn(){
  // if self.prisonerNum > 0 then
  //   self:lazyCreatePrisoneInImage()
  // elseif self.prisoneInIcon then
  //   self.prisoneInIcon:setVisible(false)
  // end
}

void WorldMapBuilding::LazyCreatePrisoneInImage(){
  // if not self.node_snowMan then
  //   if self.prisoneInIcon == nil then
  //     local prisoneInIcon = display.newSprite("#btn_hero_prison.png")
  //     prisoneInIcon:setPosition(cc.p(self.centerPoint.x, self.centerPoint.y + 120))
  //     prisoneInIcon:setScale(1.3)
  //     prisoneInIcon:addTo(self, 5)
  //     self.prisoneInIcon = prisoneInIcon
  //   else
  //     self.prisoneInIcon:setVisible(true)
  //   end
  //   local selfPlayerID = gametop.playertop_:getPlayerID() or 0
  //   if not self.isShowPrision and selfPlayerID == self.playerID then
  //     self.prisoneInIcon:setVisible(false)
  //   end
  // elseif self.prisoneInIcon then
  //   self.prisoneInIcon:setVisible(false)
  // end
}

void WorldMapBuilding::UpdateOfficial(){
  // self:updateBuildingImg()
  // local hide = true
  // if self.isShowOffice then
  //   local tbOfficialInfo = {}
  //   tbOfficialInfo.official = self.officialType
  //   tbOfficialInfo.legendTitle = self.leaguedOfficialType
  //   tbOfficialInfo.legendForSepTitle = self.kingStarOfficialType
  //   tbOfficialInfo.hegemonTitle = self.hegemonOfficialType
  //   tbOfficialInfo.atlantisOfficialType = self.atlantisOfficialType
  //   tbOfficialInfo.nebulaOfficialID = self.nebulaOfficialID
  //   tbOfficialInfo.nebulaOfficialID2 = self.nebulaOfficialID2
  //   tbOfficialInfo.showOfficialType = self.showOfficialType
  //   local showOfficialType = lordInfoCtrl:getShowOfficialTypeForLord(tbOfficialInfo)
  //   print("showOfficialType", showOfficialType, self.showOfficialType)
  //   hide = false
  //   if showOfficialType == gShowOfficialType.KING then
  //     self:lazyCreateOfficalImage()
  //     local officialInfoRead = include("officialInfoRead")
  //     local officialInfo = officialInfoRead.getInfoByType(self.officialType)
  //     if officialInfo then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialInfo.img))
  //       print("----------")
  //       dump(officialInfo, "officialInfo")
  //       if officialInfo.class < 2 then
  //         self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_king_23.png"))
  //         self:crownUpEffect(self.officalIcon)
  //       else
  //         self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_king_22.png"))
  //         self:crownDownEffect(self.officalIcon)
  //       end
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.LEGEND then
  //     self:lazyCreateOfficalImage()
  //     local legendKingRead = include("legendKingRead")
  //     local officialInfo = legendKingRead.getOfficialInfo(gLegendBuffType.PLAYER, self.leaguedOfficialType)
  //     if officialInfo then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialInfo.img))
  //       self.officalImage:setSpriteFrame(display.newSpriteFrame("icon_LegendaryKing_honor.png"))
  //       self:crownUpEffect(self.officalIcon)
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.KINGSTAR then
  //     self:lazyCreateOfficalImage()
  //     local legendKingRead = include("legendKingRead")
  //     local officialInfo = legendKingRead.getOfficialInfo(gLegendBuffType.PLAYER, self.kingStarOfficialType, worldMapDefine.KINGSTAR_KINGDOM_ID)
  //     if officialInfo then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialInfo.img))
  //       self.officalImage:setSpriteFrame(display.newSpriteFrame("icon_LegendaryKing_honor.png"))
  //       self:crownUpEffect(self.officalIcon)
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.HEGEMON then
  //     self:lazyCreateOfficalImage()
  //     self.officalImage:setScale(1)
  //     local hegemonRead = include("hegemonRead")
  //     local officialImage = hegemonRead.getOfficialIcon(self.hegemonOfficialType)
  //     local isGood = hegemonRead.judgeIsGood(self.hegemonOfficialType)
  //     if officialImage then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialImage))
  //       if isGood then
  //         self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_touxiangkuang_01.png"))
  //       else
  //         self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_touxiangkuang_02.png"))
  //       end
  //       if self.hegemonOfficialType == 1 then
  //         self.officalIcon:setScale(0.45)
  //       end
  //       if isGood then
  //         self:crownUpEffect(self.officalIcon)
  //       end
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.ATLANTIS then
  //     self:lazyCreateOfficalImage()
  //     self.officalImage:setScale(1)
  //     local lordOfficialRead = include("lordOfficialRead")
  //     local officialImage = lordOfficialRead.getOfficialIcon(showOfficialType, self.atlantisOfficialType)
  //     if officialImage then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialImage))
  //       self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_touxiangkuang_01.png"))
  //       self:crownUpEffect(self.officalIcon)
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.NEBULA then
  //     self:lazyCreateOfficalImage()
  //     self.officalImage:setScale(1)
  //     local lordOfficialRead = include("lordOfficialRead")
  //     local officialImage = lordOfficialRead.getOfficialIcon(showOfficialType, self.nebulaOfficialID)
  //     if officialImage then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialImage))
  //       self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_touxiangkuang_01.png"))
  //       self:crownUpEffect(self.officalIcon)
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   elseif showOfficialType == gShowOfficialType.NEBULA2 then
  //     self:lazyCreateOfficalImage()
  //     self.officalImage:setScale(1)
  //     local lordOfficialRead = include("lordOfficialRead")
  //     local officialImage = lordOfficialRead.getOfficialIcon(showOfficialType, self.nebulaOfficialID2)
  //     if officialImage then
  //       self.officalIcon:setSpriteFrame(display.newSpriteFrame(officialImage))
  //       self.officalImage:setSpriteFrame(display.newSpriteFrame("frame_touxiangkuang_01.png"))
  //       self:crownUpEffect(self.officalIcon)
  //       local officialImaSize = self.officalImage:getContentSize()
  //       self.officalIcon:setPosition(cc.p(officialImaSize.width / 2, officialImaSize.height / 2))
  //     end
  //   else
  //     hide = true
  //   end
  // end
  // if hide and self.officalImage and self.officalImage:isVisible() then
  //   self.officalImage:setVisible(false)
  //   self.officalIcon:removeAllChildren()
  // end
}

void WorldMapBuilding::UpdateTopShowIcons(){
  // local sortList = {
  //   self.prisoneInIcon,
  //   self.officalImage
  // }
  // local needShowTitleList = {}
  // for _, v in ipairs(sortList) do
  //   if v and v:isVisible() then
  //     table.insert(needShowTitleList, v)
  //   end
  // end
  // if #needShowTitleList >= 1 then
  //   local dis = #needShowTitleList * 105 / 2
  //   for i, v in ipairs(needShowTitleList) do
  //     v:setPosition(cc.p(self.centerPoint.x - dis + 52.5 + (i - 1) * 105, self.centerPoint.y + 120))
  //   end
  // end
}

void WorldMapBuilding::CreateMoveCityTimeNode(){
  // local node = display.newNode()
  // node:addTo(self, 100)
  // node:setPosition(cc.p(self.centerPoint.x, self.centerPoint.y - 130))
  // local image_bg = display.newSprite("#frame_map_18.png")
  // image_bg:setAnchorPoint(cc.p(0.5, 0.5))
  // image_bg:addTo(node)
  // self.imageMoveCityTime = display.newSprite("#icon_hourglass.png")
  // self.imageMoveCityTime:setAnchorPoint(cc.p(0.5, 0.5))
  // self.imageMoveCityTime:addTo(node)
  // self.txtMoveCityTime = cc.ui.UILabel.new({
  //   UILabelType = 2,
  //   text = "00:00:00",
  //   size = 20
  // })
  // self.txtMoveCityTime:setAnchorPoint(cc.p(0.5, 0.5))
  // self.txtMoveCityTime:addTo(node)
  // self.txtMoveCityTime = SoraDCreateTimerLabel(self, self.txtMoveCityTime)
  // self.txtMoveCityTime:setTimeLast(function(str, tick)
  //   local reText = i18n("remains_text_83", {time = str})
  //   return reText
  // end)
  // self.txtMoveCityTime:setTimeEndListener(function()
  //   self:cleanMoveTime()
  // end)
  // self.txtMoveCityTime:setTimeUpdateListener(function()
  //   self.imageMoveCityTime:setPositionX(SoraDFSign(self.txtMoveCityTime:getContentSize().width / 2 + 20))
  // end)
  // return node
}

void WorldMapBuilding::CleanMoveTime(){
  // self.moveCityTime = nil
  // self:updateMoveTime()
}

void WorldMapBuilding::UpdateMoveTime(){
  // if self.moveCityTime and self.moveCityTime > 0 then
  //   if not self.nodeMoveCityTime then
  //     self.nodeMoveCityTime = self:createMoveCityTimeNode()
  //   end
  //   if self.nodeMoveCityTime then
  //     self.nodeMoveCityTime:setVisible(true)
  //     if self.txtMoveCityTime then
  //       self.txtMoveCityTime:beginTime(self.moveCityTime)
  //     end
  //   end
  // elseif self.nodeMoveCityTime then
  //   self.nodeMoveCityTime:setVisible(false)
  // end
}

void WorldMapBuilding::UpdateWallWarning(EventCustom *pEvent){
  // local selfPlayerID = gametop.playertop_:getPlayerID() or 0
  // local playerID = self.playerID or 0
  // if selfPlayerID == playerID and playerID ~= 0 then
  //   local tipsHandler = function()
  //     local data = {
  //       msg = "MESSAGE_MAINCITYVIEW_MOVETO_BUILDBYBID",
  //       bid = BUILDID.WALLS,
  //       view = "defendView"
  //     }
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINSCEN_ONSHOW",
  //       viewType = VIEW_TYPE_CITY,
  //       otherData = data
  //     })
  //     SoraDRemoveAllPanelFromManager()
  //   end
  //   if worldMapDefine.isInNewTrial() then
  //     self:showWarningTip("devilvalley_text_23", tipsHandler)
  //   end
  // end
}

int32 WorldMapBuilding::GetSourceKingdomID(){
  // if self.sourceKingdomID then
  //   return self.sourceKingdomID
  // end
  // return self.kingdomID
}

void WorldMapBuilding::SendTileEffectMessage(EWorldMapLeagueManorUpdateType pUpdateType, float pRadius){
  // local selfPlayerID = gametop.playertop_:getPlayerID() or 0
  // local playerID = self.playerID or 0
  // local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  // local leagueID = self.leagueID or 0
  // local _raduis = raduis or talentSkillCtrl:getSkillConfig(3).raduis
  // SoraDSendMessage({
  //   msg = "MESSAGE_WORLD_MAP_UPDATE_TILE_EFFECT",
  //   tilePoint = self:getTilePoint(),
  //   holdInstace = self:getHoldInstace(),
  //   radiation = _raduis,
  //   isSelf = selfLeagueID > 0 and selfLeagueID == leagueID,
  //   instanceID = self.instanceID,
  //   updateType = updateType
  // })
}

GTuple<UIBasePanel *, bool, Node*> WorldMapBuilding::OnClickInstance(Node *pNode){
  // self:playClickSound()
  // return self:onShowWorldMapTip(onShowView)
}

GTuple<UIBasePanel *, bool, Node*> WorldMapBuilding::OnShowWorldMapTip(Node *pNode){
  // if gAtlantisUseSkillEffect then
  //   local atlantisWarCtrl = SoraDGetCtrl("atlantisWarCtrl")
  //   atlantisWarCtrl:reqThrowBossSkillToPlayer(gAtlantisUseSkillEffect, self.playerID)
  //   gAtlantisUseSkillEffect = nil
  //   return nil, false
  // end
  // self:setIsOnClick(true)
  // return worldMapInstance.onShowWorldMapTip(self, ...)
}

void WorldMapBuilding::RefreshSignShow(bool pIsShow){
  // if self.signature and self.signature ~= "" then
  //   self.signNode:setVisible(isShow)
  // else
  //   self.signNode:setVisible(false)
  // end
}

void WorldMapBuilding::RefreshSignText(){
  // if self.signature and self.signature ~= "" then
  //   self.signText:setString(self.signature)
  //   self:refreshSignShow(not self.isOnClick)
  //   if self.signatureBox and self.signatureBox == 1 then
  //     self.signText:setPosition(0, -10)
  //     self.signImage:loadTexture("frame_shmc_signature.png", ccui.TextureResType.plistType)
  //     self.signImage:setContentSize(cc.size(160, 110))
  //   else
  //     self.signText:setPosition(0, 12)
  //     self.signImage:loadTexture("frame_ssdt_qmk01.png", ccui.TextureResType.plistType)
  //     self.signImage:setContentSize(cc.size(150, 62))
  //   end
  // else
  //   self:refreshSignShow(false)
  // end
}

void WorldMapBuilding::SetIsOnClick(bool pIsOnClick){
  // self.isOnClick = isOnClick
  // self:refreshSignShow(not self.isOnClick)
}

void WorldMapBuilding::RefreshSkillEffect(const RWorldBuildingInitData &pData){
  // if not self.skillEffectList then
  //   self.skillEffectList = {
  //     [skillEffectType.RUINS_WAR_MOVE_CITY_LOCKED] = {
  //       key = "isMoveCityLocked",
  //       effect = nil
  //     },
  //     [skillEffectType.RUINS_WAR_SPEED_QUEUE_LOCKED] = {
  //       key = "isSpeedQueueLocked",
  //       effect = nil
  //     },
  //     [skillEffectType.APPOINT_DAMAGE_BOOST] = {
  //       key = "isInDamagePlus",
  //       effect = nil
  //     },
  //     [skillEffectType.APPOINT_CURE_SOLDIER_SPEED_BOOST] = {
  //       key = "isInCureSpeedPlus",
  //       effect = nil
  //     }
  //   }
  // end
  // for i, v in ipairs(self.skillEffectList) do
  //   if data[v.key] then
  //     if not v.effect then
  //       v.effect = self:createSkillEffect(i)
  //     end
  //   elseif v.effect then
  //     v.effect:removeFromParent()
  //     v.effect = nil
  //   end
  // end
}

void WorldMapBuilding::CreateSkillEffect(ESkillEffectType pEffectType){
  // if effectType == skillEffectType.RUINS_WAR_MOVE_CITY_LOCKED then
  //   local effect = SoraDCreatAnimation("Node_yjzz_jntx2", nil, false)
  //   effect:addTo(self, 6)
  //   effect:setPosition(0, 50)
  //   return effect
  // end
  // if effectType == skillEffectType.RUINS_WAR_SPEED_QUEUE_LOCKED then
  //   local effect = SoraDCreatAnimation("Node_yjzz_jntx1", nil, false)
  //   effect:addTo(self, 5)
  //   effect:setPosition(0, 0)
  //   return effect
  // end
  // if effectType == skillEffectType.APPOINT_DAMAGE_BOOST then
  //   local criSprite = cc.criSprite.createCriSprite("G_shixue.usm", false, true, nil)
  //   criSprite:addTo(self, 6)
  //   criSprite:setPosition(0, 80)
  //   criSprite:setBlendFunc(gl.ONE, gl.ONE)
  //   return criSprite
  // end
  // if effectType == skillEffectType.APPOINT_CURE_SOLDIER_SPEED_BOOST then
  //   local criSprite = cc.criSprite.createCriSprite("shengliao.usm", false, true, nil)
  //   criSprite:addTo(self, 6)
  //   criSprite:setPosition(-10, 50)
  //   return criSprite
  // end
}

void WorldMapBuilding::UpdateBuildStar(int32 pStarLv){
  // if starLv and starLv > 0 then
  //   self.starLv = starLv
  //   self.image_level:setSpriteFrame(display.newSpriteFrame("icon_main_buildstar_lv.png"))
  //   self.image_level:setGroupID(GROU_ID.build_star_normal)
  //   self.image_level:setPosition(cc.p(self.centerPoint.x + 90, self.centerPoint.y - 43))
  //   self.text_Level:setPosition(cc.p(self.centerPoint.x + 112, self.centerPoint.y - 49))
  //   local isShowWarLv, textLv = SoraDGetBuildWarLv(self.cityLevel)
  //   self.text_Level:setString(string.format("%d-%d", textLv, self.starLv))
  //   if not self.spStarLight then
  //     local sprite = display.newSprite()
  //     sprite:addTo(self.image_level)
  //     sprite:setPosition(83, 35)
  //     self.spStarLight = sprite
  //   end
  //   local iconName = cityltCtrl.getBuildStarLight(self.starLv)
  //   self.spStarLight:setSpriteFrame(iconName)
  //   self:checkAndSetVisible(self.spStarLight, true)
  // else
  //   self:checkAndSetVisible(self.spStarLight, false)
  // end
  // self:setBuildStarEffect()
}

void WorldMapBuilding::SetBuildStarEffect(){
  // if not self.starLv or not (self.starLv > 0) then
  //   self:checkAndSetVisible(self.buildStar_light, false)
  //   self:checkAndSetVisible(self.buildStar_level, false)
  //   return
  // end
  // local level = cityltCtrl.getBuildStarColor(self.starLv)
  // if not self.buildStar_light then
  //   local effect = SoraDCreatAnimation("Node_buildStar_light")
  //   effect:addTo(self)
  //   local x, y = self.image_level:getPosition()
  //   effect:setPosition(x + 20, y - 10)
  //   self.buildStar_light = effect
  //   for k, v in pairs(effect:getChildren()) do
  //     v:setPosition(0, 0)
  //     self:setBuildStarGroupID(v)
  //   end
  // end
  // self:checkAndSetVisible(self.buildStar_light, true)
  // local nodeName = string.format("Node_%d", level)
  // for k, v in pairs(self.buildStar_light:getChildren()) do
  //   v:setVisible(v:getName() == nodeName)
  // end
  // if level > 1 then
  //   if not self.buildStar_level then
  //     local effect = SoraDCreatAnimation("Node_buildStar_all")
  //     effect:addTo(self.warLVnode)
  //     self:setBuildStarGroupID(effect)
  //     self.buildStar_level = effect
  //   end
  //   for k, v in pairs(self.buildStar_level:getChildren()) do
  //     v:setVisible(false)
  //   end
  //   local node_moon = SoraDGetChildByName(self, "node_moon")
  //   self:checkAndSetVisible(node_moon, false)
  //   local node_top_sword = SoraDGetChildByName(self, "node_top_sword")
  //   self:checkAndSetVisible(node_top_sword, false)
  //   local __, warLv = SoraDGetBuildWarLv(self.cityLevel)
  //   local warLvColor = 0
  //   if warLv >= 6 and warLv <= 7 then
  //     warLvColor = 1
  //   elseif warLv >= 8 and warLv <= 9 then
  //     warLvColor = 2
  //   elseif warLv >= 10 then
  //     warLvColor = 3
  //   end
  //   local nodeName = string.format("Node_%d_%d", warLvColor, level - 1)
  //   local curEffect = SoraDGetChildByName(self.buildStar_level, nodeName)
  //   if curEffect then
  //     curEffect:setVisible(true)
  //     curEffect:setPosition(cc.p(0, 0))
  //     local data = worldMapDefine.getWarLevelData(warLv)
  //     if data then
  //       local pos = data.bottom.img.bg[1].pos
  //       local scale = data.bottom.scale or 1
  //       local offset = data.bottom.offset or cc.p(0, 0)
  //       local x = pos.x * scale + offset.x
  //       local y = pos.y * scale + offset.y
  //       curEffect:setPosition(cc.p(x, y))
  //     end
  //     local nodePos = {
  //       cc.p(-100, -70),
  //       cc.p(-50, -70),
  //       cc.p(170, 0),
  //       cc.p(130, 55)
  //     }
  //     for i = 1, 4 do
  //       local Node_a = SoraDGetChildByName(curEffect, "Node_a" .. i)
  //       if Node_a then
  //         Node_a:setPosition(nodePos[i])
  //       end
  //     end
  //   end
  //   self:checkAndSetVisible(self.buildStar_level, true)
  // else
  //   self:checkAndSetVisible(self.buildStar_level, false)
  //   local node_moon = SoraDGetChildByName(self, "node_moon")
  //   self:checkAndSetVisible(node_moon, true)
  //   local node_top_sword = SoraDGetChildByName(self, "node_top_sword")
  //   self:checkAndSetVisible(node_top_sword, true)
  // end
}

void WorldMapBuilding::SetBuildStarGroupID(Node *pTarget){}

bool WorldMapBuilding::IsSysWarProtect(){}
