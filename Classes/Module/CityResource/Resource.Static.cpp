#include "Resource.Static.h"
#include "Module/City/City.Static.h"

RCityResource& ResourceStatic::getCityResource(){
  return CityStatic::Get()->GetCurrentCity().CityResource;
}

