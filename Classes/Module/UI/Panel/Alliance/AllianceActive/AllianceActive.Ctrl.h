#pragma once
#include "Include/IncludeBase.h"

class AllianceActiveCtrl {
public:
  static AllianceActiveCtrl* Get();
  int32 GetCanReceiveTaskNum();
};