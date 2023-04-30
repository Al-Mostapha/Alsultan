#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeScrollSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeScrollSingle);
  CreateUIPanel(UICollegeScrollSingle);
  CreateUICCSView(UICollegeScrollSingle);
public: 
  static UICollegeScrollSingle* Create();
  void Ctor() override;
  void InitData(EScienceID p_TechId, EScienceType p_TechType = EScienceType::None){};
  void HideName(){}
  void HideNameLv(){}
  void SetTimeVisble(bool){}
};