#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeDetailsSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeDetailsSingle);
  CreateUIPanel(UICollegeDetailsSingle);
  CreateUICCSView(UICollegeDetailsSingle);
public: 
  static UICollegeDetailsSingle* Create();
  void Ctor() override;
  void InitData(EScience, EScienceType p_Type = EScienceType::None){}
};