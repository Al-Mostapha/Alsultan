
#include "InitScene.h"
#include "Game/XGame.h"
#include "Base/Type/XEvent.h"
#include "CityScene.h"

USING_NS_CC;

Scene *InitScene::createScene()
{
    return InitScene::create();
}

// on "init" you need to initialize your instance
bool InitScene::init()
{
    if (!Scene::init())
        return false;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    XEvent::Get()->Listen(Event_OnJsonFileLoaded, std::bind(&InitScene::JsonFileLoaded, this));

    return true;
}


void InitScene::onEnter(){
    Scene::onEnter();
    XGame::Get()->Init();
}

void InitScene::Load()
{
    // Should load resources here
    
}

void InitScene::JsonFileLoaded()
{
    Director::getInstance()->replaceScene(CityScene::createScene());
}