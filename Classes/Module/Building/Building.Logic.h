#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Base/Containers/Pair.h"

class BuildingLogic{
private:
  bool IsBuildingCostAchieved(const RCostBuildingUpgrade &p_CostUpgrade);
public:
  static BuildingLogic *Get();
  GPair<bool, RCostBuildingUpgrade> IsCanUpgrade(EBuilding p_BuildingType, uint32 p_CurentLvl);
  GPair<bool, RCostBuildingUpgrade> IsCanBuild(EBuilding p_BuildingType);
  int32 IsWarLvl(uint32 p_BuildingLvl) { return false; }
  bool IsShowUpgrade(EBuildingIndex p_BuildingIndex){ return true; }
  ITask *GetQueueType(EBuildingIndex p_BuildingIndex);
};