#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UILordPowerView : public UIPanelBase
{

private:
  CREATE_FUNC(UILordPowerView);
public:
  UILordPowerView(){};
  ~UILordPowerView(){};
  void InitPanel() override{};
  void Show() override {};
  static UILordPowerView *Create() {return create();};
};
