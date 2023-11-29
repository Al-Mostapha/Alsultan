#include "City.Service.h"
#include "Base/Logger/Logger.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/City/City.Type.h"
#include "Module/Player/Player.Static.h"
#include "Module/City/City.Static.h"
#include "Module/City/City.Cell.h"

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
    "/api/ACity/GetCityList", 
    [](const XJson &lJson, auto lReq){
      if(lJson.is_null()){
        Logger::Get()->Log("GetCityList is null");
        return;
      }
      auto lState = lJson.value("State", "");
      if(lState != "Ok"){
        Logger::Get()->Log("GetCityList State is not Success");
        return;
      }
      auto lCityList = lJson.value("CityList", XJson::array());
      for(auto lCity : lCityList){
        CityCell lCityCell;
        lCityCell.FromJson(lCity);
        CityStatic::Get()->GetCityList()[lCityCell._CityID] = lCityCell;
      }

      if(CityStatic::Get()->GetCityList().size() > 0){
        auto lFirstCity = CityStatic::Get()->GetCityList().begin()->second;
        CityStatic::Get()->SetCurrentCityID(lFirstCity._CityID);
      }
    }
  );
}

IRequest *CityService::GetCityInfo(int32 pCityId)
{
  return NetModule::Get()->GetJson(
    "/api/ACity/GetCityInfo", XJson::object({
      {"CityID", pCityId}
    }),
    [](auto lJson, auto lReq){

    }
  );
}