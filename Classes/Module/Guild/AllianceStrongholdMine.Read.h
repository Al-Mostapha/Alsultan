#pragma once 
#include "Base/BaseTypeDef.h"
#include "Alliance.Type.h"
#include "Module/CityResource/Resource.Enum.h"

class AllianceStrongholdMineRead
{
  public:
  static AllianceStrongholdMineRead *Get();
  EResource GetMineOutputId(int32 pMineID);
  int32 GetMineOutputNum(int32 pMineID);
  GString GetMineImage(int32 pMineID);
  GString GetMineName(int32 pMineID);
  GOpt<RStrongholdBuildConfig> GetGateClientCfg(int32 pMineID);
  uint32 GetGateLv(int32 pMineID);
};