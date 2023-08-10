#include "KingStar.Ctrl.h"

KingStarCtrl *KingStarCtrl::Get(){
  static KingStarCtrl *_KingStarCtrl = nullptr;
  if(_KingStarCtrl == nullptr){
    _KingStarCtrl = new KingStarCtrl();
  }
  return _KingStarCtrl;
}
