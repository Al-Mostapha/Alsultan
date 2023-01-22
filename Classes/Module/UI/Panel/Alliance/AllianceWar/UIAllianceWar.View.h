#pragma once
#include "Module/UI/UICCSView.h"

class UIAllianceWarView : public UIBaseView
{
CREATE_FUNC(UIAllianceWarView);
CreateUIPanel(UIAllianceWarView);
CreateUICCSView(UIAllianceWarView);
public:
  static UIAllianceWarView *Create();
  void Show();
  void InitPanel();
};