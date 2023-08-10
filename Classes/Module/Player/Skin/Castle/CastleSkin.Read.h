#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Building/Building.Enum.h"

class CastleSkinRead
{
public:
  static CastleSkinRead *Get();
  const GString &GetNameFloor(int32 pSkinID, bool pFromMemory = false);
  const GString &GetMapImage(int32 pSkinID, bool pFromMemory = false);
  EBuildingCastleModel GetCastleType(int32 pSkinID);
};