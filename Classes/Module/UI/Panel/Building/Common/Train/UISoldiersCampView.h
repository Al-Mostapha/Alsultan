#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"
#include "Module/UI/MainUI/UICommonResourcesMenu.h"
#include "Module/UI/Part/Common/Button/UICommonGoldNormalBtn.h"
#include "Module/UI/Part/Common/Input/UICommonSlider.h"
#include "Module/UI/Part/Common/Box/UICommonProgressBar.h"
#include "UISoldierSkillSingle.h"

class IBuilding;
class UISoldiersCampView : public UIBasePanel
{

  CREATE_FUNC(UISoldiersCampView);
  CreateUIPanel(UISoldiersCampView);
  CreateUICCSView(UISoldiersCampView);

  bool _IsRun = true;
  // self.selectWheel = nil
  // self.tableSoldierList = {}
  // self.tableCurSoldier = {
  //   bid = 0,
  //   armyData = {},
  //   armyCount = 1,
  //   needRes = false,
  //   needElite = false,
  //   type = 1,
  //   index = 0
  // }
  // self.tableResSingle = {}
  // self.trianQueue = nil
  Scheduler *_Timer = nullptr;
  Scheduler *_LuckyTimer = nullptr;
  Scheduler *_LuckyBlessTimer = nullptr;
  bool _LuckyBlessIsOpen = false;
  int32 _ResCostGold = 0;
  int32 _TrainGold = 0;
  // self.curIndex = nil
  bool _NeedHiddleMainScene = false;
  bool _IsOpen = true;
  // self.tableSkill = {

  //   node = {}
  // }
  struct {
    GVector<UISoldierSkillSingle *> _Node;
      //   data = {},
  } _TableSkill;
  // self.tableLabelTitle = {}
  GVector<Node *> _TableLabelTitle;
  GVector<Node *> _TableLabelValues;
  // self.tableLabelValues = {}
  GVector<Node *> _TableLabelAddValues;
  // self.tableLabeladdValues = {}
  // self.tableLoadingBar = {}
  GVector<Node *> _TableLoadingBar;
  
  // self.needResList = {}
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
  Node *_NodeSkill;
  Vec2 _TrapPos;
  Vec2 _TrapBasePos;
  
public: 
  static UISoldiersCampView* Create();
  void Ctor() override;
  void InitData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();

  void BtnWearClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnEliteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnTrainClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnTrainNowClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnSpeedUpClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnSpeedUpToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnInfoClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnDissolveClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnTrapMsgClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnTipClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnPromoteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}
  void BtnJumpClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){}

  void UpdateLuckyBless(){}
  void TrainSoldierSlider(float p_Value){}
};