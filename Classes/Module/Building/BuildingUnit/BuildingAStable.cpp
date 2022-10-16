// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingAStable.h"
#include "Module/Building/Building.Event.h"

BuildingAStable::BuildingAStable()
{

	BuildingSpriteImage = "qibingying.png";
	BuildingIconMiracle = "armyicon_b_510.png";
	BuildingSpriteOffset = {3, 33};
	LvlBgOffset = {117, -8};
}

bool BuildingAStable::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingIconMiracle();
	ShowAnimWorking();
	return true;
}

void BuildingAStable::onEnter()
{
	IBuilding::onEnter();
}

void BuildingAStable::ShowAnimWorking()
{

	auto frames = getAnimation("shibing2_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite2 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite3 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite4 = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(-18, 16);
	sprite2->setPosition(-42, 4);
	sprite3->setPosition(21, 0);
	sprite4->setPosition(-7, -11);

	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);

	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite2->runAction(RepeatForever::create(Animate::create(animation)));
	sprite3->runAction(RepeatForever::create(Animate::create(animation)));
	sprite4->runAction(RepeatForever::create(Animate::create(animation)));

	addChild(sprite);
	addChild(sprite2);
	addChild(sprite3);
	addChild(sprite4);
}

void BuildingAStable::setBuildingIconMiracle()
{

	auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
	SleepSprite2->setPosition(45, 0);
	SleepSprite2->setLocalZOrder(10);
	SleepSprite2->setScale(0.3);
	addChild(SleepSprite2);
}

void BuildingAStable::ShowWorkDone(){
  ShowTopTip();
  ShowAnimWorking();
  std::unique_ptr<ABuildingMsg> l_BuildingMsg = std::make_unique<ABuildingMsg>();
  l_BuildingMsg->BuildingIndex = m_BuildingIndex;
  l_BuildingMsg->BuildingNode = nullptr;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_BuildingMsg.get());
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_WORK_DONE_EFFECT", l_BuildingMsg.get());
}