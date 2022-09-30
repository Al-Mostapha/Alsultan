#include "Building.Logic.h"
#include "Building.Ctrl.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "CityBuildingBase.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Item/Item.Ctrl.h"
#include "Module/Player/Gold/Gold.Ctrl.h"
#include "Base/Math/Math.Base.h"

bool BuildingLogic::isCanUpgrade(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
  RBuildingUnitSpecs l_BuildingUnitSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
  if(BuildingCtrl::getBuildingMaxLvl(p_BuildingType) >=  (uint32)l_BuildingUnitSpecs.maxLvl)
    return false;
  RBuildingLvlSpecs l_lvlReq = BuildingCtrl::getReducedLvlSpec(p_BuildingType, p_CurrentLvl);
  RCostBuildingUpgrade l_CostUpgrade;
  l_CostUpgrade.CostResource    = ResourceCtrl::Get()->IsEnough(l_lvlReq.CostRes).second;
  l_CostUpgrade.CostItem        = ItemCtrl::Get()->IsEnough(l_lvlReq.CostItems).second;
  l_CostUpgrade.CostItemWEs     = ItemCtrl::Get()->IsEnough(l_lvlReq.CostWEs).second;
  l_CostUpgrade.CostBuilding    = BuildingCtrl::Get()->Is
  l_CostUpgrade.resToGold       = GoldCtrl::Get()->resourceToGold(l_CostUpgrade.CostResource);
  l_CostUpgrade.itemToGold      = GoldCtrl::Get()->itemToGold(l_CostUpgrade.CostItem);
  l_CostUpgrade.WEToGold        = GoldCtrl::Get()->itemToGold(l_CostUpgrade.CostItemWEs);
  
  RBuildingUnitSpecs l_BuildingSpecs = BuildingStatic::getBuildingUnitSpecs(p_BuildingType);
  uint32 l_BuildingInitLvl = std::max((uint32)l_BuildingSpecs.initLvl, BuildingCtrl::getBuildingMaxLvl(p_BuildingType));


  uint32 l_ReducedCostTime = l_lvlReq.CostTime;
  
  // if(!l_ResourceIsEnough.IsEnough())
  //   l_IsAchieved = false;
  // if(!l_ItemIsEnough.first)
  //   l_IsAchieved = false;
  // if(!l_ItemWEsIsEnough.first)
  //   l_IsAchieved = false;
  // uint32 l_ItemGold = 0;
  // uint32 l_ItemWEsGold = 0;
  // for(auto l_OneItem : l_lvlReq.CostItems)
  //   l_ItemGold += ItemCtrl::Get()->GetItemPrice(l_OneItem.idItem) * l_OneItem.amount;
  // for(auto l_OneItemWes : l_lvlReq.CostWEs)
  //   l_ItemWEsGold += ItemCtrl::Get()->GetItemPrice(l_OneItemWes.idItem) * l_OneItemWes.amount;
  
  return true;
}

GPair<bool, RCostBuildingUpgrade> BuildingLogic::isBuildingCostAchieved(
  EBuildingType p_BuildingType, uint32 p_CurentLvl, RBuildingLvlSpecs &p_BuildingLvlSpecs
  ){

  
  //return false;
}