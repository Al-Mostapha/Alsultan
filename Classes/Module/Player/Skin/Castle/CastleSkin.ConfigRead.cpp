#include "CastleSkin.ConfigRead.h"

CastleSkinConfigRead *CastleSkinConfigRead::Get()
{
  static CastleSkinConfigRead *sCastleSkinConfigRead = nullptr;
  if (!sCastleSkinConfigRead)
  {
    sCastleSkinConfigRead = new CastleSkinConfigRead();
  }
  return sCastleSkinConfigRead;
}


GOpt<Vec2> CastleSkinConfigRead::GetSkinOffset(EBuildingCastleModel pModel){
  return {};
}

GOpt<GTuple<float, Vec2>> CastleSkinConfigRead::GetSkinWarLvConfig(EBuildingCastleModel pModel, int32 pWarLv){
  return {
    {
      0, Vec2::ZERO
    }
  };
}