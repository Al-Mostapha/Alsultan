#include "Module/Building/Building.Type.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Building/Building.Lib.h"
#include "Module/Building/IBuilding.h"
#include "Module/City/City.Module.h"
#include "Module/Player/Player.Static.h"
#include "Scene/CityScene.h"

/**-------------------------------------------
 * Reflection For TBuildingLvlSpecs
 * -------------------------------------------*/
// REFLECT_BEGIN(TBuildingLvlSpecs)
// REFLECT_MEMBER(costTime)
// REFLECT_MEMBER(exp)
// REFLECT_MEMBER(kingdomPoint)
// REFLECT_MEMBER(power)
// REFLECT_MEMBER(atkAdd)
// REFLECT_END()

RBuildingSpecs RBuildingSpecs::fromJson(GJson* json) {
  RBuildingSpecs temp;
  temp.index = json->GetInt("index");
  temp.BuildingID = static_cast<EBuilding>(json->GetInt("BuildingID"));
  temp.isDemolish = json->GetBool("isdemolish");
  temp.isExchange = json->GetBool("isExchange");
  temp.isBuild = json->GetBool("isBuild");
  temp.isUpgrade = json->GetBool("isUpgrade");
  temp.buildingType = static_cast<EBuilding>(json->GetInt("buildingType"));
  temp.bType = static_cast<EBuildingPlace>(json->GetInt("bType"));
  temp.maxCount = json->GetInt("maxCount");
  temp.maxLvl = json->GetInt("maxLvl");
  temp.initLvl = json->GetInt("initLvl");
  temp.openWl = json->GetInt("openWl");
  temp.openStar = json->GetInt("openStar");
  temp.maxStarLv = json->GetInt("maxStarLv");
  temp.BuildingName = json->GetString("BuildingName");
  temp.BuildingIcon = json->GetString("BuildingIcon");
  temp.BuildingBrief = json->GetString("BuildingBrief");
  temp.UpgradeBrief = json->GetString("UpgradeBrief");
  temp.Describe = json->GetString("Describe");
  temp.WarDescribe = json->GetString("WarDescribe");
  temp.StarDescribe = json->GetString("StarDescribe");
  return temp;
}



void RCityBuildingUnit::fromJson(GJson* json) {
  if (json == nullptr) return;
  buildingLvl = json->GetInt("buildingLvl", 0);
  eBuildingType = static_cast<EBuilding>(json->GetInt("buildingType", 0));
}

RCityBuildingUnit& RCityBuildingUnit::buildUnit() {
  CityScene* l_RunningScene = CityScene::Get();
  if (l_RunningScene == nullptr) {
    cocos2d::log("Error: No Current Scene ... ");
    return *this;
  }

  auto _node = l_RunningScene->CityBuildingLayer->getChildByName(NodeName);
  if (!_node) {
    cocos2d::log("Error: The Current Node Has No Name Node With %s", NodeName.c_str());
    return *this;
  }

  _node->setAnchorPoint(cocos2d::Vec2(0, 0));
  _node->removeAllChildren();
  IBuilding* _building = BuildingLib::getBuildingClassByType(eBuildingType);

  if (_building != nullptr) {
    _building->setBuildingUnitData(*this);
    _node->addChild(_building);
  } else
    cocos2d::log("This Building Donot Has BuildingClass");
  return *this;
}

RCityBuildingUnit& RCityBuildingUnit::addToBuildingList() {
  BuildingModule::getCurentCityBuilding().BuildingList[BuildingPlace] = *this;
  return *this;
}
