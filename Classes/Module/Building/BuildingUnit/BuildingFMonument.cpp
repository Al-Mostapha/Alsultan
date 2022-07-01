// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFMonument.h"

BuildingFMonument::BuildingFMonument()
{

	BuildingSpriteImage = "map_build_history.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-5, 64};
}

bool BuildingFMonument::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();

	return true;
}

void BuildingFMonument::onEnter()
{

	CityBuildingBase::onEnter();
}
