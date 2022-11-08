#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonGoldTop : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonGoldTop);
public:
  UICommonGoldTop(){};
  ~UICommonGoldTop(){};
  void InitPanel() override{};
  void Show() override {};
  static UICommonGoldTop *Create() {return create();};
  void SetMainUIStyle();
  void ShowAnimation();
};
