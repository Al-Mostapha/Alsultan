#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIHospitalView : public UIBasePanel
{

  CREATE_FUNC(UIHospitalView);
  CreateUIPanel(UIHospitalView);
  CreateUICCSView(UIHospitalView);

  
public: 
  static UIHospitalView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};