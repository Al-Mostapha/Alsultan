// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingOCrystalMine : public IBuilding
{

public:
	BuildingOCrystalMine();
	bool init();
	void onEnter() override;
	static void initBuilingData();
	void setBuildingSprite();
	void ShowAnimWorking();
	void ShowNormalParticle();
  void ShowWorkDone() override;
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	CREATE_FUNC(BuildingOCrystalMine);

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
