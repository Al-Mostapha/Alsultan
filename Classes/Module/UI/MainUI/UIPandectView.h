#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIPandectView : public UIPanelBase
{

private:
  CREATE_FUNC(UIPandectView);
public:
  UIPandectView(){};
  ~UIPandectView(){};
  void InitPanel() override{};
  void Show() override {};
  static UIPandectView *Create() {return create();};
};


