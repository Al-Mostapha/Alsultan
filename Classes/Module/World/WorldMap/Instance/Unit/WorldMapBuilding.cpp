#include "WorldMapBuilding.h"
#include "Engine/OS.h"
#include "Base/Math/Math.Base.h"
#include "Base/Base.Const.h"
#include "Base/Common/Common.City.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapFireWorkEffect.h"
#include "Module/World/WorldMap/Instance/InstanceCache.Mgr.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapEffect.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/Skin/Castle/CastleSkin.Read.h"
#include "Module/Player/Skin/Castle/CastleSkin.ConfigRead.h"
#include "Module/Player/Buff/Attribute.Enum.h"
#include "Module/Player/Skill/LordSkillModule.Api.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Module/World/WorldWar/Remains/RemainsWar.Read.h"
#include "Module/World/WorldWar/LegendLord/LegendLord.Ctrl.h"
#include "Module/World/WorldWar/LegendLord/KingStar.Ctrl.h"
#include "Module/World/WorldWar/LegendLord/Hegemon.Ctrl.h"
#include "Module/World/WorldWar/LegendLord/LegendKing.Read.h"
#include "Module/World/WorldWar/LegendLord/Hegemon.Read.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Common/Panel.Manger.h"
#include "Base/Functions/ServiceFunction.h"
#include "Base/Utils/XTransition.h"
#include "Base/Base.Geometry.h"
#include "Base/Base.create.h"
#include "Engine/Base/UI/XUILabel.h"
#include "Module/Equip/Equip.Read.h"
#include "Module/Vip/ExaltedPrivilege.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Player/Official/OfficialInfo.Read.h"
#include "Module/Player/Official/LordOfficial.Read.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/WorldMap.Func.h"
#include "Module/City/City.Ctrl.h"
#include "Module/City/CityBuilding/City.LtCtrl.h"


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
  lParm._UILabelType = GBase::EUILabelType::TTF;
  lParm._Text = "";
  lParm._FontSize = 20;
  _TextName = GBase::DCreateLabel(lParm);
  _TextName->setAnchorPoint(Vec2(0.5, 0.5));
  _TextName->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 90));
  addChild(_TextName, 4);
  // self.text_Name:setGroupID(GROU_ID.group_text)
  _ImageLevel = GDisplay::Get()->NewSprite("icon_map_reslevel.png");
  _ImageLevel->setPosition(Vec2(_CenterPoint.x + 60, _CenterPoint.y - 50));
  addChild(_ImageLevel, 2);
  lParm._Text = "1";
  lParm._FontSize = 14;
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
  lParm._Text = "";
  lParm._FontSize = 14;
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
  // GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_TOGGLE_3D", CC_CALLBACK_1(IWorldMapInstance::Toggle3D, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_ENEMY_CASTLE_EFFECT", CC_CALLBACK_1(WorldMapBuilding::SetWarPlayerInfo, this));
  GBase::DAddMessage(this, "MESSAGE_WALLS_NOTIFY_TRIAL_WARNING", CC_CALLBACK_1(WorldMapBuilding::UpdateWallWarning, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_CASTLE_OFFICEICON", CC_CALLBACK_1(WorldMapBuilding::UpdateOfficeIcon, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_TITLE_SHOW", CC_CALLBACK_1(WorldMapBuilding::UpdateOfficeIcon, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_CASTLE_PRISIONICON", CC_CALLBACK_1(WorldMapBuilding::UpdatePrisionIcon, this));
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", CC_CALLBACK_1(WorldMapBuilding::UpdateAllianceCounter, this));
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

void WorldMapBuilding::InitCityData(void *pData){
  CC_ASSERT(pData);
  auto lData = static_cast<RWorldBuildingInitData *>(pData);
  UpdateData(*lData);
}

void WorldMapBuilding::UpdateData(const RWorldBuildingInitData &pData){
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  _PlayerID = pData._PlayerID;
  _PlayerName = pData._PlayerName;
  _PlayerLevel = pData._PlayerLevel;
  _InMapID = pData._InMapID;
  _HideBattleLev = pData._HideBattleLev;
  _OfficialType = pData._Official;
  _LeaguedOfficialType = pData._WorldOfficial;
  _KingStarOfficialType = pData._LegendForSepOfficial;
  _HegemonOfficialType = pData._HegemonOfficialType;
  _ShowOfficialType = pData._ShowOfficialType;
  _AtlantisOfficialType = pData._AtlantisOfficialType;
  _NebulaOfficialID = pData._NebulaOfficialID;
  _NebulaOfficialID2 = pData._NebulaOfficialID2;
  _FactionType = pData._FactionType;

  UpdateOfficial();
  UpdateTopShowIcons();
  UpdateEmojiByData(pData._PlayerID, pData._EmojiID);
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
    _TextLevel->setString(std::to_string(lTextShowLV));
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
        _FireWorkTimeNode = WorldMapEffect::Get()->CreateFireTimeNode();
        _FireWorkTimeNode->setPosition(Vec2(_CenterPoint.x - 0, _CenterPoint.y - 120));
        addChild(_FireWorkTimeNode, 5);
        _FireWorkTimeNode->Init(lLeftTime);
      }
    }
    if(pData._SelfCastleEffect == EWorldMapCastleEffectID::Snow_Effect && lLeftTime > 0){
      CastleSnowIceEffect();
    }
  }else{
    RemoveCastleFireWorkEffect();
  }
  if(pData._CastleAppearance)
    CastleSnowIceEffect(pData._PlayerID == lSelfPlayerID);

  if(pData._Attr.size()){
    auto lIsAdd = false;
    for(auto iii = 0; iii < sizeof(gRangeAttributeList)/sizeof(gRangeAttributeList[0]); iii++){
      auto lV = gRangeAttributeList[iii];
      if(pData._Attr.Contains(lV)){
        auto lAttr = pData._Attr.at(lV);
        if(IsNeedShowAttr(lV)){
          SendTileEffectMessage(EWorldMapLeagueManorUpdateType::Add, lAttr._Range);
          CheckAllCastleMeteorteEffect(pData._Attr, false);
          lIsAdd = true;
        }
        break;
      }
    }
    if(!lIsAdd)
      SendTileEffectMessage(EWorldMapLeagueManorUpdateType::Remove);
  }else{
    RemoveMeteoriteSkillEffect();
  }
  
  _Signature = pData._Signature;
  _SignatureBox = pData._SignatureBox;
  _CastleAppearanceEndTime = pData._CastleAppearanceEndTime;
  _SysWarProtectStatusEndTime = pData._SysWarProtectStatusEndTime;
  RefreshSignShow(true);
  RefreshSkillEffect(pData);
  UpdateBuildStar(pData._StarLv);
}

void WorldMapBuilding::ShowInstance(bool pShow, int32 pDelayTime){
  if(pDelayTime > 0){
    Vector<FiniteTimeAction *> lActionsArray;
    lActionsArray.pushBack(DelayTime::create(pDelayTime));
    lActionsArray.pushBack(CallFunc::create([=](){
      setVisible(pShow);
    }));
    auto lAction = XTransition::Get()->Sequence_(lActionsArray);
    runAction(lAction);
  }else{
    setVisible(pShow);
  }
  
  if(!pShow){
    SendTileEffectMessage(EWorldMapLeagueManorUpdateType::Remove);
    RemoveInstanceSelf();
  }
}

void WorldMapBuilding::UpdateLeagueInfo(){
  if(_WarCamp > 0){
    _ImageLeagueFlag->setVisible(true);
    if(_LeagueFlag){
      _ImageLeagueFlag->setSpriteFrame(RemainsWarRead::Get()->GetCampIcon(_WarCamp));
      if(_WarCamp == 1)
        _ImageLeagueFlag->setScale(0.5);
      else 
      _ImageLeagueFlag->setScale(1);
    }
  }else if(_LeagueID > 0){
    _ImageLeagueFlag->setVisible(true);
    if(_LeagueFlag){
      _ImageLeagueFlag->setSpriteFrame(AllianceRead::Get()->GetFlagIcon(_LeagueFlag));
      _ImageLeagueFlag->setScale(0.3f);
    }
  }else{
    _ImageLeagueFlag->setVisible(false);
  }
}

