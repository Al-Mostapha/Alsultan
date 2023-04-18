#include "UIMainBottom.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "spine/SkeletonAnimation.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/UI/Animations/UIAnimationCollectItems.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/Guild/Help/GuildHelp.h"
#include "Module/Effect/EffectMainUITop.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/Questionnaire/UIQuestionnaire.View.h"
#include "Module/UI/EventCenter/EventTemplate/RaidersLostArk/UIRaidersLostArk.View.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "module/UI/Panel/Alliance/CounterSys/AllianceCounterSys.Ctrl.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/Guild/AllianceTreasure.Ctrl.h"
#include "Module/UI/Panel/Alliance/AllianceMobilization/PlayerMobilization.Ctrl.h"
#include "Module/UI/Panel/Alliance/AllianceActive/AllianceActive.Ctrl.h"
#include "Module/UI/Panel/Alliance/AllianceHunt/AllianceHunt.Ctrl.h"
#include "Module/Guild/Alliance.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Science/AllianceScience.h"
#include "Module/Guild/AllianceGuide.Ctrl.h"
#include "Module/Mail/Mail.Mgr.h"
#include "Module/Hero/Hero.Ctrl.h"
#include "Module/Item/Config/ShopLt.Ctrl.h"
#include "Module/Item/Shop/LimitTimeDiscountShop.Api.h"
#include "Module/Guild/AllianceMember.Mgr.h"
#include "Module/Guild/LegendTeam/LegendTeam.Util.h"
#include "Game/Guide/Guide.Ctrl.h"
#include "Module/City/CityBuilding/CityBuilding.Func.h"
#include "Base/Type/EventArg/Lord/ShowLordInfo.EvtArg.h"
#include "Base/Type/EventArg/Alliance/AllianceInfo.EvtArg.h"
#include "Module/UI/Panel/Lord/UILordView.h"
#include "Module/UI/Panel/Lord/Skill/UISkillNewActive.View.h"
#include "Module/UI/Panel/Alliance/AllianceInfo/UIAllianceInfo.View.h"
#include "Module/UI/Panel/Alliance/Create/UIAllianceJoin.View.h"
#include "Module/City/Expostulation.Logic.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/LostRuins.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/WindTower.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/SnowWolfLost/SnowWolfLost.Ctrl.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/UILostRuinsRecord.View.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/UIWindTowerHistory.View.h"
#include "Module/UI/EventCenter/EventTemplate/SnowWolfLost/UISnowWolfRecord.h"
#include "Module/UI/EventCenter/EventTemplate/Questionnaire/UIQuestionnaire.View.h"
#include "Module/UI/EventCenter/EventTemplate/EnjoyLottery/UIEnjoyLottery.View.h"
#include "Module/UI/EventCenter/EventTemplate/SultanBack/UISultansBackWelBack.View.h"
#include "Module/UI/EventCenter/EventTemplate/GoldPackage/UIEventGoldPackage.View.h"
#include "Module/UI/Panel/Hero/HeroDetail/UIHeroList.View.h"
#include "Module/UI/Panel/Item/BagView/UIBag.View.h"
#include "Module/UI/Panel/Mail/UIMail.View.h"
#include "Module/UI/Panel/Recharge/UIRechargeMonthlyFrame.h"
#include "Module/UI/Panel/Alliance/AllianceWar/UIAllianceWar.View.h"
#include "Module/UI/Panel/Alliance/AllianceMain/UIAllianceMain.View.h"
#include "Module/UI/Panel/Alliance/AllianceWar/AtlantisWar/UIAtlantisWarTeamView.h"
#include "Module/Activity/ActivityShow.Ctrl.h"

void UIMainBottom::Ctor() {
  // cityBuildData:removeMessageListener()
  // cityBuildData:registerMessageListener()
  // userSDKManager.setAudioTarget(chatAudioMgr)
  n_NodeLOD = GBase::GetChildByName<Node*>(this, "Node_LOD");
  n_NodeAreaRb = GBase::GetChildByName<Node*>(n_NodeLOD, "Node_area_rb");
  n_NodeAreaLb = GBase::GetChildByName<Node*>(n_NodeLOD, "Node_area_lb");
  n_NodeAreaB = GBase::GetChildByName<Node*>(this, "Node_area_b");
  auto* l_AnimationCollectItems = UIAnimationCollectItems::Create();
  n_NodeAreaB->addChild(l_AnimationCollectItems, 10);
  l_AnimationCollectItems->setName("animationCollectItems");
  m_ViewChangeType = EScene::City;
  InitGroup();
  n_UiBg = GBase::GetChildByName<Sprite*>(this, "UI_Label_BG");
  n_UiBgLeft = GBase::GetChildByName<ui::ImageView*>(this, "Image_decor_left");
  n_UiBgLeft->setVisible(GBase::Const::Get()->IsArClient);
  n_UiBgRight = GBase::GetChildByName<ui::ImageView*>(this, "Image_decor_right");
  n_UiBgRight->setVisible(GBase::Const::Get()->IsArClient);
  n_NodeStyleBg = GBase::GetChildByName<Node*>(this, "Node_style_bg");
  n_NodeStyleTop = GBase::GetChildByName<Node*>(this, "Node_style_top");
  
  InitStyle();
  n_TipItems = GBase::GetChildByName<ui::ImageView*>(this, "Sprite_items");
  n_TipAlliance = GBase::GetChildByName<ui::ImageView*>(this, "Sprite_alliance");
  n_TipMail = GBase::GetChildByName<ui::ImageView*>(this, "Sprite_mail");
  n_TipHero = GBase::GetChildByName<ui::ImageView*>(this, "Sprite_hero");
  n_TipHero->setVisible(false);
  auto l_TestText = GBase::GetChildByName<ui::Text*>(this, "Text_hero");
  auto l_TestLabel = GBase::GetChildByName<Label*>(this, "Text_hero");
  n_TipHeroCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_hero"));
  // self.tipHeroCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipMailCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_mail"));
  // self.tipMailCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipAllianceCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_alliance"));
  // self.tipAllianceCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipItemsCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_items"));
  // self.tipItemsCount:setGroupID(mainUIDef.newGroupID.text)
  // self.imgWarning = SoraDGetRedWarnning()
  n_ChatMainUIView = GBase::DGetExtendChildFromCCSByName<UIChatMainUiView>(this, "CCS_chatMainUIView_Node");
  n_ChatMainUIView->InitWithData();
  n_FrameWorldCity = GBase::GetChildByName<Sprite*>(this, "frame_btn_worldCity");
  n_ButtonWorldCity = GBase::GetChildByName<ui::Button*>(this, "Button_worldCity");
  n_ImgWorldCity = GBase::GetChildByName<ui::ImageView*>(this, "img_worldCity");
  if (n_ImgWorldCity) n_ButtonWorldCity->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnWorldCityClick, this));
  // self.nodeQuestGuide = SoraDGetExtendChildFromCCSByName(self, "CCS_questGuideNode_quest")
  n_BtnAccount = GBase::GetChildByName<ui::Button*>(this, "Button_account");
  n_BtnAccount->setVisible(false);
  n_IconAccount = GBase::GetChildByName<Sprite*>(n_BtnAccount, "icon_set_account");
  n_RedPointAccount = GBase::GetChildByName<Sprite*>(this, "Sprite_redPoint");
  n_BtnPyramidBattle = GBase::GetChildByName<ui::Button*>(this, "Button_pyramidBattle");
  n_SpriteBattleTimeBg = GBase::GetChildByName<Sprite*>(this, "Sprite_battleTimeBg");
  n_TxtPyramidBattleTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(this, "Text_battleTime"));
  n_BtnPyramidPlayoffs = GBase::GetChildByName<ui::Button*>(this, "Button_pyramidPlayoffs");
  n_ImgPyramidPlayoffsBg = GBase::GetChildByName<Sprite*>(n_BtnPyramidPlayoffs, "Sprite_playoffBg");
  n_TxtPyramidPlayoffsTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(this, "Text_playoffTime"));
  n_BtnCityUnlock = GBase::GetChildByName<ui::Button*>(this, "Button_cityUnlockBuild");
  n_SpriteCityUnlock = GBase::GetChildByName<Sprite*>(n_BtnCityUnlock, "Sprite_unlock");
  n_TxtCityUnlock = GBase::GetChildByName<ui::Text*>(n_BtnCityUnlock, "Text_unlock");
  n_BtnNewPlayerBuff = GBase::GetChildByName<ui::Button*>(this, "Button_newPlayerBuff");
  n_TextNewPlayer = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnNewPlayerBuff, "Text_newPlayer"));
  n_BtnPrinceGiftNewBuff = GBase::GetChildByName<ui::Button*>(this, "Button_princeGiftNewBuff");
  // self.textPrinceGiftNew = SoraDGetChildByName(self.btnPrinceGiftNewBuff, "Text_princeGiftNewBuff")
  n_TextPrinceGiftNew = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnPrinceGiftNewBuff, "Text_princeGiftNewBuff"));
  // self.Sprite_princeGiftNewBuff = SoraDGetChildByName(self.btnPrinceGiftNewBuff, "Sprite_princeGiftNewBuff")
  n_SpritePrinceGiftNewBuff = GBase::GetChildByName<Sprite*>(n_BtnPrinceGiftNewBuff, "Sprite_princeGiftNewBuff");
  n_SpritePrinceGiftNewBuff->setScale(0.5);
  n_BtnPrinceGiftBuff = GBase::GetChildByName<ui::Button*>(this, "Button_princeGiftBuff");
  // self.textPrinceGift = SoraDGetChildByName(self.btnPrinceGiftBuff, "Text_princeGiftBuff")
  n_TextPrinceGift = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnPrinceGiftBuff, "Text_princeGiftBuff"));
  n_SpritePrinceGiftBuff = GBase::GetChildByName<Sprite*>(n_BtnPrinceGiftBuff, "Sprite_princeGiftBuff");
  n_SpritePrinceGiftBuff->setScale(0.5);
  n_BtnSultansWelBack = GBase::GetChildByName<ui::Button*>(this, "Button_sultanWelBack");
  n_TextWelBack = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnSultansWelBack, "Text_welBack"));
  n_BtnHero = GBase::GetChildByName<ui::Button*>(this, "Button_hero");
  n_IconBtnHero = GBase::GetChildByName<ui::ImageView*>(n_BtnHero, "icon_hero");
  n_BtnItems = GBase::GetChildByName<ui::Button*>(this, "Button_items");
  n_IconBtnItems = GBase::GetChildByName<ui::ImageView*>(n_BtnItems, "icon_items");
  n_ItemNewIcon = GBase::GetChildByName<Sprite*>(n_BtnItems, "icon_new");
  n_NodeDiscountEffect = GBase::GetChildByName<Node*>(n_BtnItems, "Node_discountEffect");
  n_BtnMail = GBase::GetChildByName<ui::Button*>(this, "Button_mail");
  n_IconBtnMail = GBase::GetChildByName<ui::ImageView*>(n_BtnMail, "icon_mail");
  n_BtnAlliance = GBase::GetChildByName<ui::Button*>(this, "Button_alliance");
  n_IconBtnAlliance = GBase::GetChildByName<ui::ImageView*>(n_BtnAlliance, "icon_alliance");
  n_BtnWatchTower = GBase::GetChildByName<ui::Button*>(this, "Button_watchTower");
  n_IconAlarm = GBase::GetChildByName<Sprite*>(this, "icon_building_alarm");
  n_BtnWallBurning = GBase::GetChildByName<ui::Button*>(this, "Button_wallBurnning");
  n_BtnWallBurning->setVisible(INIT_FALSE);
  n_BtnKingdomManager = GBase::GetChildByName<ui::Button*>(this, "Button_kingdomManager");
  n_BtnKingdomManagerSprite = GBase::GetChildByName<Sprite*>(n_BtnKingdomManager, "Sprite_crown");
  n_SpKingdomManagerTimeBg = GBase::GetChildByName<Sprite*>(n_BtnKingdomManager, "Sprite_giftTimeBg");
  // self.txtKingdomManagerTime = SoraDGetChildByName(self.btnKingdomManager, "Text_giftTime")
  n_TxtKingdomManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnKingdomManager, "Text_giftTime"));
  n_BtnLegendKingManager = GBase::GetChildByName<ui::Button*>(this, "Button_legendKingManager");
  n_BtnLegendKingManagerSprite = GBase::GetChildByName<Sprite*>(n_BtnLegendKingManager, "Sprite_crown");
  n_SpLegendKingManagerTimeBg = GBase::GetChildByName<Sprite*>(n_BtnLegendKingManager, "Sprite_giftTimeBg");
  // self.txtLegendKingManagerTime = SoraDGetChildByName(self.btnLegendKingManager, "Text_giftTime")
  n_TxtLegendKingManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnLegendKingManager, "Text_giftTime"));
  n_BtnLegendInvite = GBase::GetChildByName<ui::Button*>(this, "Button_legendInvite");
  n_IconLegendInvite = GBase::GetChildByName<Sprite*>(n_BtnLegendInvite, "icon_legend_red");
  n_IconLegendInvite->setVisible(INIT_FALSE);
  // self.txtLegendInviteNum = SoraDGetChildByName(self, "Text_legendInviteNum")
  n_TxtLegendInviteNum = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(this, "Text_legendInviteNum"));
  n_BtnRadianceWar = GBase::GetChildByName<ui::Button*>(this, "Button_radiance");
  n_IconRadianceWar = GBase::GetChildByName<Sprite*>(n_BtnRadianceWar, "icon_radiance_red");
  n_IconRadianceWar->setVisible(INIT_FALSE);
  n_SpriteEffect = GBase::GetChildByName<Sprite*>(n_BtnRadianceWar, "Sprite_effect");
  n_SpriteEffect->setVisible(INIT_FALSE);
  n_TxtRadianceWarNum = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(this, "Text_radianceNum"));
  n_BtnHegemonManager = GBase::GetChildByName<ui::Button*>(this, "Button_hegemonManager");
  n_BtnHegemonManagerSprite = GBase::GetChildByName<Sprite*>(n_BtnHegemonManager, "Sprite_crown");
  n_SpHegemonManagerTimeBg = GBase::GetChildByName<Sprite*>(n_BtnHegemonManager, "Sprite_giftTimeBg");
  n_TxtHegemonManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnHegemonManager, "Text_giftTime"));
  n_BtnHegemonBattle = GBase::GetChildByName<ui::Button*>(this, "Button_hegemonBattle");
  n_BtnHegemonBattleSprite = GBase::GetChildByName<Sprite*>(n_BtnHegemonBattle, "icon_hegemon_playoff");
  n_SpHegemonBattleTimeBg = GBase::GetChildByName<Sprite*>(n_BtnHegemonBattle, "Sprite_playoffBg");
  // self.txtHegemonBattleTime = SoraDGetChildByName(self.btnHegemonBattle, "Text_playoffTime")
  n_TxtHegemonBattleTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text*>(n_BtnHegemonBattle, "Text_playoffTime"));
  n_BtnTrainPower = GBase::GetChildByName<ui::Button*>(this, "Button_trainPower");
  n_TextTrainPower = GBase::GetChildByName<ui::Text*>(n_BtnTrainPower, "Text_trainPower");
  n_TextTrainPower->setString(Translate::i18n("activity_name_9001300"));
  n_RedTrainPower = GBase::GetChildByName<Sprite*>(n_BtnTrainPower, "icon_red");
  n_NumTrainPower = GBase::GetChildByName<ui::Text*>(n_RedTrainPower, "Text_btnNum");
  n_RedTrainPower->setVisible(INIT_FALSE);
  n_TextTrainPower->setFontSize(16);
  n_BtnNeckLaceRank = GBase::GetChildByName<ui::Button*>(this, "Button_necklaceRank");
  n_BtnNeckLaceRankSprite = GBase::GetChildByName<Sprite*>(n_BtnNeckLaceRank, "icon_hegemon_playoff");
  n_BtnNeckLaceRankBg = GBase::GetChildByName<Sprite*>(n_BtnNeckLaceRank, "Sprite_playoffBg");
  n_BtnNeckLaceRankText = GBase::GetChildByName<ui::Text*>(n_BtnNeckLaceRank, "Text_playoffTime");
  // self.btnRomanSoul = SoraDGetChildByName(self, "Button_romanSoul")
  n_BtnRomanSoul = GBase::GetChildByName<ui::Button*>(this, "Button_romanSoul");
  // self.labelAllianceName = self:exchangeGroupText(SoraDGetChildByName(self, "Text_allianceName"), 25)
  n_LabelAllianceName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_allianceName"), 25);
  // self.labelAllianceName:setGroupID(mainUIDef.newGroupID.text)
  n_LabelHeroName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_heroName"), 25);
  // self.labelHeroName:setGroupID(mainUIDef.newGroupID.text)
  n_LabelBagName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_bagName"), 25);
  // self.labelBagName:setGroupID(mainUIDef.newGroupID.text)
  n_LabelMailName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(this, "Text_mailName"), 25);
  // self.labelMailName:setGroupID(mainUIDef.newGroupID.text)
  n_LabelAllianceName->setString(Translate::i18n("common_text_069"));
  n_LabelHeroName->setString(Translate::i18n("common_name_01"));
  n_LabelBagName->setString(Translate::i18n("common_text_308"));
  n_LabelMailName->setString(Translate::i18n("mail_text_25"));
  n_BtnSkill = GBase::GetChildByName<ui::Button*>(this, "Button_skill");
  n_BtnSkill->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnSkillClick, this));
  n_BtnReplay = GBase::GetChildByName<ui::Button*>(this, "Button_replay");
  n_BgTextVideo = GBase::GetChildByName<Sprite*>(this, "bg_text_video");
  n_BtnReplay->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnReplayClick, this));
  if (SDKManager::Get()->IsRecording()) {
    n_BtnReplay->setVisible(true);
    m_Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIMainBottom::RecordTimeTick, this));
  } else {
    n_BtnReplay->setVisible(INIT_FALSE);
    m_Timer = nullptr;
  }
  n_TextVideo = GBase::GetChildByName<ui::Text*>(this, "text_video");
  n_FrameMainGuide = GBase::GetChildByName<Sprite*>(this, "frame_main_guide");
  n_BtnHero->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  n_BtnItems->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  n_BtnMail->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  n_BtnAlliance->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  n_BtnWatchTower->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnWatchTowerClick, this));
  n_BtnWallBurning->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnWallBurningClick, this));
  n_BtnKingdomManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnKingdomManagerClick, this));
  n_BtnLegendKingManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnLegendKingManagerClick, this));
  n_BtnLegendInvite->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnLegendInviteClick, this));
  n_BtnRadianceWar->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnRadianceWarClick, this));
  n_BtnHegemonManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnHegemonManagerClick, this));
  n_BtnHegemonBattle->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnHegemonBattleClick, this));
  n_BtnTrainPower->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnTrainPowerClick, this));
  n_BtnRomanSoul->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnRomanSoulClick, this));
  n_BtnPyramidBattle->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPyramidBattleClick, this));
  n_BtnPyramidPlayoffs->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPyramidPlayoffsClick, this));
  n_BtnCityUnlock->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnCityUnlockClick, this));
  n_BtnNewPlayerBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnNewPlayerBuffClick, this));
  n_BtnSultansWelBack->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnSultansBackWelClick, this));
  n_BtnAccount->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnAccountClick, this));
  n_BtnNeckLaceRank->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnNeckLaceRankClick, this));
  n_BtnPrinceGiftNewBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPrinceGiftNewBuffClick, this));
  n_BtnPrinceGiftBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPrinceGiftBuffClick, this));
  InitGreenPoint();
  ShowAllianceInWarEffect();
  n_NodePreDownload = GBase::DGetExtendChildFromCCSByName<UIPreDownloadMainWidget>(this, "CCS_preDownloadMainWidget_pre");
  n_NodeBottomBtn = GBase::GetChildByName<Node*>(this, "Bottom_Node_btn");
  n_BtnManager = GBase::GetChildByName<ui::ImageView*>(this, "Bottom_Image_btnBG");
  n_BtnManager->setTouchEnabled(true);
  n_ScrollBtn = GBase::GetChildByName<ui::ScrollView*>(this, "Bottom_Size_ScrollView_btn");
  n_ScrollBtn->setTouchEnabled(false);
  auto l_ImgBtnRound = GBase::GetChildByName<ui::ImageView*>(n_BtnManager, "Image_btn_round");
  n_BtnSwitch = GBase::GetChildByName<ui::Button*>(n_BtnManager, "Button_switch");
  n_NodeArrow = GBase::GetChildByName<Node*>(n_BtnManager, "Node_arrow");
  // self.node_arrow:setGroupAuto(true)
  n_IconRed = GBase::GetChildByName<Sprite*>(n_BtnSwitch, "icon_red");
  n_IconRed->setVisible(INIT_FALSE);
  n_LabBtnNum = GBase::GetChildByName<ui::Text*>(n_BtnSwitch, "Text_btnNum");
  n_BtnSwitch->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnSwitchClick, this));
  m_BtnSwitchType = 1;
  
  n_BtnLuckyRecharge = EffectMainUITop::Get()->LuckyRecharge();
  n_ScrollBtn->addChild(n_BtnLuckyRecharge);
  n_BtnLuckyRecharge->setPosition(Vec2(35, 395));
  n_BtnLuckyRecharge->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnLuckyReachergeClick, this));
  n_BtnLuckyRecharge->setVisible(INIT_FALSE);
  UpdateBtnLuckyRecharge(nullptr);
  auto l_SourceKid = LordInfoCtrl::Get()->GetLordInfo().Base.sourceKID;
  if(l_SourceKid == 0)
    AddGoldPackageButton();
  
  auto l_MonthGift = GetMonthlyCard();
  bool l_HasGift = l_MonthGift[0];
  bool l_HasBuy = l_MonthGift[1];
  bool l_HasGot = l_MonthGift[2];
  if(l_HasGift && !l_HasBuy && !GBase::Const::Get()->IsArClient)
    AddMonthCardButton();
  
  AddCrazyTrioButton(nullptr);
  AddLostRuinsButton(nullptr);
  AddWindTowerButton(nullptr);
  AddSnowWolfLostButton(nullptr);
  UpdateCommunityButton(nullptr);
  UpdateEnjoyLotteryButton();
  AddKOChoiceButton(nullptr);
  AddSixYearActivityButton();
  AddHarvestSeasonButton(nullptr);
  AddPrinceGiftNewBuffButton(nullptr);
  AddPrinceGiftBuffButton(nullptr);
  MsgUpdateMailIconNumber(nullptr);
  CheckWatchTower(nullptr);
  CheckRomanSoul(nullptr);
  BtnKingdomManagerCheck(nullptr);
  BtnLegendKingManagerCheck(nullptr);
  BtnHegemonManagerCheck(nullptr);
  BtnTrainPowerManagerCheck();
  BtnPyramidBattleCheck(nullptr);
  BtnHegemonBattleCheck(nullptr);
  BtnCityUnlockCheck(nullptr);
  BtnNewPlayerBuffCheck(nullptr);
  BtnSultansBackWelCheck(nullptr);
  ShowLuckyBless(nullptr);
  InitAccountBind(nullptr);
  UpdateBtnContainer(nullptr);
  UpdateItemsBtn();
  UpdateBtnStatues(nullptr);
  Req4AllianceInviteData();
  // self:updateNewTrialUI()
  CreateExpostulationTimer();
  CheckRemainsWar();
  MsgInvitedInfoLegend(nullptr);
  UpdateGreenPointRadianceWar(nullptr);
  InitHelpAllBtn(nullptr);
  InitBattleOpenBtn();
  CheckPreDownload(nullptr);
  CheckPreDownloadStatus(nullptr);
  BtnPayBackCheck(nullptr);
  QuestionnaireCtrl::Get()->ReqGetQuestData();
  RaidersLostArkCtrl::Get()->InitKeyNums();
}

