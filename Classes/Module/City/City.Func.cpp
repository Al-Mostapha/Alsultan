#include "City.Func.h"
#include "Scene/City/CityScene.View.h"
MainCityFunctions *MainCityFunctions::Get(){
  static MainCityFunctions *l_Instance = new MainCityFunctions();
  return l_Instance;
}

void MainCityFunctions::UpdateLockArea(MainCityView *p_View){
  // ...
}