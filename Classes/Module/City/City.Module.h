#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Building/Building.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Player/Player.Module.h"
#include "Module/Building/Building.Module.h"
#include "Scene/City/CityScene.Enum.h"
#include "Module/City/City.Type.h"
#include "Module/Player/Player.Static.h"
#include "Module/City/City.Static.h"

#include "malloc.h"

class CityModule
{
public:

  static CityModule *Get();
  void Init();
  void StartGame();

  static void GetPlayerCity(int32 idPayer)
  {
    // NetModule::getJson(
    //   "/api/City/getCity",
    //   [](GJson *json)
    //   {
    //       if (json == nullptr)
    //           return;
    //       // DSCity city;
    //       // SultanPlayer.City.fromJson(json);
    //       // SultanPlayer.City.CityBuilding.fromJson(json);
    //       //  city.CityBuilding.fromJson(json);
    //   });
  }
  static void showCityBuilding();
  static void showCityEffect();
  static RCity& getCurrentCity(){
      return CityStatic::Get()->GetCurrentCity();
  }
};