void UIMainBottom::CreateExpostulationTimer() {
  this->DeleteExpostulationTimer();
  // self.expostulationTimer = SoradCreateTimer(self, handler(self, self.updateExpostulation))
  m_ExpostulationTimer = GBase::DCreateTimer(this, [this](float p_DeltaTime) { UpdateExpostulation(nullptr); });
  std::unique_ptr<bool> l_IsInit(new bool(true));
  EventCustom* l_Event = new EventCustom("updateExpostulation");
  l_Event->setUserData(l_IsInit.get());
  UpdateExpostulation(l_Event);
}

void UIMainBottom::DeleteExpostulationTimer() {
  if (m_ExpostulationTimer) {
    GBase::DManagerRemoveTimer(m_ExpostulationTimer);
    m_ExpostulationTimer = nullptr;
  }
}

void UIMainBottom::InitHalloweenShineEffect() {
  
  auto l_EffectShine = GBase::DCreateAnimation("UiParts/MainUi/Node_Effect_wsj02.csb", nullptr, true);
  n_EffectShine = l_EffectShine.First;
  n_EffectShine->setPosition(Vec2(0, 65));
  n_NodeStyleTop->addChild(n_EffectShine);
  auto l_Img1 = GBase::GetChildByName<Sprite *>(n_EffectShine, "G_dh_Tex_wsj_002_01");
  auto l_Img2 = GBase::GetChildByName<Sprite *>(n_EffectShine, "G_dh_Tex_wsj_001_04");
  auto l_Particle1 = GBase::GetChildByName<ParticleSystemQuad *>(n_EffectShine, "et_dixintanxian_02_01");
  auto l_Particle2 = GBase::GetChildByName<ParticleSystemQuad *>(n_EffectShine, "et_dixintanxian_02_02");
  l_Img1->setVisible(false);
  l_Img2->setVisible(false);
  l_Particle1->setVisible(false);
  l_Particle2->setVisible(false);
}

void UIMainBottom::InitStyle() {
  auto l_Style = GGlobal::Get()->MainUIStyle;
  if(l_Style == EMainUIStyle::None)
    l_Style = EMainUIStyle::QuickSand;

  if(l_Style == EMainUIStyle::Easter){

    // auto l_TopNode = GBase::DCreateAnimation("UiParts/MainUi/Common/mainUI_style_easter.csb", nullptr).First;
    // n_NodeStyleTop->addChild(l_TopNode);
    // auto l_Spine = spine::SkeletonAnimation::createWithBinaryFile("spine/yezi.skel", "spine/yezi.atlas");
    // l_Spine->setPosition(65, 35);
    // l_Spine->setAnimation(0, "animation", true);
    // auto l_NodeSpine = GBase::GetChildByName<Node *>(l_TopNode, "Node_spine");
    // l_NodeSpine->addChild(l_Spine);

  }else if(l_Style == EMainUIStyle::Halloween){

    auto l_TopNode = GBase::DCreateAnimation("UiParts/MainUi/Common/mainUI_style_halloween.csb", nullptr).First;
    n_NodeStyleTop->addChild(l_TopNode);
    InitHalloweenShineEffect();

  }else if(l_Style == EMainUIStyle::Chritmas){

    auto l_TopNode = GBase::DCreateAnimation("UiParts/MainUi/Common/mainUI_style_chritmas.csb", nullptr).First;
    n_NodeStyleTop->addChild(l_TopNode);

  }else if(l_Style == EMainUIStyle::QuickSand){

    auto l_TopNode = GBase::DCreateAnimation("UiParts/MainUi/Common/mainUI_style_ztsz_top.csb", nullptr).First;
    n_NodeStyleTop->addChild(l_TopNode);
    auto l_BgNode = GBase::DCreateAnimation("UiParts/MainUi/Common/mainUI_style_ztsz.csb", nullptr).First;
    n_NodeStyleBg->addChild(l_BgNode);
    auto l_EffectNode = GBase::DCreateAnimation("UiParts/MainUi/Common/Node_Effect_liusha2.csb", nullptr).First;
    l_EffectNode->setPosition(320, 30);
    n_NodeAreaB->addChild(l_EffectNode, 999);
    l_EffectNode->setName("actNode_style");

  }

}

void UIMainBottom::InitGroup() {
  auto l_Node = GDisplay::NewNode();
  this->addChild(l_Node);
  l_Node->setLocalZOrder(5);
  //   node:setGroupID(mainUIDef.newGroupID.text, true)
  l_Node->setName("Node_group_text");
}

Label* UIMainBottom::ExchangeGroupText(ui::Text* p_Text, float p_Height) {
  
  auto l_CreateLabelParam = GBase::RCreateLabelParm();
  //l_CreateLabelParam.UILabelType = 2;
  l_CreateLabelParam.Txt = "";
  l_CreateLabelParam.fontSize = p_Text->getFontSize();
  l_CreateLabelParam.Color = Color4B(p_Text->getTextColor());
  l_CreateLabelParam.Dimensions = Size(200, p_Height || 30);
  l_CreateLabelParam.hAlignment = TextHAlignment::CENTER;
  l_CreateLabelParam.vAlignment = TextVAlignment::CENTER;

  auto l_Text = GBase::DCreateLabel(l_CreateLabelParam);
  l_Text->setAnchorPoint(p_Text->getAnchorPoint());
  l_Text->setPosition(p_Text->getPosition());
  p_Text->getParent()->addChild(l_Text);
  p_Text->removeFromParent();
  return l_Text;
}

void UIMainBottom::InitAccountBind(EventCustom* p_Event) {
  auto l_IsBind = SDKManager::Get()->ReturnAccountBindType(ESdkPlatformType::Email);
  auto l_IsPhoneBind = SDKManager::Get()->ReturnAccountBindType(ESdkPlatformType::Mobile);

  auto l_LordBase = LordInfoCtrl::Get()->GetBaseInfo();
  auto l_IsReward = l_LordBase.bHasBindAccountReward;
  auto l_IsBindPhone = !l_LordBase.bReceiveBindPhone;
  auto l_Ret = false;
  auto l_CastleLv = GBase::DGetCastleLv();
  if (GBase::Const::Get()->IsArClient) {
    if (m_ViewChangeType == EScene::City && (l_CastleLv >= GBase::Const::Get()->CastleLvl6 && (!l_IsBind || l_IsBind && !l_IsReward) ||
                                            l_CastleLv >= GBase::Const::Get()->CastleLvl10 && (!l_IsPhoneBind || l_IsPhoneBind && !l_IsBindPhone))) {
      l_Ret = true;
    } else {
      l_Ret = false;
    }
  } else if (m_ViewChangeType == EScene::City && l_CastleLv >= GBase::Const::Get()->CastleLvl6 && (!l_IsBind || l_IsBind && !l_IsReward)) {
    l_Ret = true;
  } else {
    l_Ret = false;
  }

  auto l_IsSettingHide = GBase::DConfigGet<bool>("Game:GameOptionsView:bindPhoneShow~bool", true);
  n_BtnAccount->setVisible(l_Ret && !l_IsSettingHide && !WorldMapDefine::Get()->IsInWar());
  if (GBase::Const::Get()->IsArClient) {
    auto l_IconSpriteName =
            l_CastleLv >= GBase::Const::Get()->CastleLvl10 && l_IsBind && l_IsReward ? "icon_bind_phone.png" : "icon_main_set_account_new.png";
    n_IconAccount->setSpriteFrame(l_IconSpriteName);
    n_RedPointAccount->setVisible(l_IsBind && !l_IsReward || l_IsPhoneBind && !l_IsBindPhone);
  } else {
    n_IconAccount->setSpriteFrame("icon_main_set_account_new.png");
    n_RedPointAccount->setVisible(l_IsBind && !l_IsReward);
  }

  SortBottomQuestBtns(nullptr);
}

void UIMainBottom::InitGreenPoint() {

  auto l_HasChallangeTimes = AllianceHuntCtrl::Get()->GetCheckChanllengeTimes();
  auto l_AllianceCount = KingdomMapCtrl::Get()->GetHallWarCount();
  auto l_CounterSysCount = AllianceCounterSysCtrl::Get()->GetNewPoint();
  l_AllianceCount += GuildHelp::Get()->GetHelpList().OtherHelpList.size();
  if(AllianceRead::Get()->CheckRank(EAllianceRank::R4)) {
    l_AllianceCount += AllianceRelationCtrl::Get()->GetAllyInviteNum();
  }

  auto l_MineNum = AllianceTreasureCtrl::Get()->GetDigRewardCount();
  auto l_HelpNum = AllianceTreasureCtrl::Get()->GetHelpRewardCount();
  auto l_HasActived = PlayerMobilizationCtrl::Get()->IsHaveActived();
  auto l_ActiveNum =  0; 
  if(AllianceManager::Get()->HasJoinAlliance()) 
    AllianceActiveCtrl::Get()->GetCanReceiveTaskNum();
  l_AllianceCount += l_MineNum + l_HelpNum + l_HasActived + l_HasChallangeTimes + l_CounterSysCount + l_ActiveNum;
  auto l_RewardsCount = AllianceScience::Get()->GetProsperityRewardsCount();
  l_AllianceCount += l_RewardsCount > 0 ? 1 : 0;
  l_AllianceCount += AllianceGuideCtrl::Get()->IsShowEnterPoint() ? 1 : 0;
  if(WorldMapDefine::Get()->IsInAtlantis()) {
    l_AllianceCount = KingdomMapCtrl::Get()->GetHallWarCount();
  }

  auto l_MainCount = MailManger::Get()->GetNewMailNum();
  auto l_ItemsCount = 0;
  auto l_HeroPointNum = HeroCtrl::Get()->GetHeroBottomPointNum();

  RGreenTipsCount l_GreenTipCount;
  l_GreenTipCount.alliance = l_AllianceCount;
  l_GreenTipCount.items = l_ItemsCount;
  l_GreenTipCount.mail = l_MainCount;
  l_GreenTipCount.hero = l_HeroPointNum;
  UpdateGreenTip(&l_GreenTipCount);

  if(
    !WorldMapDefine::Get()->InInCrossWar() 
    && AllianceMemberManager::Get()->GetOwnMember().bIsFirstJoin
    && !AllianceManager::Get()->HasJoinAlliance()) {
    AddFirstJoinAllianceAnimation();
  }
}

