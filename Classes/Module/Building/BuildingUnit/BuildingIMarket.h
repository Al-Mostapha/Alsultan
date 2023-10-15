// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingIMarket : public IBuilding
{

public:
	BuildingIMarket();
	bool init();
	void onEnter();
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	static void initBuilingData();
	CREATE_FUNC(BuildingIMarket);

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
