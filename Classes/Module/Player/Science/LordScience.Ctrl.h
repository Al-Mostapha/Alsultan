#pragma once
#include "Include/IncludeBase.h"
#include "LordScience.Enum.h"

class LordScienceCtrl {
public:
  static LordScienceCtrl *Get();
  uint32 GetSciencePower(ELordScience p_LordScience);
};