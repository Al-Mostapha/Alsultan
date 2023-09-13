#include "LostRuins.Read.h"

LostRuinsRead *LostRuinsRead::Get(){
  static LostRuinsRead _Instance;
  return &_Instance;
}

GTime LostRuinsRead::GetTaskTimeByQuestId(int32 pQuestID)
{
  return 120;
}