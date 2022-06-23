// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFPrison.h"


BuildingFPrison::BuildingFPrison() {

	BuildingSpriteImage  = "prison.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 3, 16 };
	LvlBgOffset = { 25 , -110 };

}


bool BuildingFPrison::init() {

	
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

void BuildingFPrison::onEnter() {

	CityBuildingBase::onEnter();

}




