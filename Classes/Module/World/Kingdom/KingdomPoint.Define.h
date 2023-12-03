#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Base/Type/XTuple.h"

class KingdomPointDefine{
public:
  static KingdomPointDefine * Get();
  GTuple<int32, int32, int32, int32> GetNeighbourKingdomsByPoint(Vec2 p_KingdomId, int32 p_RegionId);
};