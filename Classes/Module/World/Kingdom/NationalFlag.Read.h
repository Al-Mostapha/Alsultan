#pragma once
#include "Base/BaseTypeDef.h"

class NationalFlagRead
{
  public: 
  static NationalFlagRead *Get();
  GString GetImgByID(int32 p_KingdomId);
};