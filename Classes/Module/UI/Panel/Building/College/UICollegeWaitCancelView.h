#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeWaitCancelView : public UIBasePanel
{
  CREATE_FUNC(UICollegeWaitCancelView);
  CreateUIPanel(UICollegeWaitCancelView);
  CreateUICCSView(UICollegeWaitCancelView);
public: 
  static UICollegeWaitCancelView* Create();
  void Ctor() override;
  void InitData(EScience){}
  void SetStateFree(){}
};