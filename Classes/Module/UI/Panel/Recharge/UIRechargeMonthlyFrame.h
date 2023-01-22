#pragma once
#include "Module/UI/UICCSView.h"

class UIRechargeMonthlyFrame : public UIBaseView
{
  CREATE_FUNC(UIRechargeMonthlyFrame);
  CreateUIPanel(UIRechargeMonthlyFrame);
  CreateUICCSView(UIRechargeMonthlyFrame);
public: 
  static UIRechargeMonthlyFrame* Create();
  void Show();
};