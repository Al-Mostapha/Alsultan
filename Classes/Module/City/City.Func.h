#pragma once
#include "Include/IncludeBase.h"


class MainCityFunctions{
public:
  static MainCityFunctions *Get();
  void UpdateLockArea(class MainCityView *p_View);
};