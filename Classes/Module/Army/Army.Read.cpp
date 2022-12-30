#include "Army.Read.h"

ArmyRead *ArmyRead::Get(){
  static ArmyRead *s_ArmyRead = new ArmyRead();
  return s_ArmyRead;
}

const char *ArmyRead::GetIcon(EArmy p_Army){
  return "icon_item_common.png";
}

GString ArmyRead::GetName(int32 p_IdArmy){
  return "ArmyName";
}

GString ArmyRead::GetName(EArmy p_IdArmy){
  return "ArmyName";
}