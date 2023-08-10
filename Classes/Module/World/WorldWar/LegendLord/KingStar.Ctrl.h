#pragma once
#include "Base/BaseTypeDef.h"

class KingStarCtrl
{
public:
  static KingStarCtrl *Get();
  bool GetIsSelfLegendKing(){
    return true;
  }
};