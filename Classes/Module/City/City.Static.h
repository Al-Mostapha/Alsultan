#pragma once
#include "Base/BaseTypeDef.h"
#include "City.Type.h"

class CityStatic{
  static Guid idCurrentCity;
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
};