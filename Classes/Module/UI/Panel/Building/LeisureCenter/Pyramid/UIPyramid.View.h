#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIPyramidView : public UIBasePanel
{

  CREATE_FUNC(UIPyramidView);
  CreateUIPanel(UIPyramidView);
  CreateUICCSView(UIPyramidView);

  
public: 
  static UIPyramidView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};