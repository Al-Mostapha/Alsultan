// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingOCrystalMine.h"
#include "Module/Building/Building.Event.h"
#include "Base/Common/Common.Teml.h"

BuildingOCrystalMine::BuildingOCrystalMine()
{

	BuildingSpriteImage = "shuijingkuan.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-25, 45};
	LvlBgOffset = {110, 6};
}

bool BuildingOCrystalMine::init()
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

void BuildingOCrystalMine::onEnter()
{

	IBuilding::onEnter();
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITY_UPDATE_CRYSTAL_MINE");
}

void BuildingOCrystalMine::setBuildingSprite()
{

	IBuilding::setBuildingSprite();
}

void BuildingOCrystalMine::ShowAnimWorking(){};

void BuildingOCrystalMine::ShowNormalParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_shuijingk_01.plist");
	Part1->setPosition(0.0f, 20.0f);
	Part1->setScaleX(2.6f);
	Part1->setScaleY(2.6f);
	Part1->setRotation(0.0f);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 1);

	auto Part2 = ParticleSystemQuad::create("Particle/et_shuijingk_02.plist");
	Part2->setPosition(-10.0f, 24.0f);
	Part2->setScaleX(1.64f);
	Part2->setScaleY(3.7f);
	Part2->setRotation(178.26f);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 1);

	auto Part3 = ParticleSystemQuad::create("Particle/et_shuijingk_03.plist");
	Part3->setPosition(-4.0f, 68.0f);
	Part3->setScaleX(1.66f);
	Part3->setScaleY(1.66f);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 1);
}

void BuildingOCrystalMine::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLockVisible())
    return;
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_3970", { {"lv", "3"} }));
    CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
  }

}

void BuildingOCrystalMine::ShowWorkDone(){
	std::unique_ptr<ABuildingMsg> l_BuildingMsg(new ABuildingMsg());
	l_BuildingMsg->BuildingIndex = this->m_BuildingIndex;
	l_BuildingMsg->BuildingNode  = this;
    _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_BuildingMsg.get());
    ShowTopTip();
}