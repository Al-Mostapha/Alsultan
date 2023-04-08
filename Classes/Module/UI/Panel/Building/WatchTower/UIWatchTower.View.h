#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWatchTowerView : public UIBasePanel
{

  CREATE_FUNC(UIWatchTowerView);
  CreateUIPanel(UIWatchTowerView);
  CreateUICCSView(UIWatchTowerView);

  
public: 
  static UIWatchTowerView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};