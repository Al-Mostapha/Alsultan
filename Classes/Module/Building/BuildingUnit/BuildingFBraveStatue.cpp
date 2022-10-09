// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFBraveStatue.h"

BuildingFBraveStatue::BuildingFBraveStatue()
{

	BuildingSpriteImage = "yongzhediaoxiang_01.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {3, 16};
	LvlBgOffset = {25, -110};
}

bool BuildingFBraveStatue::init()
{

	if (!CityBuildingBase::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();

	return true;
}

void BuildingFBraveStatue::setBuildingLvBg()
{
	BuildingLvBg = Sprite::createWithSpriteFrameName("frame_armor_quality_01.png");
	BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
	addChild(BuildingLvBg);
}
void BuildingFBraveStatue::onEnter()
{

	CityBuildingBase::onEnter();

	// UpgradeSprite->setTexture("frame_armor_quality_01.png");
}

void BuildingFBraveStatue::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("specialization_text_01")},
      {"lv", std::to_string(GBase::Const::Get()->CastleLvl15)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::getChildByName<Node *>(this, "buildImg"));
    return;
  }
}
