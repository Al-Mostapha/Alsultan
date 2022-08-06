#include "Translate.h"
#include "Include/IncludeBase.h"
Translate::Translate(/* args */)
{
}

Translate::~Translate()
{
}


GString Translate::i18n(const char *key)
{
  return GString(key);
}
 