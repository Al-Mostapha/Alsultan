// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFLeisureCenter : public IBuilding
{

public:
	BuildingFLeisureCenter();
	bool init();
	void onEnter();
	void setBuildingParticle();
	static void initBuilingData();
	CREATE_FUNC(BuildingFLeisureCenter);

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
