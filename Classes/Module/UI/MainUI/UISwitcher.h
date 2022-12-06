#pragma once
#include "Module/UI/UICCSView.h"

class UISwitcher : public UIBaseView
{
  CREATE_FUNC(UISwitcher);
  CreateUIPanel(UISwitcher);
  CreateUICCSView(UISwitcher);
public: 
  static UISwitcher* Create();
  void CloseSwitcher();
};