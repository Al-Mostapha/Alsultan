#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonPromptBox : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonPromptBox);
public:
  UICommonPromptBox(){};
  ~UICommonPromptBox(){};
  void InitPanel() override{};
  void Show() override {};
  static UICommonPromptBox *Create() {return create();};
};
