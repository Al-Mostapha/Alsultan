#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/UIBasePanel.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/Common/Label/UICommonScoreLabel.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Common/Label/UIHtmlRichText.h"
#include "Module/UI/MainUI/UIBuilderIcon.h"
#include "Module/UI/MainUI/UIMarchingTroops.h"
#include "Module/UI/MainUI/UICommonGoldTop.h"
#include "Module/UI/MainUI/UICommonResourcesMenu.h"
#include "Module/UI/Common/UICommonPromptBox.h"
#include "Module/UI/EventCenter/EventTemplate/NewTrial/UINewTrialMainUI.h"
#include "Module/Activity/Activity.Enum.h"
#include "Base/Base.create.h"


class UIMainTop : public UIBasePanel
{
private: 
  CREATE_FUNC(UIMainTop);
  CreateUIPanel(UIMainTop);
  CreateUICCSView(UIMainTop);
  bool m_IsUpdateHP = false;
  bool m_IsSetHPStyle = false;
  bool m_IsShowEXP = false;

private:
  float m_OffestY = 0;
  GVector<UIBuilderIcon *> m_TableBuilder;
  EScene m_CurrentViewType = EScene::City;
  Node *n_NodeLOD = nullptr;
  Node *n_NodeAreaRt = nullptr;
  Node *n_NodeAreaLt = nullptr;
  Node *n_NodeAreaT = nullptr;
  UICommonGoldTop *n_NodeGold = nullptr;
  UICommonResourcesMenu *n_ResMenu = nullptr;
  ui::Button *n_BtnVip = nullptr;
  ui::ImageView *n_ImgVip = nullptr;
  Sprite *n_SpriteActiveVip = nullptr;
  ui::TextBMFont *n_LabelVip = nullptr;
  Sprite *n_SpVipPointFrm = nullptr;
  ui::ImageView *n_ImgLvBg = nullptr;
  ui::Text *n_LabelLv = nullptr;
  Sprite *n_SpriteHead = nullptr;
  Sprite *n_BarEXPBg = nullptr;
  ui::LoadingBar *n_BarEXP = nullptr;
  Sprite *n_BarHPBg = nullptr;
  ui::LoadingBar *n_BarStamina = nullptr;
  ui::Layout *n_NodeHead = nullptr;
  Node *n_NodeWeakPoint = nullptr;
  Sprite *n_SpriteLordHead = nullptr;
  ui::Button *n_BtnHead = nullptr;
  Sprite *n_SpriteHeadRedPoint = nullptr;
  Sprite *n_IconVipNew = nullptr;
  Sprite *n_ImgPower = nullptr;
  ui::Text *n_LabelPower = nullptr;
  UICommonScoreLabel *n_ScoreLabelPower = nullptr;
  ui::Button *n_BtnPower = nullptr;
  Sprite *n_IconGem = nullptr;
  ui::Button *n_BtnRechargeActivity = nullptr;
  Node *n_NodeRecharge = nullptr;
  Node *n_NodeRechargeIcon = nullptr;
  UITimerLabel *n_LabelRechargeTime = nullptr;
  Node *n_NodeEvent = nullptr;
  Node *n_NodeEventIcon = nullptr;
  ui::ImageView *n_ImageEvent = nullptr;
  Node *n_NodeNew = nullptr;
  ui::Button *n_BtnEvent = nullptr;
  ui::Text *n_LabelEventTime = nullptr;
  Sprite *n_SpriteEventRedPoint = nullptr;
  ui::Text *n_LabelEventRedNum = nullptr;
  ui::Layout *n_PanelTips = nullptr;
  Node *n_NodeNewJourney = nullptr;
  Node *n_NodeEtNew = nullptr;
  Node *n_NodeIconJourney = nullptr;
  ui::Text *n_TextNewJourney = nullptr;
  ui::Button *n_ButtonNewJourney = nullptr;
  Node *n_NodeLucky = nullptr;
  Sprite *n_LuckyNumFrm = nullptr;
  ui::Text *n_LuckyNumTxt = nullptr;
  UITimerLabel *n_TxtLuckyTime = nullptr;
  ui::Button *n_BtnLucky = nullptr;
  Node *n_NodeLuckyIcon = nullptr;
  Node *n_NodeCrazy = nullptr;
  Node *n_NodeCrazyIcon = nullptr;
  ui::Button *n_BtnCrazy = nullptr;
  UITimerLabel *n_TxtCrazyTime = nullptr;
  Sprite *n_RedPointCrazy = nullptr;
  Node *n_NodeHeroGift = nullptr;
  UIPanelBase *n_TxtHeroGiftTime = nullptr;
  ui::Button *n_BtnHeroGift = nullptr;
  Node *n_NodeKingCom = nullptr;
  ui::Button *n_BtnKing = nullptr;
  Sprite *n_KingRed = nullptr;
  UITimerLabel *n_TxtKingTime = nullptr;
  Node *n_NodeKingIcon = nullptr;
  Node *n_NodeSultansBack = nullptr;
  ui::Button *n_BtnSultansBack = nullptr;
  Sprite *n_SultansBackRed = nullptr;
  UITimerLabel *n_TxtSultansBackTime = nullptr;
  ui::Button *n_BtnExplain = nullptr;
  UIMarchingTroops *n_NodeTroops = nullptr;
  Node *n_NodeLostRuins = nullptr;
  ui::ImageView *n_LostRuinsTaskIcon = nullptr;
  UIHtmlRichText *n_LostRuinsProgress = nullptr;
  UITimerLabel *n_LostRuinsTime = nullptr;
  ui::Button *n_LostRuinsGetAwardBtn = nullptr;
  ui::Text *n_TextLostTaskStatus = nullptr;
  Node *n_NodeStylePower = nullptr;
  Node *n_NodeStyleHead = nullptr;
  Node *n_EffectShine = nullptr;
  UICommonPromptBox *n_HasShowNewTrialBox = nullptr;
  UINewTrailMainUI *n_NewTrailTeamUI = nullptr;
public:
  UIMainTop(){};
  ~UIMainTop(){};
  void Ctor();
  void Show() {};
  static UIMainTop *Create();
  void AddSubViews();
  void onEnter() override;
  void onExit() override;
  void OnBtnJourneyClick(Ref*, ui::Widget::TouchEventType);
  void BtnHeroRechargeClick(Ref*, ui::Widget::TouchEventType);
  void BtnLostRuinsGetAward(Ref*, ui::Widget::TouchEventType);
  void OnBtnClick(Ref*, ui::Widget::TouchEventType);
  void BtnPowerClickCallBack(Ref*, ui::Widget::TouchEventType);
  void BtnExplainClick(Ref*, ui::Widget::TouchEventType);
  void AddBuildStarButton();
  void RegisterListener();
  void InitView();
  void InitTimer();
  void InitData();
  void InitStyle();
  

