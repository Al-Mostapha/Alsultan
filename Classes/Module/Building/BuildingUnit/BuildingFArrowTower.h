// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingFArrowTower : public CityBuildingBase
{
	EBuildingViewModel getViewModel(int32 wallLvl);
	void setTowerOffet();

public:
	BuildingFArrowTower();
	bool init();
	void onEnter();
	static void initBuilingData();
  void Clicked(Touch *p_Touch, Event *p_Event) override;
	CREATE_FUNC(BuildingFArrowTower);

	/**

	void OnBtnClickedDetail();
	void OnBtnClickedUpgrade();
	void OnBtnClickedTrain();
	void initBuilding();
	void setSprite();
	void showTrainSol();
	void hideTrainSol(
	void setBarrackInfantry();
	void bindBtnActionFunction();
	void setOperatingProgressBar();
	static void getLvlData();
	*/
};
