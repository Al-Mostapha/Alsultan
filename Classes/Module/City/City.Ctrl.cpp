#include "City.Ctrl.h"

CityCtrl *CityCtrl::Get(){
  static CityCtrl *l_Instance  = new CityCtrl();
  return l_Instance;
}