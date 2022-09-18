#pragma once
#include "Include/IncludeBase.h"
#include "City.Type.h"

class CityStatic{
  static Guid idCurrentCity;
public:
  static Guid getIDCurrentCity(){
    return idCurrentCity;
  }

  static void setIDCurrentCity(Guid idCity){
    idCurrentCity = idCity;
  }
  static RCity& getCurrentCity();
  static RCity& getCity(Guid idCity);
};