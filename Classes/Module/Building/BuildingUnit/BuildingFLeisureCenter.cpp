// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFLeisureCenter.h"

BuildingFLeisureCenter::BuildingFLeisureCenter()
{

	BuildingSpriteImage = "BG_SPR.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {41, 70};
}

bool BuildingFLeisureCenter::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	setBuildingParticle();

	return true;
}

void BuildingFLeisureCenter::onEnter()
{

	IBuilding::onEnter();
}

void BuildingFLeisureCenter::setBuildingParticle()
{

	auto Part1 = ParticleSystemQuad::create("Particle/et_pyramid_building_01.plist");
	Part1->setPosition(44, 80);
	Part1->setScaleX(1);
	Part1->setScaleY(1);
	Part1->setRotation(-11.22f);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 10);

	auto Part2 = ParticleSystemQuad::create("Particle/et_pyramid_building_02.plist");
	Part2->setPosition(44.7f, 57.0f);
	Part2->setScaleX(1.37f);
	Part2->setScaleY(1.533f);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 10);

	auto Part3 = ParticleSystemQuad::create("Particle/et_pyramid_building_03.plist");
	Part3->setPosition(-13.3f, -135.0f);
	Part3->setScaleX(1.723f);
	Part3->setScaleY(1.532f);
	Part3->setRotation(-118.93f);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 10);

	auto Part4 = ParticleSystemQuad::create("Particle/et_pyramid_building_03.plist");
	Part4->setPosition(122.7f, 50.0f);
	Part4->setScaleX(2.515f);
	Part4->setScaleY(3.708f);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 10);
}
