#include "City.Static.h"
#include "Module/Player/Player.Static.h"
TCity& CityStatic::getCity(Guid idCity){
  return PlayerStatic::getPlayer().City;
}

TCity& CityStatic::getCurrentCity(){
  return getCity(getIDCurrentCity());
}