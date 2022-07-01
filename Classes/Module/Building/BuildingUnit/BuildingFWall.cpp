// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFWall.h"

BuildingFWall::BuildingFWall()
{

	BuildingSpriteImage = "chengmen_lv1.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 0};
	LvlBgOffset = {110, -110};
}

bool BuildingFWall::init()
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

void BuildingFWall::onEnter()
{
	CityBuildingBase::onEnter();
}
