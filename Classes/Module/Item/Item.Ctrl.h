#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/Pair.h"
#include "Item.Type.h"

 

class ItemCtrl {
public:
  struct ItemGift {
    uint32 idItem = 0;
    uint32 count = 0;
    EItemQuality Quality;
  };
  static ItemCtrl *Get();
  GPair<bool, uint32> IsEnough(uint32 p_IdItem, uint32 p_Amount);
  GPair<bool, GVector<RCostItemEnough>> IsEnough(GVector<RCostItem>& p_CostItem);
  uint32 GetItemPrice(uint32 p_IdItem);
  GVector<ItemGift> GetRandomGiftShowItems(uint32 p_IdItem);
  bool HasDesc(uint32 p_IdItem);
  bool IsSkinShow(uint32 p_IdItem);
  uint32 GetItemCount(uint32 p_IdItem){ return 0; }
};