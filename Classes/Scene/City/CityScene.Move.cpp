#include "CityScene.Move.h"
#include "CityScene.View.h"

MainCityBuildingMove *MainCityBuildingMove::Get(){
  static MainCityBuildingMove *s_MainCityBuildingMove = new MainCityBuildingMove();
  return s_MainCityBuildingMove;
}


void MainCityBuildingMove::Init(MainCityView *p_MainCityView){
  // ...
}