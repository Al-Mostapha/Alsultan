#include "CastleSkin.Read.h"

CastleSkinRead *CastleSkinRead::Get()
{
  static CastleSkinRead *sCastleSkinRead = nullptr;
  if (!sCastleSkinRead)
  {
    sCastleSkinRead = new CastleSkinRead();
  }
  return sCastleSkinRead;
}

const GString &CastleSkinRead::GetNameFloor(int32 pSkinID, bool pFromMemory){
  return "frame_castle_name_egypt01.png";
}

const GString &CastleSkinRead::GetMapImage(int32 pSkinID, bool pFromMemory){
  return "Map_castle_2022corban.png";
}
EBuildingCastleModel CastleSkinRead::GetCastleType(int32 pSkinID){
  return EBuildingCastleModel::Classical;
}