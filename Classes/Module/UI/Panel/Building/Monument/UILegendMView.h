#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UILegendMView : public UIPanelBase
{

private:

public:
  UILegendMView(){};
  ~UILegendMView(){};
  void InitPanel() override{};
  void Show() {};
  static UILegendMView *Create() {return create();};
  CREATE_FUNC(UILegendMView);

};


