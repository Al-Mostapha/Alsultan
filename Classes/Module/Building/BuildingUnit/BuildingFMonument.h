// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingFMonument : public CityBuildingBase
{

public:
	BuildingFMonument();
	bool init();
	void onEnter();
	void setBuildingAnimation() override;
	void setBuildingParticle() override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFMonument);

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
