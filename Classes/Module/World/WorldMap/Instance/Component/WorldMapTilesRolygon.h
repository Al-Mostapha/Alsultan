#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XOptional.h"
#include "Base/Type/XEngine.h"

class WorldMapTilesRolygon : public Node
{
  CREATE_FUNC(WorldMapTilesRolygon);
  public:
    static WorldMapTilesRolygon *Create(float pScale = 1.0f);
    void SetRolygonColor(const Color3B &pColor, GOpt<float> pOpacity = {});
};