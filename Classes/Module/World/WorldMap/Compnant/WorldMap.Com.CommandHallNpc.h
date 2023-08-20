#pragma once
#include "IWorldMap.Com.h"

class WorldMapComCommandHallNpc : public IWorldMapComponent
{
  public:
    void Ctor();
    void Init() override;
    void OnMessageListener() override;  
};