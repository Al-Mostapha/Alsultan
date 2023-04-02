
#include "InitScene.h"
#include "Module/Config/Config.module.h"
#include "Module/Net/NetBase.Module.h"
#include "Base/Json.h"
#include "Module/City/City.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Building/Building.Module.h"
#include "Module/Building/Building.Type.h"
#include "Include/IncludeReflection.h"
#include "Module/Module.Mgr.h"

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


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png");

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {

    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    auto l_Bear = Sprite3D::create("3d/pet/bear/et_bear01.c3b", "3d/pet/bear/xuliyaxiong_01.png");
    l_Bear->setPosition(Vec2(visibleSize.width/2 - 400, visibleSize.height/2 - 100));
    this->addChild(l_Bear, 100);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World 1 5 7 8 4", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {

    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {

    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }


    setName("My Name Is Init Scene");
    GConfigModule::init();
    GModuleMgr::Get()->Init();
    return true;
}
