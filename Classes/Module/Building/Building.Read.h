#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/Task.Enum.h"

class BuildingRead{
public:
  static BuildingRead* Get();
  ETask GetQueueType(EBuilding p_Building);
};