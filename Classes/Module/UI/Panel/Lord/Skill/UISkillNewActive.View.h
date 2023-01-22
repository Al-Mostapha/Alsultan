#pragma once
#include "Module/UI/UICCSView.h"

class UISkillNewActiveView : UIBaseView{
  CREATE_FUNC(UISkillNewActiveView)
  CreateUICCSView(UISkillNewActiveView)
  CreateUIPanel(UISkillNewActiveView)
public:
  static UISkillNewActiveView *Create();
  void Show();
};