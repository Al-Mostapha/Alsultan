#include "AllianceActive.Ctrl.h"

AllianceActiveCtrl* AllianceActiveCtrl::Get() {
  static AllianceActiveCtrl* instance = nullptr;
  if (instance == nullptr) {
    instance = new AllianceActiveCtrl();
  }
  return instance;
}

int32 AllianceActiveCtrl::GetCanReceiveTaskNum() {
  return 0;
}