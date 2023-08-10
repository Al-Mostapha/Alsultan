#include "Hegemon.Ctrl.h"

HegemonCtrl *HegemonCtrl::Get(){
  static HegemonCtrl *_HegemonCtrl = nullptr;
  if(_HegemonCtrl == nullptr){
    _HegemonCtrl = new HegemonCtrl();
  }
  return _HegemonCtrl;
}
