#pragma once
#include "IWorldMap.Com.h"

class WorldMapComLod : public IWorldMapComponent
{
  public:
    void Ctor();
    void Init() override;
    void OnMessageListener() override;  
};