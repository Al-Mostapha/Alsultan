#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingLogic{
private:
  static bool isBuildingLvlPreCondAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, TBuildingLvlSpecs &p_BuildingLvlSpecs);
  static bool isBuildingLvlCostWsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, TBuildingLvlSpecs &p_BuildingLvlSpecs);
  static bool isBuildingLvlCostItemsAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, TBuildingLvlSpecs &p_BuildingLvlSpecs);

public:
  static bool isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurentLvl);
  static bool isBuildingLvlReqAchieved(EBuildingType p_BuildingType, uint32 p_CurrentLvl, TBuildingLvlSpecs &p_BuildingLvlSpecs);
};