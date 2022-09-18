#include "Building.Ctrl.h"
#include "Building.Static.h"

#include "Module/CityResource/Resource.Type.h"
#include "Module/Effect/Effect.Type.h"
#include "Module/CityResource/Resource.Static.h"
#include "Module/CityResource/Resource.Ctrl.h"


uint32  BuildingCtrl::getBuildingMaxLvl(EBuildingType p_BuildingType){
  // TODO:: 
  return 0;
}


CityBuildingBase *BuildingCtrl::getBuildingCell(EBuildingType p_BUildingType){
  return nullptr;
}


GVector<RCostBuilding> BuildingCtrl::checkBuildingPreCond(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
  auto l_preCond = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurrentLvl).CostBuilding;
  GVector<RCostBuilding> l_OutPreCond;
  for(auto& l_OneCond : l_preCond){
    l_OneCond.isAchieved = false;
    if(getBuildingMaxLvl(l_OneCond.buildingType) >= l_OneCond.buildingLvl)
      l_OneCond.isAchieved = true;
  }
  return l_OutPreCond;
}

RResourceIsEnough BuildingCtrl::checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
  auto l_CostRes = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurrentLvl).CostRes;
  return ResourceCtrl::isResourceEnough(l_CostRes);
}



// TResource BuildingCtrl::checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
//   auto l_CostRes = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurrentLvl).costRes;

// }