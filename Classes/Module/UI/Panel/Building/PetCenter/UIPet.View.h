#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIPetView : public UIBasePanel
{

  CREATE_FUNC(UIPetView);
  CreateUIPanel(UIPetView);
  CreateUICCSView(UIPetView);
  
public: 
  static UIPetView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};