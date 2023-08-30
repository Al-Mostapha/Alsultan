#include "WorldInstance.Factory.h"
#include "InstanceLodCfgShow.h"
#include "IWorldInstance.Builder.h"
#include "WorldInstance.Type.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Func.h"

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
  const RWorldInstanceConfigLod &pConfig, 
  WorldMapCell *pCell, RWorldInstanceData pData, RInstanceData pObjData){
  auto lWorldInstance = pBuilder->AddMapInstance(pConfig, pCell, pData);

  if(!lWorldInstance){
    return nullptr;
  }

  lWorldInstance->InitInstanceData(pData._Class, pData._ObjData, pObjData._ObjID);
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
  //worldBuilding:initCityData(worldInstanceData.objData)
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
  auto [_, imgNameAngle, isFlipX] = WorldMapFunction::Get()->GetMonsterImgAngel(lBeginPoint, lEndPoint);
  lWorldMonster->InitInstanceData(pData._Class, imgNameAngle, isFlipX, lObjData);
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

GTuple<IWorldMapInstance *, bool> WorldInstanceFactory::GetInstanceByType(EWorldInstanceClass pClass, bool pCache){
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

  lV =lEmplace(EMapObjTypeDef::mapObjTypePlayer);

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
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

  lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapBuildingLod2;
  lV->_Lod[EWorldLodDef::LOD2]._Cache = true;

  lV->_Lod[EWorldLodDef::LOD3]._Class = EWorldInstanceClass::WorldMapBuildingLod;
  lV->_Lod[EWorldLodDef::LOD3]._LodLayerFun = CC_CALLBACK_2(InstanceLodCfgShow::SelfLayerLod3, InstanceLodCfgShow::Get());
  lV->_Lod[EWorldLodDef::LOD3]._Cache = true;

  lV->_Lod[EWorldLodDef::LOD4]._Class = EWorldInstanceClass::WorldMapBuildingLod;
  lV->_Lod[EWorldLodDef::LOD4]._LodLayerFun = CC_CALLBACK_2(InstanceLodCfgShow::SelfLayerLod4, InstanceLodCfgShow::Get());
  lV->_Lod[EWorldLodDef::LOD4]._Cache = true;

  lV =  lEmplace(EMapObjTypeDef::mapObjTypeLegendLord);
  lV->_HoldInstace = 3;
  lV->_FromKey = "data";
  lV->_Lod[EWorldLodDef::LOD1] = RWorldInstanceConfigLod();
  lV->_Lod[EWorldLodDef::LOD1]._Class = EWorldInstanceClass::WorldMapLegendLord;
  lV->_Lod[EWorldLodDef::LOD1]._BatchNode = EGrouID::palaceBatchNode;
  lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldInstanceObjID;
  lV->_Lod[EWorldLodDef::LOD1]._Cache = true;

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
      lV->_Lod[EWorldLodDef::LOD1]._CreateFun = AddWorldMonster;
      lV->_Lod[EWorldLodDef::LOD1]._Cache = true;
    lV->_Lod[EWorldLodDef::LOD2] = RWorldInstanceConfigLod();
      lV->_Lod[EWorldLodDef::LOD2]._Class = EWorldInstanceClass::WorldMapMonsterLod;
      lV->_Lod[EWorldLodDef::LOD2]._Cache = true;
      lV->_Lod[EWorldLodDef::LOD2]._LodLayer = ELodLayer::MONSTER;

  //   [gMapObjTypeDef.nebulaNpc] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.monsterShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMonsterNebula",
  //         batchNode = batchNode.monsterNebulaBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapMonsterLod",
  //         lodLayer = LOD_LAYER_MONSTER,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeHuntFair] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.npcShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMonsterSnowMan",
  //         batchNode = batchNode.monsterBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapMonsterLod",
  //         lodLayer = LOD_LAYER_MONSTER,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeSemluk] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.npcShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMonsterSemluk",
  //         batchNode = batchNode.monsterSemlukBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapMonsterLod",
  //         lodLayer = LOD_LAYER_MONSTER,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjSeaMonsterInvade] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.npcShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMonsterSea",
  //         batchNode = batchNode.monsterSeaBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapMonsterLod",
  //         lodLayer = LOD_LAYER_MONSTER,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeMonsterFiesta] = {
  //     holdInstace = 1,
  //     fromKey = "monsterFiesta",
  //     lodShowFun = lodShow.npcShow,
  //     isHurtDie = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMonsterFiesta",
  //         batchNode = batchNode.monsterFiestaBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapMonsterLod",
  //         lodLayer = LOD_LAYER_MONSTER,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeBoss] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         classTable = {
  //           [gBossType.windTowerBoss] = "worldMapBossWindTower"
  //         },
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeHeroBattleBoss1] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeHeroBattleBoss2] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeSuperResource] = {
  //     holdInstace = 2,
  //     fromKey = "superRes",
  //     lodShowFun = lodShow.alwaysShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapAllianceResource",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodAlliance",
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeRelics] = {
  //     holdInstace = 2,
  //     fromKey = "relics",
  //     lodShowFun = lodShow.lessLOD3,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRemains",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodInstance",
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeTreasure] = {
  //     holdInstace = 1,
  //     fromKey = "treasure",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapTreasure",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeChest] = {
  //     holdInstace = 1,
  //     fromKey = "chest",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapChest",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeTreasureBowl] = {
  //     holdInstace = 2,
  //     fromKey = "treasureBowl",
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapTreasureBowl",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeBattlefieldSite] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gMapBattlefieldSiteTypeDef.subMapObjTypeBigPyramid] = 3,
  //       [gMapBattlefieldSiteTypeDef.subMapTypeAWArmory] = 1
  //     },
  //     fromKey = "battlefieldSite",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBattlefieldSite",
  //         batchNode = batchNode.pyramidBatchNode,
  //         createFun = addWorldInstanceObjID,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeEscort] = {
  //     holdInstace = 2,
  //     fromKey = "escort",
  //     lodShowFun = lodShow.lessLOD3,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapEscort",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodInstance",
  //         lodLayer = LOD_LAYER_NPC,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeAllianceBuild] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gMapAllianceBuildType.subTypeAllianceFlag] = 1
  //     },
  //     fromKey = "build",
  //     delayTime = true,
  //     lodShowFun = lodShow.allianceBuild,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapAllianceBuild",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = false
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapAllianceBuildLod",
  //         lodLayer = LOD_LAYER.LOD_LAYER_ALLIANCERES,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeMine] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gMapAllianceBuildType.subTypeAllianceFlag] = 1
  //     },
  //     fromKey = "data",
  //     delayTime = true,
  //     lodShowFun = lodShow.lessLOD5,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapMineBuild",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodMine",
  //         lodLayer = LOD_LAYER.LOD_LAYER_ALLIANCERES,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.stronghold] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gMapAllianceBuildType.subTypeAllianceFlag] = 1
  //     },
  //     fromKey = "data",
  //     delayTime = true,
  //     lodShowFun = lodShow.lessLOD5,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapStronghold",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodStrong",
  //         lodLayer = LOD_LAYER.LOD_LAYER_ALLIANCESTRONG,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeKingdomLevelBuild] = {
  //     holdInstace = 2,
  //     fromKey = "build",
  //     lodShowFun = lodShow.lessLOD3,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapKingdomLvTower",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = false
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBattery",
  //         lodLayer = LOD_LAYER_CASTLE,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypePyramidGloryBuild] = {
  //     holdInstace = 2,
  //     fromKey = "build",
  //     lodShowFun = lodShow.lessLOD3,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapPyramidGloryBuild",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = false
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBattery",
  //         lodLayer = LOD_LAYER_CASTLE,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjNewTrialCity] = {
  //     holdInstace = 2,
  //     fromKey = "data",
  //     holdInstaceTable = {
  //       [gMapNewTrialBuildType.subMapTypeDVWCastle] = 5
  //     },
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         classTable = {
  //           [gMapNewTrialBuildType.subMapTypeDVWCastle] = "worldMapNewTrialCity",
  //           [gMapNewTrialBuildType.subMapTypeDVWBattery] = "worldMapTrialBattery"
  //         },
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapObjTypeChristmasTree] = {
  //     holdInstace = 2,
  //     fromKey = "tree",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapTreasureBowl",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeWrathBeast] = {
  //     holdInstace = 2,
  //     fromKey = "wrathBeast",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.lessLOD6,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapWrathBeast",
  //         batchNode = batchNode.wrathBeastBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_NPC,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeRamadanFeast] = {
  //     holdInstace = 1,
  //     fromKey = "feastData",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapFeast",
  //         batchNode = batchNode.feastBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeEndlessTrialsPortal] = {
  //     holdInstace = 2,
  //     lodShowFun = lodShow.lessLOD5,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapProtal",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceObjID,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodInstance",
  //         lodLayer = LOD_LAYER.LOD_LAYER_ALLIANCESTRONG,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeATBuilding] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapAncientTreasure",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeWerewolf] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeFireTreasure] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRedTreasureMap",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeWarTreasure] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapDrumAndVuln",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeRadianceWarResource] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRadianceWarResource",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeRadianceWarPalace] = {
  //     holdInstace = 5,
  //     fromKey = "data",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRadianceWarPalace",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeRadianceWarGate] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRadianceWarGate",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeRadianceWarBeacon] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapRadianceWarBeacon",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapType20Campfire] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapAnniversaryCamp",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeLostRuins] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapLostRuins",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeWindTower] = {
  //     holdInstace = 2,
  //     fromKey = "npc",
  //     delayTime = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapWindTower",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodInstance",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeAtlantisWarBuilding] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gWorldTypeServerDef.subMapTypeAtlantisWarPalace] = 3,
  //       [gWorldTypeServerDef.subMapTypeAtlantisWarFort] = 3
  //     },
  //     fromKey = "data",
  //     lodShowFun = lodShow.alwaysShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapAtlantisWar",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = false
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapAtlantisWarLod",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA,
  //         cache = false
  //       },
  //       [worldLodDef.LOD4] = {
  //         class = "worldMapAtlantisWarLod4",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA_4,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeAtlantisWarBoss] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBossAtlantis",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapBossAtlantisLod",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA,
  //         cache = false
  //       },
  //       [worldLodDef.LOD4] = {
  //         class = "worldMapBossAtlantisLod4",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA_4,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.wastelandBoss] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.mapTypeSnowWolfLost] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapSnowWolfLost",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.starTreasure] = {
  //     holdInstace = 1,
  //     fromKey = "npc",
  //     delayTime = true,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapStarTreasure",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceClass,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.nebulaWarBuilding] = {
  //     holdInstace = 2,
  //     holdInstaceTable = {
  //       [gWorldTypeServerDef.subTypeNebulaWarPalace] = 3
  //     },
  //     fromKey = "data",
  //     lodShowFun = lodShow.alwaysShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapNebulaWar",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = false
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapNebulaWarLod",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA,
  //         cache = false
  //       },
  //       [worldLodDef.LOD4] = {
  //         class = "worldMapNebulaWarLod",
  //         lodLayer = LOD_LAYER.LOD_LAYER_NEBULA_4,
  //         cache = false
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.nebulaWarMine] = {
  //     holdInstace = 1,
  //     fromKey = "data",
  //     lodShowFun = lodShow.nebulaWarMineShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapNebulaWarMine",
  //         batchNode = batchNode.buildRadiance,
  //         createFun = addWorldInstanceObjID,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapResourceLod2",
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.fireDragon1] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.fireDragon2] = {
  //     holdInstace = 2,
  //     fromKey = "boss",
  //     delayTime = true,
  //     isHurtDie = true,
  //     lodShowFun = lodShow.bossShow,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapBoss",
  //         batchNode = batchNode.bossBatchNode,
  //         createFun = addWorldMonster,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodBoss",
  //         lodLayer = LOD_LAYER_BOSS,
  //         cache = true
  //       }
  //     }
  //   },
  //   [gMapObjTypeDef.desertMeteorite] = {
  //     holdInstace = 2,
  //     fromKey = "desertMeteorite",
  //     lodShowFun = lodShow.lessLOD3,
  //     lod = {
  //       [worldLodDef.LOD1] = {
  //         class = "worldMapDesertMeteorite",
  //         batchNode = batchNode.buildingBatchNode,
  //         createFun = addWorldInstanceNormale,
  //         cache = true
  //       },
  //       [worldLodDef.LOD2] = {
  //         class = "worldMapIconLodInstance",
  //         cache = true
  //       }
  //     }
  //   }

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
    if(lWorldInstanceData){
      lWorldInstanceData = GetWorldMapInstanceData_imp(pCell, pInstanceData, lConfig);
      pInstanceData._WorldInstanceData = lWorldInstanceData;
    }
    lWorldInstance = pBuilder->CreateMapInstanceConfig(pCell, pInstanceData, lWorldInstanceData, lConfig);
  }
  return lWorldInstance;
}