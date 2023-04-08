#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICityBuffView : public UIBasePanel
{

  CREATE_FUNC(UICityBuffView);
  CreateUIPanel(UICityBuffView);
  CreateUICCSView(UICityBuffView);

  
public: 
  static UICityBuffView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};