#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/Building.Cell.h"

class CityCell;
class IBuilding;
class CityCtrl {
  GHashMap<Guid, CityCell *> m_CityList;
  Guid m_CID ;
public:
  static CityCtrl *Get();
  void AddCity(Guid p_IdCity, CityCell *p_CityCell);
  CityCell *GetCurCity();
  
  GString GetBuildStarLight(uint32 p_StarLvl) { return "" ;}
  uint32 GetBuildStarColor(uint32 p_StarLvl) { return 0 ;}
  void CollectResReq(EBuilding p_Building, EBuildingIndex p_BuildingIndex) {}
  BuildingCell *GetBuildingCell(EBuilding p_Building, EBuildingIndex p_BuildingIndex) { return new BuildingCell() ;}
  BuildingCell *GetBuildingCellByIndex(EBuildingIndex p_BuildingIndex);
  GHashMap<EBuildingIndex, BuildingCell> GetBuildList();
  bool GetCastleUpgradePopStatus();
  int32 GetBuildingMaxLv(EBuilding p_Building){ return 0;}
  void EnterGame();
  void InitClientData();
  void InitCrystalMine();
  void RegisterNotify(){}
};