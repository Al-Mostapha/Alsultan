#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"


class WindTowerUtil{
  public:
    static WindTowerUtil *Get();
    GTime GetBuildCD(Vec2 pPoint); // CD is Count down
};