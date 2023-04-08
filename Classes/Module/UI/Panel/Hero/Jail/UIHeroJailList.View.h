#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIHeroJailListView : public UIBasePanel
{

  CREATE_FUNC(UIHeroJailListView);
  CreateUIPanel(UIHeroJailListView);
  CreateUICCSView(UIHeroJailListView);

  
public: 
  static UIHeroJailListView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};