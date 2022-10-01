#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Base/Containers/Pair.h"

class BuildingLogic{
private:
  bool IsBuildingCostAchieved(const RCostBuildingUpgrade &p_CostUpgrade);
public:
  static BuildingLogic *Get();
  GPair<bool, RCostBuildingUpgrade> IsCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurentLvl);
  GPair<bool, RCostBuildingUpgrade> IsCanBuild(EBuildingType p_BuildingType);
};