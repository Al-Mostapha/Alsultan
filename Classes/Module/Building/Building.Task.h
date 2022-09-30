#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/Task.Type.h"
#include "Building.Enum.h"

struct RBuildingTask : public ITask {
  EBuildingType BuildingType = EBuildingType::None;
  EBuildingPlace BuildingPlace = EBuildingPlace::None;
};

class BuildingTask {
public:
  static BuildingTask *Get();
  GVector<RBuildingTask> &getBuildingTask();
};