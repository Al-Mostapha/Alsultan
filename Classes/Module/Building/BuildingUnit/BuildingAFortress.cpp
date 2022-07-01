// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingAFortress.h"

BuildingAFortress::BuildingAFortress()
{

	BuildingSpriteImage = "zhanzhengbaolei.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-8, 43};
}

bool BuildingAFortress::init()
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

void BuildingAFortress::onEnter()
{

	CityBuildingBase::onEnter();
}
