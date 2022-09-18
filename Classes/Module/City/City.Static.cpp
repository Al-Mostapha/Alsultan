#include "City.Static.h"
#include "Module/Player/Player.Static.h"

Guid CityStatic::idCurrentCity;
RCity& CityStatic::getCity(Guid idCity){
  return PlayerStatic::getPlayer().City;
}

RCity& CityStatic::getCurrentCity(){
  return getCity(getIDCurrentCity());
}