#include "Building.Static.h"
#include "Building.Enum.h"

GHashMap<EBuilding, RBuildingSpecs> BuildingStatic::BuildingInfo;

BuildingStatic *BuildingStatic::Get() {
  static BuildingStatic* l_Instance = new BuildingStatic();
  return l_Instance;
}

GVector<EBuilding> BuildingStatic::BuildableList = {
        EBuilding::None,         EBuilding::Castle,       EBuilding::Wall,        EBuilding::ArrowTower, EBuilding::WatchTower,
        EBuilding::Depot,        EBuilding::Embassy,      EBuilding::Market,      EBuilding::Institute,  EBuilding::TreasurePool,
        EBuilding::Blacksmith,   EBuilding::Stable,       EBuilding::TargetRange, EBuilding::Barrack,    EBuilding::ChariotPlant,
        EBuilding::Fortress,     EBuilding::DrillGrounds, EBuilding::HallOfWar,   EBuilding::TrainHall,  EBuilding::Prison,
        EBuilding::Farm,         EBuilding::LumberMill,   EBuilding::IronMine,    EBuilding::SilverMine, EBuilding::MarchingTent,
        EBuilding::FirstAidTent, EBuilding::CrystalMine,  EBuilding::Miracle,     EBuilding::ElitePalace};

bool BuildingStatic::isValidBuilding(EBuilding p_BuildingType) {
  auto l_Instance = Get();
  for (auto& l_OneBuilding : l_Instance->_BuildingInfo) {
    if (l_OneBuilding.second.BuildingID == p_BuildingType) return true;
  }
  return false;
}

bool BuildingStatic::isValidBuildingLvl(EBuilding p_BuildingType, uint32 p_Lvl) {
  auto l_Instance = Get();
  for (auto& l_OneBuilding : l_Instance->_BuildingInfo) {
    for (auto& l_OneBuildingLvl : l_OneBuilding.second.Lvls)
      if (l_OneBuildingLvl.second.lvl == p_Lvl) return true;
  }
  return false;
}



RBuildingSpecs& BuildingStatic::getBuildingSpecs(EBuilding p_BuildingType) {
  auto l_Instance = Get();
  if (!l_Instance->_BuildingInfo.Contains(p_BuildingType)) {
    uint32 l_BT = static_cast<uint32>(p_BuildingType);
    GString l_ErrorMsg = StringUtils::format("Trying To get Invalid Building Type %d", l_BT);
    Logger::Get()->Log(l_ErrorMsg, ELogLvl::Error, true);
    return l_Instance->m_InvalidBuildingSpecs;
  }
  return l_Instance->_BuildingInfo[p_BuildingType];
}

RBuildingLvlSpecs& BuildingStatic::getBuildingLvlSpec(EBuilding p_BuildingType, uint32 p_Lvl) {
  auto l_BuildingUnit = getBuildingSpecs(p_BuildingType);
  auto l_Instance = Get();
  if (!l_BuildingUnit.Lvls.Contains(p_Lvl)) {
    uint32 l_BT = static_cast<uint32>(p_BuildingType);
    GString l_ErrorMsg = StringUtils::format("Trying To get Invalid Building Type %d And Lvl", l_BT, p_Lvl);
    Logger::Get()->Log(l_ErrorMsg, ELogLvl::Error, true);
    return l_Instance->m_InvalidBuildingLvlSpecs;
  }
  return l_BuildingUnit.Lvls[p_Lvl];
}


void BuildingStatic::GetFromJsonFile(const XJson &pJson){
  Logger::Get()->Log("BuildingStatic::GetFromJsonFile: " + pJson.dump());
  for(auto &[lBId, lBuilding] : pJson.items()){
    auto lBuildingID = lBuilding.value("buildingID", 0);
    auto lBuildingType = static_cast<EBuilding>(lBuildingID);
    if(!_BuildingInfo.Contains(lBuildingType))
      _BuildingInfo[lBuildingType] = {};
    _BuildingInfo[lBuildingType].FromJson(lBuilding);
  }
}

void BuildingStatic::GetTipsFromJsonFile(const XJson &pJson){
  Logger::Get()->Log("BuildingStatic::GetTipsFromJsonFile: " + pJson.dump());
  for(auto &[lTipID, lTip] : pJson.items()){
    auto lTipID = lTip.value("btnEnum", 0);
    auto lTipType = static_cast<EBuildingTips>(lTipID);
    if(!_BuildTipsConfig.Contains(lTipType))
      _BuildTipsConfig[lTipType] = {};
    _BuildTipsConfig[lTipType].FromJson(lTip);
  }
}