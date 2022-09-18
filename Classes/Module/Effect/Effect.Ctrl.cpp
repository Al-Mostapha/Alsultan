#include "Effect.Ctrl.h"
#include "Module/Player/Player.Static.h"


TEffect EffectCtrl::getEffect(EEffectType p_EffectType){
  if(PlayerStatic::getEffects().Contains(p_EffectType))
    PlayerStatic::getEffects()[p_EffectType];
  return TEffect();
}

bool EffectCtrl::isEffectActive(EEffectType p_EffectType){
  if(getEffect(p_EffectType).timeEnd <= GDateTime::Now())
    return false;
  return true;
}

int32 EffectCtrl::getEffectVal(EEffectType p_EffectType){
  return 0;
}
