#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIDefendView : public UIBasePanel
{

  CREATE_FUNC(UIDefendView);
  CreateUIPanel(UIDefendView);
  CreateUICCSView(UIDefendView);

  
public: 
  static UIDefendView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};