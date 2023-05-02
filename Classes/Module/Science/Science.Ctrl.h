#pragma once
#include "Include/IncludeBase.h"
#include "Science.Enum.h"
#include "Science.Type.h"
#include "Base/Containers/Pair.h"



class ScienceCtrl {
public: 
  static ScienceCtrl *Get();
  uint32 GetSciencePower(EScienceEffect p_ScienceEffect);
  GPair<bool, uint32> IsEnough( EScienceEffect p_Science, uint32 p_Lvl);
  GPair<bool, GVector<RCostScienceEnough>> IsEnough(GVector<RCostScience> &p_Science);
  GPair<RScienceDetail, EScienceType> StudyingTechnology();
  GVector<RScienceLvlSpecs> GetRecommendTech();
  RScienceDetail GetTechDetails(EScience p_Science, int32 _Lvl){ return RScienceDetail(); }
  RScienceTypeData GetTechDataByID(EScience p_Science, EScienceType p_Type){
    return RScienceTypeData();
  }
};