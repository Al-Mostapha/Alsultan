#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Enum.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

class IWorldMapInstance;

class WorldInstanceFactory{
  public: 
    static WorldInstanceFactory *Get();
    GTuple<IWorldMapInstance *, bool> GetInstanceByType(EWorldInstanceClass pClass, bool pCache = false);
    int32 GetHoldInstaceByType(EMapObjTypeDef pTileInstanceType, EWorldInstanceClass pClass, int32 pClassType = 0);
    GVector<Vec2> GetTilesArrayByInstace(Vec2 pTilePoint, int32 pHoldInstace);
};