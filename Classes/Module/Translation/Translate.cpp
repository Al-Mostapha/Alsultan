#include "Translate.h"
#include "Include/IncludeBase.h"
#include "Base/Type/XJson.h"
#include "Module/Net/NetBase.Module.h"

Translate::Translate(/* args */)
{
}

Translate::~Translate()
{
}


GString Translate::i18n(const char *key, GMap<GString, GString> p_Replace)
{
  GString l_Translated = Translate::Get()->GetTranslation(key);
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

const GString &Translate::GetTranslation(const GString &pKey)
{
  auto l_Found = _Translation.find(pKey);
  if(l_Found != _Translation.end())
    return l_Found->second;
  return pKey;
}

void ParseJson(const XJson &pJson){
  for(auto l_Key : pJson.items()){
    Translate::Get()->GetTranslations()[l_Key.key()] = l_Key.value();
  }
}
void Translate::LoadTranslation()
{
  NetModule::Get()->GetJsonFile("/Static/Json/Translation/En.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("Translation.json Not loaded");
    Logger::Get()->Log("Translation.json loaded");
    ParseJson(pJson);
    _Loaded = true;
  });
}



Translate *Translate::Get()
{
  static Translate l_Translate;
  return &l_Translate;
}

