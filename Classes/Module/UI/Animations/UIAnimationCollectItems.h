#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UIAnimationCollectItems : public UIPanelBase
{

private:
  CREATE_FUNC(UIAnimationCollectItems);
public:
  UIAnimationCollectItems(){};
  ~UIAnimationCollectItems(){};
  void InitPanel() override{};
  void Show() override {};
  static UIAnimationCollectItems *Create() {return create();};
};
