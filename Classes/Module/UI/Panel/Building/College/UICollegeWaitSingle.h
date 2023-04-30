#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Science/Science.Enum.h"

class UICollegeWaitSingle : public UIBasePanel
{
  CREATE_FUNC(UICollegeWaitSingle);
  CreateUIPanel(UICollegeWaitSingle);
  CreateUICCSView(UICollegeWaitSingle);
public: 
  static UICollegeWaitSingle* Create();
  void Ctor() override;
  void InitData(EScienceID){}
  void SetStateFree(){}
};