void WorldMapBuilding::UpdateBuildingImg(){
  
  _CityImage->removeAllChildren();
  _CitySkin1Image->removeAllChildren();
  RemoveSkinEffect();
  RemoveWarLvEffect();
  auto [lIsShowWarLv, lTextShowLv, lDes] =  GBase::DGetBuildWarLv(_CityLevel);
  _IsShowWarLv = lIsShowWarLv;
  if(_IsShowWarLv)
    WarLvEffect(lTextShowLv);
  auto lIsWarLv5 = _IsShowWarLv && lTextShowLv >= 5;
  _ImageNameBg->setVisible(lIsWarLv5);

  static const GVector<GString> lNodes = {
  "citySkin1Image_down", "dglNode", "castle47effect",
  "cscNode", "xlcbfdNode", "xczwcbNode", "Node_thunder_1",
  "Node_thunder_2", "Node_starfall_1", "Node_starfall_2",
  "Node_starfall_3", "Node_coffee", "Node_sgsl"
  };

  for(auto lOneNode : lNodes){
    if(getChildByName(lOneNode))
      removeChildByName(lOneNode, true);
  }

  if(_IsCityBgSkin != 0 && _NodeSnowMan){

    auto lSkinImageName = CastleSkinRead::Get()->GetMapImage(_IsCityBgSkin);
    auto lCastleModel = CastleSkinRead::Get()->GetCastleType(_IsCityBgSkin);

    if(lSkinImageName.size()){
      _CityImage->setVisible(false);
      _CitySkin1Image->setVisible(true);
      _CitySkin1Image->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lSkinImageName.c_str()));
      //     self:setSkinGroupID(castleModel)
      _CurCityImage = _CitySkin1Image;
      auto lSkinOffset = CastleSkinConfigRead::Get()->GetSkinOffset(lCastleModel);
      if(lSkinOffset)
        _CurCityImage->setPosition(lSkinOffset.value());
      _CurCityImage->setScale(1);
      if(lCastleModel == EBuildingCastleModel::KINGCOBRA)
        _CurCityImage->setScale(0.9);
      _ImgScale = IMG_PROTECT_SCALE_SKIN;
      _ImgOffset = IMG_OFFSET_SKIN;
      AddSkinEffect(lCastleModel);
      if(_IsShowWarLv)
        SetSkinConfig(lCastleModel, lTextShowLv);
      if(lCastleModel == EBuildingCastleModel::THUNDERCLOUD){
        _CitySkin1Image->setVisible(false);
        if(getChildByName("Node_thunder_1")){
          auto [lThunderNode1, lAction] = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/Node_thunder_1.csb", nullptr, false);
          lThunderNode1->setName("Node_thunder_1");
          lThunderNode1->setPosition(0, 100);
          addChild(lThunderNode1, 2);
          lAction->setFrameEventCallFunc([=](auto pFrame){
            static const auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_thunder_2.csb";
            auto lFrameEvent = dynamic_cast<cocostudio::timeline::EventFrame *>(pFrame);
            if(!lFrameEvent)
              return;
            if(lFrameEvent->getEvent() != "toSecond")
              return;
            auto [lThunderNode2, lAction2] = GBase::DCreateAnimation(lPath);
            lThunderNode2->setName("Node_thunder_2");
            lThunderNode2->setPosition(0, 100);
            addChild(lThunderNode2, 2);
          });
        }
      }
      
      if(lCastleModel == EBuildingCastleModel::SEVENTH){
        _CitySkin1Image->setVisible(false);
        if(!getChildByName("Node_starfall_1")){
          auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_starfall_1.csb";
          auto lT = GBase::DCreateAnimation(lPath, nullptr, false);
          auto lNodeStarFall1 = lT.First;
          auto lAction = lT.Second;

          lNodeStarFall1->setName("Node_starfall_1");
          lNodeStarFall1->setPosition(0, 50);
          addChild(lNodeStarFall1, -2);
          lAction->setFrameEventCallFunc([=](auto pFrame){
            auto lFrameEventName = dynamic_cast<cocostudio::timeline::EventFrame *>(pFrame);
            if(!lFrameEventName)
              return;
            if(lFrameEventName->getEvent() != "toSecond")
              return;
            static const auto lPath2 = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_starfall_2.csb";
            auto lT2 = GBase::DCreateAnimation(lPath2, nullptr, false);
            auto lNodeStarFall2 = lT2.First;
            auto lAction2 = lT2.Second;
            lNodeStarFall2->setName("Node_starfall_2");
            lNodeStarFall2->setPosition(0, 80);
            //       if self.citySkin1Image_groupID then
            //         SoraDGetChildByName(Node_starfall_2, "chengbaozhuangban_01"):setGroupID(self.citySkin1Image_groupID)
            //       end
            addChild(lNodeStarFall2, -1);
            lAction2->setFrameEventCallFunc([=](auto pFrame){
              auto lFrameEventName = dynamic_cast<cocostudio::timeline::EventFrame *>(pFrame);
              if(!lFrameEventName)
                return;
              if(lFrameEventName->getEvent() != "tothree")
                return;
              static const auto lPath3 = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_starfall_3.csb";
              auto [lNodeStarFall3, lAction3] = GBase::DCreateAnimation(lPath3);
              lNodeStarFall3->setName("Node_starfall_3");
              lNodeStarFall3->setPosition(0, 80);
              addChild(lNodeStarFall3, -1);
              // if self.citySkin1Image_groupID then
              //   SoraDGetChildByName(Node_starfall_3, "chengbaozhuangban_02"):setGroupID(self.citySkin1Image_groupID)
              // end
              lNodeStarFall1->setVisible(false);
              lNodeStarFall2->setVisible(false);
            });
          });
        }
      }

      if(lCastleModel == EBuildingCastleModel::CORBAN2021){
        static const auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_coffee.csb";
        auto [lNodeCoffee, lAction] = GBase::DCreateAnimation(lPath);
        lNodeCoffee->setName("Node_coffee");
        lNodeCoffee->setPosition(0, 100);
        addChild(lNodeCoffee, 2);
      }

      if(lCastleModel == EBuildingCastleModel::HOURGLASS){
        static const auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/Node_sgsl.csb";
        auto [lNodeSgsl, _] = GBase::DCreateAnimation(lPath);
        lNodeSgsl->setName("Node_sgsl");
        lNodeSgsl->setPosition(-15, -20);
        addChild(lNodeSgsl, 2);
      }

      if(lCastleModel == EBuildingCastleModel::DEGULA && !getChildByName("dglNode")){
        auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/degulacbwai.csb";
        auto [lDglNode, _] = GBase::DCreateAnimation(lPath);
        lDglNode->setName("dglNode");
        lDglNode->setPosition(40, 40);
        addChild(lDglNode, 2);
      }
      
      if(lCastleModel  == EBuildingCastleModel::ICECASTLE && !getChildByName("castle47effect")){
        auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/castle47effect.csb";
        auto [lCastle47Effect, _] = GBase::DCreateAnimation(lPath);
        lCastle47Effect->setName("castle47effect");
        lCastle47Effect->setPosition(-64, 100);
        addChild(lCastle47Effect, 2);
      }

      if(lCastleModel == EBuildingCastleModel::CONSTRUCTED && !getChildByName("cscNode")){
        auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/constructedCastle.csb";
        auto [lCscNode, _] = GBase::DCreateAnimation(lPath);
        lCscNode->setName("cscNode");
        lCscNode->setPosition(-2, 124);
        addChild(lCscNode, 2);
      }

      if(lCastleModel == EBuildingCastleModel::KOH2021RAMADAN && !getChildByName("xlcbfdNode")){
        auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/animationXLCBFD.csb";
        auto [lXlcbfdNode, _] = GBase::DCreateAnimation(lPath);
        lXlcbfdNode->setName("xlcbfdNode");
        lXlcbfdNode->setPosition(-70, -20);
        addChild(lXlcbfdNode, 1);
      }

      if(lCastleModel == EBuildingCastleModel::STARKING && !getChildByName("xczwcbNode")){
        auto lPath = "UiParts/Panel/World/WorldMap/Floor/Animation/animationXCZWCB.csb";
        auto [lXczwcbNode, _] = GBase::DCreateAnimation(lPath);
        lXczwcbNode->setName("xczwcbNode");
        lXczwcbNode->setPosition(-65, -40);
        addChild(lXczwcbNode, 1);
      }

      if(lCastleModel == EBuildingCastleModel::HALLOWEEN2018 && !getChildByName("citySkin1Image_down")){
        auto lSprite = GDisplay::Get()->NewSprite("Map_castle_Hallowmas2018_01.png");
        addChild(lSprite, -2);
        lSprite->setPosition(Vec2(-60, 40));
        lSprite->setName("citySkin1Image_down");
        lSprite->runAction(RepeatForever::create(Sequence::create(
          MoveBy::create(0.16666666666666666, Vec2(0, -1)),
          MoveBy::create(1.3333333333333333, Vec2(0, -9)),
          MoveBy::create(0.16666666666666666, Vec2(0, -1)),
          MoveBy::create(0.16666666666666666, Vec2(0, 1)),
          MoveBy::create(1.3333333333333333, Vec2(0, 9)),
          MoveBy::create(0.16666666666666666, Vec2(0, 1)),
          nullptr
        )));
        // if(_CitySkin1Image->getGroupID() > 0)
        //   lSprite->setGroupID(_CitySkin1Image->getGroupID());
      }

      if(lCastleModel == EBuildingCastleModel::GOLDENCITY){
        _CurCityImage->stopAllActions();
        auto lCurPosX = _CurCityImage->getPositionX();
        auto lCurPosY = _CurCityImage->getPositionY();
        _CurCityImage->runAction(RepeatForever::create(Sequence::create(
          MoveBy::create(0.03333333333333333, Vec2(lCurPosX, lCurPosY - 0.08)),
          MoveBy::create(3.3, Vec2(lCurPosX, lCurPosY - 15)),
          MoveBy::create(3.3, Vec2(lCurPosX, lCurPosY - 0.08)),
          MoveBy::create(0.03333333333333333, Vec2(lCurPosX, lCurPosY)),
          nullptr
        )));
      }else{
        _CurCityImage->stopAllActions();
      }
      return;
    }
  } 

  else if(_IsShowWarLv && (lTextShowLv == 5 || lTextShowLv == 10)){
    _ImgScale = IMG_PROTECT_SCALE_WAR_10;
    _ImgOffset = IMG_OFFSET_WAR_10;
  }else{
    _ImgScale = _IsShowWarLv ? IMG_PROTECT_SCALE_WAR : IMG_PROTECT_SCALE_DEF;
    _ImgOffset = _IsShowWarLv ? IMG_OFFSET_WAR : IMG_OFFSET_DEF;
  }

  if(!_NodeSnowMan){
    _CityImage->setVisible(true);
    _CitySkin1Image->setVisible(false);
    WorldMapDefine::Get()->CreateCityImageWithLevel(_CityLevel, _FactionType, _CityImage);
  }
}

void WorldMapBuilding::UpdateBuildingNecklace(){
  if(_NecklaceID && WorldMapDefine::Get()->IsInRadiance()){
    _NecklaceNode->setVisible(true);
    auto lNecklaceIcon = _NecklaceNode->getChildByName<Sprite *>("necklaceIcon");
    lNecklaceIcon->setSpriteFrame(EquipRead::Get()->GetIcon(_NecklaceID));
    auto lNecklaceName = _NecklaceNode->getChildByName<ui::Text *>("necklaceName");
    lNecklaceName->setString(EquipRead::Get()->GetName(_NecklaceID));
  }else{
    _NecklaceNode->setVisible(false);
  }
}

GString WorldMapBuilding::SetLendLordPlayerInfo(const GString &pName){
  auto lTextName = pName.size() ? pName : _PlayerName;
  if(_SourceKingdomID > 0){
    lTextName = lTextName + "#" + std::to_string(_SourceKingdomID);
  }
  return lTextName;
}

void WorldMapBuilding::UpdateWarLvEffect(){
  if(_WarLVNode)
    _WarLVNode->setVisible(!_HideBattleLev);
}

void WorldMapBuilding::UpdateAllianceCounter(EventCustom *pEvent){
  if(!pEvent)
    return;
  if(pEvent->getUserData())
    return;
  auto lData = (GPair<EGreenPointNoticeType, int32>*)pEvent->getUserData();
  if(lData->First != EGreenPointNoticeType::COUNTER_SYS)
    return;
  UpdateAllianceCounterAtkEffect(nullptr);
}

