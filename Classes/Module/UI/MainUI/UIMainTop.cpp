#include "UIMainTop.h"
#include "Module/Activity/ActivityShow.Ctrl.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/UI/EventCenter/EventTemplate/LostRuins/LostRuins.Ctrl.h"
#include "Module/UI/Panel/Lord/LordInfo/UILordPowerView.h"
#include "Module/Vip/ExaltedPrivilege.Ctrl.h"
// #include "spine/SkeletonAnimation.h"

UIMainTop* UIMainTop::Create() {
  auto l_Panel = Create("UiParts/MainUi/mainUITop.csb");
  l_Panel->setName("UIMainTop");
  return l_Panel;
}

void UIMainTop::AddSubViews() {}

void UIMainTop::Ctor() {
  //   self.playerInfo = {}
  UIBaseView::Ctor();
  AddSubViews();
  n_NodeLOD = GBase::DGetChildByName<Node*>(this, "Node_LOD");
  n_NodeAreaRt = GBase::DGetChildByName<Node*>(n_NodeLOD, "Node_area_rt");
  n_NodeAreaLt = GBase::DGetChildByName<Node*>(n_NodeLOD, "Node_area_lt");
  n_NodeAreaT = GBase::DGetChildByName<Node*>(this, "Node_area_t");
  n_NodeGold = GBase::DGetExtendChildFromCCSByName<UICommonGoldTop>(this, "CCS_commonGoldTop_gold");
  n_NodeGold->SetMainUIStyle();
  n_NodeGold->ShowAnimation();
  n_ResMenu = GBase::DGetExtendChildFromCCSByName<UICommonResourcesMenu>(this, "CCS_commonResourcesMenu_menu");
  n_ResMenu->RunAnimation();
  n_ResMenu->HiddleMainUI(false);
  n_BtnVip = GBase::DGetChildByName<ui::Button*>(this, "Button_vip");
  n_BtnVip->setPressedActionEnabled(false);
  n_ImgVip = GBase::DGetChildByName<ui::ImageView*>(this, "Image_vip");
  n_SpriteActiveVip = GBase::DGetChildByName<Sprite*>(this, "Sprite_active");
  n_SpriteActiveVip->setVisible(false);
  n_LabelVip = GBase::DGetChildByName<ui::TextBMFont*>(this, "BitmapFontLabel_vip_en");
  n_SpVipPointFrm = GBase::DGetChildByName<Sprite*>(this, "Sprite_vipNumFrm");
  n_ImgLvBg = GBase::DGetChildByName<ui::ImageView*>(this, "Image_levelBg");
  n_LabelLv = GBase::DGetChildByName<ui::Text*>(this, "BitmapFontLabel_leve");
  n_SpriteHead = GBase::DGetChildByName<Sprite*>(this, "Sprite_head");
  n_BarEXPBg = GBase::DGetChildByName<Sprite*>(this, "progressbar_main_exp");
  n_BarEXP = GBase::DGetChildByName<ui::LoadingBar*>(this, "LoadingBar_exp");
  // n_BarEXP->setClipEnabled(false);
  n_BarHPBg = GBase::DGetChildByName<Sprite*>(this, "progressbar_main_stamina");
  n_BarStamina = GBase::DGetChildByName<ui::LoadingBar*>(this, "LoadingBar_stamina");
  //   self.barStamina:setClipEnabled(false)
  n_NodeHead = GBase::DGetChildByName<ui::Layout*>(this, "Panel_headFrame");
  n_NodeWeakPoint = GBase::DGetChildByName<Node*>(this, "Node_headWeakPoint");
  n_SpriteLordHead = GBase::DGetChildByName<Sprite*>(this, "sprite_lord_head");
  n_BtnHead = GBase::DGetChildByName<ui::Button*>(this, "Button_head");
  n_SpriteHeadRedPoint = GBase::DGetChildByName<Sprite*>(this, "Sprite_headRedPoint");
  n_SpriteHeadRedPoint->setVisible(false);
  n_IconVipNew = GBase::DGetChildByName<Sprite*>(this, "iconVipNew");
  n_IconVipNew->setVisible(false);
  n_ImgPower = GBase::DGetChildByName<Sprite*>(this, "sprite_power");
  n_LabelPower = GBase::DGetChildByName<ui::Text*>(this, "Text_powerValue");
  n_ScoreLabelPower = UICommonScoreLabel::DCreateScoreLabel(n_LabelPower, true);
  n_BtnPower = GBase::DGetChildByName<ui::Button*>(this, "Button_power");
  n_IconGem = GBase::DGetChildByName<Sprite*>(this, "icon_main_powegem");
  n_IconGem->setVisible(GBase::Const::Get()->IsArClient);
  n_LabelRechargeTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(this, "Text_rechargeTime"));
  n_BtnRechargeActivity = GBase::DGetChildByName<ui::Button*>(this, "Button_recharge");
  n_NodeRecharge = GBase::DGetChildByName<Node*>(this, "Node_recharge");
  n_NodeRechargeIcon = n_NodeRecharge->getChildByName("Node_icon");
  n_NodeEvent = GBase::DGetChildByName<Node*>(this, "Node_event");
  n_NodeEventIcon = n_NodeEvent->getChildByName<Node*>("Node_icon");
  n_ImageEvent = n_NodeEventIcon->getChildByName<ui::ImageView*>("Image_event");
  n_NodeNew = GBase::DGetChildByName<Node*>(this, "Node_new");
  auto l_NodeNewJump = GBase::DCreateAnimation("UiParts/Parts/Common/Animation/animationNewJump.csb").First;
  l_NodeNewJump->setPosition(38, -60);
  n_NodeNew->addChild(l_NodeNewJump);
  n_BtnEvent = GBase::DGetChildByName<ui::Button*>(this, "Button_event");
  n_LabelEventTime = GBase::DGetChildByName<ui::Text*>(this, "Text_eventTime");
  n_LabelEventTime->setString(Translate::i18n("buildDes_name_106"));
  n_SpriteEventRedPoint = GBase::DGetChildByName<Sprite*>(n_NodeEvent, "Sprite_numBg");
  n_LabelEventRedNum = GBase::DGetChildByName<ui::Text*>(n_NodeEvent, "Text_num");
  n_SpriteEventRedPoint->setVisible(false);
  n_PanelTips = GBase::DGetChildByName<ui::Layout*>(n_NodeEvent, "Panel_tips");
  GBase::DGetChildByName<ui::Text*>(n_PanelTips, "Text_tips")->setString(Translate::i18n("activity_text_03"));
  n_PanelTips->setVisible(false);
  n_ImageEvent->loadTexture("btn_main_new_activity.png", ui::Widget::TextureResType::PLIST);
  n_ImageEvent->ignoreContentAdaptWithSize(true);
  n_NodeNewJourney = GBase::DGetChildByName<Node*>(this, "Node_newJourney");
  n_NodeNewJourney->setVisible(false);
  n_NodeEtNew = GBase::DGetChildByName<Node*>(n_NodeNewJourney, "Node_etNew");
  // TODO: FullPath
  auto l_NodeNewJump_2 = GBase::DCreateAnimation("UiParts/Parts/Common/Animation/animationNewJump.csb").First;
  l_NodeNewJump_2->setPosition(38, -60);
  n_NodeEtNew->addChild(l_NodeNewJump_2);
  n_NodeIconJourney = GBase::DGetChildByName<Node*>(n_NodeNewJourney, "Node_iconJourney");
  auto l_NodeNewJump_3 = GBase::DCreateAnimation("UiParts/Parts/Common/Animation/animationJourney.csb").First;
  n_NodeIconJourney->addChild(l_NodeNewJump_3);
  n_TextNewJourney = GBase::DGetChildByName<ui::Text*>(n_NodeNewJourney, "Text_newJourney");
  n_TextNewJourney->setString(Translate::i18n("journey_art_1001"));
  n_ButtonNewJourney = GBase::DGetChildByName<ui::Button*>(n_NodeNewJourney, "Button_newJourney");
  n_ButtonNewJourney->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnJourneyClick, this));
  n_NodeLucky = GBase::DGetChildByName<Node*>(this, "Node_rechargeLucky");
  n_LuckyNumFrm = GBase::DGetChildByName<Sprite*>(this, "Sprite_numFrm");
  n_LuckyNumTxt = GBase::DGetChildByName<ui::Text*>(this, "Text_pointNum");
  n_BtnLucky = GBase::DGetChildByName<ui::Button*>(this, "Button_rechargeLucky");
  n_NodeLuckyIcon = n_NodeLucky->getChildByName("Node_icon");
  n_TxtLuckyTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(this, "Text_luckyTime"));
  n_NodeCrazy = GBase::DGetChildByName<Node*>(this, "Node_crazy");
  n_NodeCrazyIcon = n_NodeCrazy->getChildByName("Node_icon");
  n_BtnCrazy = GBase::DGetChildByName<ui::Button*>(this, "Button_crazy");
  n_TxtCrazyTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(this, "Text_crazyTime"));
  n_TxtCrazyTime->setVisible(false);
  n_RedPointCrazy = GBase::DGetChildByName<Sprite*>(this, "Sprite_crazyRedPoint");
  n_NodeCrazy->getChildByName("Sprite_redBg")->setVisible(false);
  n_NodeHeroGift = GBase::DGetChildByName<Node*>(this, "Node_choiceLucky");
  GBase::DGetChildByName<Node*>(n_NodeHeroGift, "Sprite_numFrmChoice")->setVisible(false);
  n_TxtHeroGiftTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(this, "Text_choiceLuckyTime"));
  n_BtnHeroGift = GBase::DGetChildByName<ui::Button*>(this, "Button_choiceLucky");
  n_BtnHeroGift->addTouchEventListener(CC_CALLBACK_2(UIMainTop::BtnHeroRechargeClick, this));
  auto l_NodeLucky = dynamic_cast<ui::Widget*>(n_NodeLucky);
  InitKingNode(nullptr);
  InitSultansBackNode(nullptr);

  n_BtnExplain = GBase::DGetChildByName<ui::Button*>(this, "Button_gameExplain");
  n_BtnExplain->setPosition(Vec2(GBase::DFIsRA() ? 490.0f : 150.0f, -100.0f));
  m_TableBuilder.clear();
  m_TableBuilder.push_back(GBase::DGetExtendChildFromCCSByName<UIBuilderIcon>(this, "CCS_builderIcon_iron"));
  m_TableBuilder.push_back(GBase::DGetExtendChildFromCCSByName<UIBuilderIcon>(this, "CCS_builderIcon_gold"));
  AddBuildStarButton();
  n_NodeTroops = GBase::DGetExtendChildFromCCSByName<UIMarchingTroops>(this, "CCS_marchingTroops_troop");
  n_NodeTroops->setVisible(false);
  n_NodeLostRuins = GBase::DGetChildByName<Node*>(this, "Node_LostRuins");
  n_LostRuinsTaskIcon = GBase::DGetChildByName<ui::ImageView*>(n_NodeLostRuins, "Image_TaskIcon");
  n_LostRuinsProgress = UIHtmlRichText::DChangeTextToHtml(GBase::DGetChildByName<ui::Text*>(n_NodeLostRuins, "Text_Progress"));
  n_LostRuinsTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(n_NodeLostRuins, "Text_LeftTime"));
  n_LostRuinsGetAwardBtn = GBase::DGetChildByName<ui::Button*>(n_NodeLostRuins, "Button_LostGetAward");
  n_LostRuinsGetAwardBtn->addTouchEventListener(CC_CALLBACK_2(UIMainTop::BtnLostRuinsGetAward, this));
  n_LostRuinsGetAwardBtn->setTitleText(Translate::i18n("common_text_1146"));
  n_TextLostTaskStatus = GBase::DGetChildByName<ui::Text*>(n_LostRuinsGetAwardBtn, "Text_LostTaskStatus");
  n_TextLostTaskStatus->setString(Translate::i18n("common_text_2601"));
  RegisterListener();
  InitView();
  InitTimer();
  InitData();
  n_NodeStylePower = GBase::DGetChildByName<Node*>(this, "Node_style_power");
  n_NodeStyleHead = GBase::DGetChildByName<Node*>(this, "Node_style_head");
  InitStyle();
}

void UIMainTop::UpdateHeadPos(EventCustom* p_Event) {
  if (GBase::DIsBrave8Level()) {
    n_NodeHead->setPositionX(12);
    m_OffestY = 45;
  } else {
    n_NodeHead->setPositionX(57);
    m_OffestY = 0;
  }
  RangeLeftNodes();
  RangeLeft2Nodes();
  UpdateBuilderPos(-100 - m_OffestY);
}

void UIMainTop::UpdateBuilderPos(float p_OffsetY) {
  for (int32 i = 0; i < (int32)m_TableBuilder.size(); i++) {
    m_TableBuilder.at(i)->setPositionY(p_OffsetY - 80 * (i - 1));
    if (std::floor(GDisplay::Get()->height == 853 /**and v:getBuilderType() == gQueueTypeDef.build_star_queue_privilege */)) {
      auto l_IsHide = GBase::DConfigGet<bool>("Game:GameSettingView:gameExplainSwitch~bool");
      m_TableBuilder.at(i)->setPosition(Vec2(GBase::DFIsRA() ? 490 : 150, l_IsHide ? -100 : -180));
    }
  }
}

