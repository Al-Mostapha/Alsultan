#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XOptional.h"
#include "Base/Type/XTuple.h"
#include "Base/Type/XEngine.h"
#include "Module/Building/Building.Enum.h"


class CastleSkinConfigRead
{
public:
  static CastleSkinConfigRead *Get();
  GOpt<Vec2> GetSkinOffset(EBuildingCastleModel pModel);
  GOpt<GTuple<float, Vec2>> GetSkinWarLvConfig(EBuildingCastleModel pModel, int32 pWarLv);
};