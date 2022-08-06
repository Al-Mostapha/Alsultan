// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingOMilitaryTent : public CityBuildingBase
{

public:
	BuildingOMilitaryTent();
	bool init();
	void onEnter();

	void setBuildingSprite();
	void setBuildingAnimation();
	static void initBuilingData();
	CREATE_FUNC(BuildingOMilitaryTent);

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
