#pragma once
#include "cocos2d.h"
#include "Module/Building/Building.Enum.h"

USING_NS_CC;

class MainCityView;
class IBuilding;

class MainCityMsg{
  public: 
    MainCityView *_Self;
    static MainCityMsg *Get();
    void RegisterMessage(MainCityView *p_MainCity);
    void SetOffsetContainerWithSelectBuild(cocos2d::EventCustom *p_Event);
    void RemoveBuildTip(cocos2d::EventCustom *p_Event);
    void AddBuildPreview(EventCustom *p_Event);
    void RemoveBuildPreview(EventCustom *p_Event);
};