#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIBuildingInfoPanel : public UIBasePanel
{
  CREATE_FUNC(UIBuildingInfoPanel);
  CreateUIPanel(UIBuildingInfoPanel);
  CreateUICCSView(UIBuildingInfoPanel);
public: 
  static UIBuildingInfoPanel* Create();
  void Ctor() override;
  void InitData();
};