#include "Building.Read.h"

BuildingRead* BuildingRead::Get()
{
  static BuildingRead* s_BuildingRead = new BuildingRead();
  return s_BuildingRead;
}

ETask BuildingRead::GetQueueType(EBuilding p_Building){
  return ETask::None;
}