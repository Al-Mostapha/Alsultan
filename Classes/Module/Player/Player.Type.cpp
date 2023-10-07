#include "Player.Type.h"

void RPlayer::FromJson(const XJson &pJson){
  if(pJson.contains("CityList"))
  {
    auto lCityList = pJson["CityList"];
    for(auto lCity : lCityList)
    {
      RCity lCityInfo;
      lCityInfo.FromJson(lCity);
      _Cities[lCityInfo.idCity] = lCityInfo;
    }
  }
}