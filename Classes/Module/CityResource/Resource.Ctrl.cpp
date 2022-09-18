#include "Resource.Ctrl.h"
#include "Resource.Static.h"

RResourceIsEnough ResourceCtrl::isResourceEnough(RResource& p_Resource){
  RCityResource l_CityRes = ResourceStatic::getCityResource();
  RResourceIsEnough l_IsEnough;
  l_IsEnough.Coin    = l_CityRes.Coin    >= p_Resource.Coin;
  l_IsEnough.Grain   = l_CityRes.Grain   >= p_Resource.Grain;
  l_IsEnough.Lumber  = l_CityRes.Lumber  >= p_Resource.Lumber;
  l_IsEnough.Crystal = l_CityRes.Crystal >= p_Resource.Crystal;
  l_IsEnough.Iron    = l_CityRes.Iron    >= p_Resource.Iron;
  l_IsEnough.Silver  = l_CityRes.Silver  >= p_Resource.Silver;
  return l_IsEnough;
}