void UIMainBottom::OnMessageListener() {
  using namespace std::placeholders;
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", std::bind(&UIMainBottom::ReLoginFinish, this, _1));
  GBase::DAddMessage(this, "MESSAGE_CHAT_OPEN_UI_ALLIANCE", std::bind(&UIMainBottom::OpenUIAlliance, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_ONSHOW", std::bind(&UIMainBottom::CurrentShowViewType, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", std::bind(&UIMainBottom::ShowOrHideGuideView, this, _1));
  GBase::DAddMessage(this, "MESSAGE_REQ_NEW_PRINCE_GIFT_BUY_PACKAGE", std::bind(&UIMainBottom::AddPrinceGiftNewBuffButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_GUIDE_BUFF_REFRESH", std::bind(&UIMainBottom::ShowPrinceGiftGuideView, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_GUIDE_REFRESH", std::bind(&UIMainBottom::AddPrinceGiftBuffButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_INIT", std::bind(&UIMainBottom::AddPrinceGiftBuffButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SINBAD_TREASURE_UPDATE_LV_POP_WINDOW", std::bind(&UIMainBottom::ShowSinbadPopWindow, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_ADDINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_REMOVEINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_EDITINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_CLIENT_WATCHTOWER_INGORECONTROL", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_REFRESHALL", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_WAR_SETTING", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_ADDINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_EDITINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_REMOVEINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_ROMANSOUL_ALLIANCEATTACK", std::bind(&UIMainBottom::CheckRomanSoul, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_MAINUIICONCHECK", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_GROUP_UPDATE", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_BE_KICKED", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_QUIT_SUCCESS", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", std::bind(&UIMainBottom::GreenPointUpdate, this, _1));
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE_BYTYPE", std::bind(&UIMainBottom::GreenPointUpdateByType, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_MEMBER_UPDATE", std::bind(&UIMainBottom::GreenPointUpdate, this, _1));
  GBase::DAddMessage(this, "MESSAGE_WALLS_NOTIFY_SUCCESS", std::bind(&UIMainBottom::CheckWallDefend, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_JOIN_SUCCESS", std::bind(&UIMainBottom::RemovefirstJoinAllianceAnimation, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMUSR_CHANGED", std::bind(&UIMainBottom::BtnKingdomManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMALLIANCE_GIFT", std::bind(&UIMainBottom::BtnKingdomManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_CLEAN", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_AP_LT", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_TITLE_INFO_BACK", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_CLEAN", std::bind(&UIMainBottom::MsgHegemonClean, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_AP_LT", std::bind(&UIMainBottom::BtnHegemonManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_TITLE_INFO_BACK", std::bind(&UIMainBottom::BtnHegemonManagerCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_UPDATE_MAINUI_HEGEMON", std::bind(&UIMainBottom::BtnHegemonBattleCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", std::bind(&UIMainBottom::BtnCityUnlockCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_NEWPLAYER_BUFF_END", std::bind(&UIMainBottom::BtnNewPlayerBuffCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SULTANSBACK_WELCOME_REFRESH", std::bind(&UIMainBottom::BtnSultansBackWelCheck, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAIN_RECORD_SCREEN", std::bind(&UIMainBottom::StartRecordScreen, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAIN_STOP_RECORD_SCREEN", std::bind(&UIMainBottom::StopRecording, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKY_DAY_UPDATE", std::bind(&UIMainBottom::UpdateEventcenter, this, _1));
  GBase::DAddMessage(this, "MESSAGE_WALLS_DEFENCE_DESTROY", std::bind(&UIMainBottom::DefineWallDestroy, this, _1));
  GBase::DAddMessage(this, "MESSAGE_WALLS_DEFENCE_DESTROY_RECOVER", std::bind(&UIMainBottom::DefineWallDestroyRecover, this, _1));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_BIND_AWARD", std::bind(&UIMainBottom::InitAccountBind, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAIN_BTN_UPDATE", std::bind(&UIMainBottom::UpdateBtnContainer, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAIN_BTN_UPDATE_TEST", std::bind(&UIMainBottom::UpdateBtnContainer, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MONTHLY_CARD_REFRESH_BACK", std::bind(&UIMainBottom::UpdateMonthCardButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", std::bind(&UIMainBottom::GetEventCenterReturn, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_MAINUIINVITE_REFRESH", std::bind(&UIMainBottom::InitAllianceInvitePop, this, _1));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_BY_UID", std::bind(&UIMainBottom::ServerMessageGetLordInfo, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_REQ_INFO_BACK", std::bind(&UIMainBottom::ServerMessageGetAllianceInfo, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_START_BY_STEP", std::bind(&UIMainBottom::RecevieGuideMsg, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ITEM_CHANGE_TYPE", std::bind(&UIMainBottom::RecevieItemChangeMsg, this, _1));
  GBase::DAddMessage(this, "MESSAGE_UI_EXPOSTULATION_UPDATE", std::bind(&UIMainBottom::UpdateExpostulation, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", std::bind(&UIMainBottom::ShowLuckyBless, this, _1));
  GBase::DAddMessage(this, "MESSAGE_GOLD_PACKAGE_STATE", std::bind(&UIMainBottom::UpdateGoldPackageButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_LUCKY_RECHARGE_REFRESH", std::bind(&UIMainBottom::UpdateBtnLuckyRecharge, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_GET_ALLIANCE_HELP_LIST_SUCCESS", std::bind(&UIMainBottom::InitHelpAllBtn, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGEND_TEAM_INVITED_INFO", std::bind(&UIMainBottom::MsgInvitedInfoLegend, this, _1));
  GBase::DAddMessage(this, "MESSAGE_ITEM_LIMITITEM_TIMEOUT_BACK", std::bind(&UIMainBottom::UpdateShopNewTag, this, _1));
  GBase::DAddMessage(this, "MESSAGE_QUESTIONNAIRE_REFRESH", std::bind(&UIMainBottom::UpdateQuestionnaireButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_UI_EVENTCENTER_REFRESHISNEW", std::bind(&UIMainBottom::UpdateCommunityButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RADIANCE_WAR_WARNING", std::bind(&UIMainBottom::UpdateGreenPointRadianceWar, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RADIANCE_WAR_LONGTIMEUNLOGIN", std::bind(&UIMainBottom::ShowLongTimeUnlogin, this, _1));
  GBase::DAddMessage(this, "MESSAGE_KOCHOICE_REFRESH", std::bind(&UIMainBottom::AddKOChoiceButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH", std::bind(&UIMainBottom::RefreshTrainPower, this, _1));
  GBase::DAddMessage(this, "MESSAGE_LOST_RUINS_REFRESH", std::bind(&UIMainBottom::AddLostRuinsButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_WIND_TOWER_REFRESH", std::bind(&UIMainBottom::AddWindTowerButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SNOWWOLF_LOST_REFRESH", std::bind(&UIMainBottom::AddSnowWolfLostButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN", std::bind(&UIMainBottom::UpdateCrazyTrioButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_RELASH", std::bind(&UIMainBottom::AddCrazyTrioButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPGRADE_LEVEL", std::bind(&UIMainBottom::UpdateBtnStatues, this, _1));
  GBase::DAddMessage(this, "MESSAGE_MAINUIBOTTOM_SORTBOTTOMQUESTBTNS", std::bind(&UIMainBottom::SortBottomQuestBtns, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_MAIL_REQ_BATTLE_REPORT_BACK", std::bind(&UIMainBottom::OpenReportMail, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_MAIL_REQ_SINGLE_MAIL_BACK_REPORT", std::bind(&UIMainBottom::OpenReportMail, this, _1));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", std::bind(&UIMainBottom::AddHarvestSeasonButton, this, _1));
  GBase::DAddMessage(this, "MESSAGE_HARVEST_SEASON_REDPOINT", [this](EventCustom*) {
    if (n_BtnHarvestSeason) {
      // self.btnHarvestSeason.redIcon:setVisible(false)
    }
  });
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_REFRESH", std::bind(&UIMainBottom::CheckPreDownloadStatus, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_REFRESH_DOWNLOAD", std::bind(&UIMainBottom::CheckPreDownload, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_GAME_DOWNSUC", std::bind(&UIMainBottom::OnPreDownloadSuc, this, _1));
  GBase::DAddMessage(this, "MESSAGE_PAYBACK_NOTICE", std::bind(&UIMainBottom::BtnPayBackCheck, this, _1));
}

void UIMainBottom::ShowOrHideGuideView(EventCustom* p_Event) {
  // local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  // local guideStep = guideCtrl:getCurForceGuideStep()
  // self.nodeQuestGuide:setVisible(false)
  // self.Node_area_rb:setVisible(false)
  // self.frame_main_guide:setVisible(false)
  // if guideStep then
  //   self.nodeQuestGuide:setVisible(guideStep >= 2011)
  //   self.Node_area_rb:setVisible(guideStep >= 2024)
  //   self.frame_main_guide:setVisible(guideStep < 2024)
  // else
  //   self.Node_area_rb:setVisible(true)
  //   self.nodeQuestGuide:setVisible(self.viewChangeType == VIEW_TYPE_CITY)
  //   self.frame_main_guide:setVisible(false)
  // end
}

void UIMainBottom::ShowPrinceGiftGuideView(EventCustom* p_Event) {
  CityBuildingFunc::Get()->CheckPopUnlockPrinceGift();
}

void UIMainBottom::ShowSinbadPopWindow(EventCustom* p_Event) {
  CityBuildingFunc::Get()->CheckPopUpSinbadTreasure();
}

void UIMainBottom::ReLoginFinish(EventCustom* p_Event) {
  
  n_ChatMainUIView->InitWithData();
  InitGreenPoint();
  CheckWatchTower(nullptr);
  KingdomMapCtrl::Get()->ReLoginFinish();
  BtnNeckLaceRankCheck(nullptr);
  CheckWallDefend(nullptr);
  CheckRomanSoul(nullptr);
  BtnKingdomManagerCheck(nullptr);
  BtnPyramidBattleCheck(nullptr);
  ShowLuckyBless(nullptr);
  InitAccountBind(nullptr);
  Req4AllianceInviteData();
  // self.updateAllianceGreen = nil
  CreateExpostulationTimer();
  CheckRemainsWar();
  MsgInvitedInfoLegend(nullptr);
  UpdateGreenPointRadianceWar(nullptr);
  InitHelpAllBtn(nullptr);
  BtnLegendKingManagerCheck(nullptr);
  BtnHegemonBattleCheck(nullptr);
  BtnHegemonManagerCheck(nullptr);
  BtnTrainPowerManagerCheck();
  InitBattleOpenBtn();
  CheckPreDownload(nullptr);
  CheckPreDownloadStatus(nullptr);
  AddPrinceGiftNewBuffButton(nullptr);
  AddPrinceGiftBuffButton(nullptr);
  BtnNewPlayerBuffCheck(nullptr);
  AddHarvestSeasonButton(nullptr);
  CityBuildingFunc::Get()->CheckPopUpWindow();
}

void UIMainBottom::UpdateEventcenter(EventCustom* p_Event) { 
  ShowLuckyBless(p_Event); 
}

void UIMainBottom::ServerMessageGetLordInfo(EventCustom* p_Event) {
  if(!p_Event) return;
  if(!p_Event->getUserData()) return;
  auto l_Data = static_cast<RShowLordInfoEvtArg *>(p_Event->getUserData());
  auto l_TargetName = l_Data->ClientData.TargetName;
  if(l_TargetName == "AllianceInvitePop" || l_TargetName == "atlantisMemberSingle") {
    auto l_InfoView = UILordView::Create();
    l_InfoView->InitData(l_Data->Lord);
    l_InfoView->Show();
  }
}

void UIMainBottom::UpdateExpostulation(EventCustom* p_Event) {
  static GTime GLOBAL_EXPOSTULATION_TIME =  0;
  static GTime EXPOSTULATION_INTERVAL =  20;
  if(p_Event != nullptr){
    auto l_IsUnit = static_cast<bool *>(p_Event->getUserData());
    if(l_IsUnit){
      GLOBAL_EXPOSTULATION_TIME = 0;
    }
  }
  GLOBAL_EXPOSTULATION_TIME += 1;
  if(GLOBAL_EXPOSTULATION_TIME == EXPOSTULATION_INTERVAL) {
    GLOBAL_EXPOSTULATION_TIME = 0;
    auto l_ExpostulationData = ExpostulationLogic::Get()->GetExpostulation();
    // if(l_ExpostulationData) {
    //   m_NodeQuestGuide->ChangeToExpostulation(l_ExpostulationData);
    // } else if(m_NodeQuestGuide->ExData) {
    //   m_NodeQuestGuide->InitData();
    // }
  }
}

void UIMainBottom::RecevieGuideMsg(EventCustom* p_Event) {
  auto l_AllianceInvitePop = this->getChildByName("Panel_AllianceInvitePop");
  if(l_AllianceInvitePop) {
    l_AllianceInvitePop->removeFromParent();
  }
}

void UIMainBottom::ServerMessageGetAllianceInfo(EventCustom* p_Event) {
  if(!p_Event) return;
  if(!p_Event->getUserData()) return;
  auto l_Data = static_cast<RShowAllianceInfoEvtArg *>(p_Event->getUserData());
  if(l_Data->ClientData.From == "AllianceInvitePop") {
    auto l_InfoView = UIAllianceInfoView::Create();
    l_InfoView->InitData(l_Data->Alliance, l_Data->Alliance.Property.SourceKID);
    l_InfoView->Show();
  }
}

void UIMainBottom::Req4AllianceInviteData() {
  AllianceCtrl::Get()->Req4AllianceInviteData();
}

void UIMainBottom::InitAllianceInvitePop(EventCustom* p_Event) {
  // local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  // local allianceCtrl = gametop.playertop_:getModule("allianceCtrl")
  // local function createBoard(...)
  //   local panel = SoraDCreateCSBNode("allianceInvitePop")
  //   panel:getChildByName("Button_green"):setTitleText(i18n("common_text_140"))
  //   panel:getChildByName("Text_msg"):setString(i18n("common_text_4331"))
  //   panel:getChildByName("Button_close"):addTouchEventListener(function(button, eventType)
  //     if eventType == ccui.TouchEventType.ended then
  //       SoraDPlaySound()
  //       local popPanel = self:getChildByName("Panel_AllianceInvitePop")
  //       if popPanel then
  //         popPanel:removeFromParent()
  //         popPanel = nil
  //       end
  //       allianceCtrl:resetAllianceInvitePopInfo()
  //     end
  //   end)
  //   panel:setPosition(self.btnAlliance:getPositionX(), self.btnAlliance:getPositionY())
  //   panel:setLocalZOrder(99)
  //   panel:setName("Panel_AllianceInvitePop")
  //   panel:addTo(self)
  //   return panel
  // end
  // local function fillPanel(ocx, info)
  //   dump(info, "info=============")
  //   local showName = i18n("common_text_186", {
  //     abbr = info.allianceName,
  //     name = info.leadername
  //   })
  //   ocx:getChildByName("Text_lordName"):setString(showName)
  //   ocx:getChildByName("Text_lordName"):setTouchEnabled(true)
  //   ocx:getChildByName("Text_lordName"):addTouchEventListener(function(button, eventType)
  //     if eventType == ccui.TouchEventType.ended then
  //       print("Text_lordName")
  //       SoraDPlaySound()
  //       local gametop = gModuleMgr.getObject("gametop")
  //       local kid = gametop.playertop_:getKingdomID()
  //       local allianceQuery = gametop.playertop_:getModule("allianceQuery")
  //       allianceQuery:reqAllianceInfo(kid, info.aid, {
  //         from = "AllianceInvitePop"
  //       })
  //     end
  //   end)
  //   SoraDGetHeadFromManager(ocx:getChildByName("Image_kingHead"), info.iconID, info.avatar)
  //   ocx:getChildByName("Image_kingHead"):setTouchEnabled(true)
  //   ocx:getChildByName("Image_kingHead"):addTouchEventListener(function(button, eventType)
  //     if eventType == ccui.TouchEventType.ended then
  //       print("Image_kingHead")
  //       dump(info, "info")
  //       SoraDPlaySound()
  //       local gametop = gModuleMgr.getObject("gametop")
  //       local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  //       local playerID = info.leaderid
  //       local kid = gametop.playertop_:getKingdomID()
  //       lordInfoCtrl:getLordInfoByUid(playerID, kid, {
  //         targetName = "AllianceInvitePop"
  //       })
  //     end
  //   end)
  //   ocx:getChildByName("Button_green"):addTouchEventListener(function(button, eventType)
  //     if eventType == ccui.TouchEventType.ended then
  //       SoraDPlaySound()
  //       local panel = self:getChildByName("Panel_AllianceInvitePop")
  //       if panel then
  //         panel:removeFromParent()
  //         panel = nil
  //       end
  //       allianceMgr:reqAgreeInviteJoin(info.aid, info.leaderid)
  //     end
  //   end)
  // end
  // local allianceInviteData = allianceCtrl:getAllianceInvitePopInfo()
  // if not worldMapDefine.inInCrossWar() and not allianceMgr:hasJoinAlliance() and next(allianceInviteData) and SoraDIsGameGuide() == nil then
  //   local panel = self:getChildByName("Panel_AllianceInvitePop") and self:getChildByName("Panel_AllianceInvitePop") or createBoard()
  //   panel:setVisible(true)
  //   fillPanel(panel, allianceInviteData)
  // elseif self:getChildByName("Panel_AllianceInvitePop") then
  //   self:getChildByName("Panel_AllianceInvitePop"):setVisible(false)
  // end
}

GVector<bool> UIMainBottom::GetMonthlyCard() {
  // local gametop = gModuleMgr.getObject("gametop")
  // local rechargeActivityCtrl = gametop.playertop_:getModule("rechargeActivityCtrl")
  // local monthData = rechargeActivityCtrl:getMonthActivityList()
  // local weeklyData = rechargeActivityCtrl:getWeekActivityList()
  // local takeData = rechargeActivityCtrl:getTakeActivityList()
  // local hasGift = false
  // local hasBuy = false
  // local hasGot = false
  // if next(monthData) or next(weeklyData) or next(takeData) then
  //   hasGift = true
  // end
  // if takeData and next(takeData) then
  //   if takeData.isbuy then
  //     hasBuy = true
  //   end
  //   if takeData.isbuy and takeData.isdayget then
  //     hasGot = true
  //   end
  // end
  // if weeklyData and next(weeklyData) then
  //   for k, v in pairs(weeklyData) do
  //     if v.isbuy then
  //       hasBuy = true
  //     end
  //     if v.isbuy and v.isdayget then
  //       hasGot = true
  //     end
  //   end
  // end
  // if monthData and next(monthData) then
  //   for k, v in pairs(monthData) do
  //     if v.isbuy then
  //       hasBuy = true
  //     end
  //     if v.isbuy and v.isdayget then
  //       hasGot = true
  //     end
  //   end
  // end
  // return hasGift, hasBuy, hasGot
  return {false, false, false};
}

void UIMainBottom::AddQuestionnaireButton(int32 p_Num) {
  
  n_BtnQuestionnaire = EffectMainUITop::Get()->Questionnaire(p_Num);
  n_ScrollBtn->addChild(n_BtnQuestionnaire);
  n_BtnQuestionnaire->setPosition(Vec2(35, 395));
  n_BtnQuestionnaire->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnQuestionnaireClick, this));
  UpdateBtnContainer(nullptr);

}

void UIMainBottom::UpdateQuestionnaireButton(EventCustom* p_Event) {

  if(n_BtnQuestionnaire) {
    n_BtnQuestionnaire->removeFromParent();
    n_BtnQuestionnaire = nullptr;
  }

  auto l_Num = QuestionnaireCtrl::Get()->GetReceiveStatusAndNum();
  if(l_Num > 0 && !WorldMapDefine::Get()->InInCrossWar()) {
    GBase::DCreateTimerEx(this, [](float p_Delta){
      QuestionnaireCtrl::Get()->ReqGetQuestData();
    }, 1800);
    AddQuestionnaireButton(l_Num);
  }
  UpdateBtnContainer(nullptr);
}

void UIMainBottom::AddLostRuinsButton(EventCustom* p_Event) {
  if(n_BtnLostRuins) {
    n_BtnLostRuins->removeFromParent();
    n_BtnLostRuins = nullptr;
  }
  // local recordList = lostRuinsCtrl:getRecordList()
  if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::LostRuinsActivity)/*and next(recordList) */)
  {
    auto l_Num = LostRuinsCtrl::Get()->GetNewSurveyNum();
    n_BtnLostRuins = EffectMainUITop::Get()->CreateLostRuinsBtn(l_Num);
    n_ScrollBtn->addChild(n_BtnLostRuins);
    n_BtnLostRuins->setPosition(Vec2(35, 395));
    n_BtnLostRuins->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnLostRuinsClick, this));
  }
  UpdateBtnContainer(nullptr);
}

void UIMainBottom::AddWindTowerButton(EventCustom* p_Event) {

  if(n_BtnWindTower){
    n_BtnWindTower->removeFromParent();
    n_BtnWindTower = nullptr;
  }

  auto l_IsConWar = WorldMapDefine::Get()->IsInKingdomBattle();
  if(!l_IsConWar){
    //   local recordList = windTowerCtrl:getRecordList()
    if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::WindTowerActivity)/*and next(recordList) */){
      auto l_Num = WindTowerCtrl::Get()->GetNewSurveyNum();
      n_BtnWindTower = EffectMainUITop::Get()->CreateWindTowerBtn(l_Num);
      n_ScrollBtn->addChild(n_BtnWindTower);
      n_BtnWindTower->setPosition(Vec2(35, 395));
      n_BtnWindTower->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnWindTowerClick, this));
    }
  }
  UpdateBtnContainer(nullptr);

}

void UIMainBottom::AddSnowWolfLostButton(EventCustom* p_Event) {

  if(n_BtnSnowWolfLost){
    n_BtnSnowWolfLost->removeFromParent();
    n_BtnSnowWolfLost = nullptr;
  }

  auto l_IsConWar = WorldMapDefine::Get()->IsInKingdomBattle();
  if(!l_IsConWar){
    //   local recordList = snowWolfLostCtrl:getRecordList()
    if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::SnowWolfLostActivity)/*and #recordList > 0 */)
    {
      auto l_Num = SnowWolfLostCtrl::Get()->GetNewSurveyNum();
      n_BtnSnowWolfLost = EffectMainUITop::Get()->CreateSnowWolfLostBtn(l_Num);
      n_ScrollBtn->addChild(n_BtnSnowWolfLost);
      n_BtnSnowWolfLost->setPosition(Vec2(35, 395));
      n_BtnSnowWolfLost->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnSnowWolfLostClick, this));
    }
  }

  UpdateBtnContainer(nullptr);
}

void UIMainBottom::UpdateCrazyTrioButton(EventCustom* p_Event) {
  if(!p_Event) 
    return;
  if(!p_Event->getUserData())
    return;

  auto l_DataMsg = *static_cast<GString *>(p_Event->getUserData());
  if(l_DataMsg == "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN"){
    if(m_BtnSwitchType == -1){
      m_BtnSwitchType = 1;
      SwitchBottonBtn();
      auto l_Seq = Sequence::create(
        DelayTime::create(0.33f), 
        CallFunc::create([this](){
          AddCrazyTrioButton(nullptr);
        }), nullptr);
      runAction(l_Seq);
    }else{
      AddCrazyTrioButton(nullptr);
    }
  }
}

void UIMainBottom::AddCrazyTrioButton(EventCustom* p_Event) {

  if(n_BtnCrazyTrio) {
    n_BtnCrazyTrio->removeFromParent();
    n_BtnCrazyTrio = nullptr;
  }
  // local cumuActiveCtrl = gametop.playertop_:getModule("cumuActiveCtrl")
  // local rechargeltCtrl = include("rechargeltCtrl")
  // local crazyData = cumuActiveCtrl:getCrazyTrioData()
  // local receiveNum = table.nums(crazyData.receive)
  // if cumuActiveCtrl:getActivityID() ~= gActivityTimeActivityID.CRAZY_TRIO_ACTIVITY and receiveNum >= 2 then
  //   SoraDConfigSet("Game:eventCrazyTrioNew:isShowInDown~bool", true, {byUID = true})
  // end
  // if clientEventMgr.judgeIsOpen(cumuActiveCtrl:getActivityID(), false) then
      auto l_IsShow = GBase::DConfigGet<bool>("Game:eventCrazyTrioNew:isShowInDown~bool", true);
      if(l_IsShow /**and receiveNum < rechargeltCtrl.getRechargeTotalConfigNum()*/){
        auto l_Num = 0;    //     local _, num = cumuActiveCtrl:getInitialReceiveState()
        n_BtnCrazyTrio = EffectMainUITop::Get()->CreateCrazyTrioBtn(0);
        n_ScrollBtn->addChild(n_BtnCrazyTrio);
        n_BtnCrazyTrio->setPosition(Vec2(35, 395));
        n_BtnCrazyTrio->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnCrazyTrioClick, this));
      }
  // end

  UpdateBtnContainer(nullptr);
}

void UIMainBottom::AddCommunityButton(RActivityShowData p_Info) {
  
  n_BtnCommunity = EffectMainUITop::Get()->CommunityCenter(p_Info);
  n_ScrollBtn->addChild(n_BtnCommunity);
  n_BtnCommunity->setPosition(Vec2(35, 395));
  n_BtnCommunity->addTouchEventListener([this, p_Info](Ref* p_Sender, Widget::TouchEventType p_Type){
    OnCommunityClick(p_Sender, p_Type, p_Info);
  });
}

void UIMainBottom::UpdateCommunityButton(EventCustom* p_Event) {
  if(n_BtnCommunity){
    n_BtnCommunity->removeFromParent();
    n_BtnCommunity = nullptr;
  }

  auto l_CommunityInfo = ActivityShowCtrl::Get()->GetCommunityInfo(EActivityTime::CommunityCenterMainUI);
  if(l_CommunityInfo.Param.Show != 0){
    if(l_CommunityInfo.Param.Type == 1){
      AddCommunityButton(l_CommunityInfo);
    }else if(l_CommunityInfo.Param.Type == 0 /*&& ActivityCenterUICtrl::Get()->IsHaveNewFlag(EActivityTime::CommunityCenterMainUI)*/){
      AddCommunityButton(l_CommunityInfo);
    }
  }
  UpdateBtnContainer(nullptr);
}

void UIMainBottom::AddMonthCardButton() {
  n_BtnMonthCard = EffectMainUITop::Get()->MonthOrWeeklyCard();
  n_ScrollBtn->addChild(n_BtnMonthCard);
  n_BtnMonthCard->setPosition(Vec2(35, 395));
  n_BtnMonthCard->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnMonthCardClick, this));
  UpdateBtnContainer(nullptr);
}

void UIMainBottom::UpdateMonthCardButton(EventCustom* p_Event) {

  auto l_Temp = GetMonthlyCard();
  bool l_HasGift = l_Temp.size() > 0 ? l_Temp[0] : false;
  bool l_HasBuy = l_Temp.size() > 1 ? l_Temp[1] : false;
  bool l_HasGot = l_Temp.size() > 2 ? l_Temp[2] : false;
  
  if(!n_BtnMonthCard && l_HasGift && !l_HasBuy && !GBase::Const::Get()->IsArClient){
    AddMonthCardButton();
  }
  if(n_BtnMonthCard){
    if(l_HasGift){
      if(l_HasBuy){
        n_BtnMonthCard->setVisible(false);
        UpdateBtnContainer(nullptr);
      }else{
        n_BtnMonthCard->setVisible(true);
        UpdateBtnContainer(nullptr);
      }
    }else{
      n_BtnMonthCard->setVisible(false);
      UpdateBtnContainer(nullptr);
    }
  }

}

void UIMainBottom::OnMonthCardClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_Panel = UIRechargeMonthlyFrame::Create(); 
    l_Panel->Show();
  }
}

void UIMainBottom::OnCommunityClick(Ref* p_Sender, Widget::TouchEventType p_Type, RActivityShowData p_Info) {

  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    GMap<EActivityCenter, GString> l_LocalUrl = {
      {EActivityCenter::CommunityCenter_1, "https://www.facebook.com/slateen/"},
      {EActivityCenter::CommunityCenter_2, "https://www.instagram.com/revengeofsultans/"},
      {EActivityCenter::CommunityCenter_3, "https://twitter.com/EntkamElSlaten"}
    };
    
    if(p_Info.Param.Url != ""){
      //     userSDKManager.openSDKLink(info.url)
    }else if(static_cast<EActivityCenter>(p_Info.Param.Show) == EActivityCenter::CommunityCenter_4 || static_cast<EActivityCenter>(p_Info.Param.Show) == EActivityCenter::CommunityCenter_5){
      //     userSDKManager.showSocial()
    }else{
      //     userSDKManager.openSDKLink(localUrl[info.show])
    }
    //   local activityCenterUICtrl = SoraDGetCtrl("activityCenterUICtrl")
    //   activityCenterUICtrl:sendClearNewMsg(gActivityTimeActivityID.COMMUNITY_CENTER_MAIN_UI)
  }
}

void UIMainBottom::OnLostRuinsClick(Ref* p_Sender, Widget::TouchEventType p_Type) {

  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_Tag = dynamic_cast<Widget *>(p_Sender)->getTag();
    auto l_FingerNode = dynamic_cast<Widget *>(p_Sender)->getChildByName("fingerNode");
    if(l_FingerNode){
      l_FingerNode->setVisible(false);
      l_FingerNode->stopAllActions();
      l_FingerNode->removeFromParent();
    }
    auto l_Panel = UILostRuinsRecordView::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::OnWindTowerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_FingerNode = dynamic_cast<Widget *>(p_Sender)->getChildByName("fingerNode");
    if(l_FingerNode){
      l_FingerNode->setVisible(false);
      l_FingerNode->stopAllActions();
      l_FingerNode->removeFromParent();
    }
    auto l_Panel = UIWindTowerHistoryView::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::OnSnowWolfLostClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_FingerNode = dynamic_cast<Widget *>(p_Sender)->getChildByName("fingerNode");
    if(l_FingerNode){
      l_FingerNode->setVisible(false);
      l_FingerNode->stopAllActions();
      l_FingerNode->removeFromParent();
    }
    auto l_Panel = UISnowWolfRecord::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::OnCrazyTrioClick(Ref* p_Sender, Widget::TouchEventType p_Type) {

  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_FingerNode = dynamic_cast<Widget *>(p_Sender)->getChildByName("fingerNode");
    if(l_FingerNode){
      l_FingerNode->setVisible(false);
      l_FingerNode->stopAllActions();
      l_FingerNode->removeFromParent();
    }
    //   local cumuActiveCtrl = SoraDGetCtrl("cumuActiveCtrl")
    //   local activityID = cumuActiveCtrl:getActivityID()
    //   if clientEventMgr.judgeIsOpen(activityID, false) then
    //     userSDKManager.logEvent(gSDKDef.TDonEvent.click_crazy_trio, {eventid = activityID, position = 2})
    //     clientEventMgr.singleClickEvent(activityID, 3)
    //   end
  }

}

void UIMainBottom::OnQuestionnaireClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_Panel = UIQuestionnaireView::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::UpdateEnjoyLotteryButton() {
  if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::EnjoyLottery) && !WorldMapDefine::Get()->IsInRemains()){
    if(!n_BtnEnjoyLottery){
      n_BtnEnjoyLottery = EffectMainUITop::Get()->EnjoyLotteryBtn();
      n_ScrollBtn->addChild(n_BtnEnjoyLottery);
      n_BtnEnjoyLottery->setPosition(Vec2(35, 395));
      n_BtnEnjoyLottery->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnEnjoyLotteryClick, this));
      UpdateBtnContainer(nullptr);
    }else if(!n_BtnEnjoyLottery->isVisible()){
      n_BtnEnjoyLottery->setVisible(true);
      UpdateBtnContainer(nullptr);
    }
  }else if(n_BtnEnjoyLottery && n_BtnEnjoyLottery->isVisible()){
    n_BtnEnjoyLottery->setVisible(false);
    UpdateBtnContainer(nullptr);
  }
}

void UIMainBottom::OnEnjoyLotteryClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::EnjoyLottery, true)){
      auto l_Panel = UIEnjoyLotteryView::Create();
      l_Panel->Show();
    }
  }
}

