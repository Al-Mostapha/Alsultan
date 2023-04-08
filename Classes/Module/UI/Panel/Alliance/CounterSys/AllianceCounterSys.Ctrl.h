#pragma once
#include "Include/IncludeBase.h"

class AllianceCounterSysCtrl{
public:
  static AllianceCounterSysCtrl* Get();
  int32 GetNewPoint();
};