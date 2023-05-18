#include "BackPack.h"

BackPack *BackPack::Create(EBackpackDef p_BackpackDef){
  auto l_BackPack = new BackPack();
  l_BackPack->Ctor(p_BackpackDef);
  return l_BackPack;
}

void BackPack::Ctor(EBackpackDef p_BackpackDef){

}

GVector<RClassifyItem> BackPack::GetClassifyList(EItemCategory p_ItemCategory){
  GVector<RClassifyItem> l_ClassifyList;
  return l_ClassifyList;
}

int32 BackPack::GetShowUnitNum(){
  return 0;
}

