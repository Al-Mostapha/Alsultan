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
  RRechargeAD m_IsADShow;
  bool m_IsHaveTextField = false;
  bool m_IsHideCurrentSceneView = false;
  bool m_IsHidePrePanel = true;
  int32 m_ShowPanelPowerValue = 1;
  float m_FadeInDelay = 0.0f;
  Node *m_ScaleActTarget = nullptr;
  bool m_NeedCallBack2SDK = false;
  bool m_IsAddToPopManager = false;
  bool m_IsCantCloseByReturn = false;
  ui::Button *m_CloseButton = nullptr;
  UIBaseView *m_Panel;
  CREATE_FUNC(UIBasePanel);
public: 
  UIBasePanel* InitPanel(GString p_CCsFile, RBasePenelData *p_Data = nullptr);
  UIBasePanel* InitPanel(Node *p_CCsFile, RBasePenelData *p_Data = nullptr);
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
  virtual GString GetViewName() {return m_Panel ?  m_Panel->getName() : "";}
};