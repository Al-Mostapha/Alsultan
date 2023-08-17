#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/UIBasePanel.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UICCSView.h"
#include "Module/UI/Common/Label/UICommonScoreLabel.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Common/Label/UIHtmlRichText.h"
#include "Module/UI/MainUI/City/UIBuilderIcon.h"
#include "Module/UI/MainUI/UIMarchingTroops.h"
#include "Module/UI/Part/Common/Button/UICommonGoldTop.h"
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
  bool _IsUpdateHP = false;
  bool _IsSetHPStyle = false;
  bool _IsShowEXP = false;

private:
  float m_OffestY = 0;
  GVector<UIBuilderIcon *> _TableBuilder;
  EScene _CurrentViewType = EScene::City;
  Node *_NodeLOD = nullptr;
  Node *_NodeAreaRt = nullptr;
  Node *_NodeAreaLt = nullptr;
  Node *_NodeAreaT = nullptr;
  UICommonGoldTop *_NodeGold = nullptr;
  UICommonResourcesMenu *_ResMenu = nullptr;
  ui::Button *_BtnVip = nullptr;
  ui::ImageView *_ImgVip = nullptr;
  Sprite *_SpriteActiveVip = nullptr;
  ui::TextBMFont *_LabelVip = nullptr;
  Sprite *_SpVipPointFrm = nullptr;
  ui::ImageView *_ImgLvBg = nullptr;
  ui::Text *_LabelLv = nullptr;
  Sprite *_SpriteHead = nullptr;
  Sprite *_BarEXPBg = nullptr;
  ui::LoadingBar *_BarEXP = nullptr;
  Sprite *_BarHPBg = nullptr;
  ui::LoadingBar *_BarStamina = nullptr;
  ui::Layout *_NodeHead = nullptr;
  Node *_NodeWeakPoint = nullptr;
  Sprite *_SpriteLordHead = nullptr;
  ui::Button *_BtnHead = nullptr;
  Sprite *_SpriteHeadRedPoint = nullptr;
  Sprite *_IconVipNew = nullptr;
  Sprite *_ImgPower = nullptr;
  ui::Text *_LabelPower = nullptr;
  UICommonScoreLabel *_ScoreLabelPower = nullptr;
  ui::Button *_BtnPower = nullptr;
  Sprite *_IconGem = nullptr;
  ui::Button *_BtnRechargeActivity = nullptr;
  Node *_NodeRecharge = nullptr;
  Node *_NodeRechargeIcon = nullptr;
  UITimerLabel *_LabelRechargeTime = nullptr;
  Node *_NodeEvent = nullptr;
  Node *_NodeEventIcon = nullptr;
  ui::ImageView *_ImageEvent = nullptr;
  Node *_NodeNew = nullptr;
  ui::Button *_BtnEvent = nullptr;
  ui::Text *_LabelEventTime = nullptr;
  Sprite *_SpriteEventRedPoint = nullptr;
  ui::Text *_LabelEventRedNum = nullptr;
  ui::Layout *_PanelTips = nullptr;
  Node *_NodeNewJourney = nullptr;
  Node *_NodeEtNew = nullptr;
  Node *_NodeIconJourney = nullptr;
  ui::Text *_TextNewJourney = nullptr;
  ui::Button *_ButtonNewJourney = nullptr;
  Node *_NodeLucky = nullptr;
  Sprite *_LuckyNumFrm = nullptr;
  ui::Text *_LuckyNumTxt = nullptr;
  UITimerLabel *_TxtLuckyTime = nullptr;
  ui::Button *_BtnLucky = nullptr;
  Node *_NodeLuckyIcon = nullptr;
  Node *_NodeCrazy = nullptr;
  Node *_NodeCrazyIcon = nullptr;
  ui::Button *_BtnCrazy = nullptr;
  UITimerLabel *_TxtCrazyTime = nullptr;
  Sprite *_RedPointCrazy = nullptr;
  Node *_NodeHeroGift = nullptr;
  UITimerLabel *_TxtHeroGiftTime = nullptr;
  ui::Button *_BtnHeroGift = nullptr;
  Node *_NodeKingCom = nullptr;
  ui::Button *_BtnKing = nullptr;
  Sprite *_KingRed = nullptr;
  UITimerLabel *_TxtKingTime = nullptr;
  Node *_NodeKingIcon = nullptr;
  Node *_NodeSultansBack = nullptr;
  ui::Button *_BtnSultansBack = nullptr;
  Sprite *_SultansBackRed = nullptr;
  UITimerLabel *_TxtSultansBackTime = nullptr;
  ui::Button *_BtnExplain = nullptr;
  UIMarchingTroops *_NodeTroops = nullptr;
  Node *_NodeLostRuins = nullptr;
  ui::ImageView *_LostRuinsTaskIcon = nullptr;
  UIHtmlRichText *_LostRuinsProgress = nullptr;
  UITimerLabel *_LostRuinsTime = nullptr;
  ui::Button *_LostRuinsGetAwardBtn = nullptr;
  ui::Text *_TextLostTaskStatus = nullptr;
  Node *_NodeStylePower = nullptr;
  Node *_NodeStyleHead = nullptr;
  Node *_EffectShine = nullptr;
  UICommonPromptBox *_HasShowNewTrialBox = nullptr;
  UINewTrailMainUI *_NewTrailTeamUI = nullptr;
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

  Node *GetLodNode(){ return _NodeLOD;}
  Node *GetNodeAreaTop(){ return _NodeAreaT;}
  Node *GetNodeAreaRT(){ return _NodeAreaRt;}
  Node *GetNodeAreaLT(){ return _NodeAreaLt;}

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


