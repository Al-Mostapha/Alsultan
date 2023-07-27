#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Type.h"

class IWorldMapInstance;
class WorldMapCell;

class IWorldInstanceBuilder{
  public:
    GString _LayerName;
    EWorldLodDef _Lod;
    GVector<WorldMapCell *> _MapViewCellArray;


    virtual void Ctor() = 0;
    void Init(GVector<WorldMapCell *> pCellArray);
    void InitMapCell(WorldMapCell *pCell);
    virtual IWorldMapInstance *AddMapInstance(RWorldInstanceConfigLod p, WorldMapCell *, RWorldInstanceData) = 0;
    void AddWorldInstance(WorldMapCell *, IWorldMapInstance *){};
};