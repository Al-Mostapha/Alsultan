// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Module/Building/IBuilding.h"

/**
 *
 */
class BuildingFEpicBattle : public IBuilding
{

public:
	BuildingFEpicBattle();
	bool init();
	void onEnter();
  void Clicked(Touch *p_Touch, Event *p_Event) override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFEpicBattle);
};
