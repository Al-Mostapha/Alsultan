// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFPetCenter.h"


BuildingFPetCenter::BuildingFPetCenter() {

	BuildingSpriteImage  = "chongwuguan.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 5, 27 };

}


bool BuildingFPetCenter::init() {

	
	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();

	BuildingSprite->setLocalZOrder(2);
	auto _Sp = Sprite::createWithSpriteFrameName("frame_chongwuguan_shadow.png");
	_Sp->setPosition(-25, 25);
	addChild(_Sp, 1);
	//setBuildingIconMiracle();

	return true;
}

void BuildingFPetCenter::onEnter() {

	CityBuildingBase::onEnter();

}




