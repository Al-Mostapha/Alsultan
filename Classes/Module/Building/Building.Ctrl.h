#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingCtrl {
private:
  static void getReducedCostTime(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostItem(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostResource(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostScience(RBuildingLvlSpecs &p_OriginalSpec);

public:
  BuildingCtrl *Get();
  GPair<bool, GVector<RCostBuildingEnough>> IsEnough(const GVector<RCostBuilding>& p_CostBuilding);
  static uint32 getBuildingMaxLvl(EBuildingType p_BuildingType);
  static uint32 getBuildingCount(EBuildingType p_BuildingType);
  static class CityBuildingBase *getBuildingCell(EBuildingType p_BuildingType);
  static GVector<RCostBuilding> checkBuildingPreCond(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static RCostResourceEnough checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  static RBuildingLvlSpecs getReducedLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl);
};