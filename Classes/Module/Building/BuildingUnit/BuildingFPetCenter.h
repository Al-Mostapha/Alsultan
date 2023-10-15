// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFPetCenter : public IBuilding
{

public:
	BuildingFPetCenter();
	bool init();
	void onEnter();
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFPetCenter);

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
