#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldMapInstance.Base.h"

class WorldMapInstanceLod : public WorldMapInstanceBase
{

  public:
  Vec2 _CenterPoint;
  int32 GetHoldInstance();
  void RemoveInstanceSelf();
  Vec2 GetTilePoint();
};