#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonSpeedUpBox : public UIBasePanel
{

  CREATE_FUNC(UICommonSpeedUpBox);
  CreateUIPanel(UICommonSpeedUpBox);
  CreateUICCSView(UICommonSpeedUpBox);
  
public: 
  static UICommonSpeedUpBox* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};