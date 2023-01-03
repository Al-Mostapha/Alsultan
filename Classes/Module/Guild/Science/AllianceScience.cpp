#include "AllianceScience.h"


AllianceScience *AllianceScience::Get(){
  static AllianceScience *l_Instance = new AllianceScience();
  return l_Instance;
}

int32 AllianceScience::GetProsperityRewardsCount(){
  return 0;
}