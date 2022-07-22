// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/CityBuildingBase.h"

/**
 *
 */
class BuildingABarrack : public CityBuildingBase
{

public:
	BuildingABarrack();
	bool init();
	void onEnter();
	void setBuildingBtn() override;

	CREATE_FUNC(BuildingABarrack);
};
