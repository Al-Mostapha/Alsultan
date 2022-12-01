#pragma once
#include "Activity.Enum.h"
#include "Include/IncludeBase.h"

class ActivityShowCtrl {
  GHashMap<EActivityCenter, GHashMap<EActivityTime, bool>> m_ActivityGroup;
public:
  static ActivityShowCtrl* Get();
  ActivityShowCtrl();
  EActivityState SetStateByID(EActivityTime p_IdEvent);
  GHashMap<EActivityTime, bool> GetActivityGroup(EActivityCenter p_IdGroup);
};