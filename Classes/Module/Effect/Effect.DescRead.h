#pragma once
#include "Include/IncludeBase.h"

class EffectDecRead {
public:
  static EffectDecRead* Get();
  bool IsBuff(int32 p_EffectId){
    return false;
  }
};