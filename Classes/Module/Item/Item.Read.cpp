#include "Item.Read.h"

ItemRead *ItemRead::Get(){
  static auto l_Inst = new ItemRead();
  return l_Inst;
}

GString ItemRead::GetIcon(int32 p_IdItem){
  return "icon_item_common.png";
}

GString ItemRead::GetName(int32 p_IdItem){
  return "Item";
}