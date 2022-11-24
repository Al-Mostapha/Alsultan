#include "UIMainBottom.h"
#include "Module/UI/Animations/UIAnimationCollectItems.h"

void UIMainBottom::Ctor(){
  // cityBuildData:removeMessageListener()
  // cityBuildData:registerMessageListener()
  // userSDKManager.setAudioTarget(chatAudioMgr)
  // self.Node_LOD = SoraDGetChildByName(self, "Node_LOD")
  n_NodeLOD = GBase::GetChildByName<Node *>(m_Panel, "Node_LOD");
  n_NodeAreaRb = GBase::GetChildByName<Node *>(n_NodeLOD, "Node_area_rb");
  n_NodeAreaLb = GBase::GetChildByName<Node *>(n_NodeLOD, "Node_area_lb");
  n_NodeAreaB = GBase::GetChildByName<Node *>(m_Panel, "Node_area_b");
  auto *l_AnimationCollectItems = UIAnimationCollectItems::Create();
  n_NodeAreaB->addChild(l_AnimationCollectItems, 10);
  l_AnimationCollectItems->setName("animationCollectItems");
  m_ViewChangeType = EScene::City;
  InitGroup();
  // self.uiBg = SoraDGetChildByName(self, "UI_Label_BG")
  n_UiBg = GBase::GetChildByName<Sprite *>(m_Panel, "UI_Label_BG");
  // self.uiBgLeft = SoraDGetChildByName(self, "Image_decor_left")
  n_UiBgLeft = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Image_decor_left");
  // self.uiBgLeft:setVisible(IsArClient)
  n_UiBgLeft->setVisible(GBase::Const::Get()->IsArClient);
  // self.uiBgRight = SoraDGetChildByName(self, "Image_decor_right")
  n_UiBgRight = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Image_decor_right");
  // self.uiBgRight:setVisible(IsArClient)
  n_UiBgRight->setVisible(GBase::Const::Get()->IsArClient);
  // self.Node_style_bg = SoraDGetChildByName(self, "Node_style_bg")
  n_NodeStyleBg = GBase::GetChildByName<Node *>(m_Panel, "Node_style_bg");
  // self.Node_style_top = SoraDGetChildByName(self, "Node_style_top")
  n_NodeStyleTop = GBase::GetChildByName<Node *>(m_Panel, "Node_style_top");
  // self:initStyle()
  InitStyle();
  // self.tipItems = SoraDGetChildByName(self, "Sprite_items")
  n_TipItems = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Sprite_items");
  // self.tipAlliance = SoraDGetChildByName(self, "Sprite_alliance")
  n_TipAlliance = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Sprite_alliance");

  // self.tipMail = SoraDGetChildByName(self, "Sprite_mail")
  n_TipMail = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Sprite_mail");
  // self.tipHero = SoraDGetChildByName(self, "Sprite_hero")
  n_TipHero = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Sprite_hero");
  // self.tipHero:setVisible(false)
  n_TipHero->setVisible(false);
  n_TipHeroCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_hero"));
  // self.tipHeroCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipMailCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_mail"));
  // self.tipMailCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipAllianceCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_alliance"));
  // self.tipAllianceCount:setGroupID(mainUIDef.newGroupID.text)
  n_TipItemsCount = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_items"));
  // self.tipItemsCount:setGroupID(mainUIDef.newGroupID.text)
  // self.imgWarning = SoraDGetRedWarnning()
  n_ChatMainUIView = GBase::DGetExtendChildFromCCSByName<UIChatMainUiView>(m_Panel, "CCS_chatMainUIView_Node");
  n_ChatMainUIView->InitWithData();
  n_FrameWorldCity = GBase::GetChildByName<Sprite *>(m_Panel, "frame_btn_worldCity");
  n_ButtonWorldCity = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_worldCity");
  n_ImgWorldCity = GBase::GetChildByName<ui::ImageView *>(m_Panel, "img_worldCity");
  if (n_ImgWorldCity) 
    n_ButtonWorldCity->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnWorldCityClick, this));
  // self.nodeQuestGuide = SoraDGetExtendChildFromCCSByName(self, "CCS_questGuideNode_quest")
  // self.btnAccount = SoraDGetChildByName(self, "Button_account")
  n_BtnAccount = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_account");
  // self.btnAccount:setVisible(false)
  n_BtnAccount->setVisible(false);
  // self.iconAccount = SoraDGetChildByName(self.btnAccount, "icon_set_account")
  n_IconAccount = GBase::GetChildByName<Sprite *>(n_BtnAccount, "icon_set_account");
  // self.redPointAccount = SoraDGetChildByName(self.btnAccount, "Sprite_redPoint")
  n_RedPointAccount = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_redPoint");
  // self.btnPyramidBattle = SoraDGetChildByName(self, "Button_pyramidBattle")
  n_BtnPyramidBattle = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_pyramidBattle");
  // self.spriteBattleTimeBg = SoraDGetChildByName(self, "Sprite_battleTimeBg")
  n_SpriteBattleTimeBg = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_battleTimeBg");
  n_TxtPyramidBattleTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_battleTime"));
  // self.btnPyramidPlayoffs = SoraDGetChildByName(self, "Button_pyramidPlayoffs")
  n_BtnPyramidPlayoffs = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_pyramidPlayoffs");
  // self.imgPyramidPlayoffsBg = SoraDGetChildByName(self.btnPyramidPlayoffs, "Sprite_playoffBg")
  n_ImgPyramidPlayoffsBg = GBase::GetChildByName<Sprite *>(n_BtnPyramidPlayoffs, "Sprite_playoffBg");
  // self.txtPyramidPlayoffsTime = SoraDGetChildByName(self, "Text_playoffTime")
  n_TxtPyramidPlayoffsTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_playoffTime"));
  // self.btnCityUnlock = SoraDGetChildByName(self, "Button_cityUnlockBuild")
  n_BtnCityUnlock = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_cityUnlockBuild");
  // self.spriteCityUnlock = SoraDGetChildByName(self.btnCityUnlock, "Sprite_unlock")
  n_SpriteCityUnlock = GBase::GetChildByName<Sprite *>(n_BtnCityUnlock, "Sprite_unlock");
  // self.txtCityUnlock = SoraDGetChildByName(self.btnCityUnlock, "Text_unlock")
  n_TxtCityUnlock = GBase::GetChildByName<ui::Text *>(n_BtnCityUnlock, "Text_unlock");
  // self.btnNewPlayerBuff = SoraDGetChildByName(self, "Button_newPlayerBuff")
  n_BtnNewPlayerBuff = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_newPlayerBuff");
  // self.textNewPlayer = SoraDGetChildByName(self.btnNewPlayerBuff, "Text_newPlayer")
  n_TextNewPlayer = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnNewPlayerBuff, "Text_newPlayer"));
  // self.btnPrinceGiftNewBuff = SoraDGetChildByName(self, "Button_princeGiftNewBuff")
  n_BtnPrinceGiftNewBuff = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_princeGiftNewBuff");
  // self.textPrinceGiftNew = SoraDGetChildByName(self.btnPrinceGiftNewBuff, "Text_princeGiftNewBuff")
  n_TextPrinceGiftNew = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnPrinceGiftNewBuff, "Text_princeGiftNewBuff"));
  // self.Sprite_princeGiftNewBuff = SoraDGetChildByName(self.btnPrinceGiftNewBuff, "Sprite_princeGiftNewBuff")
  n_SpritePrinceGiftNewBuff = GBase::GetChildByName<Sprite *>(n_BtnPrinceGiftNewBuff, "Sprite_princeGiftNewBuff");
  // self.Sprite_princeGiftNewBuff:setScale(0.5)
  n_SpritePrinceGiftNewBuff->setScale(0.5);
  // self.btnPrinceGiftBuff = SoraDGetChildByName(self, "Button_princeGiftBuff")
  n_BtnPrinceGiftBuff = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_princeGiftBuff");
  // self.textPrinceGift = SoraDGetChildByName(self.btnPrinceGiftBuff, "Text_princeGiftBuff")
  n_TextPrinceGift = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnPrinceGiftBuff, "Text_princeGiftBuff"));
  // self.Sprite_princeGiftBuff = SoraDGetChildByName(self.btnPrinceGiftBuff, "Sprite_princeGiftBuff")
  n_SpritePrinceGiftBuff = GBase::GetChildByName<Sprite *>(n_BtnPrinceGiftBuff, "Sprite_princeGiftBuff");
  // self.Sprite_princeGiftBuff:setScale(0.5)
  n_SpritePrinceGiftBuff->setScale(0.5);
  // self.btnSultansWelBack = SoraDGetChildByName(self, "Button_sultanWelBack")
  n_BtnSultansWelBack = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_sultanWelBack");
  // self.textWelBack = SoraDGetChildByName(self.btnSultansWelBack, "Text_welBack")
  n_TextWelBack = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnSultansWelBack, "Text_welBack"));
  // self.btnHero = SoraDGetChildByName(self, "Button_hero")
  n_BtnHero = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_hero");
  // self.iconBtnHero = SoraDGetChildByName(self.btnHero, "icon_hero")
  n_IconBtnHero = GBase::GetChildByName<ui::ImageView *>(n_BtnHero, "icon_hero");
  // self.btnItems = SoraDGetChildByName(self, "Button_items")
  n_BtnItems = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_items");
  // self.iconBtnItems = SoraDGetChildByName(self.btnItems, "icon_items")
  n_IconBtnItems = GBase::GetChildByName<ui::ImageView *>(n_BtnItems, "icon_items");
  // self.itemNewIcon = SoraDGetChildByName(self.btnItems, "icon_new")
  n_ItemNewIcon = GBase::GetChildByName<Sprite *>(n_BtnItems, "icon_new");
  // self.Node_discountEffect = SoraDGetChildByName(self.btnItems, "Node_discountEffect")
  n_NodeDiscountEffect = GBase::GetChildByName<Node *>(n_BtnItems, "Node_discountEffect");
  // self.btnMail = SoraDGetChildByName(self, "Button_mail")
  n_BtnMail = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_mail");
  // self.iconBtnMail = SoraDGetChildByName(self.btnMail, "icon_mail")
  n_IconBtnMail = GBase::GetChildByName<ui::ImageView *>(n_BtnMail, "icon_mail");
  // self.btnAlliance = SoraDGetChildByName(self, "Button_alliance")
  n_BtnAlliance = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_alliance");
  // self.iconBtnAlliance = SoraDGetChildByName(self.btnAlliance, "icon_alliance")
  n_IconBtnAlliance = GBase::GetChildByName<ui::ImageView *>(n_BtnAlliance, "icon_alliance");
  // self.btnWatchTower = SoraDGetChildByName(self, "Button_watchTower")
  n_BtnWatchTower = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_watchTower");
  // self.iconAlarm = SoraDGetChildByName(self, "icon_building_alarm")
  n_IconAlarm = GBase::GetChildByName<Sprite *>(m_Panel, "icon_building_alarm");
  // self.btnWallBurning = SoraDGetChildByName(self, "Button_wallBurnning")
  n_BtnWallBurning = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_wallBurnning");
  // self.btnWallBurning:setVisible(false)
  n_BtnWallBurning->setVisible(INIT_FALSE);
  // self.btnKingdomManager = SoraDGetChildByName(self, "Button_kingdomManager")
  n_BtnKingdomManager = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_kingdomManager");
  // self.btnKingdomManagerSprite = SoraDGetChildByName(self.btnKingdomManager, "Sprite_crown")
  n_BtnKingdomManagerSprite = GBase::GetChildByName<Sprite *>(n_BtnKingdomManager, "Sprite_crown");
  // self.spKingdomManagerTimeBg = SoraDGetChildByName(self.btnKingdomManager, "Sprite_giftTimeBg")
  n_SpKingdomManagerTimeBg = GBase::GetChildByName<Sprite *>(n_BtnKingdomManager, "Sprite_giftTimeBg");
  // self.txtKingdomManagerTime = SoraDGetChildByName(self.btnKingdomManager, "Text_giftTime")
  n_TxtKingdomManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnKingdomManager, "Text_giftTime"));
  // self.btnLegendKingManager = SoraDGetChildByName(self, "Button_legendKingManager")
  n_BtnLegendKingManager = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_legendKingManager");
  // self.btnLegendKingManagerSprite = SoraDGetChildByName(self.btnLegendKingManager, "Sprite_crown")
  n_BtnLegendKingManagerSprite = GBase::GetChildByName<Sprite *>(n_BtnLegendKingManager, "Sprite_crown");
  // self.spLegendKingManagerTimeBg = SoraDGetChildByName(self.btnLegendKingManager, "Sprite_giftTimeBg")
  n_SpLegendKingManagerTimeBg = GBase::GetChildByName<Sprite *>(n_BtnLegendKingManager, "Sprite_giftTimeBg");
  // self.txtLegendKingManagerTime = SoraDGetChildByName(self.btnLegendKingManager, "Text_giftTime")
  n_TxtLegendKingManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnLegendKingManager, "Text_giftTime"));
  // self.btnLegendInvite = SoraDGetChildByName(self, "Button_legendInvite")
  n_BtnLegendInvite = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_legendInvite");
  // self.iconLegendInvite = SoraDGetChildByName(self.btnLegendInvite, "icon_legend_red")
  n_IconLegendInvite = GBase::GetChildByName<Sprite *>(n_BtnLegendInvite, "icon_legend_red");
  // self.iconLegendInvite:setVisible(false)
  n_IconLegendInvite->setVisible(INIT_FALSE);
  // self.txtLegendInviteNum = SoraDGetChildByName(self, "Text_legendInviteNum")
  n_TxtLegendInviteNum = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_legendInviteNum"));
  // self.btnRadianceWar = SoraDGetChildByName(self, "Button_radiance")
  n_BtnRadianceWar = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_radiance");
  // self.iconRadianceWar = SoraDGetChildByName(self.btnRadianceWar, "icon_radiance_red")
  n_IconRadianceWar = GBase::GetChildByName<Sprite *>(n_BtnRadianceWar, "icon_radiance_red");
  // self.iconRadianceWar:setVisible(false)
  n_IconRadianceWar->setVisible(INIT_FALSE);
  // self.Sprite_effect = SoraDGetChildByName(self.btnRadianceWar, "Sprite_effect")
  n_SpriteEffect = GBase::GetChildByName<Sprite *>(n_BtnRadianceWar, "Sprite_effect");
  // self.Sprite_effect:setVisible(false)
  n_SpriteEffect->setVisible(INIT_FALSE);
  // self.txtRadianceWarNum = SoraDGetChildByName(self, "Text_radianceNum")
  n_TxtRadianceWarNum = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_radianceNum"));
  // self.btnHegemonManager = SoraDGetChildByName(self, "Button_hegemonManager")
  n_BtnHegemonManager = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_hegemonManager");
  // self.btnHegemonManagerSprite = SoraDGetChildByName(self.btnHegemonManager, "Sprite_crown")
  n_BtnHegemonManagerSprite = GBase::GetChildByName<Sprite *>(n_BtnHegemonManager, "Sprite_crown");
  // self.spHegemonManagerTimeBg = SoraDGetChildByName(self.btnHegemonManager, "Sprite_giftTimeBg")
  n_SpHegemonManagerTimeBg = GBase::GetChildByName<Sprite *>(n_BtnHegemonManager, "Sprite_giftTimeBg");
  // self.txtHegemonManagerTime = SoraDGetChildByName(self.btnHegemonManager, "Text_giftTime")
  n_TxtHegemonManagerTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnHegemonManager, "Text_giftTime"));
  // self.btnHegemonBattle = SoraDGetChildByName(self, "Button_hegemonBattle")
  n_BtnHegemonBattle = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_hegemonBattle");
  // self.btnHegemonBattleSprite = SoraDGetChildByName(self.btnHegemonBattle, "icon_hegemon_playoff")
  n_BtnHegemonBattleSprite = GBase::GetChildByName<Sprite *>(n_BtnHegemonBattle, "icon_hegemon_playoff");
  // self.spHegemonBattleTimeBg = SoraDGetChildByName(self.btnHegemonBattle, "Sprite_playoffBg")
  n_SpHegemonBattleTimeBg = GBase::GetChildByName<Sprite *>(n_BtnHegemonBattle, "Sprite_playoffBg");
  // self.txtHegemonBattleTime = SoraDGetChildByName(self.btnHegemonBattle, "Text_playoffTime")
  n_TxtHegemonBattleTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<ui::Text *>(n_BtnHegemonBattle, "Text_playoffTime"));
  // self.btnTrainPower = SoraDGetChildByName(self, "Button_trainPower")
  n_BtnTrainPower = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_trainPower");
  // self.Text_trainPower = SoraDGetChildByName(self.btnTrainPower, "Text_trainPower")
  n_TextTrainPower = GBase::GetChildByName<ui::Text *>(n_BtnTrainPower, "Text_trainPower");
  // self.Text_trainPower:setString(i18n("activity_name_9001300"))
  n_TextTrainPower->setString(Translate::i18n("activity_name_9001300"));
  // self.Red_trainPower = SoraDGetChildByName(self.btnTrainPower, "icon_red")
  n_RedTrainPower = GBase::GetChildByName<Sprite *>(n_BtnTrainPower, "icon_red");
  // self.Num_trainPower = SoraDGetChildByName(self.Red_trainPower, "Text_btnNum")
  n_NumTrainPower = GBase::GetChildByName<ui::Text *>(n_RedTrainPower, "Text_btnNum");
  // self.Red_trainPower:setVisible(false)
  n_RedTrainPower->setVisible(INIT_FALSE);
  // self.Text_trainPower:setFontSize(16)
  n_TextTrainPower->setFontSize(16);
  // self.btnNeckLaceRank = SoraDGetChildByName(self, "Button_necklaceRank")
  n_BtnNeckLaceRank = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_necklaceRank");
  // self.btnNeckLaceRankSprite = SoraDGetChildByName(self.btnNeckLaceRank, "icon_hegemon_playoff")
  n_BtnNeckLaceRankSprite = GBase::GetChildByName<Sprite *>(n_BtnNeckLaceRank, "icon_hegemon_playoff");
  // self.btnNeckLaceRankBg = SoraDGetChildByName(self.btnNeckLaceRank, "Sprite_playoffBg")
  n_BtnNeckLaceRankBg = GBase::GetChildByName<Sprite *>(n_BtnNeckLaceRank, "Sprite_playoffBg");
  // self.btnNeckLaceRankText = SoraDGetChildByName(self.btnNeckLaceRank, "Text_playoffTime")
  n_BtnNeckLaceRankText = GBase::GetChildByName<ui::Text *>(n_BtnNeckLaceRank, "Text_playoffTime");
  // self.btnRomanSoul = SoraDGetChildByName(self, "Button_romanSoul")
  n_BtnRomanSoul = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_romanSoul");
  // self.labelAllianceName = self:exchangeGroupText(SoraDGetChildByName(self, "Text_allianceName"), 25)
  n_LabelAllianceName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_allianceName"), 25);
  // self.labelAllianceName:setGroupID(mainUIDef.newGroupID.text)
  // self.labelHeroName = self:exchangeGroupText(SoraDGetChildByName(self, "Text_heroName"), 25)
  n_LabelHeroName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_heroName"), 25);
  // self.labelHeroName:setGroupID(mainUIDef.newGroupID.text)
  // self.labelBagName = self:exchangeGroupText(SoraDGetChildByName(self, "Text_bagName"), 25)
  n_LabelBagName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_bagName"), 25);
  // self.labelBagName:setGroupID(mainUIDef.newGroupID.text)
  // self.labelMailName = self:exchangeGroupText(SoraDGetChildByName(self, "Text_mailName"), 25)
  n_LabelMailName = ExchangeGroupText(GBase::GetChildByName<ui::Text *>(m_Panel, "Text_mailName"), 25);
  // self.labelMailName:setGroupID(mainUIDef.newGroupID.text)
  // self.labelAllianceName:setString(i18n("common_text_069"))
  n_LabelAllianceName->setString(Translate::i18n("common_text_069"));
  // self.labelHeroName:setString(i18n("common_name_01"))
  n_LabBtnNum->setString(Translate::i18n("common_name_01"));
  // self.labelBagName:setString(i18n("common_text_308"))
  n_LabelBagName->setString(Translate::i18n("common_text_308"));
  // self.labelMailName:setString(i18n("mail_text_25"))
  n_LabelMailName->setString(Translate::i18n("mail_text_25"));
  // self.btnSkill = SoraDGetChildByName(self, "Button_skill")
  n_BtnSkill = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_skill");
  // self.btnSkill:addTouchEventListener(handler(self, self.OnSkillClick))
  n_BtnSkill->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnSkillClick, this));
  // self.btnReplay = SoraDGetChildByName(self, "Button_replay")
  n_BtnReplay = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_replay");
  // self.bgTextVideo = SoraDGetChildByName(self, "bg_text_video")
  n_BgTextVideo = GBase::GetChildByName<Sprite *>(m_Panel, "bg_text_video");
  // self.btnReplay:addTouchEventListener(handler(self, self.OnReplayClick))
  n_BtnReplay->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnReplayClick, this));
  if(SDKManager::Get()->IsRecording())
  {
    n_BtnReplay->setVisible(true);
    m_Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIMainBottom::RecordTimeTick, this));
  }
  else
  {
    n_BtnReplay->setVisible(INIT_FALSE);
    m_Timer = nullptr;
  }
  // self.textVideo = SoraDGetChildByName(self, "text_video")
  n_TextVideo = GBase::GetChildByName<ui::Text *>(m_Panel, "text_video");
  // self.frame_main_guide = SoraDGetChildByName(self, "frame_main_guide")
  n_FrameMainGuide = GBase::GetChildByName<Sprite *>(m_Panel, "frame_main_guide");
  // self.btnHero:addTouchEventListener(handler(self, self.OnBottomClick))
  n_BtnHero->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  // self.btnItems:addTouchEventListener(handler(self, self.OnBottomClick))
  n_BtnItems->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  // self.btnMail:addTouchEventListener(handler(self, self.OnBottomClick))
  n_BtnMail->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  // self.btnAlliance:addTouchEventListener(handler(self, self.OnBottomClick))
  n_BtnAlliance->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnBottomClick, this));
  // self.btnWatchTower:addTouchEventListener(handler(self, self.btnWatchTowerClick))
  n_BtnWatchTower->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnWatchTowerClick, this));
  // self.btnWallBurning:addTouchEventListener(handler(self, self.btnWallBurningClick))
  n_BtnWallBurning->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnWallBurningClick, this));
  // self.btnKingdomManager:addTouchEventListener(handler(self, self.btnKingdomManagerClick))
  n_BtnKingdomManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnKingdomManagerClick, this));
  // self.btnLegendKingManager:addTouchEventListener(handler(self, self.btnLegendKingManagerClick))
  n_BtnLegendKingManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnLegendKingManagerClick, this));
  // self.btnLegendInvite:addTouchEventListener(handler(self, self.btnLegendInviteClick))
  n_BtnLegendInvite->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnLegendInviteClick, this));
  // self.btnRadianceWar:addTouchEventListener(handler(self, self.btnRadianceWarClick))
  n_BtnRadianceWar->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnRadianceWarClick, this));
  // self.btnHegemonManager:addTouchEventListener(handler(self, self.btnHegemonManagerClick))
  n_BtnHegemonManager->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnHegemonManagerClick, this));
  // self.btnHegemonBattle:addTouchEventListener(handler(self, self.btnHegemonBattleClick))
  n_BtnHegemonBattle->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnHegemonBattleClick, this));
  // self.btnTrainPower:addTouchEventListener(handler(self, self.btnTrainPowerClick))
  n_BtnTrainPower->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnTrainPowerClick, this));
  // self.btnRomanSoul:addTouchEventListener(handler(self, self.btnRomanSoulClick))
  n_BtnRomanSoul->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnRomanSoulClick, this));
  // self.btnPyramidBattle:addTouchEventListener(handler(self, self.btnPyramidBattleClick))
  n_BtnPyramidBattle->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPyramidBattleClick, this));
  // self.btnPyramidPlayoffs:addTouchEventListener(handler(self, self.btnPyramidPlayoffsClick))
  n_BtnPyramidPlayoffs->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPyramidPlayoffsClick, this));
  // self.btnCityUnlock:addTouchEventListener(handler(self, self.btnCityUnlockClick))
  n_BtnCityUnlock->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnCityUnlockClick, this));
  // self.btnNewPlayerBuff:addTouchEventListener(handler(self, self.btnNewPlayerBuffClick))
  n_BtnNewPlayerBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnNewPlayerBuffClick, this));
  // self.btnSultansWelBack:addTouchEventListener(handler(self, self.OnSultansBackWelClick))
  n_BtnSultansWelBack->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::OnSultansBackWelClick, this));
  // self.btnAccount:addTouchEventListener(handler(self, self.btnAccountClick))
  n_BtnAccount->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnAccountClick, this));
  // self.btnNeckLaceRank:addTouchEventListener(handler(self, self.btnNeckLaceRankClick))
  n_BtnNeckLaceRank->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnNeckLaceRankClick, this));
  // self.btnPrinceGiftNewBuff:addTouchEventListener(handler(self, self.btnPrinceGiftNewBuffClick))
  n_BtnPrinceGiftNewBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPrinceGiftNewBuffClick, this));
  // self.btnPrinceGiftBuff:addTouchEventListener(handler(self, self.btnPrinceGiftBuffClick))
  n_BtnPrinceGiftBuff->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnPrinceGiftBuffClick, this));
  // self:initGreenPoint()
  InitGreenPoint();
  // self:showAllianceInWarEffect()
  ShowAllianceInWarEffect();
  // self.nodePreDownload = SoraDGetExtendChildFromCCSByName(self, "CCS_preDownloadMainWidget_pre")
  n_NodePreDownload = GBase::DGetExtendChildFromCCSByName<UIPreDownloadMainWidget>(m_Panel, "CCS_preDownloadMainWidget_pre");
  // self.nodeBottomBtn = SoraDGetChildByName(self, "Bottom_Node_btn")
  n_NodeBottomBtn = GBase::GetChildByName<Node *>(m_Panel, "Bottom_Node_btn");
  // self.btnManager = SoraDGetChildByName(self, "Bottom_Image_btnBG")
  n_BtnManager = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Bottom_Image_btnBG");
  // self.btnManager:setTouchEnabled(true)
  n_BtnManager->setTouchEnabled(true);
  // self.scroll_btn = SoraDGetChildByName(self, "Bottom_Size_ScrollView_btn")
  n_ScrollBtn = GBase::GetChildByName<ui::ScrollView *>(m_Panel, "Bottom_Size_ScrollView_btn");
  // self.scroll_btn:setTouchEnabled(false)
  n_ScrollBtn->setTouchEnabled(false);
  // local img_btnRound = SoraDGetChildByName(self.btnManager, "Image_btn_round")
  auto l_ImgBtnRound = GBase::GetChildByName<ui::ImageView *>(n_BtnManager, "Image_btn_round");
  // self.btnSwitch = SoraDGetChildByName(self.btnManager, "Button_switch")
  n_BtnSwitch = GBase::GetChildByName<ui::Button *>(n_BtnManager, "Button_switch");
  // self.node_arrow = SoraDGetChildByName(self.btnManager, "Node_arrow")
  n_NodeArrow = GBase::GetChildByName<Node *>(n_BtnManager, "Node_arrow");
  // self.node_arrow:setGroupAuto(true)
  // self.iconRed = SoraDGetChildByName(self.btnSwitch, "icon_red")
  n_IconRed = GBase::GetChildByName<Sprite *>(n_BtnSwitch, "icon_red");
  // self.iconRed:setVisible(false)
  n_IconRed->setVisible(INIT_FALSE);
  // self.labBtnNum = SoraDGetChildByName(self.btnSwitch, "Text_btnNum")
  n_LabBtnNum = GBase::GetChildByName<ui::Text *>(n_BtnSwitch, "Text_btnNum");
  // self.btnSwitch:addTouchEventListener(handler(self, self.btnSwitchClick))
  n_BtnSwitch->addTouchEventListener(CC_CALLBACK_2(UIMainBottom::BtnSwitchClick, this));
  // self.btnSwitchType = 1
  m_BtnSwitchType = 1;
  // local effectMainUITop = include("effectMainUITop")
  // self.btnLuckyRecharge = effectMainUITop.luckyRecharge()
  // self.btnLuckyRecharge:addTo(self.scroll_btn)
  // self.btnLuckyRecharge:setPosition(cc.p(35, 395))
  // self.btnLuckyRecharge:addTouchEventListener(handler(self, self.OnLuckyReachergeClick))
  // self.btnLuckyRecharge:setVisible(false)
  // self:updateBtnLuckyRecharge()
  // local gametop = gModuleMgr.getObject("gametop")
  // local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  // local sourceKid = lordInfoCtrl:getLordInfo().base.sourceKid
  // if sourceKid and sourceKid == 0 then
  //   self:addGoldPackageButton()
  // end
  // local hasGift, hasBuy, hasGot = self:getMonthlyCard()
  // if hasGift and not hasBuy and not IsArClient then
  //   self:addMonthCardButton()
  // end
  // self:addCrazyTrioButton()
  // self:addLostRuinsButton()
  // self:addWindTowerButton()
  // self:addSnowWolfLostButton()
  // self:updateCommunityButton()
  // self:updateEnjoyLotteryButton()
  // self:addKOChoiceButton()
  // self:addSixYearActivityButton()
  // self:addHarvestSeasonButton()
  // self:addPrinceGiftNewBuffButton()
  // self:addPrinceGiftBuffButton()
  // self:msgUpdateMailIconNumber()
  // self:checkWatchTower()
  // self:checkRomanSoul()
  // self:btnKingdomManagerCheck()
  // self:btnLegendKingManagerCheck()
  // self:btnHegemonManagerCheck()
  // self:btnTrainPowerManagerCheck()
  // self:btnPyramidBattleCheck()
  // self:btnHegemonBattleCheck()
  // self:btnCityUnlockCheck()
  // self:btnNewPlayerBuffCheck()
  // self:btnSultansBackWelCheck()
  // self:showLuckyBless()
  // self:initAccountBind()
  // self:updateBtnContainer()
  // self:updateItemsBtn()
  // self:updateBtnStatues()
  // self:req4AllianceInviteData()
  // self:updateNewTrialUI()
  CreateExpostulationTimer();
  // self:checkRemainsWar()
  // self:msgInvitedInfo_legend()
  // self:updateGreenPointRadianceWar()
  // self:initHelpAllBtn()
  // self:initBattleOpenBtn()
  // self:checkPreDownload()
  // self:checkPreDownloadStatus()
  // self:btnPayBackCheck()
  // local questionnaireCtrl = SoraDGetCtrl("questionnaireCtrl")
  // questionnaireCtrl:reqGetQuestData()
  // local raidersLostArkCtrl = SoraDGetCtrl("raidersLostArkCtrl")
  // raidersLostArkCtrl:initKeyNums()
}

