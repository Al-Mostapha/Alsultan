#pragma once
#include "Include/IncludeBase.h"
#include "LordScience.Enum.h"

class LordScienceCtrl {
public:
  static LordScienceCtrl *Get();
  uint32 getSciencePower(ELordScience p_LordScience);
};