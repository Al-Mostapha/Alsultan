// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingAStable : public CityBuildingBase
{

public:
	BuildingAStable();
	bool init();
	void onEnter();
	void setBuildingAnimation();
	void setBuildingIconMiracle();
	static void initBuilingData();
	CREATE_FUNC(BuildingAStable);

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
