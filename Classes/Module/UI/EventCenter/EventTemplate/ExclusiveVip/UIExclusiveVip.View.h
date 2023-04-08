#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UIExclusiveVipView : public UIBasePanel
{

  CREATE_FUNC(UIExclusiveVipView);
  CreateUIPanel(UIExclusiveVipView);
  CreateUICCSView(UIExclusiveVipView);

  
public: 
  static UIExclusiveVipView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};