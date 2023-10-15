// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFBraveStatue : public IBuilding
{

public:
	BuildingFBraveStatue();
	void setBuildingLvBg();
	bool init();
	void onEnter();
  void ShowWorkDone() override;
  void ShowBuildLvl() override;
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFBraveStatue);

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
