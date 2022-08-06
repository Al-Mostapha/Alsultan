// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingFEpicBattle : public CityBuildingBase
{

public:
	BuildingFEpicBattle();
	bool init();
	void onEnter();
	static void initBuilingData();
	CREATE_FUNC(BuildingFEpicBattle);
};