void WorldMapBuilding::UpdateOfficeIcon(EventCustom *pEvent){
  if(!_OfficalImage)
    return;
  auto lIsShow = GBase::DConfigGet<bool>("Game:worldMapOfficeIcon:OfficeIcon~bool", true);
  if(!lIsShow)
    lIsShow = true;
  if(_NodeSnowMan)
    lIsShow = false;
  _IsShowOffice = lIsShow.value();
  UpdateOfficial();

}

void WorldMapBuilding::UpdatePrisionIcon(EventCustom *pEvent){
  if(!_PrisoneInIcon)
    return;
  auto lIsShow = GBase::DConfigGet<bool>("Game:castleChangeSetting:PrisonHeroIcon~bool", true);
  if(!lIsShow)
    lIsShow = true;
  if(_NodeSnowMan)
    lIsShow = false;
  _IsShowPrision = lIsShow.value();
  UpdatePrisoneIn();
}

GString WorldMapBuilding::SetWarPlayerInfo(EventCustom *pEvent){
  auto lTextName = _PlayerName;
  if(pEvent && pEvent->getUserData())
    lTextName = *(GString*)pEvent->getUserData();
  auto lSelfeSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
  auto lIsMatchKingdom = ConquestWarCtrl::Get()->IsMatchKingdom(lSelfeSourceID, _KingdomID);
  if((lSelfeSourceID == _KingdomID || lIsMatchKingdom) && lSelfeSourceID != _SourceID){
    lTextName = lTextName + "#" + std::to_string(_SourceID);
    _TextName->setColor(Color3B(200, 0, 0));
    auto lIsShowWarSmoke = GBase::DConfigGet<bool>("Game:GameOptionsView:warSmoke~bool", true);
    if(lIsShowWarSmoke)
      AddEnemyCastleEffect();
    else
      RemoveEnemyCastleEffect();
    _ImageName->setSpriteFrame("frame_castle_name_enemy.png");
  }
  return lTextName;
}

void WorldMapBuilding::AddSkinEffect(EBuildingCastleModel pCastleModel){
  auto lEtNode = getChildByName("skinBgEffectNode");
  if(!lEtNode){
    auto lEtNode = WorldMapDefine::Get()->GetCastleSkinEffect(pCastleModel);
    addChild(lEtNode, 1);
  }
}

void WorldMapBuilding::RemoveSkinEffect(){
  if(getChildByName("skinBgEffectNode"))
    removeChildByName("skinBgEffectNode", true);
}

void WorldMapBuilding::SetSkinConfig(EBuildingCastleModel pCastleModel, int32 pWarLv){
  auto lConfig = CastleSkinConfigRead::Get()->GetSkinWarLvConfig(pCastleModel, pWarLv);
  if(lConfig){
    auto [lScale, lOffset] = lConfig.value();
    _WarLVNode->setScale(lScale);
    _WarLVNode->setPosition(lOffset);
  }else{
    _WarLVNode->setScale(1);
    auto lData = WorldMapDefine::Get()->GetWarLevelData(pWarLv);
    if(lData)
      _WarLVNode->setPosition(lData.value()._Offset);
    if(_CurCityImage)
      _CurCityImage->setPosition(Vec2(0, 0));
  }
}

void WorldMapBuilding::UpdateBuildingState(){
  UpdateFireEffect(_BuildingState);
}

void WorldMapBuilding::SetImgProtect(){
  if(IsSysWarProtect())
    _ImageProtect->SetIsGray(true);
  else 
    _ImageProtect->SetIsGray(false);
  _ImageProtect->setVisible(true);
  _ImageProtect->setScale(_ImgScale);
  _ImageProtect->setPosition(_CenterPoint + _ImgOffset);
}

void WorldMapBuilding::UpdateSafeState(){
  if(IsInAllianceWar()){
    SetImgProtect();
    AddPyramidProtectEffect();
  }else{
    RemovePyramidProtectEffect();
    if(_IsSafe){
      SetImgProtect();
    }else{
      _ImageProtect->setVisible(false);
    }
  }
}

void WorldMapBuilding::AddFireEffect(GTime pFireTime ){
  // worldMapInstance.addFireEffect(self, fightTime, data)
  // if data and data.fightingToPointX and data.fightingToPointY then
  //   self.facePoint = cc.p(data.fightingToPointX, data.fightingToPointY)
  // end
  DoFightingAnimation();
}

void WorldMapBuilding::DoFightingAnimation(){

  auto [lX, lY] = getPosition();
  auto lBeginPoint = Vec2(lX, lY + 30);
  auto lEndPoint = _FacePoint;
  auto lWorldMapView = dynamic_cast<WorldMapView *>(GBase::DCurrentSceneShowView("worldMapView"));
  if(lWorldMapView){
    lEndPoint = lWorldMapView->GetPointWithTile(_FacePoint);
  }
  
  auto lAngle = GBase::DGetAngleByPos(lBeginPoint, lEndPoint);
  auto lRadius = 80;
  GMath::Randomseed(GOS::Get()->GetTime());
  for(auto iii = 0; iii < _BulletNum; iii++){

    auto lBulletSprite = Sprite::createWithSpriteFrameName("icon_battle_jian_4.png");
    auto lRandomPointX = GMath::Random(-20, 20);
    auto lRandomPointY = GMath::Random(-20, 20);
    auto lRandomAngle = GMath::Random(-50, 50);
    auto lRandomDistence = lRadius + GMath::Random(-30, 30);
    auto lNewAngle = lAngle + lRandomAngle;
    auto lRadian = GMath::Angle2Radian(lNewAngle);
    auto lPointX = lRandomDistence * GMath::Cos(lRadian);
    auto lPointY = lRandomDistence * GMath::Sin(lRadian);
    auto lPoint1 = Vec2(lRandomPointX, lRandomPointY);
    auto lPoint2 = Vec2(lPointX, lPointY);
    auto lDelayTime = GMath::Random(0, 5) / 10;

    lBulletSprite->setPosition(lPoint1);
    lBulletSprite->setScale(0.5);
    _BulletNode->addChild(lBulletSprite, 1);

    WorldMapFunction::Get()->CreateThrowAction(lBulletSprite, lPoint1, lPoint2, lDelayTime);
  }

  Vector<FiniteTimeAction *> lActionsArray;
  lActionsArray.pushBack(DelayTime::create(3));
  lActionsArray.pushBack(CallFunc::create([=](){
    DoFightingAnimation();
  }));
  XTransition::Get()->Sequence_(lActionsArray);
  _FireNode->runAction(XTransition::Get()->Sequence_(lActionsArray));
}

void WorldMapBuilding::CrownUpEffect(Node *pNode){
  GVector<RCreatEffctParam> lParams(2);
  lParams[0]._PList = "et_castle_officer_01.plist";
  lParams[0]._Scale = {1.1f, 1.1f};
  lParams[1]._PList = "et_castle_officer_02.plist";
  lParams[1]._Scale = {1.3f, 1.3f};

  auto lParNode = GBase::DCreateEffectNode(lParams);
  lParNode->setPosition(Vec2(pNode->getContentSize().width / 2, pNode->getContentSize().height / 2));
  pNode->addChild(lParNode);
}

void WorldMapBuilding::CrownDownEffect(Node *pNode){
  GVector<RCreatEffctParam> lParams(1);
  lParams[0]._PList = "et_cwgz_01.plist";
  lParams[0]._Scale = {1.45f, 1.45f};
  auto lPaNode = GBase::DCreateEffectNode(lParams);
  lPaNode->setPosition(Vec2(pNode->getContentSize().width / 2, pNode->getContentSize().height / 2));
  pNode->addChild(lPaNode);
}

