#pragma once
#include "Base/BaseTypeDef.h"

class LegendLordWarCtrl{
public:
  static LegendLordWarCtrl *Get(){
    static auto l_Instance = new LegendLordWarCtrl();
    return l_Instance;
  }
  
  GTime GetLegendOccupyTime(GTime pTime){
    return 100;
  }
};