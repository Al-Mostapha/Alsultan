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
  bool Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch) override;
	static void initBuilingData();
	CREATE_FUNC(BuildingFEpicBattle);
};
