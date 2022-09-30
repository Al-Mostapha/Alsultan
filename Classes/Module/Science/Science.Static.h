#pragma once
#include "Base/Containers/HashMap.h"
#include "Include/IncludeBase.h"
#include "Science.Type.h"

class ScienceStatic {
  private:
  GHashMap<EScienceCategory, RScienceCategory> m_Science;
  RScienceCategory m_InvalidScienceCategory;
  RScienceLvlSpecs m_InvalidScienceLvlSpecs;
  RScience m_InvalidScience;

  public:
  static ScienceStatic& Get();
  static RScienceCategory& getScienceCategory(EScienceCategory p_ScienceCategory);
  static RScience& getScience(EScience p_ScienceType);
  static RScienceLvlSpecs& getScienceLvlSpecs(EScience p_ScienceType, uint32 p_Lvl);
  static bool isValidScienceLvl(EScience p_ScienceType, uint32 p_Lvl);
  static bool isValidScience(EScience p_ScienceType);
};