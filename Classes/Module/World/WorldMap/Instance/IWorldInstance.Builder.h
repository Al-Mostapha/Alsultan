#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Type.h"

class IWorldMapInstance;
class WorldMapCell;

class IWorldInstanceBuilder{
  public:
    virtual IWorldMapInstance *AddMapInstance(RWorldInstanceConfig::RLod, WorldMapCell *, RWorldInstanceData) = 0;
    void AddWorldInstance(WorldMapCell *, IWorldMapInstance *){};
};