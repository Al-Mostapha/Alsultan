#include "CityBuildingSpritePool.h"

CityBuildingSpritePool *CityBuildingSpritePool::Get(){
  static CityBuildingSpritePool *s_Instance =  new CityBuildingSpritePool();
  return s_Instance;
}

void CityBuildingSpritePool::Init(){
  // ...
}