// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingFElitePalace.h"


BuildingFElitePalace::BuildingFElitePalace() {

	BuildingSpriteImage  = "jingyingdiantang.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 7, 38 };
	LvlBgOffset = {135, -15};

}


bool BuildingFElitePalace::init() {

	
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

void BuildingFElitePalace::onEnter() {

	CityBuildingBase::onEnter();

}




