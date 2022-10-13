// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingIEmbassy : public IBuilding
{


public:
	BuildingIEmbassy();
	bool init();
	void onEnter();
	static void initBuilingData();
  void UpdateAllianceHelpList();
  bool IsCanHelp(){return false;}
	CREATE_FUNC(BuildingIEmbassy);

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
