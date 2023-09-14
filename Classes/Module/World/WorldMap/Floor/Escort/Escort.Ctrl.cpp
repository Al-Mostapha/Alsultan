#include "Escort.Ctrl.h"

EscortCtrl *EscortCtrl::Get(){
  static EscortCtrl *sEscortCtrl = nullptr;
  if(!sEscortCtrl)
    sEscortCtrl = new EscortCtrl();
  return sEscortCtrl;
}

uint32 EscortCtrl::GetEscortCityLevelMin(){
  return 1;
}