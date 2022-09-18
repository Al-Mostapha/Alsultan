#include "Building.Static.h"
#include "Building.Enum.h"
#include "Module/Effect/Effect.Ctrl.h"
#include "Module/Science/Science.Ctrl.h"

BuildingStatic& BuildingStatic::Instance() {
  static BuildingStatic* l_Instance = new BuildingStatic();
  return *l_Instance;
}

GVector<EBuildingType> BuildingStatic::BuildableList = {
        EBuildingType::None,         EBuildingType::Castle,       EBuildingType::Wall,        EBuildingType::ArrowTower, EBuildingType::WatchTower,
        EBuildingType::Warehouse,    EBuildingType::Embassy,      EBuildingType::Market,      EBuildingType::Institute,  EBuildingType::TreasurePool,
        EBuildingType::Blacksmith,   EBuildingType::Stable,       EBuildingType::TargetRange, EBuildingType::Barrack,    EBuildingType::ChariotPlant,
        EBuildingType::Fortress,     EBuildingType::DrillGrounds, EBuildingType::HallOfWar,   EBuildingType::TrainHall,  EBuildingType::Prison,
        EBuildingType::Farm,         EBuildingType::LumberMill,   EBuildingType::IronMine,    EBuildingType::SilverMine, EBuildingType::MarchingTent,
        EBuildingType::FirstAidTent, EBuildingType::CrystalMine,  EBuildingType::Miracle,     EBuildingType::ElitePalace};

bool BuildingStatic::isValidBuilding(EBuildingType p_BuildingType) {
  auto l_Instance = Instance();
  for (auto& l_OneBuilding : l_Instance.m_BuildingInfo) {
    if (l_OneBuilding.second.buildingType == p_BuildingType) return true;
  }
  return false;
}

bool BuildingStatic::isValidBuildingLvl(EBuildingType p_BuildingType, uint32 p_Lvl) {
  auto l_Instance = Instance();
  for (auto& l_OneBuilding : l_Instance.m_BuildingInfo) {
    for (auto& l_OneBuildingLvl : l_OneBuilding.second.Lvls)
      if (l_OneBuildingLvl.second.lvl == p_Lvl) return true;
  }
  return false;
}

GHashMap<EBuildingType, RBuildingUnitSpecs> BuildingStatic::BuildingInfo;

RBuildingUnitSpecs& BuildingStatic::getBuildingUnitSpecs(EBuildingType p_BuildingType) {
  auto l_Instance = Instance();
  if (!l_Instance.m_BuildingInfo.Contains(p_BuildingType)) {
    uint32 l_BT = static_cast<uint32>(p_BuildingType);
    GString l_ErrorMsg = StringUtils::format("Trying To get Invalid Building Type %d", l_BT);
    Logger::Log(l_ErrorMsg, ELogLvl::Error, true);
    return l_Instance.m_InvalidBuildingUnitSpecs;
  }
  return l_Instance.m_BuildingInfo[p_BuildingType];
}

RBuildingLvlSpecs& BuildingStatic::getBuildingLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl) {
  auto l_BuildingUnit = getBuildingUnitSpecs(p_BuildingType);
  auto& l_Instance = Instance();
  if (!l_BuildingUnit.Lvls.Contains(p_Lvl)) {
    uint32 l_BT = static_cast<uint32>(p_BuildingType);
    GString l_ErrorMsg = StringUtils::format("Trying To get Invalid Building Type %d And Lvl", l_BT, p_Lvl);
    Logger::Log(l_ErrorMsg, ELogLvl::Error, true);
    return l_Instance.m_InvalidBuildingLvlSpecs;
  }
  return l_BuildingUnit.Lvls[p_Lvl];
}

void BuildingStatic::getReducedCostTime(RBuildingLvlSpecs& p_OriginalSpec) {}
void BuildingStatic::getReducedCostItem(RBuildingLvlSpecs& p_OriginalSpec) {}

void BuildingStatic::getReducedCostResource(RBuildingLvlSpecs& p_OriginalSpec) {

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

void BuildingStatic::getReducedCostScience(RBuildingLvlSpecs& p_OriginalSpec) {}

RBuildingLvlSpecs BuildingStatic::getReducedLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl) {

  if(!isValidBuildingLvl(p_BuildingType, p_Lvl))
    return  Instance().m_InvalidBuildingLvlSpecs;

  RBuildingLvlSpecs l_BuildingLvlSpec = getBuildingLvlSpec(p_BuildingType, p_Lvl);
  getReducedCostItem(l_BuildingLvlSpec);
  getReducedCostResource(l_BuildingLvlSpec);
  getReducedCostScience(l_BuildingLvlSpec);
  getReducedCostTime(l_BuildingLvlSpec);
  return l_BuildingLvlSpec;
}