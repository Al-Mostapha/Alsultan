#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonItemShowBox : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonItemShowBox);
public:
  UICommonItemShowBox(){};
  ~UICommonItemShowBox(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(uint32 p_IdItem) {};
  static UICommonItemShowBox *Create() {return create();};
};
