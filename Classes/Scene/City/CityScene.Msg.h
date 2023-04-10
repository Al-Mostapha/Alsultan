#pragma once
#include "cocos2d.h"
#include "Module/Building/Building.Enum.h"

class MainCityView;
class IBuilding;

class MainCityMsg{
  public: 
    MainCityView *_Self;
    static MainCityMsg *Get();
    void RegisterMessage(MainCityView *p_MainCity);
    void SetOffsetContainerWithSelectBuild(cocos2d::EventCustom *p_Event);
    void RemoveBuildTip(cocos2d::EventCustom *p_Event);
};