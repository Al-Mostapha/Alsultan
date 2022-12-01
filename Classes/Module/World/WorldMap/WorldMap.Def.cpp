#include "WorldMap.Def.h"

WorldMapDef * WorldMapDef::Get()
{
  static WorldMapDef * s_WorldMapDef = new WorldMapDef();
  return s_WorldMapDef;
}

void WorldMapDef::DoSwitchToAnchor()
{
  // Do something
}