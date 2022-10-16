// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingOFarm : public IBuilding
{

public:
	BuildingOFarm();
	bool init();
	void onEnter();
	static void initBuilingData();
	void setBuildingSprite();
	void ShowAnimWorking();
  void ShowWorkDone() override;
	CREATE_FUNC(BuildingOFarm);

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
