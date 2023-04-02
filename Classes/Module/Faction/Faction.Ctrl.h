#pragma once 
#include "Include/IncludeBase.h"
#include "Module/Building/BuildingTips/BuildingTips.Type.h"

class FactionCtrl{
  public: 
  static FactionCtrl *Get();
  RBuildingTipsBtnListData getCityBuildTipsInfo(EBuilding p_Building);
  RBuildingTipsBtnListData GetCityBuildBaseTipsCfg(EBuilding p_Building);
  RBuildingTipConfig GetBuildTipButtonCfgById(EBuildingTips p_Tip);
};