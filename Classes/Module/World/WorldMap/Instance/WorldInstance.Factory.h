#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Enum.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "WorldInstance.Type.h"

USING_NS_CC;

class IWorldMapInstance;

class WorldInstanceFactory{
  private:
    void InitConfig();
  public: 
    static WorldInstanceFactory *Get();
    GVector<Vec2> GetTilesArrayByInstace(Vec2 pTilePoint, int32 pHoldInstace);
    RWorldInstanceConfig GetConfigByType(EMapObjTypeDef pTileInstanceType);
    GString GetInstanceDataKey(EMapObjTypeDef pTileInstanceType);
    bool IsInstanceHurtDie(EMapObjTypeDef pTileInstanceType);
    int32 GetHoldInstaceByType(EMapObjTypeDef pTileInstanceType, EWorldInstanceClass pClass, int32 pClassType = 0);
    bool IsInstanceDelayTime(EMapObjTypeDef pTileInstanceType);
    GTuple<IWorldMapInstance *, bool> GetInstanceByType(EWorldInstanceClass pClass, bool pCache = false);
    IWorldMapInstance *CreateMapInstance(IWorldInstanceBuilder *pBuilder, WorldMapCell *pCell, RInstanceData pData);
};