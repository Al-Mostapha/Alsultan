#include "LostRuins.Ctrl.h"

LostRuinsCtrl* LostRuinsCtrl::Get()
{
  static LostRuinsCtrl* s_pInstance = nullptr;
  if (s_pInstance == nullptr)
  {
    s_pInstance = new LostRuinsCtrl();
  }
  return s_pInstance;
}

RLostRuinsQuest LostRuinsCtrl::GetRunningQuestInfo(){
  return RLostRuinsQuest();
}