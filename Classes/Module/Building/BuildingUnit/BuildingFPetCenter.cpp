// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFPetCenter.h"
#include "Base/Common/Common.Teml.h"

BuildingFPetCenter::BuildingFPetCenter()
{

	BuildingSpriteImage = "chongwuguan.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-105, 50};
}

bool BuildingFPetCenter::init()
{

	if (!IBuilding::init())
		return false;

	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();

	BuildingSprite->setLocalZOrder(2);
	auto _Sp = Sprite::createWithSpriteFrameName("frame_chongwuguan_shadow.png");
	_Sp->setPosition(-80, 48);
	addChild(_Sp, 1);
	//  setBuildingIconMiracle();

	return true;
}

void BuildingFPetCenter::onEnter()
{

	IBuilding::onEnter();
}

void BuildingFPetCenter::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_1973", {
      {"lv" , std::to_string(GBase::Const::Get()->CastleLvl4)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
    return;
  }
  
}