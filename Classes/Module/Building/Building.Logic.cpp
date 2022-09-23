#include "Building.Logic.h"
#include "Building.Ctrl.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "CityBuildingBase.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Item/Item.Ctrl.h"

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
  RBuildingLvlSpecs l_lvlReq = BuildingCtrl::getReducedLvlSpec(p_BuildingType, p_CurentLvl);
  RBuildingUnitSpecs l_BuildingSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
  uint32 l_BuildingInitLvl = std::max((uint32)l_BuildingSpecs.initLvl, BuildingCtrl::getBuildingMaxLvl(p_BuildingType));
  RResourceIsEnough l_ResourceIsEnough = ResourceCtrl::isResourceEnough(l_lvlReq.CostRes);
  GPair<bool, GVector<RItemIsEnough>> l_ItemIsEnough = ItemCtrl::isEnough(l_lvlReq.CostItems);
  GPair<bool, GVector<RItemIsEnough>> l_ItemWEsIsEnough = ItemCtrl::isEnough(l_lvlReq.CostWEs);
  if(!l_ResourceIsEnough.isEnough())
    return false;
  if(!l_ItemIsEnough.first)
    return false;
  if(!l_ItemWEsIsEnough.first)
    return false;

  return false;

}