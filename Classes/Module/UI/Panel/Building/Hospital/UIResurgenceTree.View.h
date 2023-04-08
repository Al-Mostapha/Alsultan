#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIResurgenceTreeView : public UIBasePanel
{

  CREATE_FUNC(UIResurgenceTreeView);
  CreateUIPanel(UIResurgenceTreeView);
  CreateUICCSView(UIResurgenceTreeView);

  
public: 
  static UIResurgenceTreeView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};