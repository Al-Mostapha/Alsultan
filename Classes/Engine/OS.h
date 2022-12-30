#pragma once
#include "Base/BaseTypeDef.h"

class GOS{
public:
  static GOS *Get();
  GTime GetTime();
};