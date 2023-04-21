#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonProgressBar : public UIBasePanel
{

  CREATE_FUNC(UICommonProgressBar);
  CreateUIPanel(UICommonProgressBar);
  CreateUICCSView(UICommonProgressBar);

  
public: 
  static UICommonProgressBar* Create();
  void Ctor() override ;
  void InitData(){}
};