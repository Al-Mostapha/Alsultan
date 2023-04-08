#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWarTechView : public UIBasePanel
{

  CREATE_FUNC(UIWarTechView);
  CreateUIPanel(UIWarTechView);
  CreateUICCSView(UIWarTechView);
  
public: 
  static UIWarTechView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};