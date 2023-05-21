#include "WorldMapView.Def.h"

WorldMapViewDef * WorldMapViewDef::Get()
{
  static WorldMapViewDef * s_WorldMapViewDef = new WorldMapViewDef();
  return s_WorldMapViewDef;
}

