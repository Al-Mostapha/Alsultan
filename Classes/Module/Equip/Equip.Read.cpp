#include "Equip.Read.h"

EquipRead *EquipRead::Get()
{
  static EquipRead *s_EquipRead = new EquipRead();
  return s_EquipRead;
}

GString EquipRead::GetName(int32 p_IDEquip)
{
  return GString("EquipName");
}