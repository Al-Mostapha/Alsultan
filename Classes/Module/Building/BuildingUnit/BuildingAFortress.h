// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Module/Building/IBuilding.h"





/**
 * 
 */
class  BuildingAFortress : public IBuilding
{

public:
	
	BuildingAFortress();
	bool init();
	void onEnter();
  void ShowWorkDone() override;
	static void initBuilingData();
	CREATE_FUNC(BuildingAFortress);

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
