#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Building/Building.Enum.h"

USING_NS_CC;

class CastleSkinConfigRead
{
public:
  static CastleSkinConfigRead *Get();
  GOpt<Vec2> GetSkinOffset(EBuildingCastleModel pModel);
  GOpt<GTuple<float, Vec2>> GetSkinWarLvConfig(EBuildingCastleModel pModel, int32 pWarLv);
};