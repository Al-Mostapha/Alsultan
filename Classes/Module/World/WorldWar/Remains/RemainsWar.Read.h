#pragma once 
#include "Base/BaseTypeDef.h"  

class RemainsWarRead{
  public:
  static RemainsWarRead* Get();
  const char *GetCampIcon(int32 camp);
};