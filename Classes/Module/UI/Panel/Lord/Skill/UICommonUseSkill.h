#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Module/Player/Skill/LordSkill.Enum.h"


class UICommonUseSkill: public UIPanelBase
{

private:
  CREATE_FUNC(UICommonUseSkill);
public:
  UICommonUseSkill(){};
  ~UICommonUseSkill(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(ELordSkill p_Skill){};
  static UICommonUseSkill *Create() {return create();};
};


