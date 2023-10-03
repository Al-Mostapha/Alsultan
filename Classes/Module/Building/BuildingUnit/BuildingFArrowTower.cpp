// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFArrowTower.h"
#include "Module/Player/Player.Static.h"
#include "Module/UI/Common/Message/UIMsgNotice.h"
#include "Base/Common/Common.Teml.h"
#include "Module/City/City.Static.h"

BuildingFArrowTower::BuildingFArrowTower()
{

	BuildingSpriteImage = "jianta_lv1_base.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 0};
	LvlBgOffset = {107, -52};
}

bool BuildingFArrowTower::init()
{
	if (!IBuilding::init())
		return false;
	// setBuildingIconMiracle();
	return true;
}

void BuildingFArrowTower::onEnter()
{

	IBuilding::onEnter();

	auto _vm = getViewModel(
		CityStatic::Get()->GetCurrentCity().CityBuilding
			.CityBuildingFixed
			.wall.buildingLvl);
	BuildingSpriteImage = StringUtils::format(
		"jianta_lv%d_base.png",
		static_cast<int32>(_vm));
	setBuildingSprite();
	setTowerOffet();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
}

void BuildingFArrowTower::setTowerOffet()
{

	if (Info.BuildingPlace == "arrowTowerR")
		BuildingSprite->setPosition(BuildingSprite->getPosition() + Vec2(-7, 27));
	else
		BuildingSprite->setPosition(BuildingSprite->getPosition() + Vec2(-10, 32));
}

EBuildingViewModel BuildingFArrowTower::getViewModel(int32 walLvl)
{
	if (walLvl <= 2)
		return EBuildingViewModel::ViewModel_1;
	if (walLvl <= 6)
		return EBuildingViewModel::ViewModel_2;
	if (walLvl <= 10)
		return EBuildingViewModel::ViewModel_3;
	if (walLvl <= 14)
		return EBuildingViewModel::ViewModel_4;
	if (walLvl <= 130)
		return EBuildingViewModel::ViewModel_5;
	return EBuildingViewModel::None;
}

void BuildingFArrowTower::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    auto l_Notice = UIMsgNotice::Create();
    l_Notice->InitPanel();
    l_Notice->Notice("notice_0056");
    CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
    return;
  }
}

void BuildingFArrowTower::UpdateLvl(){
  UpdateIsLock();
  IBuilding::UpdateLvl();
}