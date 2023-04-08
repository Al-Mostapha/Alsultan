#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAllianceCounterSysView : public UIBasePanel
{

  CREATE_FUNC(UIAllianceCounterSysView);
  CreateUIPanel(UIAllianceCounterSysView);
  CreateUICCSView(UIAllianceCounterSysView);
  
public: 
  static UIAllianceCounterSysView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};