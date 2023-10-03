#include "Json.h"
#include "external/json/stringbuffer.h"
#include "external/json/writer.h"
#undef GetObject
const char *GJson::kTypeNames[] =
    {"Null", "False", "True", "Object", "Array", "String", "Number"};

const rapidjson::Value::Ch *GJson::GetString(const char *str, rapidjson::Value::Ch *DefaultVal)
{
    if (!HasMember(str))
    {
        cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
        return nullptr;
    }

    rapidjson::Value &value = operator[](str);
    if (value.IsString())
    {
        return value.GetString();
    }
    cocos2d::log("Error Parsing String: %s For Value of %s ", str, kTypeNames[value.GetType()]);
    return DefaultVal;
}

int32 GJson::GetInt(const char *str, int32 DefaultVal)
{
    if (!HasMember(str))
    {
        cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
        return DefaultVal;
    }
    rapidjson::Value &value = operator[](str);
    if (value.IsInt())
    {
        return value.GetInt();
    }
    cocos2d::log("Error Parsing Int: %s For Value of %s ", str, kTypeNames[value.GetType()]);
    return DefaultVal;
}

float GJson::GetFloat(const char *str, float DefaultVal)
{
    if (!HasMember(str))
    {
        cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
        return DefaultVal;
    }
    rapidjson::Value &value = operator[](str);
    if (value.IsFloat())
    {
        return value.GetFloat();
    }
    cocos2d::log("Error Parsing Float: %s For Value of %s ", str, kTypeNames[value.GetType()]);
    return DefaultVal;
}

bool GJson::GetBool(const char *str, bool DefaultVal)
{
    if (!HasMember(str))
    {
        cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
        return DefaultVal;
    }
    rapidjson::Value &value = operator[](str);
    if (value.IsBool())
    {
        return value.GetBool();
    }
    cocos2d::log("Error Parsing Bool: %s For Value of %s ", str, kTypeNames[value.GetType()]);
    return DefaultVal;
}

GJson *GJson::GetJsonObject(const char *str, GJson *DefaultVal)
{
    if (!HasMember(str))
    {
        cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
        return DefaultVal;
    }
    rapidjson::Value &value = operator[](str);
    if (value.IsObject())
    {
        GJson *JsonObject = new GJson();
        JsonObject->CopyFrom(value, JsonObject->GetAllocator());
        return JsonObject;
    }
    cocos2d::log("Error Parsing Bool: %s For Value of %s ", str, kTypeNames[value.GetType()]);
    return DefaultVal;
}


GString GJson::ToString()
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    this->Accept(writer);
    return buffer.GetString();
}