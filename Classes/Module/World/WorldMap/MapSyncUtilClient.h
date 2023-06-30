#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

class MapSyncUtilClient{
public:
  static MapSyncUtilClient *Get();
  int32 GetPieceId(Vec2 p_Pos, EKingdomClassType p_KingdomClass, EWorldLodDef){ return 0; }
};