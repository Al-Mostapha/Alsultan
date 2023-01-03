#include "AllianceCounterSys.Ctrl.h"

AllianceCounterSysCtrl *AllianceCounterSysCtrl::Get() {
  static AllianceCounterSysCtrl *s_Instance = new AllianceCounterSysCtrl();
  return s_Instance;
}

int32 AllianceCounterSysCtrl::GetNewPoint() {
  return 1;
}
