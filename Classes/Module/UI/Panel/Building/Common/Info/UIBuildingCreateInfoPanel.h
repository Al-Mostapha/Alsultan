#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/Building.Type.h"
#include "Base/Common/Common.Enum.h"
#include "UIBuildingCreateSingle.h"

class IBuilding;
class UICommonResourcesMenu;
class UICommonGoldNormalBtn;
struct RCostBuildingUpgrade;

struct RBuildCreateInfoInitData
{
  EBuilding _BuildId;
  RCostBuildingUpgrade _BuildData;
  struct {
    EBuildingPlace _BuildType;
    EBuildingIndex _BuildIndex;
  } _BuildType;
};
class UIBuildingCreateInfoPanel : public UIBasePanel
{

  CREATE_FUNC(UIBuildingCreateInfoPanel);
  CreateUIPanel(UIBuildingCreateInfoPanel);
  CreateUICCSView(UIBuildingCreateInfoPanel);

  float _FadeInDelay = 0.3f;
  bool _FirstRunWar = true;
  GString _LuckyBlessTimer;
  GString _WiseTutorTimer;
  bool _LuckyBlessIsOpen = false;
  bool _RadiantDecreeIsOpen = false;
  bool _WiseTutorIsOpen = false;
  bool _ArtisanHouseIsOpen = false;
  bool _IsShowFinger = false;
  bool _IsFree = false;
  bool _IsEnough = false;
  bool _IsSkip = false;
  bool _IsSpecialReach = false;
  EBuildingIndex _CurBuildingIndex;
  bool _IsFromCreate = false;
  bool _IsHidePrePanel = true;
  bool _HaveFreeMild = false;
  int32 _WarLvl = 0;
  int32 _WarToLvl = 0;
  int32 _WarCurPro = 0;
  // self.warTimer = nil
  int32 _NeedWarBadgeBuy = 0;
  int32 _NeedWarBadgeID = static_cast<int32>(EBadgeItemID::COMMON_BADGE_ID);
  float _SingleH = 0;
  EBuildingOperateType _ViewType = EBuildingOperateType::Build;
  UICommonResourcesMenu *_NodeRescources;
  int32 _BuildType = 0;
  ui::Text *_LabelDes;
  ui::Text *_LabelNextLvlValue;
  ui::Text *_LabelNextLvl;
  ui::Button *_BtnUnlocked;
  UICommonGoldNormalBtn *_BtnUpNow;
  ui::Button *_BtnUp;
  ui::Text *_LabelNeed;
  ui::ImageView *_ImageR;
  ui::ImageView *_ImageL;
  Node *_NodeNameBg;
  ui::Text *_LabelName;
  Node *_NodeNeedTime;
  ui::Text *_LabelUpTime;
  Node *_CenterNode;
  Node *_BottomNode;
  ui::ScrollView *_ScrollUp;
  ui::ImageView *_ImgLight;
  ui::ImageView *_ImgFlag;
  ui::ImageView *_ImgDesBg;
  ui::ImageView *_ImgTime;
  ui::ImageView *_ImgNameBg;
  ui::Text *_LabelLuckyDay;
  ui::Text *_LabelFreeTip;
  Node *_NodeWiseTutor;
  ui::Text *_TextWiseTime;
  ui::Button *_BtnWiseTutor;
  Node *_NodeArtisanHouse;
  ui::Text *_TextArtisanTime;
  ui::Button *_BtnArtisanTutor;
  ui::Button *_BtnHelp;
  Node *_NodeValue;
  ui::Text *_LabelCurLvlValue;
  Sprite *_IconWarCur;
  Sprite *_IconWarTo;
  ui::Text *_LabelWarPro;
  Node *_NodeWar;
  ui::ImageView *_ImgWarBg;
  Node *_NodeProgressBar;
  Node *_NodeEffect;
  ProgressTimer *_WarBarTo;
  ProgressTimer *_WarBarCur;
  Node *_EffectWar;
  Node *_RadiantNode;
  ui::Text *_RadiantTime;
  ui::Button *_RadiantBtn;

  ui::Layout *_NodeLeft;
  ui::Layout *_NodeTop;
  ui::Layout *_NodeBottom;

  Node *_SpritHand;

  static float WELevelProMin;
  static float WELevelProMax;
  static int32 CAN_BUILD ;
  static int32 CANT_BY_BUILD ;
  static int32 CANT_BY_BUILDER ;
  static int32 CANT_BY_RES ;
  static int32 CANT_BY_TOOL;
  static int32 NEED_BUY_BUILDER;

  struct {
    struct {
      EBuilding _Bid;
      EBuildingIndex _IID;
      IBuilding *_BuildEntity;
      int32 _UnlockedId;
    } _BuildId;
    RCostBuildingUpgrade _BuildData;
    struct {
      int32 _BuildIndex;
    } _BuildType;
    ELockedArea _AreaId;
  } _TableBuildInfo;

  GVector<UIBuildingCreateSingle *> _TableScrollSingles;
private:
  void UpgradeFun();
public: 
  static UIBuildingCreateInfoPanel* Create();
  void Ctor() override;
  void InitUpgradeData(IBuilding *p_Building);
  void InitBuildData(const RBuildCreateInfoInitData &pData);
  void InitWidget();
  void SuitView();
  void SetIsFromCreate(bool p_Val){ _IsFromCreate = p_Val;};
  void UpdateWiseTutorBuff();
  void UpdateArtisanHouseBuff();
  void UpdateView();
  void InitUpgradeView();
  void InitBuildView();
  void OnMessageListener();
  void OnWiseTutorClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void OnArtisanHouseClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnUpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnUpNowCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnUnlockedCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnHelpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  void BtnShowRadiantBuff(Ref *p_Sender, ui::Widget::TouchEventType p_Touch);
  Node *WarLvBarEffect(Node *p_Target);

  void ResUpdate(EventCustom *p_Event){}
  void CloseLoading(EventCustom *p_Event);
  void UpdateLuckyBless(EventCustom *p_Event = nullptr);
  void JudgeClose(EventCustom *p_Event){}
  void CloseByBuildLock(EventCustom *p_Event){}
  void UpdateBuff(EventCustom *p_Event);

  Node *AddRadiantDecreeBtn();
  void UpdateRadiantDecreeBuff();
  void OpenRadiantDecreeTime(float dt);
  void OpenLuckyTime(float p_Dt);
  void AdjustWiseArtisanBuffPos(){}
  void OpenWiseTutorTime(float p_Dt){}
  void SetBtnUpNowState();
  void SetBuildBtnTouchEnable(bool p_Enable){}
  void InitScroll();
  void SetSpecail();
  void InitUnlockView();
  void RunActClose();
  void InitWarView();
  void ShowUnlockedInfo();
  void InitUpgradeDes(bool p_UpDes, bool p_IsStar = false);
  void SetFlagSizeDes(float p_TotalHeight, GVector<Node *> p_Nodes);
  void InitUnlockData(ELockedArea p_Area);
  GPair<bool, int32> ScreenQueueList();
  void ScrollSingleCallBack(UIBuildingCreateSingle::RBuildingCondData &p_Data){}
  void ShowFingerClick(Vec2 p_Pos);
  void LightBlink(int32 p_Index);
  void ResBuyCallBack();


  void Build(EOperateMode p_Mode = EOperateMode::Normal);
  void BuildNow(EMsgBoxCallBack p_Call);
  void Upgrade(EOperateMode p_Mode = EOperateMode::Normal);
  void UpgradeNow(EMsgBoxCallBack p_Call);
  void ReloadScroll(bool p_Force){}

  void OnExitPanel() override;
};