#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Panel/Chat/UIChatMainUiView.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Module/UI/Common/UIPreDownloadMainWidget.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/Part/Quest/UIQuestGuideNode.h"
#include "Module/Activity/Activity.Type.h"

struct RGreenTipsCount{
  int32 alliance;
  int32 mail;
  int32 hero;
  int32 items;
};

class UIMainBottom : public UIBaseView {
  private:
  CREATE_FUNC(UIMainBottom);
  CreateUIPanel(UIMainBottom);
  CreateUICCSView(UIMainBottom);
  Node* _NodeLOD = nullptr;
  Node* _NodeAreaRb = nullptr;
  Node* _NodeAreaLb = nullptr;
  Node* _NodeAreaB = nullptr;
  EScene _ViewChangeType = EScene::City;
  Sprite* _UiBg = nullptr;
  ui::ImageView* _UiBgLeft = nullptr;
  ui::ImageView* _UiBgRight = nullptr;
  Node* _NodeStyleBg = nullptr;
  Node* _NodeStyleTop = nullptr;
  ui::ImageView* _TipItems = nullptr;
  ui::ImageView* _TipAlliance = nullptr;
  ui::ImageView* _TipMail = nullptr;
  ui::ImageView* _TipHero = nullptr;
  Label *_TipHeroCount = nullptr;
  Label *_TipMailCount = nullptr;
  Label *_TipAllianceCount = nullptr;
  Label *_TipItemsCount = nullptr;
  UIChatMainUiView* _ChatMainUIView = nullptr;
  Sprite* _FrameWorldCity = nullptr;
  ui::Button* _ButtonWorldCity = nullptr;
  ui::ImageView* _ImgWorldCity = nullptr;
  ui::Button* _BtnAccount = nullptr;
  Sprite* _IconAccount = nullptr;
  Sprite* _RedPointAccount = nullptr;
  ui::Button* _BtnPyramidBattle = nullptr;
  Sprite* _SpriteBattleTimeBg = nullptr;
  UITimerLabel* _TxtPyramidBattleTime = nullptr;
  ui::Button* _BtnPyramidPlayoffs = nullptr;
  Sprite* _ImgPyramidPlayoffsBg = nullptr;
  UITimerLabel* _TxtPyramidPlayoffsTime = nullptr;
  ui::Button* _BtnCityUnlock = nullptr;
  Sprite* _SpriteCityUnlock = nullptr;
  ui::Text* _TxtCityUnlock = nullptr;
  ui::Button* _BtnNewPlayerBuff = nullptr;
  UITimerLabel* _TextNewPlayer = nullptr;
  ui::Button* _BtnPrinceGiftNewBuff = nullptr;
  UITimerLabel* _TextPrinceGiftNew = nullptr;
  Sprite* _SpritePrinceGiftNewBuff = nullptr;
  ui::Button* _BtnPrinceGiftBuff = nullptr;
  UITimerLabel* _TextPrinceGift = nullptr;
  Sprite* _SpritePrinceGiftBuff = nullptr;
  ui::Button* _BtnSultansWelBack = nullptr;
  UITimerLabel* _TextWelBack = nullptr;
  ui::Button* _BtnHero = nullptr;
  ui::ImageView* _IconBtnHero = nullptr;
  ui::Button* _BtnItems = nullptr;
  ui::ImageView* _IconBtnItems = nullptr;
  Sprite* _ItemNewIcon = nullptr;
  Node* _NodeDiscountEffect = nullptr;
  ui::Button* _BtnMail = nullptr;
  ui::ImageView* _IconBtnMail = nullptr;
  ui::Button* _BtnAlliance = nullptr;
  ui::ImageView* _IconBtnAlliance = nullptr;
  ui::Button* _BtnWatchTower = nullptr;
  Sprite* _IconAlarm = nullptr;
  ui::Button* _BtnWallBurning = nullptr;
  ui::Button* _BtnKingdomManager = nullptr;
  Sprite* _BtnKingdomManagerSprite = nullptr;
  Sprite* _SpKingdomManagerTimeBg = nullptr;
  UITimerLabel* _TxtKingdomManagerTime = nullptr;
  ui::Button* _BtnLegendKingManager = nullptr;
  Sprite* _BtnLegendKingManagerSprite = nullptr;
  Sprite* _SpLegendKingManagerTimeBg = nullptr;
  UITimerLabel* _TxtLegendKingManagerTime = nullptr;
  ui::Button* _BtnLegendInvite = nullptr;
  Sprite* _IconLegendInvite = nullptr;
  UITimerLabel* _TxtLegendInviteNum = nullptr;
  ui::Button* _BtnRadianceWar = nullptr;
  Sprite* _IconRadianceWar = nullptr;
  Sprite* _SpriteEffect = nullptr;
  UITimerLabel* _TxtRadianceWarNum = nullptr;
  ui::Button* _BtnHegemonManager = nullptr;
  Sprite* _BtnHegemonManagerSprite = nullptr;
  Sprite* _SpHegemonManagerTimeBg = nullptr;
  UITimerLabel* _TxtHegemonManagerTime = nullptr;
  ui::Button* _BtnHegemonBattle = nullptr;
  Sprite* _BtnHegemonBattleSprite = nullptr;
  Sprite* _SpHegemonBattleTimeBg = nullptr;
  UITimerLabel* _TxtHegemonBattleTime = nullptr;
  ui::Button* _BtnTrainPower = nullptr;
  ui::Text* _TextTrainPower = nullptr;
  Sprite* _RedTrainPower = nullptr;
  ui::Text* _NumTrainPower = nullptr;
  ui::Button* _BtnNeckLaceRank = nullptr;
  Sprite* _BtnNeckLaceRankSprite = nullptr;
  Sprite* _BtnNeckLaceRankBg = nullptr;
  ui::Text* _BtnNeckLaceRankText = nullptr;
  ui::Button* _BtnRomanSoul = nullptr;
  Label* _LabelAllianceName = nullptr;
  Label* _LabelHeroName = nullptr;
  Label* _LabelBagName = nullptr;
  Label* _LabelMailName = nullptr;
  ui::Button* _BtnSkill = nullptr;
  ui::Button* _BtnReplay = nullptr;
  Sprite* _BgTextVideo = nullptr;
  Scheduler* _Timer = nullptr;
  ui::Text* _TextVideo = nullptr;
  Sprite* _FrameMainGuide = nullptr;
  UIQuestGuideNode *_NodeQuestGuide = nullptr;
  UIPreDownloadMainWidget* _NodePreDownload = nullptr;
  Node* _NodeBottomBtn = nullptr;
  ui::ImageView* _BtnManager = nullptr;
  ui::ScrollView* _ScrollBtn = nullptr;
  ui::Button* _BtnSwitch = nullptr;
  Node* _NodeArrow = nullptr;
  Sprite* _IconRed = nullptr;
  ui::Text* _LabBtnNum = nullptr;
  int32 _BtnSwitchType = 1;
  ui::Button *_BtnLuckyRecharge = nullptr;
  ui::Button *_BtnHarvestSeason = nullptr;
  ui::Button *_BtnQuestionnaire = nullptr;
  ui::Button *_BtnLostRuins = nullptr;
  ui::Button *_BtnWindTower = nullptr;
  ui::Button *_BtnSnowWolfLost = nullptr;
  ui::Button *_BtnCrazyTrio = nullptr;
  ui::Button *_BtnCommunity = nullptr;
  ui::Button *_BtnMonthCard = nullptr;
  ui::Button *_BtnEnjoyLottery = nullptr;
  ui::Button *_BtnGoldPackage = nullptr;
  Node *_LuckyBlessNode = nullptr;
  Scheduler *_ExpostulationTimer = nullptr;
  Node *_BtnHelpAll = nullptr;
  Node *_EffectShine = nullptr;
  public:
  UIMainBottom(){};
  ~UIMainBottom(){};
  void InitPanel() {};
  void Ctor();
  void Show() {};
  static UIMainBottom* Create() { 
    return Create("UiParts/MainUi/mainUIBottom.csb");
  };

