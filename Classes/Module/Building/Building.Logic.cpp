#include "Building.Logic.h"
#include "Base/Math/Math.Base.h"
#include "Building.Ctrl.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "IBuilding.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Item/Item.Ctrl.h"
#include "Module/Player/Gold/Gold.Ctrl.h"
#include "Building.Const.h"

BuildingLogic* BuildingLogic::Get() {
  static BuildingLogic* l_Instance = new BuildingLogic();
  return l_Instance;
}

bool BuildingLogic::IsBuildingCostAchieved(const RCostBuildingUpgrade& p_CostUpgrade) {
  if (!p_CostUpgrade.CostResource.IsEnough()) return false;
  for (auto l_OneCostItem : p_CostUpgrade.CostItem) {
    if (!l_OneCostItem.isEnough) return false;
  }
  for (auto l_OneCostItem : p_CostUpgrade.CostItemWEs) {
    if (!l_OneCostItem.isEnough) return false;
  }
  for (auto l_OneCostBuilding : p_CostUpgrade.CostBuilding) {
    if (!l_OneCostBuilding.isEnough) return false;
  }
  return true;
} 

GPair<bool, RCostBuildingUpgrade> BuildingLogic::IsCanUpgrade(EBuilding p_BuildingType, uint32 p_CurrentLvl) {
  auto l_CostUpgrade = GPair<bool, RCostBuildingUpgrade>::Make(true, RCostBuildingUpgrade());
  RBuildingLvlSpecs l_lvlReq = BuildingCtrl::Get()->getReducedLvlSpec(p_BuildingType, p_CurrentLvl);

  l_CostUpgrade.Second.CostResource = ResourceCtrl::Get()->IsEnough(l_lvlReq.CostRes).Second;
  l_CostUpgrade.Second.CostItem     = ItemCtrl::Get()->IsEnough(l_lvlReq.CostItems).Second;
  l_CostUpgrade.Second.CostItemWEs  = ItemCtrl::Get()->IsEnough(l_lvlReq.CostWEs).Second;
  l_CostUpgrade.Second.CostBuilding = BuildingCtrl::Get()->IsEnough(l_lvlReq.CostBuilding).Second;
  l_CostUpgrade.Second.resToGold    = GoldCtrl::Get()->resourceToGold(l_CostUpgrade.Second.CostResource);
  l_CostUpgrade.Second.itemToGold   = GoldCtrl::Get()->itemToGold(l_CostUpgrade.Second.CostItem);
  l_CostUpgrade.Second.WEToGold     = GoldCtrl::Get()->itemToGold(l_CostUpgrade.Second.CostItemWEs);
  l_CostUpgrade.Second.timeToGold   = GoldCtrl::Get()->timeToGold(l_lvlReq.CostTime);
  l_CostUpgrade.Second.Reword.exp   = l_lvlReq.Reword.exp;
  l_CostUpgrade.Second.Reword.power = l_lvlReq.Reword.power;

  l_CostUpgrade.First = IsBuildingCostAchieved(l_CostUpgrade.Second);

  return l_CostUpgrade;
}

GPair<bool, RCostBuildingUpgrade> BuildingLogic::IsCanBuild(EBuilding p_BuildingType){
  auto l_BuildingSpecs = BuildingStatic::getBuildingSpecs(p_BuildingType);
  if(!l_BuildingSpecs.isBuild){
    return GPair<bool, RCostBuildingUpgrade>::Make(false, RCostBuildingUpgrade());
  }

  return IsCanUpgrade(p_BuildingType, BuildingConst::Get()->FirstLvl);
}

ETask BuildingLogic::GetQueueType(EBuildingIndex p_BuildingIndex) {
  return ETask::None;
}