  void RangeLeftNodes();
  void RangeLeft2Nodes();
  void UpdateBuilderPos(float p_OffsetY);


 
  void InitHalloweenShineEffect();

  void InitKingNode(EventCustom *p_Event);
  void InitSultansBackNode(EventCustom *p_Event); 
  void TradeBoardMsgShowTip(EventCustom *p_Event); 
  void UpdateRedPoint(EventCustom *p_Event); 
  void UpdateLostRuinsNode(EventCustom *p_Event);
  void UpdateWindTowerNode(EventCustom *p_Event);
  void UpdateSnowWolfLostNode(EventCustom *p_Event);
  void UpdateHeadPos(EventCustom *p_Event);

  void ReLoginFinish(EventCustom *p_Event); 
  void SetMarchingTroopsVisible(EventCustom *p_Event); 
  void UpdateLordInfo(EventCustom *p_Event); 
  void UpdateVip(EventCustom *p_Event); 
  void DefineWallDestroy(EventCustom *p_Event); 
  void InitRechargeBtn(EventCustom *p_Event); 
  void UpdateRechargeRedPoint(EventCustom *p_Event); 
  void GetEventCenterReturn(EventCustom *p_Event); 
  void InitCrazyBtn(EventCustom *p_Event); 
  void LuckyBtnPoint(EventCustom *p_Event); 
  void InitLuckyBtn(EventCustom *p_Event); 
  void RechargeCloseLoading(EventCustom *p_Event); 
  void ShowLordHPChange(EventCustom *p_Event); 
  void ShowLordPowerEXPChange(EventCustom *p_Event); 
  void LordPowerChange(EventCustom *p_Event); 
  void ShowLordEXPChange(EventCustom *p_Event); 
  void SetLordHPUpdate(EventCustom *p_Event); 
  void KingBattleFun(EventCustom *p_Event); 
  void LegendLordBattleVectoryFun(EventCustom *p_Event); 
  void PyramidBattleStartFun(EventCustom *p_Event); 
  void EndPyramid(EventCustom *p_Event); 
  void EndLegendLordWar(EventCustom *p_Event); 
  void GetEquipSuccess(EventCustom *p_Event); 
  void CheckServerIsOK4SDKCallBack(EventCustom *p_Event); 
  void HandlEscort(EventCustom *p_Event); 
  void InitEventNode(EventCustom *p_Event); 
  void MsgGuideEnd(EventCustom *p_Event); 
  void MsgInvitedInfo(EventCustom *p_Event); 
  void UpdateTeamMainUIWidget(EventCustom *p_Event); 
  void OnTeamMatchSuc(EventCustom *p_Event); 
  void OnRemainsWarEnd(EventCustom *p_Event); 
  void OnRadianceWarEnd(EventCustom *p_Event); 
  void OnRemainsWarTeamJoin(EventCustom *p_Event); 
  void UpdateAttackInfo(EventCustom *p_Event); 
  void RefreshNewTrialUI(EventCustom *p_Event); 
  void RefreshNewTrialTeam(EventCustom *p_Event); 
  void RefreshBeginNewTrial(EventCustom *p_Event); 
  void NewTrialEndRefresh(EventCustom *p_Event); 
  void RoyalSummonsGold(EventCustom *p_Event); 
  void AncientReelGold(EventCustom *p_Event); 
  void InitHeroGiftBtn(EventCustom *p_Event); 
  void CastleLevelUp(EventCustom *p_Event); 
  void KingdomLevelUp(EventCustom *p_Event); 
  void CheckSecondBuildStarButton(EventCustom *p_Event); 
  void ShowOrHideGuideView(EventCustom *p_Event); 
  void InitExplainBtn(); 
  void InitNewJourney();

  void UpdatePlayer(bool p_IsFirset = false);
  void UpdateLordPower();

  Label *ExchangeGroupText(Label *p_Label, float p_Height);
  Node *GetResTarget(EResource p_ResType);

  void RangeNodes(GVector<GString> p_TableBtnName, float p_PosY = 0);
  void OnMessageListener();
  void RefreshNodeEvent();

  Node *GetLodNode(){ return n_NodeLOD;}
  Node *GetNodeAreaTop(){ return n_NodeAreaT;}
  Node *GetNodeAreaRT(){ return n_NodeAreaRt;}
  Node *GetNodeAreaLT(){ return n_NodeAreaLt;}

private:
  bool IsRedPoint();
  void PopLuckyFrame();
  void UpdateSultansBackRed();
  void PopEventFrame(bool p_IsAdd = false);
  void UpdateGoldRedPoint();
  void UpdateMonthRedPoint();
  void PopEventFromEventCenter();

  void AddEffectOrAnimationByEventIndex(int p_EventIndex);
  void GetLuckyGiftEffect();
  void GetEventCenterReturn_imp(EActivityTime p_Activity);

  void CheckBuildStarButton();
};


