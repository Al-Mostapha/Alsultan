#pragma once
#include "Base/BaseTypeDef.h"

class CastleSkinRead
{
public:
  static CastleSkinRead *Get();
  const GString &GetNameFloor(int32 pSkinID, bool pFromMemory = false);
};