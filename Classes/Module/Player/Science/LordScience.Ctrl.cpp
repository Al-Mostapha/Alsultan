#include "LordScience.Ctrl.h"

LordScienceCtrl *LordScienceCtrl::Get(){
  static LordScienceCtrl *l_Instance = new LordScienceCtrl();
  return l_Instance;
}

uint32 LordScienceCtrl::getSciencePower(ELordScience p_LordScience){
  return 0;
}