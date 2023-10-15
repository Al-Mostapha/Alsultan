// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingIHallOfWar : public IBuilding
{

public:
	BuildingIHallOfWar();
	bool init();
	void onEnter() override;
	static void initBuilingData();
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	CREATE_FUNC(BuildingIHallOfWar);

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