  void InitGroup();
  void InitStyle();
  void InitGreenPoint();
  void InitAllianceView();
  void ShowAllianceInWarEffect();
  void InitBattleOpenBtn();


  Node *GetLodNode(){ return _NodeLOD; };
  Node *GetNodeAreaBottom(){ return _NodeAreaB; }
  Node *GetNodeAreaRB(){ return _NodeAreaRb; }
  Node *GetNodeAreaLB(){ return _NodeAreaLb; }

  Label *ExchangeGroupText(ui::Text *p_Node, float p_Height = 0);

  void OnWorldCityClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnSkillClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnReplayClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

  void OnHeroClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnItemClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnMailClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void OnAllianceClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

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
  void OnCommunityClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type, RActivityShowData p_Info);
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
  void AddCommunityButton(RActivityShowData p_Info);
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
  void ShowFireBorder(bool p_IsRemove = false);
  void RefreshBattleOpenBtn(float p_Delta);
  ui::Button *GetBtnTarget(const GString &p_Name);
  void CheckRemainsWar();

  void ReLoginFinish(EventCustom *p_Event);
  void OpenUIAlliance(EventCustom *p_Event);
  void CurrentShowViewType(EventCustom *p_Event);
  void ShowOrHideGuideView(EventCustom *p_Event);
  void AddPrinceGiftNewBuffButton(EventCustom *p_Event);
  void ShowPrinceGiftGuideView(EventCustom *p_Event);
  void AddPrinceGiftBuffButton(EventCustom *p_Event);
  void ShowSinbadPopWindow(EventCustom *p_Event);
  void CheckWatchTower(EventCustom *p_Event);
  void CheckRomanSoul(EventCustom *p_Event);
  void BtnPyramidBattleCheck(EventCustom *p_Event);
  void GreenPointUpdate(EventCustom *p_Event);
  void GreenPointUpdateByType(EventCustom *p_Event);
  void CheckWallDefend(EventCustom *p_Event);
  void RemovefirstJoinAllianceAnimation(EventCustom *p_Event);
  void BtnKingdomManagerCheck(EventCustom *p_Event);
  void BtnLegendKingManagerCheck(EventCustom *p_Event);
  void MsgHegemonClean(EventCustom *p_Event);
  void BtnHegemonManagerCheck(EventCustom *p_Event);
  void BtnHegemonBattleCheck(EventCustom *p_Event);
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
