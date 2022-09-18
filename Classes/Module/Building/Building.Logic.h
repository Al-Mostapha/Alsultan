#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingLogic{
private:
  static bool isCostBuildingAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static bool isCostWsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static bool isCostItemsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static bool isCostResourceAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl);

public:
  static bool isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurentLvl);
  static bool isBuildingCostAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, RBuildingLvlSpecs &p_BuildingLvlSpecs);
};