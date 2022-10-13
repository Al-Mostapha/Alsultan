// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFMiracle.h"

BuildingFMiracle::BuildingFMiracle()
{

	BuildingSpriteImage = "BG_statue.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-40, 94};
	LvlBgOffset = {50, -9};
}

bool BuildingFMiracle::init()
{
	if (!IBuilding::init())
		return false;
	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	return true;
}

void BuildingFMiracle::onEnter()
{

	IBuilding::onEnter();
}
