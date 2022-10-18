#pragma once
#include "Include/IncludeBase.h"
#include "Science.Enum.h"
#include "Science.Type.h"
#include "Base/Containers/Pair.h"

class ScienceCtrl {
public: 
  static ScienceCtrl *Get();
  uint32 getSciencePower(EScienceEffect p_ScienceEffect);
  GPair<bool, uint32> IsEnough( EScience p_Science, uint32 p_Lvl);
  GPair<bool, GVector<RCostScienceEnough>> IsEnough(GVector<RCostScience> &p_Science);
  EScience StudyingTechnology();
};