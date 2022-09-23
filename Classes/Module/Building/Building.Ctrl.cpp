#include "Building.Ctrl.h"
#include "Building.Static.h"

#include "Module/CityResource/Resource.Type.h"
#include "Module/Effect/Effect.Type.h"
#include "Module/CityResource/Resource.Static.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Effect/Effect.Ctrl.h"
#include "Module/Science/Science.Ctrl.h"


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



void BuildingCtrl::getReducedCostTime(RBuildingLvlSpecs& p_OriginalSpec) {
  /* local technologyCtrl = gametop.playertop_:getModule("technologyCtrl")
  local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  local allianceScience = gametop.playertop_:getModule("allianceScience")
  local skill_add = lordInfoCtrl:getTechnologyPower(gLordTechnologyType.ACCELERATE_CONSTRUCTION)
  local technologyAdd = technologyCtrl:getTechnologyPower(gTechnologyType.CONSTRUCTION_SPEED)
  local allianceAdd = allianceScience:getScienceAddValue(gAScienceType.BUILDING_UPGRADE_SPEED)
  local buffCtrl = gametop.playertop_:getModule("buffCtrl")
  local buffValue = buffCtrl:getBuffEffect(gBuffEffect.BUILD_SPEED_BOOST) or 0
  if blv and blv <= 30 then
    local buffValue30 = buffCtrl:getBuffEffect(gBuffEffect.CONSTRUCTION_SPEED_30) or 0
    buffValue = buffValue + buffValue30
  end
  local buffReduce = buffCtrl:getBuffEffect(gBuffEffect.BUILD_SPEED_REDUCE) or 0
  if buffReduce and buffReduce > 0 then
    buffValue = buffValue - buffReduce
  end
  if blv and blv <= 70 then
    local buffValue70 = buffCtrl:getBuffEffect(gBuffEffect.CONSTRUCTION_SPEED_Z4) or 0
    buffValue = buffValue + buffValue70
  end
  local attrPlus = attributeSystem.query(gAttributeEnum.BUILD_SPEED_UP_RATE) or 0
  attrPlus = attrPlus / 10
  buffValue = buffValue + attrPlus
  buffValue = buffValue and buffValue / 1000 or 0
  local ret = skill_add + technologyAdd + allianceAdd + buffValue
  return ret*/
}

void BuildingCtrl::getReducedCostItem(RBuildingLvlSpecs& p_OriginalSpec) {}

void BuildingCtrl::getReducedCostResource(RBuildingLvlSpecs& p_OriginalSpec) {

  auto l_CostReduced = EffectCtrl::getEffectVal(EEffectType::UpgradeCastleCostResReduce);
  if (p_OriginalSpec.lvl <= 30) 
    l_CostReduced += EffectCtrl::getEffectVal(EEffectType::UpgradeBuildingCostResReduceLess30);
  if (p_OriginalSpec.lvl <= 70)
    l_CostReduced += EffectCtrl::getEffectVal(EEffectType::UpgradeBuildingCostResReduceLessZ4);
  l_CostReduced = l_CostReduced /1000 + ScienceCtrl::getSciencePower(EScienceEffect::BuildingCostReduce);

  p_OriginalSpec.CostRes.Coin    = std::ceil(p_OriginalSpec.CostRes.Coin    * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Crystal = std::ceil(p_OriginalSpec.CostRes.Crystal * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Grain   = std::ceil(p_OriginalSpec.CostRes.Grain   * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Iron    = std::ceil(p_OriginalSpec.CostRes.Iron    * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Lumber  = std::ceil(p_OriginalSpec.CostRes.Lumber  * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Metal   = std::ceil(p_OriginalSpec.CostRes.Metal   * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Silver  = std::ceil(p_OriginalSpec.CostRes.Silver  * (1 - l_CostReduced));

}

void BuildingCtrl::getReducedCostScience(RBuildingLvlSpecs& p_OriginalSpec) {}

RBuildingLvlSpecs BuildingCtrl::getReducedLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl) {
  if(!BuildingStatic::isValidBuildingLvl(p_BuildingType, p_Lvl))
    return  BuildingStatic::Instance().getBuildingLvlSpec(p_BuildingType, p_Lvl);
  RBuildingLvlSpecs l_BuildingLvlSpec = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_Lvl);
  getReducedCostItem(l_BuildingLvlSpec);
  getReducedCostResource(l_BuildingLvlSpec);
  getReducedCostScience(l_BuildingLvlSpec);
  getReducedCostTime(l_BuildingLvlSpec);
  return l_BuildingLvlSpec;
}




// TResource BuildingCtrl::checkBuildingCostRes(EBuildingType p_BuildingType, uint32 p_CurrentLvl){
//   auto l_CostRes = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_CurrentLvl).costRes;

// }