#include "Science.Static.h"

ScienceStatic& ScienceStatic::Instance() {
  static ScienceStatic* s_Instance = new ScienceStatic();
  return (*s_Instance);
}

RScienceCategory& ScienceStatic::getScienceCategory(EScienceCategory p_ScienceCategory) {
  auto l_Instance = Instance();
  if (!l_Instance.m_Science.Contains(p_ScienceCategory)) {
    uint32 l_SC = static_cast<uint32>(p_ScienceCategory);
    GString l_ErrorMsg = StringUtils::format("Trying To get Science Category From ScienceMap %d", l_SC);
    Logger::Log(l_ErrorMsg, ELogLvl::Error, true);
    return l_Instance.m_InvalidScienceCategory;
  }
  return l_Instance.m_Science[p_ScienceCategory];
}

RScience& ScienceStatic::getScience(EScienceType p_ScienceType) {
  ScienceStatic& l_Instance = Instance();
  for (auto& l_OneScienceCat : l_Instance.m_Science) {
    for (auto& l_OneScience : l_OneScienceCat.second.Tree) {
      if (l_OneScience.first == p_ScienceType) return l_OneScience.second;
    }
  }
  /* Not Found Science*/
  uint32 l_SC = static_cast<uint32>(p_ScienceType);
  GString l_ErrorMsg = StringUtils::format("Trying To get Science From ScienceMap %d", l_SC);
  Logger::Log(l_ErrorMsg, ELogLvl::Error, true);
  return l_Instance.m_InvalidScience;
}

RScienceLvlSpecs& ScienceStatic::getScienceLvlSpecs(EScienceType p_ScienceType, uint32 p_Lvl) {
  ScienceStatic& l_Instance = Instance();
  auto l_Science = getScience(p_ScienceType);
  for (auto& l_OneScienceLvl : l_Science.Lvls) {
    if (l_OneScienceLvl.second.lvl == p_Lvl) return l_OneScienceLvl.second;
  }

  /* Not Found Science Lvl*/
  uint32 l_SC = static_cast<uint32>(p_ScienceType);
  GString l_ErrorMsg = StringUtils::format("Trying To get Science Lvl %d And ScienceLvl %d", l_SC, p_Lvl);
  Logger::Log(l_ErrorMsg, ELogLvl::Error, true);
  return l_Instance.m_InvalidScienceLvlSpecs;
}

bool ScienceStatic::isValidScienceLvl(EScienceType p_ScienceType, uint32 p_Lvl) {
  ScienceStatic& l_Instance = Instance();
  auto l_Science = getScience(p_ScienceType);
  for (auto& l_OneScienceLvl : l_Science.Lvls) {
    if (l_OneScienceLvl.second.lvl == p_Lvl) return true;
  }
  return false;
}

bool ScienceStatic::isValidScience(EScienceType p_ScienceType) { 
  ScienceStatic& l_Instance = Instance();
  for (auto& l_OneScienceCat : l_Instance.m_Science) {
    for (auto& l_OneScience : l_OneScienceCat.second.Tree) {
      if (l_OneScience.first == p_ScienceType) return true;
    }
  }
  return false;
}


