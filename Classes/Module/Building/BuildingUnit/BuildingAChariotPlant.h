// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingAChariotPlant : public CityBuildingBase
{

public:
	BuildingAChariotPlant();
	bool init();
	void onEnter();
	void setBuildingAnimation();
	void setBuildingIconMiracle();

	CREATE_FUNC(BuildingAChariotPlant);

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
