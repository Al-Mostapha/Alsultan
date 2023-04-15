#include "Item.Ctrl.h"
#include "Item.Static.h"

ItemCtrl *ItemCtrl::Get(){
  ItemCtrl *l_Instance = new ItemCtrl();
  return l_Instance;
}

GPair<bool, uint32> ItemCtrl::IsEnough(uint32 p_IdItem, uint32 p_Amount){
  return GPair<bool, uint32>::Make(true, 0);
}

GPair<bool, GVector<RCostItemEnough>> ItemCtrl::IsEnough(GVector<RCostItem> &p_CostItem){
  bool l_IsEnough = true;
  GVector<RCostItemEnough> l_CostItemEnough;
  RCostItemEnough l_OneCostItemEnough;
  GPair<bool, uint32> l_OneIsEnough = GPair<bool, uint32>::Make(false, 0);
  for(auto &l_OneCost : p_CostItem){
    l_OneIsEnough = IsEnough(l_OneCost.idItem, l_OneCost.amount);
    l_OneCostItemEnough._ItemCount = l_OneCost.amount;
    l_OneCostItemEnough.AmountLack = l_OneIsEnough.Second - l_OneCost.amount;
    //TODO
    l_OneCostItemEnough._CurCount  = l_OneIsEnough.Second;
    l_OneCostItemEnough.idItem  = l_OneCost.idItem;
    l_OneCostItemEnough._IsReach  = l_OneIsEnough.First;
    
    if(!l_OneCostItemEnough._IsReach)
      l_IsEnough = false;
    l_CostItemEnough.push_back(l_OneCostItemEnough);
  }
  return GPair<bool, GVector<RCostItemEnough>>::Make(l_IsEnough, l_CostItemEnough);
}

uint32 ItemCtrl::GetItemPrice(uint32 p_IdItem){
  return 0;
}

GVector<ItemCtrl::ItemGift> ItemCtrl::GetRandomGiftShowItems(uint32 p_IdItem){
  return GVector<ItemCtrl::ItemGift>();
}

bool ItemCtrl::HasDesc(uint32 p_IdItem){
  return false;
}

bool ItemCtrl::IsSkinShow(uint32 p_IdItem){
  return false;
}

