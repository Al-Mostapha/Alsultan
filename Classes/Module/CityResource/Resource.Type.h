#pragma once
#include "Include/IncludeBase.h"

struct RResource
{
  uint32 Coin = 0;
  uint32 Grain = 0;
  uint32 Lumber = 0;
  uint32 Iron = 0;
  uint32 Silver = 0;
  uint32 Metal = 0;
  uint32 Crystal = 0;
  uint32 MeteorCrystal = 0;
};

struct RCostResourceEnough
{
  bool Coin = false;
  bool Grain = false;
  bool Lumber = false;
  bool Iron = false;
  bool Silver = false;
  bool Metal = false;
  bool Crystal = false;
  bool MeteorCrystal = false;

  int32 CoinNeed = 0;
  int32 GrainNeed = 0;
  int32 LumberNeed = 0;
  int32 IronNeed = 0;
  int32 SilverNeed = 0;
  int32 MetalNeed = 0;
  int32 CrystalNeed = 0;
  int32 MeteorCrystalNeed = 0;
};

struct RCityResource : public RResource
{
  int32 idPlayer;
  int32 idCity;
  int32 CoinIn;
  int32 GrainIn;
  int32 LumberIn;
  int32 SilverIn;
  int32 IronIn;
  int32 CrystalIn;
  int32 CoinOut;
  int32 GrainOut;
  int32 LumberOut;
  int32 SilverOut;
  int32 IronOut;
  int32 CrystalOut;
  int32 CoinCap;
  int32 GrainCap;
  int32 LumberCap;
  int32 SilverCap;
  int32 IronCap;
  int32 CrystalCap;
  void fromJson(GJson *json)
  {
    if (json == nullptr)
      return;
    idPlayer = json->GetInt("idPlayer", 0);
    idCity = json->GetInt("idCity", 0);
    Coin = json->GetInt("Coin", 0);
    Grain = json->GetInt("Grain", 0);
    Lumber = json->GetInt("Lumber", 0);
    Silver = json->GetInt("Silver", 0);
    Iron = json->GetInt("Iron", 0);
    Crystal = json->GetInt("Crystal", 0);
    CoinIn = json->GetInt("CoinIn", 0);
    GrainIn = json->GetInt("GrainIn", 0);
    LumberIn = json->GetInt("LumberIn", 0);
    SilverIn = json->GetInt("SilverIn", 0);
    IronIn = json->GetInt("IronIn", 0);
    CrystalIn = json->GetInt("CrystalIn", 0);
    CoinOut = json->GetInt("CoinOut", 0);
    GrainOut = json->GetInt("GrainOut", 0);
    LumberOut = json->GetInt("LumberOut", 0);
    SilverOut = json->GetInt("SilverOut", 0);
    IronOut = json->GetInt("IronOut", 0);
    CrystalOut = json->GetInt("CrystalOut", 0);
    CoinCap = json->GetInt("CoinCap", 0);
    GrainCap = json->GetInt("GrainCap", 0);
    LumberCap = json->GetInt("LumberCap", 0);
    SilverCap = json->GetInt("SilverCap", 0);
    IronCap = json->GetInt("IronCap", 0);
    CrystalCap = json->GetInt("CrystalCap", 0);
  }
};
