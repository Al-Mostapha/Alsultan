#pragma once
#include "IWorldInstance.Builder.h"

class WorldInstanceBuilderNormal : public IWorldInstanceBuilder{
  public:
    static WorldInstanceBuilderNormal *Create();
    void Ctor() override;
    IWorldMapInstance *AddMapInstance(RWorldInstanceConfigLod, WorldMapCell *, RWorldInstanceData) override;
};