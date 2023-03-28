#include "CityBuilding.Create.h"
#include "Module/Building/Building.Lib.h"

CityBuildingCreate *CityBuildingCreate::Get(){
  static auto l_Inst = new CityBuildingCreate();
  return l_Inst;
}

IBuilding *CityBuildingCreate::CreateBuild(EBuilding p_BuildingId){
  auto l_BuildingNode = GetBuildClass(p_BuildingId);
  l_BuildingNode->InitWithUIType();
  l_BuildingNode->SetBuildingBID(p_BuildingId);
  l_BuildingNode->LoadView();
  return l_BuildingNode;
};

IBuilding* CityBuildingCreate::GetBuildClass(EBuilding p_BuildingId){
  return BuildingLib::getBuildingClassByType(p_BuildingId);
}