#pragma once
#include "Effect.Type.h"

class EffectCtrl{

public: 
  static TEffect getEffect(EEffectType p_EffectType);
  static bool isEffectActive(EEffectType p_EffectType);
  static int32 getEffectVal(EEffectType p_EffectType);
};