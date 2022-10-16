// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOMilitaryTent.h"


BuildingOMilitaryTent::BuildingOMilitaryTent() {

	BuildingSpriteImage  = "xingjunzhangpeng.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOMilitaryTent::init() {

	
	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	//setBuildingIconMiracle();
	ShowAnimWorking();
	n_BuildingLvBg->setLocalZOrder(6);
	n_BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOMilitaryTent::onEnter() {

	IBuilding::onEnter();

}

void BuildingOMilitaryTent::setBuildingSprite() {

	IBuilding::setBuildingSprite();

}


void BuildingOMilitaryTent::ShowAnimWorking() {};
