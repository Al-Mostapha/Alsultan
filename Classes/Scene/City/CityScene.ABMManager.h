#pragma once
#include "Include/IncludeBase.h"

class MainCityABMManager {
public:
  static MainCityABMManager *Get();
  void Init(class MainCityView *p_MainCityView);  
};