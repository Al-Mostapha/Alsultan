// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingOSilver : public IBuilding
{

public:
	BuildingOSilver();
	bool init();
	void onEnter();
  void ShowWorkDone() override;
	void setBuildingSprite();
	void ShowAnimWorking();
	static void initBuilingData();
	CREATE_FUNC(BuildingOSilver);

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