void UIMainBottom::CreateExpostulationTimer(){
  // self:deleteExpostulationTimer()
  // self.expostulationTimer = SoradCreateTimer(self, handler(self, self.updateExpostulation))
  // self:updateExpostulation(self, {isInit = true})
}

void UIMainBottom::DeleteExpostulationTimer(){
  // if self.expostulationTimer then
  //   SoraDManagerRemoveTimer(self, self.expostulationTimer)
  //   self.expostulationTimer = nil
  // end
}

void UIMainBottom::InitHalloweenShineEffect(){
  // local effectShine = SoraDCreatAnimation("Node_Effect_wsj02", nil, true)
  // self.effectShine = effectShine
  // effectShine:setPosition(cc.p(0, 65))
  // self.Node_style_top:addChild(effectShine)
  // local img1 = SoraDGetChildByName(effectShine, "G_dh_Tex_wsj_002_01")
  // local img2 = SoraDGetChildByName(effectShine, "G_dh_Tex_wsj_001_04")
  // local particle1 = SoraDGetChildByName(effectShine, "et_dixintanxian_02_01")
  // local particle2 = SoraDGetChildByName(effectShine, "et_dixintanxian_02_02")
  // img1:setVisible(false)
  // img2:setVisible(false)
  // particle1:setVisible(false)
  // particle2:setVisible(false)
}

