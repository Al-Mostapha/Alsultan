#include "PalaceInfo.Read.h"

PalaceInfoRead *PalaceInfoRead::Get(){
  static PalaceInfoRead *sPalaceInfoRead = nullptr;
  if (!sPalaceInfoRead){
    sPalaceInfoRead = new PalaceInfoRead();
  }
  return sPalaceInfoRead;
}

GString PalaceInfoRead::GetImg(int32 pID, bool pFromMemory){
  return "Map_King_castle_01.png";
}