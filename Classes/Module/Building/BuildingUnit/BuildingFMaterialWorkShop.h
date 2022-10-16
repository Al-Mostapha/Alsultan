// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFMaterialWorkShop : public IBuilding
{

public:
	BuildingFMaterialWorkShop();
	bool init();
	void onEnter();
	void ShowNormalParticle();
	void ShowAnimWorkingSpecific(){}
	void ShowAnimWorking(bool p_ShowGlow = false) override;
  void ShowWorkDone() override;
  void Clicked(Touch *p_Touch, Event *p_Event);
	static void initBuilingData();
	CREATE_FUNC(BuildingFMaterialWorkShop);

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
