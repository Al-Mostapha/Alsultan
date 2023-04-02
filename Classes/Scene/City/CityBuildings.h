#pragma once
#include "CityCommon.h"
class CityBuildings : public CityCommon {
  class UIBuildingTipPanel *_CurrentSelectTip; 
  public:
  void ShowBuildTint();
  virtual void BuildingButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch);
};