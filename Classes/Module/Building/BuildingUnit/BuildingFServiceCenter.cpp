// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFServiceCenter.h"

BuildingFServiceCenter::BuildingFServiceCenter()
{

	/*
	 local cLevel = cityCtrl:getBuildMaxLv(BUILDID.CASTLE)
		if cLevel >= CASTLE_LV25_LIMITED then
			self.buildImg:setSpriteFrame("BG_notice.png")
			self.buildImg:setPosition(cc.p(-32.5, 0))
			self.buildImg:setLocalZOrder(mainCityDefine.CITY_TARGET_ZORDER.drill)
		elseif SoraDGetFactionType() == FACTION_TYPE.FACTION_NORMAL then
			self.buildImg:setSpriteFrame("gonggaolan.png")
		elseif SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
			self.buildImg:setSpriteFrame("gonggaolan_bzt.png")
			self.buildImg:setPosition(cc.p(25, 20))
		end

	*/
	BuildingSpriteImage = "BG_notice.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-33, 0};
}

bool BuildingFServiceCenter::init()
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

void BuildingFServiceCenter::onEnter()
{

	CityBuildingBase::onEnter();
}
