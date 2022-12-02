#pragma once
#include "Include/IncludeBase.h"
#include "Guide.Type.h"

class GuideCtrl
{
public:
  static GuideCtrl *Get();
  RGuideStep *GetCurMainCityGuideStep();
};