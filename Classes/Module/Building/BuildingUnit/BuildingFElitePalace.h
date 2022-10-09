// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingFElitePalace : public CityBuildingBase
{
	void showWorkingEffect();

public:
	BuildingFElitePalace();
	bool init();
	void onEnter();
	static void initBuilingData();
  void Clicked(Touch *p_Touch, Event *p_Event) override;
	CREATE_FUNC(BuildingFElitePalace);

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
