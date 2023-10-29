#include "PrivilegeGift.Ctrl.h"

PrivilegeGiftCtrl *PrivilegeGiftCtrl::Get(){
  static auto lPrivilegeGiftCtrl = new PrivilegeGiftCtrl();
  return lPrivilegeGiftCtrl;
}