#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeScrollView : public UIBasePanel
{
  CREATE_FUNC(UICollegeScrollView);
  CreateUIPanel(UICollegeScrollView);
  CreateUICCSView(UICollegeScrollView);
public: 
  static UICollegeScrollView* Create(const char *p_FileName);
  void Ctor() override;
  void InitData(EScienceID){}
  void SetStateFree(){}
};