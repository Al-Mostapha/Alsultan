#include "LuckyBless.Ctrl.h"
#include "LuckyBless.Type.h"
#include "Base/Containers/Pair.h"

LuckyBlessCtrl *LuckyBlessCtrl::Get(){
  static auto l_Inst = new LuckyBlessCtrl();
  return l_Inst;
}

ELuckyBlessEffect LuckyBlessCtrl::GetCurEffectType(){
  return ELuckyBlessEffect::BuildingUpgrade;
}

RLuckyBlessData LuckyBlessCtrl::GetLuckyData(){ return RLuckyBlessData(); }

GPair<GTime, GTime> LuckyBlessCtrl::GetRealTime(){
  return GPair<GTime, GTime>(100, 100);
}