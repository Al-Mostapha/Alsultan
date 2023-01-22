#pragma once
#include "Base/BaseTypeDef.h"

class ShopLtCtrl{
public:
  static ShopLtCtrl *Get();
  bool GetShopNewTag(const char *p_For = "all");
};