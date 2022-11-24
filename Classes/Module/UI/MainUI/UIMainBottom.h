#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Panel/Chat/UIChatMainUiView.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Module/UI/Common/UIPreDownloadMainWidget.h"

struct RGreenTipsCount{
  int32 alliance;
  int32 mail;
  int32 hero;
  int32 items;
};

class UIMainBottom : public UIPanelBase {
  private:
  CREATE_FUNC(UIMainBottom);
  Node* n_NodeLOD = nullptr;
  Node* n_NodeAreaRb = nullptr;
  Node* n_NodeAreaLb = nullptr;
  Node* n_NodeAreaB = nullptr;
  EScene m_ViewChangeType = EScene::City;
  Sprite* n_UiBg = nullptr;
  ui::ImageView* n_UiBgLeft = nullptr;
  ui::ImageView* n_UiBgRight = nullptr;
  Node* n_NodeStyleBg = nullptr;
  Node* n_NodeStyleTop = nullptr;
  ui::ImageView* n_TipItems = nullptr;
  ui::ImageView* n_TipAlliance = nullptr;
  ui::ImageView* n_TipMail = nullptr;
  ui::ImageView* n_TipHero = nullptr;
  ui::Text* n_TipHeroCount = nullptr;
  ui::Text* n_TipMailCount = nullptr;
  ui::Text* n_TipAllianceCount = nullptr;
  ui::Text* n_TipItemsCount = nullptr;
  UIChatMainUiView* n_ChatMainUIView = nullptr;
  Sprite* n_FrameWorldCity = nullptr;
  ui::Button* n_ButtonWorldCity = nullptr;
  ui::ImageView* n_ImgWorldCity = nullptr;
  ui::Button* n_BtnAccount = nullptr;
  Sprite* n_IconAccount = nullptr;
  Sprite* n_RedPointAccount = nullptr;
  ui::Button* n_BtnPyramidBattle = nullptr;
  Sprite* n_SpriteBattleTimeBg = nullptr;
  UITimerLabel* n_TxtPyramidBattleTime = nullptr;
  ui::Button* n_BtnPyramidPlayoffs = nullptr;
  Sprite* n_ImgPyramidPlayoffsBg = nullptr;
  UITimerLabel* n_TxtPyramidPlayoffsTime = nullptr;
  ui::Button* n_BtnCityUnlock = nullptr;
  Sprite* n_SpriteCityUnlock = nullptr;
  ui::Text* n_TxtCityUnlock = nullptr;
  ui::Button* n_BtnNewPlayerBuff = nullptr;
  UITimerLabel* n_TextNewPlayer = nullptr;
  ui::Button* n_BtnPrinceGiftNewBuff = nullptr;
  UITimerLabel* n_TextPrinceGiftNew = nullptr;
  Sprite* n_SpritePrinceGiftNewBuff = nullptr;
  ui::Button* n_BtnPrinceGiftBuff = nullptr;
  UITimerLabel* n_TextPrinceGift = nullptr;
  Sprite* n_SpritePrinceGiftBuff = nullptr;
  ui::Button* n_BtnSultansWelBack = nullptr;
  UITimerLabel* n_TextWelBack = nullptr;
  ui::Button* n_BtnHero = nullptr;
  ui::ImageView* n_IconBtnHero = nullptr;
  ui::Button* n_BtnItems = nullptr;
  ui::ImageView* n_IconBtnItems = nullptr;
  Sprite* n_ItemNewIcon = nullptr;
  Node* n_NodeDiscountEffect = nullptr;
  ui::Button* n_BtnMail = nullptr;
  ui::ImageView* n_IconBtnMail = nullptr;
  ui::Button* n_BtnAlliance = nullptr;
  ui::ImageView* n_IconBtnAlliance = nullptr;
  ui::Button* n_BtnWatchTower = nullptr;
  Sprite* n_IconAlarm = nullptr;
  ui::Button* n_BtnWallBurning = nullptr;
  ui::Button* n_BtnKingdomManager = nullptr;
  Sprite* n_BtnKingdomManagerSprite = nullptr;
  Sprite* n_SpKingdomManagerTimeBg = nullptr;
  UITimerLabel* n_TxtKingdomManagerTime = nullptr;
  ui::Button* n_BtnLegendKingManager = nullptr;
  Sprite* n_BtnLegendKingManagerSprite = nullptr;
  Sprite* n_SpLegendKingManagerTimeBg = nullptr;
  UITimerLabel* n_TxtLegendKingManagerTime = nullptr;
  ui::Button* n_BtnLegendInvite = nullptr;
  Sprite* n_IconLegendInvite = nullptr;
  UITimerLabel* n_TxtLegendInviteNum = nullptr;
  ui::Button* n_BtnRadianceWar = nullptr;
  Sprite* n_IconRadianceWar = nullptr;
  Sprite* n_SpriteEffect = nullptr;
  UITimerLabel* n_TxtRadianceWarNum = nullptr;
  ui::Button* n_BtnHegemonManager = nullptr;
  Sprite* n_BtnHegemonManagerSprite = nullptr;
  Sprite* n_SpHegemonManagerTimeBg = nullptr;
  UITimerLabel* n_TxtHegemonManagerTime = nullptr;
  ui::Button* n_BtnHegemonBattle = nullptr;
  Sprite* n_BtnHegemonBattleSprite = nullptr;
  Sprite* n_SpHegemonBattleTimeBg = nullptr;
  UITimerLabel* n_TxtHegemonBattleTime = nullptr;
  ui::Button* n_BtnTrainPower = nullptr;
  ui::Text* n_TextTrainPower = nullptr;
  Sprite* n_RedTrainPower = nullptr;
  ui::Text* n_NumTrainPower = nullptr;
  ui::Button* n_BtnNeckLaceRank = nullptr;
  Sprite* n_BtnNeckLaceRankSprite = nullptr;
  Sprite* n_BtnNeckLaceRankBg = nullptr;
  ui::Text* n_BtnNeckLaceRankText = nullptr;
  ui::Button* n_BtnRomanSoul = nullptr;
  ui::Text* n_LabelAllianceName = nullptr;
  ui::Text* n_LabelHeroName = nullptr;
  ui::Text* n_LabelBagName = nullptr;
  ui::Text* n_LabelMailName = nullptr;
  ui::Button* n_BtnSkill = nullptr;
  ui::Button* n_BtnReplay = nullptr;
  Sprite* n_BgTextVideo = nullptr;
  Scheduler* m_Timer = nullptr;
  ui::Text* n_TextVideo = nullptr;
  Sprite* n_FrameMainGuide = nullptr;
  UIPreDownloadMainWidget* n_NodePreDownload = nullptr;
  Node* n_NodeBottomBtn = nullptr;
  ui::ImageView* n_BtnManager = nullptr;
  ui::ScrollView* n_ScrollBtn = nullptr;
  ui::Button* n_BtnSwitch = nullptr;
  Node* n_NodeArrow = nullptr;
  Sprite* n_IconRed = nullptr;
  ui::Text* n_LabBtnNum = nullptr;
  int32 m_BtnSwitchType = 1;
  ui::Button* n_BtnLuckyRecharge = nullptr;
  ui::Button* n_BtnHarvestSeason = nullptr;

