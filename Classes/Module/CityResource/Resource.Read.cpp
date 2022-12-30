#include "Resource.Read.h"

ResourceRead *ResourceRead::Get(){
  static ResourceRead *s_ResourceRead = new ResourceRead();
  return s_ResourceRead;
}

const char *ResourceRead::GetIcon(EResource p_Resource){
  return "icon_item_common.png";
}

GString ResourceRead::GetName(EResource p_Resource){
  return "Resource";
}

GString ResourceRead::GetName(int32 p_Resource){
  return GetName(static_cast<EResource>(p_Resource));
}