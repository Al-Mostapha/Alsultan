#pragma once
#include "Include/IncludeBase.h"
#include "Activity.Enum.h"
#include "Activity.Type.h"
#include "Base/Containers/HashMap.h"

class ActivityShowCtrl {
  GHashMap<EActivityCenter, GHashMap<EActivityTime, bool>> m_ActivityGroup;
public:
  static ActivityShowCtrl* Get();
  ActivityShowCtrl();
  EActivityState SetStateByID(EActivityTime p_IdEvent);
  GHashMap<EActivityTime, bool> GetActivityGroup(EActivityCenter p_IdGroup);
  RActivityShowData GetCommunityInfo(EActivityTime p_IdEvent);
  bool IsActivityOpen(EActivityTime p_IdEvent);
};