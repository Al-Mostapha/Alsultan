#include "WindTower.Read.h"

WindTowerRead *WindTowerRead::Get() {
  static WindTowerRead *pInstance = nullptr;
  if (pInstance == nullptr) {
    pInstance = new WindTowerRead();
  }
  return pInstance;
}

GTime WindTowerRead::GetTaskTimeByQuestId(int32 pQuestID) {
  return 0;
}