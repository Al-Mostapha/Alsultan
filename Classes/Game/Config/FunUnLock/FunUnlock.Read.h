#pragma once
#include "FunUnlock.Type.h"
#include "FunUnlock.Enum.h"
#include "Module/Building/Building.Enum.h"


class FunUnlockRead{
  public: 
    static FunUnlockRead *Get();
    int32 GetUnlockLevel(EFunID pFid){ return 0; }
    int32 GetLvByOpName(EBuildingTips pOpName) { return 0;} ;
};