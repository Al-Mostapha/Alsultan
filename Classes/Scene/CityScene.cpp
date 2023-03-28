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

#include "Scene/CityScene.h"
#include "cocostudio/CocoStudio.h"
#include "../Bootstrap/BootstrapPlist.h"
#include "external/json/document.h"
#include "Include/IncludeCityBuilding.h"
#include "Module/City/CityBuildingUtils/CityBuildingTopTip.h"
#include "Module/Building/Building.Module.h"
#include "Module/City/City.Module.h"

USING_NS_CC;

CityScene *CityScene::Get(){
  Scene* l_RunningScene = Director::getInstance()->getRunningScene();
  if (l_RunningScene == nullptr) {
    cocos2d::log("Error: No Current Scene ... ");
    return nullptr;
  }
  return dynamic_cast<CityScene*>(l_RunningScene);
}

Scene *CityScene::createScene()
{
    return CityScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char *filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool CityScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
  
    BaseScrollLayer = Ext::ScrollView::create(Director::getInstance()->getWinSize());

    BaseScrollLayer->setPosition(Vec2(0, 0));
    return true;
}

void CityScene::initCityLayers()
{

    CityFloorLayer = CSLoader::createNode("Scene/City/mainCityViewBG.csb");
    CityBuildingLayer = CSLoader::createNode("Scene/City/mainCityViewInfo.csb");
    containerView = CityBuildingLayer;
    batchNodeXiyiNpc = Node::create();
    batchNodeNpc = Node::create();
    batchNodeSoldierGuards = Node::create();

    CityBuildingLayer->addChild(batchNodeXiyiNpc);
    CityBuildingLayer->addChild(batchNodeNpc);
    CityBuildingLayer->addChild(batchNodeSoldierGuards);

    batchNodeXiyiNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
    batchNodeNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
    batchNodeSoldierGuards->setLocalZOrder(ECityTargetZOrder::Get()->soldiers);
    
    batchNodeXiyiNpc->setPosition(0, 0);
    batchNodeNpc->setPosition(0, 0);
    batchNodeSoldierGuards->setPosition(0, 0);
    
    auto Cloud = CSLoader::createNode("Scene/City/mainCityViewCloud.csb");
    CityUiLayer = CSLoader::createNode("UiParts/MainUi/mainUIBottom.csb");
    auto ResBox = CSLoader::createNode("UiParts/MainUi/commonResourcesMenu.csb");
    auto TopUi = CSLoader::createNode("UiParts/MainUi/mainUITop.csb");

    ResBox->setPosition(0, Director::getInstance()->getWinSize().height);
    TopUi->setPosition(0, Director::getInstance()->getWinSize().height - 57);
    Cloud->setPosition(0, 680);
    Cloud->setLocalZOrder(-1);
    this->CityFloorLayer->addChild(CityBuildingLayer);
    this->CityFloorLayer->addChild(Cloud);
    this->CityUiLayer->addChild(ResBox);
    this->CityUiLayer->addChild(TopUi, -1);

   // BaseScrollLayer->setContainer(CityBuildingLayer);

    if (this->CityFloorLayer)
      BaseScrollLayer->addChild(this->CityFloorLayer);
    if (this->CityUiLayer)
      addChild(this->CityUiLayer);
}

void CityScene::initDraggingEvent()
{

  auto MouseListiner = EventListenerTouchOneByOne::create();
  MouseListiner->setSwallowTouches(true);
  //MouseListiner->onTouchEnded
    // static bool isDragging = false;

    // MouseListiner->onTouchBegan = [](Touch *T, Event *event)
    // {
    //     isDragging = true;
    //     return true;
    // };
    // MouseListiner->onTouchMoved = [=](Touch *T, Event *event)
    // {
    //     this->CityFloorLayer->setPosition(this->CityFloorLayer->getPosition() + T->getDelta());
    // };
    // MouseListiner->onTouchEnded = [=](Touch *touch, Event *event)
    // {
    //     // your code
    // };
  
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListiner, this);
}

void CityScene::menuCloseCallback(Ref *pSender)
{
    // Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    // EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void CityScene::onEnter()
{
    Scene::onEnter();
    BootstrapPlist::loadSpriteSheet(nullptr);
    initCityLayers();
    initDraggingEvent();
    CityModule::showCityBuilding();
    CityModule::showCityEffect();
    
}

CityScene *CityScene::getCityScene()
{
    Scene *RunningScene = Director::getInstance()->getRunningScene();
    CityScene *_scene = dynamic_cast<CityScene *>(RunningScene);
    return _scene;
}