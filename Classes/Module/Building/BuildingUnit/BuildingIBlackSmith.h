// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingIBlackSmith : public IBuilding
{

public:
	BuildingIBlackSmith();
	bool init();
	void onEnter() override;
	void ShowNormalParticle() override;
  void ShowAnimWorking(bool p_ShowGlow = false) override;
  void ShowWorkDone() override;
  void HideWorkDone() override;
	static void initBuilingData();
  void Clicked(Touch *p_Touch, Event *p_Event) override;
	CREATE_FUNC(BuildingIBlackSmith);

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
