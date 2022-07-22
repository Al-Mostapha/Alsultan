// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingABarrack.h"
#include "ui/UIButton.h"
#include "Scene/CityScene.h"
#include <iostream>

BuildingABarrack::BuildingABarrack()
{

	BuildingSpriteImage = "chebingying.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 39};
}

bool BuildingABarrack::init()
{

	if (!CityBuildingBase::init())
		return false;



	return true;
}

void BuildingABarrack::onEnter()
{
	CityBuildingBase::onEnter();
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
	BuildingBtn->setAnchorPoint(Vec2(0.5, 0.5));
	auto closeItem = MenuItem::create([](Ref * sender){ cocos2d::log("Button 1 4555555555555555555555555"); });
	closeItem->setColor(Color3B::BLUE);
	closeItem->setContentSize(Size(100, 100));
	closeItem->setCascadeColorEnabled(true);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2(100, 100));
	BuildingBtn->addChild(menu);
	addChild(BuildingBtn, 1500);
}
