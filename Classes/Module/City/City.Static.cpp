#include "City.Static.h"
#include "Module/Player/Player.Static.h"

Guid CityStatic::idCurrentCity;

CityStatic *CityStatic::Get(){
  static CityStatic *pCityStatic = new CityStatic();
  return pCityStatic;
}

RCity& CityStatic::getCity(Guid idCity){
  return PlayerStatic::getPlayer()._Cities[idCity];
}

RCity& CityStatic::GetCurrentCity(){
  return getCity(getIDCurrentCity());
}