#pragma once
#include "FunUnlock.Type.h"
#include "FunUnlock.Enum.h"


class FunUnlockRead{
  public: 
    static FunUnlockRead *Get();
    int32 GetUnlockLevel(EFunID pFid){ return 0; }
};