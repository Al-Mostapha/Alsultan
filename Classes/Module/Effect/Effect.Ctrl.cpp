#include "Effect.Ctrl.h"
#include "Module/Player/Player.Static.h"


TEffect EffectCtrl::getEffect(EEffectType p_EffectType){
  if(PlayerStatic::getEffects().Contains(p_EffectType))
    PlayerStatic::getEffects()[p_EffectType];
  return TEffect();
}