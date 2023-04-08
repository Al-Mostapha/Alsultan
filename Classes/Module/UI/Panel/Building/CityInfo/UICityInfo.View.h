#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICityInfoView : public UIBasePanel
{

  CREATE_FUNC(UICityInfoView);
  CreateUIPanel(UICityInfoView);
  CreateUICCSView(UICityInfoView);

  
public: 
  static UICityInfoView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};