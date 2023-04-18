#include "Building.Task.h"

BuildingTask *BuildingTask::Get(){
  BuildingTask *l_Instance = new BuildingTask();
  return l_Instance;
}
GVector<RBuildingTask> _TempForGetBuildingTask;
GVector<RBuildingTask> &BuildingTask::getBuildingTask(){
  return _TempForGetBuildingTask;
}