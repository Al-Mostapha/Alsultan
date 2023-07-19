#include "WorldInstance.Factory.h"
#include "IWorldInstance.Builder.h"
#include "WorldInstance.Type.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"

IWorldMapInstance *AddWorldInstanceNormale(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfig::RLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);
  if(lWorldInstance){
    lWorldInstance->InitInstanceData(pData._ObjData);
  }
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldInstanceClass(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfig::RLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }
  
  if(EMapObjTypeDef::mapObjTypeChristmasTree == pData._TileInstanceType || EMapObjTypeDef::mapTypeRamadanFeast == pData._TileInstanceType){
    lWorldInstance->InitInstanceData(pData._Class,pData._ObjData);
    lWorldInstance->SetTilePoint(pData._TilePoint);
    lWorldInstance->SetInstanceID(pData._TileInstanceID);
  }else{
    lWorldInstance->InitInstanceData(pData._Class, pData._ObjData);
  }
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldInstanceObjID(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfig::RLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, int32 pObjID){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }

  lWorldInstance->InitInstanceData(pData._Class, pData._ObjData, pObjID);
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldBuilding(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfig::RLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, int32 pObjID){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }
  //worldBuilding:initCityData(worldInstanceData.objData)
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldMonster(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfig::RLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, int32 pObjID){
  auto lWorldMonster = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldMonster){
    return nullptr;
  }
  
  auto lObjData = static_cast<RWorldMonsterObjData *>(pData._ObjData);
  auto lShowTilePoint = pData._TilePoint;
  Vec2 lFaceTilePoint;
  if(lObjData->_FaceTo == EMapNpcFaceTypeDef::LeftBottom){
    lFaceTilePoint = {lShowTilePoint.x, lFaceTilePoint.y + 1};
  }else{
    lFaceTilePoint = {lShowTilePoint.x + 1, lFaceTilePoint.y};
  }
  
  auto lBeginPoint = pCell->GetPointWithTile(lShowTilePoint);
  auto lEndPoint = pCell->GetPointWithTile(lFaceTilePoint);
  // local _, imgNameAngle, isFlipX = worldMapFunction.getMonsterImgAngel(beginPoint, endPoint)
  // worldMonster:initInstanceData(worldInstanceData.class, imgNameAngle, isFlipX, worldInstanceData.objData)
  // if worldInstanceData.massRef and worldMonster.setMassRef then
  //   worldMonster:setMassRef(worldInstanceData.massRef)
  // end
  return lWorldMonster;
}



WorldInstanceFactory *WorldInstanceFactory::Get(){
  static WorldInstanceFactory *lInstance = nullptr;
  if(!lInstance){
    lInstance = new WorldInstanceFactory();
  }
  return lInstance;
}

GTuple<IWorldMapInstance *, bool> WorldInstanceFactory::GetInstanceByType(EWorldInstanceClass pClass, bool pCache){
  return {nullptr, false};
}

int32 WorldInstanceFactory::GetHoldInstaceByType(EMapObjTypeDef pTileInstanceType, EWorldInstanceClass pClass, int32 pClassType){
  return 0;
}

GVector<Vec2> WorldInstanceFactory::GetTilesArrayByInstace(Vec2 pTilePoint, int32 pHoldInstace){
  return {};
}
