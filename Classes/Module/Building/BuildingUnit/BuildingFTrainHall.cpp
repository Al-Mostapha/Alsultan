// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFTrainHall.h"

BuildingFTrainHall::BuildingFTrainHall()
{

	BuildingSpriteImage = "train.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-46, 50};
	LvlBgOffset = {135, -90};
}

bool BuildingFTrainHall::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	setBuildingParticle();
	// setBuildingIconMiracle();

	return true;
}

void BuildingFTrainHall::setBuildingParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_diaoxiang_02.plist");
	Part1->setPosition(0, 0);
	Part1->setScaleX(0.68);
	Part1->setScaleY(0.68);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 3);

	auto Part2 = ParticleSystemQuad::create("Particle/et_mijinggezi_01.plist");
	Part2->setPosition(0, 0);
	Part2->setScaleX(1.1);
	Part2->setScaleY(1.3);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 3);

	auto Part3 = ParticleSystemQuad::create("Particle/et_mijinggezi_03.plist");
	Part3->setPosition(0, 0);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 3);
}

void BuildingFTrainHall::onEnter()
{

	CityBuildingBase::onEnter();
}