void UIMainBottom::InitStyle(){
  // local param = {
  //   [gMainUIStype.EASTER] = {
  //     top = "mainUI_style_easter",
  //     spine = {
  //       skel = "spine/yezi.skel",
  //       atlas = "spine/yezi.atlas"
  //     }
  //   },
  //   [gMainUIStype.HALLOWEEN] = {
  //     top = "mainUI_style_halloween"
  //   },
  //   [gMainUIStype.CHRITMAS] = {
  //     top = "mainUI_style_chritmas"
  //   },
  //   [gMainUIStype.QUICKSAND] = {
  //     top = "mainUI_style_ztsz_top",
  //     bg = "mainUI_style_ztsz",
  //     act = "Node_Effect_liusha2",
  //     actPos = cc.p(320, 30)
  //   },
  //   [gMainUIStype.ROSNORMAL] = {}
  // }
  // local cfg = param[GLOBAL_MAINUI_STYLE] or param[gMainUIStype.QUICKSAND]
  // if cfg.top then
  //   local topNode = SoraDCreatAnimation(cfg.top, nil, cfg.isLoop or false)
  //   if GLOBAL_MAINUI_STYLE == gMainUIStype.HALLOWEEN then
  //     topNode:addTo(self.Node_style_bg)
  //     self:initHalloweenShineEffect()
  //   else
  //     topNode:addTo(self.Node_style_top)
  //   end
  //   if cfg.spine then
  //     local Node_spine = SoraDGetChildByName(topNode, "Node_spine")
  //     local spine = sp.SkeletonAnimation:create(cfg.spine.skel, cfg.spine.atlas, 1)
  //     spine:setAnimation(0, "animation", true)
  //     spine:addTo(Node_spine)
  //   end
  // end
  // if cfg.bg then
  //   local topNode = SoraDCreatAnimation(cfg.bg, nil, cfg.isLoop or false)
  //   topNode:addTo(self.Node_style_bg)
  // end
  // if cfg.act then
  //   local actNode = SoraDCreatAnimation(cfg.act, nil, true)
  //   actNode:setPosition(cfg.actPos)
  //   actNode:addTo(self.Node_area_b, 999)
  //   actNode:setName("actNode_style")
  // end
}

void UIMainBottom::InitGroup(){
  // local function createGroupNode(groupID, zOrder, nodeName)
  //   local node = display.newNode()
  //   node:setGroupID(groupID, true)
  //   node:addTo(self)
  //   node:setLocalZOrder(zOrder)
  //   node:setName(nodeName)
  // end
  // createGroupNode(mainUIDef.newGroupID.text, 5, "Node_group_text")
}

ui::Text *UIMainBottom::ExchangeGroupText(ui::Text *p_Text, float p_Height){
  // local text = SoraDCreateLabel({
  //   UILabelType = 2,
  //   text = "",
  //   size = target:getFontSize(),
  //   color = target:getTextColor(),
  //   dimensions = cc.size(200, height or 30),
  //   align = cc.TEXT_ALIGNMENT_CENTER,
  //   valign = cc.VERTICAL_TEXT_ALIGNMENT_CENTER
  // })
  // text:setAnchorPoint(cc.p(target:getAnchorPoint().x, target:getAnchorPoint().y))
  // text:setPosition(cc.p(target:getPositionX(), target:getPositionY()))
  // text:addTo(target:getParent())
  // target:removeFromParent()
  // return text

  return nullptr;
}

