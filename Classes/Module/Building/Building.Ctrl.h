#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingCtrl {
public:
  static uint32 getBuildingMaxLvl(EBuildingType p_BuildingType);
  static uint32 getBuildingCount(EBuildingType p_BuildingType);
  static class CityBuildingBase *getBuildingCell(EBuildingType p_BuildingType);
  static GVector<TBuildingPreCond> checkBuildingPreCond(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static TResource checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
};