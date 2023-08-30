#include "WorldInstance.Builder.Normal.h"
#include "IWorldMapInstance.h"
#include "WorldInstance.Factory.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapBuilding.h"

WorldInstanceBuilderNormal *WorldInstanceBuilderNormal::Create(){
  auto lBuilder = new WorldInstanceBuilderNormal();
  lBuilder->Ctor();
  return lBuilder;
}

void WorldInstanceBuilderNormal::Ctor(){
  _Lod = EWorldLodDef::LOD1;
  _LayerName = "LayerLod_1";
}

GTuple<IWorldMapInstance *, bool> GetInstanceByType(RWorldInstanceConfigLod pLodConfig, int32 pClassType = 0){
  auto lClass = pLodConfig._Class;
  if(pClassType && pLodConfig._ClassTable.Contains(pClassType)){
    lClass = pLodConfig._ClassTable[pClassType];
  }
  if(lClass != EWorldInstanceClass::None){
    return WorldInstanceFactory::Get()->GetInstanceByType(lClass, pLodConfig._Cache);
  }
  return {nullptr, false};
};

IWorldMapInstance *WorldInstanceBuilderNormal::AddMapInstance(RWorldInstanceConfigLod pConfig, WorldMapCell *pCell, RWorldInstanceData pData){
  
  auto lTilePoint = pData._TilePoint;
  auto lTileInstanceType = pData._TileInstanceType;
  auto lHoldInstace = WorldInstanceFactory::Get()->GetHoldInstaceByType(lTileInstanceType, pConfig._Class, pData._SubMapType);
  auto [lWorldInstance, lCache] = GetInstanceByType(pConfig, static_cast<int32>(pData._Class));
  auto lInstancePoint = pCell->GetPointWithTile(lTilePoint, lHoldInstace);
  auto lDistance = lTilePoint.distance(Vec2::ZERO);
  auto lLayerType = pConfig._BatchNode;
  
  if(lLayerType != EGrouID::None){
    lWorldInstance->SetBatchNodeGroupID(lLayerType);
  }
  lWorldInstance->setPosition(lInstancePoint);
  lWorldInstance->setLocalZOrder(lDistance);
  AddWorldInstance(pCell, lWorldInstance);
  if(lCache){
    lWorldInstance->release();
  }
  auto lTilesArray = WorldInstanceFactory::Get()->GetTilesArrayByInstace(lTilePoint, lHoldInstace);
  lWorldInstance->SetInstanceType(lTileInstanceType);
  lWorldInstance->SetWorldMapCell(pCell);
  lWorldInstance->SetKingdomID(pCell->_KingdomID);
  lWorldInstance->SetMapTypeClass(pCell->_MapClassType);
  lWorldInstance->SetInstanceID(pData._TileInstanceID);
  lWorldInstance->SetTilesArray(lTilesArray);
  lWorldInstance->SetTilePoint(lTilePoint);
  lWorldInstance->SetHoldInstace(lHoldInstace);
  
  return lWorldInstance;
}

IWorldMapInstance *WorldInstanceBuilderNormal::CreateMapInstance(WorldMapCell * pCell, RInstanceData pInstanceData){
  auto lWorldMapInstance = WorldInstanceFactory::Get()->CreateMapInstance(this, pCell, pInstanceData);
  if(lWorldMapInstance){
    auto lDelayTime = pInstanceData._DelayTime;
    auto lBuildInstance = dynamic_cast<WorldMapBuilding *>(lWorldMapInstance);
    if(lBuildInstance)
      lBuildInstance->ShowInstance(true, lDelayTime);
  }
  return lWorldMapInstance;
}

GOpt<RWorldInstanceConfigLod> GetConfigByType(RWorldInstanceConfig pConfig, EWorldLodDef pLod = EWorldLodDef::LOD1){
  auto lLodConfig = pConfig._Lod;
  if(lLodConfig.Contains(pLod)){
    return lLodConfig[pLod];
  } 
  return {};
}

IWorldMapInstance *WorldInstanceBuilderNormal::
CreateMapInstanceConfig(
  WorldMapCell *pCell, RInstanceData pInstanceData, 
  GOpt<RWorldInstanceData> pWorldInstanceData, RWorldInstanceConfig pConfig
){
  auto lLodConfig = GetConfigByType(pConfig, _Lod);
  if(!lLodConfig){
    return nullptr;
  }
  IWorldMapInstance *lWorldInstance = nullptr;
  auto lCreateFun = lLodConfig->_CreateFun;
  if(lCreateFun){
    lWorldInstance = lCreateFun(this, *lLodConfig, pCell, *pWorldInstanceData, pInstanceData);
    // if(lLodConfig->_Cache){
    //   lWorldInstance->SetCacheStatus(lLodConfig->_Cache);
    // }
  } else{
    cocos2d::log("[instanceFactory] createFun is nil %d", pInstanceData._Type);
  }
  return lWorldInstance;
}