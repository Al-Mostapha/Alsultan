// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFTrainHall.h"


BuildingFTrainHall::BuildingFTrainHall() {

	BuildingSpriteImage  = "train.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 1, -12 };
	LvlBgOffset = { 135 , -90 };

}


bool BuildingFTrainHall::init() {

	
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

void BuildingFTrainHall::onEnter() {

	CityBuildingBase::onEnter();

}




