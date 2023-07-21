#pragma once

enum class EWorldInstanceClass {
  None = 0,
  WorldMapBuilding,
  WorldMapBuildingLod2,
  WorldMapBuildingLod,
  WorldMapLegendLord,
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
  WorldMapMonsterLod
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