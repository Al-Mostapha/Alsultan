#pragma once
#include "Base/BaseTypeDef.h"

class LimitTimeDiscountShopApi{
  public:
    static LimitTimeDiscountShopApi *Get();
    bool GetActivityStatus();
    GTime GetActivityRemainTime();
};