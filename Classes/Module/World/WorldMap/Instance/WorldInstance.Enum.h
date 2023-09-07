#pragma once

enum class EWorldInstanceClass {
  None = 0,
  WorldMapBuilding,
  WorldMapBuildingLod2,
  WorldMapBuildingLod,
  WorldMapLegendLord,
  WorldMapRemains,
  WorldMapIconLodInstance,
  WorldMapRemainsWar,
  WorldMapCastle,
  WorldMapIconLodCastle,
  WorldMapBattery,
  WorldMapIconLodBattery,
  WorldMapFortress,
  WorldMapResource,
  WorldMapResourceLod2,
  WorldMapResourceLod,
  WorldMapCampsite,
  WorldMapIconLodCampsite,
  WorldMapMonster,
  WorldMapMonsterLod,
  WorldMapAllianceBuild,
  WorldMapAllianceBuildLod,
  WorldMapMonsterNebula,
  WorldMapMonsterSnowMan,
  WorldMapMonsterSemluk,
  WorldMapMonsterSea,
  WorldMapMonsterFiesta,
  WorldMapBoss,
  WorldMapBossWindTower,
  WorldMapIconLodBoss,
  WorldMapAllianceResource,
  WorldMapIconLodAlliance,
  WorldMapTreasure,
  WorldMapChest,
  WorldMapTreasureBowl,
  WorldMapBattlefieldSite,
  WorldMapEscort,
  WorldMapMineBuild,
  WorldMapIconLodMine,
  WorldMapStronghold,
  WorldMapIconLodStrong,
  WorldMapKingdomLvTower,
  WorldMapPyramidGloryBuild,
  WorldMapNewTrialCity,
  WorldMapTrialBattery,
};


enum class EMapNpcFaceTypeDef {
  None = 0,
  LeftBottom = 1,
  RightBottom = 2
};

enum class ELodLayer {
  None = 0,
  NORMAL = 1,
  NPC = 2,
  ALLIANCE = 3,
  SELF = 4,
  CASTLE = 5,
  ALLIANCERES = 6,
  ALLIANCESTRONG = 7,
  MONSTER = 8,
  BOSS = 9,
  NEBULA = 10,
  NEBULA_4 = 11
};

enum class EMapObjStateTypeDef{
  None = 0,
  Free = 1,
  Fighting = 2,
  HurtDie = 3,
  Working = 4
};

enum class EMapAllianceBuildType{
  None = 0,
  Palace = 1,
  Fort = 2,
  WarHall = 3,
  Shelter = 4,
  KnowledgeTower = 5,
  Flag = 6,
  Altar = 8,
  PriPalace = 9
};

enum class ESignatureBoxType{
  None = 0,
  Normal = 1,
  War = 2
};

enum class ESkillEffectType {
  None = 0,
  RUINS_WAR_MOVE_CITY_LOCKED = 1,
  RUINS_WAR_SPEED_QUEUE_LOCKED = 2,
  APPOINT_DAMAGE_BOOST = 3,
  APPOINT_CURE_SOLDIER_SPEED_BOOST = 4
};


enum class EKWBattery{
  None = 0,
  NORTH = 11,
  EAST = 14,
  SOUTH = 13,
  WEST = 12
};


enum class EMapBattlefieldSiteTypeDef {
  None = 0,
  ObjTypeBigPyramid = 1,
  ObjTypeSmallPyramid = 2,
  ObjTypeSuplly = 3,
  ObjTypeTransport = 4,
  ObjTypeBlessTower = 5,
  ObjTypeMedicalCenter = 6,
  ObjTypeStage = 7,
  ObjTypeRelic = 8,
  ObjTypeBattery = 9,
  TypeAWBellTower = 10,
  TypeAWArmory = 11
};

enum class EMapNewTrialBuildType {
  Castle = 1, 
  Battery = 2
};