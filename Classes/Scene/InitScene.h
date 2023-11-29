#pragma once
#include "cocos2d.h"
#include "Base/Containers/HashMap.h"


class InitScene : public cocos2d::Scene
{
  public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    void onEnter() override;
    void Load();
    CREATE_FUNC(InitScene);
};
