#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIGameOptionsView : public UIPanelBase
{

private:
  CREATE_FUNC(UIGameOptionsView);
public:
  UIGameOptionsView(){};
  ~UIGameOptionsView(){};
  void InitPanel() override{};
  void Show() override {};
  static UIGameOptionsView *Create() {return create();};
  void JumpByName(const char *p_Name){}
};


