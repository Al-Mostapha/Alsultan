#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

class WorldMapRadianceWarBeacon : public IWorldMapInstance
{
  public:
  int32 GetSiteClassID() {
    return 0;
  };
};