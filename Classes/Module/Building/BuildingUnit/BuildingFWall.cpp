// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFWall.h"
#include "Module/Player/Player.DT.h"
#include "Scene/CityScene.h"

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

	// setBuildingIconMiracle();

	return true;
}

EBuildingViewModel BuildingFWall::getViewModel(int32 walLvl)
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
	return EBuildingViewModel::ViewModel_1;
}

void BuildingFWall::setBuildingSprite()
{
	auto _vm = getViewModel(
			DTPlayer::SultanPlayer
					.City.CityBuilding
					.CityBuildingFixed
					.wall.buildingLvl);
	BuildingSpriteImage = StringUtils::format("chengmen_lv%d.png", static_cast<int32>(_vm));

	Scene *currentScene = Director::getInstance()->getRunningScene();
	CityScene *_cityScene = dynamic_cast<CityScene *>(currentScene);
	if (_cityScene && _cityScene->CityBuildingLayer)
	{
		auto wall1 = dynamic_cast<Sprite *>(_cityScene->CityBuildingLayer->getChildByName("Sprite_Cq_1"));
		auto wall2 = dynamic_cast<Sprite *>(_cityScene->CityBuildingLayer->getChildByName("Sprite_Cq_2"));
		auto wall3 = dynamic_cast<Sprite *>(_cityScene->CityBuildingLayer->getChildByName("Sprite_Cq_3"));
		auto wall4 = dynamic_cast<Sprite *>(_cityScene->CityBuildingLayer->getChildByName("Sprite_Cq_4"));
		if (!wall1 || !wall2 || !wall3 || !wall4)
			return;
		wall1->setSpriteFrame(StringUtils::format("chengqiang_lv%d.png", static_cast<int32>(_vm)));
		wall2->setSpriteFrame(StringUtils::format("chengqiang_lv%d.png", static_cast<int32>(_vm)));
		wall3->setSpriteFrame(StringUtils::format("chengqiang_lv%d.png", static_cast<int32>(_vm)));
		wall4->setSpriteFrame(StringUtils::format("chengqiang_lv%d.png", static_cast<int32>(_vm)));
	}

	BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
	BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
	addChild(BuildingSprite);
}

void BuildingFWall::onEnter()
{
	//"Sprite_Cq_3"
	CityBuildingBase::onEnter();

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
}
