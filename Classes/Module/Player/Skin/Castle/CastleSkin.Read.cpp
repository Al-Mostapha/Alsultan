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