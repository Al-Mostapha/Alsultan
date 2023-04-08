#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UILifeSpringsView : public UIBasePanel
{

  CREATE_FUNC(UILifeSpringsView);
  CreateUIPanel(UILifeSpringsView);
  CreateUICCSView(UILifeSpringsView);

  
public: 
  static UILifeSpringsView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};