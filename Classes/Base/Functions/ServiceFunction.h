#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"

class GServiceFunction{
public:
  static GServiceFunction *Get();
  EIDType GetIDType(int p_ID);
  GTime SystemTime();
};