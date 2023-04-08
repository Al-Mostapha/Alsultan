#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIMilitaryRankSkillView : public UIBasePanel
{

  CREATE_FUNC(UIMilitaryRankSkillView);
  CreateUIPanel(UIMilitaryRankSkillView);
  CreateUICCSView(UIMilitaryRankSkillView);
  
public: 
  static UIMilitaryRankSkillView* Create();
  void Ctor() override;
  void InitData();
  void SwitchScroll(bool p_Switch);
  void InitWidget();
};