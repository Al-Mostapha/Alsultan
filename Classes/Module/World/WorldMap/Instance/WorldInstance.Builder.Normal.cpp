#include "WorldInstance.Builder.Normal.h"
#include "IWorldMapInstance.h"
#include "WorldInstance.Factory.h"
#include "Module/World/WorldMap/View/WorldMapCell.h"

GTuple<IWorldMapInstance *, bool> GetInstanceByType(RWorldInstanceConfig::RLod pLodConfig, int32 pClassType = 0){
  auto lClass = pLodConfig._Class;
  if(pClassType && pLodConfig._ClassTable.Contains(pClassType)){
    lClass = pLodConfig._ClassTable[pClassType];
  }
  if(lClass != EWorldInstanceClass::None){
    return WorldInstanceFactory::Get()->GetInstanceByType(lClass, pLodConfig._Cache);
  }
  return {nullptr, false};
};

IWorldMapInstance *WorldInstanceBuilderNormal::AddMapInstance(RWorldInstanceConfig::RLod pConfig, WorldMapCell *pCell, RWorldInstanceData pData){
  
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
  lWorldInstance->SetPosition(lInstancePoint);
  lWorldInstance->SetLocalZOrder(lDistance);
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