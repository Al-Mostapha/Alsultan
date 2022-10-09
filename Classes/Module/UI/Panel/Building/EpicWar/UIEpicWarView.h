#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UIEpicWarView : public UIPanelBase
{

private:

public:
  UIEpicWarView(){};
  ~UIEpicWarView(){};
  void InitPanel() override{};
  void Show() {};
  static UIEpicWarView *Create() {return create();};
  CREATE_FUNC(UIEpicWarView);

};


