
#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XMap.h"
#include "Base/Containers/HashMap.h"


class Translate
{
private:
  /* data */
public:
  Translate(/* args */);
  ~Translate();
  static Translate *Get();
  void Init() { }
  static GString i18n(const char *key, GMap<GString, GString> p_Replace = GMap<GString, GString>());
  GHashMap<GString, GString> &GetTranslations(){ return _Translation; }
  void LoadTranslation();

  private:
  const GString &GetTranslation(const GString &pKey);
  GHashMap<GString, GString> _Translation;
  bool _Loaded = false;

};