void UIMainTop::UpdateLostRuinsNode(EventCustom* p_Event) {
  auto l_LostRuinsCtrl = LostRuinsCtrl::Get();
  auto l_QuestInfo = l_LostRuinsCtrl->GetRunningQuestInfo();
  if (ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::LostRuinsActivity, false) /*and next(questInfo) */) {
    //   if self.teamMainUIWidget and self.teamMainUIWidget:isVisible() then
    //     self.teamMainUIWidget:setPositionY(-87)
    //     self.nodeLostRuins:setPositionY(-267)
    //   elseif self.newTrailTeamUI and self.newTrailTeamUI:isVisible() then
    //     self.newTrailTeamUI:setPositionY(-30)
    //     self.nodeLostRuins:setPositionY(-255)
    //   else
    //     self.nodeLostRuins:setPositionY(-67)
    //   end
    //   self.nodeLostRuins:setVisible(true)
    //   if questInfo.isFinish then
    //     self.lostRuinsProgress:setVisible(false)
    //     self.textLostTaskStatus:setVisible(true)
    //     self.lostRuinsGetAwardBtn:setVisible(true)
    //     self.lostRuinsTime:getParent():setVisible(false)
    //   else
    //     self.lostRuinsProgress:setVisible(true)
    //     self.textLostTaskStatus:setVisible(false)
    //     self.lostRuinsGetAwardBtn:setVisible(false)
    //     self.lostRuinsTime:getParent():setVisible(true)
    //     local lostRuinsRead = include("lostRuinsRead")
    //     local totalTime = lostRuinsRead.getTaskTimeByQuestId(questInfo.questId)
    //     local leftTime = math.max(0, totalTime - (serviceFunctions.systemTime() - lostRuinsCtrl:getRunningQuestInfo(questInfo.questId).startTime))
    //     self.lostRuinsTime:setTimeUpdateListener(function(leftTime)
    //       if leftTime <= 300 then
    //         self.lostRuinsTime:setColor(cc.c3b(254, 1, 1))
    //       else
    //         self.lostRuinsTime:setColor(display.COLOR_WHITE)
    //       end
    //     end)
    //     self.lostRuinsTime:beginTime(leftTime)
    //     local eventQuestRead = include("eventQuestRead")
    //     local progress = lostRuinsCtrl:getQuestProgress(questInfo.questId)
    //     local aim = eventQuestRead.getAim(questInfo.questId)
    //     print("updateLostRuinsNode", questInfo.questId, progress, leftTime)
    //     self.lostRuinsProgress:setString(i18n_html("common_text_155", {member = progress, total = aim}, {
    //       member = {color = "#FE0101"}
    //     }))
    //   end
  } else {
    n_NodeLostRuins->setVisible(false);
  }
}

void UIMainTop::UpdateWindTowerNode(EventCustom* p_Event) {
  // local windTowerCtrl = SoraDGetCtrl("windTowerCtrl")
  // local questInfo = windTowerCtrl:getRunningQuestInfo()
  // print("updateWindTowerNode", _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.WIND_TOWER_ACTIVITY), windTowerCtrl:isRunningQuest())
  // if _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.WIND_TOWER_ACTIVITY, false) and next(questInfo) then
  //   if not self.windTowerMainWidget then
  //     local windTowerMainWidget = include("windTowerMainWidget").new()
  //     windTowerMainWidget:setPosition(cc.p(320, -67))
  //     windTowerMainWidget:addTo(self)
  //     self.windTowerMainWidget = windTowerMainWidget
  //   end
  //   if self.windTowerMainWidget then
  //     if self.teamMainUIWidget and self.teamMainUIWidget:isVisible() then
  //       self.teamMainUIWidget:setPositionY(-87)
  //       self.windTowerMainWidget:setPositionY(-267)
  //     elseif self.newTrailTeamUI and self.newTrailTeamUI:isVisible() then
  //       self.newTrailTeamUI:setPositionY(-30)
  //       self.windTowerMainWidget:setPositionY(-255)
  //     else
  //       self.windTowerMainWidget:setPositionY(-67)
  //     end
  //     self.windTowerMainWidget:initData()
  //   end
  // elseif self.windTowerMainWidget then
  //   self.windTowerMainWidget:removeFromParent()
  //   self.windTowerMainWidget = nil
  // end
}

void UIMainTop::UpdateSnowWolfLostNode(EventCustom* p_Event) {
  // local snowWolfLostCtrl = SoraDGetCtrl("snowWolfLostCtrl")
  // local questInfo = snowWolfLostCtrl:getRunningQuestInfo()
  // print("updateLostRuinsNode", clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SNOWWOLF_LOST_ACTIVITY), snowWolfLostCtrl:isRunningQuest())
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.SNOWWOLF_LOST_ACTIVITY, false) and next(questInfo) then
  //   self.lostRuinsTaskIcon:loadTexture("Map_build_snowWolfLost.png", ccui.TextureResType.plistType)
  //   self.lostRuinsTaskIcon:setContentSize(cc.size(136, 127))
  //   self.lostRuinsTaskIcon:setScale(0.5)
  //   self.lostRuinsTaskIcon:setPosition(100, 0)
  //   self.lostRuinsGetAwardBtn:addTouchEventListener(function(button, type)
  //     if type == ccui.TouchEventType.ended then
  //       SoraDPlaySound("uicontrol", 19)
  //       local snowWolfLostCtrl = SoraDGetCtrl("snowWolfLostCtrl")
  //       snowWolfLostCtrl:reqSnowWolfLostRecieveReward()
  //     end
  //   end)
  //   if self.teamMainUIWidget and self.teamMainUIWidget:isVisible() then
  //     self.teamMainUIWidget:setPositionY(-87)
  //     self.nodeLostRuins:setPositionY(-267)
  //   elseif self.newTrailTeamUI and self.newTrailTeamUI:isVisible() then
  //     self.newTrailTeamUI:setPositionY(-30)
  //     self.nodeLostRuins:setPositionY(-255)
  //   else
  //     self.nodeLostRuins:setPositionY(-67)
  //   end
  //   self.nodeLostRuins:setVisible(true)
  //   if questInfo.isFinish then
  //     self.lostRuinsProgress:setVisible(false)
  //     self.textLostTaskStatus:setVisible(true)
  //     self.lostRuinsGetAwardBtn:setVisible(true)
  //     self.lostRuinsTime:getParent():setVisible(false)
  //   else
  //     self.lostRuinsProgress:setVisible(true)
  //     self.textLostTaskStatus:setVisible(false)
  //     self.lostRuinsGetAwardBtn:setVisible(false)
  //     self.lostRuinsTime:getParent():setVisible(true)
  //     local snowWolfLostRead = include("snowWolfLostRead")
  //     local totalTime = snowWolfLostRead.getTaskTimeByQuestId(questInfo.questId)
  //     local leftTime = math.max(0, totalTime - (serviceFunctions.systemTime() - snowWolfLostCtrl:getRunningQuestInfo(questInfo.questId).startTime))
  //     self.lostRuinsTime:setTimeUpdateListener(function(leftTime)
  //       if leftTime <= 300 then
  //         self.lostRuinsTime:setColor(cc.c3b(254, 1, 1))
  //       else
  //         self.lostRuinsTime:setColor(display.COLOR_WHITE)
  //       end
  //     end)
  //     self.lostRuinsTime:beginTime(leftTime)
  //     local eventQuestRead = include("eventQuestRead")
  //     local progress = snowWolfLostCtrl:getQuestProgress(questInfo.questId)
  //     local aim = eventQuestRead.getAim(questInfo.questId)
  //     print("updateLostRuinsNode", questInfo.questId, progress, leftTime)
  //     self.lostRuinsProgress:setString(i18n_html("common_text_155", {member = progress, total = aim}, {
  //       member = {color = "#FE0101"}
  //     }))
  //   end
  // else
  //   self.nodeLostRuins:setVisible(false)
  // end
}

void UIMainTop::InitHalloweenShineEffect() {
  auto l_effectShine = GBase::DCreateAnimation("Node_Effect_wsj01", nullptr, true).First;
  n_EffectShine = l_effectShine;
  n_EffectShine->setPosition(195, 15);
  n_ImgPower->addChild(n_EffectShine);
}

void UIMainTop::InitStyle() {
  auto l_Style = GGlobal::Get()->MainUIStyle;
  if (l_Style == EMainUIStyle::QuickSand) {
    auto l_TopNode = GBase::DCreateAnimation("mainUITop_style_ztsz", nullptr).First;
    n_NodeStylePower->addChild(l_TopNode);
    auto l_ActNode = GBase::DCreateAnimation("Node_Effect_liusha1", nullptr, true).First;
    l_ActNode->setPosition(320, 15);
    n_NodeAreaT->addChild(l_ActNode, 999);
    l_ActNode->setName("actNode_style");
  } else if (l_Style == EMainUIStyle::Chritmas) {
    auto l_TopNode = GBase::DCreateAnimation("mainUITop_style_chritmas", nullptr).First;
    n_NodeStyleHead->addChild(l_TopNode);
    n_ImgPower->setSpriteFrame("farmer_sdzjm_zdl.png");
    n_LabelPower->setPositionX(128.5);
    n_BtnPower->setPosition(Vec2(128.5, 61.5));
  } else if (l_Style == EMainUIStyle::Easter) {
    // auto l_Spine = spine::SkeletonAnimation::createWithBinaryFile("spine/zhandouli.skel", "spine/zhandouli.atlas");
    // l_Spine->setPosition(65, 35);
    // l_Spine->setAnimation(0, "animation", true);
    // n_ImgPower->addChild(l_Spine);
    // auto l_Spine2 = spine::SkeletonAnimation::createWithBinaryFile("spine/zhandouli.skel", "spine/zhandouli.atlas");
    // l_Spine2->setPosition(250, 35);
    // l_Spine2->setAnimation(0, "animation", true);
    // n_ImgPower->addChild(l_Spine2);
  } else if (l_Style == EMainUIStyle::Halloween) {
    n_ImgPower->setPositionY(-20);
    n_ImgPower->setLocalZOrder(10);
    n_ImgPower->setSpriteFrame("frame_main_halloween_power01.png");
    n_LabelPower->setPosition(Vec2(200, 62));
    n_BtnPower->setPosition(Vec2(200, 70));
    n_BtnVip->setLocalZOrder(10);
    n_NodeGold->setLocalZOrder(10);
    InitHalloweenShineEffect();
  }
}

void UIMainTop::InitKingNode(EventCustom* p_Event) {
  if (ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::NEW_SERVER_RANK_MATCH)) {
    n_NodeKingCom = n_NodeLucky;
    n_NodeKingCom->setVisible(true);
    n_NodeKingCom->setName("nodeKingCom");
    n_NodeKingCom->setPositionX(n_NodeCrazy->getPositionX());
    n_BtnKing = GBase::DGetChildByName<ui::Button*>(n_NodeKingCom, "Button_rechargeLucky");
    n_KingRed = GBase::DGetChildByName<Sprite*>(n_NodeKingCom, "Sprite_numFrm");
    n_TxtKingTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(n_NodeKingCom, "Text_luckyTime"));
    n_NodeKingIcon = n_NodeKingCom->getChildByName("Node_icon");
    auto l_Node = GBase::DCreateAnimation("UiParts/Parts/Common/Animation/kingCompetitionEnterEffect.csb").First;
    n_NodeKingIcon->addChild(l_Node);
    l_Node->setPosition(Vec2(8, 40));
    l_Node->setScale(1.2f);
    GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite*>(l_Node, "Sprite_9"));
    GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite*>(l_Node, "Sprite_9_0"));
    GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite*>(l_Node, "dh_zhounianjm_01_3"));
    n_BtnKing->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  }
  // local kingCompetitionltCtrl = include("kingCompetitionltCtrl")
  // if not clientEventMgr.judgeIsOpen(gActivityTimeActivityID.NEW_SERVER_RANK_MATCH) then
  //   self.nodeKingCom:setVisible(false)
  //   self:rangeLeft2Nodes()
  //   return
  // else
  //   self.nodeKingCom:setVisible(true)
  //   self:rangeLeft2Nodes()
  // end
  // local function checkRedNode()
  //   local kingCompetitionCtrl = gametop.playertop_:getModule("kingCompetitionCtrl")
  //   local info = lordInfoCtrl:getBaseInfo()
  //   local first = 0
  //   local lv = SoraDGetCastleLv()
  //   local lvCfg = {
  //     SoraDGetCastleLv(),
  //     SoraDGetLordLv(),
  //     info.totalFc
  //   }
  //   for i = 1, 3 do
  //     local num = kingCompetitionltCtrl:getTargetNum(i)
  //     lv = lvCfg[i]
  //     print("lvlvlv: " .. lv)
  //     if kingCompetitionCtrl:checkRedNode(i, num, first, lv) then
  //       return true
  //     end
  //     first = first + num
  //   end
  //   return false
  // end
  // self.kingRed:setVisible(checkRedNode())
  // self.txtKingTime:setTimeLast(function(ticket)
  //   return i18n(ticket)
  // end)
  // self.txtKingTime:setTimeEndListener(function()
  //   self.nodeKingCom:setVisible(false)
  //   self:rangeLeft2Nodes()
  // end)
  // local activityTime = SoraDGetCtrl("activityShowCtrl"):getTimeInfoByID(gActivityTimeActivityID.NEW_SERVER_RANK_MATCH)
  // if activityTime then
  //   self.txtKingTime:beginTime(activityTime.timerNode.timer:getRemainTime())
  // end
}

