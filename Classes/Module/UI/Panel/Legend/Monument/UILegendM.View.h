#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UILegendMView : public UIBasePanel
{

  CREATE_FUNC(UILegendMView);
  CreateUIPanel(UILegendMView);
  CreateUICCSView(UILegendMView);

  
public: 
  static UILegendMView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};