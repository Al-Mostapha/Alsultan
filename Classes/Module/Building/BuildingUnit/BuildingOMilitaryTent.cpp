// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOMilitaryTent.h"
#include "Engine/Display.h"


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
	_BuildingLvBg->setLocalZOrder(6);
	_BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOMilitaryTent::onEnter() {

	IBuilding::onEnter();

}

void BuildingOMilitaryTent::setBuildingSprite() {

	IBuilding::setBuildingSprite();

}


void BuildingOMilitaryTent::ShowAnimWorking() {};

void BuildingOMilitaryTent::InitWithUIType(){
  auto l_BatchNodeOuterBuilds = GDisplay::Get()->NewNode();
  addChild(l_BatchNodeOuterBuilds, 0);
  m_ViewNodes.n_MainCityOuter = l_BatchNodeOuterBuilds;
}