#pragma once
#include "Include/IncludeBase.h"
#include "Base/Type/XVector.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/IBuilding.h"
#include "Module/CityResource/CityResource.h"
#include "Module/Task/ITask.h"
#include "Base/Type/XJson.h"

class CityCell {
  public:
  GHashMap<EBuildingIndex, BuildingCell> BuildingList;
  RResource ResList;
  GVector<ELockedArea> AreaList;
  GVector<ITask*> Queue;
  RResource SafeRes;
  int32 _CityID;
  int32 _Lvl;
  int32 _PlayerID;
  void *Mastery;
  void *DrawingData;

  void AddBuilding(EBuildingIndex p_Index, BuildingCell p_Building);
  void RemoveBuilding(EBuildingIndex p_Index);
  void UpgradeBuilding(EBuildingIndex p_Index);
  void UpgradeBuildingStar(EBuildingIndex p_Index);
  void ExchangeBuild(EBuildingIndex p_PreIndex, EBuildingIndex p_AftIndex);
  void OpenArea(ELockedArea p_Area);
  ITask *QueryQueue(ETask p_Task){return nullptr;}
  void FromJson(GJson *p_Json);
  void FromJson(const XJson &pJson);
  private:
    BuildingCell &GetBuilding(EBuildingIndex p_Index);
    bool BuildingFound(EBuildingIndex p_Index);
};