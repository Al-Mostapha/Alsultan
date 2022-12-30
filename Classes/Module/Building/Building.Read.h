#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/Task.Enum.h"

class BuildingRead{
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
};