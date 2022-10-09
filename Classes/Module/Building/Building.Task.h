#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/Task.Type.h"
#include "Building.Enum.h"

struct RBuildingTask : public ITask {
  EBuilding BuildingType = EBuilding::None;
  EBuildingIndex BuildingPlace = EBuildingIndex::None;
};

class BuildingTask {
public:
  static BuildingTask *Get();
  GVector<RBuildingTask> &getBuildingTask();
};