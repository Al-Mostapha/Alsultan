#include "Resource.Ctrl.h"
#include "Resource.Static.h"

ResourceCtrl *ResourceCtrl::Get(){
  static ResourceCtrl *l_Instance = new ResourceCtrl();
  return l_Instance;
}

GPair<bool, RCostResourceEnough> ResourceCtrl::IsEnough(RResource& p_Resource){
  RCityResource l_CityRes = ResourceStatic::getCityResource();
  RCostResourceEnough l_IsEnough;
  // l_IsEnough.Coin    = l_CityRes.Coin    >= p_Resource.Coin;
  // l_IsEnough.Grain   = l_CityRes.Grain   >= p_Resource.Grain;
  // l_IsEnough.Lumber  = l_CityRes.Lumber  >= p_Resource.Lumber;
  // l_IsEnough.Crystal = l_CityRes.Crystal >= p_Resource.Crystal;
  // l_IsEnough.Iron    = l_CityRes.Iron    >= p_Resource.Iron;
  // l_IsEnough.Silver  = l_CityRes.Silver  >= p_Resource.Silver;

  // l_IsEnough.CoinNeed    = l_CityRes.Coin    - p_Resource.Coin;
  // l_IsEnough.GrainNeed   = l_CityRes.Grain   - p_Resource.Grain;
  // l_IsEnough.LumberNeed  = l_CityRes.Lumber  - p_Resource.Lumber;
  // l_IsEnough.CrystalNeed = l_CityRes.Crystal - p_Resource.Crystal;
  // l_IsEnough.IronNeed    = l_CityRes.Iron    - p_Resource.Iron;
  // l_IsEnough.SilverNeed  = l_CityRes.Silver  - p_Resource.Silver;

  return GPair<bool, RCostResourceEnough>::Make(
    false,
    l_IsEnough
  );
}

int32 ResourceCtrl::GetResCount(EResource p_Res){
  // local curcity = self:getCurCity()
  // if curcity.resList then
  //   local ret = curcity.resList[tostring(resid)]
  //   if ret then
  //     return math.floor(tonumber(ret))
  //   end
  // else
  // end
  return 0;
}