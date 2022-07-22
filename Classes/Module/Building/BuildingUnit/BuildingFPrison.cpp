// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFPrison.h"

BuildingFPrison::BuildingFPrison()
{

	BuildingSpriteImage = "prison.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-45, 64};
	LvlBgOffset = {25, -110};
}

bool BuildingFPrison::init()
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

void BuildingFPrison::setBuildingParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_jinzitaloading_01.plist");
	Part1->setPosition(143.47, 27.63);
	Part1->setScaleX(0.09f);
	Part1->setScaleY(0.135f);
	Part1->setRotation(-131.65);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 1);

	auto Part2 = ParticleSystemQuad::create("Particle/et_jinzitaloading_01.plist");
	Part2->setPosition(73.76f, -56.02f);
	Part2->setScaleX(0.36f);
	Part2->setScaleY(0.36f);
	Part2->setRotation(-104.94f);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 2);

	auto Part3 = ParticleSystemQuad::create("Particle/et_jianyujz_01.plist");
	Part3->setPosition(61.15f, -45.59f);
	Part3->setScaleX(0.448f);
	Part3->setScaleY(0.672f);
	Part3->setRotation(-33.46f);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 3);

	auto Part4 = ParticleSystemQuad::create("Particle/et_jinzitaloading_05.plist");
	Part4->setPosition(127.71f, 34.75f);
	Part4->setScaleX(0.18f);
	Part4->setScaleY(0.18f);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 4);

	auto Part5 = ParticleSystemQuad::create("Particle/et_jianyujz_01.plist");
	Part5->setPosition(47.68f, 24.77f);
	Part5->setScaleX(0.38);
	Part5->setScaleY(0.569);
	Part5->setRotation(-14.91);
	Part5->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part5, 5);

	auto Part6 = ParticleSystemQuad::create("Particle/et_jinzitaloading_01.plist");
	Part6->setPosition(44.06, 25.74);
	Part6->setScaleX(0.12);
	Part6->setScaleY(0.135);
	Part6->setRotation(130.31);
	Part6->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part6, 6);
}

void BuildingFPrison::onEnter()
{

	CityBuildingBase::onEnter();
}
