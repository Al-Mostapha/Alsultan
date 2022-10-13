// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingABarrack : public IBuilding
{

public:
	BuildingABarrack();
	bool init();
	void onEnter();
	void setBuildingBtn() override;
  void ShowWorkDone() override;
	static void initBuilingData();

	CREATE_FUNC(BuildingABarrack);
};
