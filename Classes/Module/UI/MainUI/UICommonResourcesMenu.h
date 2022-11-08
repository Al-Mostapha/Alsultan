#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonResourcesMenu : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonResourcesMenu);
public:
  UICommonResourcesMenu(){};
  ~UICommonResourcesMenu(){};
  void InitPanel() override{};
  void Show() override {};
  static UICommonResourcesMenu *Create() {return create();};
  void RunAnimation();
  void HiddleMainUI(bool p_IsHiddle = false);
};
