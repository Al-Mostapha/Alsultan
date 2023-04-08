#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UITreasureHuntView : public UIBasePanel
{

  CREATE_FUNC(UITreasureHuntView);
  CreateUIPanel(UITreasureHuntView);
  CreateUICCSView(UITreasureHuntView);

  
public: 
  static UITreasureHuntView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};