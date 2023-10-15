// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFElitePalace : public IBuilding
{
	void showWorkingEffect();

public:
	BuildingFElitePalace();
	bool init();
	void onEnter() override;
  void ShowWorkDone() override;
	static void initBuilingData();
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
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
