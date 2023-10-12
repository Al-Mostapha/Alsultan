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
	_BuildingLvBg->setLocalZOrder(6);
	_BuildingLvText->setLocalZOrder(8);
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
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_ABuildingMsg.get());
  ShowTopTip();
}

void BuildingOSilver::InitWithUIType(){
  auto l_BatchNodeOuterBuilds = GDisplay::Get()->NewNode();
  addChild(l_BatchNodeOuterBuilds, 0);
  m_ViewNodes.n_MainCityOuter = l_BatchNodeOuterBuilds;
}