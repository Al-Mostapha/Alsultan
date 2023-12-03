#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "Base/Type/XEngine.h"


struct REndlessTrailsSnowMountain{
  uint32 _ID;
  uint32 _SnowMountainID;
  GString _Name;
  uint32 _Type;
  Vec2 _Coordinate;
  GVector<int32> _Arms;
  uint32 _MaxLv;
};