#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UINewTradeBoardView : public UIBasePanel
{

  CREATE_FUNC(UINewTradeBoardView);
  CreateUIPanel(UINewTradeBoardView);
  CreateUICCSView(UINewTradeBoardView);

  
public: 
  static UINewTradeBoardView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};