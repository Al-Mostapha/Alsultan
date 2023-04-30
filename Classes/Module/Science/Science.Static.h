#pragma once
#include "Base/Containers/HashMap.h"
#include "Include/IncludeBase.h"
#include "Science.Type.h"

class ScienceStatic {
  private:
  GHashMap<EScienceType, RScienceCategory> m_Science;
  RScienceCategory m_InvalidScienceCategory;
  RScienceLvlSpecs m_InvalidScienceLvlSpecs;
  RScience m_InvalidScience;

  public:
  static ScienceStatic& Get();
  static RScienceCategory& getScienceCategory(EScienceType p_ScienceCategory);
  static RScience& getScience(EScienceID p_ScienceType);
  static RScienceLvlSpecs& getScienceLvlSpecs(EScienceID p_ScienceType, uint32 p_Lvl);
  static bool isValidScienceLvl(EScienceID p_ScienceType, uint32 p_Lvl);
  static bool isValidScience(EScienceID p_ScienceType);
};