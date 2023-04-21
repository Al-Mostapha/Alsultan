#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"


class UISoldierSkillSingle : public UIBasePanel
{

  CREATE_FUNC(UISoldierSkillSingle);
  CreateUIPanel(UISoldierSkillSingle);
  CreateUICCSView(UISoldierSkillSingle);

  
public: 
  static UISoldierSkillSingle* Create();
  void Ctor() override;
};