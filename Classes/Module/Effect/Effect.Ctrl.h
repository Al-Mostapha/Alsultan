#pragma once
#include "Effect.Type.h"

class EffectCtrl {
  public:
  static EffectCtrl* Get();
  TEffect getEffect(EEffect p_EffectType);
  bool isEffectActive(EEffect p_EffectType);
  uint32 getEffectVal(EEffect p_EffectType);
  // Percent of 1000 not 100
  float GetBuffEffect(EEffect p_EffectType){return 0;}
};