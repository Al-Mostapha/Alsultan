// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingARange.h"
#include "Module/Building/Building.Event.h"

BuildingARange::BuildingARange()
{

	BuildingSpriteImage = "gongbingying.png";
	BuildingIconMiracle = "armyicon_b_610.png";
	BuildingSpriteOffset = {0, 38};
}

bool BuildingARange::init()
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

void BuildingARange::onEnter()
{
	IBuilding::onEnter();
}

void BuildingARange::ShowAnimWorking()
{

	auto frames = getAnimation("shibing3_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite2 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite3 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite4 = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(5, 44);
	sprite2->setPosition(-15, 33);
	sprite3->setPosition(31, 29);
	sprite4->setPosition(12, 20);

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

void BuildingARange::setBuildingIconMiracle()
{

	auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
	SleepSprite2->setPosition(45, 0);
	SleepSprite2->setLocalZOrder(10);
	SleepSprite2->setScale(0.3);
	addChild(SleepSprite2);
}


void BuildingARange::ShowWorkDone(){
  ShowTopTip();
  ShowAnimWorking();
  std::unique_ptr<ABuildingMsg> l_BuildingMsg(new ABuildingMsg());
  l_BuildingMsg->BuildingIndex = m_BuildingIndex;
  l_BuildingMsg->BuildingNode = nullptr;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_BuildingMsg.get());
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_WORK_DONE_EFFECT", l_BuildingMsg.get());
}