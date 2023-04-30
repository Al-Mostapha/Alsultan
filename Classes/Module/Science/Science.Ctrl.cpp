#include "Science.Ctrl.h"


ScienceCtrl *ScienceCtrl::Get(){
  ScienceCtrl *l_Instance = new ScienceCtrl();
  return l_Instance;
}

uint32 ScienceCtrl::GetSciencePower(EScienceID p_ScienceEffect){
  return 0;
}

GPair<bool, uint32> ScienceCtrl::IsEnough( EScienceID p_Science, uint32 p_Lvl){
  return GPair<bool, uint32>::Make(true, 0);
}
GPair<bool, GVector<RCostScienceEnough>> ScienceCtrl::IsEnough(GVector<RCostScience> &p_Science){
  auto l_IsEnough = GPair<bool, GVector<RCostScienceEnough>>::Make(true, {});
  return l_IsEnough;
}

GPair<RScienceDetail, EScienceType> ScienceCtrl::StudyingTechnology(){
  return GPair<RScienceDetail, EScienceType>(RScienceDetail(), EScienceType::Resource);
}

GVector<RScienceLvlSpecs> ScienceCtrl::GetRecommendTech(){
  return GVector<RScienceLvlSpecs>();
}