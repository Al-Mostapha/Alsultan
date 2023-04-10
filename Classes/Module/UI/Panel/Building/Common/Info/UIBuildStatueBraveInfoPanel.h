#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIBuildStatueBraveInfoPanel : public UIBasePanel
{

  CREATE_FUNC(UIBuildStatueBraveInfoPanel);
  CreateUIPanel(UIBuildStatueBraveInfoPanel);
  CreateUICCSView(UIBuildStatueBraveInfoPanel);

  
public: 
  static UIBuildStatueBraveInfoPanel* Create();
  void Ctor() override;
  void InitUpgradeStarData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};