#include "Building.Cell.h"
#include "Base/Type/Json/XJson.h"

void BuildingCell::Upgrade(){
  
}

void BuildingCell::UpgradeStar(){

}

void BuildingCell::FromJson(const XJson &pJson){
  if (pJson.is_null())
    return;
  _Info.FromJson(pJson);
}

void RBuildingCellInfo::FromJson(const XJson &pJson){
  if (pJson.is_null())
    return;
  IdBuilding = pJson.value("_Type", EBuilding::None);
  BuildingIndex = pJson.value("_Index", EBuildingIndex::None);
  buildingLvl = pJson.value("_Lvl", 0);
  starLvl = pJson.value("_StarLvl", 0);
  state = pJson.value("_State", EBuildingState::None);
}

