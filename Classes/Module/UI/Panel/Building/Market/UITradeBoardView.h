#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Building/Building.Enum.h"

class IBuilding;
class UITradeBoardView : public UIBasePanel
{

  CREATE_FUNC(UITradeBoardView);
  CreateUIPanel(UITradeBoardView);
  CreateUICCSView(UITradeBoardView);

  
public: 
  static UITradeBoardView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};