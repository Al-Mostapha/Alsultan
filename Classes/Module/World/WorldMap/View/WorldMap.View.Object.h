#pragma once
#include "Module/World/WorldMap/WorldMap.Type.h"

class IWorldMapCompnant;
class WorldMapView;
class WorldMapViewObject
{
  protected:
    GVector<IWorldMapCompnant *> _Components;
  public:
    void AddComponents(RViewClass p_Config, WorldMapView *p_Target);
    void CallComFuncInit();
};