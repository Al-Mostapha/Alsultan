#pragma once
#include "WindTower.Type.h"

class WindTowerRead
{
  public:
    static WindTowerRead *Get();
    GTime  GetTaskTimeByQuestId(int32 pQuestID);
    
};