void UIMainBottom::OnSultansBackWelClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::SultanBackWelcomeActivity, true)){
      auto l_Panel = UISultansBackWelBackView::Create();
      l_Panel->Show();
    }
  }
}

void UIMainBottom::OnGoldPackageClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    auto l_Panel = UIEventGoldPackageView::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::ShowLuckyBless(EventCustom* p_Event) {
  // local luckyBlessCtrl = gametop.playertop_:getModule("luckyBlessCtrl")
  // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  // if (luckyBlessCtrl:getLeftActivateCount() > 0 or luckyBlessCtrl:getLuckyBlessStatus() == 2) and
  // activityShowCtrl:isActivityOpen(gActivityTimeActivityID.LUCKY_BLESSING_ACTIVITY) then
  //   if self.luckyBlessNode then
  //     self.luckyBlessNode:removeFromParent()
  //     self.luckyBlessNode = nil
  //   end
  //   if self.luckyBlessNode == nil and self.viewChangeType == VIEW_TYPE_CITY then
  //     self.luckyBlessNode = include("effectMainUITop").luckyBlessShow(luckyBlessCtrl:getCurEffectType())
  //     self.luckyBlessNode:addTo(self.Node_area_lb)
  //     self.luckyBlessNode:setName("luckyBlessNode")
  //     self.luckyBlessNode:setVisible(false)
  //     local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  //     local guideStep = guideCtrl:getCurForceGuideStep()
  //     if not guideStep then
  //       self.luckyBlessNode:setVisible(true)
  //     end
  //   end
  // elseif self.luckyBlessNode then
  //   self.luckyBlessNode:removeFromParent()
  //   self.luckyBlessNode = nil
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::AddGoldPackageButton() {

  n_BtnGoldPackage = EffectMainUITop::Get()->GoldPackage();
  n_ScrollBtn->addChild(n_BtnGoldPackage);
  n_BtnGoldPackage->setPosition(Vec2(35, 395));
  n_BtnGoldPackage->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnGoldPackageClick, this));
  if(WorldMapDefine::Get()->IsInRemains() || !ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::GoldPackage, false))
    n_BtnGoldPackage->setVisible(false);
  else 
    n_BtnGoldPackage->setVisible(true);
  UpdateBtnContainer(nullptr);

}

void UIMainBottom::UpdateGoldPackageButton(EventCustom* p_Event) {
  if(ClientEventMgr::Get()-> JudgeIsOpen(EActivityTime::GoldPackage, false)){
    if(n_BtnGoldPackage){
      n_BtnGoldPackage->setVisible(true);
      UpdateBtnContainer(nullptr);
    }
  }else if(n_BtnGoldPackage){
    n_BtnGoldPackage->setVisible(true);
    auto l_SourceKID = LordInfoCtrl::Get()->GetLordInfo().Base.sourceKID;
    if(l_SourceKID == 0){
      n_BtnGoldPackage->setVisible(true);
    }
    UpdateBtnContainer(nullptr);
  }
}

void UIMainBottom::OnWorldCityClick(Ref* p_Sender, ui::Widget::TouchEventType p_Type) {
  if(p_Type == ui::Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    if(m_ViewChangeType == EScene::City){
      m_ViewChangeType = EScene::World;
      GBase::DSendMessage("MESSAGE_MAINCITYVIEW_SAVE_MAIN_CITY_POS");
      GBase::DSendMessage("MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE");
      //     gReGetWorldMapTroopDataCount = 0
    }else{
      m_ViewChangeType = EScene::City;
    }
    GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &m_ViewChangeType);
  }
}

void UIMainBottom::OnBottomClick(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  if(p_Touch == Widget::TouchEventType::ENDED){
    if(p_Sender == n_BtnHero){
      auto l_CastleLvl = GBase::DGetCastleLv();
      if(l_CastleLvl >= GBase::Const::Get()->CastleLvl7){
        //GBase::PlaySound("buildopsound", "OpWish");
        UIHeroListView::Create()->Show();
      }else{
        GBase::PlaySound("uicontrol", 20);
        GBase::DShowMsgTip(Translate::i18n("common_text_2122",{
          {"name", Translate::i18n("common_name_01")},
          {"lv", std::to_string(GBase::Const::Get()->CastleLvl7)}
        }));
      }
    }else if(p_Sender == n_BtnItems){
      GBase::PlaySound("uicontrol", 14);
      UIBagView::Create()->Show();
    }else if(p_Sender == n_BtnMail){
      GBase::PlaySound("uicontrol", 30);
      auto l_MailView = UIMailView::Create();
      l_MailView->Show();
      l_MailView->InitWithData();
    }else if(p_Sender == n_BtnAlliance){
      GBase::PlaySound("uicontrol", 29);
      InitAllianceView();
    }
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE");
  }
}

