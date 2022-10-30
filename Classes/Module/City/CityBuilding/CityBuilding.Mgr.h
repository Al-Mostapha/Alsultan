#pragma once
#include "Include/IncludeBase.h"


class CityBuildingMgr
{
public:
  static CityBuildingMgr *Get();
  void InitWithData(class MainCityView *p_View);
};