Node *WorldMapBuilding::CreateLvEffectNode(int32 pWarLv){
  auto lData = WorldMapDefine::Get()->GetWarLevelData(pWarLv);
  if(!lData)
    return nullptr;
  auto lNodeWarLvNode = GDisplay::Get()->NewNode();
  auto lNodeBottom = GDisplay::Get()->NewNode();
  lNodeWarLvNode->addChild(lNodeBottom, 1);
  auto lBottom = lData.value()._Bottom;
  auto lBottomImg = lBottom._Img;

  for(auto lV : lBottomImg._Bg){
    auto lBg = GDisplay::Get()->NewSprite(lV._Png.c_str());
    lBg->setPosition(lV._Pos);
    //   bg:setGroupID(GROU_ID.group_warLv_base)
    lNodeBottom->addChild(lBg, 1);
  }

  for(auto lV : lBottomImg._Dh){
    auto lDh = GDisplay::Get()->NewSprite(lV._Png.c_str());
    lDh->setPosition(lV._Pos);
    //   dh:setGroupID(GROU_ID.group_warLv_base)
    RFadeInOutParam lParam;
    lParam._BeginOpacity = 0.3f;
    lParam._EndOpacity = 0.7f;
    GBase::DFadeINOUT(lDh, lParam);
    lNodeBottom->addChild(lDh, 2);
  }
  
  if(!lBottom._Et.empty()){
    auto lEtBottom = GBase::DCreateEffectNode(lBottom._Et);
    //   et_bottom:setGroupID(GROU_ID.group_warLv_base_particle)
    //   et_bottom:setGroupAuto(true)
    lNodeBottom->addChild(lEtBottom, 3);
  }
  
  if(lBottom._Scale){
    lNodeBottom->setScale(lBottom._Scale.value());  
  }
  
  if(lBottom._Offset){
    lNodeBottom->setPosition(lBottom._Offset.value());
  }
  
  auto lTop = lData.value()._Top;
  auto lNodeTop = GDisplay::Get()->NewNode();
  lNodeWarLvNode->addChild(lNodeTop, 2);

  auto lTopImg = lTop._Img;

  for(auto lV : lTopImg._Bg){
    auto lBg = GDisplay::Get()->NewSprite(lV._Png.c_str());
    lBg->setPosition(lV._Pos);
    //   bg:setGroupID(GROU_ID.group_warLv_base)
    lNodeTop->addChild(lBg, 1);
  }

  for(auto lV : lTopImg._Dh){
    auto lDh = GDisplay::Get()->NewSprite(lV._Png.c_str());
    lDh->setPosition(lV._Pos);
    //   dh:setGroupID(GROU_ID.group_warLv_top)
    RFadeInOutParam lParam;
    lParam._BeginOpacity = 0.3f;
    lParam._EndOpacity = 0.7f;
    GBase::DFadeINOUT(lDh, lParam);
    lNodeTop->addChild(lDh, 2);
  }

  if(!lTop._Et.empty()){
    auto lEtTop = GBase::DCreateEffectNode(lTop._Et);
    //   et_top:setGroupID(GROU_ID.group_warLv_top_particle)
    //   et_top:setGroupAuto(true)
    lNodeTop->addChild(lEtTop, 3);
  }
  
  if(lTop._Scale){
    lNodeTop->setScale(lTop._Scale.value());  
  }
  
  if(lTop._Offset)
    lNodeTop->setPosition(lTop._Offset.value());

  auto lTopSword = lData.value()._TopSword;
  auto lNodeTopSword = GDisplay::Get()->NewNode();
  lNodeTop->addChild(lNodeTopSword, 2);
  lNodeTopSword->setName("node_top_sword");

  if(lTopSword){
    
    auto lTopImg = lTopSword.value()._Img;
    for(auto lV : lTopImg._Bg){
      auto lBg = GDisplay::Get()->NewSprite(lV._Png.c_str());
      //bg:setGroupID(GROU_ID.group_warLv_top)
      lBg->setPosition(lV._Pos);
      lNodeTopSword->addChild(lBg, 1);
    }

    for(auto lV : lTopImg._Dh){
      auto lDh = GDisplay::Get()->NewSprite(lV._Png.c_str());
      lDh->setPosition(lV._Pos);
      //   dh:setGroupID(GROU_ID.group_warLv_top)
      RFadeInOutParam lParam;
      lParam._BeginOpacity = 0.3f;
      lParam._EndOpacity = 0.7f;
      GBase::DFadeINOUT(lDh, lParam);
      lNodeTopSword->addChild(lDh, 2);
    }

    if(!lTopSword.value()._Et.empty()){
      auto lEtTop = GBase::DCreateEffectNode(lTopSword.value()._Et);
      //     et_top:setGroupID(GROU_ID.group_warLv_top_particle)
      //     et_top:setGroupAuto(true)
      lNodeTopSword->addChild(lEtTop, 3);
    }
  }
  
  auto lSeq = Sequence::create(
    MoveBy::create(1.5, Vec2(0, 5)),
    MoveBy::create(1.5, Vec2(0, -5)),
    nullptr
  );
  
  lNodeTop->runAction(RepeatForever::create(lSeq));

  if(lData.value()._Moon){
    
    auto lNodeMoon = GDisplay::Get()->NewNode();
    lNodeWarLvNode->addChild(lNodeMoon, 3);
    lNodeMoon->setName("node_moon");
    
    for(auto lV : lData.value()._Moon.value()._Img._Bg){
      auto lBg = GDisplay::Get()->NewSprite(lV._Png.c_str());
      lBg->setPosition(lV._Pos);
      //   bg:setGroupID(GROU_ID.group_warLv_top)
      lNodeMoon->addChild(lBg, 1);
    }

    for(auto lV : lData.value()._Moon.value()._Img._Dh){
      auto lDh = GDisplay::Get()->NewSprite(lV._Png.c_str());
      lDh->setPosition(lV._Pos);
      //   dh:setGroupID(GROU_ID.group_warLv_top)
      RFadeInOutParam lParam;
      lParam._BeginOpacity = 0.3f;
      lParam._EndOpacity = 0.7f;
      GBase::DFadeINOUT(lDh, lParam);
      lNodeMoon->addChild(lDh, 2);
    }
    
    if(!lData.value()._Moon.value()._Et.empty()){
      auto lEtTop = GBase::DCreateEffectNode(lData.value()._Moon.value()._Et);
      //     et_top:setGroupID(GROU_ID.group_warLv_top_particle)
      //     et_top:setGroupAuto(true)
      lNodeMoon->addChild(lEtTop, 3);
    }

    if(pWarLv == GBase::Const::Get()->CASTLE_NEX_MAX_WARLV){
      auto lSeq = Sequence::create(
        MoveBy::create(0.5833333333333334, Vec2(0, -8)),
        MoveBy::create(0.16666666666666666, Vec2(0, 4)),
        MoveBy::create(0.43333333333333335, Vec2(0, 8)),
        MoveBy::create(0.15, Vec2(0, -2)),
        MoveBy::create(0.5, Vec2(0, -8)),
        MoveBy::create(0.8333333333333334, Vec2(0, 6)),
        nullptr
      );
      lNodeMoon->runAction(RepeatForever::create(lSeq));
    }

    if(lData.value()._Moon.value()._Scale)
      lNodeMoon->setScale(lData.value()._Moon.value()._Scale.value());

    if(lData.value()._Moon.value()._Offset)
      lNodeMoon->setPosition(lData.value()._Moon.value()._Offset.value());
  }
  
  lNodeWarLvNode->setTag(WAR_LV_BEGIN_TYPE + pWarLv);
  return lNodeWarLvNode;
}

void WorldMapBuilding::WarLvEffect(int32 pWarLv){

  if(pWarLv == 0){
    RemoveWarLvEffect();
    return;
  }
  
  auto lData = WorldMapDefine::Get()->GetWarLevelData(pWarLv);
  if(!lData)
    return;
  _WarLVNode->setPosition(lData.value()._Offset);
  auto lNodeWarLvNode = InstanceCacheMgr::Get()->GetInstance(WAR_LV_BEGIN_TYPE + pWarLv);
  if(lNodeWarLvNode){
    _NodeWarLvNode = lNodeWarLvNode;
    _WarLVNode->addChild(lNodeWarLvNode);
    lNodeWarLvNode->release();
  }else{
    lNodeWarLvNode = CreateLvEffectNode(pWarLv);
    if(lNodeWarLvNode){
      _NodeWarLvNode = lNodeWarLvNode;
      _WarLVNode->addChild(lNodeWarLvNode);
    }else{
      CCLOG("createLvEffectNode error warLv %d", pWarLv);
    }
  }
}

void WorldMapBuilding::RemoveWarLvEffect(){
  if(_NodeWarLvNode){
    InstanceCacheMgr::Get()->AddNormalNode(_NodeWarLvNode);
    _NodeWarLvNode->removeFromParent();
    _NodeWarLvNode = nullptr;
  }
  _WarLVNode->setPosition(Vec2::ZERO);
}

void WorldMapBuilding::AddEnemyCastleEffect(){
  if(getChildByName("et_node_enemy"))
    return;
  GVector<RCreatEffctParam> lParams(1);
  lParams[0]._PList = "et_heiwu_display_01.plist";
  lParams[0]._Pos = {-8, -10};
  auto lEtNode = GBase::DCreateEffectNode(lParams);
  lEtNode->setName("et_node_enemy");
  addChild(lEtNode);
}

void WorldMapBuilding::RemoveEnemyCastleEffect(){
  if(getChildByName("et_node_enemy"))
    removeChildByName("et_node_enemy", true);
}

bool WorldMapBuilding::IsNeedShowAttr(EAttributeEnum pAttrType){
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
  auto lLeagueID = _LeagueID;
  for(auto lV : gMeteoriteSkillList){
    if(pAttrType == lV){
      if(lSelfLeagueID == lLeagueID)
        return true;
      else
        return false;
    }
  }
  return true;
}

void WorldMapBuilding::CheckAllCastleMeteorteEffect(const GHashMap<EAttributeEnum, RWorldBuildingInitDataAttr> &pAttr, bool pIsRemove){
  // local worldMapView = SoraDCurrentSceneShowView("worldMapView")
  auto lView = GBase::DCurrentSceneShowView("worldMapView");
  auto lWorldMapView = dynamic_cast<WorldMapView *>(lView);
  if(!lWorldMapView)
    return;
    
  auto lRet = lWorldMapView->GetShowTilesArray();
  if(lRet.empty())
    return;

  auto lSelfPoint = GetTilePoint();
  for(auto lV : gMeteoriteSkillList){
    if(pAttr.Contains(lV)){
      auto lAttrValue = pAttr.at(lV);
      auto lRect = Rect(lSelfPoint.x - lAttrValue._Range, lSelfPoint.y - lAttrValue._Range, lAttrValue._Range * 2, lAttrValue._Range * 2);
      for(auto [Key, lTileInstance] : lRet){
        if(lTileInstance && lTileInstance->_InstanceType == EMapObjTypeDef::mapObjTypePlayer && _LeagueID == lTileInstance->_LeagueID){
          auto lTilePoint = lTileInstance->GetTilePoint();
          if(lRect.containsPoint(lTilePoint)){
              CC_ASSERT(dynamic_cast<WorldMapBuilding *>(lTileInstance));
              dynamic_cast<WorldMapBuilding *>(lTileInstance)->AddMeteoriteSkillEffect(lV);
          }
        }
      }
    }
  }
}

void WorldMapBuilding::AddMeteoriteSkillEffect(EAttributeEnum pAttrType){
  if(pAttrType == EAttributeEnum::METEOR_MARCH_SPEED_BOOST){
    RemoveMeteoriteSkillEffect();
    auto lEffectSp = GDisplay::Get()->NewSprite("dh_chengbaosxzs_01.png");
    lEffectSp->setPosition(Vec2(-15, 50));
    lEffectSp->setScale(2);
    addChild(lEffectSp, 1);
    auto lFrames = GDisplay::Get()->NewFrames("dh_chengbaosxzs_%.2d.png", 1, 30);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 1 / lFrames.size());
    XTransition::Get()->PlayAnimationForever(lEffectSp, lAnimation);
    lEffectSp->runAction(Sequence::create(
      DelayTime::create(5),
      CallFunc::create([=](){
        RemoveMeteoriteSkillEffect();
      }),
      nullptr
    ));
    _MeteoriteEffect = lEffectSp;
  } else {
    auto lEffectSp = GDisplay::Get()->NewSprite("dh_chengbaosxjn_01.png");
    lEffectSp->setPosition(Vec2(-15, 150));
    lEffectSp->setScale(2.5);
    addChild(lEffectSp, 1);
    auto lFrames = GDisplay::Get()->NewFrames("dh_chengbaosxjn_%.2d.png", 1, 29);
    auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 2 / lFrames.size());
    XTransition::Get()->PlayAnimationOnce(lEffectSp, lAnimation, true);
  }
}

