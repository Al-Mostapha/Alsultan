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

  for (auto l_OneCostItem : p_CostUpgrade._CostItem) {
    if (!l_OneCostItem._IsReach) return false;
  }
  for (auto l_OneCostItem : p_CostUpgrade._CostItemWEs) {
    if (!l_OneCostItem._IsReach) return false;
  }
  for (auto l_OneCostBuilding : p_CostUpgrade._CostBuilding) {
    if (!l_OneCostBuilding._IsReach) return false;
  }
  return true;
} 

GPair<bool, RCostBuildingUpgrade> BuildingLogic::IsCanUpgrade(EBuildingIndex p_BuildingType, uint32 p_CurrentLvl) {
  auto l_CostUpgrade = GPair<bool, RCostBuildingUpgrade>::Make(true, RCostBuildingUpgrade());
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(p_BuildingType);
  RBuildingLvlSpecs l_lvlReq = BuildingCtrl::Get()->getReducedLvlSpec(l_BuildingCell->GetBuildingId(), p_CurrentLvl);

  //l_CostUpgrade.Second._CostResource = ResourceCtrl::Get()->IsEnough(l_lvlReq.CostRes).Second;
  l_CostUpgrade.Second._CostItem     = ItemCtrl::Get()->IsEnough(l_lvlReq.CostItems).Second;
  l_CostUpgrade.Second._CostItemWEs  = ItemCtrl::Get()->IsEnough(l_lvlReq.CostWEs).Second;
  l_CostUpgrade.Second._CostBuilding = BuildingCtrl::Get()->IsEnough(l_lvlReq.CostBuilding).Second;
  l_CostUpgrade.Second.resToGold    = GoldCtrl::Get()->resourceToGold(l_CostUpgrade.Second._CostResource);
  l_CostUpgrade.Second.itemToGold   = GoldCtrl::Get()->itemToGold(l_CostUpgrade.Second._CostItem);
  l_CostUpgrade.Second.WEToGold     = GoldCtrl::Get()->itemToGold(l_CostUpgrade.Second._CostItemWEs);
  l_CostUpgrade.Second.timeToGold   = GoldCtrl::Get()->timeToGold(l_lvlReq._CostTime);
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
  return GPair<bool, RCostBuildingUpgrade>::Make(false, RCostBuildingUpgrade());
  //return IsCanUpgrade(p_BuildingType, BuildingConst::Get()->FirstLvl);
}

ITask *BuildingLogic::GetQueueType(EBuildingIndex p_BuildingIndex) {
  return nullptr;
}

GPair<ETask, GTime> BuildingLogic::GetIdleBuildQueue() {
  //   local freequeue = queueCtrl:queryQueue(gQueueTypeDef.free_build_queue)
  // local chargequeue = queueCtrl:queryQueue(gQueueTypeDef.charge_build_queue)
  // if not freequeue then
  //   return gQueueTypeDef.free_build_queue, 0
  // elseif not chargequeue then
  //   local buildchargequeue = cityCtrl:getCurCity():queryQueue(gQueueTypeDef.charge_build_queue)
  //   if buildchargequeue then
  //     local timerNode = buildchargequeue.timerNode
  //     if timerNode then
  //       return gQueueTypeDef.charge_build_queue, timerNode.timer:getRemainTime()
  //     end
  //   end
  // end
  return GPair<ETask, GTime>(ETask::None, 0);
}

bool BuildingLogic::GetOutBuildIsResBuild(EBuilding p_Bid){
  if(p_Bid == EBuilding::Farm)
    return true;
  if(p_Bid == EBuilding::LumberMill)
    return true;
  if(p_Bid == EBuilding::IronMine)
    return true;
  if(p_Bid == EBuilding::SilverMine)
    return true;
  if(p_Bid == EBuilding::CrystalMine)
    return true;
  return false;
}