void UIMainBottom::InitAllianceView() {
  if(WorldMapDefine::Get()->IsInRemains()){
    UIAllianceWarView::Create()->Show();
  }else if(WorldMapDefine::Get()->IsInLegendLord()){
    LegendTeamUtil::Get()->OpenTeamView();
  }else if(WorldMapDefine::Get()->IsInAtlantis()){
    UIAtlantisWarTeamView::Create()->Show();
  }else{
    if(AllianceManager::Get()->HasJoinAlliance())
      UIAllianceMainView::Create()->Show();
    else 
      UIAllianceJoinView::Create()->Show();
  }
}

void UIMainBottom::UpdateGreenTip(RGreenTipsCount* p_BtnState) {

  n_TipAllianceCount->setString(std::to_string(p_BtnState->alliance));
  n_TipAlliance->setVisible(p_BtnState->alliance > 0);
  n_TipAllianceCount->setVisible(p_BtnState->alliance > 0);

  n_TipMailCount->setString(std::to_string(p_BtnState->mail));
  n_TipMail->setVisible(p_BtnState->mail > 0);
  n_TipMailCount->setVisible(p_BtnState->mail > 0);
  
  n_TipHeroCount->setString(std::to_string(p_BtnState->hero));
  n_TipHero->setVisible(p_BtnState->hero > 0);
  n_TipHeroCount->setVisible(p_BtnState->hero > 0);
  
  auto l_IsNew = ShopLtCtrl::Get()->GetShopNewTag("all");
  n_TipItemsCount->setString(std::to_string(p_BtnState->items));
  n_TipItems->setVisible(p_BtnState->items > 0 && l_IsNew);
  n_ItemNewIcon->setVisible(l_IsNew);

}

void UIMainBottom::UpdateShopNewTag(EventCustom* p_Event) {
  auto l_IsNew = ShopLtCtrl::Get()->GetShopNewTag("all");
  n_ItemNewIcon->setVisible(l_IsNew);
  if(l_IsNew){
    n_TipItems->setVisible(false);
    n_TipItemsCount->setVisible(false);
  }
}

void UIMainBottom::InitTipJump(Node* p_TipName) {

  if(!p_TipName)
    return;
  p_TipName->stopAllActions();
  p_TipName->setPosition(70, 60);
  if(GBase::DFIsRA()){
    p_TipName->setPosition(20, 60);
  }
  static auto l_MoveUp = MoveTo::create(0.5, Vec2(p_TipName->getPositionX(), p_TipName->getPositionY() + 8));
  static auto l_MoveDown = MoveTo::create(0.2, Vec2(p_TipName->getPositionX(), p_TipName->getPositionY() - 5));
  static auto l_Move = MoveTo::create(0.1, p_TipName->getPosition());
  static auto l_MoveAct = Sequence::create(
    DelayTime::create(5),
    l_MoveUp, 
    l_MoveDown,
    l_MoveUp, 
    l_MoveDown,
    l_MoveUp, 
    l_MoveDown,
    l_Move,
    nullptr
  );
  p_TipName->runAction(RepeatForever::create(l_MoveAct));
}

void UIMainBottom::OnSkillClick(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  if(p_Touch == Widget::TouchEventType::ENDED){
    GBase::PlaySound("uicontrol", 13);
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE");
    auto l_Panel = UISkillNewActiveView::Create();
    l_Panel->Show();
  }
}

void UIMainBottom::OnReplayClick(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  if(p_Touch == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    GBase::DSendMessage("MESSAGE_MAIN_STOP_RECORD_SCREEN");
  }
}

void UIMainBottom::UpdateBtnLuckyRecharge(EventCustom* p_Event) {

  if(!ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::LuckyRechargeTaskActivity)){
    n_BtnLuckyRecharge->setVisible(false);
    UpdateBtnContainer(nullptr);
    return;
  }
  if(WorldMapDefine::Get()->InInCrossWar()){
    n_BtnLuckyRecharge->setVisible(false);
    UpdateBtnContainer(nullptr);
    return;
  }
  // local eventLuckyRechargeCtrl = gametop.playertop_:getModule("eventLuckyRechargeCtrl")
  // local luckyRechargeData = eventLuckyRechargeCtrl:getLuckyRechargeData()

  // local state = luckyRechargeData.rechargeStatus
  // if state then
  //   if state == gLuckyRechargeStatus.CAN_NOT_RECEIVE then
  //     self.btnLuckyRecharge:setVisible(true)
  //     self.btnLuckyRecharge.img_yes:setVisible(false)
  //     self.btnLuckyRecharge.lab_target:setVisible(true)
  //     self.btnLuckyRecharge.img_black:setVisible(true)
  //     local rtarget = luckyRechargeData.todayRechargeTarget or 0
  //     self.btnLuckyRecharge.lab_target:setString("$" .. rtarget)
  //     transition.stopTarget(self.btnLuckyRecharge.btn_bg)
  //   elseif state == gLuckyRechargeStatus.CAN_RECEIVE then
  //     self.btnLuckyRecharge:setVisible(true)
  //     self.btnLuckyRecharge.img_yes:setVisible(true)
  //     self.btnLuckyRecharge.lab_target:setVisible(false)
  //     self.btnLuckyRecharge.img_black:setVisible(false)
  //     local seq = cca.seq({
  //       cca.rotateTo(0.2, -20),
  //       cca.rotateTo(0.1, 0),
  //       cca.rotateTo(0.1, 20),
  //       cca.rotateTo(0.1, 0),
  //       cca.rotateTo(0.1, 20),
  //       cca.rotateTo(0.1, 0),
  //       cca.delay(2)
  //     })
  //     transition.stopTarget(self.btnLuckyRecharge.btn_bg)
  //     self.btnLuckyRecharge.btn_bg:runAction(cc.RepeatForever:create(seq))
  //   else
  //     self.btnLuckyRecharge:setVisible(false)
  //   end
  // else
  //   self.btnLuckyRecharge:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::OnLuckyReachergeClick(Ref* p_Sender, ui::Widget::TouchEventType p_Touch) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("eventLuckyRechargeView"):show()
  // end
}

void UIMainBottom::StopRecording(EventCustom* p_Event) {
  // userSDKManager.logEvent(gSDKDef.TDonEvent.screen_recording_log, {
  //   type = 2,
  //   times = gSDKDef.GAME_RECORD_TIME
  // })
  // gSDKDef.GAME_RECORD_TIME = 0
  // userSDKManager.stopRecording()
  // SoraDManagerRemoveTimer(self, self.timer)
  // self.timer = nil
  // self.btnReplay:setVisible(false)
  // self.textVideo:setString(SoraDConvertSecondToString(0))
  // if device.platform == "ios" then
  //   local seq = cca.seq({
  //     cca.callFunc(function()
  //       self:updateBtnContainer()
  //     end)
  //   })
  //   self:runAction(seq)
  // else
  //   self:updateBtnContainer()
  // end
}

void UIMainBottom::OpenUIAlliance(EventCustom* p_Event) { InitAllianceView(); }

void UIMainBottom::CurrentShowViewType(EventCustom* p_Event) {
  EScene l_ViewType = EScene::None;
  if (p_Event && p_Event->getUserData() != nullptr) l_ViewType = *static_cast<EScene*>(p_Event->getUserData());
  m_ViewChangeType = l_ViewType;
  if (m_ViewChangeType == EScene::City) {
    n_ImgWorldCity->loadTexture("btn_main_world.png", TextureResType::PLIST);
    if (n_NodeQuestGuide) n_NodeQuestGuide->setVisible(true);
    CreateExpostulationTimer();
    InitAccountBind(nullptr);
    UpdateBtnContainer(nullptr);
    ShowOrHideGuideView(nullptr);
  } else {
    n_ImgWorldCity->loadTexture("btn_main_city.png", TextureResType::PLIST);
    if (n_NodeQuestGuide) n_NodeQuestGuide->setVisible(false);
    DeleteExpostulationTimer();
    if (n_BtnAccount) n_BtnAccount->setVisible(false);
  }
  BtnNeckLaceRankCheck(nullptr);
  UpdateEventcenter(nullptr);
  CheckWallDefend(nullptr);
  InitHelpAllBtn(nullptr);
  SortBottomQuestBtns(nullptr);
}

void UIMainBottom::MsgUpdateMailIconNumber(EventCustom* p_Event) {
  auto l_NumberNewMailTotal = MailManger::Get()->GetNewMailNum();
  if(l_NumberNewMailTotal == 0){
    n_TipMail->setVisible(false);
  }else{
    n_TipMail->setVisible(true);
    n_TipMailCount->setString(std::to_string(l_NumberNewMailTotal));
  }
}

void UIMainBottom::sMsgUpdateNumberNewMail(EventCustom* p_Event) {
  MsgUpdateMailIconNumber(p_Event); 
}

void UIMainBottom::CheckWatchTower(EventCustom* p_Event) {
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local red, blue, frm, roman = kingdomMapCtrl:getWatchTowerLightInfo()
  // local isIgnoreRomanSoul = kingdomMapCtrl:getWatchTowerQueue():isIgnoreRomanSoul()
  // if red > 0 then
  //   self.btnWatchTower:setVisible(true)
  //   self.iconAlarm:setSpriteFrame("icon_main_building_alarm.png")
  // elseif blue > 0 then
  //   self.btnWatchTower:setVisible(true)
  //   self.iconAlarm:setSpriteFrame("icon_main_building_alarm_blue.png")
  // else
  //   self.btnWatchTower:setVisible(false)
  // end
  // self:openWarning(roman > 0 and not isIgnoreRomanSoul or frm > 0)
  // if not self.inRomanTime then
  //   self.btnRomanSoul:setVisible(roman > 0)
  //   self:updateBtnContainer()
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::CheckRomanSoul(EventCustom* p_Event) {
  // print("MainUIBottom:checkRomanSoul")
  // local romeActivityCtrl = gametop.playertop_:getModule("romeActivityCtrl")
  // local isRomanEvent = false
  // if romeActivityCtrl.state == gAllianceRomeActivityState.RUNNING and not worldMapDefine.isInRemains() then
  //   isRomanEvent = true
  // end
  // if isRomanEvent then
  //   self.inRomanTime = true
  //   self.btnRomanSoul:setVisible(true)
  //   self:updateBtnContainer()
  // else
  //   self.inRomanTime = false
  //   self:checkWatchTower()
  // end
}

void UIMainBottom::CheckWallDefend(EventCustom* p_Event) {
  // local wallsCtrl = gametop.playertop_:getModule("wallsCtrl")
  // local burnningTime = wallsCtrl:getBurningTime()
  // if self.viewChangeType == VIEW_TYPE_CITY then
  //   if burnningTime > 0 then
  //     self.btnWallBurning:setVisible(true)
  //     self:showWallFireEffect()
  //   else
  //     self.btnWallBurning:setVisible(false)
  //     self:hideWallFireEffect()
  //   end
  // else
  //   self.btnWallBurning:setVisible(false)
  //   self:hideWallFireEffect()
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::BtnPyramidBattleCheck(EventCustom* p_Event) {
  // local pyramidWarCtrl = gametop.playertop_:getModule("pyramidWarCtrl")
  // local canShow, leftTime = pyramidWarCtrl:isShowEnterPyramidWar()
  // print("btnPyramidBattleCheck", canShow, leftTime)
  // canShow = canShow and not worldMapDefine.isInWar()
  // self.btnPyramidBattle:setVisible(canShow)
  // self.txtPyramidBattleTime:beginTime(leftTime or 0)
  // self.btnPyramidPlayoffs:setVisible(false)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnNeckLaceRankCheck(EventCustom* p_Event) {
  // self.btnNeckLaceRank:setVisible(false)
  // self:updateBtnContainer()
}

void UIMainBottom::MsgHegemonClean(EventCustom* p_Event) {
  // self:btnHegemonManagerCheck()
  // self:btnHegemonBattleCheck()
}

void UIMainBottom::BtnCityUnlockCheck(EventCustom* p_Event) {
  // local maincityDesRead = include("maincityDesRead")
  // local lv = SoraDGetCastleLv()
  // local data = maincityDesRead.getUnlockInfoByLv(lv, false)
  // if #data > 0 then
  //   self.spriteCityUnlock:setSpriteFrame(maincityDesRead.getUnlockIconByLv(lv))
  //   self.txtCityUnlock:setString(i18n("common_text_427", {
  //     level = data[1].unlocklevel
  //   }))
  //   self.btnCityUnlock:setVisible(true)
  // else
  //   self.btnCityUnlock:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::BtnPayBackCheck(EventCustom* p_Event) {
  // local payBackCtrl = SoraDGetCtrl("payBackCtrl")
  // local price = payBackCtrl:getPrice()
  // if price > 0 then
  //   if not self.btnPayBack then
  //     self.btnPayBack = self.btnHegemonBattle:clone()
  //     self.btnPayBack:addTo(self.scroll_btn)
  //     self.btnPayBack:addTouchEventListener(handler(self, self.btnPayBackClick))
  //     local icon = SoraDGetChildByName(self.btnPayBack, "icon_hegemon_playoff")
  //     icon:setSpriteFrame("icon_eytk_01.png")
  //     local Text_enter = SoraDGetChildByName(self.btnPayBack, "Text_playoffTime")
  //     Text_enter:setString(i18n("PayBack_Text_01"))
  //   end
  //   self.btnPayBack:setVisible(true)
  // elseif self.btnPayBack then
  //   self.btnPayBack:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddPrinceGiftNewBuffButton(EventCustom* p_Event) {
  //  local gametop = gModuleMgr.getObject("gametop")
  // local princeGiftNewCtrl = gametop.playertop_:getModule("princeGiftNewCtrl")
  // if data and data.isRelogin then
  //   princeGiftNewCtrl:reqInitInfo()
  // end
  // local remainTime = princeGiftNewCtrl:getBuffEndTime() - serviceFunctions.systemTime()
  // dump(remainTime, "MainUIBottom:addPrinceGiftNewBuffButton")
  // if remainTime > 0 then
  //   self.btnPrinceGiftNewBuff:setVisible(true)
  //   self.textPrinceGiftNew:setTimeEndListener(function()
  //     self.btnPrinceGiftNewBuff:setVisible(false)
  //     self:updateBtnContainer()
  //   end)
  //   self.textPrinceGiftNew:beginTime(remainTime)
  // else
  //   self.btnPrinceGiftNewBuff:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddPrinceGiftBuffButton(EventCustom* p_Event) {
  //     local gametop = gModuleMgr.getObject("gametop")
  //   local princeGiftCtrl = gametop.playertop_:getModule("princeGiftCtrl")
  //   if data and data.isRelogin then
  //     princeGiftCtrl:reqInitInfo()
  //   end
  //   local remainTime = princeGiftCtrl:getBuffEndTime() - serviceFunctions.systemTime()
  //   if remainTime > 0 then
  //     self.btnPrinceGiftBuff:setVisible(true)
  //     self.textPrinceGift:setTimeEndListener(function()
  //       self.btnPrinceGiftBuff:setVisible(false)
  //       self:updateBtnContainer()
  //     end)
  //     self.textPrinceGift:beginTime(remainTime)
  //   else
  //     self.btnPrinceGiftBuff:setVisible(false)
  //   end
  //   self:updateBtnContainer()
}

void UIMainBottom::BtnNewPlayerBuffCheck(EventCustom* p_Event) {
  // local gametop = gModuleMgr.getObject("gametop")
  // local buffCtrl = gametop.playertop_:getModule("buffCtrl")
  // local isNewPlayer = buffCtrl:isNewPlayerBuffOpen()
  // local remainTime = buffCtrl:getRemainTimeByBuffID(5451) or 0
  // if isNewPlayer and remainTime > 0 then
  //   self.btnNewPlayerBuff:setVisible(true)
  //   self.textNewPlayer:setTimeLast(function(ticket)
  //     return i18n("guide_text_159") .. "\n" .. ticket
  //   end)
  //   self.textNewPlayer:setTimeEndListener(function()
  //     self.btnNewPlayerBuff:setVisible(false)
  //     self:updateBtnContainer()
  //   end)
  //   self.textNewPlayer:beginTime(remainTime)
  // else
  //   self.btnNewPlayerBuff:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::BtnSultansBackWelCheck(EventCustom* p_Event) {
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SULTAN_BACK_WELCOME_ACTIVITY, false) then
  //   self.btnSultansWelBack:setVisible(true)
  //   local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  //   local eventTime = activityShowCtrl:getTimeInfoByID(gActivityTimeActivityID.SULTAN_BACK_WELCOME_ACTIVITY)
  //   if eventTime then
  //     self.textWelBack:beginTime(eventTime.timerNode.timer:getRemainTime())
  //   end
  //   self:updateBtnContainer()
  // elseif self.btnSultansWelBack then
  //   self.btnSultansWelBack:setVisible(false)
  //   self:updateBtnContainer()
  // end
}

void UIMainBottom::BtnHegemonBattleCheck(EventCustom* p_Event) {
  // local worldMapDefine = include("worldMapDefine")
  // local isShow = false
  // local hegemonCtrl = gametop.playertop_:getModule("hegemonCtrl")
  // local castleLv = SoraDGetCastleLv()
  // if castleLv < 30 or worldMapDefine.isInRemains() then
  //   isShow = false
  // else
  //   local joinBid = hegemonCtrl:getJoinBid()
  //   print("joinBid = ", joinBid)
  //   if not joinBid then
  //     isShow = false
  //   elseif worldMapDefine.isInLegendLord() then
  //     isShow = false
  //   else
  //     local hegemonRead = include("hegemonRead")
  //     local activityID = hegemonRead.getActivityIdByBuildID(joinBid)
  //     print("jonBid = ", joinBid)
  //     local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  //     local param = activityShowCtrl:getParamByID(activityID)
  //     dump(param, "param", 10)
  //     if param then
  //       local curState = param.curState
  //       if curState == ACTIVITY_STATE.ACTIVE then
  //         local settleTime = param.timeConfig.settleTime
  //         local leftTime = settleTime - serviceFunctions.systemTime()
  //         print("leftTime = ", leftTime)
  //         if leftTime > 0 then
  //           self.spHegemonBattleTimeBg:setVisible(true)
  //           self.txtHegemonBattleTime:setVisible(true)
  //           isShow = true
  //           self.txtHegemonBattleTime:beginTime(leftTime)
  //           self.txtHegemonBattleTime:setTimeEndListener(function(...)
  //             self.btnHegemonBattle:setVisible(false)
  //             self:updateBtnContainer()
  //           end)
  //         else
  //           self.spHegemonBattleTimeBg:setVisible(false)
  //           self.txtHegemonBattleTime:setVisible(false)
  //           isShow = false
  //         end
  //         print("settleTime", settleTime, leftTime)
  //       end
  //     end
  //   end
  // end
  // self.btnHegemonBattle:setVisible(isShow)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnKingdomManagerCheck(EventCustom* p_Event) {
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local myRank = kingdomMapCtrl:getKingWarRank()
  // local isShow = false
  // self.btnKingdomManagerState = 0
  // local function showTime(bool)
  //   if bool then
  //     self.spKingdomManagerTimeBg:setVisible(true)
  //     self.txtKingdomManagerTime:setVisible(true)
  //     local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  //     local timeLeft = kingdomMapCtrl:getKingWarPackLeftTime()
  //     if timeLeft > 0 then
  //       self.txtKingdomManagerTime:beginTime(timeLeft)
  //     end
  //   else
  //     self.spKingdomManagerTimeBg:setVisible(false)
  //     self.txtKingdomManagerTime:setVisible(false)
  //   end
  // end
  // local function showCrown(bool)
  //   if bool then
  //     self.btnKingdomManagerSprite:setVisible(true)
  //     if self.btnKingdomManager:getChildByName("Sprite_PlayerBox") then
  //       self.btnKingdomManager:getChildByName("Sprite_PlayerBox"):setVisible(false)
  //     end
  //     showTime(false)
  //   else
  //     self.btnKingdomManagerSprite:setVisible(false)
  //     if self.btnKingdomManager:getChildByName("Sprite_PlayerBox") then
  //       self.btnKingdomManager:getChildByName("Sprite_PlayerBox"):setVisible(true)
  //     else
  //       local effectMainUITop = include("effectMainUITop")
  //       local node = effectMainUITop.combatantGift()
  //       node:setPosition(self.btnKingdomManager:getContentSize().width / 2, self.btnKingdomManager:getContentSize().height / 2)
  //       node:setName("Sprite_PlayerBox")
  //       node:addTo(self.btnKingdomManager, 10)
  //     end
  //     self.spKingdomManagerTimeBg:setLocalZOrder(11)
  //     self.txtKingdomManagerTime:setLocalZOrder(12)
  //     showTime(true)
  //   end
  // end
  // if not worldMapDefine.isInWar() then
  //   if SoraDIsSelfKing() then
  //     isShow = true
  //     self.btnKingdomManagerState = 1
  //     showCrown(true)
  //   elseif myRank and myRank >= ALLIANCE_GIFT_MAX_RANK and myRank <= ALLIANCE_GIFT_MIN_RANK then
  //     isShow = true
  //     self.btnKingdomManagerState = 2
  //     showCrown(false)
  //   end
  // end
  // self.btnKingdomManager:setVisible(isShow)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnLegendKingManagerCheck(EventCustom* p_Event) {
  // local isShow = false
  // local legendLordCtrl = gametop.playertop_:getModule("legendLordCtrl")
  // local nodesArray = {
  //   self.spLegendKingManagerTimeBg,
  //   self.txtLegendKingManagerTime
  // }
  // SoraDSetNodeArrayVisible(nodesArray, false)
  // local isLegendKing = legendLordCtrl:getIsSelfLegendKing()
  // if isLegendKing and not worldMapDefine.isInRemains() then
  //   isShow = true
  // end
  // self.btnLegendKingManager:setVisible(isShow)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnHegemonManagerCheck(EventCustom* p_Event) {
  // local isShow = false
  // local hegemonCtrl = gametop.playertop_:getModule("hegemonCtrl")
  // local nodesArray = {
  //   self.spHegemonManagerTimeBg,
  //   self.txtHegemonManagerTime
  // }
  // SoraDSetNodeArrayVisible(nodesArray, false)
  // local isHegemon = hegemonCtrl:getIsSelfHegemon()
  // print("isHegemon = ", isHegemon)
  // if isHegemon and not worldMapDefine.isInRemains() then
  //   isShow = true
  // end
  // self.btnHegemonManager:setVisible(isShow)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnTrainPowerManagerCheck() {
  // local isShow = false
  // local trainPowerCtrl = gametop.playertop_:getModule("trainPowerCtrl")
  // isShow = clientEventMgr.judgeIsOpen(gActivityTimeActivityID.TRAIN_POWER_ACTIVITY)
  // dump(isShow, "btnTrainPowerManagerCheck")
  // self.btnTrainPower:setVisible(isShow)
  // if isShow then
  //   local flag, num = trainPowerCtrl:getReceiveStatusAndNum()
  //   dump(trainPowerCtrl:getReceiveStatusAndNum(), "btnTrainPowerManagerCheck")
  //   self.Red_trainPower:setVisible(flag)
  //   self.Num_trainPower:setString(num > 0 and tostring(num) or "")
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::RefreshTrainPower(EventCustom* p_Event) {
  // if not data then
  //   return
  // end
  // if data.eventID == gActivityTimeActivityID.TRAIN_POWER_ACTIVITY or data.activityID == gActivityTimeActivityID.TRAIN_POWER_ACTIVITY then
  //   self:btnTrainPowerManagerCheck()
  // end
}

void UIMainBottom::BtnWatchTowerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("watchTowerView")
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnWallBurningClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("defendView"):show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnKingdomManagerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if 1 == self.btnKingdomManagerState then
  //     worldMapDefine.kingdomStatusManager = true
  //     local panel = SoraDCreatePanel("worldMapKingdomCityOfficialManagerView")
  //     panel:initView()
  //     panel:show()
  //   elseif 2 == self.btnKingdomManagerState then
  //     SoraDCreatePanel("worldMapKingdomCityPlayerGiftBag"):show()
  //   end
  // end
}

void UIMainBottom::BtnLegendKingManagerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local legendaryKingView = SoraDCreatePanel("legendaryKingView")
  //   legendaryKingView:show()
  //   legendaryKingView:init({viewType = 2})
  // end
}

