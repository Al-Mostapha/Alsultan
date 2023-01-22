#pragma once
#include "Include/IncludeBase.h"

struct RLostRuinsQuest{
  bool bIsFinish;
  int32 idQuest; 
};

class LostRuinsCtrl
{
public:
  static LostRuinsCtrl* Get();
  int32 GetNewSurveyNum();
    RLostRuinsQuest GetRunningQuestInfo();
};
