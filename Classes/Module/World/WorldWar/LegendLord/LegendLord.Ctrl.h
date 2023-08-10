#pragma once
#include "Base/BaseTypeDef.h"

class LegendLordCtrl
{
public:
  static LegendLordCtrl *Get();
  bool GetIsSelfLegendKing(){
    return true;
  }
};