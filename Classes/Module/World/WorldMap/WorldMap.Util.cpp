#include "WorldMap.Util.h"

WorldMapUtil *WorldMapUtil::Get()
{
  static WorldMapUtil * s_WorldMapUtil = new WorldMapUtil();
  return s_WorldMapUtil;
}

void WorldMapUtil::ResetConfig()
{
  // Do something
}