void UIMainBottom::BtnLegendInviteClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if not SoraDSearchPanelFromManagerByName("legendTeamInvitedView") then
  //     local panel = SoraDCreatePanel("legendTeamInvitedView")
  //     panel:show()
  //     panel:initData()
  //   end
  // end
}

void UIMainBottom::BtnRadianceWarClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local radianceWarUtil = include("radianceWarUtil")
  //   radianceWarUtil.openRadianceWarView()
  // end
}

void UIMainBottom::BtnHegemonManagerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local legendaryKingView = SoraDCreatePanel("hegemonView")
  //   legendaryKingView:show()
  //   local hegemonCtrl = gametop.playertop_:getModule("hegemonCtrl")
  //   legendaryKingView:init({
  //     bid = hegemonCtrl:getJoinBid()
  //   })
  // end
}

void UIMainBottom::BtnHegemonBattleClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("hegemonActivity"):show()
  // end
}

void UIMainBottom::BtnTrainPowerClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 49)
  //   local panel = SoraDCreatePanel("trainPowerView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnRomanSoulClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("watchTowerSoulView")
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnPyramidPlayoffsClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("pyramidAllianceGiftView"):show()
  // end
}

void UIMainBottom::BtnPyramidBattleClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("pyramidBattleView"):show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnAccountClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 48)
  //   local panel = SoraDCreatePanel("commonAccountBonusBox")
  //   panel:show()
  // end
}

void UIMainBottom::BtnNeckLaceRankClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("ringRankView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnCityUnlockClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("cityUpgradeUnlockView")
  //   panel:initData(panel.unlockInfo)
  //   panel:show()
  // end
}

void UIMainBottom::BtnNewPlayerBuffClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("citybuffView")
  //   panel:show()
  //   panel:openNewPlayerView()
  // end
}

void UIMainBottom::BtnPrinceGiftNewBuffClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("princeGiftNewBuffPreviewPopView")
  //   local princeGiftNewCtrl = SoraDGetCtrl("princeGiftNewCtrl")
  //   panel:initData(princeGiftNewCtrl:getBuffDesc())
  //   panel:show()
  // end
}

void UIMainBottom::BtnPrinceGiftBuffClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("princeGiftBuffStrengthenView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnSwitchClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   self.btnSwitchType = -self.btnSwitchType
  //   self.btnSwitch:setTouchEnabled(false)
  //   self:switchBottonBtn()
  // end
}

void UIMainBottom::SwitchBottonBtn() {
  // local actFrame = 20
  // self.node_arrow:stopAllActions()
  // local rBy = 180
  // self.nodeBottomBtn:stopAllActions()
  // if self.btnSwitchType < 0 then
  //   self.node_arrow:setRotation(0)
  //   rBy = 180
  //   do
  //     local _dt = 0
  //     local _height = self.btnManager:getContentSize().height
  //     local _sHeight = self.scroll_btn:getContentSize().height
  //     local seq_close = cca.seq({
  //       cca.delay(0.016666666666666666),
  //       cca.callFunc(function()
  //         if _dt <= actFrame then
  //           self.btnManager:setContentSize(cc.size(72, math.max(72, _height * (1 - _dt / actFrame))))
  //           self.scroll_btn:setContentSize(cc.size(70, math.max(0, _sHeight * (1 - _dt / actFrame))))
  //           self.btnSwitch:setPositionY(math.max((_height - 35) * (1 - _dt / actFrame), 37))
  //           _dt = _dt + 1
  //         else
  //           self.iconRed:setVisible(true)
  //           self.nodeBottomBtn:stopAllActions()
  //         end
  //       end)
  //     })
  //     self.nodeBottomBtn:runAction(cc.RepeatForever:create(seq_close))
  //   end
  // else
  //   self.node_arrow:setRotation(180)
  //   rBy = -180
  //   do
  //     local _dt = 0
  //     local seq_open = cca.seq({
  //       cca.delay(0.016666666666666666),
  //       cca.callFunc(function()
  //         if _dt <= actFrame then
  //           self.btnManager:setContentSize(cc.size(72, math.max(72, self.showHeight * _dt / actFrame)))
  //           self.scroll_btn:setContentSize(cc.size(70, math.max(0, (self.showHeight - 108) * _dt / actFrame)))
  //           self.btnSwitch:setPositionY(math.max(self.showHeight * _dt / actFrame - 37, 37))
  //           _dt = _dt + 1
  //         else
  //           self.nodeBottomBtn:stopAllActions()
  //         end
  //       end)
  //     })
  //     self.nodeBottomBtn:runAction(cc.RepeatForever:create(seq_open))
  //     self.iconRed:setVisible(false)
  //   end
  // end
  // local seq = cca.seq({
  //   cca.rotateBy(actFrame / 60, rBy),
  //   cca.callFunc(function()
  //     self.btnSwitch:setTouchEnabled(true)
  //   end)
  // })
  // self.node_arrow:runAction(seq)
}

void UIMainBottom::UpdateBtnContainer(EventCustom* p_Event) {
  // local btnTableName = {
  //   "btnCityUnlock",
  //   "btnNewPlayerBuff",
  //   "btnRomanSoul",
  //   "btnPyramidPlayoffs",
  //   "btnPyramidBattle",
  //   "btnLegendKingManager",
  //   "btnHegemonManager",
  //   "btnHegemonBattle",
  //   "btnKingdomManager",
  //   "btnCrazyTrio",
  //   "btnLostRuins",
  //   "btnWindTower",
  //   "btnSnowWolfLost",
  //   "btnTrainPower",
  //   "btnLuckyRecharge",
  //   "btnGoldPackage",
  //   "btnEnjoyLottery",
  //   "btnMonthCard",
  //   "btnReplay",
  //   "btnQuestionnaire",
  //   "btnCommunity",
  //   "btnNeckLaceRank",
  //   "btnBattleOpen",
  //   "btnTogetherTeam",
  //   "btnKOChoice",
  //   "btnSultansWelBack",
  //   "btnThanksGivingParty",
  //   "btnPrinceGiftBuff",
  //   "btnPrinceGiftNewBuff",
  //   "btnSixYearActivity",
  //   "btnHarvestSeason",
  //   "nodePreDownload",
  //   "btnPayBack"
  // }
  // local btnTable = {}
  // for i, v in ipairs(btnTableName) do
  //   if self[v] then
  //     table.insert(btnTable, self[v])
  //   end
  // end
  // local btnCounts = #btnTable
  // local showNum = 0
  // for i = 1, btnCounts do
  //   if btnTable[i] then
  //     if data and data.test then
  //       btnTable[i]:setVisible(data.test[i])
  //     end
  //     if btnTable[i]:isVisible() then
  //       showNum = showNum + 1
  //     end
  //   end
  // end
  // if showNum == 0 then
  //   self.btnManager:setVisible(false)
  //   self.scroll_btn:setVisible(false)
  //   return
  // end
  // self.labBtnNum:setString(showNum)
  // self.btnManager:setVisible(true)
  // self.scroll_btn:setVisible(true)
  // local currentScene = display.getRunningScene()
  // local _mainUITop = currentScene:currentMainUI()
  // local topNum = 0
  // if _mainUITop and _mainUITop.topArea then
  //   local nodes = {
  //     _mainUITop.topArea.nodeLucky,
  //     _mainUITop.topArea.nodeRecharge,
  //     _mainUITop.topArea.nodeEvent
  //   }
  //   for k, v in ipairs(nodes) do
  //     if v:isVisible() then
  //       topNum = topNum + 1
  //     end
  //   end
  // end
  // local maxShowHeight = display.height - 355 - topNum * 90
  // self.showHeight = math.min(maxShowHeight, 105 + showNum * 80)
  // if 0 > self.btnSwitchType then
  //   self.btnManager:setContentSize(cc.size(72, 72))
  //   self.scroll_btn:setContentSize(cc.size(70, 0))
  //   self.btnSwitch:setPositionY(37)
  // else
  //   local scrollShowHeight = self.showHeight - 108
  //   self.btnManager:setContentSize(cc.size(72, math.max(72, self.showHeight)))
  //   self.scroll_btn:setContentSize(cc.size(70, math.min(80 * showNum, scrollShowHeight)))
  //   self.btnSwitch:setPositionY(self.showHeight - 37)
  //   self.scroll_btn:setTouchEnabled(scrollShowHeight < 80 * showNum)
  // end
  // self.scroll_btn:setInnerContainerSize(cc.size(70, math.max(80 * showNum, self.scroll_btn:getContentSize().height)))
  // local visTbl = {}
  // for _, v in ipairs(btnTable) do
  //   if v:isVisible() then
  //     table.insert(visTbl, v)
  //   end
  // end
  // local posY = 35
  // for _, v in ipairs(visTbl) do
  //   v:setPositionY(posY)
  //   posY = posY + 80
  // end
}

void UIMainBottom::AddKOChoiceButton(EventCustom* p_Event) {
  // print("addKOChoiceButton")
  // if userSDKManager.isKO() then
  //   local bPopBefore = SoraDConfigGet("Game:MainCityView:ROSKOChoice~bool", {byUID = true})
  //   if not bPopBefore then
  //     local effectMainUITop = include("effectMainUITop")
  //     self.btnKOChoice = effectMainUITop.createCommonBtn("#icon_user_transfer_KO.png")
  //     self.btnKOChoice:addTo(self.scroll_btn)
  //     self.btnKOChoice:setPosition(cc.p(35, 395))
  //     self.btnKOChoice:addTouchEventListener(handler(self, self.OnKOChoiceClick))
  //     self:updateBtnContainer()
  //   elseif self.btnKOChoice then
  //     self.btnKOChoice:removeFromParent()
  //     self.btnKOChoice = nil
  //     self:updateBtnContainer()
  //   end
  // end
}

void UIMainBottom::OnKOChoiceClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("koUserNotifyView")
  //   panel:show()
  // end
}

