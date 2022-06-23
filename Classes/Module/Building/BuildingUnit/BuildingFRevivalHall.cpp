// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFRevivalHall.h"


BuildingFRevivalHall::BuildingFRevivalHall() {

	BuildingSpriteImage  = "fuhuoquanshui.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 4, 73 };

}


bool BuildingFRevivalHall::init() {

	
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

void BuildingFRevivalHall::onEnter() {

	CityBuildingBase::onEnter();

}




