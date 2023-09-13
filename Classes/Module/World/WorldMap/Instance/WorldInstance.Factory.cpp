#include "WorldInstance.Factory.h"
#include "InstanceLodCfgShow.h"
#include "IWorldInstance.Builder.h"
#include "WorldInstance.Type.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Func.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapAllianceBuild.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapAllianceResource.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapAncientTreasure.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapBuilding.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapResource.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapMonster.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapCastle.h"
#include "Module/World/WorldMap/Instance/Unit/WorldMapLegendLord.h"

GHashMap<EMapObjTypeDef, RWorldInstanceConfig> _WorldInstanceConfig;

IWorldMapInstance *AddWorldInstanceNormale(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);
  if(lWorldInstance){
    lWorldInstance->InitInstanceData(pData._ObjData);
  }
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldInstanceClass(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }
  
  if(EMapObjTypeDef::mapObjTypeChristmasTree == pData._TileInstanceType || EMapObjTypeDef::mapTypeRamadanFeast == pData._TileInstanceType){
    lWorldInstance->InitInstanceData(static_cast<int32>(pData._Class), pData._ObjData);
    lWorldInstance->SetTilePoint(pData._TilePoint);
    lWorldInstance->SetInstanceID(pData._TileInstanceID);
  }else{
    lWorldInstance->InitInstanceData(static_cast<int32>(pData._Class), pData._ObjData);
  }
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldInstanceObjID(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData pObjData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }

  lWorldInstance->InitInstanceData(static_cast<int32>(pData._Class), pData._ObjData, pObjData._ObjID);
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldBuilding(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }
  auto lWorldBuilding = dynamic_cast<WorldMapBuilding *>(lWorldInstance);
  if(lWorldBuilding){
    lWorldBuilding->InitCityData(pData._ObjData);
  }
  return lWorldInstance;
}

IWorldMapInstance *
AddWorldMonster(
  IWorldInstanceBuilder *pBuilder, 
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData){
  auto lWorldMonster = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldMonster){
    return nullptr;
  }
  
  auto lObjData = static_cast<RMonsterInitData *>(pData._ObjData);
  auto lShowTilePoint = pData._TilePoint;
  Vec2 lFaceTilePoint;
  if(lObjData->_FaceTo == EMapNpcFaceTypeDef::LeftBottom){
    lFaceTilePoint = {lShowTilePoint.x, lFaceTilePoint.y + 1};
  }else{
    lFaceTilePoint = {lShowTilePoint.x + 1, lFaceTilePoint.y};
  }
  
  auto lBeginPoint = pCell->GetPointWithTile(lShowTilePoint);
  auto lEndPoint = pCell->GetPointWithTile(lFaceTilePoint);
  auto [_, imgNameAngle, isFlipX] = WorldMapFunction::Get()->GetMonsterImgAngel(lBeginPoint, lEndPoint);
  lWorldMonster->InitInstanceData(static_cast<int32>(pData._Class), imgNameAngle, isFlipX, lObjData);
  // if worldInstanceData.massRef and worldMonster.setMassRef then
  //   worldMonster:setMassRef(worldInstanceData.massRef)
  // end
  return lWorldMonster;
}



WorldInstanceFactory *WorldInstanceFactory::Get(){
  static WorldInstanceFactory *lInstance = nullptr;
  if(!lInstance){
    lInstance = new WorldInstanceFactory();
    lInstance->InitConfig();
  }
  return lInstance;
}

GTuple<IWorldMapInstance *, bool> WorldInstanceFactory:: GetInstanceByType(const RWorldInstanceConfigLod &pLodConfig, std::function<IWorldMapInstance *()> pCtorFunc, bool pCache){
  // local worldInstance
  // if class then
  //   if cache then
  //     worldInstance = instanceCacheMgr.getInstance(class)
  //     if worldInstance then
  //       return worldInstance, true
  //     end
  //   end
  //   worldInstance = include(class).new()
  //   worldInstance:setClassType(class)
  // end
  // return worldInstance
  return {pCtorFunc(), false};
  return {nullptr, false};
}

