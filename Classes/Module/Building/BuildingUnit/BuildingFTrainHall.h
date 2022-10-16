// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFTrainHall : public IBuilding
{

public:
	BuildingFTrainHall();
	bool init();
	void onEnter();
	void ShowNormalParticle();
  void Clicked(Touch *p_Touch, Event *p_Event);
	static void initBuilingData();
	CREATE_FUNC(BuildingFTrainHall);

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
