#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Army/Army.Type.h"
#include "Module/Building/Building.Enum.h"
#include "Module/UI/MainUI/UICommonResourcesMenu.h"
#include "Module/UI/Part/Common/Button/UICommonGoldNormalBtn.h"
#include "Module/UI/Part/Common/Input/UICommonSlider.h"
#include "Module/UI/Part/Common/Box/UICommonProgressBar.h"
#include "UISoldierSkillSingle.h"


class IBuilding;
class ITask;
class UIWheelScrollView;
class UIBuildCreateResBuySingle;
class UISoldiersTrainScrollSingle;

class UISoldiersCampView : public UIBasePanel
{

  CREATE_FUNC(UISoldiersCampView);
  CreateUIPanel(UISoldiersCampView);
  CreateUICCSView(UISoldiersCampView);
public:
  bool _IsRun = true;
  UIWheelScrollView *_SelectWheel = nullptr;
  GVector<RCanTrainArmy> _TableSoldierList;
  struct RCurrentSoldierData {
    EBuilding _Bid = EBuilding::None;
    RCanTrainArmy _ArmyData;
    int32 _ArmyCount = 1;
    bool _NeedRes = false;
    bool _NeedElite = false;
    ETrainType _Type = ETrainType::None;
    EBuildingIndex _Index = EBuildingIndex::None;
  } _TableCurSoldier;
  IBuilding *_BuildEntity = nullptr;
  GVector<UIBuildCreateResBuySingle *> _TableResSingle;
  // self.trianQueue = nil
  ITask *_TrainQueue= nullptr;
  GString _Timer;
  GString _LuckyTimer;
  GString _LuckyBlessTimer;
  bool _LuckyBlessIsOpen = false;
  int32 _ResCostGold = 0;
  int32 _TrainGold = 0;  
  int32 _CurIndex;
  bool _NeedHiddleMainScene = false;
  bool _IsOpen = true;
  // self.tableSkill = {

  //   node = {}
  // }
  struct {
    GVector<UISoldierSkillSingle *> _Node;
    GVector<EArmySkill> _Data;
  } _TableSkill;

  struct RTrainSoldiersLog {
    EArmy _MaxArmyId = EArmy::None;
    EArmy _TrainArmyId = EArmy::None;
  };
  GHashMap<EBuilding, RTrainSoldiersLog> _TrainSoldiersLog;
  GVector<Node *> _TableLabelTitle;
  GVector<Node *> _TableLabelValues;
  GVector<Node *> _TableLabelAddValues;
  GVector<Node *> _TableLoadingBar;
  
