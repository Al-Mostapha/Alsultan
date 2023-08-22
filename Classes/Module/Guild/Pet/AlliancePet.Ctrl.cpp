#include "AlliancePet.Ctrl.h"

AlliancePetCtrl *AlliancePetCtrl::Get(){
  static auto *pInstance = new AlliancePetCtrl();
  return pInstance;
}
EAlliancePetState AlliancePetCtrl::GetAlliancePetState(){
  return EAlliancePetState::CALL;
}