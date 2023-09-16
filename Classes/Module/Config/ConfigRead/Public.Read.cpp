#include "Public.Read.h"

PublicRead *PublicRead::Get(){
  static PublicRead *s_PublicRead = nullptr;
  if (s_PublicRead == nullptr){
    s_PublicRead = new PublicRead();
  }
  return s_PublicRead;
}

GString PublicRead::GetIcon(int32 pResID){
  return "1001.png";
}

GString PublicRead::GetIcon(EResource pResID){
  return "1001.png";
}