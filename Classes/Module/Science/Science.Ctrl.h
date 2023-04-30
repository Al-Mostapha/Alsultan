#pragma once
#include "Include/IncludeBase.h"
#include "Science.Enum.h"
#include "Science.Type.h"
#include "Base/Containers/Pair.h"



class ScienceCtrl {
public: 
  static ScienceCtrl *Get();
  uint32 GetSciencePower(EScienceID p_ScienceEffect);
  GPair<bool, uint32> IsEnough( EScienceID p_Science, uint32 p_Lvl);
  GPair<bool, GVector<RCostScienceEnough>> IsEnough(GVector<RCostScience> &p_Science);
  GPair<RScienceDetail, EScienceType> StudyingTechnology();
  GVector<RScienceLvlSpecs> GetRecommendTech();
};