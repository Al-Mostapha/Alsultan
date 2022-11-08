#include "LoginGift.Ctrl.h"


LoginGiftCtrl *LoginGiftCtrl::Get() {
  static LoginGiftCtrl *s_pInstance = nullptr;
  if (s_pInstance == nullptr) {
    s_pInstance = new LoginGiftCtrl();
  }
  return s_pInstance;
}

void LoginGiftCtrl::ResetLoginDays() {

}