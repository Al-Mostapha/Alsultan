#pragma once
#include "Item.Enum.h"
#include "Item.Type.h"
#include "Base/BaseTypeDef.h"

class BackPack {
  private:
    void Ctor(EBackpackDef);
  public :
    static BackPack *Create(EBackpackDef);
    GVector<RClassifyItem> GetClassifyList(EItemCategory);
    int32 GetShowUnitNum();
};