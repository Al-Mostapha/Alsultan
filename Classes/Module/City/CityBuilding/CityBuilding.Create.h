#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/IBuilding.h"

class CityBuildingCreate {
  public:
  static CityBuildingCreate* Get();
  // createBuild_Alone
  IBuilding* CreateBuild(EBuilding p_BuildingId);
  // createBuild_Relyon
  IBuilding* CreateBuild(EBuilding p_BuildingId, Node* p_ViewNode, Vec2 p_BasePos);

  private:
  IBuilding* GetBuildClass(EBuilding p_BuildingId);
};