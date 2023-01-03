#include "AllianceScience.Ctrl.h"

AllianceScienceCtrl *AllianceScienceCtrl::Get(){
  static AllianceScienceCtrl *l_Instance = new AllianceScienceCtrl();
  return l_Instance;
}

uint32 AllianceScienceCtrl::GetSciencePower(EGuildScience p_GuildScience){
  return 0;
}