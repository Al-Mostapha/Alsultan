#pragma once
#include "Module/UI/UICCSView.h"

class UIAllianceMainView : public UIBaseView
{
  CREATE_FUNC(UIAllianceMainView);
  CreateUIPanel(UIAllianceMainView);
  CreateUICCSView(UIAllianceMainView);
public:
  static UIAllianceMainView* Create();
  void Show();
};