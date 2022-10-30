#include "City.Ctrl.h"

CityCtrl *CityCtrl::Get(){
  static CityCtrl *l_Instance  = new CityCtrl();
  return l_Instance;
}
// THis function should return all buildings in the city
GVector<IBuilding *> CityCtrl::GetBuildList(){
  return GVector<IBuilding *>();
}

bool CityCtrl::GetCastleUpgradePopStatus(){
  return false;
}