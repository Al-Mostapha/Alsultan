// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingOCrystalMine.h"

BuildingOCrystalMine::BuildingOCrystalMine()
{

	BuildingSpriteImage = "shuijingkuan.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-25, 45};
	LvlBgOffset = {110, 6};
}

bool BuildingOCrystalMine::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	setBuildingAnimation();
	setBuildingParticle();
	BuildingLvBg->setLocalZOrder(6);
	BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOCrystalMine::onEnter()
{

	CityBuildingBase::onEnter();
}

void BuildingOCrystalMine::setBuildingSprite()
{

	CityBuildingBase::setBuildingSprite();
}

void BuildingOCrystalMine::setBuildingAnimation(){};

void BuildingOCrystalMine::setBuildingParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_shuijingk_01.plist");
	Part1->setPosition(0, 20);
	Part1->setScaleX(2.6);
	Part1->setScaleY(2.6);
	Part1->setRotation(0);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 1);

	auto Part2 = ParticleSystemQuad::create("Particle/et_shuijingk_02.plist");
	Part2->setPosition(-10, 24);
	Part2->setScaleX(1.64);
	Part2->setScaleY(3.7);
	Part2->setRotation(178.26);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 1);

	auto Part3 = ParticleSystemQuad::create("Particle/et_shuijingk_03.plist");
	Part3->setPosition(-4, 68);
	Part3->setScaleX(1.66);
	Part3->setScaleY(1.66);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 1);
}
