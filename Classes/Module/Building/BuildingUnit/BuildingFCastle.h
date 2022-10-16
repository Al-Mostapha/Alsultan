// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFCastle : public IBuilding
{

public:
  BuildingFCastle();
  bool init();
  void onEnter();
  void setBuildingSprite();
  void UpdateLvl() override;
	static void initBuilingData();
  CREATE_FUNC(BuildingFCastle);

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
