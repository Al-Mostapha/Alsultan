#pragma once
#include "IWorldMap.Com.h"

class WorldMapComWater : public IWorldMapComponent
{
  public:
    void Ctor();
    void Init() override;
    void OnMessageListener() override;  
    void InitAtlantisWater();
    void InitWater();
};