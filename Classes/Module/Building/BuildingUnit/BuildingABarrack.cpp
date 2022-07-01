// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingABarrack.h"

BuildingABarrack::BuildingABarrack()
{

	BuildingSpriteImage = "chebingying.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 39};
}

bool BuildingABarrack::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingIconMiracle();

	return true;
}

void BuildingABarrack::onEnter()
{
	CityBuildingBase::onEnter();
}
