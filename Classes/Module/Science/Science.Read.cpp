#include "Science.Read.h"

ScienceRead *ScienceRead::Get(){
  static ScienceRead *s_ScienceRead = new ScienceRead();
  return s_ScienceRead;
}

const char *ScienceRead::GetIcon(EScience p_Science){
  return "icon_item_common.png";
}

bool ScienceRead::IsScience(int32 p_Science){
  return true;
}

GString ScienceRead::GetName(EScience p_Science){
  return "Science";
}

GString ScienceRead::GetName(int32 p_Science){
  return GetName(static_cast<EScience>(p_Science));
}