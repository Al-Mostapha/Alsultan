#include "KillMonsterVerify.Ctrl.h"

KillMonsterVerifyCtrl *KillMonsterVerifyCtrl::Get()
{
  static KillMonsterVerifyCtrl *l_Instance = nullptr;
  if(!l_Instance){
    l_Instance = new KillMonsterVerifyCtrl();
    l_Instance->Init();
  }
  return l_Instance;
}

bool KillMonsterVerifyCtrl::IsQuickSearchMonsterLock()
{
  return false;
}

GTime KillMonsterVerifyCtrl::GetQuickSearchMonsterLockLeftTime(){
  return 0;
}