void UIMainBottom::InitAccountBind(EventCustom *p_Event){
  // local isBind = userSDKManager.returnAccountBindType(gSDKDef.platformType.email)
  // local isPhoneBind = userSDKManager.returnAccountBindType(gSDKDef.platformType.mobile)
  // local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  // local lordBase = lordInfoCtrl:getBaseInfo()
  // local isReward = lordBase.hasBindAccountReward or false
  // local isBindPhone = not lordBase.receiveBindPhone and false
  // local ret = false
  // if IsArClient then
  //   if self.viewChangeType == VIEW_TYPE_CITY and (SoraDGetCastleLv() >= CASTLE_LV6_LIMITED and (not isBind or isBind and not isReward) or SoraDGetCastleLv() >= CASTLE_LV10_LIMITED and (not isPhoneBind or isPhoneBind and not isBindPhone)) then
  //     ret = true
  //   else
  //     ret = false
  //   end
  // elseif self.viewChangeType == VIEW_TYPE_CITY and SoraDGetCastleLv() >= CASTLE_LV6_LIMITED and (not isBind or isBind and not isReward) then
  //   ret = true
  // else
  //   ret = false
  // end
  // local isSettingHide = SoraDConfigGet("Game:GameOptionsView:bindPhoneShow~bool", {byUID = true}) or false
  // self.btnAccount:setVisible(ret and not isSettingHide and not worldMapDefine.isInWar())
  // if IsArClient then
  //   self.iconAccount:setSpriteFrame(SoraDGetCastleLv() >= CASTLE_LV10_LIMITED and isBind and isReward and "icon_bind_phone.png" or "icon_main_set_account_new.png")
  //   self.redPointAccount:setVisible(isBind and not isReward or isPhoneBind and not isBindPhone)
  // else
  //   self.iconAccount:setSpriteFrame("icon_main_set_account_new.png")
  //   self.redPointAccount:setVisible(isBind and not isReward)
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::InitGreenPoint(){
  // local allianceHelp = gametop.playertop_:getModule("allianceHelp")
  // local allianceRelationCtrl = gametop.playertop_:getModule("allianceRelationCtrl")
  // local allianceDesRead = include("allianceDesRead")
  // local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  // local memberMgr = gametop.playertop_:getModule("memberMgr")
  // local ownmember = memberMgr:getOwnMember()
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // local allianceTreasureCtrl = gametop.playertop_:getModule("allianceTreasureCtrl")
  // local allianceActiveCtrl = gametop.playertop_:getModule("allianceActiveCtrl")
  // local allianceHuntCtrl = gametop.playertop_:getModule("allianceHuntCtrl")
  // local allianceCounterSysCtrl = gametop.playertop_:getModule("allianceCounterSysCtrl")
  // local hasChallengeTimes = allianceHuntCtrl:getCheckChanllengeTimes()
  // local allianceCount = kingdomMapCtrl:getHallWarCount()
  // local counterSysCount = allianceCounterSysCtrl:getNewPoint()
  // allianceCount = allianceCount + #allianceHelp:getHelpList().otherhelplist
  // if allianceDesRead.checkRank(gAllianceRank.R4) then
  //   allianceCount = allianceCount + allianceRelationCtrl:getAllyInviteNum()
  // end
  // local mineNum = allianceTreasureCtrl:getDigRewardCount()
  // local helpNum = allianceTreasureCtrl:getHelpRewardCount()
  // local playerMobilizationCtrl = gametop.playertop_:getModule("playerMobilizationCtrl")
  // local hasActived = playerMobilizationCtrl:isHaveActived()
  // local activeNum = allianceMgr:hasJoinAlliance() and allianceActiveCtrl:getCanReceiveTaskNum() or 0
  // allianceCount = allianceCount + mineNum + helpNum + hasActived + hasChallengeTimes + counterSysCount + activeNum
  // local rewardsCount = SoraDGetCtrl("allianceScience"):getProsperityRewardsCount()
  // if rewardsCount > 0 then
  //   allianceCount = allianceCount + 1
  // end
  // if allianceGuideCtrl:isShowEnterPoint() then
  //   allianceCount = allianceCount + 1
  // end
  // if worldMapDefine.isInAtlantis() then
  //   allianceCount = kingdomMapCtrl:getHallWarCount()
  // end
  // local mainCount = mailMgr:getNewMailNum()
  // local itemsCount = 0
  // local heroPointNum = heroltCtrl:getHeroBottomPointNum()
  // self:updateGreenTip({
  //   alliance = allianceCount,
  //   items = itemsCount,
  //   mail = mainCount,
  //   hero = heroPointNum
  // })
  // if not worldMapDefine.inInCrossWar() and ownmember:getProperty("isfirstjoin") and not allianceMgr:hasJoinAlliance() then
  //   self:addFirstJoinAllianceAnimation()
  // end
}

void UIMainBottom::OnMessageListener(){
  using namespace std::placeholders;
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINFINSH", handler(self, self.reLoginFinish))
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", std::bind(&UIMainBottom::ReLoginFinish, this, _1));
  // SoraDAddMessage(self, "MESSAGE_CHAT_OPEN_UI_ALLIANCE", handler(self, self.openUIAlliance))
  GBase::DAddMessage(this, "MESSAGE_CHAT_OPEN_UI_ALLIANCE", std::bind(&UIMainBottom::OpenUIAlliance, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_ONSHOW", handler(self, self.currentShowViewType))
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_ONSHOW", std::bind(&UIMainBottom::CurrentShowViewType, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", handler(self, self.showOrHideGuideView))
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", std::bind(&UIMainBottom::ShowOrHideGuideView, this, _1));
  // SoraDAddMessage(self, "MESSAGE_REQ_NEW_PRINCE_GIFT_BUY_PACKAGE", handler(self, self.addPrinceGiftNewBuffButton))
  GBase::DAddMessage(this, "MESSAGE_REQ_NEW_PRINCE_GIFT_BUY_PACKAGE", std::bind(&UIMainBottom::AddPrinceGiftNewBuffButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PRINCE_GIFT_GUIDE_BUFF_REFRESH", handler(self, self.showPrinceGiftGuideView))
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_GUIDE_BUFF_REFRESH", std::bind(&UIMainBottom::ShowPrinceGiftGuideView, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PRINCE_GIFT_GUIDE_REFRESH", handler(self, self.addPrinceGiftBuffButton))
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_GUIDE_REFRESH", std::bind(&UIMainBottom::AddPrinceGiftBuffButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PRINCE_GIFT_INIT", handler(self, self.addPrinceGiftBuffButton))
  GBase::DAddMessage(this, "MESSAGE_PRINCE_GIFT_INIT", std::bind(&UIMainBottom::AddPrinceGiftBuffButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SINBAD_TREASURE_UPDATE_LV_POP_WINDOW", handler(self, self.showSinbadPopWindow))
  GBase::DAddMessage(this, "MESSAGE_SINBAD_TREASURE_UPDATE_LV_POP_WINDOW", std::bind(&UIMainBottom::ShowSinbadPopWindow, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHTOWER_ADDINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_ADDINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHTOWER_REMOVEINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_REMOVEINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHTOWER_EDITINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_EDITINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_CLIENT_WATCHTOWER_INGORECONTROL", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_CLIENT_WATCHTOWER_INGORECONTROL", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHTOWER_REFRESHALL", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHTOWER_REFRESHALL", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_WAR_SETTING", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_WAR_SETTING", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHSOULTOWER_ADDINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_ADDINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHSOULTOWER_EDITINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_EDITINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHSOULTOWER_REMOVEINFO", handler(self, self.checkWatchTower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_WATCHSOULTOWER_REMOVEINFO", std::bind(&UIMainBottom::CheckWatchTower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_ROMANSOUL_ALLIANCEATTACK", handler(self, self.checkRomanSoul))
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_ROMANSOUL_ALLIANCEATTACK", std::bind(&UIMainBottom::CheckRomanSoul, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_PYRAMIDBATTLE_MAINUIICONCHECK", handler(self, self.btnPyramidBattleCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_MAINUIICONCHECK", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_PYRAMIDBATTLE_GROUP_UPDATE", handler(self, self.btnPyramidBattleCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_GROUP_UPDATE", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_BE_KICKED", handler(self, self.btnPyramidBattleCheck))
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_BE_KICKED", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_QUIT_SUCCESS", handler(self, self.btnPyramidBattleCheck))
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_QUIT_SUCCESS", std::bind(&UIMainBottom::BtnPyramidBattleCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_GREEN_POINT_UPDATE", handler(self, self.greenPointUpdate))
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", std::bind(&UIMainBottom::GreenPointUpdate, this, _1));
  // SoraDAddMessage(self, "MESSAGE_GREEN_POINT_UPDATE_BYTYPE", handler(self, self.greenPointUpdateByType))
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE_BYTYPE", std::bind(&UIMainBottom::GreenPointUpdateByType, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_MEMBER_UPDATE", handler(self, self.greenPointUpdate))
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_MEMBER_UPDATE", std::bind(&UIMainBottom::GreenPointUpdate, this, _1));
  // SoraDAddMessage(self, "MESSAGE_WALLS_NOTIFY_SUCCESS", handler(self, self.checkWallDefend))
  GBase::DAddMessage(this, "MESSAGE_WALLS_NOTIFY_SUCCESS", std::bind(&UIMainBottom::CheckWallDefend, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_JOIN_SUCCESS", handler(self, self.RemovefirstJoinAllianceAnimation))
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_JOIN_SUCCESS", std::bind(&UIMainBottom::RemovefirstJoinAllianceAnimation, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMUSR_CHANGED", handler(self, self.btnKingdomManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMUSR_CHANGED", std::bind(&UIMainBottom::BtnKingdomManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMALLIANCE_GIFT", handler(self, self.btnKingdomManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMALLIANCE_GIFT", std::bind(&UIMainBottom::BtnKingdomManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_CLEAN", handler(self, self.btnLegendKingManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_CLEAN", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_AP_LT", handler(self, self.btnLegendKingManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_AP_LT", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGENDLORD_LORD_TITLE_INFO_BACK", handler(self, self.btnLegendKingManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_LORD_TITLE_INFO_BACK", std::bind(&UIMainBottom::BtnLegendKingManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_CLEAN", handler(self, self.msgHegemonClean))
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_CLEAN", std::bind(&UIMainBottom::MsgHegemonClean, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_AP_LT", handler(self, self.btnHegemonManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_AP_LT", std::bind(&UIMainBottom::BtnHegemonManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_LORD_TITLE_INFO_BACK", handler(self, self.btnHegemonManagerCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_LORD_TITLE_INFO_BACK", std::bind(&UIMainBottom::BtnHegemonManagerCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_UPDATE_MAINUI_HEGEMON", handler(self, self.btnHegemonBattleCheck))
  GBase::DAddMessage(this, "MESSAGE_SERVER_HEGEMON_UPDATE_MAINUI_HEGEMON", std::bind(&UIMainBottom::BtnHegemonBattleCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", handler(self, self.btnCityUnlockCheck))
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", std::bind(&UIMainBottom::BtnCityUnlockCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_NEWPLAYER_BUFF_END", handler(self, self.btnNewPlayerBuffCheck))
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_NEWPLAYER_BUFF_END", std::bind(&UIMainBottom::BtnNewPlayerBuffCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SULTANSBACK_WELCOME_REFRESH", handler(self, self.btnSultansBackWelCheck))
  GBase::DAddMessage(this, "MESSAGE_SULTANSBACK_WELCOME_REFRESH", std::bind(&UIMainBottom::BtnSultansBackWelCheck, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAIN_RECORD_SCREEN", handler(self, self.startRecordScreen))
  GBase::DAddMessage(this, "MESSAGE_MAIN_RECORD_SCREEN", std::bind(&UIMainBottom::StartRecordScreen, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAIN_STOP_RECORD_SCREEN", handler(self, self.stopRecording))
  GBase::DAddMessage(this, "MESSAGE_MAIN_STOP_RECORD_SCREEN", std::bind(&UIMainBottom::StopRecording, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LUCKY_DAY_UPDATE", handler(self, self.updateEventcenter))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKY_DAY_UPDATE", std::bind(&UIMainBottom::UpdateEventcenter, this, _1));
  // SoraDAddMessage(self, "MESSAGE_WALLS_DEFENCE_DESTROY", handler(self, self.defineWallDestroy))
  GBase::DAddMessage(this, "MESSAGE_WALLS_DEFENCE_DESTROY", std::bind(&UIMainBottom::DefineWallDestroy, this, _1));
  // SoraDAddMessage(self, "MESSAGE_WALLS_DEFENCE_DESTROY_RECOVER", handler(self, self.defineWallDestroyRecover))
  GBase::DAddMessage(this, "MESSAGE_WALLS_DEFENCE_DESTROY_RECOVER", std::bind(&UIMainBottom::DefineWallDestroyRecover, this, _1));
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_BIND_AWARD", handler(self, self.initAccountBind))
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_BIND_AWARD", std::bind(&UIMainBottom::InitAccountBind, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAIN_BTN_UPDATE", handler(self, self.updateBtnContainer))
  GBase::DAddMessage(this, "MESSAGE_MAIN_BTN_UPDATE", std::bind(&UIMainBottom::UpdateBtnContainer, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAIN_BTN_UPDATE_TEST", handler(self, self.updateBtnContainer))
  GBase::DAddMessage(this, "MESSAGE_MAIN_BTN_UPDATE_TEST", std::bind(&UIMainBottom::UpdateBtnContainer, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MONTHLY_CARD_REFRESH_BACK", handler(self, self.updateMonthCardButton))
  GBase::DAddMessage(this, "MESSAGE_MONTHLY_CARD_REFRESH_BACK", std::bind(&UIMainBottom::UpdateMonthCardButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", handler(self, self.getEventCenterReturn))
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", std::bind(&UIMainBottom::GetEventCenterReturn, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_MAINUIINVITE_REFRESH", handler(self, self.initAllianceInvitePop))
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_MAINUIINVITE_REFRESH", std::bind(&UIMainBottom::InitAllianceInvitePop, this, _1));
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_BY_UID", handler(self, self.serverMessageGetLordInfo))
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_BY_UID", std::bind(&UIMainBottom::ServerMessageGetLordInfo, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_REQ_INFO_BACK", handler(self, self.serverMessageGetAllianceInfo))
  GBase::DAddMessage(this, "MESSAGE_ALLIANCE_REQ_INFO_BACK", std::bind(&UIMainBottom::ServerMessageGetAllianceInfo, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_START_BY_STEP", handler(self, self.recevieGuideMsg))
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_START_BY_STEP", std::bind(&UIMainBottom::RecevieGuideMsg, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ITEM_CHANGE_TYPE", handler(self, self.recevieItemChangeMsg))
  GBase::DAddMessage(this, "MESSAGE_ITEM_CHANGE_TYPE", std::bind(&UIMainBottom::RecevieItemChangeMsg, this, _1));
  // SoraDAddMessage(self, "MESSAGE_UI_EXPOSTULATION_UPDATE", handler(self, self.updateExpostulation))
  GBase::DAddMessage(this, "MESSAGE_UI_EXPOSTULATION_UPDATE", std::bind(&UIMainBottom::UpdateExpostulation, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", handler(self, self.showLuckyBless))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", std::bind(&UIMainBottom::ShowLuckyBless, this, _1));
  // SoraDAddMessage(self, "MESSAGE_GOLD_PACKAGE_STATE", handler(self, self.updateGoldPackageButton))
  GBase::DAddMessage(this, "MESSAGE_GOLD_PACKAGE_STATE", std::bind(&UIMainBottom::UpdateGoldPackageButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_LUCKY_RECHARGE_REFRESH", handler(self, self.updateBtnLuckyRecharge))
  GBase::DAddMessage(this, "MESSAGE_LUCKY_RECHARGE_REFRESH", std::bind(&UIMainBottom::UpdateBtnLuckyRecharge, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_GET_ALLIANCE_HELP_LIST_SUCCESS", handler(self, self.initHelpAllBtn))
  GBase::DAddMessage(this, "MESSAGE_ALLIACNE_GET_ALLIANCE_HELP_LIST_SUCCESS", std::bind(&UIMainBottom::InitHelpAllBtn, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGEND_TEAM_INVITED_INFO", handler(self, self.msgInvitedInfo_legend))
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGEND_TEAM_INVITED_INFO", std::bind(&UIMainBottom::MsgInvitedInfoLegend, this, _1));
  // SoraDAddMessage(self, "MESSAGE_ITEM_LIMITITEM_TIMEOUT_BACK", handler(self, self.updateShopNewTag))
  GBase::DAddMessage(this, "MESSAGE_ITEM_LIMITITEM_TIMEOUT_BACK", std::bind(&UIMainBottom::UpdateShopNewTag, this, _1));
  // SoraDAddMessage(self, "MESSAGE_QUESTIONNAIRE_REFRESH", handler(self, self.updateQuestionnaireButton))
  GBase::DAddMessage(this, "MESSAGE_QUESTIONNAIRE_REFRESH", std::bind(&UIMainBottom::UpdateQuestionnaireButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_UI_EVENTCENTER_REFRESHISNEW", handler(self, self.updateCommunityButton))
  GBase::DAddMessage(this, "MESSAGE_UI_EVENTCENTER_REFRESHISNEW", std::bind(&UIMainBottom::UpdateCommunityButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_RADIANCE_WAR_WARNING", handler(self, self.updateGreenPointRadianceWar))
  GBase::DAddMessage(this, "MESSAGE_SERVER_RADIANCE_WAR_WARNING", std::bind(&UIMainBottom::UpdateGreenPointRadianceWar, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_RADIANCE_WAR_LONGTIMEUNLOGIN", handler(self, self.showLongTimeUnlogin))
  GBase::DAddMessage(this, "MESSAGE_SERVER_RADIANCE_WAR_LONGTIMEUNLOGIN", std::bind(&UIMainBottom::ShowLongTimeUnlogin, this, _1));
  // SoraDAddMessage(self, "MESSAGE_KOCHOICE_REFRESH", handler(self, self.addKOChoiceButton))
  GBase::DAddMessage(this, "MESSAGE_KOCHOICE_REFRESH", std::bind(&UIMainBottom::AddKOChoiceButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH", handler(self, self.refreshTrainPower))
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH", std::bind(&UIMainBottom::RefreshTrainPower, this, _1));
  // SoraDAddMessage(self, "MESSAGE_LOST_RUINS_REFRESH", handler(self, self.addLostRuinsButton))
  GBase::DAddMessage(this, "MESSAGE_LOST_RUINS_REFRESH", std::bind(&UIMainBottom::AddLostRuinsButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_WIND_TOWER_REFRESH", handler(self, self.addWindTowerButton))
  GBase::DAddMessage(this, "MESSAGE_WIND_TOWER_REFRESH", std::bind(&UIMainBottom::AddWindTowerButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SNOWWOLF_LOST_REFRESH", handler(self, self.addSnowWolfLostButton))
  GBase::DAddMessage(this, "MESSAGE_SNOWWOLF_LOST_REFRESH", std::bind(&UIMainBottom::AddSnowWolfLostButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN", handler(self, self.updateCrazyTrioButton))
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN", std::bind(&UIMainBottom::UpdateCrazyTrioButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_RELASH", handler(self, self.addCrazyTrioButton))
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_RELASH", std::bind(&UIMainBottom::AddCrazyTrioButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_UPGRADE_LEVEL", handler(self, self.updateBtnStatues))
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPGRADE_LEVEL", std::bind(&UIMainBottom::UpdateBtnStatues, this, _1));
  // SoraDAddMessage(self, "MESSAGE_MAINUIBOTTOM_SORTBOTTOMQUESTBTNS", handler(self, self.sortBottomQuestBtns))
  GBase::DAddMessage(this, "MESSAGE_MAINUIBOTTOM_SORTBOTTOMQUESTBTNS", std::bind(&UIMainBottom::SortBottomQuestBtns, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_MAIL_REQ_BATTLE_REPORT_BACK", handler(self, self.openReportMail))
  GBase::DAddMessage(this, "MESSAGE_SERVER_MAIL_REQ_BATTLE_REPORT_BACK", std::bind(&UIMainBottom::OpenReportMail, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_MAIL_REQ_SINGLE_MAIL_BACK_REPORT", handler(self, self.openReportMail))
  GBase::DAddMessage(this, "MESSAGE_SERVER_MAIL_REQ_SINGLE_MAIL_BACK_REPORT", std::bind(&UIMainBottom::OpenReportMail, this, _1));
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", handler(self, self.addHarvestSeasonButton))
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", std::bind(&UIMainBottom::AddHarvestSeasonButton, this, _1));
  // SoraDAddMessage(self, "MESSAGE_HARVEST_SEASON_REDPOINT", function()
  //   if self.btnHarvestSeason then
  //     self.btnHarvestSeason.redIcon:setVisible(false)
  //   end
  // end)
  GBase::DAddMessage(this, "MESSAGE_HARVEST_SEASON_REDPOINT", [this](EventCustom *) {
    if (n_BtnHarvestSeason) {
       //self.btnHarvestSeason.redIcon:setVisible(false)
    }
  });
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_REFRESH", handler(self, self.checkPreDownloadStatus))
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_REFRESH", std::bind(&UIMainBottom::CheckPreDownloadStatus, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_REFRESH_DOWNLOAD", handler(self, self.checkPreDownload))
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_REFRESH_DOWNLOAD", std::bind(&UIMainBottom::CheckPreDownload, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_GAME_DOWNSUC", handler(self, self.OnPreDownloadSuc))
  GBase::DAddMessage(this, "MESSAGE_PRE_DOWNLOAD_GAME_DOWNSUC", std::bind(&UIMainBottom::OnPreDownloadSuc, this, _1));
  // SoraDAddMessage(self, "MESSAGE_PAYBACK_NOTICE", handler(self, self.btnPayBackCheck))
  GBase::DAddMessage(this, "MESSAGE_PAYBACK_NOTICE", std::bind(&UIMainBottom::BtnPayBackCheck, this, _1));
}

void UIMainBottom::ShowOrHideGuideView(EventCustom *p_Event){
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

void UIMainBottom::ShowPrinceGiftGuideView(EventCustom *p_Event){
  //cityBuildFunction:checkPopUnlockPrinceGift()
}

void UIMainBottom::ShowSinbadPopWindow(EventCustom *p_Event){
  //cityBuildFunction:checkPopUpSinbadTreasure()
}

void UIMainBottom::ReLoginFinish(EventCustom *p_Event){
  // print("\230\150\173\231\186\191\233\135\141\232\191\158\229\149\166\239\188\129")
  // self.chatMainUIView:initWithData()
  // self:initGreenPoint()
  // self:checkWatchTower()
  // local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  // kingdomMapCtrl:reLoginFinish()
  // self:btnNeckLaceRankCheck()
  // self:checkWallDefend()
  // self:checkRomanSoul()
  // self:btnKingdomManagerCheck()
  // self:btnPyramidBattleCheck()
  // self:showLuckyBless()
  // self:initAccountBind()
  // self:req4AllianceInviteData()
  // self.updateAllianceGreen = nil
  // self:createExpostulationTimer()
  // self:checkRemainsWar()
  // self:msgInvitedInfo_legend()
  // self:updateGreenPointRadianceWar()
  // self:initHelpAllBtn()
  // self:btnLegendKingManagerCheck()
  // self:btnHegemonBattleCheck()
  // self:btnHegemonManagerCheck()
  // self:btnTrainPowerManagerCheck()
  // self:initBattleOpenBtn()
  // self:checkPreDownload()
  // self:checkPreDownloadStatus()
  // self:addPrinceGiftNewBuffButton()
  // self:addPrinceGiftBuffButton()
  // self:btnNewPlayerBuffCheck()
  // self:addHarvestSeasonButton()
  // cityBuildFunction:checkPopUpWindow()
}

void UIMainBottom::UpdateEventcenter(EventCustom *p_Event){
  ShowLuckyBless(p_Event);
}

void UIMainBottom::ServerMessageGetLordInfo(EventCustom *p_Event){
  // if data.clientData and data.lord then
  //   local targetName = data.clientData.targetName
  //   if targetName == "AllianceInvitePop" or targetName == "atlantisMemberSingle" then
  //     local infoView = SoraDCreatePanel("lordView")
  //     infoView:initData(data.lord)
  //     infoView:show()
  //   end
  // end
}

void UIMainBottom::UpdateExpostulation(EventCustom *p_Event){
  // if data and data.isInit then
  //   GLOBAL_EXPOSTULATION_TIME = 0
  // end
  // GLOBAL_EXPOSTULATION_TIME = GLOBAL_EXPOSTULATION_TIME + 1
  // if GLOBAL_EXPOSTULATION_TIME == EXPOSTULATION_INTERVAL then
  //   local expostulationData = expostulationLogic.getExpostulation()
  //   GLOBAL_EXPOSTULATION_TIME = 0
  //   if expostulationData then
  //     self.nodeQuestGuide:changeToExpostulation(expostulationData)
  //   elseif self.nodeQuestGuide.exData then
  //     self.nodeQuestGuide:initData()
  //   end
  // end
}

void UIMainBottom::RecevieGuideMsg(EventCustom *p_Event){
  // local allianceInvitePop = self:getChildByName("Panel_AllianceInvitePop")
  // if allianceInvitePop then
  //   allianceInvitePop:removeFromParent()
  // end
}

void UIMainBottom::ServerMessageGetAllianceInfo(EventCustom *p_Event){
  // local alliance = data.alliance
  // if data.clientData then
  //   local from = data.clientData.from
  //   if from == "AllianceInvitePop" then
  //     local kid = alliance:getProperty("sourceKid")
  //     local panel = SoraDCreatePanel("allianceInfoView")
  //     panel:initData(alliance, kid)
  //     panel:show()
  //   end
  // end
}

void UIMainBottom::Req4AllianceInviteData(){
  // local allianceCtrl = gametop.playertop_:getModule("allianceCtrl")
  // allianceCtrl:req4AllianceInviteData()
}

void UIMainBottom::InitAllianceInvitePop(EventCustom *p_Event){
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

GVector<bool> UIMainBottom::GetMonthlyCard(){
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
  return GVector<bool>();
}

void UIMainBottom::AddQuestionnaireButton(int32 p_Num){
  // local effectMainUITop = include("effectMainUITop")
  // self.btnQuestionnaire = effectMainUITop.questionnaire(num)
  // self.btnQuestionnaire:addTo(self.scroll_btn)
  // self.btnQuestionnaire:setPosition(cc.p(35, 395))
  // self.btnQuestionnaire:addTouchEventListener(handlerEx(self, self.OnQuestionnaireClick, info))
  // self:updateBtnContainer()
}

void UIMainBottom::UpdateQuestionnaireButton(EventCustom *p_Event){
  // if self.btnQuestionnaire then
  //   self.btnQuestionnaire:removeFromParent()
  //   self.btnQuestionnaire = nil
  // end
  // local questionnaireCtrl = SoraDGetCtrl("questionnaireCtrl")
  // local num = questionnaireCtrl:getReceiveStatusAndNum()
  // if num > 0 and not worldMapDefine.inInCrossWar() then
  //   if not self.questionQuireHandle then
  //     self.questionQuireHandle = SoraDCreateTimerEx(self, function(dt)
  //       questionnaireCtrl:reqGetQuestData()
  //     end, 1800)
  //   end
  //   self:addQuestionnaireButton(num)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddLostRuinsButton(EventCustom *p_Event){
  // if self.btnLostRuins then
  //   self.btnLostRuins:removeFromParent()
  //   self.btnLostRuins = nil
  // end
  // local lostRuinsCtrl = SoraDGetCtrl("lostRuinsCtrl")
  // local recordList = lostRuinsCtrl:getRecordList()
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.LOST_RUINS_ACTIVITY, false) and next(recordList) then
  //   local effectMainUITop = include("effectMainUITop")
  //   local num = lostRuinsCtrl:getNewSurveyNum()
  //   self.btnLostRuins = effectMainUITop.createLostRuinsBtn(num)
  //   self.btnLostRuins:addTo(self.scroll_btn)
  //   self.btnLostRuins:setPosition(cc.p(35, 395))
  //   self.btnLostRuins:addTouchEventListener(handler(self, self.OnLostRuinsClick))
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddWindTowerButton(EventCustom *p_Event){
  // if self.btnWindTower then
  //   self.btnWindTower:removeFromParent()
  //   self.btnWindTower = nil
  // end
  // local isConWar = worldMapDefine.isInKingdomBattle()
  // if not isConWar then
  //   local windTowerCtrl = SoraDGetCtrl("windTowerCtrl")
  //   local recordList = windTowerCtrl:getRecordList()
  //   if _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.WIND_TOWER_ACTIVITY, false) and #recordList > 0 then
  //     local effectMainUITop = include("effectMainUITop")
  //     local num = windTowerCtrl:getNewSurveyNum()
  //     self.btnWindTower = effectMainUITop.createWindTowerBtn(num)
  //     self.btnWindTower:addTo(self.scroll_btn)
  //     self.btnWindTower:setPosition(cc.p(35, 395))
  //     self.btnWindTower:addTouchEventListener(handler(self, self.OnWindTowerClick))
  //   end
  // end
  // self:updateBtnContainer()
}


void UIMainBottom::AddSnowWolfLostButton(EventCustom *p_Event){
  // if self.btnSnowWolfLost then
  //   self.btnSnowWolfLost:removeFromParent()
  //   self.btnSnowWolfLost = nil
  // end
  // local isConWar = worldMapDefine.isInKingdomBattle()
  // if not isConWar then
  //   local snowWolfLostCtrl = SoraDGetCtrl("snowWolfLostCtrl")
  //   local recordList = snowWolfLostCtrl:getRecordList()
  //   dump({
  //     #recordList,
  //     clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SNOWWOLF_LOST_ACTIVITY, false)
  //   }, "clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SNOWWOLF_LOST_ACTIVITY, false)")
  //   if _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SNOWWOLF_LOST_ACTIVITY, false) and #recordList > 0 then
  //     local effectMainUITop = include("effectMainUITop")
  //     local num = snowWolfLostCtrl:getNewSurveyNum()
  //     self.btnSnowWolfLost = effectMainUITop.createSnowWolfLostBtn(num)
  //     self.btnSnowWolfLost:addTo(self.scroll_btn)
  //     self.btnSnowWolfLost:setPosition(cc.p(35, 395))
  //     self.btnSnowWolfLost:addTouchEventListener(handler(self, self.OnSnowWolfLostClick))
  //   end
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::UpdateCrazyTrioButton(EventCustom *p_Event){
  // if data and data.msg == "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN" then
  //   if self.btnSwitchType == -1 then
  //     self.btnSwitchType = 1
  //     self:switchBottonBtn()
  //     local seq = cca.seq({
  //       cca.delay(0.3333333333333333),
  //       cca.callFunc(function()
  //         self:addCrazyTrioButton()
  //       end)
  //     })
  //     self:runAction(seq)
  //   else
  //     self:addCrazyTrioButton()
  //   end
  // end
}

void UIMainBottom::AddCrazyTrioButton(EventCustom *p_Event){
  // if self.btnCrazyTrio then
  //   self.btnCrazyTrio:removeFromParent()
  //   self.btnCrazyTrio = nil
  // end
  // local cumuActiveCtrl = gametop.playertop_:getModule("cumuActiveCtrl")
  // local rechargeltCtrl = include("rechargeltCtrl")
  // local crazyData = cumuActiveCtrl:getCrazyTrioData()
  // local receiveNum = table.nums(crazyData.receive)
  // if cumuActiveCtrl:getActivityID() ~= gActivityTimeActivityID.CRAZY_TRIO_ACTIVITY and receiveNum >= 2 then
  //   SoraDConfigSet("Game:eventCrazyTrioNew:isShowInDown~bool", true, {byUID = true})
  // end
  // if clientEventMgr.judgeIsOpen(cumuActiveCtrl:getActivityID(), false) then
  //   if SoraDConfigGet("Game:eventCrazyTrioNew:isShowInDown~bool", {byUID = true}) and receiveNum < rechargeltCtrl.getRechargeTotalConfigNum() then
  //     local effectMainUITop = include("effectMainUITop")
  //     local _, num = cumuActiveCtrl:getInitialReceiveState()
  //     self.btnCrazyTrio = effectMainUITop.createCrazyTrioBtn(num)
  //     self.btnCrazyTrio:addTo(self.scroll_btn)
  //     self.btnCrazyTrio:setPosition(cc.p(35, 395))
  //     self.btnCrazyTrio:addTouchEventListener(handler(self, self.OnCrazyTrioClick))
  //   end
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddCommunityButton(void *p_Info){
  // local effectMainUITop = include("effectMainUITop")
  // self.btnCommunity = effectMainUITop.communityCenter(info)
  // self.btnCommunity:addTo(self.scroll_btn)
  // self.btnCommunity:setPosition(cc.p(35, 395))
  // self.btnCommunity:addTouchEventListener(handlerEx(self, self.OnCommunityClick, info.param))
}

void UIMainBottom::UpdateCommunityButton(EventCustom *p_Event){
  // if self.btnCommunity then
  //   self.btnCommunity:removeFromParent()
  //   self.btnCommunity = nil
  // end
  // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  // local activityCenterUICtrl = SoraDGetCtrl("activityCenterUICtrl")
  // local commnutiInfo = activityShowCtrl:getCommunityInfo(gActivityTimeActivityID.COMMUNITY_CENTER_MAIN_UI)
  // if commnutiInfo.param and commnutiInfo.param.show then
  //   print("skldjfksljdflskdj", commnutiInfo.param.type)
  //   if commnutiInfo.param.type == 1 then
  //     self:addCommunityButton(commnutiInfo)
  //   elseif commnutiInfo.param.type == 0 and activityCenterUICtrl:isHaveNewFlag(gActivityTimeActivityID.COMMUNITY_CENTER_MAIN_UI) then
  //     self:addCommunityButton(commnutiInfo)
  //   end
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::AddMonthCardButton(){
  // local effectMainUITop = include("effectMainUITop")
  // self.btnMonthCard = effectMainUITop.monthOrWeeklyCard()
  // self.btnMonthCard:addTo(self.scroll_btn)
  // self.btnMonthCard:setPosition(cc.p(35, 395))
  // self.btnMonthCard:addTouchEventListener(handler(self, self.OnMonthCardClick))
  // self:updateBtnContainer()
}

void UIMainBottom::UpdateMonthCardButton(EventCustom *p_Event){
  // local hasGift, hasBuy, hasGot = self:getMonthlyCard()
  // if not self.btnMonthCard and hasGift and not hasBuy and not IsArClient then
  //   self:addMonthCardButton()
  // end
  // if self.btnMonthCard then
  //   if hasGift then
  //     if hasBuy then
  //       self.btnMonthCard:setVisible(false)
  //       self:updateBtnContainer()
  //     else
  //       self.btnMonthCard:setVisible(true)
  //       self:updateBtnContainer()
  //     end
  //   else
  //     self.btnMonthCard:setVisible(false)
  //     self:updateBtnContainer()
  //   end
  // end
}

void UIMainBottom::OnMonthCardClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("rechargeMonthlyFrame")
  //   panel:show()
  // end
}

void UIMainBottom::OnCommunityClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local localUrl = {
  //     [gActivityCenterUIEnum.COMMUNITY_CENTER_1] = "https://www.facebook.com/slateen/",
  //     [gActivityCenterUIEnum.COMMUNITY_CENTER_2] = "https://www.instagram.com/revengeofsultans/",
  //     [gActivityCenterUIEnum.COMMUNITY_CENTER_3] = "https://twitter.com/EntkamElSlaten"
  //   }
  //   if info.url and info.url ~= "" then
  //     print("MainUIBottom-community_url", info.url)
  //     userSDKManager.openSDKLink(info.url)
  //   elseif info.show == gActivityCenterUIEnum.COMMUNITY_CENTER_4 or info.show == gActivityCenterUIEnum.COMMUNITY_CENTER_5 then
  //     print("\194\183\194\183\194\183\230\137\147\229\188\128\231\164\190\229\140\186")
  //     userSDKManager.showSocial()
  //   else
  //     userSDKManager.openSDKLink(localUrl[info.show])
  //   end
  //   local activityCenterUICtrl = SoraDGetCtrl("activityCenterUICtrl")
  //   activityCenterUICtrl:sendClearNewMsg(gActivityTimeActivityID.COMMUNITY_CENTER_MAIN_UI)
  // end
}

void UIMainBottom::OnLostRuinsClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local tag = target:getTag()
  //   if target.fingerNode then
  //     target.fingerNode:setVisible(false)
  //     target.fingerNode:stopAllActions()
  //     target.fingerNode:removeFromParent()
  //     target.fingerNode = nil
  //   end
  //   local panel = SoraDCreatePanel("lostRuinsRecordView")
  //   panel:show()
  // end
}

void UIMainBottom::OnWindTowerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if target.fingerNode then
  //     target.fingerNode:setVisible(false)
  //     target.fingerNode:stopAllActions()
  //     target.fingerNode:removeFromParent()
  //     target.fingerNode = nil
  //   end
  //   local panel = SoraDCreatePanel("windTowerHistoryView")
  //   panel:show()
  // end
}


void UIMainBottom::OnSnowWolfLostClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if target.fingerNode then
  //     target.fingerNode:setVisible(false)
  //     target.fingerNode:stopAllActions()
  //     target.fingerNode:removeFromParent()
  //     target.fingerNode = nil
  //   end
  //   uiManager:show("SnowWolfRecord")
  // end
}

void UIMainBottom::OnCrazyTrioClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local tag = target:getTag()
  //   if target.fingerNode then
  //     target.fingerNode:setVisible(false)
  //     target.fingerNode:stopAllActions()
  //     target.fingerNode:removeFromParent()
  //     target.fingerNode = nil
  //   end
  //   local cumuActiveCtrl = SoraDGetCtrl("cumuActiveCtrl")
  //   local activityID = cumuActiveCtrl:getActivityID()
  //   if clientEventMgr.judgeIsOpen(activityID, false) then
  //     userSDKManager.logEvent(gSDKDef.TDonEvent.click_crazy_trio, {eventid = activityID, position = 2})
  //     clientEventMgr.singleClickEvent(activityID, 3)
  //   end
  // end
}

void UIMainBottom::OnQuestionnaireClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("questionnaireView")
  //   panel:show()
  // end
}

void UIMainBottom::UpdateEnjoyLotteryButton(){
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.ENJOY_LOTTERY, false) and not worldMapDefine.isInRemains() then
  //   if not self.btnEnjoyLottery then
  //     local effectMainUITop = include("effectMainUITop")
  //     self.btnEnjoyLottery = effectMainUITop.enjoyLotteryBtn()
  //     self.btnEnjoyLottery:addTo(self.scroll_btn)
  //     self.btnEnjoyLottery:setPosition(cc.p(35, 395))
  //     self.btnEnjoyLottery:addTouchEventListener(handler(self, self.OnEnjoyLotteryClick))
  //     self:updateBtnContainer()
  //   elseif not self.btnEnjoyLottery:isVisible() then
  //     self.btnEnjoyLottery:setVisible(true)
  //     self:updateBtnContainer()
  //   end
  // elseif self.btnEnjoyLottery and self.btnEnjoyLottery:isVisible() then
  //   self.btnEnjoyLottery:setVisible(false)
  //   self:updateBtnContainer()
  // end
}

void UIMainBottom::OnEnjoyLotteryClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.ENJOY_LOTTERY, true) then
  //     SoraDCreatePanel("enjoyLotteryView"):show()
  //   end
  // end
}

void UIMainBottom::OnSultansBackWelClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SULTAN_BACK_WELCOME_ACTIVITY, true) then
  //     SoraDCreatePanel("sultansBackWelBackView"):show()
  //   end
  // end
}

void UIMainBottom::OnGoldPackageClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("eventGoldPackageView"):show()
  // end
}

void UIMainBottom::ShowLuckyBless(EventCustom *p_Event){
  // local luckyBlessCtrl = gametop.playertop_:getModule("luckyBlessCtrl")
  // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  // if (luckyBlessCtrl:getLeftActivateCount() > 0 or luckyBlessCtrl:getLuckyBlessStatus() == 2) and activityShowCtrl:isActivityOpen(gActivityTimeActivityID.LUCKY_BLESSING_ACTIVITY) then
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

void UIMainBottom::AddGoldPackageButton(){
  // local effectMainUITop = include("effectMainUITop")
  // self.btnGoldPackage = effectMainUITop.goldPackage()
  // self.btnGoldPackage:addTo(self.scroll_btn)
  // self.btnGoldPackage:setPosition(cc.p(35, 395))
  // self.btnGoldPackage:addTouchEventListener(handler(self, self.OnGoldPackageClick))
  // if worldMapDefine.isInRemains() or not clientEventMgr.judgeIsOpen(gActivityTimeActivityID.GOLD_PACKAGE, false) then
  //   self.btnGoldPackage:setVisible(false)
  // else
  //   self.btnGoldPackage:setVisible(true)
  // end
  // self:updateBtnContainer()
}

void UIMainBottom::UpdateGoldPackageButton(EventCustom *p_Event){
  // if not clientEventMgr.judgeIsOpen(gActivityTimeActivityID.GOLD_PACKAGE, false) then
  //   if self.btnGoldPackage then
  //     self.btnGoldPackage:setVisible(false)
  //     self:updateBtnContainer()
  //   end
  // elseif self.btnGoldPackage then
  //   self.btnGoldPackage:setVisible(true)
  //   local gametop = gModuleMgr.getObject("gametop")
  //   local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  //   local sourceKid = lordInfoCtrl:getLordInfo().base.sourceKid
  //   if sourceKid and sourceKid == 0 then
  //     self.btnGoldPackage:setVisible(true)
  //   end
  //   self:updateBtnContainer()
  // end
}

void UIMainBottom::OnWorldCityClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if self.viewChangeType == VIEW_TYPE_CITY then
  //     local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  //     self.viewChangeType = VIEW_TYPE_MAP
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_SAVE_MAIN_CITY_POS"
  //     })
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //     })
  //     gReGetWorldMapTroopDataCount = 0
  //   else
  //     self.viewChangeType = VIEW_TYPE_CITY
  //   end
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINSCEN_ONSHOW",
  //     viewType = self.viewChangeType
  //   })
  // end
}

void UIMainBottom::OnBottomClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   if button == self.btnHero then
  //     local mainCityFunctions = include("mainCityFunctions")
  //     local castleLv = mainCityFunctions:getCastleLv()
  //     if castleLv >= CASTLE_LV7_LIMITED then
  //       SoraDPlaySound("buildopsound", "OpWish")
  //       if include("pyramidWarltCtrl").checkPwXianXiaSai() then
  //         SoraDCreatePanel("heroListView"):show()
  //       end
  //     else
  //       SoraDPlaySound("uicontrol", 20)
  //       SoraDShowMsgTip(i18n("common_text_2122", {
  //         name = i18n("common_name_01"),
  //         lv = CASTLE_LV7_LIMITED
  //       }))
  //     end
  //   elseif button == self.btnItems then
  //     SoraDPlaySound("uicontrol", 14)
  //     SoraDCreatePanel("bagView"):show()
  //   elseif button == self.btnMail then
  //     SoraDPlaySound("uicontrol", 30)
  //     local mailView = SoraDCreatePanel("mailView")
  //     mailView:show()
  //     mailView:initWithData(nil)
  //   elseif button == self.btnAlliance then
  //     SoraDPlaySound("uicontrol", 29)
  //     self:initAllianceView()
  //   end
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::InitAllianceView(){
  // if worldMapDefine.isInRemains() then
  //   SoraDCreatePanel("allianceWarView"):show()
  // elseif worldMapDefine.isInLegendLord() then
  //   local legendTeamUtil = include("legendTeamUtil")
  //   legendTeamUtil.openTeamView()
  // elseif worldMapDefine.isInAtlantis() then
  //   SoraDCreatePanel("atlantisWarTeamView"):show()
  // else
  //   local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  //   if allianceMgr:hasJoinAlliance() then
  //     local panel = SoraDCreatePanel("allianceMainView")
  //     panel:show()
  //   else
  //     SoraDCreatePanel("allianceJoinView"):show()
  //   end
  // end
}

void UIMainBottom::UpdateGreenTip(RGreenTipsCount *p_BtnState){
  // if btnState.alliance then
  //   self.tipAllianceCount:setString(btnState.alliance)
  //   self.tipAlliance:setVisible(btnState.alliance > 0)
  //   self.tipAllianceCount:setVisible(btnState.alliance > 0)
  // end
  // if btnState.mail then
  //   self.tipMailCount:setString(btnState.mail)
  //   self.tipMail:setVisible(0 < btnState.mail)
  //   self.tipMailCount:setVisible(0 < btnState.mail)
  // end
  // if btnState.hero then
  //   self.tipHeroCount:setString(btnState.hero)
  //   self.tipHero:setVisible(0 < btnState.hero)
  //   self.tipHeroCount:setVisible(0 < btnState.hero)
  // end
  // if btnState.items then
  //   local shopltCtrl = gModuleMgr.sharedMgr("shopltCtrl")
  //   local isNew = shopltCtrl:getShopNewTag("all")
  //   self.tipItemsCount:setString(btnState.items)
  //   self.tipItems:setVisible(0 < btnState.items and not isNew)
  //   self.tipItemsCount:setVisible(0 < btnState.items and not isNew)
  //   self.itemNewIcon:setVisible(isNew)
  // end
}

void UIMainBottom::UpdateShopNewTag(EventCustom *p_Event){
  // local shopltCtrl = gModuleMgr.sharedMgr("shopltCtrl")
  // local isNew = shopltCtrl:getShopNewTag("all")
  // print("updateShopNewTag", isNew)
  // self.itemNewIcon:setVisible(isNew)
  // if isNew then
  //   self.tipItems:setVisible(false)
  //   self.tipItemsCount:setVisible(false)
  // end
}

void UIMainBottom::InitTipJump(Node *p_Node){
  // if not tipName then
  //   return
  // end
  // tipName:stopAllActions()
  // tipName:setPosition(cc.p(70, 60))
  // if SoraDFIsRA() then
  //   tipName:setPosition(cc.p(20, 60))
  // end
  // self.moveUp = cca.moveTo(0.5, tipName:getPositionX(), tipName:getPositionY() + 8)
  // self.moveDown = cca.moveTo(0.2, tipName:getPositionX(), tipName:getPositionY() - 5)
  // self.move = cca.moveTo(0.1, tipName:getPositionX(), tipName:getPositionY())
  // self.moveAct = cca.seq({
  //   cca.delay(5),
  //   self.moveUp,
  //   self.moveDown,
  //   self.moveUp,
  //   self.moveDown,
  //   self.moveUp,
  //   self.moveDown,
  //   self.move
  // })
  // tipName:runAction(cca.repeatForever(self.moveAct))
}

void UIMainBottom::OnSkillClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 13)
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  //   local panel = SoraDCreatePanel("skillNewActiveView")
  //   panel:show()
  // end
}

void UIMainBottom::OnReplayClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAIN_STOP_RECORD_SCREEN"
  //   })
  // end
}

void UIMainBottom::UpdateBtnLuckyRecharge(EventCustom *p_Event){
  // if not clientEventMgr.judgeIsOpen(gActivityTimeActivityID.LUCKY_RECHARGE_TASK_ACTIVIYT) then
  //   self.btnLuckyRecharge:setVisible(false)
  //   self:updateBtnContainer()
  //   return
  // end
  // if worldMapDefine.inInCrossWar() then
  //   self.btnLuckyRecharge:setVisible(false)
  //   self:updateBtnContainer()
  //   return
  // end
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

void UIMainBottom::OnLuckyReachergeClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("eventLuckyRechargeView"):show()
  // end
}

void UIMainBottom::StopRecording(EventCustom *p_Event){
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

void UIMainBottom::OpenUIAlliance(EventCustom *p_Event){
  InitAllianceView();
}

void UIMainBottom::CurrentShowViewType(EventCustom *p_Event){
  // local viewType = data.viewType
  // self.viewChangeType = viewType
  // if self.viewChangeType == VIEW_TYPE_CITY then
  //   self.imgWorldCity:loadTexture("btn_main_world.png", ccui.TextureResType.plistType)
  //   self.nodeQuestGuide:setVisible(true)
  //   self:createExpostulationTimer()
  //   self:initAccountBind()
  //   self:updateBtnContainer()
  //   self:showOrHideGuideView()
  // else
  //   self.imgWorldCity:loadTexture("btn_main_city.png", ccui.TextureResType.plistType)
  //   self.nodeQuestGuide:setVisible(false)
  //   self:deleteExpostulationTimer()
  //   self.btnAccount:setVisible(false)
  // end
  // self:btnNeckLaceRankCheck()
  // self:updateEventcenter()
  // self:checkWallDefend()
  // self:initHelpAllBtn()
  // self:sortBottomQuestBtns()
}

void UIMainBottom::MsgUpdateMailIconNumber(EventCustom *p_Event){
  // local numberNewMailTotal = mailMgr:getNewMailNum()
  // if numberNewMailTotal == 0 then
  //   self.tipMail:setVisible(false)
  // else
  //   self.tipMail:setVisible(true)
  //   self.tipMailCount:setString(tostring(numberNewMailTotal))
  // end
}

void UIMainBottom::sMsgUpdateNumberNewMail(EventCustom *p_Event){
  MsgUpdateMailIconNumber(p_Event);
}

void UIMainBottom::CheckWatchTower(EventCustom *p_Event){
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

void UIMainBottom::CheckRomanSoul(EventCustom *p_Event){
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

void UIMainBottom::CheckWallDefend(EventCustom *p_Event){
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

void UIMainBottom::BtnPyramidBattleCheck(EventCustom *p_Event){
  // local pyramidWarCtrl = gametop.playertop_:getModule("pyramidWarCtrl")
  // local canShow, leftTime = pyramidWarCtrl:isShowEnterPyramidWar()
  // print("btnPyramidBattleCheck", canShow, leftTime)
  // canShow = canShow and not worldMapDefine.isInWar()
  // self.btnPyramidBattle:setVisible(canShow)
  // self.txtPyramidBattleTime:beginTime(leftTime or 0)
  // self.btnPyramidPlayoffs:setVisible(false)
  // self:updateBtnContainer()
}

void UIMainBottom::BtnNeckLaceRankCheck(EventCustom *p_Event){
  // self.btnNeckLaceRank:setVisible(false)
  // self:updateBtnContainer()
}

void UIMainBottom::MsgHegemonClean(EventCustom *p_Event){
  // self:btnHegemonManagerCheck()
  // self:btnHegemonBattleCheck()
}

void UIMainBottom::BtnCityUnlockCheck(EventCustom *p_Event){
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


void UIMainBottom::BtnPayBackCheck(EventCustom *p_Event){
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

void UIMainBottom::AddPrinceGiftNewBuffButton(EventCustom *p_Event){
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

void UIMainBottom::AddPrinceGiftBuffButton(EventCustom *p_Event){
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

void UIMainBottom::BtnNewPlayerBuffCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnSultansBackWelCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnHegemonBattleCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnKingdomManagerCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnLegendKingManagerCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnHegemonManagerCheck(EventCustom *p_Event){
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

void UIMainBottom::BtnTrainPowerManagerCheck(){
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

void UIMainBottom::RefreshTrainPower(EventCustom *p_Event){
  // if not data then
  //   return
  // end
  // if data.eventID == gActivityTimeActivityID.TRAIN_POWER_ACTIVITY or data.activityID == gActivityTimeActivityID.TRAIN_POWER_ACTIVITY then
  //   self:btnTrainPowerManagerCheck()
  // end
}

void UIMainBottom::BtnWatchTowerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("watchTowerView")
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnWallBurningClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("defendView"):show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnKingdomManagerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
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

void UIMainBottom::BtnLegendKingManagerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local legendaryKingView = SoraDCreatePanel("legendaryKingView")
  //   legendaryKingView:show()
  //   legendaryKingView:init({viewType = 2})
  // end
}

void UIMainBottom::BtnLegendInviteClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   if not SoraDSearchPanelFromManagerByName("legendTeamInvitedView") then
  //     local panel = SoraDCreatePanel("legendTeamInvitedView")
  //     panel:show()
  //     panel:initData()
  //   end
  // end
}

void UIMainBottom::BtnRadianceWarClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local radianceWarUtil = include("radianceWarUtil")
  //   radianceWarUtil.openRadianceWarView()
  // end
}

void UIMainBottom::BtnHegemonManagerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
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

void UIMainBottom::BtnHegemonBattleClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("hegemonActivity"):show()
  // end
}

void UIMainBottom::BtnTrainPowerClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 49)
  //   local panel = SoraDCreatePanel("trainPowerView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnRomanSoulClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("watchTowerSoulView")
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnPyramidPlayoffsClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("pyramidAllianceGiftView"):show()
  // end
}

void UIMainBottom::BtnPyramidBattleClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   SoraDCreatePanel("pyramidBattleView"):show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //   })
  // end
}

void UIMainBottom::BtnAccountClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 48)
  //   local panel = SoraDCreatePanel("commonAccountBonusBox")
  //   panel:show()
  // end
}

void UIMainBottom::BtnNeckLaceRankClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("ringRankView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnCityUnlockClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("cityUpgradeUnlockView")
  //   panel:initData(panel.unlockInfo)
  //   panel:show()
  // end
}

void UIMainBottom::BtnNewPlayerBuffClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("citybuffView")
  //   panel:show()
  //   panel:openNewPlayerView()
  // end
}

void UIMainBottom::BtnPrinceGiftNewBuffClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("princeGiftNewBuffPreviewPopView")
  //   local princeGiftNewCtrl = SoraDGetCtrl("princeGiftNewCtrl")
  //   panel:initData(princeGiftNewCtrl:getBuffDesc())
  //   panel:show()
  // end
}

void UIMainBottom::BtnPrinceGiftBuffClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("princeGiftBuffStrengthenView")
  //   panel:show()
  // end
}

void UIMainBottom::BtnSwitchClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   self.btnSwitchType = -self.btnSwitchType
  //   self.btnSwitch:setTouchEnabled(false)
  //   self:switchBottonBtn()
  // end
}

void UIMainBottom::SwitchBottonBtn(){
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

void UIMainBottom::UpdateBtnContainer(EventCustom *p_Event){
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

void UIMainBottom::AddKOChoiceButton(EventCustom *p_Event){
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

void UIMainBottom::OnKOChoiceClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if eventType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local panel = SoraDCreatePanel("koUserNotifyView")
  //   panel:show()
  // end
}

void UIMainBottom::AddSixYearActivityButton(){
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

void UIMainBottom::AddHarvestSeasonButton(EventCustom *p_Event){
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

void UIMainBottom::RecevieItemChangeMsg(EventCustom *p_Event){
  // if redata and redata.itemType and gItemType.HERO_CHIP == redata.itemType then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_GREEN_POINT_UPDATE",
  //     type = GREEN_POINT_NOTICE_TYPE.HERO
  //   })
  // end
}


void UIMainBottom::GreenPointUpdate(EventCustom *p_Event){
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

void UIMainBottom::GreenPointUpdateByType(EventCustom *p_Event){
  // if GREEN_POINT_NOTICE_TYPE.ALLIANCE == data.type then
  //   self:updateGreenPointAlliance()
  // end
}

void UIMainBottom::UpdateGreenPointAlliance(){
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

void UIMainBottom::UpdateGreenPointRadianceWar(EventCustom *p_Event){
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

void UIMainBottom::ShowLongTimeUnlogin(EventCustom *p_Event){
  //SoraDShowMsgBox(i18n("brightWar_text_155"), i18n("common_text_054"), nil, nil, {canNotClose = true})
}

void UIMainBottom::OpenRadianceWarning(bool p_IsOpen){
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

void UIMainBottom::OpenWarning(bool p_IsOpen){
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

void UIMainBottom::StartRecordScreen(EventCustom *p_Event){
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

void UIMainBottom::RecordTimeTick(float p_Delta){
  // gSDKDef.GAME_RECORD_TIME = gSDKDef.GAME_RECORD_TIME + 1
  // self.textVideo:setString(SoraDConvertSecondToString(gSDKDef.GAME_RECORD_TIME))
}

void UIMainBottom::OnExitOther(){
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

void UIMainBottom::ShowWallFireEffect(){
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

void UIMainBottom::HideWallFireEffect(){
  // local node_pyramid_effect = self.btnWallBurning:getChildByName("Node_pyramid_effect")
  // local node_normal_effect = self.btnWallBurning:getChildByName("Node_normal_effect")
  // node_pyramid_effect:setVisible(false)
  // node_normal_effect:setVisible(false)
}

void UIMainBottom::AddFirstJoinAllianceAnimation(){
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

void UIMainBottom::RemovefirstJoinAllianceAnimation(EventCustom *p_Event){
  // display.removeAnimationCache("firstJoinAllianceGold")
  // if self.btnAlliance and self.btnAlliance:getChildByName("Sprite_join") then
  //   self.btnAlliance:removeChildByName("Sprite_join")
  // end
  // local allianceCtrl = gametop.playertop_:getModule("allianceCtrl")
  // allianceCtrl:resetAllianceInvitePopInfo()
  // self:initAllianceInvitePop()
  // userSDKManager.report2firebase("jointAlliance")
}

void UIMainBottom::ShowAllianceInWarEffect(){
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

void UIMainBottom::GetEventCenterReturn(EventCustom *p_Event){
  // self:updateEventcenter()
  // if type(redata.activityID) == "table" then
  //   for _, v in pairs(redata.activityID) do
  //     self:getEventCenterReturn_imp(v)
  //   end
  // elseif type(redata.activityID) == "number" then
  //   self:getEventCenterReturn_imp(redata.activityID)
  // end
}

void UIMainBottom::GetEventCenterReturn_Imp(EventCustom *p_Event){
  // local activityID = data.activityID
  // local eventID = data.eventID
  // if gActivityTimeActivityID.LIMITED_DISCOUNT_ACTIVITY == activityID then
  //   self:updateItemsBtn()
  // elseif gActivityTimeActivityID.ALLIANCE_MOBILIZATION_ACTIVITY == activityID or gActivityTimeActivityID.ALLIANCE_MOBILIZATION_ACTIVITY == eventID then
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

void UIMainBottom::UpdateItemsBtn(){
  // local allianceDesRead = include("allianceDesRead")
  // local limitTimeDiscountShopAPI = include("limitTimeDiscountShopAPI")
  // local status, remainTime = limitTimeDiscountShopAPI:getActivityInfo()
  // if status and not allianceDesRead.getPlayerConquestWarMigration(false) and not allianceDesRead.getPlayerBattleGroundMigration(false) then
  //   self:showFireBorder()
  // else
  //   self:showFireBorder(true)
  // end
}

void UIMainBottom::UpdateBtnStatues(EventCustom *p_Event){
  // local lordLevel = lordInfoCtrl:getLordLevel()
  // self.btnSkill:getParent():setVisible(lordLevel >= 4)
  // if self.btnSkill:getParent():isVisible() then
  //   self.btnManager:getParent():setPositionY(204)
  // else
  //   self.btnManager:getParent():setPositionY(122)
  // end
}

void UIMainBottom::ShowFireBorder(bool p_IsRemove){
  // if isRemove then
  //   self.Node_discountEffect:setVisible(false)
  //   return
  // end
  // self.Node_discountEffect:setVisible(true)
  // local Image_dh = self.Node_discountEffect:getChildByName("Image_dh")
  // SoraDFadeINOUT(Image_dh)
}

void UIMainBottom::SortBottomQuestBtns(EventCustom *p_Event){
  // if self.viewChangeType ~= VIEW_TYPE_CITY then
  //   local posy = 240
  //   if worldMapDefine.isInLegendLord() then
  //     posy = 420
  //   elseif worldMapDefine.isInRemains() then
  //     posy = 620
  //   elseif worldMapDefine.isInRadiance() then
  //     posy = 520
  //   elseif worldMapDefine.isInAtlantis() then
  //     local worldMap = SoraDCurrentSceneShowView("worldMapView")
  //     if worldMap and worldMap.getBottomQuestBtnsOffsetY then
  //       posy = worldMap:getBottomQuestBtnsOffsetY()
  //     else
  //       posy = 600
  //     end
  //   end
  //   local btnTableName = {
  //     "btnWatchTower",
  //     "luckyEffectNode",
  //     "luckyBlessNode",
  //     "btnLegendInvite",
  //     "btnRadianceWar"
  //   }
  //   for _, v in ipairs(btnTableName) do
  //     if self[v] and self[v]:isVisible() then
  //       self[v]:setPosition(SoraDFPoint(585, posy, 640))
  //       posy = posy + 80
  //     end
  //   end
  // else
  //   local basePosy = 170
  //   if self.nodeQuestGuide:isVisible() then
  //     basePosy = 250
  //   end
  //   local basePosx = 585
  //   local posy = basePosy
  //   local posx = basePosx
  //   local btnTableName = {
  //     "btnWallBurning",
  //     "btnWatchTower",
  //     "btnHelpAll",
  //     "btnAccount",
  //     "luckyEffectNode",
  //     "luckyBlessNode",
  //     "btnLegendInvite",
  //     "btnRadianceWar"
  //   }
  //   local hCount = 3
  //   if display.height < 960 then
  //     hCount = 2
  //   elseif display.height >= 1136 then
  //     hCount = 4
  //   end
  //   local index = 1
  //   for i, v in ipairs(btnTableName) do
  //     if self[v] and self[v]:isVisible() then
  //       local _h = index % hCount == 0 and hCount or index % hCount
  //       local _l = math.ceil(index / hCount)
  //       local realPosy = posy + (_h - 1) * 80
  //       self[v]:setPosition(SoraDFPoint(posx - (_l - 1) * 90, realPosy, 640))
  //       index = index + 1
  //     end
  //   end
  // end
}

void UIMainBottom::InitHelpAllBtn(EventCustom *p_Event){
  // if not self.btnHelpAll then
  //   local effect = SoraDCreateCSBNode("alliancehelpEffect")
  //   effect:addTo(self.Node_area_lb)
  //   effect:setVisible(false)
  //   effect:setName("alliancehelpEffect")
  //   local Image_btn = SoraDGetChildByName(effect, "Image_btn")
  //   Image_btn:addTouchEventListener(handler(self, self.btnHelpAllClick))
  //   effect.redNum = SoraDGetChildByName(effect, "Text_questNum")
  //   self.btnHelpAll = effect
  // end
  // if self.viewChangeType ~= VIEW_TYPE_CITY then
  //   self.btnHelpAll:setVisible(false)
  //   self:sortBottomQuestBtns()
  //   return
  // end
  // local allianceHelp = SoraDGetCtrl("allianceHelp")
  // if allianceHelp:getIsCanHelp() then
  //   self.btnHelpAll:setVisible(true)
  //   local helpCount = #allianceHelp:getHelpList().otherhelplist
  //   self.btnHelpAll.redNum:setString(helpCount)
  // else
  //   self.btnHelpAll:setVisible(false)
  // end
  // self:sortBottomQuestBtns()
}

void UIMainBottom::BtnHelpAllClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local allianceHelp = SoraDGetCtrl("allianceHelp", gametop)
  //   allianceHelp:reqHelpAll()
  // end
}

void UIMainBottom::InitBattleOpenBtn(){
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

void UIMainBottom::RefreshBattleOpenBtn(float p_Delta){
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
  // if remainsTeamCtrl:isActiveOpen() and (remainsTeamCtrl:isWarMatchBegin() or remainsTeamCtrl:isTeamCanInWar() and remainsTeamCtrl:isHasTeam()) then
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

void UIMainBottom::BtnBattleOpenClick(Ref *p_Sender, Widget::TouchEventType p_Type)
{
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

void UIMainBottom::BtnPayBackClick(Ref *p_Sender, Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   uiManager:show("BackMoneyPopView")
  // end
}

ui::Button *UIMainBottom::GetBtnTarget(const GString &p_Name){
  // print("    function MainUIBottom:getBtnTarget(id)")
  // if id == "mail" then
  //   return self.btnMail
  // elseif id == "alliance" then
  //   return self.btnAlliance
  // elseif id == "items" then
  //   return self.btnItems
  // elseif id == "hero" then
  //   return self.btnHero
  // end
  return nullptr;
}

void UIMainBottom::CheckRemainsWar(){
  // if worldMapDefine.isInRemains() then
  //   self.labelAllianceName:setString(i18n("common_text_047"))
  // elseif worldMapDefine.isInLegendLord() then
  //   self.labelAllianceName:setString(i18n("free_team_text_41"))
  // elseif worldMapDefine.isInAtlantis() then
  //   self.labelAllianceName:setString(i18n("atlantiswar_text_0139"))
  // else
  //   self.labelAllianceName:setString(i18n("common_text_069"))
  // end
}

void UIMainBottom::MsgInvitedInfoLegend(EventCustom *p_Event){
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

void UIMainBottom::OpenReportMail(EventCustom *p_Event){
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

void UIMainBottom::CheckPreDownloadStatus(EventCustom *p_Event){
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

void UIMainBottom::CheckPreDownload(EventCustom *p_Event){
  // local preDownloadUtil = include("preDownloadUtil")
  // preDownloadUtil.checkPreDownloadAutoStart()
}

void UIMainBottom::OnPreDownloadSuc(EventCustom *p_Event){
  // local preDownloadUtil = include("preDownloadUtil")
  // preDownloadUtil.checkSendPredownloadOk()
}