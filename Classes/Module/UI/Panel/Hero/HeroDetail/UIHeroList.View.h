#pragma once
#include "Module/UI/UICCSView.h"

class UIHeroListView : public UIBaseView
{
  CREATE_FUNC(UIHeroListView);
  CreateUICCSView(UIHeroListView);
  CreateUIPanel(UIHeroListView);
public:
  static UIHeroListView *Create();  
  void Show();
};