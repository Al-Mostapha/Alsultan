/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Scene/WorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "../Bootstrap/BootstrapPlist.h"
#include "external/json/document.h"
#include "Include/IncludeCityBuilding.h"
#include "Module/City/CityBuildingUtils/CityBuildingTopTip.h"
#include "ui/CocosGUI.h"
#include "Engine/XTiledMap/XTiledMap.h"
USING_NS_CC;

Scene *WorldScene::createScene()
{
    return WorldScene::create();
}

void WorldScene::onEnter(){
  Scene::onEnter();
  auto _TmxView = XTiledMap::create("tileMaps/WorldMapNew.tmx");
  _TmxView->setName("tileMapTmx");
  _TmxView->setIgnoreAnchorPointForPosition(false);
  _TmxView->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TmxView->setCascadeOpacityEnabled(true);
  _TmxView->setCascadeColorEnabled(true);

  auto _TmxViewSize = _TmxView->getContentSize();
  _TmxView->setPosition(Vec2(-_TmxViewSize.width/2, -_TmxViewSize.height/2));  
  auto _ViewScrollView = Ext::ScrollView::create(Director::getInstance()->getVisibleSize());
  _ViewScrollView->setName("viewScrollView");
  _ViewScrollView->setContainer(_TmxView);
  // _ViewScrollView->setClippingToBounds(false);
  // _ViewScrollView->setMinScale(0.75);
  // _ViewScrollView->setMaxScale(1.35);
  // _ViewScrollView->setZoomScale(1);
  // _ViewScrollView->setBounceable(false);
  // self.viewScrollView:setInertiaValue(1)
  // if self.viewScrollView.setScrollSpeed then
  //   self.viewScrollView:setScrollSpeed(4)
  //   self.viewScrollView:setScrollAcceleration(-3)
  // end
  _ViewScrollView->setPosition(Vec2(0, 0));
  this->addChild(_ViewScrollView, 10);
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WorldScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    //BootstrapPlist::loadSpriteSheet();

    // FileUtils::getInstance()->addSearchPath("cocosstudio");

    // auto visibleSize = Director::getInstance()->getVisibleSize();
    // Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // initWorldLayers();
    // initDraggingEvent();

    /**auto mysprite = Sprite::createWithSpriteFrameName("prison.png");
     mysprite->setLocalZOrder(10);
     mysprite->setPosition(150, 150);
     mysprite->setSpriteFrame("qibingying.png");

     this->addChild(mysprite);


     const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";

     cocos2d::log("Original JSON:\n %s\n", json);

     rapidjson::Document document;
     document.Parse(json);

     cocos2d::log("hello = %s\n", document["hello"].GetString());*/

    return true;
}

void WorldScene::initWorldLayers()
{

    auto scrollView = ui::ScrollView::create();
    scrollView->setPosition(Vec2(0, 0));
    scrollView->setDirection(ui::ScrollView::Direction::BOTH);
    scrollView->setBounceEnabled(true);
    this->addChild(scrollView);

    auto map = TMXTiledMap::create("World/TiledMap/WorldTile_2.tmx");
    /**auto sprite = Sprite::create("res/HelloWorld.png");
    sprite->setScale(2.0f);
    sprite->setPosition(sprite->getBoundingBox().size / 2);*/
    auto ground = map->getLayer("ground");
    auto tile = map->getLayer("tile");
    // if(ground)
    //   scrollView->addChild(ground);
    if (tile)
        scrollView->addChild(tile);
    scrollView->setInnerContainerSize(map->getBoundingBox().size);
    scrollView->setContentSize(map->getContentSize());

    // addChild(map, 0);
}

void WorldScene::initDraggingEvent()
{

    return;
    auto MouseListiner = EventListenerTouchOneByOne::create();

    MouseListiner->setSwallowTouches(true);
    static bool isDragging = false;

    MouseListiner->onTouchBegan = [](Touch *T, Event *event)
    {
        isDragging = true;
        return true;
    };

    MouseListiner->onTouchMoved = [=](Touch *T, Event *event)
    {
        this->CityFloorLayer->setPosition(this->CityFloorLayer->getPosition() + T->getDelta());
    };

    MouseListiner->onTouchEnded = [=](Touch *touch, Event *event)
    {
        // your code
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListiner, this);
}

void WorldScene::menuCloseCallback(Ref *pSender)
{
    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    // EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}