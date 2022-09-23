#include "Building.Static.h"
#include "Building.Enum.h"

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
