#pragma once
#include "LegendLord.Enum.h"
#include "Base/BaseTypeDef.h"
#include "Module/Player/Official/Official.Type.h"


class LegendKingRead
{
public:
  static LegendKingRead *Get();
  GOpt<ROfficialInfo> GetOfficialInfo(ELegendBuffType pType, uint32 pID, int32 pMapId = 0){
    return {};
  }
};