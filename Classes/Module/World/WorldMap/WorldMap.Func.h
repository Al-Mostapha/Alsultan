#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class WorldMapFunction{
  public:
    static WorldMapFunction *Get();
    GTuple<float, GString, bool> GetMonsterImgAngel(Vec2 pBeginPoint, Vec2 pEndPoint);
};