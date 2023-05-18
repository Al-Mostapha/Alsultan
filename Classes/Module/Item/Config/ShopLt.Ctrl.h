#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Item/Item.Enum.h"

class ShopLtCtrl{
public:
  static ShopLtCtrl *Get();
  bool GetShopNewTag(const char *p_For = "all");
  EItemType GetItemType(EItemID);
};