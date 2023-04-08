#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"
#include "UIBuildingCreateInfoPanel.h"

class IBuilding;
class UIBuildingStarUpgradePanel : public UIBuildingCreateInfoPanel
{

  CREATE_FUNC(UIBuildingStarUpgradePanel);
  CreateUIPanel(UIBuildingStarUpgradePanel);
  CreateUICCSView(UIBuildingStarUpgradePanel);

  
public: 
  static UIBuildingStarUpgradePanel* Create();
  void Ctor() override;
  void InitUpgradeStarData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};