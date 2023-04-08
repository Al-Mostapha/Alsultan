#pragma once
#include "Include/IncludeBase.h"
#include "UIBaseView.h"
#include "UICCSView.h"
#include "Module/Config/ConfigRead/RechargeADRead.h"
#include "View/Recharge/UIRechargeTinyPageNode.h"
#include "Module/Translation/Translate.h"


class UIRechargeTinyPageNode;
struct RBasePenelData{
  GString FutureName;
};

class UIBasePanel : public UIBaseView
{
public:
  RRechargeAD _IsADShow;
  bool _IsHaveTextField = false;
  bool _IsHideCurrentSceneView = false;
  bool _IsHidePrePanel = true;
  int32 _ShowPanelPowerValue = 1;
  float _FadeInDelay = 0.0f;
  Node *_ScaleActTarget = nullptr;
  bool _NeedCallBack2SDK = false;
  bool _IsAddToPopManager = false;
  bool _IsCantCloseByReturn = false;
  ui::Button *_CloseButton = nullptr;
  UIBaseView *_Panel;
public: 
  UIBasePanel* InitPanel(GString p_CCsFile, RBasePenelData *p_Data = nullptr);
  UIBasePanel* InitPanel(Node *p_CCsFile, RBasePenelData *p_Data = nullptr);
  static UIBasePanel* create(){return nullptr;}
  static UIBasePanel* Create(GString p_CCsFile, RBasePenelData *p_Data = nullptr);
  virtual void Ctor();
  void DeviceFitOffset();
  void BindBtnClose();
  void ClosePanel();
  void CloseKeyBoard();
  void PanelFadeIn();
  void PanelScaleAct();
  void PanelScaleActBack();
  UIRechargeTinyPageNode *AddRechargeADNode(Node *p_Node);
  bool JudgeShowPanelPower();
  UIBasePanel *Show(Node *p_Parent = nullptr, int32 p_ZOrder = 1);  
  Node *GameGuide_getTarget(GString p_Name);

  void onExit() override;

  virtual void EndShow(){}
  virtual void OnEnterPanel(){}
  virtual void OnExitPanel(){}
  virtual void OnEnterOther(){OnEnterPanel();}
  virtual void AddSubViews(){};
  virtual GString GetViewName() {return _Panel ?  _Panel->getName() : "";}
};