#include "LuckyBless.Ctrl.h"


LuckyBlessCtrl *LuckyBlessCtrl::Get(){
  static auto l_Inst = new LuckyBlessCtrl();
  return l_Inst;
}

ELuckyBlessEffect LuckyBlessCtrl::GetCurEffectType(){
  return ELuckyBlessEffect::BuildingUpgrade;
}