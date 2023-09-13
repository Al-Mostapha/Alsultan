#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldKingdomLvView : public UIBasePanel
{

  CREATE_FUNC(UIWorldKingdomLvView);
  CreateUIPanel(UIWorldKingdomLvView);
  CreateUICCSView(UIWorldKingdomLvView);

  
public: 
  static UIWorldKingdomLvView *Create();
  void Ctor() override;
};