void WorldMapBuilding::RemoveMeteoriteSkillEffect(){
  if(_MeteoriteEffect){
    _MeteoriteEffect->removeFromParent();
    _MeteoriteEffect = nullptr;
  }
}

void WorldMapBuilding::CastleLoveEffect(){
  if(_EtNodeLove)
    return;

  GVector<RCreatEffctParam> lParams(4);
  lParams[0]._PList = "et_castlelove_02.plist";
  lParams[0]._Pos = {7.32, 27.46};
  lParams[1]._PList = "et_castlelove_03.plist";
  lParams[1]._Pos = {18.96, -59.42};
  lParams[2]._PList = "et_castlelove_04.plist";
  lParams[2]._Pos = {15.15, 10.27};
  lParams[2]._Scale = {2, 2};
  lParams[3]._PList = "et_castlelove_01.plist";
  lParams[3]._Pos = {9.99, 53.25};
  lParams[3]._Scale = {2.5, 4.6};
  _EtNodeLove = GBase::DCreateEffectNode(lParams);
  addChild(_EtNodeLove);
}

void WorldMapBuilding::RemoveCastleEffect(){

  if(_EtNodeLove){
    _EtNodeLove->removeFromParent();
    _EtNodeLove = nullptr;
  }

  if(_NodeSnowMan){
    _NodeSnowMan->removeFromParent();
    _NodeSnowMan = nullptr;
    UpdateBuildingImg();
    UpdateOfficeIcon(nullptr);
    UpdatePrisoneIn();
  }

  if(_EtNodeRainbow){
    _EtNodeRainbow->stopAllActions();
    _EtNodeRainbow->removeFromParent();
    _EtNodeRainbow = nullptr;
  }

  if(_EtNodeShining){
    _EtNodeShining->removeFromParent();
    _EtNodeShining = nullptr;
  }
  if(getChildByName("et_node_rainbow_1"))
    removeChildByName("et_node_rainbow_1", true);
  if(getChildByName("et_node_rainbow_2"))
    removeChildByName("et_node_rainbow_2", true);

}

void WorldMapBuilding::CastleSnowEffect(){
  if(_NodeSnowEffect)
    return;
  _NodeSnowEffect = GDisplay::Get()->NewNode();
  _NodeSnowEffect->setPosition(Vec2(-30, 70));
  addChild(_NodeSnowEffect, 1);
  auto lSnowEffect = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/animationSnowEffect.csb");
  _NodeSnowEffect->addChild(lSnowEffect.First);
}

void WorldMapBuilding::CastleSnowIceEffect(bool pIsSelf){

  if(_NodeSnowMan)
    return;
  _NodeSnowMan = GDisplay::Get()->NewNode();
  _NodeSnowMan->setPosition(Vec2::ZERO);
  addChild(_NodeSnowMan, 1);

  if(pIsSelf && _CastleAppearanceEndTime > 0){
    auto lLeftTime = GMath::Max(0, _CastleAppearanceEndTime - GOS::Get()->GetTime());
    auto lTimeNode = WorldMapEffect::Get()->CreateFireTimeNode();
    lTimeNode->setPosition(Vec2(0, -120));
    _NodeSnowMan->addChild(lTimeNode, 5);
    lTimeNode->Init(_CastleAppearanceEndTime);
  }
  
  _CurCityImage->setVisible(false);
  _CitySkin1Image->setVisible(false);
  UpdateOfficeIcon(nullptr);
  UpdatePrisoneIn();
  
  auto lXueren = GDisplay::Get()->NewSprite("xuerenzhuangban.png");
  lXueren->setPosition(Vec2(-45, 60));
  _NodeSnowMan->addChild(lXueren, 0);
  auto lYun = GDisplay::Get()->NewSprite("yunduozhuangban_001.png");
  lYun->setPosition(Vec2(-15, 100));
  lYun->setBlendFunc({GL_ONE, GL_ONE_MINUS_SRC_COLOR});
  _NodeSnowMan->addChild(lYun, 1);
  auto lFrames = GDisplay::Get()->NewFrames("yunduozhuangban_%.3d.png", 1, 20);
  auto lAnimation = GDisplay::Get()->NewAnimation(lFrames, 2 / lFrames.size());
  XTransition::Get()->PlayAnimationForever(lYun, lAnimation);

  GVector<RCreatEffctParam> lParams(9);

  lParams[0]._PList = "et_xuerenddj_01.plist";
  lParams[0]._Pos = {119.09, 53.82};
  lParams[0]._Scale = {1.35f, 1.35f};
  lParams[1]._PList = "et_xuerenddj_01.plist";
  lParams[1]._Pos = {-37.39, 57.54};
  lParams[1]._Scale = {1.65f, 1.65f};
  lParams[2]._PList = "et_xuerenddj_02.plist";
  lParams[2]._Pos = {-70.93, -33.32};
  lParams[3]._PList = "et_xuerenddj_02.plist";
  lParams[3]._Pos = {-14.11, -89.37};
  lParams[4]._PList = "et_xuerenddj_02.plist";
  lParams[4]._Pos = {152.46, -19.55};
  lParams[5]._PList = "et_xuerenddj_03.plist";
  lParams[5]._Pos = {41.9, -46.1};
  lParams[5]._Scale = {1.4237f, 1.4237f};
  lParams[6]._PList = "et_xuerenddj_04.plist";
  lParams[6]._Pos = {32.99, -36.95};
  lParams[6]._Scale = {1.1245f, 1.1245f};
  lParams[7]._PList = "et_xuerenddj_05.plist";
  lParams[7]._Pos = {117.46, 54.45};
  lParams[7]._Rotate = 179.07f;
  lParams[8]._PList = "et_xuerenddj_05.plist";
  lParams[8]._Pos = {-31.71, 53.92};
  lParams[8]._Scale = {0.8419f, 0.8419f};
  lParams[8]._Rotate = 179.07f;
  
  auto lEtNode = GBase::DCreateEffectNode(lParams);
  lEtNode->setPosition(Vec2(-45, 45));
  _NodeSnowMan->addChild(lEtNode, 0);
}

void WorldMapBuilding::CastleShiningEffect(){
  if(_EtNodeShining)
    return;
  _EtNodeShining = GDisplay::Get()->NewNode();
  _EtNodeShining->setPosition(0, 0);
  addChild(_EtNodeShining);
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
  if(GBase::DGetFactionType() == EFactionType::Byzantine)
    _EtNodeShining->setScale(1.2);
}

void WorldMapBuilding::CastleShining2Effect(){
  if(_EtNodeShining)
    return;
  auto lEffect = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/Node_bxcqcb_effect.csb");
  addChild(lEffect.First, 999);
  lEffect.First->setPosition(Vec2(-60, 120));
  auto lHideName = GBase::DFIsRA() ? "Sprite_text_en" : "Sprite_text_ar";
  GBase::DGetChildByName<Node *>(lEffect.First, lHideName)->setVisible(false);
  _EtNodeShining = lEffect.First;
}

void WorldMapBuilding::CastleShining3Effect(){
  if(_EtNodeShining)
    return;
  auto [lEffect, _] = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/animationXLCBCWTX.csb");
  lEffect->setName("xlcbtxNode");
  lEffect->setPosition(Vec2(-45, 140));
  addChild(lEffect, 2);
  _EtNodeShining = lEffect;
}

// Frozen Lion effect
void WorldMapBuilding::CastleShining4Effect(){
  if(_EtNodeShining)
    return;
  auto [lEffect, _] = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/animationBYXLCBYHTX.csb");
  lEffect->setPosition(-45, 140);
  addChild(lEffect, 2);
  _EtNodeShining = lEffect;
}

void WorldMapBuilding::CastleRainbowEffect(){
  if(_EtNodeRainbow)
    return;
  auto lBPercent = 0;
  auto lEPercent = 78;
  auto lActionTime = 2;
  auto lPerFrame = float(lEPercent) / (lActionTime * 60);
  auto lIsEffectShow = false;
  _EtNodeRainbow = GDisplay::Get()->NewNode();
  _EtNodeRainbow->setPosition(_CenterPoint + Vec2(-20, 50));
  addChild(_EtNodeRainbow, 9);
  auto lProgressRainbow = GDisplay::Get()->NewProgressTimer("icon_rainbow.png", ProgressTimer::Type::RADIAL);
  lProgressRainbow->setRotation(-140);
  _EtNodeRainbow->addChild(lProgressRainbow, 9);
  lProgressRainbow->setPercentage(lBPercent);

  auto lFreeEffect = [this](){
    auto lBeginPos = _CenterPoint + Vec2(-161, -128.5);
    auto lControl1 = _CenterPoint + Vec2(-55.44f, 307.77f);
    auto lControl2 = _CenterPoint + Vec2(281, 393.5);
    auto lEndPos = _CenterPoint + Vec2(315.6f, 147.8f);

    GVector<RCreatEffctParam> lParams(1);
    lParams[0]._PList = "et_caihong_01.plist";
    lParams[0]._Pos = lBeginPos;
    lParams[0]._Scale = {2.237f, 2.237f};
    lParams[0]._Rotate = -18.87f;
    lParams[0]._PosType = ParticleSystem::PositionType::FREE;

    auto lEtRainbow = GBase::DCreateEffectNode(lParams);
    lEtRainbow->setName("et_node_rainbow_2");
    addChild(lEtRainbow, 10);
    auto lSeq = Sequence::create(
      EaseSineIn::create(BezierTo::create(1.6, {lControl1, lControl2, lEndPos})),
      CallFunc::create([lEtRainbow](){
        GBase::DStopEffectNode(lEtRainbow);
      }),
      nullptr
    );
    lEtRainbow->runAction(lSeq);
  };

  auto lSeqRainbow = Sequence::create(
    Spawn::create(
      CallFunc::create([&](){
        lBPercent = 0;
        lProgressRainbow->stopAllActions();
        lProgressRainbow->setPercentage(lBPercent);
        auto lSeq = Sequence::create(
          CallFunc::create([&](){
            lBPercent += lPerFrame;
            if(lBPercent <= lEPercent)
              lProgressRainbow->setPercentage(lBPercent);
            else
              lProgressRainbow->stopAllActions();
          }),
          DelayTime::create(0.016666666666666666),
          nullptr
        );
        lProgressRainbow->runAction(RepeatForever::create(lSeq));
      }),
      CallFunc::create([this, lFreeEffect](){
        lFreeEffect();
      }),
      nullptr
    ),
    DelayTime::create(2),
    CallFunc::create([this, &lIsEffectShow](){
      if(lIsEffectShow)
        return;
      GVector<RCreatEffctParam> lParams(3);
      lParams[0]._PList = "et_caihong_02.plist";
      lParams[0]._Rotate = -22.21f;
      lParams[0]._Pos = _CenterPoint + Vec2{19.28f, 24.46f};
      lParams[1]._PList = "et_caihong_03.plist";
      lParams[1]._Scale = {-0.855f, 0.876f};
      lParams[1]._Rotate = 42.65f;
      lParams[1]._Pos = _CenterPoint + Vec2{29.f, 76.06f};
      lParams[2]._PList = "et_caihong_03.plist";
      lParams[2]._Scale = {2.237f, 2.237f};
      lParams[2]._Rotate = -18.87f;
      lParams[2]._Pos = _CenterPoint + Vec2{61.85f, 147.93f};
      auto lEtNode = GBase::DCreateEffectNode(lParams);
      lEtNode->setName("et_node_rainbow_1");
      lEtNode->setPosition(Vec2::ZERO);
      addChild(lEtNode, 10);
      lIsEffectShow = true;
    }), nullptr
  );
  _EtNodeRainbow->runAction(lSeqRainbow);
}

