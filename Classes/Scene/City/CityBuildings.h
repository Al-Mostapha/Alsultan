#pragma once
#include "CityCommon.h"
class CityBuildings : public CityCommon {
  
  public:
  Node *_CurrentSelectBuild;
  class UIBuildingTipPanel *_CacheTip = nullptr;
  class UIBuildingTipPanel *_CurrentSelectTip; 
  bool _IsNeedRecover = false;
  void ShowBuildTint();
  virtual void BuildingButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch);
};