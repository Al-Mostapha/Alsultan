#include "LordOfficial.Read.h"

LordOfficialRead *LordOfficialRead::Get()
{
  static LordOfficialRead sInstance;
  return &sInstance;
}


  GOpt<GString> LordOfficialRead::GetOfficialIcon(EShowOfficialType pType, int32 pOfficialId){
    return GOpt<GString>();
  }