#pragma once
#include "Include/IncludeBase.h"

class CityCtrl {
public:
  static CityCtrl *Get();
  GString GetBuildStarLight(uint32 p_StarLvl) { return "" ;}
  uint32 GetBuildStarColor(uint32 p_StarLvl) { return 0 ;}
};