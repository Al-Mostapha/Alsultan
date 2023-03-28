// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingOIronMine.h"
#include "Module/Building/Building.Event.h"


BuildingOIronMine::BuildingOIronMine() {

	BuildingSpriteImage  = "tiekuangchang.png";
	BuildingIconMiracle  = "armyicon_s_10004711.png";
	BuildingSpriteOffset = { 0, 0 };
	LvlBgOffset = {64, -6};

}


bool BuildingOIronMine::init() {

	
	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	//setBuildingIconMiracle();
	ShowAnimWorking();
	n_BuildingLvBg->setLocalZOrder(6);
	n_BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOIronMine::onEnter() {

	IBuilding::onEnter();

}

void BuildingOIronMine::setBuildingSprite() {

	IBuilding::setBuildingSprite();

}


void BuildingOIronMine::ShowAnimWorking() {};

void BuildingOIronMine::ShowWorkDone(){
  auto l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_ABuildingMsg.get());
  ShowTopTip();
}

void BuildingOIronMine::InitWithUIType(){
  auto l_BatchNodeOuterBuilds = GDisplay::Get()->NewNode();
  addChild(l_BatchNodeOuterBuilds, 0);
  m_ViewNodes.n_MainCityOuter = l_BatchNodeOuterBuilds;
}