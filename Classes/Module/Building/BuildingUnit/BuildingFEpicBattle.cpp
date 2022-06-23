// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFEpicBattle.h"


BuildingFEpicBattle::BuildingFEpicBattle() {

	BuildingSpriteImage  = "altar.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 7, 38 };
	LvlBgOffset = {-15, 59};

}


bool BuildingFEpicBattle::init() {

	
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

void BuildingFEpicBattle::onEnter() {

	CityBuildingBase::onEnter();

}




