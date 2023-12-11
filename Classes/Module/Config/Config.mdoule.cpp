
#include "Config.module.h"
#include "Base/Type/XJson.h"
#include "cocos/platform/CCFileUtils.h"
USING_NS_CC;

GConfig GConfigModule::Config;

void GConfigModule::init()
{
    loadNetConfig();
}

void GConfigModule::loadNetConfig()
{
    FileUtils *lFileUtils = cocos2d::FileUtils::getInstance();
    GString lFilePath = lFileUtils->fullPathForFilename("Config/Net.Config.json");
    GString lFileContent = lFileUtils->getStringFromFile(lFilePath);
    const char *lJsonStr = lFileContent.c_str();

    if(!XJson::accept(lJsonStr)){
        Logger::Get()->Log("Json is not valid");
        return;
    }
    
    XJson lJsonDoc = XJson::parse(lJsonStr);
    GConfigModule::Config._HttpConfig._Prorocole  = lJsonDoc["HttpConfig"].value("Protocole", "http");
    GConfigModule::Config._HttpConfig._Host  = lJsonDoc["HttpConfig"].value("Host", "Invalid");
    GConfigModule::Config._HttpConfig._Port  = lJsonDoc["HttpConfig"].value("Port", 0);
    GConfigModule::Config._HttpConfig._Scope = lJsonDoc["HttpConfig"].value("Scope", "Invalid");
    GConfigModule::Config._WsConfig._Host    = lJsonDoc["WsConfig"].value("Host", "Invalid");
    GConfigModule::Config._WsConfig._Port    = lJsonDoc["WsConfig"].value("Port", 0);

}