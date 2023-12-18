#include "Effect.Ctrl.h"
#include "Base/DateTime.h"
#include "Module/Player/Player.Static.h"

EffectCtrl *EffectCtrl::Get(){
  EffectCtrl *l_Instance = new EffectCtrl();
  return l_Instance;
}

TEffect EffectCtrl::getEffect(EEffect p_EffectType){
  if(PlayerStatic::getEffects().Contains(p_EffectType))
    PlayerStatic::getEffects()[p_EffectType];
  return TEffect();
}

bool EffectCtrl::isEffectActive(EEffect p_EffectType){
  if(getEffect(p_EffectType).timeEnd <= GDateTime::Now())
    return false;
  return true;
}

uint32 EffectCtrl::getEffectVal(EEffect p_EffectType){
  return 0;
}
