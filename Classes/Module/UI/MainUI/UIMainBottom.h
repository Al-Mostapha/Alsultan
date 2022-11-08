#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIMainBottom : public UIPanelBase
{

private:
  CREATE_FUNC(UIMainBottom);
public:
  UIMainBottom(){};
  ~UIMainBottom(){};
  void InitPanel() override{};
  void Show() override {};
  static UIMainBottom *Create() {return create();};
};


