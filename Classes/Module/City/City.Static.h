#pragma once
#include "Base/BaseTypeDef.h"
#include "City.Type.h"
#include "City.Cell.h"

class CityStatic{
  static Guid idCurrentCity;
  int32 _CurrentCityID;
  public:
  GHashMap<Guid, CityCell> _CityList;
public:
  static Guid getIDCurrentCity(){
    return idCurrentCity;
  }

  static CityStatic *Get();

  static void setIDCurrentCity(Guid idCity){
    idCurrentCity = idCity;
  }
  RCity& GetCurrentCity();
  static RCity& getCity(Guid idCity);
  int32 GetCurrentCityID(){
    return _CurrentCityID;
  }

  void SetCurrentCityID(int32 pCityID){
    _CurrentCityID = pCityID;
  }

  GHashMap<Guid, CityCell> &GetCityList(){
    return _CityList;
  }
};