#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Base/Containers/Pair.h"

class BuildingCtrl {
private:
  void getReducedCostTime(RBuildingLvlSpecs &p_OriginalSpec);
  void getReducedCostItem(RBuildingLvlSpecs &p_OriginalSpec);
  void getReducedCostResource(RBuildingLvlSpecs &p_OriginalSpec);
  void getReducedCostScience(RBuildingLvlSpecs &p_OriginalSpec);

public:
  static BuildingCtrl *Get();
  GPair<bool, GVector<struct RCostBuildingEnough>> IsEnough(const GVector<struct RCostBuilding>& p_CostBuilding);
  uint32 getBuildingMaxLvl(EBuildingType p_BuildingType);
  uint32 getBuildingCount(EBuildingType p_BuildingType);
  class CityBuildingBase *getBuildingCell(EBuildingType p_BuildingType);
  GVector<RCostBuilding> checkBuildingPreCond(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  RCostResourceEnough checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl);
  RBuildingLvlSpecs getReducedLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl);
};