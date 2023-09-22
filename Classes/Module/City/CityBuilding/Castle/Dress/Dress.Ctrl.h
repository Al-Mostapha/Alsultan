#pragma once 
#include "Base/BaseTypeDef.h"
#include "Dress.Enum.h"

class DressCtrl
{
  public:
  static DressCtrl* Get();
  int32 GetCurDressID(EDressType type);
};