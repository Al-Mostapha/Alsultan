// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingFWall : public CityBuildingBase
{

public:
	BuildingFWall();
	bool init();
	void onEnter();
	EBuildingViewModel getViewModel(int32 wallLvl);
	void setBuildingSprite();

	CREATE_FUNC(BuildingFWall);

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
