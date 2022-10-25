#include "Science.Ctrl.h"


ScienceCtrl *ScienceCtrl::Get(){
  ScienceCtrl *l_Instance = new ScienceCtrl();
  return l_Instance;
}

uint32 ScienceCtrl::getSciencePower(EScienceEffect p_ScienceEffect){
  return 0;
}

GPair<bool, uint32> ScienceCtrl::IsEnough( EScience p_Science, uint32 p_Lvl){
  return GPair<bool, uint32>::Make(true, 0);
}
GPair<bool, GVector<RCostScienceEnough>> ScienceCtrl::IsEnough(GVector<RCostScience> &p_Science){
  auto l_IsEnough = GPair<bool, GVector<RCostScienceEnough>>::Make(true, {});
  return l_IsEnough;
}

EScience ScienceCtrl::StudyingTechnology(){
  return EScience::None;
}