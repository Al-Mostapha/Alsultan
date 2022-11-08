#pragma once
#include "Include/IncludeBase.h"

class InteriorCtrl {
public:
  static InteriorCtrl *Get();
  void ResetLoginDays();
};