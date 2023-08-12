#include "OfficialInfo.Read.h"

OfficialInfoRead *OfficialInfoRead::Get(){
  static OfficialInfoRead *lOfficialInfoRead = new OfficialInfoRead();
  return lOfficialInfoRead;
}

GOpt<ROfficialInfo> OfficialInfoRead::GetInfoByType(EShowOfficialType pType){
  return {};
}