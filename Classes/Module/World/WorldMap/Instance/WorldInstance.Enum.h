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