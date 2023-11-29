#include "Translate.h"
#include "Include/IncludeBase.h"

Translate::Translate(/* args */)
{
}

Translate::~Translate()
{
}


GString Translate::i18n(const char *key, GMap<GString, GString> p_Replace)
{
  GString l_Translated(key) ;
  if(p_Replace.size()){
    for(auto l_Key : p_Replace){
      // GString l_WrappedKey = cocos2d::StringUtils::format("%{%s}", l_Key.first.c_str());
      GString l_WrappedKey = GString("%{") + l_Key.first + "}";
      auto l_Found = l_Translated.find(l_WrappedKey);
      if(l_Found != std::string::npos)
        l_Translated.replace(l_Found, l_WrappedKey.length(), l_Key.second);
    }
  }
  return l_Translated;
}