void WorldMapBuilding::RemoveCastleFireWorkEffect(){
  if(_FireWork){
    _FireWork->removeFromParent();
    _FireWork = nullptr;
    if(_FireWorkTimeNode){
      _FireWorkTimeNode->stopAllActions();
      _FireWorkTimeNode->removeFromParent();
      _FireWorkTimeNode = nullptr;
    }
  }

  if(_NodeSnowEffect){
    _NodeSnowEffect->removeFromParent();
    _NodeSnowEffect = nullptr;
  }
}

void WorldMapBuilding::AddPyramidProtectEffect(){

  GVector<RCreatEffctParam> lParams(4);

  lParams[0]._PList = "et_cjztzc_protect_01.plist";
  lParams[0]._Pos = {0, 140};
  lParams[0]._Scale = {2, 2};
  lParams[1]._PList = "et_cjztzc_protect_02.plist";
  lParams[1]._Pos = {0, 140};
  lParams[1]._Scale = {2, 2};
  lParams[2]._PList = "et_cjztzc_protect_03.plist";
  lParams[2]._Pos = {0, 140};
  lParams[2]._Scale = {2, 2};
  lParams[3]._PList = "et_cjztzc_protect_04.plist";
  lParams[3]._Pos = {0, 140};
  lParams[3]._Scale = {2, 2};

  if(_PyramidProtectNode){
    GBase::DResetEffectNode(_PyramidProtectNode);
  }else{
    _PyramidProtectNode = GBase::DCreateEffectNode(lParams);
    addChild(_PyramidProtectNode, 5);
    _PyramidProtectNode->setScale(_ImgScale);
    _PyramidProtectNode->setPosition(_ImgOffset);
  }
}

void WorldMapBuilding::RemovePyramidProtectEffect(){
  if(_PyramidProtectNode){
    _PyramidProtectNode->removeFromParent();
    _PyramidProtectNode = nullptr;
  }
}

GString WorldMapBuilding::GetFavoriteName(){
  auto lFavoriteName = _PlayerName;
  if(!_LeagueName.empty())
    lFavoriteName = Translate::i18n("common_text_186", {
      {"abbr", _LeagueName.c_str()},
      {"name", _PlayerName.c_str()}
    });
  return lFavoriteName;
}

void WorldMapBuilding::PlayClickSound(){
  GBase::PlaySound("innerbuildsound", 101);
}

GVector<RButtonTypeArray> WorldMapBuilding::GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar){
  GVector<RButtonTypeArray> lButtonTypeArray;
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();

  if(pIsSelfKingdom){
    
    auto lPlayerID = _PlayerID;
    auto lLeagueID = _LeagueID;

    if(lSelfPlayerID == _PlayerID){

      lButtonTypeArray.push_back({EWorldMapTipButtonType::jinruChengshi});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::chengshiZengyi});
      lButtonTypeArray.push_back({EWorldMapTipButtonType::decorate});
      if(ExaltedPrivilegeCtrl::Get()->CheckPrivilege(EExaltedPrivilege::SIGNATURE))
        lButtonTypeArray.push_back({EWorldMapTipButtonType::sign});
      
    }else{
      if(!pIsInWar && WorldMapDefine::Get()->_kingdomStatus == EKingStatus::king)
        lButtonTypeArray.push_back({EWorldMapTipButtonType::renMing});
      auto lIsInPyramid = IsInAllianceWar();
      GString lMsgTipsKey;
      if(WorldMapDefine::Get()->IsInAtlantis()){
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
      }else if(WorldMapDefine::Get()->IsInNebula()){
        //       local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
        //       if nebulaActivityCtrl:getCurRound() <= 3 then
        //         isInPyramid = true
        //         msgTipsKey = i18n("nebula_war_text_0194")
        //       end
      }

      if(lSelfLeagueID > 0 && lSelfLeagueID == _LeagueID){
        if(WorldMapWarDef::Get()->IsInWarForbidResourceHelp())
          lButtonTypeArray.push_back({EWorldMapTipButtonType::ziyuanYuanzhu, ! lIsInPyramid, lMsgTipsKey});
        
        if(KingdomMapCtrl::Get()->HasMyQueue(EMapMoveLineServerType::MassSlave, {}, {}, _PlayerID))
          lButtonTypeArray.push_back({EWorldMapTipButtonType::jijieBuduiXinxi});
        
        if(KingdomMapCtrl::Get()->HasArmyHelpQueue2Player(_PlayerID, EMapMoveLineStatusType::Working)){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::chakanYuanjun});
        }else{
          lButtonTypeArray.push_back({EWorldMapTipButtonType::shibingYuabzhu, ! lIsInPyramid, lMsgTipsKey});
        }
      }else{
        
        auto lIsEnable = true;
        auto lIsEnableZhenCha = true;
        auto lIsEnableGongJi = true;

        if(WorldMapDefine::Get()->IsRadianceKingdomID(_KingdomID)){
          auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
          if(_SourceKingdomID > 0 && _SourceKingdomID == lSelfSourceID){
            lIsEnable = false;
            lIsEnableZhenCha = false;
            lMsgTipsKey = Translate::i18n("brightWar_text_133");
          }else{
            //    local radianceWarUtil = include("radianceWarUtil")
            //    isEnable = radianceWarUtil.isInSelfLeagueManor(self:getTilePoint(), selfLeagueID, 2)
            //    if not isEnable then
            //      function msgTipsKey()
            //        radianceWarUtil.showGuildToBuild(self:getTilePoint())
            //      end
            //    end
          }
          lIsEnableGongJi = lIsEnable;
        } else if(WorldMapDefine::Get()->IsInAtlantis()){
          //         isEnable = atlantis.isCanZhanling
          //         isEnableGongJi = atlantis.isCanZhanling
        }else if(WorldMapDefine::Get()->IsInNebula()){
          //         local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
          //         if nebulaActivityCtrl:getCurRound() <= 3 then
          //           isEnable = false
          //           isEnableGongJi = false
          //           isEnableZhenCha = false
          //         end
        }else if(GBase::Const::Get()->IsArClient){
          if(ConquestWarCtrl::Get()->IsConquestWarOpenningAndNotInWar()){
            auto lSelfSourceID = LordInfoCtrl::Get()->GetMapSourceKid();
            if(_SourceID > 0 && lSelfSourceID == _SourceID){
              lIsEnable = false;
              lMsgTipsKey = Translate::i18n("common_text_4576");
            }
          }
        }
      
        lButtonTypeArray.push_back({EWorldMapTipButtonType::gongJi, lIsEnableGongJi, lMsgTipsKey});
        
        auto lHaveHall = CityCtrl::Get()->GetBuildingCell(EBuilding::HallOfWar, EBuildingIndex::None);
        if(lHaveHall && lSelfLeagueID > 0 && _CityLevel >= GBase::Const::Get()->CastleLvl6){
          lButtonTypeArray.push_back({EWorldMapTipButtonType::xuanZhan, lIsEnable, lMsgTipsKey});
        }
        
        auto lTowerLv = CityCtrl::Get()->GetBuildingMaxLv(EBuilding::WatchTower);
        if(lTowerLv >= GBase::Const::Get()->WATCH_TOWER_SCOUT_MIN_LV && ! _IsSafe){
          auto l_MsgTipsKey = lMsgTipsKey;
          //         if worldMapDefine.isInAtlantis() then
          //           isEnableZhenCha = atlantis.isCanZhencha
          //           _msgTipsKey = atlantis.zhenchaTips
          //         end
          lButtonTypeArray.push_back({EWorldMapTipButtonType::zhenCha, lIsEnableZhenCha, l_MsgTipsKey});
        }
        auto lQianRuInfo = LordSkillModuleAPI::Get()->GetSkillCDData(GBase::Const::Get()->LORD_SKILL_QIANRU);
        if(_IsSafe && lQianRuInfo._IsOpened)
          lButtonTypeArray.push_back({EWorldMapTipButtonType::qianru, ! lIsInPyramid});
      }
    } 
    if(CanHasEmojiOperator(lSelfPlayerID)){
      lButtonTypeArray.push_back({EWorldMapTipButtonType::biaoqingyinzhang});
    }
  }
  
  lButtonTypeArray.push_back({EWorldMapTipButtonType::yongHuXinxi});

  if(!pIsInWar){
    if(_LeaguedOfficialType <= 0 && LegendLordCtrl::Get()->GetIsSelfLegendKing())
      lButtonTypeArray.push_back({EWorldMapTipButtonType::leaguerenMing});
    if(_HegemonOfficialType <= 0 && KingStarCtrl::Get()->GetIsSelfLegendKing())
      lButtonTypeArray.push_back({EWorldMapTipButtonType::kingStar_renMing});
    if(_HegemonOfficialType <= 0 && HegemonCtrl::Get()->GetIsSelfHegemon())
      lButtonTypeArray.push_back({EWorldMapTipButtonType::hegemonrenMing});
  }

  if(_PrisonerNum > 0)
    lButtonTypeArray.push_back({EWorldMapTipButtonType::prisonerIn});
  
  if(WorldMapDefine::Get()->IsRemainsKingdomID(_KingdomID) && ! WorldMapDefine::Get()->IsInRemains())
    lButtonTypeArray.push_back({EWorldMapTipButtonType::remains_buff});
  
  return lButtonTypeArray;
}

