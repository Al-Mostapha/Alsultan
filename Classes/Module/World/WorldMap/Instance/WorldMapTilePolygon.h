#pragma once
#include "Base/BaseTypeDef.h"

class WorldMapTilePolygon : public Sprite
{
  CREATE_FUNC(WorldMapTilePolygon);
public:

  static WorldMapTilePolygon *Create(){
    return create();
  }
};