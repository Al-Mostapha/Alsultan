// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFMonument.h"
#include "Scene/CityScene.h"
#include "Module/UI/Panel/Legend/Monument/UILegendM.View.h"
#include "Base/Common/Common.Teml.h"

BuildingFMonument::BuildingFMonument()
{

	BuildingSpriteImage = "map_build_history.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-5, 64};
}

bool BuildingFMonument::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	ShowNormalParticle();
	ShowAnimWorking();
	// setBuildingIconMiracle();

	return true;
}

void BuildingFMonument::ShowAnimWorking(bool p_ShowGlow)
{
	auto frames = getAnimation("dh_xwxuzhuang_%02d.png", 1, 15);
	auto sprite = Sprite::createWithSpriteFrame(frames.front());

	sprite->setPosition(-25, 140);
	sprite->setScale(1.475f, 1.695f);
	sprite->setRotation(-28.15f);
	sprite->setOpacity(76.5f);

	auto animation = Animation::createWithSpriteFrames(frames, 0.1111111111111111f);

	sprite->runAction(RepeatForever::create(Animate::create(animation)));

	addChild(sprite, 11);
}

void BuildingFMonument::ShowNormalParticle()
{
	auto Part1 = ParticleSystemQuad::create("Particle/et_kohbiannianshi_01.plist");
	Part1->setPosition(3 + -25, -20 + 140);
	Part1->setScaleX(1.34f);
	Part1->setScaleY(1.32f);
	Part1->setRotation(-38);
	Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part1, 12);

	auto Part2 = ParticleSystemQuad::create("Particle/et_kohbiannianshi_02.plist");
	Part2->setPosition(3 + -25, -10 + 140);
	Part2->setScaleX(1.092f);
	Part2->setScaleY(1.296f);
	Part2->setRotation(-10);
	Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
	addChild(Part2, 12);
}

void BuildingFMonument::onEnter()
{

	IBuilding::onEnter();
}

void BuildingFMonument::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("history_name_11")},
      {"lv", std::to_string(GBase::Const::Get()->CastleLvl6)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
    return;
  }
  auto l_Sequence = Sequence::create(
    CallFunc::create([this](){
      CityLib::Get()->PlaySound(
        "innerbuildsound", EBuilding::Monument,
        EBuildingActionTag::TagPlayClickBuildSound
      );
      auto l_Scene = CityScene::Get();
      if(l_Scene && l_Scene->ButtonMonument){
        l_Scene->ButtonMonument->setEnabled(false);
        CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
      }
    }),
    DelayTime::create(0.3),
    CallFunc::create([](){
      auto l_Panel = UILegendMView::Create();
      l_Panel->Show();
    }),
    DelayTime::create(0.3),
    CallFunc::create([this](){
      auto l_Scene = CityScene::Get();
      if(l_Scene && l_Scene->ButtonMonument){
        l_Scene->ButtonMonument->setEnabled(true);
        l_Scene->ButtonMonument->setSwallowTouches(false);
      }
    })
  );
  if(CityScene::Get())
    CityScene::Get()->runAction(l_Sequence);
}