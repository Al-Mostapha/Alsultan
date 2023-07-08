#include "NationalFlag.Read.h"

NationalFlagRead *NationalFlagRead::Get(){
  static NationalFlagRead *l_NationalFlagRead = new NationalFlagRead();
  return l_NationalFlagRead;
}

GString NationalFlagRead::GetImgByID(int32 p_KingdomId){
  return "Nationalflag_1001.png";
}