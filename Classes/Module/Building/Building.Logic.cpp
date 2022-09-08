#include "Building.Logic.h"
#include "Building.Ctrl.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "CityBuildingBase.h"

bool BuildingLogic::isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
  TBuildingUnitSpecs l_BuildingUnitSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
  if(BuildingCtrl::getBuildingMaxLvl(p_BuildingType) >=  (uint32)l_BuildingUnitSpecs.maxLvl)
    return false;
  CityBuildingBase *l_BuildingCell = BuildingCtrl::getBuildingCell(p_BuildingType);
  

  return true;
}

bool  BuildingLogic::isBuildingLvlReqAchieved(
  EBuildingType p_BuildingType, uint32 p_CurentLvl, TBuildingLvlSpecs &p_BuildingLvlSpecs
  ){
    TBuildingLvlSpecs l_lvlReq = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurentLvl);
    TBuildingUnitSpecs l_BuildingSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
    uint32 l_BuildingInitLvl = std::max((uint32)l_BuildingSpecs.initLvl, BuildingCtrl::getBuildingMaxLvl(p_BuildingType));
    
    return false;

}