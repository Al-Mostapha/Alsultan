// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingAChariotPlant.h"

BuildingAChariotPlant::BuildingAChariotPlant()
{

	BuildingSpriteImage = "bubingying.png";
	BuildingIconMiracle = "armyicon_b_410.png";
	BuildingSpriteOffset = {-6, 32};
	LvlBgOffset = {111, -14};
}

bool BuildingAChariotPlant::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingIconMiracle();
	setBuildingAnimation();

	return true;
}

void BuildingAChariotPlant::onEnter()
{
	CityBuildingBase::onEnter();
}

void BuildingAChariotPlant::setBuildingAnimation()
{

	auto frames = getAnimation("shibing1_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite2 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite3 = Sprite::createWithSpriteFrame(frames.front());
	auto sprite4 = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(-5, 20);
	sprite2->setPosition(-26, 7);
	sprite3->setPosition(-4, -6);
	sprite4->setPosition(23, 7);

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

void BuildingAChariotPlant::setBuildingIconMiracle()
{

	auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
	SleepSprite2->setPosition(45, 0);
	SleepSprite2->setLocalZOrder(10);
	SleepSprite2->setScale(0.3);
	addChild(SleepSprite2);
}
