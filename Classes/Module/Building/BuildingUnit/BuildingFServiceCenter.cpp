// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFServiceCenter.h"


BuildingFServiceCenter::BuildingFServiceCenter() {

	BuildingSpriteImage  = "gonggaolan.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 2, 10 };

}


bool BuildingFServiceCenter::init() {

	
	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	//setBuildingIconMiracle();

	return true;
}

void BuildingFServiceCenter::onEnter() {

	CityBuildingBase::onEnter();

}




