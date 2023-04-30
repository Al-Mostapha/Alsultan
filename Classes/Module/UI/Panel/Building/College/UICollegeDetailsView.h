#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeDetailsView : public UIBasePanel
{
  CREATE_FUNC(UICollegeDetailsView);
  CreateUIPanel(UICollegeDetailsView);
  CreateUICCSView(UICollegeDetailsView);
public: 
  static UICollegeDetailsView* Create();
  void Ctor() override;
  void InitData(EScienceID, EScienceType p_Type = EScienceType::None){}
};