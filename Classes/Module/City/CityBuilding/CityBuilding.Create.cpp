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

IBuilding *CityBuildingCreate::CreateBuild(EBuilding p_BuildingId, Node* p_ViewNode, Vec2 p_BasePos){
  auto l_BuildingNode = GetBuildClass(p_BuildingId);
  RBuildingViewNodes l_ViewNodes;
  l_ViewNodes.n_MainCityOuter = p_ViewNode;
  l_BuildingNode->InitWithUIType(l_ViewNodes, p_BasePos);
  l_BuildingNode->SetBuildingBID(p_BuildingId);
  l_BuildingNode->LoadView();
  return l_BuildingNode;
};

IBuilding* CityBuildingCreate::GetBuildClass(EBuilding p_BuildingId){
  return BuildingLib::getBuildingClassByType(p_BuildingId);
}