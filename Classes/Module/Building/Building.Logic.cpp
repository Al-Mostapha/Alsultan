#include "Building.Logic.h"
#include "Building.Ctrl.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "CityBuildingBase.h"

bool BuildingLogic::isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
  RBuildingUnitSpecs l_BuildingUnitSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
  if(BuildingCtrl::getBuildingMaxLvl(p_BuildingType) >=  (uint32)l_BuildingUnitSpecs.maxLvl)
    return false;
  CityBuildingBase *l_BuildingCell = BuildingCtrl::getBuildingCell(p_BuildingType);
 
  return true;
}

bool BuildingLogic::isBuildingCostAchieved(
  EBuildingType p_BuildingType, uint32 p_CurentLvl, RBuildingLvlSpecs &p_BuildingLvlSpecs
  ){
    RBuildingLvlSpecs l_lvlReq = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurentLvl);
    RBuildingUnitSpecs l_BuildingSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
    uint32 l_BuildingInitLvl = std::max((uint32)l_BuildingSpecs.initLvl, BuildingCtrl::getBuildingMaxLvl(p_BuildingType));
    
    return false;

}