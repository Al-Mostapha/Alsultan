#pragma once
#include "Include/IncludeBase.h"
#include "Module/World/WorldMap./WorldMap.Enum.h"

struct RLostRuinsQuest{
  bool bIsFinish;
  int32 _QuestID; 
  ELosRuinsStatus _State = ELosRuinsStatus::SURVEY;
  GTime _StartTime;
  GTime _CdBeginTime;
};

class LostRuinsCtrl
{
public:
  static LostRuinsCtrl* Get();
  int32 GetNewSurveyNum();
  RLostRuinsQuest GetRunningQuestInfo();
  RLostRuinsQuest GetQuestInfo(Vec2 pPos);
};
