// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFElitePalace.h"

BuildingFElitePalace::BuildingFElitePalace()
{

  BuildingSpriteImage = "jingyingdiantang.png";
  BuildingIconMiracle = "armyicon_s_10004711.png";
  BuildingSpriteOffset = {-46, 55};
  LvlBgOffset = {135, -15};
}

bool BuildingFElitePalace::init()
{

  if (!CityBuildingBase::init())
    return false;
  setBuildingSprite();
  setBuildingLvBg();
  setUpgradeSprite();
  setBuildingLvlText();
  setBuildingSleepSprite();
  showWorkingEffect();
  // setBuildingIconMiracle();
  return true;
}

void BuildingFElitePalace::onEnter()
{

  CityBuildingBase::onEnter();
}

void BuildingFElitePalace::showWorkingEffect()
{
  auto Part1 = ParticleSystemQuad::create("Particle/et_jingyingxl_01.plist");
  Part1->setPosition(38, 112);
  Part1->setScaleX(0.6);
  Part1->setScaleY(-0.6);
  Part1->setPositionType(ParticleSystem::PositionType::RELATIVE);
  addChild(Part1, 10);

  auto Part2 = ParticleSystemQuad::create("Particle/et_jingyingxl_02.plist");
  Part2->setPosition(43.5f, 117.8f);
  Part2->setScaleX(1.81f);
  Part2->setScaleY(1.81f);
  Part2->setRotation(0.9f);
  Part2->setPositionType(ParticleSystem::PositionType::RELATIVE);
  addChild(Part2, 10);

  auto Part3 = ParticleSystemQuad::create("Particle/et_jingyingxl_03.plist");
  Part3->setPosition(45.0f, 119.5f);
  Part3->setScaleX(1.35f);
  Part3->setScaleY(1.35f);
  Part3->setRotation(-10.88f);
  Part3->setPositionType(ParticleSystem::PositionType::RELATIVE);
  addChild(Part3, 10);

  auto Part4 = ParticleSystemQuad::create("Particle/et_jingyingxl_04.plist");
  Part4->setPosition(24.0f, -45.0f);
  Part4->setScaleX(1.16f);
  Part4->setScaleY(1.22f);
  Part4->setPositionType(ParticleSystem::PositionType::RELATIVE);
  addChild(Part4, 10);

  auto Part5 = ParticleSystemQuad::create("Particle/et_jingyingxl_05.plist");
  Part5->setPosition(24.0f, 9.0f);
  Part5->setPositionType(ParticleSystem::PositionType::RELATIVE);
  addChild(Part5, 10);
}

void BuildingFElitePalace::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("common_text_3129")},
      {"lv", std::to_string(GBase::Const::Get()->CastleLvl16)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::getChildByName<Node *>(this, "buildImg"));
    return;
  }
}