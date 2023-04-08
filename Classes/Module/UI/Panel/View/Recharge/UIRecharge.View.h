#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIRechargeView : public UIBasePanel
{

  CREATE_FUNC(UIRechargeView);
  CreateUIPanel(UIRechargeView);
  CreateUICCSView(UIRechargeView);

  
public: 
  static UIRechargeView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};