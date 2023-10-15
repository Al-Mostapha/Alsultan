// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFMiracle : public IBuilding
{

public:
	BuildingFMiracle();
	bool init();
	void onEnter();
  void ShowBuildLvl() override;
  void UpdateLvl() override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFMiracle);
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override; 

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
