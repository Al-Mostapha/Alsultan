// #include "XJson.h"
// #include "cocos2d.h"

// XJson XJson::Create(const GString &str)
// {
//     XJson lJson;
//     try
//     {
//         lJson._Json = Json::parse(str);
//     }
//     catch (const std::exception &e)
//     {
//         cocos2d::log("Error Parsing Json: %s", e.what());
//     }
//     return lJson;
// }

// XJson XJson::Create(const Json &pJson)
// {
//     XJson lJson;
//     lJson._Json = pJson;
//     return lJson;
// }

// GString XJson::GetString(const char *str,const GString &DefaultVal) const
// {
//     if (!_Json.contains(str))
//     {
//         cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
//         return nullptr;
//     }

//     auto lVal = _Json.at(str);
//     if(lVal.is_string())
//     {
//         return lVal.get<GString>();
//     }
//     return DefaultVal;
// }

// int32 XJson::GetInt(const char *str, int32 DefaultVal) const
// {
//     if (!_Json.contains(str))
//     {
//         cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
//         return DefaultVal;
//     }
//     auto lVal = _Json.at(str);
//     if (lVal.is_number_integer())
//     {
//         return lVal.get<int32>();
//     }
//     return DefaultVal;
// }

// float XJson::GetFloat(const char *str, float DefaultVal) const
// {
//     if (!_Json.contains(str))
//     {
//         cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
//         return DefaultVal;
//     }
//     auto lVal = _Json.at(str);
//     if (lVal.is_number_float())
//     {
//         return lVal.get<float>();
//     }
//     return DefaultVal;
// }

// bool XJson::GetBool(const char *str, bool DefaultVal) const
// {
//     if (!_Json.contains(str))
//     {
//         cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
//         return DefaultVal;
//     }
//     auto lVal = _Json.at(str);
//     if (lVal.is_boolean())
//     {
//         return lVal.get<bool>();
//     }
//     return DefaultVal;
// }

// Json XJson::GetJsonObject(const char *str, const Json &DefaultVal) const
// {
//     if (!_Json.contains(str))
//     {
//         cocos2d::log("Error Parsing Key: %s Not Found In Object", str);
//         return DefaultVal;
//     }
//     // auto value = at(str);
//     // if (value.is_object())
//     // {
//     //     return value;
//     // }
//     return DefaultVal;
// }


// GString XJson::ToString()
// {
//     return _Json.dump();
// }