int32 WorldInstanceFactory::GetHoldInstaceByType(EMapObjTypeDef pTileInstanceType, EWorldInstanceClass pClass, int32 pClassType){
  auto lHoldInstace = 1;
  if(_WorldInstanceConfig.Contains(pTileInstanceType)){
    auto lConfig = _WorldInstanceConfig[pTileInstanceType];
    lHoldInstace = lConfig._HoldInstace;
    if(lConfig._HoldInstaceTable.Contains(static_cast<int32>(pClass))){
      lHoldInstace = lConfig._HoldInstaceTable[static_cast<int32>(pClass)];
    }else if(lConfig._HoldInstaceTable.Contains(pClassType)){
      lHoldInstace = lConfig._HoldInstaceTable[pClassType];
    }
  }
  return lHoldInstace;
}



GVector<Vec2> WorldInstanceFactory::GetTilesArrayByInstace(Vec2 pTilePoint, int32 pHoldInstace){
  return {};
}


void WorldInstanceFactory::InitConfig(){
  RWorldInstanceConfig *lV;

  auto lEmplace = [](EMapObjTypeDef pType){
    _WorldInstanceConfig.emplace(pType, RWorldInstanceConfig());
    return &(_WorldInstanceConfig[pType]);
  };

  {
    lV = lEmplace(EMapObjTypeDef::mapObjTypePlayer);
    lV->_HoldInstace = 2;
    lV->_FromKey = "user";
    lV->_DelayTime = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3OrSelfLegend, InstanceLodCfgShow::Get());

    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
    lV->_Lod[EWorldLodDef::LOD3] = RWorldInstanceConfigLod();
    lV->_Lod[EWorldLodDef::LOD4] = RWorldInstanceConfigLod();

    lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBuilding;
    lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::castleBatchNode;
    lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldBuilding;
    lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = IWorldMapInstance::Create<WorldMapBuilding>;
    lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

    lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapBuildingLod2;
    lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

    lV->_Lod[EWorldLodDef::LOD3]._Class = EWorldInstanceClass::WorldMapBuildingLod;
    lV->_Lod[EWorldLodDef::LOD3]._LodLayerFun = CC_CALLBACK_2(InstanceLodCfgShow::SelfLayerLod3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD3]._Cache = true;

    lV->_Lod[EWorldLodDef::LOD4]._Class = EWorldInstanceClass::WorldMapBuildingLod;
    lV->_Lod[EWorldLodDef::LOD4]._LodLayerFun = CC_CALLBACK_2(InstanceLodCfgShow::SelfLayerLod4, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD4]._Cache = true;
  }

  {
    lV =  lEmplace(EMapObjTypeDef::mapObjTypeLegendLord);
    lV->_HoldInstace = 3;
    lV->_FromKey = "data";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
    lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapLegendLord;
    lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = IWorldMapInstance::Create<WorldMapLegendLord>;
    lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::palaceBatchNode;
    lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
    lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
  }

  lV = lEmplace(EMapObjTypeDef::mapObjTypeRemainsWar);
  lV->_HoldInstace = 3;
  lV->_FromKey = "data";

  lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRemainsWar;
  lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::palaceBatchNode;
  lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeCastale);
  lV->_HoldInstace = 3;
  lV->_FromKey = "castle";
  lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::AlwaysShow, InstanceLodCfgShow::Get());

  lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapCastle;
  lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::palaceBatchNode;
  lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodCastle;
  lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::CASTLE;
  lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeBattery);
  lV->_HoldInstace = 2;
  lV->_FromKey = "battery";
  lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
  lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBattery;
  lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::batteryBatchNode;
  lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
  
  lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBattery;
  lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::CASTLE;
  lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeFortress);
  lV->_HoldInstace = 2;
  lV->_FromKey = "fortress";
  lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapFortress;
  lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
  lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;


  lV = lEmplace(EMapObjTypeDef::mapObjTypeResource);
    lV->_HoldInstace = 1;
    lV->_FromKey = "resource";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3OrSelf, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapResource;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapResourceLod2;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD3] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD3]._Class = EWorldInstanceClass::WorldMapResourceLod;
      lV->_Lod[EWorldLodDef::LOD3]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeCampsite);
    lV->_HoldInstace = 1;
    lV->_FromKey = "camp";
    lV->_DelayTime = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD2OrSelf, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapCampsite;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodCampsite;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeNpc);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::MonsterShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonster;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = IWorldMapInstance::Create<WorldMapMonster>;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

    lV = lEmplace(EMapObjTypeDef::nebulaNpc);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::MonsterShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonsterNebula;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterNebulaBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = IWorldMapInstance::Create<WorldMapMonster>;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

  lV = lEmplace(EMapObjTypeDef::mapTypeHuntFair);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::NpcShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonsterSnowMan;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;
    
  lV = lEmplace(EMapObjTypeDef::mapTypeSemluk);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::NpcShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonsterSemluk;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterSemlukBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

  lV = lEmplace(EMapObjTypeDef::mapObjSeaMonsterInvade);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::NpcShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonsterSea;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterSeaBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

  lV = lEmplace(EMapObjTypeDef::mapTypeMonsterFiesta);
    lV->_HoldInstace = 1;
    lV->_FromKey = "monsterFiesta";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::NpcShow, InstanceLodCfgShow::Get());
    lV->_IsHurtDie = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMonsterFiesta;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::monsterFiestaBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeBoss);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._ClassTable = {
        {
          {
            static_cast<int32>(EBossType::windTowerBoss), 
            {EWorldInstanceClass::WorldMapBossWindTower, /*IWorldMapInstance::Create<WorldMapBossWindTower>*/nullptr}
          }
        }
      };
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeHeroBattleBoss1);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
  
  lV = lEmplace(EMapObjTypeDef::mapTypeHeroBattleBoss2);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      
  lV = lEmplace(EMapObjTypeDef::mapObjTypeSuperResource);
    lV->_HoldInstace = 2;
    lV->_FromKey = "superRes";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::AlwaysShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapAllianceResource;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodAlliance;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

    lV = lEmplace(EMapObjTypeDef::mapObjTypeRelics);
    lV->_HoldInstace = 2;
    lV->_FromKey = "relics";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRemains;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = nullptr;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeTreasure);
    lV->_HoldInstace = 1;
    lV->_FromKey = "treasure";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapTreasure;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeChest);
    lV->_HoldInstace = 1;
    lV->_FromKey = "chest";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapChest;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
  
  lV = lEmplace(EMapObjTypeDef::mapTypeTreasureBowl);
    lV->_HoldInstace = 2;
    lV->_FromKey = "treasureBowl";
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapTreasureBowl;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeBattlefieldSite);
    lV->_HoldInstace = 2;
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EMapBattlefieldSiteTypeDef::ObjTypeBigPyramid), 3},
      {static_cast<int32>(EMapBattlefieldSiteTypeDef::TypeAWArmory), 1}
    }};
    lV->_FromKey = "battlefieldSite";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBattlefieldSite;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::pyramidBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
  
  lV = lEmplace(EMapObjTypeDef::mapObjTypeEscort);
    lV->_HoldInstace = 2;
    lV->_FromKey = "escort";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapEscort;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::NPC;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeAllianceBuild);
    lV->_HoldInstace = 2;
    lV->_FromKey = "build";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::AllianceBuild, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapAllianceBuild;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._ConstructorFun = IWorldMapInstance::Create<WorldMapAllianceBuild>;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapAllianceBuildLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeMine);
    lV->_HoldInstace = 2;
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EMapAllianceBuildType::Flag), 1}
    }};
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLod5, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapMineBuild;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodMine;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::ALLIANCERES;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::stronghold);
    lV->_HoldInstace = 2;
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EMapAllianceBuildType::Flag), 1}
    }};
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLod5, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapStronghold;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodStrong;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::ALLIANCESTRONG;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
  
  lV = lEmplace(EMapObjTypeDef::mapObjTypeKingdomLevelBuild);
    lV->_HoldInstace = 2;
    lV->_FromKey = "build";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapKingdomLvTower;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBattery;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeKingdomLevelBuild);
    lV->_HoldInstace = 2;
    lV->_FromKey = "build";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapPyramidGloryBuild;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBattery;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::CASTLE;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapObjTypeKingdomLevelBuild);
    lV->_HoldInstace = 2;
    lV->_FromKey = "data";
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EMapNewTrialBuildType::Castle), 5}
    }};
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._ClassTable = {{
        {
          static_cast<int32>(EMapNewTrialBuildType::Castle),
          {EWorldInstanceClass::WorldMapNewTrialCity, /*IWorldMapInstance::Create<WorldMapNewTrialCity>*/nullptr}
        },
        {
          static_cast<int32>(EMapNewTrialBuildType::Battery),
          {EWorldInstanceClass::WorldMapTrialBattery, /*IWorldMapInstance::Create<WorldMapTrialBattery>*/nullptr}
        }
      }};
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
      
  lV = lEmplace(EMapObjTypeDef::mapObjTypeChristmasTree);
    lV->_HoldInstace = 2;
    lV->_FromKey = "tree";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapTreasureBowl;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeWrathBeast);
    lV->_HoldInstace = 2;
    lV->_FromKey = "wrathBeast";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD6, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapWrathBeast;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::wrathBeastBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::NPC;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRamadanFeast);
    lV->_HoldInstace = 1;
    lV->_FromKey = "feastData";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapFeast;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::feastBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeEndlessTrialsPortal);
    lV->_HoldInstace = 2;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLod5, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapProtal;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::ALLIANCESTRONG;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeATBuilding);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapAncientTreasure;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;

  lV = lEmplace(EMapObjTypeDef::mapTypeWerewolf);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeFireTreasure);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRedTreasureMap;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeWarTreasure);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapDrumAndVuln;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRadianceWarResource);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRadianceWarResource;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRadianceWarPalace);
    lV->_HoldInstace = 5;
    lV->_FromKey = "data";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRadianceWarPalace;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRadianceWarGate);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRadianceWarGate;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRadianceWarBeacon);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapRadianceWarBeacon;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeRadianceWarBeacon);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapAnniversaryCamp;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeLostRuins);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapLostRuins;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;


  lV = lEmplace(EMapObjTypeDef::mapTypeWindTower);
    lV->_HoldInstace = 2;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod(); 
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapWindTower;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeAtlantisWarBuilding);
    lV->_HoldInstace = 2;
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EWorldTypeServerDef::subMapTypeAtlantisWarPalace), 3},
      {static_cast<int32>(EWorldTypeServerDef::subMapTypeAtlantisWarFort), 3}
    }};
    lV->_FromKey = "data";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::AlwaysShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapAtlantisWar;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapAtlantisWarLod;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::NEBULA;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD4] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD4]._Class = EWorldInstanceClass::WorldMapAtlantisWarLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = false;

  lV = lEmplace(EMapObjTypeDef::mapTypeAtlantisWarBoss);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBossAtlantis;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapBossAtlantisLod;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::NEBULA;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD4] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD4]._Class = EWorldInstanceClass::WorldMapBossAtlantisLod;
      lV->_Lod[EWorldLodDef::LOD4]._LodLayer = ELodLayer::NEBULA_4;
      lV->_Lod[EWorldLodDef::LOD4]._Cache = false;

  lV = lEmplace(EMapObjTypeDef::wastelandBoss);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::mapTypeSnowWolfLost);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapSnowWolfLost;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::starTreasure);
    lV->_HoldInstace = 1;
    lV->_FromKey = "npc";
    lV->_DelayTime = true;
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapStarTreasure;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceClass;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::nebulaWarBuilding);
    lV->_HoldInstace = 2;
    lV->_HoldInstaceTable = {{
      {static_cast<int32>(EWorldTypeServerDef::subTypeNebulaWarPalace), 3}
    }};
    lV->_FromKey = "data";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::AlwaysShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapNebulaWar;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapNebulaWarLod;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::NEBULA;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = false;
    lV->_Lod[EWorldLodDef::LOD4] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD4]._Class = EWorldInstanceClass::WorldMapNebulaWarLod;
      lV->_Lod[EWorldLodDef::LOD4]._LodLayer = ELodLayer::NEBULA_4;
      lV->_Lod[EWorldLodDef::LOD4]._Cache = false;

  lV = lEmplace(EMapObjTypeDef::nebulaWarMine);
    lV->_HoldInstace = 1;
    lV->_FromKey = "data";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::NebulaWarMineShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapNebulaWarMine;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildRadiance;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapResourceLod2;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::fireDragon1);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::fireDragon2);
    lV->_HoldInstace = 2;
    lV->_FromKey = "boss";
    lV->_DelayTime = true;
    lV->_IsHurtDie = true;
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::BossShow, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapBoss;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::bossBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodBoss;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::BOSS;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV = lEmplace(EMapObjTypeDef::desertMeteorite);
    lV->_HoldInstace = 2;
    lV->_FromKey = "desertMeteorite";
    lV->_LodShowFun = CC_CALLBACK_3(InstanceLodCfgShow::LessLOD3, InstanceLodCfgShow::Get());
    lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapDesertMeteorite;
      lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::buildingBatchNode;
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceNormale;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapIconLodInstance;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

}

