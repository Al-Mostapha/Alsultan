#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Enum.h"

class PalaceInfoRead
{
  public:
    static PalaceInfoRead *Get();
    GString GetImg(int32 pID, bool pFromMemory = false);
    GString GetBatteryImg(EKWBattery pBatteryPlace);
};