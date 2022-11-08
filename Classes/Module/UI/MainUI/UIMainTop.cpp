#include "UIMainTop.h"


void UIMainTop::Ctor(){
  m_Panel = CSLoader::createNode("UiParts/MainUi/mainUITop.csb");
  //   self.playerInfo = {}
  n_NodeLOD = GBase::GetChildByName<Node *>(m_Panel, "Node_LOD");
  n_NodeAreaRt = GBase::GetChildByName<Node *>(n_NodeLOD, "Node_area_rt");
  n_NodeAreaLt = GBase::GetChildByName<Node *>(n_NodeLOD, "Node_area_lt");
  n_NodeAreaT = GBase::GetChildByName<Node *>(m_Panel, "Node_area_t");
  n_NodeGold = GBase::DGetExtendChildFromCCSByName<UICommonGoldTop>(m_Panel, "CCS_commonGoldTop_gold");
  n_NodeGold->SetMainUIStyle();
  n_NodeGold->ShowAnimation();
  n_ResMenu = GBase::DGetExtendChildFromCCSByName<UICommonResourcesMenu>(m_Panel, "CCS_commonResourcesMenu_menu");
  n_ResMenu->RunAnimation();
  n_ResMenu->HiddleMainUI(false);
  n_BtnVip = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_vip");
  n_BtnVip->setPressedActionEnabled(false);
  n_ImgVip = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Image_vip");
  n_SpriteActiveVip = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_active");
  n_SpriteActiveVip->setVisible(false);
  n_LabelVip = GBase::GetChildByName<ui::TextBMFont *>(m_Panel, "BitmapFontLabel_vip_en");
  n_SpVipPointFrm = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_vipNumFrm");
  n_ImgLvBg = GBase::GetChildByName<ui::ImageView *>(m_Panel, "Image_levelBg");
  n_LabelLv = GBase::GetChildByName<ui::Text *>(m_Panel, "BitmapFontLabel_leve");
  n_SpriteHead = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_head");
  n_BarEXPBg = GBase::GetChildByName<Sprite *>(m_Panel, "progressbar_main_exp");
  n_BarEXP = GBase::GetChildByName<ui::LoadingBar *>(m_Panel, "LoadingBar_exp");
  //n_BarEXP->setClipEnabled(false);
  n_BarHPBg = GBase::GetChildByName<Sprite *>(m_Panel, "progressbar_main_stamina");
  n_BarStamina = GBase::GetChildByName<ui::LoadingBar *>(m_Panel, "LoadingBar_stamina");
  //   self.barStamina:setClipEnabled(false)
  n_NodeHead = GBase::GetChildByName<ui::Layout *>(m_Panel, "Panel_headFrame");
  n_NodeWeakPoint = GBase::GetChildByName<Node *>(m_Panel, "Node_headWeakPoint");
  n_SpriteLordHead = GBase::GetChildByName<Sprite *>(m_Panel, "sprite_lord_head");
  n_BtnHead = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_head");
  n_SpriteHeadRedPoint = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_headRedPoint");
  n_SpriteHeadRedPoint->setVisible(false);
  n_IconVipNew = GBase::GetChildByName<Sprite *>(m_Panel, "iconVipNew");
  n_IconVipNew->setVisible(false);
  n_ImgPower = GBase::GetChildByName<Sprite *>(m_Panel, "sprite_power");
  n_LabelPower = GBase::GetChildByName<ui::Text *>(m_Panel, "Text_powerValue");
  n_ScoreLabelPower = UICommonScoreLabel::DCreateScoreLabel(n_LabelPower, true);
  n_BtnPower = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_power");
  n_IconGem = GBase::GetChildByName<Sprite *>(m_Panel, "icon_main_powegem");
  n_IconGem->setVisible(GBase::Const::Get()->IsArClient);
  n_LabelRechargeTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(m_Panel, "Text_rechargeTime"));
  n_BtnRechargeActivity = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_recharge");
  n_NodeRecharge = GBase::GetChildByName<Node *>(m_Panel, "Node_recharge");
  n_NodeRechargeIcon = n_NodeRecharge->getChildByName("Node_icon");
  n_NodeEvent = GBase::GetChildByName<Node *>(m_Panel, "Node_event");
  n_NodeEventIcon = n_NodeEvent->getChildByName<Node *>("Node_icon");
  n_ImageEvent = n_NodeEventIcon->getChildByName<ui::ImageView *>("Image_event");
  n_NodeNew = GBase::GetChildByName<Node *>(m_Panel, "Node_new");
  auto l_NodeNewJump = GBase::DCreateAnimation("animationNewJump").First;
  l_NodeNewJump->setPosition(38, -60);
  n_NodeNew->addChild(l_NodeNewJump);
  n_BtnEvent = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_event");
  n_LabelEventTime = GBase::GetChildByName<ui::Text *>(m_Panel, "Text_eventTime");
  n_LabelEventTime->setString(Translate::i18n("buildDes_name_106"));
  n_SpriteEventRedPoint = GBase::GetChildByName<Sprite *>(n_NodeEvent, "Sprite_numBg");
  n_LabelEventRedNum = GBase::GetChildByName<ui::Text *>(n_NodeEvent, "Text_num");
  n_SpriteEventRedPoint->setVisible(false);
  n_PanelTips = GBase::GetChildByName<ui::Layout *>(n_NodeEvent, "Panel_tips");
  GBase::GetChildByName<ui::Text *>(n_PanelTips, "Text_tips")->setString(Translate::i18n("activity_text_03"));
  n_PanelTips->setVisible(false);
  n_ImageEvent->loadTexture("btn_main_new_activity.png", ui::Widget::TextureResType::PLIST);
  n_ImageEvent->ignoreContentAdaptWithSize(true);
  n_NodeNewJourney = GBase::GetChildByName<Node *>(m_Panel, "Node_newJourney");
  n_NodeNewJourney->setVisible(false);
  n_NodeEtNew = GBase::GetChildByName<Node *>(n_NodeNewJourney, "Node_etNew");
  //TODO: FullPath
  auto l_NodeNewJump_2 = GBase::DCreateAnimation("animationNewJump"/**full Path*/).First;
  l_NodeNewJump_2->setPosition(38, -60);
  n_NodeEtNew->addChild(l_NodeNewJump_2);
  n_NodeIconJourney = GBase::GetChildByName<Node *>(n_NodeNewJourney, "Node_iconJourney");
  auto l_NodeNewJump_3 = GBase::DCreateAnimation("animationJourney").First;
  n_NodeIconJourney->addChild(l_NodeNewJump_3);
  n_TextNewJourney = GBase::GetChildByName<ui::Text *>(n_NodeNewJourney, "Text_newJourney");
  n_TextNewJourney->setString(Translate::i18n("journey_art_1001"));
  n_ButtonNewJourney = GBase::GetChildByName<ui::Button *>(n_NodeNewJourney, "Button_newJourney");
  n_ButtonNewJourney->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnJourneyClick, this));
  n_NodeLucky = GBase::GetChildByName<Node *>(m_Panel, "Node_rechargeLucky");
  n_LuckyNumFrm = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_numFrm");
  n_LuckyNumTxt = GBase::GetChildByName<ui::Text *>(m_Panel, "Text_pointNum");
  n_BtnLucky = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_rechargeLucky");
  n_NodeLuckyIcon = n_NodeLucky->getChildByName("Node_icon");
  n_TxtLuckyTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(m_Panel, "Text_luckyTime"));
  n_NodeCrazy = GBase::GetChildByName<Node *>(m_Panel, "Node_crazy");
  n_NodeCrazyIcon = n_NodeCrazy->getChildByName("Node_icon");
  n_BtnCrazy = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_crazy");
  n_TxtCrazyTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(m_Panel, "Text_crazyTime"));
  n_TxtCrazyTime->setVisible(false);
  n_RedPointCrazy = GBase::GetChildByName<Sprite *>(m_Panel, "Sprite_crazyRedPoint");
  n_NodeCrazy->getChildByName("Sprite_redBg")->setVisible(false);
  n_NodeHeroGift = GBase::GetChildByName<Node *>(m_Panel, "Node_choiceLucky");
  GBase::GetChildByName<Node *>(n_NodeHeroGift, "Sprite_numFrmChoice")->setVisible(false);
  n_TxtHeroGiftTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(m_Panel, "Text_choiceLuckyTime"));
  n_BtnHeroGift = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_choiceLucky");
  n_BtnHeroGift->addTouchEventListener(CC_CALLBACK_2(UIMainTop::BtnHeroRechargeClick, this));
  auto l_NodeLucky = static_cast<ui::Widget *>(n_NodeLucky);
  n_NodeKingCom = l_NodeLucky->clone();
  n_NodeAreaRt->addChild(n_NodeKingCom);
  n_NodeKingCom->setVisible(true);
  n_NodeKingCom->setName("nodeKingCom");
  n_NodeKingCom->setPositionX(n_NodeCrazy->getPositionX());
  n_BtnKing = GBase::GetChildByName<ui::Button *>(n_NodeKingCom, "Button_rechargeLucky");
  n_KingRed = GBase::GetChildByName<Sprite *>(n_NodeKingCom, "Sprite_numFrm");
  n_TxtKingTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(n_NodeKingCom, "Text_luckyTime"));
  n_NodeKingIcon = n_NodeKingCom->getChildByName("Node_icon");
  auto l_Node = GBase::DCreateAnimation("kingCompetitionEnterEffect").First;
  n_NodeKingIcon->addChild(l_Node);
  l_Node->setPosition(Vec2(8, 40));
  l_Node->setScale(1.2f);
  //   for i, v in ipairs({
  //     "Sprite_9",
  //     "Sprite_9_0",
  //     "dh_zhounianjm_01_3"
  //   }) do
  //     SoraDMixtureGLONE(SoraDGetChildByName(node, v))
  //   end
  n_BtnKing->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  //n_NodeSultansBack = l_NodeLucky->clone();
  n_NodeAreaRt->addChild(n_NodeSultansBack);
  n_NodeSultansBack->setVisible(true);
  n_NodeSultansBack->setName("nodeSultansBack");
  n_NodeSultansBack->setPositionX(n_NodeCrazy->getPositionX());
  auto l_Sprite = BaseCreate::CreateSprite("icon_sudanback_mian.png");
  n_NodeSultansBack->getChildByName("Node_icon")->addChild(l_Sprite);
  l_Sprite->setPosition(0, 36);
  auto l_EtSultan = GBase::DCreateAnimation("animationSultansBack").First;
  l_EtSultan->setPosition(0, 36);
  n_NodeSultansBack->getChildByName("Node_icon")->addChild(l_EtSultan);
  n_BtnSultansBack = GBase::GetChildByName<ui::Button *>(n_NodeSultansBack, "Button_rechargeLucky");
  n_BtnSultansBack->addTouchEventListener(CC_CALLBACK_2(UIMainTop::OnBtnClick, this));
  n_SultansBackRed = GBase::GetChildByName<Sprite *>(n_NodeSultansBack, "Sprite_numFrm");
  n_TxtSultansBackTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(n_NodeSultansBack, "Text_luckyTime"));
  n_BtnExplain = GBase::GetChildByName<ui::Button *>(m_Panel, "Button_gameExplain");
  n_BtnExplain->setPosition(Vec2(GBase::DFIsRA() ? 490 : 150, -100));
  m_TableBuilder.clear();
  m_TableBuilder.push_back(GBase::DGetExtendChildFromCCSByName<UIBuilderIcon>(m_Panel, "CCS_builderIcon_iron"));
  m_TableBuilder.push_back(GBase::DGetExtendChildFromCCSByName<UIBuilderIcon>(m_Panel, "CCS_builderIcon_gold"));
  AddBuildStarButton();
  n_NodeTroops = GBase::DGetExtendChildFromCCSByName<UIMarchingTroops>(m_Panel, "CCS_marchingTroops_troop");
  n_NodeTroops->setVisible(false);
  n_NodeLostRuins = GBase::GetChildByName<Node *>(m_Panel, "Node_LostRuins");
  n_LostRuinsTaskIcon = GBase::GetChildByName<ui::ImageView *>(n_NodeLostRuins, "Image_TaskIcon");
  n_LostRuinsProgress = UIHtmlRichText::DChangeTextToHtml(GBase::GetChildByName<ui::Text *>(n_NodeLostRuins, "Text_Progress"));
  n_LostRuinsTime = UITimerLabel::DCreateTimerLabel(GBase::GetChildByName<Node *>(n_NodeLostRuins, "Text_LeftTime"));
  n_LostRuinsGetAwardBtn = GBase::GetChildByName<ui::Button *>(n_NodeLostRuins, "Button_LostGetAward");
  n_LostRuinsGetAwardBtn->addTouchEventListener(CC_CALLBACK_2(UIMainTop::BtnLostRuinsGetAward, this));
  n_LostRuinsGetAwardBtn->setTitleText(Translate::i18n("common_text_1146"));
  n_TextLostTaskStatus = GBase::GetChildByName<ui::Text *>(n_LostRuinsGetAwardBtn, "Text_LostTaskStatus");
  n_TextLostTaskStatus->setString(Translate::i18n("common_text_2601"));
  RegisterListener();
  InitView();
  InitTimer();
  InitData();
  n_NodeStylePower = GBase::GetChildByName<Node *>(m_Panel, "Node_style_power");
  n_NodeStyleHead = GBase::GetChildByName<Node *>(m_Panel, "Node_style_head");
  InitStyle();
}

