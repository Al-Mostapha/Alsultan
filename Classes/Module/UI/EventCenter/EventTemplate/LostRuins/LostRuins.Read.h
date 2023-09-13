#pragma once
#include "LostRuins.Type.h"

class LostRuinsRead
{
  public:
    static LostRuinsRead* Get();
    GTime GetTaskTimeByQuestId(int32 pQuestID);
};