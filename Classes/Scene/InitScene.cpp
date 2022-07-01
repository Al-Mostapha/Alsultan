
#include "InitScene.h"
#include "Module/Config/Config.module.h"
#include "Module/Net/NetBase.Module.h"
#include "Base/Json.h"
#include "Module/City/City.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Building/Building.Module.h"

USING_NS_CC;

Scene *InitScene::createScene()
{
    return InitScene::create();
}

// on "init" you need to initialize your instance
bool InitScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    setName("My Name Is Init Scene");
    GConfigModule::init();
    ArmyModule::init();
    BuildingModule::init();
    ResourceModule::init();

    /*NetBaseModule::getJson("/api/City/getCity",
                       [](const wchar_t *json)
                       {
                           GJson *j = new GJson(json);
                       {

    if (response->isSucceed())
    {
        GString responseStr = GString(response->getResponseData()->begin(), response->getResponseData()->end());

        GJson JsonObject ;
        JsonObject.Parse(responseStr.c_str());

        if (JsonObject.HasParseError())
        {
            cocos2d::log("Error: %s\n", JsonObject.GetParseError());
            return;
        }

        cocos2d::log("%d", JsonObject.GetInt("idPlayer"));

        // rapidjson::Document document;
        // document.Parse(responseStr.c_str());

    }
    else
    {
        cocos2d::log("Error: %s\n", response->getErrorBuffer());
    } });*/
    return true;
}
