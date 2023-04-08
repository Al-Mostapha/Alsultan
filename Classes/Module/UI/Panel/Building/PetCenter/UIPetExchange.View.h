#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIPetExchangeView : public UIBasePanel
{

  CREATE_FUNC(UIPetExchangeView);
  CreateUIPanel(UIPetExchangeView);
  CreateUICCSView(UIPetExchangeView);
  
public: 
  static UIPetExchangeView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};