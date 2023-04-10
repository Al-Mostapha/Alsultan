#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIMilitaryFortressMainView : public UIBasePanel
{

  CREATE_FUNC(UIMilitaryFortressMainView);
  CreateUIPanel(UIMilitaryFortressMainView);
  CreateUICCSView(UIMilitaryFortressMainView);
  
public: 
  static UIMilitaryFortressMainView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};