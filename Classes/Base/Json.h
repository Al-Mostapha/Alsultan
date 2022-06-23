#pragma once
#include "external/json/document.h"
#include "Include/IncludeBase.h"

class GJson : public rapidjson::Document
{
    static const char *kTypeNames[];

public:
    const rapidjson::Value::Ch *GetString(const char *str, rapidjson::Value::Ch *DefaultVal = nullptr);
    int32 GetInt(const char *str, int DefaultVal = -1);
    float GetFloat(const char *str, float DefaultVal = -1);
    bool GetBool(const char *str, bool DefaultVal = false);
    GJson *GetJsonObject(const char *str, GJson *DefaultVal = nullptr);
};