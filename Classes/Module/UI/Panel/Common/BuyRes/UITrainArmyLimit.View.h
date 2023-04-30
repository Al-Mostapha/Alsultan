#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Item/Item.Enum.h"

class UITrainArmyLimitView : public UIBasePanel
{

  CREATE_FUNC(UITrainArmyLimitView);
  CreateUIPanel(UITrainArmyLimitView);
  CreateUICCSView(UITrainArmyLimitView);
  
public: 
  static UITrainArmyLimitView* Create();
  void Ctor() override{}
  void InitData(EItemType){}
};