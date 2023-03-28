#include "City.Cell.h"

void CityCell::AddBuilding(EBuildingIndex p_Index, BuildingCell p_Building) {
  if(BuildingFound(p_Index))
    return;
  BuildingList[p_Index] = p_Building;
}

void CityCell::RemoveBuilding(EBuildingIndex p_Index) {
  auto l_Entry = BuildingList.find(p_Index);
  if(l_Entry == BuildingList.end())
    return;
  BuildingList.erase(p_Index);
}

void CityCell::UpgradeBuilding(EBuildingIndex p_Index) {
  if(!BuildingFound(p_Index))
    return;
  auto l_Builaing = GetBuilding(p_Index);
  l_Builaing.Upgrade();
}

void CityCell::UpgradeBuildingStar(EBuildingIndex p_Index) {

  if(BuildingFound(p_Index))
    return;
  auto l_Builaing = GetBuilding(p_Index);
  l_Builaing.UpgradeStar();
}

void CityCell::ExchangeBuild(EBuildingIndex p_PreIndex, EBuildingIndex p_AftIndex) {
  //   local prebuild = self.buildList[tostring(preindex)]
  // local aftbuild = self.buildList[tostring(aftindex)]
  // if prebuild and aftbuild then
  //   prebuild.info.index = tostring(aftindex)
  //   self.buildList[tostring(aftindex)] = prebuild
  //   aftbuild.info.index = tostring(preindex)
  //   self.buildList[tostring(preindex)] = aftbuild
  // end
  // if prebuild and not aftbuild then
  //   prebuild.info.index = tostring(aftindex)
  //   self.buildList[tostring(aftindex)] = prebuild
  //   self.buildList[tostring(preindex)] = nil
  // end
  // if not prebuild and aftbuild then
  //   aftbuild.info.index = tostring(preindex)
  //   self.buildList[tostring(preindex)] = aftbuild
  //   self.buildList[tostring(aftindex)] = nil
  // end
}

void CityCell::OpenArea(ELockedArea p_Area) {
  auto l_FoundIt = std::find(AreaList.begin(), AreaList.end(), p_Area);
  if(l_FoundIt != AreaList.end())
    AreaList.emplace_back(p_Area);
}

BuildingCell &CityCell::GetBuilding(EBuildingIndex p_Index){
  return BuildingList[p_Index];
}

bool CityCell::BuildingFound(EBuildingIndex p_Index){
  return BuildingList.find(p_Index) != BuildingList.end();
}