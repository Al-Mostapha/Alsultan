#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/Pair.h"
#include "Item.Type.h"

class ItemCtrl {
public:
  static ItemCtrl *Get();
  static GPair<bool, uint32> IsEnough(uint32 p_IdItem, uint32 p_Amount);
  GPair<bool, GVector<RCostItemEnough>> IsEnough(GVector<RCostItem>& p_CostItem){
    return GPair<bool, GVector<RCostItemEnough>>::Make(true, GVector<RCostItemEnough>());
  };
  uint32 GetItemPrice(uint32 p_IdItem);
};