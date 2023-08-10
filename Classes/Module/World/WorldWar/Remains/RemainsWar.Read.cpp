#include "RemainsWar.Read.h"

RemainsWarRead* RemainsWarRead::Get(){
  static RemainsWarRead* pInstance = nullptr;
  if (pInstance == nullptr){
    pInstance = new RemainsWarRead();
  }
  return pInstance;
}

const char *RemainsWarRead::GetCampIcon(int32 camp){
  return "icon_yjzz_lf.png";
}
