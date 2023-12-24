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

static RBuildingSpecs sDefaultBuildingSpecs;

bool RBuildingSpecs::FromJson(const XJson& pJson) {
  index = pJson.value("index", 0);
  BuildingID = static_cast<EBuilding>(pJson.value("BuildingID", 0));
  oldUnlocklevel = pJson.value("oldUnlocklevel", sDefaultBuildingSpecs.oldUnlocklevel);
  oldShowlevel = pJson.value("oldShowlevel", sDefaultBuildingSpecs.oldShowlevel);
  unlocklevel = pJson.value("unlocklevel", 0);
  showlevel = pJson.value("showlevel", 0);
  bType = static_cast<EBuildingPlace>(pJson.value("bType", 0));
  isDemolish = pJson.value("isDemolish", false);
  isExchange = pJson.value("isExchange", false);
  isBuild = pJson.value("isBuild", false);
  isUpgrade = pJson.value("isUpgrade", false);
  maxCount = pJson.value("maxCount", 0);
  maxLvl = pJson.value("maxLvl", 0);
  initLvl = pJson.value("initLvl", 0);
  openWl = pJson.value("openWl", 0);
  openStar = pJson.value("openStar", 0);
  maxStarLv = pJson.value("maxStarLv", 0);
  isCanBuild = pJson.value("isCanBuild", sDefaultBuildingSpecs.isCanBuild);
  addmaxstarlv = pJson.value("addmaxstarlv", 0);
  BuildingName = pJson.value("BuildingName", "DefaultBuildingName");
  BuildingIcon = pJson.value("BuildingIcon", "DefaultBuildingIcon");
  BuildingBrief = pJson.value("BuildingBrief", "DefaultBuildingBrief");
  UpgradeBrief = pJson.value("UpgradeBrief", "DefaultUpgradeBrief");
  Describe = pJson.value("Describe", "DefaultDescribe");
  WarDescribe = pJson.value("WarDescribe", "DefaultWarDescribe");
  StarDescribe = pJson.value("StarDescribe", "DefaultStarDescribe");
  TipButtons.FromJson(pJson["TipButtons"]);
  for(auto [lLvl, lBuilding] : pJson["Lvls"].items()) {
    Lvls[std::stoi(lLvl)].FromJson(lBuilding);
  }
  return true;
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
    cocos2d::log("Error: The Current Node Has No Name Node With %s", NodeName);
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
