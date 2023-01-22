#pragma once
#include "Module/UI/UICCSView.h"

class UISultansBackWelBackView : UIBaseView{
  CREATE_FUNC(UISultansBackWelBackView);
  CreateUIPanel(UISultansBackWelBackView);
  CreateUICCSView(UISultansBackWelBackView);
public: 
  static UISultansBackWelBackView* Create();
  void Show();
};