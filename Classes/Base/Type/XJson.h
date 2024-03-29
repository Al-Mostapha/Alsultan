#pragma once
#include "Base/Logger/Logger.h"
#define JSON_TRY_USER if(true)
#define JSON_CATCH_USER(exception) if(false)
#define JSON_THROW_USER(exception)                           \
    {Logger::Get()->LogJsonError(exception);\
    }

#include "Json/XJson.Base.h"

using XJson = nlohmann::json;


// class XJson : public Json{
//   nlohmann::json _Json;
//   public:
//   static XJson Create(const GString &str);
//   // create a XJson object from nlohmann::json;
//   static XJson Create(const nlohmann::json &json);
//   GString GetString(const char *str,const GString &DefaultVal = "") const;
//   int32 GetInt(const char *str, int DefaultVal = -1) const;
//   float GetFloat(const char *str, float DefaultVal = -1) const;
//   bool GetBool(const char *str, bool DefaultVal = false) const;
//   Json GetJsonObject(const char *str,const Json &DefaultVal = {}) const;
//   GString ToString();
// };