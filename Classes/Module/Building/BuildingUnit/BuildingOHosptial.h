// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingOHosptial : public IBuilding
{

public:
	BuildingOHosptial();
	bool init();
	void onEnter() override;

	void setBuildingSprite();
	void ShowAnimWorking();
	void ShowNormalParticle();
	static void initBuilingData();
  void InitWithUIType() override;
	CREATE_FUNC(BuildingOHosptial);

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
