#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/Pair.h"
#include "Item.Type.h"

class ItemCtrl {
public:
  static ItemCtrl *Get();
  GPair<bool, uint32> IsEnough(uint32 p_IdItem, uint32 p_Amount);
  GPair<bool, GVector<RCostItemEnough>> IsEnough(GVector<RCostItem>& p_CostItem);
  uint32 GetItemPrice(uint32 p_IdItem);
};