// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFMonument : public IBuilding
{

public:
	BuildingFMonument();
	bool init();
	void onEnter();
	void setBuildingAnimation() override;
	void setBuildingParticle() override;
  void Clicked(Touch *p_Touch, Event *p_Event) override;
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
