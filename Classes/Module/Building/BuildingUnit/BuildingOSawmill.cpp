// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOSawmill.h"
#include "Module/Building/Building.Event.h"

BuildingOSawmill::BuildingOSawmill() {

	BuildingSpriteImage  = "fmc_base.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOSawmill::init() {

	
	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	//setBuildingIconMiracle();
	ShowAnimWorking();
	n_BuildingLvBg->setLocalZOrder(6);
	n_BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOSawmill::onEnter() {

	IBuilding::onEnter();

}

void BuildingOSawmill::setBuildingSprite() {

	IBuilding::setBuildingSprite();

	auto _Sp1 = Sprite::createWithSpriteFrameName("fmc_tree_01.png"); // green grass
	auto _Sp2 = Sprite::createWithSpriteFrameName("fmc_tree_02.png");  // befor yeild 
	auto _Sp3 = Sprite::createWithSpriteFrameName("fmc_house_01.png");  // yeild
	auto _Sp4 = Sprite::createWithSpriteFrameName("fmc_house_02.png"); // 
	auto _Sp5 = Sprite::createWithSpriteFrameName("fmc_house_03.png"); // 
	auto _Sp6 = Sprite::createWithSpriteFrameName("fmc_house_04.png"); // 
	auto _Sp7 = Sprite::createWithSpriteFrameName("fmc_wood.png"); // 

	_Sp1->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp2->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp3->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp4->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp5->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp6->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp7->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);

	_Sp1->setLocalZOrder(1);
	_Sp2->setLocalZOrder(1);
	_Sp3->setLocalZOrder(2);
	_Sp4->setLocalZOrder(2);
	_Sp5->setLocalZOrder(2);
	_Sp6->setLocalZOrder(2);
	_Sp7->setLocalZOrder(4);

	addChild(_Sp1);
	addChild(_Sp2);
	addChild(_Sp3);
	addChild(_Sp4);
	addChild(_Sp5);
	addChild(_Sp6);
	addChild(_Sp7);

}


void BuildingOSawmill::ShowAnimWorking() {
	auto frames = getAnimation("fuma_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(30, 10);
	sprite->setLocalZOrder(3);
	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	addChild(sprite);
}

void BuildingOSawmill::ShowWorkDone(){
  auto l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_ABuildingMsg.get());
  ShowTopTip();
}

void BuildingOSawmill::InitWithUIType(){
  auto l_BatchNodeOuterBuilds = GDisplay::Get()->NewNode();
  addChild(l_BatchNodeOuterBuilds, 0);
  m_ViewNodes.n_MainCityOuter = l_BatchNodeOuterBuilds;
}