#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapTipButton : public UIBaseView
{

  CREATE_FUNC(UIWorldMapTipButton);
  CreateUIPanel(UIWorldMapTipButton);
  CreateUICCSView(UIWorldMapTipButton);

  
public: 
  static UIWorldMapTipButton* Create();
  void Ctor() override;
};