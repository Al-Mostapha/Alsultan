#pragma once
#include "Base/Containers/HashMap.h"
#include "Building.Const.h"
#include "Building.Enum.h"
#include "Building.Type.h"
#include "Include/IncludeBase.h"

class BuildingStatic {
  private:
  GHashMap<EBuilding, RBuildingSpecs> m_BuildingInfo;
  RBuildingSpecs m_InvalidBuildingSpecs;
  RBuildingLvlSpecs m_InvalidBuildingLvlSpecs;

  public:
  static GHashMap<EBuilding, RBuildingSpecs> BuildingInfo;
  static BuildingStatic *Get();
  static GVector<EBuilding> BuildableList;

  static bool isValidBuilding(EBuilding p_BuildingType);
  static bool isValidBuildingLvl(EBuilding p_BuildingType, uint32 p_Lvl);
  static RBuildingSpecs &getBuildingSpecs(EBuilding p_BuildingType);
  static RBuildingLvlSpecs &getBuildingLvlSpec(EBuilding p_BuildingType, uint32 p_Lvl);
};
