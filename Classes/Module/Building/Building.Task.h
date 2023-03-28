#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/ITask.h"
#include "Building.Enum.h"

struct RBuildingTask : public ITask {
  EBuilding BuildingType = EBuilding::None;
  EBuildingIndex BuildingIndex = EBuildingIndex::None;
  EBuilding GetBuildingType() {
    return BuildingType;
  }
  EBuildingIndex GetBuildingIndex() {
    return BuildingIndex;
  }
};

class BuildingTask {
public:
  static BuildingTask *Get();
  GVector<RBuildingTask> &getBuildingTask();
};