#include "Building.Task.h"

BuildingTask *BuildingTask::Get(){
  BuildingTask *l_Instance = new BuildingTask();
  return l_Instance;
}

GVector<RBuildingTask> &BuildingTask::getBuildingTask(){
  return GVector<RBuildingTask>();
}