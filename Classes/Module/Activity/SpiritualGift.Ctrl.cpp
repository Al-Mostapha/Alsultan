#include "SpiritualGift.Ctrl.h"

SpiritualGiftCtrl *SpiritualGiftCtrl::Get() {
  static SpiritualGiftCtrl *s_SpiritualGiftCtrl = nullptr;
  if (s_SpiritualGiftCtrl == nullptr) {
    s_SpiritualGiftCtrl = new SpiritualGiftCtrl();
  }
  return s_SpiritualGiftCtrl;
}

void SpiritualGiftCtrl::ResetDrawCount() {
  
}