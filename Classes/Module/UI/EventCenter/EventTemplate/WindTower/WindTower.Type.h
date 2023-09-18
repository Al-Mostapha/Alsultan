#pragma once
#include "Base/BaseTypeDef.h"
#include "WindTower.Enum.h"

struct RWindTowerQuestInfo{
  bool _Finish;
  EWindTowerStatus _Status;
  GTime _EndTime;
  int32 _QuestID;
};

struct RWindTowerActionConfig{
  int32 _Index;
  int32 _Group;
  int32 _QuestID;
  int32 _Time;
  int32 _Weight;
};