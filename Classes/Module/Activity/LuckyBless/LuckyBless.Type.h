#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "LuckyBLess.Enum.h"

struct RLuckyBlessData{
  uint32 _CostGold;
  uint32 _CurEffectEndTime;
  ELuckyBlessEffect _CurEffectType = ELuckyBlessEffect::None;
  uint32 _Discount;
  uint32 _LeftActivateCount;
  uint32 _LeftOpenCount;
  struct ROpenRecord{
    ELuckyBlessEffect _Type = ELuckyBlessEffect::None;
    uint32 _Value;
  };
  GVector <ROpenRecord> _OpenRecord;
};