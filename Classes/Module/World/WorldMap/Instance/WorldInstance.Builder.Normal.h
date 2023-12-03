#pragma once
#include "Base/Type/XOptional.h"
#include "IWorldInstance.Builder.h"


class WorldInstanceBuilderNormal : public IWorldInstanceBuilder{
  public:
    static WorldInstanceBuilderNormal *Create();
    void Ctor() override;
    IWorldMapInstance *AddMapInstance(RWorldInstanceConfigLod, WorldMapCell *, RWorldInstanceData) override;
    IWorldMapInstance *CreateMapInstance(WorldMapCell *pCell, RInstanceData pInstanceData) override;
    IWorldMapInstance *CreateMapInstanceConfig(WorldMapCell *pCell, RInstanceData pInstanceData, 
      GOpt<RWorldInstanceData> pWorldInstanceData, RWorldInstanceConfig pConfig) override;
};