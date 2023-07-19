#pragma once
#include "IWorldInstance.Builder.h"

class WorldInstanceBuilderNormal : public IWorldInstanceBuilder{
  public:
    IWorldMapInstance *AddMapInstance(RWorldInstanceConfig::RLod, WorldMapCell *, RWorldInstanceData) override;
};