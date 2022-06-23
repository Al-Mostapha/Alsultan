#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class InitScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene *createScene();
    cocos2d::ui::ScrollView *BaseScrollLayer;
    virtual bool init();
    CREATE_FUNC(InitScene);
};
