#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"


class MapSyncUtilClient{
public:
  static MapSyncUtilClient *Get();
  int32 GetPieceId(Vec2 p_Pos, EKingdomClassType p_KingdomClass, EWorldLodDef){ return 0; }
};