  public:
  UIMainBottom(){};
  ~UIMainBottom(){};
  void InitPanel() override{};
  void Ctor();
  void Show() override{};
  static UIMainBottom* Create() { return create(); };

  void InitGroup();
  void InitStyle();
  void InitGreenPoint();
  void InitAllianceView();
  void ShowAllianceInWarEffect();
  void InitBattleOpenBtn();


  Node *GetLodNode(){ return n_NodeLOD; };
  Node *GetNodeAreaBottom(){ return n_NodeAreaB; }
  Node *GetNodeAreaRB(){ return n_NodeAreaRb; }
  Node *GetNodeAreaLB(){ return n_NodeAreaLb; }

  ui::Text *ExchangeGroupText(ui::Text *p_Node, float p_Height = 0);

  void OnWorldCityClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnSkillClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnReplayClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnBottomClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnWatchTowerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnWallBurningClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnKingdomManagerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnLegendKingManagerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnLegendInviteClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnRadianceWarClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnHegemonManagerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnHegemonBattleClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnTrainPowerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnRomanSoulClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPyramidBattleClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPyramidPlayoffsClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnCityUnlockClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnNewPlayerBuffClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnSultansBackWelClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnAccountClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnNeckLaceRankClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPrinceGiftNewBuffClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPrinceGiftBuffClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnSwitchClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnMonthCardClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnCommunityClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnLostRuinsClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnWindTowerClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnSnowWolfLostClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnCrazyTrioClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnQuestionnaireClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnEnjoyLotteryClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnGoldPackageClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnLuckyReachergeClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnKOChoiceClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnHelpAllClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnBattleOpenClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPayBackClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
 
  
  void RecordTimeTick(float p_Delta);
  void OnExitOther();
  void ShowWallFireEffect();
  void HideWallFireEffect();
  void AddFirstJoinAllianceAnimation();

