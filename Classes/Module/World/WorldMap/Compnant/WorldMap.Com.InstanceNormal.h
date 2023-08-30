#pragma once
#include "IWorldMap.Com.h"

class WorldMapComInstanceNormal : public IWorldMapComponent
{
  public:
    void Ctor();
    void Init() override;
    void OnMessageListener() override;  
};