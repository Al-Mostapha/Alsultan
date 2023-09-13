#pragma once
#include "LegendLord.Enum.h"
#include "Base/BaseTypeDef.h"
#include "Module/Player/Official/Official.Type.h"


class HegemonRead
{
public:
  static HegemonRead *Get();
  GOpt<GString> GetOfficialIcon(int32 pOfficialId){
    return {};
  }
  bool JudgeIsGood(int32 pOfficialId){
    return false;
  }

  GString GetName(int32 pBuildTypeID){
    return "HegemonReadName";
  };

  GString GetImage(int32 pBuildTypeID){
    return "LegendaryKing_palace.png";
  };

  bool IsLegendLordBuilding(int32 pBuildTypeID){
    return true;
  };
};