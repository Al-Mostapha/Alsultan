// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOSteel.h"


BuildingOSteel::BuildingOSteel() {

	BuildingSpriteImage  = "miyinkuangchang.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOSteel::init() {

	
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

void BuildingOSteel::onEnter() {

	CityBuildingBase::onEnter();

}

void BuildingOSteel::setBuildingSprite() {

	CityBuildingBase::setBuildingSprite();

}


void BuildingOSteel::setBuildingAnimation() {};
