#pragma once
#include "LuckyBLess.Enum.h"

class LuckyBlessCtrl{
  public:
    static LuckyBlessCtrl *Get();
  ELuckyBlessEffect GetCurEffectType(); 
  int GetResult(int p_ResCount){ return p_ResCount; }
};