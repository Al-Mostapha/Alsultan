#pragma once
#include "LuckyBLess.Enum.h"
#include "Base/BaseTypeDef.h"


struct RLuckyBlessData;
template <typename F, typename S>
class GPair;
class LuckyBlessCtrl{
  public:
    static LuckyBlessCtrl *Get();
  ELuckyBlessEffect GetCurEffectType(); 
  int GetResult(int p_ResCount){ return p_ResCount; }
  RLuckyBlessData GetLuckyData();
  GPair<GTime, GTime> GetRealTime();
  int32 GetLeftActivateCount();
  int32 GetLuckyBlessStatus();
};