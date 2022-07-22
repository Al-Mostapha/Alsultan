// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFRevivalHall.h"

BuildingFRevivalHall::BuildingFRevivalHall()
{

	BuildingSpriteImage = "fuhuoquanshui.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {4, 73};
}

bool BuildingFRevivalHall::init()
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

void BuildingFRevivalHall::setBuildingParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_lifetree_01_01.plist");
	Part1->setPosition(0, 0);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 1);

	auto Part2 = ParticleSystemQuad::create("Particle/et_gongfang_complete_02.plist");
	Part2->setScaleX(1.16);
	Part2->setScaleY(1.2);
	Part2->setPosition(0, 0);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 2);
}

void BuildingFRevivalHall::onEnter()
{

	CityBuildingBase::onEnter();
}