void UIMainTop::InitSultansBackNode(EventCustom* p_Event) {
  auto l_NeedShow = GBase::DConfigGet<bool>("Game:sultansBackView:showInMainUITop~bool", true);
  auto l_ActivityIdList = ActivityShowCtrl::Get()->GetActivityGroup(EActivityCenter::SultanBack);
  auto l_IsOpen = false;
  for (auto l_ActivityId : l_ActivityIdList) {
    if (ClientEventMgr::Get()->JudgeIsOpen(l_ActivityId.first)) {
      l_IsOpen = true;
      break;
    }
  }
  if (!l_IsOpen) {
    RangeLeft2Nodes();
    return;
  }
  n_NodeSultansBack = n_NodeLucky;
  n_NodeSultansBack->setVisible(true);
  n_NodeSultansBack->setName("nodeSultansBack");
  n_NodeSultansBack->setPositionX(n_NodeCrazy->getPositionX());
  auto l_Sprite = BaseCreate::CreateSprite("icon_sudanback_mian.png");
  n_NodeSultansBack->getChildByName("Node_icon")->addChild(l_Sprite);
  l_Sprite->setPosition(0, 36);
  auto l_EtSultan = GBase::DCreateAnimation("UiParts/Parts/Common/Animation/animationSultansBack.csb").First;
  l_EtSultan->setPosition(0, 36);
  n_NodeSultansBack->getChildByName("Node_icon")->addChild(l_EtSultan);
  n_BtnSultansBack = GBase::DGetChildByName<ui::Button*>(n_NodeSultansBack, "Button_rechargeLucky");
  n_BtnSultansBack->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_SultansBackRed = GBase::DGetChildByName<Sprite*>(n_NodeSultansBack, "Sprite_numFrm");
  n_TxtSultansBackTime = UITimerLabel::DCreateTimerLabel(GBase::DGetChildByName<Node*>(n_NodeSultansBack, "Text_luckyTime"));

  // if not isOpen or not needShow or worldMapDefine.isInNewTrial() then
  //   self.nodeSultansBack:setVisible(false)
  //   self:rangeLeft2Nodes()
  //   return
  // else
  //   self.nodeSultansBack:setVisible(true)
  //   self:rangeLeft2Nodes()
  // end
  // self.txtSultansBackTime:setString(i18n("activity_name_9001289"))
  // local showRed, redNum = sultansBackCtrl:getReceiveStatusAndNum()
  // self.sultansBackRed:setVisible(showRed)
  // local text = self.sultansBackRed:getChildByName("Text_pointNum")
  // if redNum > 0 then
  //   text:setVisible(true)
  //   text:setString(redNum)
  // else
  //   text:setVisible(false)
  // end
}

Label* UIMainTop::ExchangeGroupText(Label* p_Label, float p_Height) {
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

void UIMainTop::TradeBoardMsgShowTip(EventCustom* p_Event) {
  // if redata and redata.info then
  //   local publicRead = include("publicRead")
  //   if redata.showType and redata.showType == "newTradeBoard" then
  //     local itemName = i18n("common_text_1460", {
  //       name = publicRead.getName(redata.info._item),
  //       count = redata.info._num
  //     })
  //     SoraDShowMsgTip(i18n("auction_text_30", {item = itemName}))
  //   else
  //     SoraDShowMsgTip(i18n("mail_text_277", {
  //       name = publicRead.getName(redata.info._item),
  //       num = redata.info._num
  //     }))
  //   end
  // end
}

bool UIMainTop::IsRedPoint() {
  // local achievementctrl = gametop.playertop_:getModule("achievementctrl")
  // local honourNum = achievementctrl:getTipNum()
  // if honourNum == nil then
  //   honourNum = 0 or honourNum
  // end
  // if honourNum >= 1 then
  //   return true
  // end
  // local haveReward = not lordInfoCtrl:getLordInfo().militaryRankInfo.gotReward and 0 < lordInfoCtrl:getLordInfo().militaryRankInfo.lastRank
  // if haveReward then
  //   return true
  // end
  // local lordSkillModuleAPI = include("lordSkillModuleAPI")
  // local skillPoint = lordSkillModuleAPI:getRemainPoint() or 0
  // local guardianCtrl = gametop.playertop_:getModule("guardianCtrl")
  // if guardianCtrl:getIsCanReceive() then
  //   return true
  // end
  // local welfareInfo = exaltedPrivilegeCtrl:getWelfareInfo()
  // if 0 < table.nums(welfareInfo) then
  //   return true
  // end
  // if skillPoint >= 1 then
  //   return true
  // end
  // local isNewTotal = exaltedPrivilegeCtrl:isNewFlagTotalJudge()
  // if isNewTotal then
  //   return true
  // end
  // local equipmentMgr = include("equipmentMgr")
  // local equipSort = {
  //   gEquipmentPart.WEAPON,
  //   gEquipmentPart.BODY,
  //   gEquipmentPart.HEAD,
  //   gEquipmentPart.LEG,
  //   gEquipmentPart.FOOT,
  //   gEquipmentPart.HAND
  // }
  // for i, v in ipairs(equipSort) do
  //   if 0 < #equipmentMgr.getAllEquipmentByPart(v) and equipmentMgr.getPartEquipment(v) == nil then
  //     return true
  //   end
  // end
  return false;
}

void UIMainTop::UpdateRedPoint(EventCustom* p_Event) {
  // self.spriteHeadRedPoint:setVisible(not not isRedPoint())
}

void UIMainTop::BtnPowerClickCallBack(Ref* p_Button, ui::Widget::TouchEventType p_Type) {
  if (p_Type == ui::Widget::TouchEventType::ENDED) {
    GBase::PlaySound("uicontrol", 19);
    n_ImgPower->setScale(1);
    auto l_LordPowerView = UILordPowerView::Create();
    l_LordPowerView->InitPanel();
    l_LordPowerView->Show();
  } else if (p_Type == ui::Widget::TouchEventType::BEGAN) {
    n_ImgPower->setScale(1.1f);
  } else if (p_Type == ui::Widget::TouchEventType::CANCELED) {
    n_ImgPower->setScale(1);
  }
}

void UIMainTop::BtnLostRuinsGetAward(Ref* p_Button, ui::Widget::TouchEventType p_Type) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 19)
  //   local lostRuinsCtrl = SoraDGetCtrl("lostRuinsCtrl")
  //   lostRuinsCtrl:reqLostRuinsRecieveReward()
  // end
}

Node* UIMainTop::GetResTarget(EResource p_ResType) { return n_ResMenu->GetResTarget(p_ResType); }

void UIMainTop::onEnter() {
  UIBaseView::onEnter();
  OnMessageListener();
}

void UIMainTop::onExit() {
  UIBaseView::onExit();
  // print("main scene  exit ")
  // if self.upgradePowerHandle ~= nil then
  //   cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.upgradePowerHandle)
  //   self.upgradePowerHandle = nil
  // end
  // SoraDRemoveMessageByTarget(self)
}

