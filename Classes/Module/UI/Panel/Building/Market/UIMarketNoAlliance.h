#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIMarketNoAlliance : public UIBasePanel
{

  CREATE_FUNC(UIMarketNoAlliance);
  CreateUIPanel(UIMarketNoAlliance);
  CreateUICCSView(UIMarketNoAlliance);

  
public: 
  static UIMarketNoAlliance* Create();
  void Ctor() override;
  void InitData(EBuildingIndex p_Index, IBuilding *p_Building);
  void InitWidget();
};