#pragma once
#include "Base/BaseTypeDef.h"

class PalaceInfoRead
{
  public:
    static PalaceInfoRead *Get();
    GString GetImg(int32 pID, bool pFromMemory = false);
};