#pragma once

#include "Module/UI/UICCSView.h"

class UIAllianceJoinView : public UIBaseView
{
  CREATE_FUNC(UIAllianceJoinView);
  CreateUIPanel(UIAllianceJoinView);
  CreateUICCSView(UIAllianceJoinView);
public:
  static UIAllianceJoinView *Create();
  void Show();
};