// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingAFortress.h"
#include "Module/Building/Building.Event.h"

BuildingAFortress::BuildingAFortress()
{

	BuildingSpriteImage = "zhanzhengbaolei.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-8, 43};
}

bool BuildingAFortress::init()
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

void BuildingAFortress::onEnter()
{

	IBuilding::onEnter();
}

void BuildingAFortress::ShowWorkDone(){
  ShowTopTip();
  ShowAnimWorking();
  std::unique_ptr<ABuildingMsg> l_BuildingMsg = std::make_unique<ABuildingMsg>();
  l_BuildingMsg->BuildingIndex = m_BuildingIndex;
  l_BuildingMsg->BuildingNode = nullptr;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_BuildingMsg.get());
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_WORK_DONE_EFFECT", l_BuildingMsg.get());
}