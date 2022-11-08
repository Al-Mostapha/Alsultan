
#include "Interior.Ctrl.h"

InteriorCtrl *InteriorCtrl::Get() {
  static InteriorCtrl *s_pInstance = nullptr;
  if (s_pInstance == nullptr) {
    s_pInstance = new InteriorCtrl();
  }
  return s_pInstance;
}

void InteriorCtrl::ResetLoginDays(){
  
}