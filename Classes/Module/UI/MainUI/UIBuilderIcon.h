#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIBuilderIcon : public UIPanelBase
{

private:
  CREATE_FUNC(UIBuilderIcon);
public:
  UIBuilderIcon(){};
  ~UIBuilderIcon(){};
  void InitPanel() override{};
  void Show() override {};
  static UIBuilderIcon *Create() {return create();};
};
