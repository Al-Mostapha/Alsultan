#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonSpeedUpByItemBox : public UIBasePanel
{

  CREATE_FUNC(UICommonSpeedUpByItemBox);
  CreateUIPanel(UICommonSpeedUpByItemBox);
  CreateUICCSView(UICommonSpeedUpByItemBox);
  
public: 
  static UICommonSpeedUpByItemBox* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};