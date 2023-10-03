#include "City.Service.h"
#include "Module/Net/NetBase.Module.h"

CityService *CityService::Get()
{
    static CityService *instance = new CityService();
    return instance;
}

void CityService::Init()
{
}

IRequest *CityService::GetCityList()
{
  return NetModule::Get()->GetJson(
    "/api/City/GetCityList"
  );
}

IRequest *CityService::GetCityInfo(int32 pCityId)
{
  return NetModule::Get()->GetJson(
    "/api/City/GetCityInfo"
  );
}