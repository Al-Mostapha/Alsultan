#include "StarRhapsody.Ctrl.h"

StarRhapsodyCtrl *StarRhapsodyCtrl::Get() {
  static StarRhapsodyCtrl *s_pInstance = nullptr;
  if (s_pInstance == nullptr) {
    s_pInstance = new StarRhapsodyCtrl();
  }
  return s_pInstance;
}

void StarRhapsodyCtrl::ResetResetTimes() {
  
}