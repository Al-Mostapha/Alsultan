#include "Building.Ctrl.h"
#include "Building.Static.h"

#include "Module/CityResource/Resource.Type.h"
#include "Module/Effect/Effect.Type.h"
#include "Module/CityResource/Resource.Static.h"
#include "Module/CityResource/Resource.Ctrl.h"
#include "Module/Effect/Effect.Ctrl.h"
#include "Module/Science/Science.Ctrl.h"
#include "Module/Player/Science/LordScience.Ctrl.h"
#include "Module/Guild/Science/GuildScience.Ctrl.h"

BuildingCtrl *BuildingCtrl::Get(){
  static BuildingCtrl *l_Instance = new BuildingCtrl();
  return l_Instance;
}

uint32  BuildingCtrl::getBuildingMaxLvl(EBuilding p_BuildingType){
  // TODO:: 
  return 0;
}

uint32 BuildingCtrl::getBuildingCount(EBuilding p_BuildingType){
  return 0;
}


IBuilding *BuildingCtrl::getBuildingCell(EBuilding p_BUildingType){
  return nullptr;
}


void BuildingCtrl::getReducedCostTime(RBuildingLvlSpecs& p_OriginalSpec) {

  uint32  l_skill_add = LordScienceCtrl::Get()->getSciencePower(ELordScience::AccelerateConstruction);
  uint32  l_technologyAdd = ScienceCtrl::Get()->getSciencePower(EScienceEffect::ConstructionSpeed);
  uint32  l_allianceAdd = GuildScienceCtrl::Get()->getSciencePower(EGuildScience::BuildingUpgradeSpeed);
  uint32 l_Effect = EffectCtrl::Get()->getEffectVal(EEffect::BuildingSpeedBoost);
  if(p_OriginalSpec.lvl <= 30)
    l_Effect  += EffectCtrl::Get()->getEffectVal(EEffect::ConstructionSpeed30);
  l_Effect -= EffectCtrl::Get()->getEffectVal(EEffect::BuildingSpeedReduce);
  if(p_OriginalSpec.lvl <= 70)
    l_Effect += EffectCtrl::Get()->getEffectVal(EEffect::ConstructionSpeedZ4);
  // local attrPlus = attributeSystem.query(gAttributeEnum.BUILD_SPEED_UP_RATE) or 0
  // attrPlus = attrPlus / 10
  // buffValue = buffValue + attrPlus
  l_Effect = l_Effect/1000;
  p_OriginalSpec.CostTime = std::floor((uint32)1/(uint32)(1+l_skill_add + l_technologyAdd + l_allianceAdd + l_Effect)); 
 
}

void BuildingCtrl::getReducedCostItem(RBuildingLvlSpecs& p_OriginalSpec) {}

void BuildingCtrl::getReducedCostResource(RBuildingLvlSpecs& p_OriginalSpec) {

  auto l_CostReduced = EffectCtrl::Get()->getEffectVal(EEffect::UpgradeCastleCostResReduce);
  if (p_OriginalSpec.lvl <= 30) 
    l_CostReduced += EffectCtrl::Get()->getEffectVal(EEffect::UpgradeBuildingCostResReduceLess30);
  if (p_OriginalSpec.lvl <= 70)
    l_CostReduced += EffectCtrl::Get()->getEffectVal(EEffect::UpgradeBuildingCostResReduceLessZ4);
  l_CostReduced = l_CostReduced /1000 + ScienceCtrl::Get()->getSciencePower(EScienceEffect::BuildingCostReduce);

  p_OriginalSpec.CostRes.Coin    = std::ceil(p_OriginalSpec.CostRes.Coin    * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Crystal = std::ceil(p_OriginalSpec.CostRes.Crystal * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Grain   = std::ceil(p_OriginalSpec.CostRes.Grain   * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Iron    = std::ceil(p_OriginalSpec.CostRes.Iron    * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Lumber  = std::ceil(p_OriginalSpec.CostRes.Lumber  * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Metal   = std::ceil(p_OriginalSpec.CostRes.Metal   * (1 - l_CostReduced));
  p_OriginalSpec.CostRes.Silver  = std::ceil(p_OriginalSpec.CostRes.Silver  * (1 - l_CostReduced));

}

void BuildingCtrl::getReducedCostScience(RBuildingLvlSpecs& p_OriginalSpec) {}

RBuildingLvlSpecs BuildingCtrl::getReducedLvlSpec(EBuilding p_BuildingType, uint32 p_Lvl) {
  if(!BuildingStatic::isValidBuildingLvl(p_BuildingType, p_Lvl))
    return BuildingStatic::Get()->getBuildingLvlSpec(p_BuildingType, p_Lvl);
  RBuildingLvlSpecs l_BuildingLvlSpec = BuildingStatic::getBuildingLvlSpec(p_BuildingType, p_Lvl);
  getReducedCostItem(l_BuildingLvlSpec);
  getReducedCostResource(l_BuildingLvlSpec);
  getReducedCostScience(l_BuildingLvlSpec);
  getReducedCostTime(l_BuildingLvlSpec);
  return l_BuildingLvlSpec;
}


GPair<bool, GVector<RCostBuildingEnough>> BuildingCtrl::IsEnough(const GVector<RCostBuilding>& p_CostBuilding){
  auto l_CostBuildingEnough = GPair<bool, GVector<RCostBuildingEnough>>::Make(true, {});

  for(auto l_OneBuilding : p_CostBuilding){
    RCostBuildingEnough l_OneCostEnough;
    l_OneCostEnough.TypeReq   = l_OneBuilding.TypeReq;
    l_OneCostEnough.lvlReq    = l_OneBuilding.lvlReq;
    l_OneCostEnough.lvlCurMax = getBuildingMaxLvl(l_OneBuilding.TypeReq);
    l_OneCostEnough.isEnough  = l_OneCostEnough.lvlCurMax >= l_OneCostEnough.lvlReq;
    l_OneCostEnough.lvlLack   = l_OneCostEnough.lvlCurMax - l_OneCostEnough.lvlReq;
    if( !l_OneCostEnough.isEnough )
      l_CostBuildingEnough.First = false;
  }
  return l_CostBuildingEnough;
}
