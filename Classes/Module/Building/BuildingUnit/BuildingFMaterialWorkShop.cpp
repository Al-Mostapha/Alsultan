// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFMaterialWorkShop.h"
#include "Module/UI/Panel/Building/MatrialFactory/UIMatrialFactoryView.h"

BuildingFMaterialWorkShop::BuildingFMaterialWorkShop()
{

	BuildingSpriteImage = "gongfang.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-2, 38};
}

bool BuildingFMaterialWorkShop::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	// setBuildingLvBg();
	// setUpgradeSprite();
	// setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	setBuildingParticle();
	setBuildingAnimation();

	return true;
}

void BuildingFMaterialWorkShop::setBuildingAnimation()
{
	auto frames = getAnimation("gongfangfengche_%02d.png", 1, 8);
	auto frames_1 = getAnimation("gongfangshuiche_%02d.png", 1, 8);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());
	auto sprite_1 = Sprite::createWithSpriteFrame(frames_1.front());

	sprite->setPosition(86, 40);
	sprite_1->setPosition(10, 100);

	auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 8);
	auto animation_1 = Animation::createWithSpriteFrames(frames_1, 1.0f / 8);

	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite_1->runAction(RepeatForever::create(Animate::create(animation_1)));

	addChild(sprite, 5);
	addChild(sprite_1, -1);
}

void BuildingFMaterialWorkShop::onEnter()
{

	IBuilding::onEnter();
}

void BuildingFMaterialWorkShop::setBuildingParticle()
{

	auto Part1 = ParticleSystemQuad::create("Particle/et_gongfang_working_01.plist");
	Part1->setPosition(-5, 0);
	Part1->setScaleX(2.7);
	Part1->setScaleY(1.34);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 10);

	auto Part2 = ParticleSystemQuad::create("Particle/et_gongfang_working_02.plist");
	Part2->setPosition(5, -7);
	Part2->setScaleX(2.8);
	Part2->setScaleY(2.7);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 10);

	auto Part3 = ParticleSystemQuad::create("Particle/et_gongfang_complete_01.plist");
	Part3->setPosition(-5, 0);
	Part3->setScaleX(2.11);
	Part3->setScaleY(1.04);
	Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part3, 10);

	auto Part4 = ParticleSystemQuad::create("Particle/et_gongfang_complete_02.plist");
	Part4->setPosition(10, 20);
	Part4->setScaleX(1.76);
	Part4->setScaleY(1.76);
	Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part4, 10);

	auto Part5 = ParticleSystemQuad::create("Particle/et_gongfang_complete_03.plist");
	Part5->setPosition(0, 10);
	Part5->setScaleX(1.99);
	Part5->setScaleY(1.99);
	Part5->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part5, 10);
}


void BuildingFMaterialWorkShop::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    auto l_TipInfo = Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("common_text_2123")},
      {"lv", ""}
    });
    GBase::DShowMsgTip(l_TipInfo, "gongfang.png");
    CityLib::Get()->ShowTintOnce(GBase::getChildByName<Node *>(this, "buildImg"));
    return;
  }

  auto l_Panel = UIMatrialFactoryView::Create();
  l_Panel->InitPanel();
  l_Panel->Show();
}