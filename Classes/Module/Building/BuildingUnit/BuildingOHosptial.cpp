// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingOHosptial.h"

BuildingOHosptial::BuildingOHosptial()
{

	BuildingSpriteImage = "yiliaozhangpeng.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {0, 0};
	LvlBgOffset = {64, -6};
}

bool BuildingOHosptial::init()
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
	ShowNormalParticle();
	n_BuildingLvBg->setLocalZOrder(6);
	n_BuildingLvText->setLocalZOrder(8);
	return true;
}

void BuildingOHosptial::onEnter()
{

	IBuilding::onEnter();
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_HOSPTIAL_VIEW");
}

void BuildingOHosptial::setBuildingSprite()
{

	IBuilding::setBuildingSprite();
}

void BuildingOHosptial::ShowAnimWorking(){};

void BuildingOHosptial::ShowNormalParticle()
{

	auto Part1 = ParticleSystemQuad::create("Particle/et_yiyuan_01.plist");
	Part1->setPosition(-4.5f, 14);
	Part1->setScaleX(1.77);
	Part1->setScaleY(3.36);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 10);

	auto Part2 = ParticleSystemQuad::create("Particle/et_yiyuan_02.plist");
	Part2->setPosition(-7, 43);
	Part2->setScaleX(0.67f);
	Part2->setScaleY(2.1f);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 10);

	auto Part3 = ParticleSystemQuad::create("Particle/et_yiyuan_03.plist");
	Part3->setPosition(0, 0);
	Part3->setScaleX(2.4);
	Part3->setScaleY(1.22f);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 10);

	// This special cond
	auto Part4 = ParticleSystemQuad::create("Particle/et_lifetree_01_01.plist");
	Part4->setPosition(0, 0);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 10);

	auto Part5 = ParticleSystemQuad::create("Particle/et_gongfang_complete_02.plist");
	Part5->setPosition(0, 0);
	Part5->setScaleX(1.16f);
	Part5->setScaleY(1.2f);
	Part5->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part5, 10);
}


void BuildingOHosptial::InitWithUIType(){
  auto l_BatchNodeOuterBuilds = GDisplay::Get()->NewNode();
  addChild(l_BatchNodeOuterBuilds, 0);
  m_ViewNodes.n_MainCityOuter = l_BatchNodeOuterBuilds;
}