// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFHarbor.h"


BuildingFHarbor::BuildingFHarbor() {

	BuildingSpriteImage  = "huochuan.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 7, 17 };

}


bool BuildingFHarbor::init() {

	
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

void BuildingFHarbor::onEnter() {

	CityBuildingBase::onEnter();

}