  // self.needResList = {}
  GVector<Node *> _SoldierArray;
  Vec2 _SoldierOriPos;
  Node *_NodeCenter;
  Node *_NodeArmyBase;
  Node *_NodeStarArmy;
  ui::ImageView *_ImgSoldier;
  ui::Button *_BtnPromote;
  Node *_NodeEliteSoldier;
  Node *_NodeOwn;
  Node *_NodeHave;
  ui::Button *_BtnDissolve;
  bool _IsWarForbid;
  ui::Text *_LabelHave;
  Node *_NodeTrap;
  Node *_NodeTrapInfo;
  ui::Button *_BtnTrap;
  ui::Text *_LabelTrap;
  UICommonResourcesMenu *_NodeResources;
  ui::Text *_LabelLuckyDay;
  Node *_NodeElite;
  Node *_NodeEliteInfo;
  ui::Button *_BtnElite;
  ui::Text *_LabelElite;
  Node *_NodeBaseInfo;
  ui::Button *_BtnInfo;
  Node *_NodeAttack;
  ui::LoadingBar *_LoadingBarAttack;
  ui::Text *_TextAttack;
  ui::ImageView *_ImgLine;
  Node *_NodeTrain;
  Node *_NodeTrainInfo;
  UICommonSlider *_NodeSlider;
  UICommonGoldNormalBtn *_BtnTrainNow;
  Node *_NodeTrainBtn;
  ui::Button *_BtnTrain;
  Node *_NodeTrainTime;
  ui::Text *_LabelTrainTime;
  ui::Text *_LabelEliteNotice;
  Node *_NodeToolInfo;
  ui::Text *_LabelToolLeftTimes;
  ui::Text *_LabelToolAddValue;
  ui::Button *_BtnTip;
  ui::Button *_BtnTool;
  Node *_NodeUnTrain;
  ui::Button *_BtnJump;
  ui::Text *_LabelDes;
  Node *_NodeTrainQueue;
  ui::Text *_LabelName;
  UICommonGoldNormalBtn *_BtnSpeedUp;
  ui::Button *_BtnSpeedUpTool;
  ui::Text *_LabelSpeedUpTool;
  UICommonProgressBar *_NodeBar;
  ui::LoadingBar *_LoadingBarChild;
  ui::Text *_LabelSpeedUpTime;
  ui::Layout *_TipLayout;
  ui::Text *_LabelTip1;
  ui::Text *_LabelTip2;
  ui::Button *_BtnWear;
  Node *_NodeEffect;
  Node *_NodeSkill;
  Vec2 _TrapPos;
  Vec2 _TrapBasePos;
  int32 _SoundHandler = -1;

public: 
  static UISoldiersCampView* Create();
  void Ctor() override;
  void OnExitPanel() override;
  void InitData(EBuildingIndex p_Index, IBuilding *p_Building, ETrainType p_TrainType);
  void InitWidget();

  void BtnWearClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnEliteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnTrainClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnTrainNowClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnSpeedUpClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnSpeedUpToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnInfoClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnDissolveClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnTrapMsgClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnTipClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnPromoteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void BtnJumpClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type);
  void Close(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

  void ShowInfoNode();

  void SpeedUpCallBack(EMsgBoxCallBack p_CallBack);
  void SpeedUpToolCallBack(EMsgBoxCallBack p_CallBack);
  void CheckIsMaxSingleAdd(EOperateMode p_OperateMode);
  void TrainArmySent(EOperateMode p_OperateMode);

  void UpdateView( EventCustom *p_Event );
  void InitSlider( EventCustom *p_Event );
  void UpdateTrainNode( EventCustom *p_Event ){}
  void TrainNow( EventCustom *p_Event ){}
  void UpdateLuckyBless(EventCustom *p_Event = nullptr){}
  void UpdateToolTrainInfo(EventCustom *p_Event = nullptr){}
  void ResetWarframeSlider(EventCustom *p_Event = nullptr){}
  void UpdateData(EventCustom *p_Event = nullptr){}
  void UpdateArmyInfo(EventCustom *p_Event = nullptr){
    UpdateLabelHave();
    UpdatePromoteIcon();
  }

  void OnMsgSpeedUpBack(EventCustom *p_Event = nullptr){}
  void BuildQueueCallback(EventCustom *p_Event = nullptr){}

  void UpdateTip();
  void UpdateLabelHave();
  void InitSkill();
  void SetBaseInfo(){}
  void UpdatePromoteIcon();

  void TrainSoldierSlider(float p_Value);
  void InitResSingle();
  void IsTraining(bool p_IsTraining);
  void CreateWheelScrollView();
  void UpdateResSingleAlign(int32 l_ResCount);
  void WheelScrollBack(RCanTrainArmy p_Soldier);
  void SoldierEnterAct(Node *p_Target, float p_ToScale = 1,bool p_IsTrap = false);
  void UpdateSoldiersView(){}
  void UpdateTrapView(){}



  int32 GetMaxCampCount();
  void TrainImmediately();
  void ResBuyCallBack();
  void ShowResBuyView(){}
  void RemoveSelf();
  void AddTrapEffectByArmyType(EArmy p_ArmyId);
  void ScrollToChoose(int32 p_Index){
    _CurIndex = p_Index;
  }

};