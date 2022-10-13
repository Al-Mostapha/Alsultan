// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingOSilver.h"

BuildingOSilver::BuildingOSilver()
{

	BuildingSpriteImage = "miyinkuangchang.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 0};
	LvlBgOffset = {64, -6};
}

bool BuildingOSilver::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	setBuildingAnimation();
	BuildingLvBg->setLocalZOrder(6);
	BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOSilver::onEnter()
{

	IBuilding::onEnter();
}

void BuildingOSilver::setBuildingSprite()
{

	IBuilding::setBuildingSprite();
}

void BuildingOSilver::setBuildingAnimation(){};
