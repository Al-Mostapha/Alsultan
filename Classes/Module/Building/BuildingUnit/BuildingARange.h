// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingARange : public IBuilding
{

public:
	BuildingARange();
	bool init();
	void onEnter();
	void setBuildingAnimation();
	void setBuildingIconMiracle();
  void ShowWorkDone() override;
	static void initBuilingData();
	CREATE_FUNC(BuildingARange);

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
