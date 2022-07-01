
#include "BootstrapPlist.h"

void BootstrapPlist::loadCitySpriteSheet()
{

	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("MainCity/mainCityInner.plist");
	spritecache->addSpriteFramesWithFile("MainCity/mainCityOuter.plist");
	spritecache->addSpriteFramesWithFile("MainCity/mainCityEffect.plist");

	spritecache->addSpriteFramesWithFile("SingleModule/armyIcon.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/iconBuilding.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/equipUI.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/allianceUI.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/petIcon.plist");

	spritecache->addSpriteFramesWithFile("SingleModule/itemUI1.plist");

	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI1.plist");
	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI2.plist");
	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI3.plist");

	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI0.plist");
	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI1.plist");
	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI2.plist");

	spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityNpc.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/diaoxiangFA.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityOutGfsc.plist");

	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI1.plist");
	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI2.plist");
	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI3.plist");
}

void BootstrapPlist::loadSpriteSheet()
{
	loadCitySpriteSheet();
}