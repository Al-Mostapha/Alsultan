#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Task/Task.Enum.h"
#include "Building.Enum.h"
#include "Module/Science/Science.Enum.h"
#include "Module/Army/Army.Enum.h"

struct RBuildingMoreInfoData;
class BuildingRead{
  struct RNextUnlockedData{
    EBuilding _Building = EBuilding::None;
    EScience _Science = EScience::None;
    EArmy _Army = EArmy::None;
    int32 _unlockLvl = 0;
    bool _IsValid;
  };
public:
  static BuildingRead* Get();
  GString GetName(EBuilding p_Building);
  GString GetName(int32 p_Building);
  GString GetBrief(EBuilding p_Building);
  GString GetDes(EBuilding p_Building);
  GString GetWarDes(EBuilding p_Building);
  GString GetStarDes(EBuilding p_Building);
  GString GetUpgradeDes(EBuilding p_Building);
  GString GetUpgradeStarDes(EBuilding p_Building);
  GString GetIcon(EBuilding p_Building);
  ETask GetQueueType(EBuilding p_Building);
  GVector<RBuildingMoreInfoData> GetMoreInfoData(EBuildingIndex p_Building);
  GVector<RBuildingMoreInfoData> GetUpgradeInfoData(EBuildingIndex p_Building, bool l_IsStar);
  RNextUnlockedData GetNextUnlockedInfo(EBuilding p_Building, int32 p_Lvl){ return RNextUnlockedData();}
};