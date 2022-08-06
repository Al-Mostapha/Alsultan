// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingIWareHouse : public CityBuildingBase
{

public:
	BuildingIWareHouse();
	bool init();
	void onEnter();
	static void initBuilingData();
	CREATE_FUNC(BuildingIWareHouse);

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
