#pragma once 
#include "Include/IncludeBase.h"
#include "Module/Building/BuildingTips/BuildingTips.Type.h"

class FactionCtrl{
  public: 
  static FactionCtrl *Get();
  RBuildingTipsBtnListData GetCityBuildBaseTipsCfg(EBuilding p_Building);
};