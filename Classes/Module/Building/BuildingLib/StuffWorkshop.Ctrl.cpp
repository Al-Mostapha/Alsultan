#include "StuffWorkshop.Ctrl.h"

StuffWorkshopCtrl *StuffWorkshopCtrl::Get(){
  static StuffWorkshopCtrl *instance = new StuffWorkshopCtrl();
  return instance;
}

uint32 StuffWorkshopCtrl::GetDoneID() {
  return 0;
}

void  StuffWorkshopCtrl::SendGetStuff() {}