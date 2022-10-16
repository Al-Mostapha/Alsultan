// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingOSilver.h"
#include "Module/Building/Building.Event.h"

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
	ShowAnimWorking();
	n_BuildingLvBg->setLocalZOrder(6);
	n_BuildingLvText->setLocalZOrder(8);
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

void BuildingOSilver::ShowAnimWorking(){};

void BuildingOSilver::ShowWorkDone(){
  auto l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_ABuildingMsg.get());
  ShowTopTip();
}