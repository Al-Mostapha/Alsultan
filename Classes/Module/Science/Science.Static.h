#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Science.Type.h"

class ScienceStatic{
private:
  GHashMap<EScienceCategory, RScienceCategory> m_Science;
  RScienceCategory m_InvalidScienceCategory;
  RScienceLvlSpecs m_InvalidScienceLvlSpecs;
  RScience m_InvalidScience;

public:
  static ScienceStatic& Instance();
  static RScienceCategory& getScienceCategory(EScienceCategory p_ScienceCategory);
  static RScience& getScience(EScienceType p_ScienceType);
  static RScienceLvlSpecs& getScienceLvlSpecs(EScienceType p_ScienceType, uint32 p_Lvl);
  static bool isValidScienceLvl(EScienceType p_ScienceType, uint32 p_Lvl);
  static bool isValidScience(EScienceType p_ScienceType);
};