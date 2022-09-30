#include "GuildScience.Ctrl.h"

GuildScienceCtrl *GuildScienceCtrl::Get(){
  static GuildScienceCtrl *l_Instance = new GuildScienceCtrl();
  return l_Instance;
}

uint32 GuildScienceCtrl::getSciencePower(EGuildScience p_GuildScience){
  return 0;
}