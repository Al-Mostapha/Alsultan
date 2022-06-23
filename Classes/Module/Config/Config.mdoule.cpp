
#include "Config.module.h"
#include "cocos/platform/CCFileUtils.h"
USING_NS_CC;

GConfig GConfigModule::Config;

void GConfigModule::init()
{
    loadNetConfig();
}

void GConfigModule::loadNetConfig()
{
    FileUtils *fileUtils = cocos2d::FileUtils::getInstance();
    GString filePath = fileUtils->fullPathForFilename("Config/Net.Config.json");
    GString FileContent = fileUtils->getStringFromFile(filePath);
    const char *json = FileContent.c_str();
    rapidjson::Document document;
    document.Parse(json);
    if (document.HasParseError())
    {
        cocos2d::log("Error: %s\n", document.GetParseError());
        return;
    }
    GConfigModule::Config.ApiConfig.ApiUrl = document["ApiUrl"].GetString();
    GConfigModule::Config.ApiConfig.ApiPort = document["ApiPort"].GetString();
    GConfigModule::Config.ApiConfig.ApiFullUrl = document["ApiFullUrl"].GetString();
}