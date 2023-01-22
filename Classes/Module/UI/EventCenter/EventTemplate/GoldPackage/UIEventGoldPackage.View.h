#pragma once
#include "Module/UI/UICCSView.h"

class UIEventGoldPackageView : UIBaseView{
  CREATE_FUNC(UIEventGoldPackageView);
  CreateUIPanel(UIEventGoldPackageView);
  CreateUICCSView(UIEventGoldPackageView);
public: 
  static UIEventGoldPackageView* Create();
  void Show();
};