void WorldMapBuilding::LazyCreateOfficalImage(){
  if(!_OfficalImage){
    _OfficalImage = GDisplay::Get()->NewSprite("frame_king_22.png");
    _OfficalImage->setPosition(_CenterPoint + Vec2(0, 150));
    _OfficalImage->setScale(0.75f);
    addChild(_OfficalImage, 5);
    auto lOfficialImgSize = _OfficalImage->getContentSize();
    _OfficalIcon = GDisplay::Get()->NewSprite("icon_king.png");
    _OfficalIcon->setPosition(lOfficialImgSize / 2);
    _OfficalImage->addChild(_OfficalIcon, 2);
  }else{
    _OfficalImage->setScale(0.75f);
    _OfficalIcon->setScale(1);
    _OfficalImage->setVisible(true);
    _OfficalIcon->removeAllChildren();
  }
}

void WorldMapBuilding::UpdatePrisoneIn(){
  if(_PrisonerNum > 0){
    LazyCreatePrisoneInImage();
  }else{
    _PrisoneInIcon->setVisible(false);
  }
}

void WorldMapBuilding::LazyCreatePrisoneInImage(){
  if(!_NodeSnowMan){
    if(!_PrisoneInIcon){
      _PrisoneInIcon = GDisplay::Get()->NewSprite("btn_hero_prison.png");
      _PrisoneInIcon->setPosition(_CenterPoint + Vec2(0, 120));
      _PrisoneInIcon->setScale(1.3f);
      addChild(_PrisoneInIcon, 5);
    }else{
      _PrisoneInIcon->setVisible(true);
    }
    auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
    if(!_IsShowPrision && lSelfPlayerID == _PlayerID)
      _PrisoneInIcon->setVisible(false);
  }else if(_PrisoneInIcon){
    _PrisoneInIcon->setVisible(false);
  }
}

void WorldMapBuilding::UpdateOfficial(){
  UpdateBuildingImg();
  auto lHide = true;
  
  if(_IsShowOffice) {
    
    RLordInfo lTbOfficialInfo;
    lTbOfficialInfo._Official = _OfficialType;
    lTbOfficialInfo._LegendTitle = _LeaguedOfficialType;
    lTbOfficialInfo._LegendForSepTitle = _KingStarOfficialType;
    lTbOfficialInfo._HegemonTitle = _HegemonOfficialType;
    lTbOfficialInfo._AtlantisOfficialType = _AtlantisOfficialType;
    lTbOfficialInfo._NebulaOfficialID = _NebulaOfficialID;
    lTbOfficialInfo._NebulaOfficialID2 = _NebulaOfficialID2;
    lTbOfficialInfo._ShowOfficialType = _ShowOfficialType;
    auto lShowOfficialType = LordInfoCtrl::Get()->GetShowOfficialTypeForLord(lTbOfficialInfo);
    lHide = false;

    if(lShowOfficialType == EShowOfficialType::KING){
      LazyCreateOfficalImage();
      auto lOfficialInfo = OfficialInfoRead::Get()->GetInfoByType(_OfficialType);
      if(lOfficialInfo){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialInfo.value()._Img.c_str()));
        if((int32)lOfficialInfo.value()._Class < (int32)EOfficialPersonClass::Bad){
          _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_king_23.png"));
          CrownUpEffect(_OfficalIcon);
        }else{
          _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_king_22.png"));
          CrownDownEffect(_OfficalIcon);
        }
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::LEGEND){
      LazyCreateOfficalImage();
      auto lOfficialInfo = LegendKingRead::Get()->GetOfficialInfo(ELegendBuffType::PLAYER, _LeaguedOfficialType);
      if(lOfficialInfo){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialInfo.value()._Img.c_str()));
        _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("icon_LegendaryKing_honor.png"));
        CrownUpEffect(_OfficalIcon);
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::KINGSTAR){
      LazyCreateOfficalImage();
      auto lOficialInfo = LegendKingRead::Get()->GetOfficialInfo(ELegendBuffType::PLAYER, _KingStarOfficialType, (int32)WorldMapDefine::Get()->KINGSTAR_KINGDOM_ID);
      if(lOficialInfo){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOficialInfo.value()._Img.c_str()));
        _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("icon_LegendaryKing_honor.png"));
        CrownUpEffect(_OfficalIcon);
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::HEGEMON){
      LazyCreateOfficalImage();
      _OfficalImage->setScale(1);
      auto lOfficialImage = HegemonRead::Get()->GetOfficialIcon(_HegemonOfficialType);
      auto lIsGood = HegemonRead::Get()->JudgeIsGood(_HegemonOfficialType);
      if(lOfficialImage){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialImage.value().c_str()));
        if(lIsGood){
          _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_touxiangkuang_01.png"));
        }else{
          _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_touxiangkuang_02.png"));
        }
        if(_HegemonOfficialType == 1){
          _OfficalIcon->setScale(0.45f);
        }
        if(lIsGood){
          CrownUpEffect(_OfficalIcon);
        }
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::ATLANTIS){
      LazyCreateOfficalImage();
      _OfficalImage->setScale(1);
      auto lOfficialImage = LordOfficialRead::Get()->GetOfficialIcon(lShowOfficialType, _AtlantisOfficialType);
      if(lOfficialImage){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialImage.value().c_str()));
        _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_touxiangkuang_01.png"));
        CrownUpEffect(_OfficalIcon);
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::NEBULA){
      LazyCreateOfficalImage();
      _OfficalImage->setScale(1);
      auto lOfficialImage = LordOfficialRead::Get()->GetOfficialIcon(lShowOfficialType, _NebulaOfficialID);
      if(lOfficialImage){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialImage.value().c_str()));
        _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_touxiangkuang_01.png"));
        CrownUpEffect(_OfficalIcon);
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else if(lShowOfficialType == EShowOfficialType::NEBULA2){
      LazyCreateOfficalImage();
      _OfficalImage->setScale(1);
      auto lOfficialImage = LordOfficialRead::Get()->GetOfficialIcon(lShowOfficialType, _NebulaOfficialID2);
      if(lOfficialImage){
        _OfficalIcon->setSpriteFrame(GDisplay::Get()->NewSpriteFrame(lOfficialImage.value().c_str()));
        _OfficalImage->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("frame_touxiangkuang_01.png"));
        CrownUpEffect(_OfficalIcon);
        _OfficalIcon->setPosition(_OfficalImage->getContentSize() / 2);
      }
    } else {
      lHide = true;
    }
  }

  if(lHide && _OfficalImage && _OfficalImage->isVisible()){
    _OfficalImage->setVisible(false);
    _OfficalIcon->removeAllChildren();
  }
}

void WorldMapBuilding::UpdateTopShowIcons(){
  GVector<Node *> lNeedShowTitleList;
  if(_PrisoneInIcon && _PrisoneInIcon->isVisible())
    lNeedShowTitleList.push_back(_PrisoneInIcon);
  if(_OfficalImage && _OfficalImage->isVisible())
    lNeedShowTitleList.push_back(_OfficalImage);
  
  if(lNeedShowTitleList.size() >= 1){
    auto lDis = lNeedShowTitleList.size() * 105 / 2;
    for(int32 i = 0; i < lNeedShowTitleList.size(); ++i){
      lNeedShowTitleList[i]->setPosition(Vec2(_CenterPoint.x - lDis + 52.5 + i * 105, _CenterPoint.y + 120));
    }
  }
}

Node *WorldMapBuilding::CreateMoveCityTimeNode(){
  auto lNode = GDisplay::Get()->NewNode();
  addChild(lNode, 100);
  lNode->setPosition(_CenterPoint + Vec2(0, -130));
  auto lImageBg = GDisplay::Get()->NewSprite("frame_map_18.png");
  lImageBg->setAnchorPoint(Vec2(0.5, 0.5));
  lNode->addChild(lImageBg);
  _ImageMoveCityTime = GDisplay::Get()->NewSprite("icon_hourglass.png");
  _ImageMoveCityTime->setAnchorPoint(Vec2(0.5, 0.5));
  lNode->addChild(_ImageMoveCityTime);
  UIFontLabelParam lParam;
  lParam._FontSize = 20;
  lParam._Text = "00:00:00";
  lParam._UILabelType = GBase::EUILabelType::TTF;

  _TxtMoveCityTime = XUILabel::Create<UITimerLabel>(lParam);
  _TxtMoveCityTime->setAnchorPoint(Vec2(0.5, 0.5));
  lNode->addChild(_TxtMoveCityTime);
  _TxtMoveCityTime->SetTimeLast([](const GString &pStr, GTime tick){
    return Translate::i18n("remains_text_83", {{"time", pStr}});
  });
  _TxtMoveCityTime->SetTimeEndListener([this](){
    CleanMoveTime();
  });
  _TxtMoveCityTime->SetTimeUpdateListener([this](GTime pTick){
    _ImageMoveCityTime->setPositionX(GBase::DFSign(_TxtMoveCityTime->getContentSize().width / 2 + 20));
  });
  return lNode;
}

void WorldMapBuilding::CleanMoveTime(){
  _MoveCityTime = 0;
  UpdateMoveTime();
}

void WorldMapBuilding::UpdateMoveTime(){
  if(_MoveCityTime > 0){
    if(!_NodeMoveCityTime){
      _NodeMoveCityTime = CreateMoveCityTimeNode();
    }
    if(_NodeMoveCityTime){
      _NodeMoveCityTime->setVisible(true);
      if(_TxtMoveCityTime){
        _TxtMoveCityTime->BeginTime(_MoveCityTime);
      }
    }
  }else if(_NodeMoveCityTime){
    _NodeMoveCityTime->setVisible(false);
  }
}

