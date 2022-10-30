#include "CityBuilding.Mgr.h"
#include "Scene/City/CityScene.View.h"

CityBuildingMgr *CityBuildingMgr::Get()
{
  static CityBuildingMgr *l_Instance = new CityBuildingMgr();
  return l_Instance;
}

void CityBuildingMgr::InitWithData(MainCityView *p_View)
{
  // ...
}