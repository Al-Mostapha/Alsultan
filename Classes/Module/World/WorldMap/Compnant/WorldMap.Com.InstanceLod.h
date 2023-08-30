#pragma once
#include "IWorldMap.Com.h"

class WorldMapComInstanceLod : public IWorldMapComponent
{
  public:
    void Ctor();
    void Init() override;
    void OnMessageListener() override;  
};