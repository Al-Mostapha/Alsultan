#pragma once
#include "Module/UI/UICCSView.h"

class UIBagView : public UIBaseView
{
  CREATE_FUNC(UIBagView);
  CreateUICCSView(UIBagView);
  CreateUIPanel(UIBagView);
  public:
    static UIBagView* Create();
    void Show();
};