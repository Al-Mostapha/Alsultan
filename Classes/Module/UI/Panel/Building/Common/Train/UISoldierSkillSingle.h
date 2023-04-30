#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/Army/Army.Enum.h"


class UISoldierSkillSingle : public UIBasePanel
{

  CREATE_FUNC(UISoldierSkillSingle);
  CreateUIPanel(UISoldierSkillSingle);
  CreateUICCSView(UISoldierSkillSingle);

  
public: 
  static UISoldierSkillSingle* Create();
  void InitData(EArmySkill){}
  void Ctor() override;
};