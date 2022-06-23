// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "cocos2d.h"
#include "Base/BaseTypeDef.h"

USING_NS_CC;
/**
 * 
 */
class  CityBuildingTopTip : public cocos2d::Node
{

public:
	
	Label* TipText;
	Sprite* TipBg;
	Sprite* TipIcon;



	CityBuildingTopTip();
	void setTipIcon(const char* Icon);
	void setTipText();
	void setTipBg();
	void setTipAction();

	bool init();
	void onEnter();

	CREATE_FUNC(CityBuildingTopTip);

	static CityBuildingTopTip* tipTypeFree();
	static CityBuildingTopTip* tipHelpAll();
	static CityBuildingTopTip* tipReqHelp();
	static CityBuildingTopTip* tipTypeTrainFinish();
	static CityBuildingTopTip* tipTopTypeTrainTrap();
	static CityBuildingTopTip* tipTypeCollectFood();
	static CityBuildingTopTip* tipTypeCollectWood();
	static CityBuildingTopTip* tipTypeCollectIron();
	static CityBuildingTopTip* tipTypeCollectCrystal();
	static CityBuildingTopTip* tipTypeCollectSteel();
	static CityBuildingTopTip* tipTypeCollectGangkou();
	static CityBuildingTopTip* tipTypeCommunityBBS();
	static CityBuildingTopTip* tipTypeCommunityService();
	static CityBuildingTopTip* tipTypeTrainEquip();
	static CityBuildingTopTip* tipTypeAllianceWar();
	static CityBuildingTopTip* tipTypeTrainMaterial();
	static CityBuildingTopTip* tipTypeHuochuang();
	static CityBuildingTopTip* tipTypeBulletInBoard();
	static CityBuildingTopTip* tipTypeActivity();
	static CityBuildingTopTip* tipTypePrompt();
	static CityBuildingTopTip* tipTypeGold();
	static CityBuildingTopTip* tipTypePremiumVipMall();
	static CityBuildingTopTip* tipTypeNpcTip();
	static CityBuildingTopTip* tipTypeAllianceTreasureTip();
	static CityBuildingTopTip* tipEndlessTreasure();
	static CityBuildingTopTip* tipTypeCastleGiftTip();
	static CityBuildingTopTip* tipArenaTip();
	static CityBuildingTopTip* tipPetUnlock();
	static CityBuildingTopTip* tipPetSkillSend();
	static CityBuildingTopTip* tipEpicwarFull();
	static CityBuildingTopTip* tipFriendApply();
	static CityBuildingTopTip* tipTypePromote();
	static CityBuildingTopTip* tipTypeHasPrisoner();
	static CityBuildingTopTip* tipTypeHeroReward();
	static CityBuildingTopTip* tipTypeDefendEmptySite();
	static CityBuildingTopTip* tipTypeMonument();

};
