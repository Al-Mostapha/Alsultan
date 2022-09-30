#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingLogic{
private:
  static GPair<bool, GVector<struct RCostBuildingEnough>> isCostBuildingAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static GPair<bool, GVector<struct RCostItemEnough>> isCostWsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static GPair<bool, GVector<struct RCostItemEnough>> isCostItemsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static GPair<bool, struct RCostBuildingEnough> isCostResourceAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);

public:
  static bool isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurentLvl);
  static GPair<bool, RCostBuildingUpgrade> isBuildingCostAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, RBuildingLvlSpecs &p_BuildingLvlSpecs);
};