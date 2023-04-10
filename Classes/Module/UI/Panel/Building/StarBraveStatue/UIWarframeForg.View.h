#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWarframeForgView : public UIBasePanel
{

  CREATE_FUNC(UIWarframeForgView);
  CreateUIPanel(UIWarframeForgView);
  CreateUICCSView(UIWarframeForgView);
  
public: 
  static UIWarframeForgView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};