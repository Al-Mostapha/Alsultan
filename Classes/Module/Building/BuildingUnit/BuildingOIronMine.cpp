// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOIronMine.h"


BuildingOIronMine::BuildingOIronMine() {

	BuildingSpriteImage  = "tiekuangchang.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOIronMine::init() {

	
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

void BuildingOIronMine::onEnter() {

	CityBuildingBase::onEnter();

}

void BuildingOIronMine::setBuildingSprite() {

	CityBuildingBase::setBuildingSprite();

}


void BuildingOIronMine::setBuildingAnimation() {};
