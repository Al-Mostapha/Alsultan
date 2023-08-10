#include "LegendLord.Ctrl.h"

LegendLordCtrl *LegendLordCtrl::Get(){
  static LegendLordCtrl *_LegendLordCtrl = nullptr;
  if(_LegendLordCtrl == nullptr){
    _LegendLordCtrl = new LegendLordCtrl();
  }
  return _LegendLordCtrl;
}
