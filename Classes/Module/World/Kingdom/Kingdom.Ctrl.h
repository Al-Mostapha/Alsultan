#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XOptional.h"
#include "Kingdom.Type.h"

class KingdomCtrl
{
  public: 
  static KingdomCtrl *Get();
  GOpt<RKingdomInfo> IsFoundKingdomID(int32 p_KingdomId);
};