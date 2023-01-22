#include "LostRuins.Ctrl.h"

LostRuinsCtrl * LostRuinsCtrl::Get()
{
  static LostRuinsCtrl * pCtrl = new LostRuinsCtrl();
  return pCtrl;
}

int32 LostRuinsCtrl::GetNewSurveyNum()
{
  return 0;
}
RLostRuinsQuest LostRuinsCtrl::GetRunningQuestInfo(){
  return RLostRuinsQuest();
}