#include "Module/Building/Building.DT.h"
#include "Module/Building/CityBuildingBase.h"
#include "Scene/CityScene.h"
#include "Module/Building/Building.Lib.h"

void DSCityBuildingUnit::fromJson(GJson *json)
{
    if (json == nullptr)
        return;
    buildingLvl = json->GetInt("buildingLvl", 0);
    eBuildingType = static_cast<EBuildingType>(json->GetInt("buildingType", 0));
}

void DSCityBuildingUnit::buildUnit()
{

    Scene *runningScene = Director::getInstance()->getRunningScene();
    if (runningScene == nullptr)
    {
        cocos2d::log("Error: No Current Scene ... ");
        return;
    }
    CityScene *_scene = dynamic_cast<CityScene *>(runningScene);
    if (_scene == nullptr)
    {
        cocos2d::log("Error: The Current Lvl not CityScene... ");
        return;
    }

    auto _node = _scene->CityBuildingLayer->getChildByName(NodeName);
    if (!_node)
    {
        cocos2d::log("Error: The Current Node Has No Name Node With %s", NodeName.c_str());
        return;
    }

    _node->setAnchorPoint(cocos2d::Vec2(0, 0));
    _node->removeAllChildren();
    CityBuildingBase *_building = BuildingLib::getBuildingClassByType(eBuildingType);

    if (_building != nullptr)
    {
        _node->addChild(_building);
        _building->setBuildingUnitData(*this);
    }
    else
        cocos2d::log("ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
}