  void CreateExpostulationTimer();
  void DeleteExpostulationTimer();
  void InitHalloweenShineEffect();
  void OnMessageListener();
  void Req4AllianceInviteData();
  GVector<bool> GetMonthlyCard();
  void AddQuestionnaireButton(int32  p_Num);
  void AddCommunityButton(void *p_Info);
  void AddMonthCardButton();
  void UpdateEnjoyLotteryButton();
  void AddGoldPackageButton();
  void UpdateGreenTip(RGreenTipsCount *p_BtnState);
  void InitTipJump(Node *p_Node);
  void BtnTrainPowerManagerCheck();
  void SwitchBottonBtn();
  void AddSixYearActivityButton();
  void UpdateGreenPointAlliance();
  void OpenRadianceWarning(bool p_IsOpen);
  void OpenWarning(bool p_IsOpen);
  void UpdateItemsBtn();
  void ShowFireBorder(bool p_IsRemove);
  void RefreshBattleOpenBtn(float p_Delta);
  ui::Button *GetBtnTarget(const GString &p_Name);
  void CheckRemainsWar();

  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINFINSH", handler(self, self.reLoginFinish))
  void ReLoginFinish(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_CHAT_OPEN_UI_ALLIANCE", handler(self, self.openUIAlliance))
  void OpenUIAlliance(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_ONSHOW", handler(self, self.currentShowViewType))
  void CurrentShowViewType(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", handler(self, self.showOrHideGuideView))
  void ShowOrHideGuideView(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_REQ_NEW_PRINCE_GIFT_BUY_PACKAGE", handler(self, self.addPrinceGiftNewBuffButton))
  void AddPrinceGiftNewBuffButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PRINCE_GIFT_GUIDE_BUFF_REFRESH", handler(self, self.showPrinceGiftGuideView))
  void ShowPrinceGiftGuideView(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PRINCE_GIFT_GUIDE_REFRESH", handler(self, self.addPrinceGiftBuffButton))
  void AddPrinceGiftBuffButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SINBAD_TREASURE_UPDATE_LV_POP_WINDOW", handler(self, self.showSinbadPopWindow))
  void ShowSinbadPopWindow(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_WATCHTOWER_ADDINFO", handler(self, self.checkWatchTower))
  void CheckWatchTower(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_ROMANSOUL_ALLIANCEATTACK", handler(self, self.checkRomanSoul))
  void CheckRomanSoul(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_PYRAMIDBATTLE_MAINUIICONCHECK", handler(self, self.btnPyramidBattleCheck))
  void BtnPyramidBattleCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_GREEN_POINT_UPDATE", handler(self, self.greenPointUpdate))
  void GreenPointUpdate(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_GREEN_POINT_UPDATE_BYTYPE", handler(self, self.greenPointUpdateByType))
  void GreenPointUpdateByType(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_WALLS_NOTIFY_SUCCESS", handler(self, self.checkWallDefend))
  void CheckWallDefend(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_JOIN_SUCCESS", handler(self, self.RemovefirstJoinAllianceAnimation))
  void RemovefirstJoinAllianceAnimation(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_KINGDOMWAR_KINGDOMUSR_CHANGED", handler(self, self.btnKingdomManagerCheck))
  void BtnKingdomManagerCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGENDLORD_LORD_NOTIFY_CLEAN", handler(self, self.btnLegendKingManagerCheck))
  void BtnLegendKingManagerCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_CLEAN", handler(self, self.msgHegemonClean))
  void MsgHegemonClean(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_LORD_NOTIFY_AP_LT", handler(self, self.btnHegemonManagerCheck))
  void BtnHegemonManagerCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_HEGEMON_UPDATE_MAINUI_HEGEMON", handler(self, self.btnHegemonBattleCheck))
  void BtnHegemonBattleCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", handler(self, self.btnCityUnlockCheck))
  void BtnCityUnlockCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_NEWPLAYER_BUFF_END", handler(self, self.btnNewPlayerBuffCheck))
  void BtnNewPlayerBuffCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SULTANSBACK_WELCOME_REFRESH", handler(self, self.btnSultansBackWelCheck))
  void BtnSultansBackWelCheck(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAIN_RECORD_SCREEN", handler(self, self.startRecordScreen))
  void StartRecordScreen(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAIN_STOP_RECORD_SCREEN", handler(self, self.stopRecording))
  void StopRecording(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_LUCKY_DAY_UPDATE", handler(self, self.updateEventcenter))
  void UpdateEventcenter(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_WALLS_DEFENCE_DESTROY", handler(self, self.defineWallDestroy))
  void DefineWallDestroy(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_WALLS_DEFENCE_DESTROY_RECOVER", handler(self, self.defineWallDestroyRecover))
  void DefineWallDestroyRecover(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_BIND_AWARD", handler(self, self.initAccountBind))
  void InitAccountBind(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAIN_BTN_UPDATE", handler(self, self.updateBtnContainer))
  void UpdateBtnContainer(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MONTHLY_CARD_REFRESH_BACK", handler(self, self.updateMonthCardButton))
  void UpdateMonthCardButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", handler(self, self.getEventCenterReturn))
  void GetEventCenterReturn(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_MAINUIINVITE_REFRESH", handler(self, self.initAllianceInvitePop))
  void InitAllianceInvitePop(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_BY_UID", handler(self, self.serverMessageGetLordInfo))
  void ServerMessageGetLordInfo(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ALLIANCE_REQ_INFO_BACK", handler(self, self.serverMessageGetAllianceInfo))
  void ServerMessageGetAllianceInfo(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_START_BY_STEP", handler(self, self.recevieGuideMsg))
  void RecevieGuideMsg(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ITEM_CHANGE_TYPE", handler(self, self.recevieItemChangeMsg))
  void RecevieItemChangeMsg(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_UI_EXPOSTULATION_UPDATE", handler(self, self.updateExpostulation))
  void UpdateExpostulation(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", handler(self, self.showLuckyBless))
  void ShowLuckyBless(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_GOLD_PACKAGE_STATE", handler(self, self.updateGoldPackageButton))
  void UpdateGoldPackageButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_LUCKY_RECHARGE_REFRESH", handler(self, self.updateBtnLuckyRecharge))
  void UpdateBtnLuckyRecharge(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ALLIACNE_GET_ALLIANCE_HELP_LIST_SUCCESS", handler(self, self.initHelpAllBtn))
  void InitHelpAllBtn(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_LEGEND_TEAM_INVITED_INFO", handler(self, self.msgInvitedInfo_legend))
  void MsgInvitedInfoLegend(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_ITEM_LIMITITEM_TIMEOUT_BACK", handler(self, self.updateShopNewTag))
  void UpdateShopNewTag(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_QUESTIONNAIRE_REFRESH", handler(self, self.updateQuestionnaireButton))
  void UpdateQuestionnaireButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_UI_EVENTCENTER_REFRESHISNEW", handler(self, self.updateCommunityButton))
  void UpdateCommunityButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_RADIANCE_WAR_WARNING", handler(self, self.updateGreenPointRadianceWar))
  void UpdateGreenPointRadianceWar(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_RADIANCE_WAR_LONGTIMEUNLOGIN", handler(self, self.showLongTimeUnlogin))
  void ShowLongTimeUnlogin(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_KOCHOICE_REFRESH", handler(self, self.addKOChoiceButton))
  void AddKOChoiceButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH", handler(self, self.refreshTrainPower))
  void RefreshTrainPower(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_LOST_RUINS_REFRESH", handler(self, self.addLostRuinsButton))
  void AddLostRuinsButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_WIND_TOWER_REFRESH", handler(self, self.addWindTowerButton))
  void AddWindTowerButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SNOWWOLF_LOST_REFRESH", handler(self, self.addSnowWolfLostButton))
  void AddSnowWolfLostButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_SHOWDOWN", handler(self, self.updateCrazyTrioButton))
  void UpdateCrazyTrioButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_CUMUACTIVITY_CRAZYTRIO_RELASH", handler(self, self.addCrazyTrioButton))
  void AddCrazyTrioButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_UPGRADE_LEVEL", handler(self, self.updateBtnStatues))
  void UpdateBtnStatues(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINUIBOTTOM_SORTBOTTOMQUESTBTNS", handler(self, self.sortBottomQuestBtns))
  void SortBottomQuestBtns(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_MAIL_REQ_BATTLE_REPORT_BACK", handler(self, self.openReportMail))
  void OpenReportMail(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", handler(self, self.addHarvestSeasonButton))
  void AddHarvestSeasonButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_REFRESH", handler(self, self.checkPreDownloadStatus))
  void CheckPreDownloadStatus(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_REFRESH_DOWNLOAD", handler(self, self.checkPreDownload))
  void CheckPreDownload(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_GAME_DOWNSUC", handler(self, self.OnPreDownloadSuc))
  void OnPreDownloadSuc(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_PAYBACK_NOTICE", handler(self, self.btnPayBackCheck))
  void BtnPayBackCheck(EventCustom *p_Event);
  void MsgUpdateMailIconNumber(EventCustom *p_Event);
  void sMsgUpdateNumberNewMail(EventCustom *p_Event);
  void GetEventCenterReturn_Imp(EventCustom *p_Event);
  void BtnNeckLaceRankCheck(EventCustom *p_Event);
};
