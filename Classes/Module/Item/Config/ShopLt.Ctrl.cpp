#include "ShopLt.Ctrl.h"

ShopLtCtrl *ShopLtCtrl::Get(){
  static ShopLtCtrl *l_Inst = new ShopLtCtrl();
  return l_Inst;
}

bool ShopLtCtrl::GetShopNewTag(const char *p_For){
  return true;
}


EItemType ShopLtCtrl::GetItemType(EItemID){
  return EItemType::None;
}