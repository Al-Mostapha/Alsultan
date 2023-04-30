// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFBraveStatue.h"
#include "Module/Building/Building.Event.h"
#include <memory>

BuildingFBraveStatue::BuildingFBraveStatue()
{
	BuildingSpriteImage = "yongzhediaoxiang_01.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {3, 16};
	LvlBgOffset = {25, -110};
}

bool BuildingFBraveStatue::init()
{
	if (!IBuilding::init())
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
	n_BuildingLvBg = Sprite::createWithSpriteFrameName("frame_armor_quality_01.png");
	n_BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
	addChild(n_BuildingLvBg);
}
void BuildingFBraveStatue::onEnter()
{

	IBuilding::onEnter();

	// n_UpgradeSprite->setTexture("frame_armor_quality_01.png");
}

void BuildingFBraveStatue::Clicked(Touch *p_Touch, Event *p_Event){
  if(IsLocked()){
    GBase::DShowMsgTip(Translate::i18n("common_text_2122", {
      {"name", Translate::i18n("specialization_text_01")},
      {"lv", std::to_string(GBase::Const::Get()->CastleLvl15)}
    }));
    CityLib::Get()->ShowTintOnce(GBase::DGetChildByName<Node *>(this, "buildImg"));
    return;
  }
}

void BuildingFBraveStatue::ShowWorkDone(){
  auto l_ABuildingMsg = new ABuildingMsg();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", l_ABuildingMsg);
}

void BuildingFBraveStatue::ShowBuildLvl(){
  if(!GetStarLvl())
    return;
  IBuilding::ShowBuildLvl();
}