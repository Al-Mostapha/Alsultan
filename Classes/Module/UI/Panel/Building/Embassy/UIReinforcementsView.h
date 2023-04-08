#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIReinforcementsView : public UIBasePanel
{

  CREATE_FUNC(UIReinforcementsView);
  CreateUIPanel(UIReinforcementsView);
  CreateUICCSView(UIReinforcementsView);

  
public: 
  static UIReinforcementsView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};