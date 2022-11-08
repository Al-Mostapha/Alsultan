#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/Common/Label/UICommonScoreLabel.h"
#include "Module/UI/Common/Timer/UITimerLabel.h"
#include "Module/UI/Common/Label/UIHtmlRichText.h"
#include "Module/UI/MainUI/UIBuilderIcon.h"
#include "Module/UI/MainUI/UIMarchingTroops.h"
#include "Module/UI/MainUI/UICommonGoldTop.h"
#include "Module/UI/MainUI/UICommonResourcesMenu.h"
#include "Base/Base.create.h"


class UIMainTop : public UIPanelBase
{

private:
  CREATE_FUNC(UIMainTop);
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
public:
  UIMainTop(){};
  ~UIMainTop(){};
  void InitPanel() override;
  void Ctor();
  void Show() override {};
  static UIMainTop *Create() {return create();};
  void OnBtnJourneyClick(Ref*, ui::Widget::TouchEventType);
  void BtnHeroRechargeClick(Ref*, ui::Widget::TouchEventType);
  void BtnLostRuinsGetAward(Ref*, ui::Widget::TouchEventType);
  void OnBtnClick(Ref*, ui::Widget::TouchEventType);
  void AddBuildStarButton();
  void RegisterListener();
  void InitView();
  void InitTimer();
  void InitData();
  void InitStyle();
  
  void UpdateHeadPos();
  void RangeLeftNodes();
  void RangeLeft2Nodes();
  void UpdateBuilderPos(float p_OffsetY);
  void UpdateLostRuinsNode();
  void UpdateWindTowerNode();
  void UpdateSnowWolfLostNode();
  void InitHalloweenShineEffect();
};


