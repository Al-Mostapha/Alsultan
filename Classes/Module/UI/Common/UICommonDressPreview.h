#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"
#include "Module/UI/Panel/UIPanelBase.h"


class UICommonDressPreview : public UIPanelBase
{

private:
  CREATE_FUNC(UICommonDressPreview);
public:
  UICommonDressPreview(){};
  ~UICommonDressPreview(){};
  void InitPanel() override{};
  void Show() override {};
  void InitData(uint32 p_IdItem) {};
  static UICommonDressPreview *Create() {return create();};
};
