#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIBuildUpgradeStatueBrave : public UIBasePanel
{

  CREATE_FUNC(UIBuildUpgradeStatueBrave);
  CreateUIPanel(UIBuildUpgradeStatueBrave);
  CreateUICCSView(UIBuildUpgradeStatueBrave);

  
public: 
  static UIBuildUpgradeStatueBrave* Create();
  void Ctor() override;
  void InitUpgradeStarData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};