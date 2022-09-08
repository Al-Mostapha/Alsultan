#include "Resource.Static.h"
#include "Module/City/City.Static.h"

TCityResource& ResourceStatic::getCityResource(){
  return CityStatic::getCurrentCity().CityResource;
}

