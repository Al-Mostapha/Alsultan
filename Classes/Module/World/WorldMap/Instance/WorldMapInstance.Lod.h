#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldMapInstance.Base.h"

class WorldMapInstanceLod : public WorldMapInstanceBase
{

  public:
  Vec2 _CenterPoint;
  uint32 _InstanceID;
  uint32 GetInstanceID();
  int32 GetHoldInstance();
  void RemoveInstanceSelf();
  Vec2 GetTilePoint();
};