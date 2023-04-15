#pragma once 
#include "Module/Activity/Activity.Enum.h"
#include "Base/BaseTypeDef.h"
#include "Base/Containers/Pair.h"

class WiseTutorCtrl{
  public: 
    static WiseTutorCtrl *Get();
    GPair<EActivityState, GTime> GetStateInfo();
    bool IsBuffEffect();
};