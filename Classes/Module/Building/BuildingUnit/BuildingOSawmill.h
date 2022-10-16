// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"


/**
 * 
 */
class  BuildingOSawmill : public IBuilding
{

public:
	
	BuildingOSawmill();
	bool init();
	void onEnter();

	void setBuildingSprite();
	void ShowAnimWorking();
  void ShowWorkDone() override;
	static void initBuilingData();
	CREATE_FUNC(BuildingOSawmill);

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
