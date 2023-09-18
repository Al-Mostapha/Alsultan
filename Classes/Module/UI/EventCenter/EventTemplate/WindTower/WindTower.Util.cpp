#include "WindTower.Util.h"

WindTowerUtil *WindTowerUtil::Get(){
  static WindTowerUtil *s_WindTowerUtil = nullptr;
  if (s_WindTowerUtil == nullptr){
    s_WindTowerUtil = new WindTowerUtil();
  }
  return s_WindTowerUtil;
}

GTime WindTowerUtil::GetBuildCD(Vec2 pPoint){
  return 0;
}