void UIMainTop::InitPanel()
{
  Ctor();
}

void UIMainTop::UpdateHeadPos(){
  // if SoraDIsBrave8Level() then
  if(GBase::DIsBrave8Level()){
    n_NodeHead->setPositionX(12);
    m_OffestY = 45;
  }else{
    n_NodeHead->setPositionX(57);
    m_OffestY = 0;
  }
  RangeLeftNodes();
  RangeLeft2Nodes();
  UpdateBuilderPos(-100 - m_OffestY);
}

void UIMainTop::UpdateBuilderPos(float p_OffsetY){
  for(int32 i = 0; i < (int32)m_TableBuilder.size(); i++){
    m_TableBuilder.at(i)->setPositionY(p_OffsetY - 80 * (i - 1));
    if(std::floor(GBase::Display::Get()->height == 853/**and v:getBuilderType() == gQueueTypeDef.build_star_queue_privilege */)){
      auto l_IsHide = GBase::DConfigGet<bool>("Game:GameSettingView:gameExplainSwitch~bool");
      m_TableBuilder.at(i)->setPosition(Vec2(GBase::DFIsRA() ? 490 : 150, l_IsHide ? -100 : -180));
    }
  }
}

void UIMainTop::UpdateLostRuinsNode(){
  // local lostRuinsCtrl = SoraDGetCtrl("lostRuinsCtrl")
  // local questInfo = lostRuinsCtrl:getRunningQuestInfo()
  // print("updateLostRuinsNode", clientEventMgr.judgeIsOpen(gActivityTimeActivityID.LOST_RUINS_ACTIVITY), lostRuinsCtrl:isRunningQuest())
  // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.LOST_RUINS_ACTIVITY, false) and next(questInfo) then
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
  // else
  //   self.nodeLostRuins:setVisible(false)
  // end
}

void UIMainTop::UpdateWindTowerNode(){
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

void UIMainTop::UpdateSnowWolfLostNode(){
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

void UIMainTop::InitHalloweenShineEffect(){
  // local effectShine = SoraDCreatAnimation("Node_Effect_wsj01", nil, true)
  // self.effectShine = effectShine
  // effectShine:setPosition(cc.p(195, 15))
  // self.imgPower:addChild(effectShine)
}

void UIMainTop::RangeLeftNodes(){}

void UIMainTop::RangeLeft2Nodes(){}


void UIMainTop::OnBtnJourneyClick(Ref*, ui::Widget::TouchEventType){}

void UIMainTop::BtnHeroRechargeClick(Ref*, ui::Widget::TouchEventType){}

void UIMainTop::BtnLostRuinsGetAward(Ref*, ui::Widget::TouchEventType){}

void UIMainTop::AddBuildStarButton(){}

void UIMainTop::OnBtnClick(Ref*, ui::Widget::TouchEventType){}

void UIMainTop::RegisterListener(){}

void UIMainTop::InitView(){}

void UIMainTop::InitTimer(){}

void UIMainTop::InitData(){}

void UIMainTop::InitStyle(){}

