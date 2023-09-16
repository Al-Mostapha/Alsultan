#include "EndlessTrials.Ctrl.h"

EndlessTrialsCtrl *EndlessTrialsCtrl::Get(){
  static EndlessTrialsCtrl *sInstance = nullptr;
  if (!sInstance) {
    sInstance = new EndlessTrialsCtrl();
  }
  return sInstance;
}
GHashMap<uint32, REndlessTrailsSnowMountain> EndlessTrialsCtrl::GetMountainConfig(){
  return _MountainConfig;
}
REndlessTrailsSnowMountain EndlessTrialsCtrl::GetMountainConfig(uint32 pID){
  return REndlessTrailsSnowMountain{};
}