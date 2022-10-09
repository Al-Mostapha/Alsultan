#pragma once
#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"
#include "Include/IncludeBuildingBase.h"


class UIAllianceWarView : public UIPanelBase
{

private:

public:
  UIAllianceWarView(){};
  ~UIAllianceWarView(){};
  void InitPanel() override{};
  void Show() {};
  static UIAllianceWarView *Create() {return create();};
  CREATE_FUNC(UIAllianceWarView);

};


