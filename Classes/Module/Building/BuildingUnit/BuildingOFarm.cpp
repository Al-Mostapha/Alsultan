// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOFarm.h"


BuildingOFarm::BuildingOFarm() {

	BuildingSpriteImage  = "nt_base.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOFarm::init() {

	
	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	//setBuildingIconMiracle();
	setBuildingAnimation();
	BuildingLvBg->setLocalZOrder(6);
	BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOFarm::onEnter() {

	IBuilding::onEnter();

}

void BuildingOFarm::setBuildingSprite() {

	IBuilding::setBuildingSprite();

	auto _Sp1 = Sprite::createWithSpriteFrameName("nt_lvmiao_01.png"); // green grass
	auto _Sp2 = Sprite::createWithSpriteFrameName("nt_maizi_01.png");  // befor yeild 
	auto _Sp3 = Sprite::createWithSpriteFrameName("nt_maizi_02.png");  // yeild
	auto _Sp4 = Sprite::createWithSpriteFrameName("nt_shuiqu.png"); // 
	auto _Sp5 = Sprite::createWithSpriteFrameName("nt_decorate_02.png"); // 
	auto _Sp6 = Sprite::createWithSpriteFrameName("nt_decorate_03.png"); // 
	auto _Sp7 = Sprite::createWithSpriteFrameName("nt_decorate_04.png"); // 
	auto _Sp8 = Sprite::createWithSpriteFrameName("nt_decorate_05.png"); //

	_Sp1->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp2->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp3->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp4->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp5->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp6->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp7->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);
	_Sp8->setPosition(BuildingSpriteOffset.x, BuildingSpriteOffset.y);

	_Sp1->setLocalZOrder(1);
	_Sp2->setLocalZOrder(2);
	_Sp3->setLocalZOrder(2);
	_Sp4->setLocalZOrder(3);
	_Sp5->setLocalZOrder(4);
	_Sp6->setLocalZOrder(4);
	_Sp7->setLocalZOrder(4);
	_Sp8->setLocalZOrder(4);

	addChild(_Sp1);
	addChild(_Sp2);
	addChild(_Sp3);
	addChild(_Sp4);
	addChild(_Sp5);
	addChild(_Sp6);
	addChild(_Sp7);
	addChild(_Sp8);

}


void BuildingOFarm::setBuildingAnimation() {


	auto frames = getAnimation("nongmin_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(40, 24);
	sprite->setLocalZOrder(5);
	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	addChild(sprite);


}

