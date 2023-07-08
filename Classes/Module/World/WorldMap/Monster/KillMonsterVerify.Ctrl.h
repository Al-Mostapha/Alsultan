#pragma once
#include "Base/BaseTypeDef.h"

class KillMonsterVerifyCtrl{
  public:
    static KillMonsterVerifyCtrl *Get();
    void Init();
    bool IsQuickSearchMonsterLock();
    GTime GetQuickSearchMonsterLockLeftTime();
};