void UIMainBottom::AddSixYearActivityButton() {
  // local activityID = gActivityTimeActivityID.SIX_YEAR_ACTIVITY
  // if clientEventMgr.judgeIsOpen(activityID) then
  //   if not self.btnSixYearActivity then
  //     local effectMainUITop = include("effectMainUITop")
  //     local button = effectMainUITop.thanksGivingPartyBtn()
  //     button.btn_bg:setSpriteFrame("frame_huodongzhongxin_6tubiao.png")
  //     button.btn_bg:setScale(0.8)
  //     button:addTo(self.scroll_btn)
  //     button:setPosition(cc.p(35, 395))
  //     button:addTouchEventListener(function(button, eventType)
  //       if eventType ~= ccui.TouchEventType.ended then
  //         return
  //       end
  //       SoraDPlaySound()
  //       clientEventMgr.singleClickEvent(activityID)
  //     end)
  //     self.btnSixYearActivity = button
  //   end
  //   local eventTime = SoraDGetCtrl("activityShowCtrl"):getTimeInfoByID(activityID)
  //   if eventTime then
  //     self.btnSixYearActivity.labelTime:beginTime(eventTime.timerNode.timer:getRemainTime())
  //   else
  //     self.btnSixYearActivity.labelTime:setVisible(false)
  //   end
  // elseif self.btnSixYearActivity then
  //   self.btnSixYearActivity:removeFromParent()
  //   self.btnSixYearActivity = nil
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddHarvestSeasonButton(EventCustom* p_Event) {
  // if not IsArClient then
  //   return
  // end
  // local actIDList = {}
  // local newFlag = false
  // local config = require("app." .. LocalTblPath .. ".config_server.act_common_config")
  // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  // local activityCenterUICtrl = gametop.playertop_:getModule("activityCenterUICtrl")
  // local remainTime = 0
  // for actID, v in pairs(config) do
  //   if clientEventMgr.judgeIsOpen(actID) then
  //     local newF = activityCenterUICtrl:isHaveNewFlag(actID)
  //     if newF then
  //       newFlag = true
  //     end
  //     table.insert(actIDList, actID)
  //     local eventTime = activityShowCtrl:getTimeInfoByID(actID)
  //     if eventTime then
  //       local tmp = eventTime.timerNode.timer:getRemainTime()
  //       if remainTime < tmp then
  //         remainTime = tmp
  //       end
  //     end
  //   end
  // end
  // if remainTime and remainTime ~= 0 then
  //   if self.btnHarvestSeason then
  //     self.btnHarvestSeason.labelTime:beginTime(remainTime)
  //     if newFlag then
  //       self.btnHarvestSeason.redIcon:setVisible(true)
  //     end
  //   else
  //     local effectMainUITop = include("effectMainUITop")
  //     local button = effectMainUITop.harvestSeason()
  //     button.btn_bg:setSpriteFrame("icon_fsjj_rktb.png")
  //     button.btn_bg:setScale(0.8)
  //     button.redIcon:setVisible(false)
  //     button:addTo(self.scroll_btn)
  //     button:setPosition(cc.p(35, 395))
  //     if newFlag then
  //       button.redIcon:setVisible(true)
  //     end
  //     button:addTouchEventListener(function(button, eventType)
  //       if eventType ~= ccui.TouchEventType.ended then
  //         return
  //       end
  //       SoraDPlaySound()
  //       print("djjdjjsjsj")
  //       dump(actIDList)
  //       SoraDGetCtrl("activityCenterUICtrl", gametop):sendClearNewList2Msg(actIDList)
  //       self.btnHarvestSeason.redIcon:setVisible(false)
  //       local param = {time = remainTime, actList = actIDList}
  //       uiManager:show("HarvestSeasonMain", param)
  //     end)
  //     self.btnHarvestSeason = button
  //     isUpdate = true
  //     self.btnHarvestSeason.labelTime:beginTime(remainTime)
  //   end
  // elseif self.btnHarvestSeason then
  //   self.btnHarvestSeason:removeFromParent()
  //   self.btnHarvestSeason = nil
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::RecevieItemChangeMsg(EventCustom* p_Event) {
  // if redata and redata.itemType and gItemType.HERO_CHIP == redata.itemType then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_GREEN_POINT_UPDATE",
  //     type = GREEN_POINT_NOTICE_TYPE.HERO
  //   })
  // end
}

void UIMainBottom::GreenPointUpdate(EventCustom* p_Event) {
  // local questCtrl = gametop.playertop_:getModule("questCtrl")
  // local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
  // if data.type == GREEN_POINT_NOTICE_TYPE.QUEST then
  // elseif data.type == GREEN_POINT_NOTICE_TYPE.ITEMS then
  //   self:updateGreenTip({
  //     items = backpackCtrl:getNewItemTotal()
  //   })
  // elseif data.type == GREEN_POINT_NOTICE_TYPE.MAIL then
  //   self:updateGreenTip({
  //     mail = mailMgr:getNewMailNum()
  //   })
  // elseif data.type == GREEN_POINT_NOTICE_TYPE.HERO then
  //   self:updateGreenTip({
  //     hero = heroltCtrl:getHeroBottomPointNum()
  //   })
  // else
  //   local updateAllianceGreen = SoraDIntervalCallOnce("MainUIBottom_UpdateGreen", function()
  //     self.updateAllianceGreen = nil
  //     self:updateGreenPointAlliance()
  //     self:updateGreenPointRadianceWar()
  //     self:showAllianceInWarEffect()
  //   end, 1, true)
  //   if updateAllianceGreen then
  //     self.updateAllianceGreen = updateAllianceGreen
  //   end
  // end
}

void UIMainBottom::GreenPointUpdateByType(EventCustom* p_Event) {
  // if GREEN_POINT_NOTICE_TYPE.ALLIANCE == data.type then
  //   self:updateGreenPointAlliance()
  // end
}

void UIMainBottom::UpdateGreenPointAlliance() {
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local allianceTreasureCtrl = gametop.playertop_:getModule("allianceTreasureCtrl")
  // local allianceActiveCtrl = gametop.playertop_:getModule("allianceActiveCtrl")
  // local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  // local allianceCount = kingdomMapCtrl:getHallWarCount()
  // if not worldMapDefine.isInWarForbid(true) then
  //   local allianceRelationCtrl = gametop.playertop_:getModule("allianceRelationCtrl")
  //   local allianceCounterSysCtrl = gametop.playertop_:getModule("allianceCounterSysCtrl")
  //   local counterSysCount = gametop.playertop_:getModule("counterSysCount")
  //   local allianceDesRead = include("allianceDesRead")
  //   if allianceDesRead.checkRank(gAllianceRank.R4) then
  //     allianceCount = allianceCount + allianceRelationCtrl:getAllyInviteNum()
  //   end
  //   local counterSysCount = allianceCounterSysCtrl:getNewPoint()
  //   local mineNum = allianceTreasureCtrl:getDigRewardCount()
  //   local helpNum = allianceTreasureCtrl:getHelpRewardCount()
  //   local playerMobilizationCtrl = gametop.playertop_:getModule("playerMobilizationCtrl")
  //   local hasActived = playerMobilizationCtrl:isHaveActived()
  //   local allianceHuntCtrl = gametop.playertop_:getModule("allianceHuntCtrl")
  //   local hasChallengeTimes = allianceHuntCtrl:getCheckChanllengeTimes()
  //   local activeNum = allianceMgr:hasJoinAlliance() and allianceActiveCtrl:getCanReceiveTaskNum() or 0
  //   allianceCount = allianceCount + mineNum + hasActived + hasChallengeTimes + helpNum + counterSysCount + activeNum
  //   local rewardsCount = SoraDGetCtrl("allianceScience"):getProsperityRewardsCount()
  //   if rewardsCount > 0 then
  //     allianceCount = allianceCount + 1
  //   end
  // end
  // if worldMapDefine.isInLegendLord() then
  //   local legendTeamCtrl = gametop.playertop_:getModule("legendTeamCtrl")
  //   local isTeamApproval = legendTeamCtrl:isTeamHasApproval()
  //   if isTeamApproval then
  //     allianceCount = allianceCount + 1
  //   end
  // elseif not worldMapDefine.isInRemains() then
  //   local allianceHelp = gametop.playertop_:getModule("allianceHelp")
  //   local allianceTerritoryAPI = include("allianceTerritoryAPI")
  //   allianceCount = allianceCount + #allianceHelp:getHelpList().otherhelplist
  //   allianceCount = allianceCount + allianceTerritoryAPI:getWellDestroyBuildingNum()
  // end
  // if allianceGuideCtrl:isShowEnterPoint() then
  //   allianceCount = allianceCount + 1
  // end
  // if worldMapDefine.isInAtlantis() then
  //   allianceCount = kingdomMapCtrl:getHallWarCount()
  // end
  // self:updateGreenTip({alliance = allianceCount})
}

void UIMainBottom::UpdateGreenPointRadianceWar(EventCustom* p_Event) {
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local num = kingdomMapCtrl:getHallWarCount(true)
  // local isRed = num > 0
  // self.btnRadianceWar:setVisible(isRed)
  // if isRed then
  //   self.txtRadianceWarNum:setString(num)
  //   if self.iconRadianceWar:isVisible() ~= isRed then
  //     self.iconRadianceWar:setVisible(isRed)
  //     self.Sprite_effect:setVisible(isRed)
  //     self.Sprite_effect:stopAllActions()
  //     local seq = cca.seq({
  //       cca.callFunc(function()
  //         self.Sprite_effect:setScale(1)
  //         self.Sprite_effect:setOpacity(0)
  //       end),
  //       cca.spawn({
  //         cca.scaleTo(0.2833333333333333, 1.18),
  //         cca.fadeTo(0.2833333333333333, 0.53)
  //       }),
  //       cca.spawn({
  //         cca.scaleTo(0.4666666666666667, 1.3),
  //         cca.fadeTo(0.4666666666666667, 0)
  //       }),
  //       cca.delay(0.5833333333333334)
  //     })
  //     self.Sprite_effect:runAction(cca.repeatForever(seq))
  //   end
  // else
  //   self.iconRadianceWar:setVisible(false)
  // end
  // local openWarning = SoraDConfigGet("Game:radianceWar:openWarning~bool", {byUID = true})
  // self:openRadianceWarning(openWarning and isRed)
  // self:sortBottomQuestBtns()
}

void UIMainBottom::ShowLongTimeUnlogin(EventCustom* p_Event) {
  // SoraDShowMsgBox(i18n("brightWar_text_155"), i18n("common_text_054"), nil, nil, {canNotClose = true})
}

void UIMainBottom::OpenRadianceWarning(bool p_IsOpen) {
  // if self.imgWarning:isVisible() then
  //   return
  // end
  // if not self.imgRadianceWarning then
  //   self.imgRadianceWarning = SoraDGetRedWarnning("frame_sheer_red_02.png")
  //   self.imgRadianceWarning:setColor(cc.c3b(255, 178, 63))
  // end
  // if self.imgRadianceWarning:isVisible() == bool then
  //   return
  // end
  // self.imgRadianceWarning:setVisible(bool)
  // if bool then
  //   if not self.radianceAction then
  //     self.imgRadianceWarning:stopAllActions()
  //     self.imgRadianceWarning:setOpacity(0.28)
  //     local actionRepeat = cca.repeatForever(cca.seq({
  //       cca.fadeTo(0.6333333333333333, 0.6),
  //       cca.fadeTo(0.7, 0.28)
  //     }))
  //     self.imgRadianceWarning:runAction(actionRepeat)
  //     self.radianceAction = true
  //   else
  //     self.imgRadianceWarning:setVisible(true)
  //   end
  // else
  //   self.imgRadianceWarning:setVisible(false)
  // end
}

void UIMainBottom::OpenWarning(bool p_IsOpen) {
  // if self.imgWarning:isVisible() == bool then
  //   return
  // end
  // self.imgWarning:setVisible(bool)
  // if bool then
  //   if not self.towerAction then
  //     self.imgWarning:stopAllActions()
  //     local actionTintTo = cca.fadeTo(1, 0)
  //     local actionTinBack = cca.fadeTo(1, 1)
  //     local actionDelay = cca.delay(0.8)
  //     local actionRepeat = cca.repeatForever(cca.seq({
  //       actionTintTo,
  //       actionTinBack,
  //       actionDelay
  //     }))
  //     self.imgWarning:runAction(actionRepeat)
  //     self.towerAction = true
  //   else
  //     self.imgWarning:setVisible(true)
  //   end
  //   if self.imgRadianceWarning and self.imgRadianceWarning:isVisible() then
  //     self.imgRadianceWarning:setVisible(false)
  //   end
  // else
  //   self.imgWarning:setVisible(false)
  // end
}

void UIMainBottom::StartRecordScreen(EventCustom* p_Event) {
  // self.btnReplay:setVisible(true)
  // self.timer = SoradCreateTimer(self, handler(self, self.recordTimeTick))
  // if device.platform == "ios" then
  //   local seq = cca.seq({
  //     cca.callFunc(function()
  //       self:updateBtnContainer()
  //     end)
  //   })
  //   self:runAction(seq)
  // else
  //   self:updateBtnContainer()
  // end
}

void UIMainBottom::RecordTimeTick(float p_Delta) {
  // gSDKDef.GAME_RECORD_TIME = gSDKDef.GAME_RECORD_TIME + 1
  // self.textVideo:setString(SoraDConvertSecondToString(gSDKDef.GAME_RECORD_TIME))
}

void UIMainBottom::OnExitOther() {
  // gChatMgrs:clean()
  // userSDKManager:setAudioTarget(nil)
  // local cityBuildFunction = include("cityBuildFunction")
  // cityBuildFunction:removeAll()
  // local cityBuildData = include("cityBuildData")
  // cityBuildData:removeAll()
  // if self.updateAllianceGreen ~= nil then
  //   cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.updateAllianceGreen)
  //   self.updateAllianceGreen = nil
  // end
}

void UIMainBottom::ShowWallFireEffect() {
  // local worldMapDefine = include("worldMapDefine")
  // local isInWar = worldMapDefine.isInPyramid()
  // local nodeWallTip = self.btnWallBurning:getChildByName("Node_wallTip")
  // local node_pyramid_effect = self.btnWallBurning:getChildByName("Node_pyramid_effect")
  // local node_normal_effect = self.btnWallBurning:getChildByName("Node_normal_effect")
  // local spriteBurn = self.btnWallBurning:getChildByName("icon_main_burn")
  // if isInWar then
  //   node_pyramid_effect:setVisible(true)
  //   node_normal_effect:setVisible(false)
  //   spriteBurn:setSpriteFrame("icon_main_burn.png")
  //   if not self.imgWallTipPop then
  //     nodeWallTip:setVisible(true)
  //     local imgWallTip = nodeWallTip:getChildByName("Image_wallTipBg")
  //     local seq = cca.seq({
  //       cca.scaleTo(0.5, 1),
  //       cca.delay(7),
  //       cca.scaleTo(0.5, 0)
  //     })
  //     nodeWallTip:stopAllActions()
  //     nodeWallTip:runAction(seq)
  //     self.imgWallTipPop = true
  //   end
  //   nodeWallTip:getChildByName("Text_wallTip"):setString(i18n("common_text_3201"))
  // else
  //   node_pyramid_effect:setVisible(false)
  //   node_normal_effect:setVisible(true)
  //   nodeWallTip:stopAllActions()
  //   nodeWallTip:setVisible(false)
  //   spriteBurn:setSpriteFrame("icon_main_burn_normal.png")
  // end
}

void UIMainBottom::HideWallFireEffect() {
  // local node_pyramid_effect = self.btnWallBurning:getChildByName("Node_pyramid_effect")
  // local node_normal_effect = self.btnWallBurning:getChildByName("Node_normal_effect")
  // node_pyramid_effect:setVisible(false)
  // node_normal_effect:setVisible(false)
}

void UIMainBottom::AddFirstJoinAllianceAnimation() {
  // local joinSprite = display.newSprite("#et_alliance_newjoin_01.png")
  // joinSprite:setPosition(cc.p(self.btnAlliance:getContentSize().width / 2, self.btnAlliance:getContentSize().height - 15))
  // joinSprite:setName("Sprite_join")
  // self.btnAlliance:addChild(joinSprite, 2)
  // local frames = display.newFrames("et_alliance_newjoin_%.2d.png", 1, 8)
  // local animation = display.newAnimation(frames, 0.125)
  // display.setAnimationCache("firstJoinAllianceGold", animation)
  // local seq = transition.sequence({
  //   cca.callFunc(function()
  //     joinSprite:setVisible(true)
  //   end),
  //   cca.callFunc(function()
  //     local animation = display.getAnimationCache("firstJoinAllianceGold")
  //     if animation then
  //       joinSprite:playAnimationOnce(animation)
  //     end
  //   end),
  //   cca.delay(1),
  //   cca.callFunc(function()
  //     joinSprite:setVisible(false)
  //   end),
  //   cca.delay(1)
  // })
  // joinSprite:runAction(cc.RepeatForever:create(seq))
}

void UIMainBottom::RemovefirstJoinAllianceAnimation(EventCustom* p_Event) {
  // display.removeAnimationCache("firstJoinAllianceGold")
  // if self.btnAlliance and self.btnAlliance:getChildByName("Sprite_join") then
  //   self.btnAlliance:removeChildByName("Sprite_join")
  // end
  // local allianceCtrl = gametop.playertop_:getModule("allianceCtrl")
  // allianceCtrl:resetAllianceInvitePopInfo()
  // self:initAllianceInvitePop()
  // userSDKManager.report2firebase("jointAlliance")
}

void UIMainBottom::ShowAllianceInWarEffect() {
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local hallWarCount = kingdomMapCtrl:getHallWarCount()
  // local fNode = self.btnAlliance:getParent():getChildByName("alliance_fightNode")
  // if hallWarCount > 0 then
  //   if not fNode then
  //     local fightNode = SoraDGetFightingEffect()
  //     fightNode:setName("alliance_fightNode")
  //     fightNode:setScale(0.5)
  //     fightNode:setPosition(cc.p(self.btnAlliance:getPositionX(), self.btnAlliance:getPositionY() - 30))
  //     fightNode:addTo(self.btnAlliance:getParent())
  //     local param = {
  //       [1] = {
  //         plist = "et_lmzdan_02.plist"
  //       },
  //       [2] = {
  //         plist = "et_lmzdan_01.plist",
  //         pos = {x = 0, y = 10}
  //       }
  //     }
  //     local et_node = SoraDCreateEffectNode(param)
  //     et_node:setScale(2)
  //     et_node:addTo(fightNode)
  //   end
  // elseif fNode then
  //   fNode:removeFromParent()
  // end
}

void UIMainBottom::GetEventCenterReturn(EventCustom* p_Event) {
  // self:updateEventcenter()
  // if type(redata.activityID) == "table" then
  //   for _, v in pairs(redata.activityID) do
  //     self:getEventCenterReturn_imp(v)
  //   end
  // elseif type(redata.activityID) == "number" then
  //   self:getEventCenterReturn_imp(redata.activityID)
  // end
}

void UIMainBottom::GetEventCenterReturn_Imp(EventCustom* p_Event) {
  // local activityID = data.activityID
  // local eventID = data.eventID
  // if gActivityTimeActivityID.LIMITED_DISCOUNT_ACTIVITY == activityID then
  //   self:updateItemsBtn()
  // elseif gActivityTimeActivityID.ALLIANCE_MOBILIZATION_ACTIVITY == activityID or gActivityTimeActivityID.ALLIANCE_MOBILIZATION_ACTIVITY == eventID
  // then
  //   self:updateGreenPointAlliance()
  // elseif gActivityTimeActivityID.COMMUNITY_CENTER_MAIN_UI == activityID then
  //   self:updateCommunityButton()
  // elseif activityID == gActivityCenterUIEnum.LEGEND_HEGEMON then
  //   self:btnHegemonBattleCheck()
  // elseif gActivityTimeActivityID.ENJOY_LOTTERY == activityID then
  //   self:updateEnjoyLotteryButton()
  // elseif gActivityTimeActivityID.SIX_YEAR_ACTIVITY == activityID then
  //   self:addSixYearActivityButton()
  // elseif gActivityTimeActivityID.PREDOWNLOAD_REWARD_ACTIVITY == activityID then
  //   self:checkPreDownload()
  //   self:checkPreDownloadStatus()
  // end
}

void UIMainBottom::UpdateItemsBtn() {
  
  bool l_ConquestWar = AllianceRead::Get()->GetPlayerConquestWarMigration(false);
  bool l_BattleGround = AllianceRead::Get()->GetPlayerBattleGroundMigration(false);
  auto l_Status = LimitTimeDiscountShopApi::Get()->GetActivityStatus();
  if(l_Status && !l_ConquestWar && !l_BattleGround) {
    ShowFireBorder();
  } else {
    ShowFireBorder(true);
  }
  
}

void UIMainBottom::UpdateBtnStatues(EventCustom* p_Event) {
  auto l_LordLevel = LordInfoCtrl::Get()->GetLordLevel();
  n_BtnSkill->getParent()->setVisible(l_LordLevel >= 4);
  if(n_BtnSkill->getParent()->isVisible()) {
    n_BtnManager->getParent()->setPositionY(204);
  } else {
    n_BtnManager->getParent()->setPositionY(122);
  }
}

void UIMainBottom::ShowFireBorder(bool p_IsRemove) {
  if(p_IsRemove) {
    n_NodeDiscountEffect->setVisible(false);
    return;
  }
  n_NodeDiscountEffect->setVisible(true);
  auto l_ImageDh = n_NodeDiscountEffect->getChildByName("Image_dh");
  GBase::DFadeInOut(l_ImageDh);
}

void UIMainBottom::SortBottomQuestBtns(EventCustom* p_Event) {
  if (m_ViewChangeType != EScene::City) {
    auto l_PosY = 240;
    if (WorldMapDefine::Get()->IsInLegendLord()) {
      l_PosY = 420;
    } else if (WorldMapDefine::Get()->IsInRemains()) {
      l_PosY = 620;
    } else if (WorldMapDefine::Get()->IsInRadiance()) {
      l_PosY = 520;
    } else if (WorldMapDefine::Get()->IsInAtlantis()) {
      auto l_WorldMap = dynamic_cast<WorldMapView*>(GBase::DCurrentSceneShowView("worldMapView"));
      if (l_WorldMap && l_WorldMap->GetBottomQuestBtnsOffsetY())
        l_PosY = l_WorldMap->GetBottomQuestBtnsOffsetY();
      else
        l_PosY = 600;
    }
    GVector<Node*> l_BtnTableName = {n_BtnWatchTower,
                                     // n_LuckyEffectNode,
                                    n_LuckyBlessNode, n_BtnLegendInvite, n_BtnRadianceWar};
    for (auto l_Node : l_BtnTableName) {
      if (l_Node && l_Node->isVisible()) {
        l_Node->setPosition(GBase::DFPoint(585, l_PosY, 640));
        l_PosY += 80;
      }
    }

  } else {
    auto l_BasePosy = 170;
    if (n_NodeQuestGuide && n_NodeQuestGuide->isVisible()) {
      l_BasePosy = 250;
    }

    auto l_BasePosx = 585;
    auto l_Posy = l_BasePosy;
    auto l_Posx = l_BasePosx;
    GVector<Node*> l_BtnTableName = 
    {
      n_BtnWallBurning, n_BtnWatchTower, 
      n_BtnHelpAll, n_BtnAccount, // n_LuckyEffectNode,
      n_LuckyBlessNode, n_BtnLegendInvite,
      n_BtnRadianceWar
    };

    auto l_HCount = 3;
    if (GDisplay::Get()->height < 960) {
      l_HCount = 2;
    } else if (GDisplay::Get()->height >= 1136) {
      l_HCount = 4;
    }

    auto l_Index = 1;
    for (auto l_Node : l_BtnTableName) {
      if (l_Node && l_Node->isVisible()) {
        auto l_H = l_Index % l_HCount == 0 ? l_HCount : l_Index % l_HCount;
        auto l_L = std::ceil(l_Index / l_HCount);
        auto l_RealPosy = l_Posy + (l_H - 1) * 80;
        l_Node->setPosition(GBase::DFPoint(l_Posx - (l_L - 1) * 90, l_RealPosy, 640));
        l_Index++;
      }
    }
  }
}

void UIMainBottom::InitHelpAllBtn(EventCustom* p_Event) {
  
  ui::Text *l_RedNum = nullptr;

  if(!n_BtnHelpAll) {
    auto l_Effect = GBase::DCreateCSBNode("UiParts/Panel/Building/View/Embassy/alliancehelpEffect.csb");
    n_NodeAreaLb->addChild(l_Effect);
    l_Effect->setVisible(false);
    l_Effect->setName("alliancehelpEffect");
    auto l_ImageBtn = GBase::GetChildByName<ui::ImageView *>(l_Effect, "Image_btn");
    l_ImageBtn->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnHelpAllClick, this));
    l_RedNum = GBase::GetChildByName<ui::Text *>(l_Effect, "Text_questNum");
    n_BtnHelpAll = l_Effect;
  }
  
  if(m_ViewChangeType != EScene::City){
    n_BtnHelpAll->setVisible(false);
    SortBottomQuestBtns(nullptr);
    return;
  }

  if(GuildHelp::Get()->IsCanHelp()){
    n_BtnHelpAll->setVisible(true);
    auto l_HelpCount = GuildHelp::Get()->GetHelpList().OtherHelpList.size();
    l_RedNum->setString(std::to_string(l_HelpCount));
  }else{
    n_BtnHelpAll->setVisible(false);
  }

  SortBottomQuestBtns(nullptr);
}

