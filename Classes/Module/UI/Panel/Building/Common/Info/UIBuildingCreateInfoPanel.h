#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIBuildingCreateInfoPanel : public UIBasePanel
{

  CREATE_FUNC(UIBuildingCreateInfoPanel);
  CreateUIPanel(UIBuildingCreateInfoPanel);
  CreateUICCSView(UIBuildingCreateInfoPanel);

  
public: 
  static UIBuildingCreateInfoPanel* Create();
  void Ctor() override;
  void InitUpgradeData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};