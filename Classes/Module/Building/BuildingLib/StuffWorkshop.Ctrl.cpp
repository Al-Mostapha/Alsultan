#include "StuffWorkshop.Ctrl.h"

StuffWorkShopCtrl *StuffWorkShopCtrl::Get() {
  static StuffWorkShopCtrl *s_StuffWorkShopCtrl = new StuffWorkShopCtrl();
  return s_StuffWorkShopCtrl;
}

uint32 StuffWorkShopCtrl::GetDoneID() {
  return 0;
}
void  StuffWorkShopCtrl::SendGetStuff() {}