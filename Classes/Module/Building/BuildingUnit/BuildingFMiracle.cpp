// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingFMiracle.h"

BuildingFMiracle::BuildingFMiracle()
{

	BuildingSpriteImage = "BG_statue.png";
	BuildingIconMiracle = "armyicon_s_10004711.png";
	BuildingSpriteOffset = {-40, 94};
	LvlBgOffset = {50, -9};
}

bool BuildingFMiracle::init()
{
	if (!IBuilding::init())
		return false;
	setBuildingSprite();
	setBuildingLvBg();
	setUpgradeSprite();
	setBuildingLvlText();
	setBuildingSleepSprite();
	// setBuildingIconMiracle();
	return true;
}

void BuildingFMiracle::onEnter()
{

	IBuilding::onEnter();
}

void BuildingFMiracle::ShowBuildLvl(){
  if(!GetStarLvl())
    return;
  IBuilding::ShowBuildLvl();
}

void BuildingFMiracle::UpdateLvl(){
  ShowBuildLvl();
  IBuilding::UpdateLvl();
}

bool BuildingFMiracle::Clicked(Ref* p_Ref, ui::Widget::TouchEventType p_Touch){
  //   local _iscanbuild, retdata = buildLogic.isCanBuild(BUILDID.MIRACLE)
  //   local tableCurBuild = {
  //     bid = BUILDID.MIRACLE,
  //     iscanbuild = _iscanbuild
  //   }
  //   local tableCurRetdata = retdata
  //   local panel = SoraDCreatePanel("buildCreateInfoPanel")
  //   panel:initBuildData({
  //     buildID = tableCurBuild,
  //     buildData = tableCurRetdata,
  //     buildType = {buildType = buildType, buildIndex = index}
  //   })
  //   panel:show()
  return true;
}