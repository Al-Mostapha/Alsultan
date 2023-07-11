#include "FunUnlock.Read.h"

FunUnlockRead *FunUnlockRead::Get(){
  static auto sInstance = new FunUnlockRead();
  return sInstance;
}

