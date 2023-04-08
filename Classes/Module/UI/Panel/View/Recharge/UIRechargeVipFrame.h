#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIRechargeVipFrame : public UIBasePanel
{

  CREATE_FUNC(UIRechargeVipFrame);
  CreateUIPanel(UIRechargeVipFrame);
  CreateUICCSView(UIRechargeVipFrame);

  
public: 
  static UIRechargeVipFrame* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};