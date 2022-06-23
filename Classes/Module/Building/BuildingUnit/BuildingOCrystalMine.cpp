// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOCrystalMine.h"


BuildingOCrystalMine::BuildingOCrystalMine() {

	BuildingSpriteImage  = "shuijingkuan.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { -25, 45 };
	LvlBgOffset = {110, 6};

}


bool BuildingOCrystalMine::init() {

	
	if (!CityBuildingBase::init())
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

void BuildingOCrystalMine::onEnter() {

	CityBuildingBase::onEnter();

}

void BuildingOCrystalMine::setBuildingSprite() {

	CityBuildingBase::setBuildingSprite();

}


void BuildingOCrystalMine::setBuildingAnimation() {};
