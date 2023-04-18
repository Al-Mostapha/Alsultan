// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingABarrack.h"
#include "ui/UIButton.h"
#include "Scene/CityScene.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Building/Building.Event.h"
#include <iostream>

BuildingABarrack::BuildingABarrack()
{

	BuildingSpriteImage = "chebingying.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 39};
}

void BuildingABarrack::initBuilingData()
{
	
}
bool BuildingABarrack::init()
{

	if (!IBuilding::init())
		return false;



	return true;
}

void BuildingABarrack::onEnter()
{
	IBuilding::onEnter();
	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingIconMiracle();
	setBuildingBtn();
}

void BuildingABarrack::setBuildingBtn(){
	BuildingBtn = Layout::create();
	BuildingBtn->setBackGroundColor(Color3B::BLACK);
	BuildingBtn->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	BuildingBtn->setContentSize(Size(100, 100));
	BuildingBtn->setAnchorPoint(Vec2(0.5f, 0.5f));
	auto closeItem = MenuItem::create([](Ref * sender){ cocos2d::log("Button 1 4555555555555555555555555"); });
	closeItem->setColor(Color3B::BLUE);
	closeItem->setContentSize(Size(100, 100));
	closeItem->setCascadeColorEnabled(true);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2(100, 100));
	BuildingBtn->addChild(menu);
	addChild(BuildingBtn, 1500);
}

void BuildingABarrack::ShowWorkDone(){
  ShowTopTip();
  ShowAnimWorking();
  std::unique_ptr<ABuildingMsg> l_BuildingMsg(new ABuildingMsg());
  l_BuildingMsg->BuildingIndex = m_BuildingIndex;
  l_BuildingMsg->BuildingNode = nullptr;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_BuildingMsg.get());
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_WORK_DONE_EFFECT", l_BuildingMsg.get());
}