void WorldMapBuilding::UpdateWallWarning(EventCustom *pEvent){
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lPlayerID = _PlayerID;
  if(_PlayerID == lSelfPlayerID && _PlayerID != 0){
    if(WorldMapDefine::Get()->IsInNewTrial()){
      ShowWarningTip("devilvalley_text_23", [this](){
        static RShowMainCityView lShowMainCityView;
        lShowMainCityView.ViewType = EScene::City;
        lShowMainCityView.OtherData._Msg = "MESSAGE_MAINCITYVIEW_MOVETO_BUILDBYBID";
        lShowMainCityView.OtherData._BID = EBuilding::Wall;
        lShowMainCityView.OtherData._View = "defendView";
        GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &lShowMainCityView);
        GPanelManger::Get()->DRemoveAllPanelFromManager();
      });
    }
  }
}

int32 WorldMapBuilding::GetSourceKingdomID(){
  if(_SourceKingdomID)
    return _SourceKingdomID;
  return _KingdomID;
}

void WorldMapBuilding::SendTileEffectMessage(EWorldMapLeagueManorUpdateType pUpdateType, float pRadius){
  
  auto lSelfPlayerID = PlayerTop::Get()->GetPlayerID();
  auto lSelfLeagueID = AllianceManager::Get()->GetOwnTeamID();
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
  PlayClickSound();
  return OnShowWorldMapTip(pNode);
}

GTuple<UIBasePanel *, bool, Node*> WorldMapBuilding::OnShowWorldMapTip(Node *pNode){
  // if gAtlantisUseSkillEffect then
  //   local atlantisWarCtrl = SoraDGetCtrl("atlantisWarCtrl")
  //   atlantisWarCtrl:reqThrowBossSkillToPlayer(gAtlantisUseSkillEffect, self.playerID)
  //   gAtlantisUseSkillEffect = nil
  //   return nil, false
  // end
  SetIsOnClick(true);
  return IWorldMapInstance::OnShowWorldMapTip(this);
}

void WorldMapBuilding::RefreshSignShow(bool pIsShow){
  if(_Signature.empty()){
    _SignNode->setVisible(false);
  }else{
    _SignNode->setVisible(pIsShow);
  }
}

void WorldMapBuilding::RefreshSignText(){
  if(!_Signature.empty()){
    _SignText->setString(_Signature);
    RefreshSignShow(!_IsOnClick);
    if(_SignatureBox == ESignatureBoxType::Normal){
      _SignText->setPosition(Vec2(0, -10));
      _SignImage->loadTexture("frame_shmc_signature.png", ui::Widget::TextureResType::PLIST);
      _SignImage->setContentSize(Size(160, 110));
    }else{
      _SignText->setPosition(Vec2(0, 12));
      _SignImage->loadTexture("frame_ssdt_qmk01.png", ui::Widget::TextureResType::PLIST);
      _SignImage->setContentSize(Size(150, 62));
    }
  }else{
    RefreshSignShow(false);
  }
}

void WorldMapBuilding::SetIsOnClick(bool pIsOnClick){
  _IsOnClick = pIsOnClick;
  RefreshSignShow(!_IsOnClick);
}

void WorldMapBuilding::RefreshSkillEffect(const RWorldBuildingInitData &pData){
  // static GHashMap<ESkillEffectType, GPair<GString, Node *>> lSkillEffectTypeList = {
  //   {ESkillEffectType::RUINS_WAR_MOVE_CITY_LOCKED, {"isMoveCityLocked", nullptr}},
  //   {ESkillEffectType::RUINS_WAR_SPEED_QUEUE_LOCKED, {"isSpeedQueueLocked", nullptr}},
  //   {ESkillEffectType::APPOINT_DAMAGE_BOOST, {"isInDamagePlus", nullptr}},
  //   {ESkillEffectType::APPOINT_CURE_SOLDIER_SPEED_BOOST, {"isInCureSpeedPlus", nullptr}}
  // };
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

Node *WorldMapBuilding::CreateSkillEffect(ESkillEffectType pEffectType){
  // if effectType == skillEffectType.RUINS_WAR_MOVE_CITY_LOCKED then
  //   local effect = SoraDCreatAnimation("Node_yjzz_jntx2", nil, false)
  //   effect:addTo(self, 6)
  //   effect:setPosition(0, 50)
  //   return effect
  // end
  if(pEffectType == ESkillEffectType::RUINS_WAR_SPEED_QUEUE_LOCKED){
    auto lEffect = GBase::DCreateAnimation("Node_yjzz_jntx1", nullptr, false);
    addChild(lEffect.First, 5);
    lEffect.First->setPosition(Vec2(0, 0));
    return lEffect.First;
  }
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
  if(pStarLv > 0){
    _StarLv = pStarLv;
    _ImageLevel->setSpriteFrame(GDisplay::Get()->NewSpriteFrame("icon_main_buildstar_lv.png"));
    //   self.image_level:setGroupID(GROU_ID.build_star_normal)
    _ImageLevel->setPosition(_CenterPoint + Vec2(90, -43));
    _TextLevel->setPosition(_CenterPoint + Vec2(112, -49));
    auto [lIsShWarLv, lTextLv, l_] = GBase::DGetBuildWarLv(_CityLevel);
    _TextLevel->setString(StringUtils::format("%s-%d", lTextLv, _StarLv));
    if(!_SpStarLight){
      _SpStarLight = Sprite::create();
      _ImageLevel->addChild(_SpStarLight);
      _SpStarLight->setPosition(83, 35);
    }
    auto lIconName = CityLtCtrl::Get()->GetBuildStarLight(_StarLv);
    _SpStarLight->setSpriteFrame(lIconName);
    CheckAndSetVisible(_SpStarLight, true);
  }else{
    CheckAndSetVisible(_SpStarLight, false);
  }
  SetBuildStarEffect();
}

void WorldMapBuilding::CheckAndSetVisible(Node *pWidget, bool pIsVisible){
  if(pWidget)
    pWidget->setVisible(pIsVisible);
}

void WorldMapBuilding::SetBuildStarEffect(){
  if(_StarLv == 0){
    CheckAndSetVisible(_BuildStarLight, false);
    CheckAndSetVisible(_BuildStarLevel, false);
  }
  auto lLevel = CityLtCtrl::Get()->GetBuildStarColor(_StarLv);
  if(!_BuildStarLight){
    auto lEffect = GBase::DCreateAnimation("UiParts/Panel/World/WorldMap/Floor/Animation/Node_buildStar_light.csb");
    addChild(lEffect.First);
    lEffect.First->setPosition(_ImageLevel->getPosition() + Vec2(20, -10));
    _BuildStarLight = lEffect.First;
    for(auto lChild : lEffect.First->getChildren()){
      lChild->setPosition(Vec2(0, 0));
      SetBuildStarGroupID(lChild);
    }
  }
  CheckAndSetVisible(_BuildStarLight, true);
  auto lNodeName = StringUtils::format("Node_%d", lLevel);
  for(auto lChild : _BuildStarLight->getChildren()){
    lChild->setVisible(lChild->getName() == lNodeName);
  }
  if(lLevel > 1){
    if(_BuildStarLevel){
      auto [lEffect, _] = GBase::DCreateAnimation("Node_buildStar_all");
      _WarLVNode->addChild(lEffect);
      _BuildStarLevel = lEffect;
    }

    for(auto lChild : _BuildStarLevel->getChildren()){
      lChild->setVisible(false);
    }
    auto lNodeMoon = GBase::DGetChildByName<Node *>(_BuildStarLevel, "node_moon");
    CheckAndSetVisible(lNodeMoon, false);
    auto lNodeTopSword = GBase::DGetChildByName<Node *>(_BuildStarLevel, "node_top_sword");
    CheckAndSetVisible(lNodeTopSword, false);
    auto [_, lWarLv, lStr] = GBase::DGetBuildWarLv(_CityLevel);
    int32 lWarLvColor = 0;
    if(lWarLv >= 6 && lWarLv <= 7)
      lWarLvColor = 1;
    else if(lWarLv >= 8 && lWarLv <= 9)
      lWarLvColor = 2;
    else if(lWarLv >= 10)
      lWarLvColor = 3;
    auto lNodeName = StringUtils::format("Node_%d_%d", lWarLvColor, _StarLv - 1);
    auto lCurEffect = GBase::DGetChildByName<Node *>(_BuildStarLevel, lNodeName.c_str());
    if(lCurEffect){
      lCurEffect->setVisible(true);
      lCurEffect->setPosition(Vec2(0, 0));
      auto lData = WorldMapDefine::Get()->GetWarLevelData(lWarLv);
      if(lData){
        auto lPos = lData->_Bottom._Img._Bg[0]._Pos;
        auto lScale = lData->_Bottom._Scale.value();
        auto lOffset = lData->_Bottom._Offset.value();
        auto lX = lPos.x * lScale + lOffset.x;
        auto lY = lPos.y * lScale + lOffset.y;
        lCurEffect->setPosition(Vec2(lX, lY));
      }
      static auto lNodePos = GVector<Vec2>{
        Vec2(-100, -70),
        Vec2(-50, -70),
        Vec2(170, 0),
        Vec2(130, 55)
      };
      for(int32 i = 0; i < 4; ++i){
        auto lNodeA = GBase::DGetChildByName<Node *>(lCurEffect, StringUtils::format("Node_a%d", i + 1).c_str());
        if(lNodeA){
          lNodeA->setPosition(lNodePos[i]);
        }
      }
    }
    CheckAndSetVisible(_BuildStarLevel, true);
  }else{
    CheckAndSetVisible(_BuildStarLevel, false);
    auto lNodeMoon = GBase::DGetChildByName<Node *>(_BuildStarLevel, "node_moon");
    CheckAndSetVisible(lNodeMoon, true);
    auto lNodeTopSword = GBase::DGetChildByName<Node *>(_BuildStarLevel, "node_top_sword");
    CheckAndSetVisible(lNodeTopSword, true);
  }
}

void WorldMapBuilding::SetBuildStarGroupID(Node *pTarget){}

bool WorldMapBuilding::IsSysWarProtect(){
  auto lEndTime = _SysWarProtectStatusEndTime;
  if(lEndTime > 0 && lEndTime > GOS::Get()->GetTime())
    return true;
  else
    return false;
}