void UIMainTop::OnMessageListener() {
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", CC_CALLBACK_1(UIMainTop::ReLoginFinish, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_ONSHOW", CC_CALLBACK_1(UIMainTop::SetMarchingTroopsVisible, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPDATE_BASE", CC_CALLBACK_1(UIMainTop::UpdateLordInfo, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_PHYSICAL_RECOVERY", CC_CALLBACK_1(UIMainTop::UpdateLordInfo, this));
  GBase::DAddMessage(this, "MESSAGE_LORDVALUE_VIP", CC_CALLBACK_1(UIMainTop::UpdateVip, this));
  GBase::DAddMessage(this, "MESSAGE_LORDVALUE_VIP_GIFTREFRESH", CC_CALLBACK_1(UIMainTop::UpdateVip, this));
  GBase::DAddMessage(this, "MESSAGE_WALLS_DEFENCE_DESTROY", CC_CALLBACK_1(UIMainTop::DefineWallDestroy, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_ACTIVETIMEOUT", CC_CALLBACK_1(UIMainTop::InitRechargeBtn, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_RUIRUILADDER_REFRESH", CC_CALLBACK_1(UIMainTop::InitRechargeBtn, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_DAILYFREEGIFT_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_DAILYSPECIALGIFTBUY_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_DAILYSPECIALGIFT_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(UIMainTop::GetEventCenterReturn, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_ACTIVETIMEOUT", [](EventCustom* p_Event) {
    //   if redata and redata.redata and redata.redata.rid then
    //     local rechargeRead = include("rechargeRead")
    //     local info = rechargeRead.getPageViewData(redata.redata.rid)
    //     if info then
    //       if gRechargeActiveModelType.MONTHLYGIFT == info.activeModelType then
    //         self:updateRechargeRedPoint()
    //       elseif gRechargeActiveModelType.WEEKLY_GIFT == info.activeModelType then
    //         self:updateRechargeRedPoint()
    //       elseif gRechargeActiveModelType.SUBSCRIPTION == info.activeModelType then
    //         self:updateRechargeRedPoint()
    //       end
    //     end
    //   end
  });
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_WEEKLY_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_MONTHLY_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_TAKE_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRechargeRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_RELASH", CC_CALLBACK_1(UIMainTop::InitCrazyBtn, this));
  GBase::DAddMessage(this, "MESSAGE_CLIENT_RECHARGECENTER_LUCKYGIFTPOINTREFRESH", CC_CALLBACK_1(UIMainTop::LuckyBtnPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_LUCKYGIFTREFRESH", CC_CALLBACK_1(UIMainTop::InitLuckyBtn, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RECHARGECENTER_REFRESH", CC_CALLBACK_1(UIMainTop::RechargeCloseLoading, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_HP", CC_CALLBACK_1(UIMainTop::ShowLordHPChange, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_POWER_EXP", CC_CALLBACK_1(UIMainTop::ShowLordPowerEXPChange, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_POWER_CHANGE", CC_CALLBACK_1(UIMainTop::LordPowerChange, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_EXP_CHANGE", CC_CALLBACK_1(UIMainTop::ShowLordEXPChange, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_DISPATCH_ARMY", CC_CALLBACK_1(UIMainTop::SetLordHPUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_KINGDOMBATTLE_VICTORY", CC_CALLBACK_1(UIMainTop::KingBattleFun, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_WAR_END", CC_CALLBACK_1(UIMainTop::LegendLordBattleVectoryFun, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_START", CC_CALLBACK_1(UIMainTop::PyramidBattleStartFun, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_PYRAMIDBATTLE_PERSONAL_RESULT", CC_CALLBACK_1(UIMainTop::EndPyramid, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LEGENDLORD_PERSONAL_RESULT", CC_CALLBACK_1(UIMainTop::EndLegendLordWar, this));
  GBase::DAddMessage(this, "MESSAGE_UI_EQUIP_GET_SUCCESS", CC_CALLBACK_1(UIMainTop::GetEquipSuccess, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EQUIP_WEAR_BACK", CC_CALLBACK_1(UIMainTop::GetEquipSuccess, this));
  GBase::DAddMessage(this, "MESSAGE_MAIN_SERVERTIME_CALLBAK", CC_CALLBACK_1(UIMainTop::CheckServerIsOK4SDKCallBack, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_RESET_SKILL", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPDATE_SKILL", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPGRADE_SKILL", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_SKILL_SET_ACTIVE_BACK", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_HONOUR_ACHIEVEMENT", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_LORDMILITARY_GET_REWARD", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_LORDMILITARY_UPDATE", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_GUARDIAN_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_EXCLUSIVE_VIP_WELFARE_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EQUIP_DISASSEMBLE_BACK", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EQUIP_FORGE_BACK", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EQUIP_LIMIT_TIMEOUT", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_MARKET_TRADEBOARDRETURN_MSGGETTIP", CC_CALLBACK_1(UIMainTop::TradeBoardMsgShowTip, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_ESCORT_REQ_CLOSEST_BUILD", CC_CALLBACK_1(UIMainTop::HandlEscort, this));
  GBase::DAddMessage(this, "MESSAGE_UI_EVENTCENTER_REFRESHISNEW", CC_CALLBACK_1(UIMainTop::InitEventNode, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH", CC_CALLBACK_1(UIMainTop::InitEventNode, this));
  GBase::DAddMessage(this, "MESSAGE_GREEN_POINT_UPDATE", CC_CALLBACK_1(UIMainTop::InitEventNode, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_END", CC_CALLBACK_1(UIMainTop::MsgGuideEnd, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_REMAINS_TEAM_INVITED_INFO", CC_CALLBACK_1(UIMainTop::MsgInvitedInfo, this));
  GBase::DAddMessage(this, "MESSAGE_UI_TEAM_MY_INFO", CC_CALLBACK_1(UIMainTop::UpdateTeamMainUIWidget, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_REMAINS_TEAM_MATCH_SUC", CC_CALLBACK_1(UIMainTop::OnTeamMatchSuc, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_REMAINS_WAR_BATTLE_END", CC_CALLBACK_1(UIMainTop::OnRemainsWarEnd, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_RADIANCE_WAR_BATTLE_END", CC_CALLBACK_1(UIMainTop::OnRadianceWarEnd, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_REMAINS_TEAM_JOIN", CC_CALLBACK_1(UIMainTop::OnRemainsWarTeamJoin, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_REMAINS_WAR_ATTACK_INFO", CC_CALLBACK_1(UIMainTop::UpdateAttackInfo, this));
  GBase::DAddMessage(this, "MESSAGE_UI_NEWTRIALMAINUI", CC_CALLBACK_1(UIMainTop::RefreshNewTrialUI, this));
  GBase::DAddMessage(this, "MESSAGE_NEWTRIAL_JOINTEAMLIST_REFRESH", CC_CALLBACK_1(UIMainTop::RefreshNewTrialTeam, this));
  GBase::DAddMessage(this, "MESSAGE_NEWTRIAL_BEGIN_REFRESH", CC_CALLBACK_1(UIMainTop::RefreshBeginNewTrial, this));
  GBase::DAddMessage(this, "MESSAGE_NEWTRIAL_END_REFRESH", CC_CALLBACK_1(UIMainTop::NewTrialEndRefresh, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_ROYAL_SUMMONS_GOLD", CC_CALLBACK_1(UIMainTop::RoyalSummonsGold, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_ANCIENT_REEL_GOLD", CC_CALLBACK_1(UIMainTop::AncientReelGold, this));
  GBase::DAddMessage(this, "MESSAGE_HERO_GIFT_RECHARGE_REFRESH", CC_CALLBACK_1(UIMainTop::InitHeroGiftBtn, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_KING_COMPETITION_GET_REWARD_SUCCESS", CC_CALLBACK_1(UIMainTop::InitKingNode, this));
  GBase::DAddMessage(this, "MESSAGE_EXCLUSIVE_VIP_CLEAN_NEW_FLAG", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_EXCLUSIVE_VIP_REFRESH_DATA", CC_CALLBACK_1(UIMainTop::UpdateRedPoint, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", CC_CALLBACK_1(UIMainTop::CastleLevelUp, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WORLDKINGDOM_LV_CHANGE", CC_CALLBACK_1(UIMainTop::KingdomLevelUp, this));
  GBase::DAddMessage(this, "MESSAGE_SECOND_STAR_BUILDING_BTN_REFRESH", CC_CALLBACK_1(UIMainTop::CheckSecondBuildStarButton, this));
  GBase::DAddMessage(this, "MESSAGE_SULTANSBACK_SETTING_REFRESH", CC_CALLBACK_1(UIMainTop::InitSultansBackNode, this));
  GBase::DAddMessage(this, "MESSAGE_LOST_RUINS_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateLostRuinsNode, this));
  GBase::DAddMessage(this, "MESSAGE_WIND_TOWER_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateWindTowerNode, this));
  GBase::DAddMessage(this, "MESSAGE_SNOWWOLF_LOST_REFRESH", CC_CALLBACK_1(UIMainTop::UpdateSnowWolfLostNode, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", CC_CALLBACK_1(UIMainTop::ShowOrHideGuideView, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITY_UPDATE_MAINUITOP_HEADPOS", CC_CALLBACK_1(UIMainTop::UpdateHeadPos, this));
  GBase::DAddMessage(this, "MESSAGE_EXCLUSIVE_VIP_INIT", CC_CALLBACK_1(UIMainTop::CheckSecondBuildStarButton, this));
}

void UIMainTop::ShowOrHideGuideView(EventCustom* p_Event) {
  // local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  // local guideStep = guideCtrl:getCurForceGuideStep()
  // self.Node_area_rt:setVisible(false)
  // print("MainUITopyyyyyyyyyy", guideStep)
  // if not guideStep then
  //   self.Node_area_rt:setVisible(true)
  // else
  //   self.Node_area_rt:setVisible(guideStep >= 2036)
  // end
}

void UIMainTop::ReLoginFinish(EventCustom* p_Event) {
  InitView();
  InitData();
  InitTimer();
  // userSDKManager.reportReline()
  // paymentManager.isInRecharging = false
  // paymentManager.reconsumePayWhenRelogin()
}

void UIMainTop::HandlEscort(EventCustom* p_Event) {
  // local retData = data.data
  // SoraDCloseLoading()
  // if retData.closestBuild == nil then
  //   return
  // end
  // local x = retData.closestBuild.x
  // local y = retData.closestBuild.y
  // if x ~= -1 and y ~= -1 then
  //   print("\229\188\128\229\167\139\232\183\179\232\189\172\229\136\176\229\157\144\230\160\135 -------", x, " ,", y)
  //   SoraDRemoveTopPanelFromManager()
  //   SoraDGotoWorldMapPoint(cc.p(x, y), true)
  // else
  //   SoraDShowMsgTip("Sorry! cannot find!")
  // end
}

void UIMainTop::GetEquipSuccess(EventCustom* p_Event) {
  // local lightSprite = self.nodeHead:getChildByName("Sprite_light")
  // if guideCtrl:isGuideOpen(gGuideModule.WEAR_EQUIPMENT) then
  //   if lightSprite == nil then
  //     lightSprite = display.newSprite("#dh_zhujiemian_01.png")
  //     SoraDMixtureGLONE(lightSprite)
  //     lightSprite:setName("Sprite_light")
  //     lightSprite:setPosition(cc.p(self.nodeHead:getContentSize().width / 2, 72.5))
  //     lightSprite:setScale(1.1)
  //     lightSprite:setOpacity(0)
  //     lightSprite:addTo(self.nodeHead, 1)
  //     lightSprite:runAction(cca.repeatForever(cca.seq({
  //       cca.fadeIn(0.5),
  //       cca.delay(0.1),
  //       cca.fadeOut(0.3),
  //       cca.delay(0.5)
  //     })))
  //   end
  // elseif lightSprite then
  //   lightSprite:removeFromParent()
  // end
  // self:updateRedPoint()
}

void UIMainTop::SetMarchingTroopsVisible(EventCustom* p_Event) {
  EScene l_ViewType = EScene::None;
  if (p_Event && p_Event->getUserData() != nullptr) l_ViewType = *static_cast<EScene*>(p_Event->getUserData());
  if (l_ViewType == EScene::None || m_CurrentViewType == l_ViewType) return;

  bool l_ShowBuilder = l_ViewType == EScene::City;
  n_NodeTroops->InitData(!l_ShowBuilder);
  for (auto l_Builder : m_TableBuilder) l_Builder->setVisible(l_ShowBuilder);

  if (n_NewTrailTeamUI) n_NewTrailTeamUI->setVisible(l_ShowBuilder);
  UpdateLostRuinsNode(nullptr);
  UpdateWindTowerNode(nullptr);
  UpdateSnowWolfLostNode(nullptr);
  m_CurrentViewType = l_ViewType;
  if (GBase::DConfigGet<bool>("Game:GameSettingView:gameExplainSwitch~bool")) n_BtnExplain->setVisible(l_ShowBuilder);
}

void UIMainTop::RegisterListener() {
  n_BtnVip->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_BtnHead->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_BtnRechargeActivity->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_BtnPower->addTouchEventListener(CC_CALLBACK_2(UIMainTop::BtnPowerClickCallBack, this));
  n_BtnEvent->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_BtnLucky->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_BtnCrazy->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
}

void UIMainTop::UpdateLordInfo(EventCustom* p_Event) {
  // self.playerInfo.player = lordInfoCtrl:getBaseInfo()
  // self:updatePlayer()
}

void UIMainTop::ShowLordHPChange(EventCustom* p_Event) {
  // self.hpReduceValue = data.hp
  // self.isUpdateHP = true
  // if self.isSetHPStyle and self.isUpdateHP then
  //   effectMainUITop.showLordPhysicalEffect(self)
  // end
}

void UIMainTop::ShowLordEXPChange(EventCustom* p_Event) {
  // self:initKingNode()
  // local isReachFullExp = self.playerInfo.player.isReachFullExp
  // if not isReachFullExp then
  //   effectMainUITop.showLordEXPChange(self, data)
  // end
}

void UIMainTop::ShowLordPowerEXPChange(EventCustom* p_Event) {
  // self:initKingNode()
  // local isReachFullExp = self.playerInfo.player.isReachFullExp
  // if not isReachFullExp then
  //   self.isShowEXP = true
  //   effectMainUITop.showLordPowerEXPEffect(self, data)
  // else
  //   self.isShowEXP = false
  //   self:lordPowerChange(self)
  // end
}

void UIMainTop::LordPowerChange(EventCustom* p_Event) {
  // self:initKingNode()
  // if self.isShowEXP then
  //   return
  // end
  // self.upgradePowerHandle = SoraDDelayCallOnce("MainUITop_UpdatePower", function()
  //   self.upgradePowerHandle = nil
  //   if self.updateLordPower then
  //     self:updateLordPower()
  //   end
  // end, 0.5)
}

void UIMainTop::UpdateLordPower() {
  // effectMainUITop.showLordPowerChange(self)
  // self.oriPower = self.curPower
}

void UIMainTop::OnBtnJourneyClick(Ref*, ui::Widget::TouchEventType) {
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   print("\230\150\176\230\156\141\229\190\129\233\128\148========")
  //   if _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.NEW_SERVER_JOURNEY_ACTIVITY, false) then
  //     userSDKManager.logEvent(gSDKDef.TDonEvent.newJourney_mainUI_enter_click, {})
  //     uiManager:show("NewJourney")
  //     SoraDConfigSet("Game:journey:readTime~integer", serviceFunctions.systemTime(), {byUID = true})
  //     self.Node_etNew:setVisible(false)
  //   else
  //     SoraDShowMsgTip(i18n("journey_text_1010"))
  //   end
  // end
}

void UIMainTop::OnBtnClick(Ref* p_Button, ui::Widget::TouchEventType p_Type) {
  //   if type == ccui.TouchEventType.ended then
  //     if button == self.btnGold then
  //       SoraDPlaySound("uicontrol", 25)
  //       local panel = SoraDCreatePanel("rechargeView")
  //       panel:show()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnVip then
  //       SoraDPlaySound("uicontrol", 22)
  //       local panel = SoraDCreatePanel("vipCenterView")
  //       panel:show()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnHead then
  //       if self.playerInfo.player.avatar and self.playerInfo.player.avatar ~= "" then
  //         SoraDPlaySound()
  //       else
  //         SoraDPlaySound("headClick", self.playerInfo.player.imageId)
  //       end
  //       local head = SoraDCreatePanel("lordView")
  //       head:initData(lordInfoCtrl:getLordInfo())
  //       head:show()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnRechargeActivity then
  //       SoraDPlaySound()
  //       self:popEventFrame()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnEvent then
  //       SoraDPlaySound("uicontrol", 12)
  //       self:popEventFromEventCenter()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnLucky then
  //       SoraDPlaySound("uicontrol", 18)
  //       advertiseCollect.TriggerEvent(gSDKDef.TDonEvent.advertise_lucky_gift)
  //       self:popLuckyFrame()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnCrazy then
  //       SoraDPlaySound()
  //       local cumuActiveCtrl = SoraDGetCtrl("cumuActiveCtrl")
  //       local activityID = cumuActiveCtrl:getActivityID()
  //       if clientEventMgr.judgeIsOpen(activityID, false) then
  //         userSDKManager.logEvent(gSDKDef.TDonEvent.click_crazy_trio, {eventid = activityID, position = 2})
  //         clientEventMgr.singleClickEvent(activityID, 3)
  //       end
  //     elseif button == self.btnKing then
  //       SoraDPlaySound("uicontrol", 18)
  //       if SoraDGetCtrl("cityCtrl"):getBuildMaxLv(BUILDID.CASTLE) >= CASTLE_LV5_LIMITED then
  //         SoraDCreatePanel("kingCompetitionView"):show()
  //       else
  //         SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV5_LIMITED}))
  //       end
  //       SoraDSendMessage({
  //         msg = "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE"
  //       })
  //     elseif button == self.btnSultansBack then
  //       SoraDPlaySound()
  //       SoraDCreatePanel("sultansBackView"):show()
  //     end
  //   end
}

void UIMainTop::BtnHeroRechargeClick(Ref*, ui::Widget::TouchEventType) {
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound("uicontrol", 50)
  //   local heroGiftCtrl = SoraDGetCtrl("heroGiftCtrl")
  //   SoraDConfigSet("Game:heroGiftCtrl:isNewGift~bool", false, {byUID = true})
  //   local heroID = heroGiftCtrl:getMinimumTimeGift().heroID
  //   SoraDConfigSet("Game:heroGiftCtrl:endHeroID~integer", heroID, {byUID = true})
  //   self:initHeroGiftBtn()
  //   local panel = SoraDCreatePanel("heroGiftRechargeView")
  //   panel:show()
  // end
}

void UIMainTop::InitView() {
  InitRechargeBtn(nullptr);
  InitCrazyBtn(nullptr);
  InitExplainBtn();
  InitLuckyBtn(nullptr);
  InitNewJourney();
  n_NodeGold->UpdateGold();
  UpdateRechargeRedPoint(nullptr);
  InitEventNode(nullptr);
  // TODO: self:lbsWeakPoint()
  UpdateTeamMainUIWidget(nullptr);
  RefreshNewTrialUI(nullptr);
  InitHeroGiftBtn(nullptr);
  InitKingNode(nullptr);
  InitSultansBackNode(nullptr);
  UpdateLostRuinsNode(nullptr);
  UpdateLostRuinsNode(nullptr);
  UpdateSnowWolfLostNode(nullptr);
  ShowOrHideGuideView(nullptr);
  UpdateHeadPos(nullptr);
}

void UIMainTop::InitData() {
  // TODO: self.playerInfo.player = lordInfoCtrl:getBaseInfo()
  UpdatePlayer(true);
  UpdateVip(nullptr);
  UpdateRedPoint(nullptr);
  n_ResMenu->UpdateResources();
  m_IsUpdateHP = false;
  m_IsSetHPStyle = false;
  m_IsShowEXP = false;
  n_HasShowNewTrialBox = nullptr;
}

void UIMainTop::InitTimer() {
  // local queueTypeList = {
  //   gQueueTypeDef.free_build_queue,
  //   gQueueTypeDef.charge_build_queue,
  //   gQueueTypeDef.build_star_queue,
  //   gQueueTypeDef.build_star_queue_privilege
  // }
  // for i, v in ipairs(self.tableBuilder) do
  //   v:initData(queueTypeList[i])
  // end
}

void UIMainTop::UpdatePlayer(bool p_IsFirst) {
  // self.labelLv:setString(tostring(self.playerInfo.player.leve))
  // SoraDGetHeadFromManager(self.spriteHead, self.playerInfo.player.imageId, self.playerInfo.player.avatar)
  // if self.playerInfo.player.isReachFullExp then
  //   self.barEXP:setPercent(100)
  // else
  //   self.barEXP:setPercent(self.playerInfo.player.exp * 100 / self.playerInfo.player.expUpper)
  // end
  // self.barStamina:setPercent(self.playerInfo.player.physical * 100 / self.playerInfo.player.physicalUpper)
  // self.curPower = self.playerInfo.player.totalFc
  // self.curEXP = self.playerInfo.player.exp
  // self.curLV = self.playerInfo.player.leve
  // if isFirst then
  //   self.oriPower = self.playerInfo.player.totalFc
  //   self.oriEXP = self.playerInfo.player.exp
  //   self.labelPower:setString(string.formatnumberthousands(self.playerInfo.player.totalFc))
  // end
  // if not isFirst and self.oriPower ~= self.curPower then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_LORDINFO_POWER_CHANGE"
  //   })
  // end
  // if self.curPower > self.oriPower then
  //   advertiseCollect.TriggerEvent(gSDKDef.TDonEvent.advertise_fight_point, self.curPower)
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAIN_AGREEMENT_BOX",
  //     showPush = true
  //   })
  // end
}

void UIMainTop::UpdateVip(EventCustom* p_Event) {
  // self.playerInfo.vip = lordInfoCtrl:getVip()
  // local vipLocalData = include("vipLocalData")
  // local vipLv = self.playerInfo.vip[1]
  // local vipNum, isSVip = vipLocalData:getVipNum(vipLv)
  // self.labelVip:setString(vipLocalData:getVipSmallFntChar(self.playerInfo.vip[1]))
  // self.vipImage = nil
  // if self.playerInfo.vip[2] then
  //   self.imgVip:setVisible(false)
  //   self.spriteActiveVip:setVisible(true)
  //   local frames = display.newFrames("dh_anniuzjm_%.2d.png", 1, 12)
  //   local animation = display.newAnimation(frames, 1.5 / #frames)
  //   self.spriteActiveVip:stopAllActions()
  //   self.spriteActiveVip:playAnimationForever(animation)
  // else
  //   self.imgVip:getVirtualRenderer():setState(1)
  //   self.imgVip:setVisible(true)
  //   self.spriteActiveVip:stopAllActions()
  //   self.spriteActiveVip:setVisible(false)
  // end
  // if self.playerInfo.vip[1] >= VIP_LV5_LIMITED and not lordInfoCtrl:vipDailyGiftBeGot() and self.playerInfo.vip[2] then
  //   self.SpVipPointFrm:setVisible(true)
  // else
  //   self.SpVipPointFrm:setVisible(false)
  // end
}

void UIMainTop::MsgGuideEnd(EventCustom* p_Event) {
  // self:lbsWeakPoint()
}

void UIMainTop::MsgInvitedInfo(EventCustom* p_Event) {
  // local remainsTeamCtrl = gametop.playertop_:getModule("remainsTeamCtrl")
  // if remainsTeamCtrl:isHasInvitedInfo() and not SoraDSearchPanelFromManagerByName("teamInvitedView") and SoraDIsGameGuide() == nil then
  //   local panel = SoraDCreatePanel("teamInvitedView")
  //   panel:show()
  // end
}

void UIMainTop::BtnExplainClick(Ref* p_Button, ui::Widget::TouchEventType p_Type) {
  // if btnType == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   self.btnExplain:setTouchEnabled(false)
  //   transition.execute(self.btnExplain, nil, {
  //     delay = 1,
  //     onComplete = function()
  //       self.btnExplain:setTouchEnabled(true)
  //       SoraDShowMsgBox(i18n("common_text_1027"), i18n("common_text_204"), nil, function(eventType)
  //         if eventType == MSGBOX_CALLBACK_YES then
  //           SoraDConfigSet("Game:GameSettingView:gameExplainSwitch~bool", true)
  //           self.btnExplain:setVisible(false)
  //         end
  //       end)
  //     end
  //   })
  //   userSDKManager.showFAQs()
  // end
}

void UIMainTop::InitExplainBtn() {
  // if SoraDConfigGet("Game:GameSettingView:gameExplainSwitch~bool") then
  //   self.btnExplain:setVisible(false)
  // else
  //   self.btnExplain:addTouchEventListener(handler(self, self.btnExplainClick))
  // end
}

void UIMainTop::RangeLeftNodes() {
  // local btnTableName = {
  //   "nodeLucky",
  //   "nodeRecharge",
  //   "nodeEvent",
  //   "nodeGiftCar",
  //   "Node_newJourney"
  // }
  // self:rangeNodes(btnTableName)
  // SoraDSendMessage({
  //   msg = "MESSAGE_MAIN_BTN_UPDATE"
  // })
}

void UIMainTop::RangeLeft2Nodes() {
  // local btnTableName = {
  //   "nodeSultansBack",
  //   "nodeKingCom",
  //   "nodeCrazy",
  //   "nodeHeroGift"
  // }
  // self:rangeNodes(btnTableName)
}

void UIMainTop::RangeNodes(GVector<GString> p_TableBtnName, float p_PosY) {
  // local visiableNodes = {}
  // for i, v in ipairs(btnTableName) do
  //   if self[v] and self[v]:isVisible() then
  //     table.insert(visiableNodes, self[v])
  //   end
  // end
  // local posY = _posY or {
  //   -140,
  //   -240,
  //   -340,
  //   -440,
  //   -540
  // }
  // for i, v in ipairs(visiableNodes) do
  //   local cPosY = posY[i] or posY[i - 1] - 100
  //   v:setPositionY(cPosY - self.offsetY)
  // end
}

void UIMainTop::PopLuckyFrame() {
  // local gametop = gModuleMgr.getObject("gametop")
  // local luckyGiftCtrl = gametop.playertop_:getModule("luckyGiftCtrl")
  // local newLuckyGift = luckyGiftCtrl:getNewLuckyGiftData()
  // if next(newLuckyGift) ~= nil then
  //   local panel = SoraDCreatePanel("rechargePopFrame")
  //   panel:initData(newLuckyGift.luckyGiftID, gRechargeActiveFromEnum.ROAD02)
  //   panel:show()
  // end
}

void UIMainTop::InitEventNode(EventCustom* p_Event) {
  // local newTB = clientEventMgr.getNewInfo()
  // local redTB = clientEventMgr.getRedPointInfo()
  // if next(newTB) then
  //   self.Node_new:setVisible(true)
  //   self.spriteEventRedPoint:setVisible(false)
  //   self.labEventRedNum:setVisible(false)
  // elseif next(redTB) then
  //   self.Node_new:setVisible(false)
  //   self.spriteEventRedPoint:setVisible(true)
  //   self.labEventRedNum:setVisible(false)
  // else
  //   self.Node_new:setVisible(false)
  //   self.spriteEventRedPoint:setVisible(false)
  //   self.labEventRedNum:setVisible(false)
  // end
  // if not self.isInitEventDone then
  //   self.isInitEventDone = true
  //   if next(newTB) and SoraDGetCastleLv() <= CASTLE_LV26_LIMITED then
  //     local clickTime = SoraDConfigGet("Game:mainUITop:clickEventCenterView~integer", {byUID = true})
  //     if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
  //       self.Panel_tips:setVisible(true)
  //       self.Panel_tips:runAction(cca.seq({
  //         cca.delay(5),
  //         cca.callFunc(function()
  //           self.Panel_tips:setVisible(false)
  //         end)
  //       }))
  //     end
  //   end
  // end
  // self:updateSultansBackRed()
}

void UIMainTop::UpdateSultansBackRed() {
  // if self.nodeSultansBack:isVisible() then
  //   local sultansBackCtrl = SoraDGetCtrl("sultansBackCtrl")
  //   local showRed, redNum = sultansBackCtrl:getReceiveStatusAndNum()
  //   self.sultansBackRed:setVisible(showRed)
  //   self.sultansBackRed:getChildByName("Text_pointNum"):setString(redNum)
  // end
}

void UIMainTop::InitNewJourney() {
  // local isOpen = _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.NEW_SERVER_JOURNEY_ACTIVITY, false)
  // print("initNewJourney isOpen=", isOpen)
  // self.Node_newJourney:setVisible(isOpen)
  // self:rangeLeftNodes()
  // if isOpen then
  //   local status1 = cumuActiveCtrl:isAllCrazyTrioClaimed()
  //   local status2 = princeGiftNewCtrl:getIsBuy()
  //   local status3 = castleRewardCtrl:getIsBuy()
  //   local status4 = false
  //   local buffMonthData = rechargeActivityCtrl:getMonthActivityList()
  //   if next(buffMonthData) then
  //     for k, v in pairs(buffMonthData) do
  //       if v.isbuy and v.totalday and v.totalday >= 30 then
  //         status4 = true
  //         break
  //       end
  //     end
  //   end
  //   local status = status1 or status2 or status3 or status4
  //   self.Node_etNew:setVisible(not status)
  //   if not status then
  //     local readTime = SoraDConfigGet("Game:journey:readTime~integer", {byUID = true}) or 0
  //     local isSameDay = serviceFunctions.isSameDay(readTime)
  //     self.Node_etNew:setVisible(not isSameDay)
  //   end
  // end
}

void UIMainTop::InitLuckyBtn(EventCustom* p_Event) {
  // local gametop = gModuleMgr.getObject("gametop")
  // local luckyGiftCtrl = gametop.playertop_:getModule("luckyGiftCtrl")
  // local newLuckyGift = luckyGiftCtrl:getNewLuckyGiftData()
  // local function showNumPoint(...)
  //   local pNum = luckyGiftCtrl:getRedPointNum()
  //   if pNum > 0 then
  //     self.luckyNumFrm:setVisible(true)
  //     self.luckyNumTxt:setString(pNum)
  //   else
  //     self.luckyNumFrm:setVisible(false)
  //   end
  // end
  // local function addLuckyEffect(eventType)
  //   if self.nodeLuckyIcon then
  //     self.nodeLuckyIcon:removeAllChildren()
  //     local giftNode = effectEventGift.getGiftNode(eventType)
  //     giftNode:addTo(self.nodeLuckyIcon)
  //   end
  // end
  // if not worldMapDefine.isInNewTrial() and next(newLuckyGift) then
  //   self.nodeLucky:setScale(0.1)
  //   self.nodeLucky:setVisible(true)
  //   transition.execute(self.nodeLucky, cca.seq({
  //     cca.scaleTo(0.8, 1)
  //   }), {easing = "BACKIN"})
  //   if newLuckyGift.lastTime and newLuckyGift.lastTime > 0 then
  //     self.txtLuckyTime:beginTime(newLuckyGift.lastTime)
  //   end
  //   showNumPoint()
  //   local rechargeRead = include("rechargeRead")
  //   local info = rechargeRead.getPageViewData(tonumber(newLuckyGift.luckyGiftID))
  //   addLuckyEffect(info.eventType)
  // else
  //   self.nodeLucky:setVisible(false)
  // end
  // self:rangeLeftNodes()
  // if redata and redata.pushNew then
  //   self:getLuckyGiftEffect()
  // end
  // if target then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //   })
  // end
}

void UIMainTop::InitHeroGiftBtn(EventCustom* p_Event) {
  // local heroGiftIcon = display.newSprite("#icon_main_heroGift.png")
  // heroGiftIcon:addTo(self.nodeHeroGift:getChildByName("Node_iconChoice"))
  // heroGiftIcon:setPositionY(40)
  // local heroGiftCtrl = SoraDGetCtrl("heroGiftCtrl")
  // local rechargeList = heroGiftCtrl:getRechargeList()
  // if not worldMapDefine.isInNewTrial() and rechargeList and next(rechargeList) then
  //   self.nodeHeroGift:setVisible(true)
  //   do
  //     local info = heroGiftCtrl:getMinimumTimeGift()
  //     local firstHeroID = info.heroID
  //     local leftTime = info.endTime - serviceFunctions.systemTime()
  //     self.txtHeroGiftTime:beginTime(leftTime)
  //     self.txtHeroGiftTime:setTimeUpdateListener(function(leftTime)
  //       local lastHeroID = SoraDConfigGet("Game:heroGiftCtrl:endHeroID~integer", {byUID = true})
  //       if lastHeroID ~= firstHeroID and leftTime < 86400 then
  //         SoraDGetChildByName(self.nodeHeroGift, "Sprite_numFrmChoice"):setVisible(true)
  //       end
  //     end)
  //     local lastHeroID = SoraDConfigGet("Game:heroGiftCtrl:endHeroID~integer", {byUID = true})
  //     local newGift = SoraDConfigGet("Game:heroGiftCtrl:isNewGift~bool", {byUID = true})
  //     local isEnd = false
  //     if lastHeroID ~= firstHeroID and leftTime < 86400 then
  //       isEnd = true
  //     end
  //     SoraDGetChildByName(self.nodeHeroGift, "Sprite_numFrmChoice"):setVisible(isEnd or newGift)
  //   end
  // else
  //   self.nodeHeroGift:setVisible(false)
  // end
  // self:rangeLeft2Nodes()
}

void UIMainTop::LuckyBtnPoint(EventCustom* p_Event) {
  // self.luckyNumFrm:setVisible(false)
}

void UIMainTop::PopEventFrame(bool p_IsAdd) {
  // print("self.eventIndex", self.eventIndex, isAdd)
  // if isAdd then
  //   local function funcQeueueRecharge()
  //     local panel = SoraDCreatePanel("rechargePopFrame")
  //     if panel:initData(tonumber(self.eventIndex), gRechargeActiveFromEnum.ROAD01) then
  //       panel:show()
  //     end
  //   end
  //   SoraDAddPopupWindow(funcQeueueRecharge, uiDequeTypeTab.RECHARGE)
  // else
  //   local panel = SoraDCreatePanel("rechargePopFrame")
  //   if panel:initData(tonumber(self.eventIndex), gRechargeActiveFromEnum.ROAD01) then
  //     panel:show()
  //   end
  // end
}

void UIMainTop::InitRechargeBtn(EventCustom* p_Event) {
  // local function popShowActiveID(...)
  //   local reID = 0
  //   local recommendList = {}
  //   local normalList = {}
  //   local copyActivityList = rechargeActivityCtrl:filterBuyRankData(rechargeActivityCtrl:getNormalAndAllianceRechargeActivityList()) or {}
  //   for k, v in pairs(copyActivityList) do
  //     if v.recommend and paymentManager.judgeGiftExclusive(tonumber(k)) then
  //       table.insert(recommendList, k)
  //     elseif not v.recommend and paymentManager.judgeGiftExclusive(tonumber(k)) then
  //       table.insert(normalList, k)
  //     end
  //   end
  //   if 0 < table.nums(recommendList) then
  //     reID = tonumber(recommendList[math.random(#recommendList)])
  //   elseif 0 < table.nums(normalList) then
  //     reID = tonumber(normalList[math.random(#normalList)])
  //   end
  //   return reID
  // end
  // self.eventIndex = popShowActiveID()
  // if self.eventIndex == 0 or worldMapDefine.isInNewTrial() then
  //   self.nodeRecharge:setVisible(false)
  // else
  //   self.labelRechargeTime:beginTime(rechargeActivityCtrl:queryQueue(self.eventIndex).timerNode.timer:getRemainTime())
  //   local rechargeRead = include("rechargeRead")
  //   local info = rechargeRead.getPageViewData(self.eventIndex)
  //   if info then
  //     self.nodeRecharge:setVisible(true)
  //     self:addEffectOrAnimationByEventIndex(info.eventType)
  //     if info.hideTime and info.hideTime == 1 then
  //       self.labelRechargeTime:endTime()
  //       self.labelRechargeTime:setString(i18n(info.activeName))
  //     end
  //   end
  // end
  // self:rangeLeftNodes()
}

void UIMainTop::InitCrazyBtn(EventCustom* p_Event) {
  // if redata and redata.showInDown then
  //   if self.nodeCrazy:isVisible() then
  //     self.nodeCrazy:setScale(1)
  //     self.nodeCrazy:runAction(cca.seq({
  //       cc.EaseBackIn:create(cca.scaleTo(0.2, 0.8)),
  //       cca.spawn({
  //         cca.scaleTo(0.2, 0),
  //         cca.fadeTo(0.2, 0),
  //         cca.moveTo(0.2, SoraDFPosX(65, 640), -self:getPanelOffsetHeight() / 2)
  //       }),
  //       cca.callFunc(function()
  //         self.nodeCrazy:setVisible(false)
  //         SoraDConfigSet("Game:eventCrazyTrioNew:isShowInDown~bool", true, {byUID = true})
  //         SoraDSendMessage({
  //           msg = "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN"
  //         })
  //         self:rangeLeft2Nodes()
  //       end)
  //     }))
  //   end
  //   return
  // end
  // if not activityShowCtrl:isActivityOpen(cumuActiveCtrl:getActivityID()) or SoraDGetCastleLv() < CASTLE_LV2_LIMITED then
  //   self.nodeCrazy:setVisible(false)
  //   self:rangeLeft2Nodes()
  //   return
  // end
  // local receiveAll = false
  // local actOpen = false
  // local rechargeltCtrl = include("rechargeltCtrl")
  // local redIsVisible = cumuActiveCtrl:getInitialReceiveState()
  // self.redPointCrazy:setVisible(redIsVisible)
  // local crazyData = cumuActiveCtrl:getCrazyTrioData()
  // local receiveNum = table.nums(crazyData.receive)
  // receiveAll = receiveNum == rechargeltCtrl.getRechargeTotalConfigNum()
  // if not SoraDConfigGet("Game:eventCrazyTrioNew:isShowInDown~bool", {byUID = true}) then
  //   actOpen = true
  // end
  // local isNewJourneyOpen = _G.clientEventMgr.judgeIsOpen(gActivityTimeActivityID.NEW_SERVER_JOURNEY_ACTIVITY, false)
  // self.nodeCrazy:setVisible(not receiveAll and actOpen and not worldMapDefine.isInNewTrial() and not isNewJourneyOpen)
  // self:rangeLeft2Nodes()
}

void UIMainTop::UpdateRechargeRedPoint(EventCustom* p_Event) {
  // local tableFun = {
  //   handler(self, self.updateMonthRedPoint),
  //   handler(self, self.updateGoldRedPoint)
  // }
  // for i, v in ipairs(tableFun) do
  //   if v() then
  //     self.nodeGold:setRedPoint(true)
  //     return
  //   end
  // end
  // self.nodeGold:setRedPoint(false)
}

void UIMainTop::UpdateGoldRedPoint() {
  //   local getTabLength = function(_table)
  //   local leng = 0
  //   if _table == nil then
  //     return leng
  //   end
  //   for k, v in pairs(_table) do
  //     leng = leng + 1
  //   end
  //   return leng
  // end
  // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
  // local actOpen = activityShowCtrl:isActivityOpen(gActivityTimeActivityID.DAILY_DISCOUNT_GIFT_ACTIVITY)
  // local dailyDiscountGiftCtrl = gametop.playertop_:getModule("dailyDiscountGiftCtrl")
  // local isReceiveFreeGift = serviceFunctions.isSameDay(dailyDiscountGiftCtrl.dailyDiscountGiftData.freeGiftTime)
  // local isReceiveSpecialGift = serviceFunctions.isSameDay(dailyDiscountGiftCtrl.dailyDiscountGiftData.rewardGiftTime)
  // local _maxValue = getTabLength(dailyDiscountGiftCtrl.dailyDiscountGiftData.giftData)
  // local _curValue = getTabLength(dailyDiscountGiftCtrl.dailyDiscountGiftData.buyGiftList)
  // local isNeedReceiveSpeGift = not isReceiveSpecialGift and _maxValue == _curValue
  // if actOpen and (not isReceiveFreeGift or isNeedReceiveSpeGift) then
  //   return true
  // else
  //   return false
  // end
}

void UIMainTop::UpdateMonthRedPoint() {
  // local rechargeActivityCtrl = gametop.playertop_:getModule("rechargeActivityCtrl")
  // local weeklyData = rechargeActivityCtrl:getWeekActivityList()
  // if weeklyData and next(weeklyData) then
  //   for k, v in pairs(weeklyData) do
  //     if v.isbuy and not v.isdayget then
  //       return true
  //     end
  //   end
  // end
  // local monthData = rechargeActivityCtrl:getMonthActivityList()
  // if monthData and next(monthData) then
  //   for k, v in pairs(monthData) do
  //     if v.isbuy and not v.isdayget then
  //       return true
  //     end
  //   end
  // end
  // local takeData = rechargeActivityCtrl:getTakeActivityList()
  // if takeData and next(takeData) and takeData.isbuy and not takeData.isdayget then
  //   return true
  // end
  // return false
}

void UIMainTop::PopEventFromEventCenter() {
  // if worldMapDefine.isInNewTrial() then
  //   SoraDShowMsgTip(i18n("devilvalley_tips_08"))
  // else
  //   local panel = SoraDCreatePanel("eventCenterView")
  //   panel:setLogPosition(2)
  //   panel:show()
  //   local clickTime = SoraDConfigGet("Game:mainUITop:clickEventCenterView~integer", {byUID = true})
  //   if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
  //     SoraDConfigSet("Game:mainUITop:clickEventCenterView~integer", serviceFunctions.systemTime(), {byUID = true})
  //   end
  // end
}

void UIMainTop::AddEffectOrAnimationByEventIndex(int p_EventIndex) {
  // self.nodeRechargeIcon:removeAllChildren()
  // local giftNode = effectEventGift.getGiftNode(eType)
  // giftNode:addTo(self.nodeRechargeIcon)
}

void UIMainTop::GetLuckyGiftEffect() {
  // local img = "#btn_rechareactivity_07_base.png"
  // local gift = display.newSprite(img)
  // gift:setPosition(cc.p(self:getContentSize().width / 2, -self:getPositionY() / 3))
  // local giftSize = gift:getContentSize()
  // gift:setScale(0)
  // gift:addTo(self, 1000)
  // local function explode()
  //   local param = {
  //     [1] = {
  //       plist = "et_chongzhi_lucky02_01.plist",
  //       scale = 1.6
  //     },
  //     [2] = {
  //       plist = "et_chongzhi_lucky02_02.plist",
  //       scale = 3.08
  //     },
  //     [3] = {
  //       plist = "et_chongzhi_lucky02_03.plist",
  //       scale = 3
  //     },
  //     [4] = {
  //       plist = "et_chongzhi_lucky02_04.plist",
  //       scale = 1.7
  //     }
  //   }
  //   local parNode = SoraDCreateEffectNode(param)
  //   parNode:setPosition(cc.p(giftSize.width / 2, giftSize.height / 2))
  //   parNode:addTo(gift, 2)
  // end
  // local seq = transition.sequence({
  //   cca.scaleTo(0.2, 1.8),
  //   cca.callFunc(explode),
  //   cca.scaleTo(0.2, 1),
  //   cca.scaleTo(0.1, 1.2),
  //   cca.scaleTo(0.1, 1),
  //   cca.delay(0.8),
  //   cca.spawn({
  //     cca.moveTo(0.3, cc.p(self.nodeLucky:getPositionX(), self.nodeLucky:getPositionY() + 80)),
  //     cca.scaleTo(0.3, 0)
  //   }),
  //   cca.delay(0.3),
  //   cca.callFunc(function()
  //     gift:removeFromParent()
  //   end)
  // })
  // gift:runAction(seq)
}

void UIMainTop::DefineWallDestroy(EventCustom* p_Event) {
  // if worldMapDefine.isInNewTrial() then
  // else
  //   SoraDShowMsgBox(i18n("common_text_797"), i18n("common_text_798"), nil, function(eventType)
  //     if eventType == MSGBOX_CALLBACK_YES then
  //       local gametop = gModuleMgr.getObject("gametop")
  //       local wallsCtrl = gametop.playertop_:getModule("wallsCtrl")
  //       wallsCtrl:reqRebuildWall()
  //       SoraDSendMessage({
  //         msg = "MESSAGE_WALLS_DEFENCE_DESTROY_RECOVER"
  //       })
  //     end
  //   end, {
  //     canNotClose = true,
  //     basePanelPowerValue = POP_WINDOW_POWERVALUE_WALLDEFINE,
  //     isCantCloseByReturn = true,
  //     align = SoraDFLabelR()
  //   })
  // end
  // if SoraDIsGameGuide() then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_SERVER_CLOSE_GUIDE"
  //   })
  // end
}

void UIMainTop::SetLordHPUpdate(EventCustom* p_Event) {
  // self.hpReduceStyle = data.style
  // self.hpReduceValue = data.hp
  // self.isSetHPStyle = true
  // if self.isSetHPStyle and self.isUpdateHP then
  //   effectMainUITop.showLordPhysicalEffect(self)
  // end
}

void UIMainTop::KingBattleFun(EventCustom* p_Event) {
  // if redata and redata.mid then
  //   local gametop = gModuleMgr.getObject("gametop")
  //   local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //   local cLevel = cityCtrl:getBuildMaxLv(BUILDID.CASTLE) or 0
  //   if cLevel >= CASTLE_LV10_LIMITED and SoraDIsGameGuide() == nil then
  //     local panel = SoraDCreatePanel("kingdomBattleWinWar")
  //     panel:initData(redata.mid)
  //     panel:show()
  //   end
  // end
}

void UIMainTop::LegendLordBattleVectoryFun(EventCustom* p_Event) {
  // local panel = SoraDCreatePanel("pyramidBattleWinPopView")
  // panel:setStyle(3)
  // panel:initLegendData(redata.data)
  // panel:show()
  // panel:setLocalZOrder(5)
}

void UIMainTop::PyramidBattleStartFun(EventCustom* p_Event) {
  // TODO:
  // effectMainUITop.warStartVSEffect()
}

void UIMainTop::CheckServerIsOK4SDKCallBack(EventCustom* p_Event) {
  // if redata and redata.otherData and redata.otherData.checkServerIsOK4SDKCallBack then
  //   print("checkServerIsOK4SDKCallBack = \230\136\144\229\138\159\232\167\166\229\143\145\239\188\154userSDKManager.reportReline()")
  //   userSDKManager.reportReline()
  // end
}

void UIMainTop::GetEventCenterReturn_imp(EActivityTime p_Activity) {
  // if v == gActivityTimeActivityID.DAILY_DISCOUNT_GIFT_ACTIVITY then
  //   self:updateRechargeRedPoint()
  // elseif v == cumuActiveCtrl:getActivityID() then
  //   self:initCrazyBtn()
  //   local cityBuildFunction = include("cityBuildFunction")
  //   local ret = cityBuildFunction:checkCrazyTrio()
  //   print("nodeCrazy", ret)
  // elseif v == gActivityTimeActivityID.NEW_SERVER_RANK_MATCH then
  //   self:initKingNode()
  // elseif v == gActivityCenterUIEnum.SULTAN_BACK then
  //   self:initSultansBackNode()
  // elseif v == gActivityTimeActivityID.NEW_SERVER_JOURNEY_ACTIVITY then
  //   self:initNewJourney()
  //   self:initCrazyBtn()
  // end
  // self:rangeLeftNodes()
}

void UIMainTop::GetEventCenterReturn(EventCustom* p_Event) {
  // if type(redata.activityID) == "table" then
  //   for _, v in pairs(redata.activityID) do
  //     self:getEventCenterReturn_imp(v)
  //   end
  // elseif type(redata.activityID) == "number" then
  //   self:getEventCenterReturn_imp(redata.activityID)
  // end
}

void UIMainTop::RechargeCloseLoading(EventCustom* p_Event) {
  // dump(redata, "rechargeCloseLoading")
  // SoraDCloseLoading()
  // paymentManager.isInRecharging = false
  // if not redata.data then
  //   return
  // end
  // local rechargePopFail = function()
  //   local callBackHandle = function()
  //     userSDKManager.openFeedback("Purchase", true)
  //   end
  //   local panel = include("commonPromptBoxTitle").new()
  //   panel:initData({
  //     title = i18n("common_text_1035"),
  //     content = i18n("common_text_3506"),
  //     yes = i18n("common_text_2102"),
  //     handle = callBackHandle
  //   })
  //   panel:show()
  // end
  // local rechargePopMsg = function(goods, mid, rid)
  //   if goods and next(goods) ~= nil then
  //     local panel = SoraDCreatePanel("gemGoodsBuyGiftSuccess")
  //     panel:initData(goods, mid, rid)
  //     panel:show()
  //   end
  // end
  // local rechargeNewListPopMsg = function(goods, mid, rid)
  //   if goods and next(goods) ~= nil then
  //     local panel = SoraDCreatePanel("gemGoodsBuyGiftSuccess")
  //     panel:initDetailData(goods, mid, rid)
  //     panel:show()
  //   end
  // end
  // local rechargeGemGoodsPopMsg = function(goods, mid, rid)
  //   if goods and next(goods) ~= nil then
  //     local panel = SoraDCreatePanel("gemGoodsBuyGiftSuccess")
  //     panel:initData(goods, mid, rid)
  //     panel:show()
  //   end
  // end
  // if redata.data.result then
  //   print("\229\133\133\229\128\188\230\136\144\229\138\159\229\188\185\231\170\151")
  //   do
  //     local _rid = redata.data.rid
  //     if _rid then
  //       local goods = redata.data.itemList
  //       local mailID = redata.data.mailID
  //       local rechargeRead = include("rechargeRead")
  //       local rechargeInfo = rechargeRead.getPageViewData(_rid)
  //       if rechargeInfo then
  //         if gRechargeActiveModelType.NORMAL == rechargeInfo.activeModelType or rechargeInfo.activeModelType == gRechargeActiveModelType.PETRA_GIFT
  //         then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //           })
  //           self:initRechargeBtn()
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.LUCKYGIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //           })
  //           self:initLuckyBtn()
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.MONTHLYGIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_MONTHLY_REFRESH"
  //           })
  //           local gametop = gModuleMgr.getObject("gametop")
  //           local rechargeActivityCtrl = gametop.playertop_:getModule("rechargeActivityCtrl")
  //           local monthGiftSpecialRid = 11485
  //           if rechargeActivityCtrl.monthAward and rechargeActivityCtrl.monthAward[tostring(monthGiftSpecialRid)] then
  //             local _day = rechargeActivityCtrl.monthAward[tostring(monthGiftSpecialRid)].curTotalday or
  //             rechargeActivityCtrl.monthAward[tostring(monthGiftSpecialRid)].totalday or 0 SoraDShowMsgBox(i18n("common_text_1127", {num = _day}),
  //             i18n("common_text_204"), nil, nil)
  //           end
  //         elseif gRechargeActiveModelType.WEEKLY_GIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_WEEKLY_REFRESH"
  //           })
  //           do
  //             local gametop = gModuleMgr.getObject("gametop")
  //             local rechargeActivityCtrl = gametop.playertop_:getModule("rechargeActivityCtrl")
  //             local function autoFightFun()
  //               local weekdata = rechargeActivityCtrl:getWeekActivityList()
  //               local weedsingle = weekdata[tostring(_rid)]
  //               if weedsingle then
  //                 for i, v in ipairs(weedsingle.buff) do
  //                   if v == 5148 then
  //                     SoraDSendMessage({
  //                       msg = "MESSAGE_SERVER_GUIDE_START_BY_STEP",
  //                       step = 60005
  //                     })
  //                   end
  //                 end
  //               end
  //             end
  //             if rechargeActivityCtrl.monthAward and rechargeActivityCtrl.monthAward[tostring(_rid)] then
  //               local _day = rechargeActivityCtrl.monthAward[tostring(_rid)].curTotalday or
  //               rechargeActivityCtrl.monthAward[tostring(_rid)].totalday or 0 if _day > 7 then
  //                 local weekInfo = rechargeRead.getPageViewData(_rid)
  //                 local leftTime = rechargeActivityCtrl:getRechargeLeftTime(_rid)
  //                 if weekInfo and weekInfo.activeName and leftTime then
  //                   SoraDShowMsgBox(i18n("common_text_4175", {
  //                     giftname = i18n(weekInfo.activeName),
  //                     time = SoraDConvertSecondToString(leftTime)
  //                   }), i18n("common_text_204"))
  //                 else
  //                   SoraDShowMsgBox(i18n("common_text_1127", {num = _day}), i18n("common_text_204"), nil, autoFightFun)
  //                 end
  //               else
  //                 SoraDShowMsgBox(i18n("common_text_1127", {num = _day}), i18n("common_text_204"), nil, autoFightFun)
  //               end
  //             end
  //           end
  //         elseif gRechargeActiveModelType.SUBSCRIPTION == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_SUBSCRIPTION_REFRESH"
  //           })
  //           if redata.data.hadFreeSubed then
  //             SoraDShowMsgTip(i18n("subscribe_gift_text_13"))
  //           else
  //             local weekInfo = rechargeRead.getPageViewData(_rid)
  //             local leftTime = rechargeActivityCtrl:getRechargeLeftTime(_rid)
  //             if weekInfo and weekInfo.activeName and leftTime then
  //               SoraDShowMsgTip(i18n("common_text_4175", {
  //                 giftname = i18n(weekInfo.activeName),
  //                 time = SoraDConvertSecondToString(leftTime)
  //               }))
  //             end
  //           end
  //           self:updateRechargeRedPoint()
  //         elseif gRechargeActiveModelType.KINGDOMGROUPBUY == rechargeInfo.activeModelType then
  //           SoraDShowMsgTip(i18n("common_text_1031"))
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_EVENTCENTER_KINGGROUPBUY_INIT",
  //             rechargeRefresh = true
  //           })
  //         elseif gRechargeActiveModelType.REDPACKAGE == rechargeInfo.activeModelType then
  //           SoraDShowMsgTip(i18n("common_text_3484"))
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_REDPACKETSUCCESS"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_REDPACKETNEXTSUCCESS"
  //           })
  //         elseif gRechargeActiveModelType.ICEBREAK == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //           })
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.SEVEN_DAY_GIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_SEVENDAYS"
  //           })
  //           rechargeNewListPopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.PRIVILEGE_GIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_MAINCITY_CASTLE_GIFT_MSG",
  //             success = true
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.RUIRUILADDER == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //           })
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.DAILYDISCOUNT == rechargeInfo.activeModelType then
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.HONOR_BACK_GIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_HONOR_BACK_UPDATE_GIFTS"
  //           })
  //           rechargePopMsg(goods, mailID, _rid)
  //         elseif gRechargeActiveModelType.LINGLANG_GIFT == rechargeInfo.activeModelType then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_CLIENT_RECHARGECENTER_POPVIEWCLOSE"
  //           })
  //           SoraDSendMessage({
  //             msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWREFRESH"
  //           })
  //           self:initRechargeBtn()
  //           rechargeGemGoodsPopMsg(goods, mailID, _rid)
  //         end
  //       elseif paymentManager.getPaymentBullets(_rid) then
  //         local isActive = paymentManager.getPaymentBullets(_rid).isActive
  //         if isActive == gBuyType.RECHARGE_ACTIVITY or isActive == gBuyType.AMAZING_FORTUNE then
  //           rechargePopMsg(goods, mailID, _rid)
  //         else
  //           SoraDShowMsgTip(i18n("common_text_1032"))
  //         end
  //       else
  //         SoraDShowMsgTip(i18n("common_text_1032"))
  //       end
  //       local gold = redata.data.goldCount or 0
  //       if paymentManager.bullets[_rid] and paymentManager.bullets[_rid].isActive == gBuyType.RECHARGE then
  //         SoraDSendMessage({
  //           msg = "MESSAGE_SERVER_RECHARGECENTER_RECHARGEVIEWGOLDREFRESH"
  //         })
  //         local itemList = {
  //           gIDDef.GOLD,
  //           gold
  //         }
  //         rechargePopMsg(itemList, mailID, _rid)
  //       end
  //     end
  //   end
  // else
  //   local _rid = redata.data.rid
  //   print("\229\133\133\229\128\188\229\164\177\232\180\165", _rid)
  //   if _rid then
  //     local rechargeRead = include("rechargeRead")
  //     local rechargeInfo = rechargeRead.getPageViewData(_rid)
  //     if rechargeInfo then
  //       if gRechargeActiveModelType.NORMAL == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.LUCKYGIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.MONTHLYGIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.WEEKLY_GIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.SUBSCRIPTION == rechargeInfo.activeModelType then
  //       elseif gRechargeActiveModelType.KINGDOMGROUPBUY == rechargeInfo.activeModelType then
  //         if redata.data.contactMe then
  //           rechargePopFail()
  //         else
  //           rechargePopFail()
  //         end
  //       elseif gRechargeActiveModelType.REDPACKAGE == rechargeInfo.activeModelType then
  //       elseif gRechargeActiveModelType.ICEBREAK == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.SEVEN_DAY_GIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.PRIVILEGE_GIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.RUIRUILADDER == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.DAILYDISCOUNT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       elseif gRechargeActiveModelType.HONOR_BACK_GIFT == rechargeInfo.activeModelType then
  //         rechargePopFail()
  //       else
  //         rechargePopFail()
  //       end
  //     end
  //     if paymentManager.bullets[_rid] and (paymentManager.bullets[_rid].isActive == gBuyType.RECHARGE or paymentManager.bullets[_rid].isActive ==
  //     gBuyType.EARTH_TREASURE) and not SoraDSearchPanelFromManagerByName("commonPromptBoxTitle") then
  //       rechargePopFail()
  //     end
  //     if _rid == 14261 then
  //       rechargePopFail()
  //     end
  //   else
  //     rechargePopFail()
  //   end
  // end
}

void UIMainTop::EndLegendLordWar(EventCustom* p_Event) {
  // if data.data then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_SERVER_LEGENDLORD_WAR_END",
  //     data = data.data
  //   })
  // end
}

void UIMainTop::EndPyramid(EventCustom* p_Event) {
  // if data.data then
  //   SoraDManagerRemoveAllTimer()
  //   local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //   local cLevel = cityCtrl:getBuildMaxLv(BUILDID.CASTLE) or 0
  //   if cLevel >= CASTLE_LV10_LIMITED then
  //     dump(data.data, "pyramidBattleVectoryFun", 10)
  //     SoraDRemoveAllPanelFromManager()
  //     local panel = SoraDCreatePanel("pyramidBattleNewWinPopView")
  //     panel:initData(data.data)
  //     panel:prepare4Action()
  //     panel:show()
  //     panel:start2Action()
  //   end
  // end
}

void UIMainTop::UpdateTeamMainUIWidget(EventCustom* p_Event) {
  // if worldMapDefine.inInCrossWar() then
  //   if self.teamMainUIWidget then
  //     self.teamMainUIWidget:removeFromParent()
  //     self.teamMainUIWidget = nil
  //   end
  //   return
  // end
  // local remainsTeamCtrl = gametop.playertop_:getModule("remainsTeamCtrl")
  // if remainsTeamCtrl:isHasTeam() then
  //   if not self.teamMainUIWidget then
  //     local teamMainUIWidget = include("teamMainUIWidget").new()
  //     teamMainUIWidget:setViewType(self.currentViewType)
  //     teamMainUIWidget:setPosition(cc.p(320, -100))
  //     teamMainUIWidget:addTo(self)
  //     self.teamMainUIWidget = teamMainUIWidget
  //   end
  //   if self.teamMainUIWidget then
  //     self.teamMainUIWidget:initData()
  //   end
  // elseif self.teamMainUIWidget then
  //   self.teamMainUIWidget:removeFromParent()
  //   self.teamMainUIWidget = nil
  // end
  // self:updateLostRuinsNode()
  // self:updateWindTowerNode()
  // self:updateSnowWolfLostNode()
}

void UIMainTop::OnTeamMatchSuc(EventCustom* p_Event) {
  // local panel = SoraDCreatePanel("teamMatchView")
  // panel:show()
  // panel:initView(data)
}

void UIMainTop::OnRadianceWarEnd(EventCustom* p_Event) {
  // local resultInfo = data.resultInfo
  // if resultInfo then
  //   if not resultInfo.ruinsWarSettleData then
  //     local panel = SoraDCreatePanel("remainsWarScoreView")
  //     panel:show()
  //     panel:initData(resultInfo)
  //   else
  //     local panel = SoraDCreatePanel("remainsWarResultView")
  //     panel:show()
  //     panel:initData(data)
  //   end
  // end
}

void UIMainTop::OnRemainsWarEnd(EventCustom* p_Event) {
  // local panel = SoraDCreatePanel("radianceWarResultView")
  // panel:show()
}

void UIMainTop::OnRemainsWarTeamJoin(EventCustom* p_Event) {
  // local remainsWarUtil = include("remainsWarUtil")
  // if data.err == gErrDef.Err_None then
  //   remainsWarUtil.doAllianceInvite(data.extraData)
  // else
  //   remainsWarUtil.errShowTips(data.err)
  // end
}

void UIMainTop::UpdateAttackInfo(EventCustom* p_Event) {
  // if not self.remainsWarwAttackWidget then
  //   local remainsWarwAttackWidget = include("remainsWarAttackWidget").new()
  //   remainsWarwAttackWidget:setPosition(cc.p(320, 0))
  //   remainsWarwAttackWidget:addTo(self)
  //   self.remainsWarwAttackWidget = remainsWarwAttackWidget
  //   if self.remainsWarwAttackWidget then
  //     self.remainsWarwAttackWidget:updateAttackInfo(target, data)
  //   end
  // end
}

void UIMainTop::RefreshNewTrialUI(EventCustom* p_Event) {
  // local devilValleyCtrl = gametop.playertop_:getModule("devilValleyCtrl")
  // if devilValleyCtrl:hasTeams() and not worldMapDefine.isInNewTrial() then
  //   self.newTrailTeamUI = SoraDGetChildByName(self, "newTrialMainUI")
  //   if not self.newTrailTeamUI then
  //     self.newTrailTeamUI = SoraDCreatePanel("newTrialMainUI")
  //     self.newTrailTeamUI:setName("newTrialMainUI")
  //     self.newTrailTeamUI:addTo(self)
  //     self.newTrailTeamUI:setPosition(cc.p(320, -50))
  //   end
  //   self.newTrailTeamUI:initData()
  //   self.newTrailTeamUI:setVisible(self.currentViewType == VIEW_TYPE_CITY)
  // else
  //   self.newTrailTeamUI = SoraDGetChildByName(self, "newTrialMainUI")
  //   if self.newTrailTeamUI then
  //     self.newTrailTeamUI:removeFromParent()
  //     self.newTrailTeamUI = nil
  //   end
  // end
  // print("newTrialMainUI", self.currentViewType == VIEW_TYPE_CITY)
  // self:updateLostRuinsNode()
  // self:updateWindTowerNode()
  // self:updateSnowWolfLostNode()
}

void UIMainTop::RefreshNewTrialTeam(EventCustom* p_Event) {
  // local devilValleyCtrl = SoraDGetCtrl("devilValleyCtrl")
  // if devilValleyCtrl:hasTeams() then
  //   SoraDCreatePanel("newTrialMyTeamView"):show()
  // end
}

void UIMainTop::RefreshBeginNewTrial(EventCustom* p_Event) {
  // local devilValleyCtrl = SoraDGetCtrl("devilValleyCtrl")
  // local teams = devilValleyCtrl:getMyTeams()
  // if teams.start and not devilValleyCtrl:getSelfIsStart() and (not self.hasShowNewTrialBox or not not tolua.isnull(self.hasShowNewTrialBox)) then
  //   do
  //     local panel = SoraDShowMsgBox(i18n("devilvalley_tips_07"), i18n("devilvalley_btn_14"), i18n("devilvalley_btn_13"), function(eventType)
  //       self.hasShowNewTrialBox = nil
  //       if MSGBOX_CALLBACK_YES == eventType and SoraDGetCtrl("devilValleyCtrl"):checkEnterCondition() then
  //         SoraDGetCtrl("devilValleyCtrl"):sendReqStartChallenge()
  //       end
  //     end)
  //     self.hasShowNewTrialBox = panel
  //     if panel then
  //       SoraDAddMessage(panel, "MESSAGE_NEWTRIAL_TEAM_REFRESH", function(target, data)
  //         if not devilValleyCtrl:hasTeams() then
  //           panel:removeFromParent()
  //           self.hasShowNewTrialBox = nil
  //         end
  //       end)
  //     end
  //   end
  // end
}

void UIMainTop::RefreshNodeEvent() {
  // if worldMapDefine.isInNewTrial() then
  //   self.nodeEvent:setVisible(false)
  //   self.nodeCrazy:setVisible(false)
  //   self.nodeRecharge:setVisible(false)
  //   self.nodeLucky:setVisible(false)
  //   self.nodeSultansBack:setVisible(false)
  //   self.nodeHeroGift:setVisible(false)
  // else
  //   self.nodeEvent:setVisible(true)
  //   self:initCrazyBtn()
  //   self:initRechargeBtn()
  //   self:initLuckyBtn()
  //   self:initNewJourney()
  //   self:initSultansBackNode()
  //   self:initHeroGiftBtn()
  // end
  // self:rangeLeftNodes()
}

void UIMainTop::NewTrialEndRefresh(EventCustom* p_Event) {
  // print("newTrialEndRefresh")
  // SoraDCloseLoading(self)
  // local panel = SoraDCreatePanel("newTrialResultView")
  // panel:initData(data.data)
  // panel:show()
}

void UIMainTop::RoyalSummonsGold(EventCustom* p_Event) {
  // print("royalSummonsGold")
  // local royalSummonsCtrl = gametop.playertop_:getModule("royalSummonsCtrl")
  // if royalSummonsCtrl:isActiveGold() then
  //   local panelName = "royalSummonsActivity"
  //   if royalSummonsCtrl:getClassType() == 2 then
  //     panelName = "dashToSkyActivity"
  //   end
  //   local panel = SoraDCreatePanel(panelName)
  //   panel:show()
  // end
}

void UIMainTop::AncientReelGold(EventCustom* p_Event) {
  // local ancientReelCtrl = gametop.playertop_:getModule("ancientReelCtrl")
  // if ancientReelCtrl:isActiveGold() then
  //   local panelName = "ancientReelActivity"
  //   local panel = SoraDCreatePanel(panelName)
  //   panel:show()
  // end
}

void UIMainTop::CastleLevelUp(EventCustom* p_Event) {
  // if SoraDGetCastleLv() == CASTLE_LV90_LIMITED then
  //   self:checkBuildStarButton()
  // end
  // if SoraDGetCastleLv() == CASTLE_LV2_LIMITED then
  //   self:initCrazyBtn()
  // end
}

void UIMainTop::KingdomLevelUp(EventCustom* p_Event) {
  // local cityltCtrl = include("cityltCtrl")
  // local unlockLv = cityltCtrl.buildStarLvInfo(BUILDID.CASTLE, 1, BUILD_LVINFO.KINGDOMLV)
  // local kingdomLevelDataModuleAPI = include("kingdomLevelDataModuleAPI")
  // local kingdomLevel = kingdomLevelDataModuleAPI:getKingdomLevel()
  // if kingdomLevel == unlockLv then
  //   self:checkBuildStarButton()
  // end
}

void UIMainTop::CheckBuildStarButton() {
  auto l_IsFound = false;
  for(auto l_BuilderIcon : m_TableBuilder){
    if(l_BuilderIcon->GetBuilderType() == ETask::BuildStarQueue){
      l_IsFound = true;
      break;
    }
  }
  if(!l_IsFound)
    AddBuildStarButton();
}

void UIMainTop::CheckSecondBuildStarButton(EventCustom* p_Event) {
  bool l_IsFound = false;
  for (auto it : m_TableBuilder) {
    if (it->GetBuilderType() == ETask::BuildStarQueuePrivilege) {
      l_IsFound = true;
      break;
    }
  }
  if (l_IsFound) return;
  if (!GBase::DCheckIsOpenBuildStar()) return;
  if (!ExaltedPrivilegeCtrl::Get()->CheckPrivilege(EExaltedPrivilege::ExtraStarUpgradeQueueNun)) return;
  auto l_BtnSecond = UIBuilderIcon::Create();
  l_BtnSecond->setScale(0.8f);
  l_BtnSecond->setPosition(Vec2(GBase::DFIsRA() ? 590 : 50, -340));
  l_BtnSecond->InitData(ETask::BuildStarQueuePrivilege);
  l_BtnSecond->setVisible(m_CurrentViewType == EScene::City);
  m_TableBuilder.push_back(l_BtnSecond);
  n_NodeAreaLt->addChild(l_BtnSecond);
  UpdateHeadPos(nullptr);
}

void UIMainTop::AddBuildStarButton() {
  if (GBase::DCheckIsOpenBuildStar()) {
    auto l_Btn = UIBuilderIcon::Create();
    l_Btn->setPosition(Vec2(GBase::DFIsRA() ? 590 : 50, -260));
    l_Btn->setScale(0.8f);
    l_Btn->InitData(ETask::BuildStarQueue);
    l_Btn->setVisible(m_CurrentViewType == EScene::City);
    m_TableBuilder.push_back(l_Btn);
    n_NodeAreaLt->addChild(l_Btn);
    if (ExaltedPrivilegeCtrl::Get()->CheckPrivilege(EExaltedPrivilege::ExtraStarUpgradeQueueNun)) {
      auto l_BtnSecond = UIBuilderIcon::Create();
      l_BtnSecond->setScale(0.8f);
      l_BtnSecond->setPosition(Vec2(GBase::DFIsRA() ? 590 : 50, -340));
      l_BtnSecond->InitData(ETask::BuildStarQueuePrivilege);
      l_BtnSecond->setVisible(m_CurrentViewType == EScene::City);
      m_TableBuilder.push_back(l_BtnSecond);
      n_NodeAreaLt->addChild(l_BtnSecond);
    }
  }
}
