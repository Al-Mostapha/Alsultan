#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIIntetiorMainView : public UIBasePanel
{

  CREATE_FUNC(UIIntetiorMainView);
  CreateUIPanel(UIIntetiorMainView);
  CreateUICCSView(UIIntetiorMainView);
  
public: 
  static UIIntetiorMainView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};