RWorldInstanceData GetWorldMapInstanceData_imp(WorldMapCell *pCell, RInstanceData pInstanceData, RWorldInstanceConfig pConfig){
  
  auto lKingdomID = pInstanceData._KID ? pInstanceData._KID : pCell->_KingdomID;
  RWorldInstanceData lWorldInstanceData;
  lWorldInstanceData._TileInstanceType = pInstanceData._Type;
  lWorldInstanceData._TilePoint = Vec2(pInstanceData._X, pInstanceData._Y);
  lWorldInstanceData._TileInstanceID = pInstanceData._ID;
  lWorldInstanceData._TileInstanceKingdomID = lKingdomID;
  lWorldInstanceData._MassRef = pInstanceData._Ref;

  //   if config.fromKey then
  //     worldInstanceData.objData = instanceData[config.fromKey] or {}
  //   end
  lWorldInstanceData._Class = pInstanceData._Class;
  lWorldInstanceData._SubMapType = pInstanceData._SubMapType;
  lWorldInstanceData._ObjID = pInstanceData._ObjID;
  //lWorldInstanceData._ObjData._SettingID = pInstanceData._SettingID;


  /*TODO: Remove this line*/
  lWorldInstanceData._ObjData = pInstanceData._ObjData;

  return lWorldInstanceData;
}


IWorldMapInstance *WorldInstanceFactory::CreateMapInstance(
  IWorldInstanceBuilder *pBuilder, WorldMapCell *pCell, RInstanceData pInstanceData
){
  auto lInstanceType = pInstanceData._Type;
  IWorldMapInstance *lWorldInstance = nullptr;
  RWorldInstanceConfig lConfig;
  if(_WorldInstanceConfig.Contains(lInstanceType)){
    lConfig = _WorldInstanceConfig[lInstanceType];
    auto lWorldInstanceData = pInstanceData._WorldInstanceData;
    if(!lWorldInstanceData){
      lWorldInstanceData = GetWorldMapInstanceData_imp(pCell, pInstanceData, lConfig);
      pInstanceData._WorldInstanceData = lWorldInstanceData;
    }
    lWorldInstance = pBuilder->CreateMapInstanceConfig(pCell, pInstanceData, lWorldInstanceData, lConfig);
  }
  return lWorldInstance;
}