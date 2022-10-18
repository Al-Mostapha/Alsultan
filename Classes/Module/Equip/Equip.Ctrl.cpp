#include "Equip.Ctrl.h"

EquipCtrl *EquipCtrl::Get() {
  static EquipCtrl *s_EquipCtrl = new EquipCtrl();
  return s_EquipCtrl;
}

bool EquipCtrl::IsCanGetEquip() {
  return false;
}