#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class WindTowerUtil{
  public:
    static WindTowerUtil *Get();
    GTime GetBuildCD(Vec2 pPoint); // CD is Count down
};