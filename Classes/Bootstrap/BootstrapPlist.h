#pragma once

#include "cocos2d.h"

USING_NS_CC;


class BootstrapPlist : public cocos2d::Ref {

private: 
	static void loadCitySpriteSheet(CallFunc* afterFinish);

public:
	static void loadSpriteSheet(CallFunc* afterFinish);

};