void UIMainBottom::BtnHelpAllClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local allianceHelp = SoraDGetCtrl("allianceHelp", gametop)
  //   allianceHelp:reqHelpAll()
  // end
}

void UIMainBottom::InitBattleOpenBtn() {
  // if not self.btnBattleOpen then
  //   self.btnBattleOpen = self.btnHegemonBattle:clone()
  //   self.btnBattleOpen:addTo(self.scroll_btn)
  //   self.btnBattleOpen:setVisible(false)
  //   self.btnBattleOpen:addTouchEventListener(handler(self, self.btnBattleOpenClick))
  //   self.sprBattleOpen = SoraDGetChildByName(self.btnBattleOpen, "icon_hegemon_playoff")
  //   self.sprBattleOpen:setScale(1)
  //   self.txtBattleOpen = SoraDGetChildByName(self.btnBattleOpen, "Text_playoffTime")
  //   self.btnBattleOpen.curIndex = 1
  //   self.btnBattleOpen.curTime = 0
  // end
  // if self.battleOpenHandle then
  //   SoraDManagerRemoveTimer(self, self.battleOpenHandle)
  //   self.battleOpenHandle = nil
  // end
  // if not self.battleOpenHandle then
  //   self.battleOpenHandle = SoraDCreateTimerEx(self, function(dt)
  //     self:refreshBattleOpenBtn(dt)
  //   end, 1)
  // end
  // self:refreshBattleOpenBtn()
}

// local battleOpenImageConfig = {
//   [1] = "icon_maincity_king.png",
//   [2] = "icon_maincity_conquestwar.png",
//   [3] = "icon_maincity_ruins.png",
//   [4] = "icon_maincity_devilvalley.png",
//   [5] = "icon_maincity_legendaryking.png",
//   [6] = "icon_shmc_small_905.png"
// }
// local battleOpenHandleConfig = {
//   [1] = function()
//     SoraDGotoWorldMapPoint(cc.p(gPlaceSetting[gPlaceId].x, gPlaceSetting[gPlaceId].y), true)
//   end,
//   [2] = function()
//     SoraDCreatePanel("kingdomBattleReadyView"):show()
//   end,
//   [3] = function()
//     SoraDCreatePanel("remainsWarActivity"):show()
//   end,
//   [4] = function()
//     SoraDCreatePanel("newTrialMainView"):show()
//   end,
//   [5] = function()
//     SoraDCreatePanel("legendaryKingActivity"):show()
//   end,
//   [6] = function()
//     SoraDCreatePanel("atlantisWarActivity"):show()
//   end
// }

void UIMainBottom::RefreshBattleOpenBtn(float p_Delta) {
  // local openList = {}
  // if worldMapDefine.isInWar() then
  //   if self.btnBattleOpen:isVisible() then
  //     self.btnBattleOpen.curIndex = 1
  //     self.btnBattleOpen.curTime = 0
  //     self.btnBattleOpen:setVisible(false)
  //     self:updateBtnContainer()
  //   end
  //   if self.battleOpenHandle then
  //     SoraDManagerRemoveTimer(self.btnBattleOpen, self.battleOpenHandle)
  //     self.battleOpenHandle = nil
  //   end
  //   return
  // end
  // local activityShowCtrl = SoraDGetCtrl("activityShowCtrl")
  // local queueCtrl = SoraDGetCtrl("queueCtrl")
  // local conquestWarCtrl = SoraDGetCtrl("conquestWarCtrl")
  // local remainsTeamCtrl = SoraDGetCtrl("remainsTeamCtrl")
  // local isInConquestWar = conquestWarCtrl:getConquestWarState() == gConquestWarState.OPENING
  // local warStatus = worldMapDefine.kingWarStatus
  // if not isInConquestWar and warStatus == gKingdomWarStatusType.inWar then
  //   local coolQueue = queueCtrl:queryQueue(gQueueTypeDef.world_resource_cool, gWorldResourceCoolQueueId)
  //   if coolQueue then
  //     local leftTime = coolQueue.timerNode.timer:getRemainTime()
  //     table.insert(openList, {ctype = 1, leftTime = leftTime})
  //   end
  // end
  // if isInConquestWar then
  //   local castle_limited = _G.CASTLE_LV16_LIMITED
  //   if castle_limited <= SoraDGetCastleLv() then
  //     local leftTime = conquestWarCtrl:getLeftTime()
  //     table.insert(openList, {ctype = 2, leftTime = leftTime})
  //   end
  // end
  // if remainsTeamCtrl:isActiveOpen() and (remainsTeamCtrl:isWarMatchBegin() or remainsTeamCtrl:isTeamCanInWar() and remainsTeamCtrl:isHasTeam())
  // then
  //   local castle_limited = _G.CASTLE_LV27_LIMITED
  //   if castle_limited <= SoraDGetCastleLv() then
  //     local leftTime = remainsTeamCtrl:getWarStatusTime()
  //     table.insert(openList, {ctype = 3, leftTime = leftTime})
  //   end
  // end
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.DEVIL_VALLEY_ACTIVITY) then
  //   local newTrialRead = include("newTrialRead")
  //   local castle_limited = newTrialRead.getCastleCondition(1) or 0
  //   if castle_limited <= SoraDGetCastleLv() then
  //     local _eventTime = activityShowCtrl:getTimeInfoByID(gActivityTimeActivityID.DEVIL_VALLEY_ACTIVITY)
  //     local leftTime = _eventTime.timerNode.timer:getRemainTime()
  //     table.insert(openList, {ctype = 4, leftTime = leftTime})
  //   end
  // end
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.LEGEND_LORD) then
  //   local param = activityShowCtrl:getParamByID(gActivityTimeActivityID.LEGEND_LORD)
  //   local legendLordState = param.curState
  //   if legendLordState == ACTIVITY_STATE.ACTIVE then
  //     local castle_limited = _G.CASTLE_LV50_LIMITED
  //     if castle_limited <= SoraDGetCastleLv() then
  //       local _eventTime = activityShowCtrl:getTimeInfoByID(gActivityTimeActivityID.LEGEND_LORD)
  //       local leftTime = _eventTime.timerNode.timer:getRemainTime()
  //       table.insert(openList, {ctype = 5, leftTime = leftTime})
  //     end
  //   end
  // end
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.ATLANTIS_WAR_ACTIVITY) then
  //   local atlantisState = SoraDGetCtrl("atlantisActivityCtrl"):getActivityCurState()
  //   if atlantisState == ATLANTIS_WAR_STATE.BATTLE then
  //     local _eventTime = SoraDGetCtrl("atlantisActivityCtrl"):getStageEndTime()
  //     table.insert(openList, {
  //       ctype = 6,
  //       leftTime = _eventTime - serviceFunctions.systemTime()
  //     })
  //   end
  // end
  // if #openList == 0 then
  //   if self.btnBattleOpen:isVisible() then
  //     self.btnBattleOpen.curIndex = 1
  //     self.btnBattleOpen.curTime = 0
  //     self.btnBattleOpen:setVisible(false)
  //     self:updateBtnContainer()
  //   end
  //   return
  // end
  // local data = openList[self.btnBattleOpen.curIndex]
  // if data then
  //   self.btnBattleOpen:setTag(data.ctype)
  //   local iconName = battleOpenImageConfig[data.ctype]
  //   self.sprBattleOpen:setSpriteFrame(iconName)
  //   self.sprBattleOpen:setScale(math.min(1, 70 / self.sprBattleOpen:getContentSize().height))
  //   self.txtBattleOpen:setString(SoraDConvertSecondToString(data.leftTime))
  //   if not self.btnBattleOpen:isVisible() then
  //     self.btnBattleOpen:setVisible(true)
  //     self:updateBtnContainer()
  //   end
  //   dt = dt or 0
  //   self.btnBattleOpen.curTime = self.btnBattleOpen.curTime + dt
  //   if self.btnBattleOpen.curTime >= 10 then
  //     self.btnBattleOpen.curTime = self.btnBattleOpen.curTime - 10
  //     self.btnBattleOpen.curIndex = self.btnBattleOpen.curIndex + 1
  //     if self.btnBattleOpen.curIndex > #openList then
  //       self.btnBattleOpen.curIndex = 1
  //     end
  //   end
  // else
  //   self.btnBattleOpen.curIndex = 1
  //   self:refreshBattleOpenBtn()
  // end
}

void UIMainBottom::BtnBattleOpenClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local tag = button:getTag()
  //   print("==tag==", tag)
  //   local func = battleOpenHandleConfig[tag]
  //   if func then
  //     func()
  //   end
  // end
}

void UIMainBottom::BtnPayBackClick(Ref* p_Sender, Widget::TouchEventType p_Type) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   uiManager:show("BackMoneyPopView")
  // end
}

ui::Button* UIMainBottom::GetBtnTarget(const GString& p_Name) {
  if(p_Name == "mail") 
    return n_BtnMail;
  else if(p_Name == "alliance")
    return n_BtnAlliance;
  else if(p_Name == "items")
    return n_BtnItems;
  else if(p_Name == "hero")
    return n_BtnHero;
  return nullptr;
}

void UIMainBottom::CheckRemainsWar() {
  if(WorldMapDefine::Get()->IsInRemains()) {
    n_LabelAllianceName->setString(Translate::i18n("common_text_047"));
  } else if(WorldMapDefine::Get()->IsInLegendLord()) {
    n_LabelAllianceName->setString(Translate::i18n("free_team_text_41"));
  } else if(WorldMapDefine::Get()->IsInAtlantis()) {
    n_LabelAllianceName->setString(Translate::i18n("atlantiswar_text_0139"));
  } else {
    n_LabelAllianceName->setString(Translate::i18n("common_text_069"));
  }
}

void UIMainBottom::MsgInvitedInfoLegend(EventCustom* p_Event) {
  // local legendTeamCtrl = gametop.playertop_:getModule("legendTeamCtrl")
  // local hasInvite = legendTeamCtrl:isHasInvitedInfo()
  // self.btnLegendInvite:setVisible(hasInvite)
  // if hasInvite then
  //   self.iconLegendInvite:setVisible(true)
  //   local inviteList = legendTeamCtrl:getInvitedInfo() or {}
  //   self.txtLegendInviteNum:setString(#inviteList)
  // else
  //   self.iconLegendInvite:setVisible(false)
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::OpenReportMail(EventCustom* p_Event) {
  // dump(data, "openReportMail")
  // SoraDCloseLoading()
  // if data.mail == nil then
  //   local msgNotice = include("msgNotice")
  //   msgNotice.notice("common_text_1382")
  //   return
  // end
  // local panel = SoraDCreatePanel("mailItemDetailView")
  // panel:show()
  // panel:hideRightAndLeftBtn()
  // panel:initWithData(data.mail, "key", data.senderId)
}

void UIMainBottom::CheckPreDownloadStatus(EventCustom* p_Event) {
  // local preDownloadUtil = include("preDownloadUtil")
  // local isShow = preDownloadUtil:isShowPreDownloadWidget()
  // if isShow then
  //   self.nodePreDownload:setVisible(true)
  //   self.nodePreDownload:initData()
  // else
  //   self.nodePreDownload:setVisible(false)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::CheckPreDownload(EventCustom* p_Event) {
  // local preDownloadUtil = include("preDownloadUtil")
  // preDownloadUtil.checkPreDownloadAutoStart()
}

void UIMainBottom::OnPreDownloadSuc(EventCustom* p_Event) {
  // local preDownloadUtil = include("preDownloadUtil")
  // preDownloadUtil.checkSendPredownloadOk()
}