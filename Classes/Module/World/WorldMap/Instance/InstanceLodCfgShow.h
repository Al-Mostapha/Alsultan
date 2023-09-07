#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Enum.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

class InstanceLodCfgShow{
  public:
  static InstanceLodCfgShow *Get();
  bool LessLOD3OrSelfLegend(EWorldLodDef pLod, int32 pPlayerID, int32 pLeagueID){ return true; }
  bool LessLOD3OrSelf(EWorldLodDef pLod, int32 pPlayerID, int32 pLeagueID){ return true; }
  bool LessLOD2OrSelf(EWorldLodDef pLod, int32 pPlayerID, int32 pLeagueID){ return true; }
  bool AlwaysShow(EWorldLodDef pLod, int32 pPlayerID, int32 pLeagueID){ return true; }
  bool LessLOD3(EWorldLodDef pLod, int32 = 0, int32 = 0){ return true; }
  bool LessLod5(EWorldLodDef pLod, int32 = 0, int32 = 0){ return true; }
  bool MonsterShow(EWorldLodDef pLod, int32 = 0, int32 = 0){ return true; }
  bool AllianceBuild(EWorldLodDef pLod, int32 pLeagueID = 0, int32 = 0){ return true; }
  bool NpcShow(EWorldLodDef pLod, int32 pLeagueID = 0, int32 = 0){ return true; }
  bool BossShow(EWorldLodDef pLod, int32 pLeagueID = 0, int32 = 0){ return true; }
  ELodLayer SelfLayerLod3(EWorldLodDef pLod, int32 pPlayerID){ return ELodLayer::NORMAL; }
  ELodLayer SelfLayerLod4(EWorldLodDef pLod, int32 pPlayerID){ return ELodLayer::ALLIANCE; }
};