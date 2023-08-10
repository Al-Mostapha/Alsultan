#pragma once
#include "Include/IncludeBase.h"

class EquipRead
{
  public: 
    static EquipRead *Get();
    GString GetName(int32 p_IDEquip);
    GString GetIcon(int32 p_IDEquip);
};