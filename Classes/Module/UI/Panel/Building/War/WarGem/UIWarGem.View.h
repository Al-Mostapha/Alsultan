#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWarGemView : public UIBasePanel
{

  CREATE_FUNC(UIWarGemView);
  CreateUIPanel(UIWarGemView);
  CreateUICCSView(UIWarGemView);
  
public: 
  static UIWarGemView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};