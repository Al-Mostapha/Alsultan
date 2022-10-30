#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "CityScene.View.h"


class MainCityBuildingMove {
public:
  static MainCityBuildingMove *Get();
  void Init(class MainCityView *p_MainCityView);
};