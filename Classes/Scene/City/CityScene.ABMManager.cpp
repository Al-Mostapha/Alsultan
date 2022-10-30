#include "CityScene.ABMManager.h"

MainCityABMManager *MainCityABMManager::Get(){
  static MainCityABMManager *s_MainCityABMManager = new MainCityABMManager();
  return s_MainCityABMManager;
}

void MainCityABMManager::Init(MainCityView *p_MainCityView){
  // ...
}