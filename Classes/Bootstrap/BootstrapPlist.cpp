
#include "BootstrapPlist.h"

void BootstrapPlist::loadCitySpriteSheet(CallFunc* afterFinish)
{

	auto spritecache = SpriteFrameCache::getInstance();
	// Director::getInstance()->getRunningScene()->runAction(
	// 		Sequence::create(
				
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("MainCity/mainCityInner.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("MainCity/mainCityOuter.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("MainCity/mainCityEffect.plist");}),
	// 			DelayTime::create(0.1),

  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/armyIcon.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/iconBuilding.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/equipUI.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/allianceUI.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/petIcon.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/itemUI1.plist");}),
	// 			DelayTime::create(0.1),

  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("SingleModule/itemUI1.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("Lucency/xwxuzhuang.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("Lucency/imageEffect.plist");}),
	// 			DelayTime::create(0.1),
        
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("NormalUI/NormalUI1.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("NormalUI/NormalUI2.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("NormalUI/NormalUI3.plist");}),
	// 			DelayTime::create(0.1),
        
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("CommonUI/CommonUI0.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("CommonUI/CommonUI1.plist");}),
	// 			DelayTime::create(0.1),
  //       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("CommonUI/CommonUI2.plist");}),
	// 			DelayTime::create(0.1),
				
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityNpc.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/diaoxiangFA.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityOutGfsc.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/commonFAnimation_1.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/commonFAnimation_2.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("FrameAnimation/NPCAnimation.plist");}),
	// 			DelayTime::create(0.1),

	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI1.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI2.plist");}),
	// 			DelayTime::create(0.1),
	//       CallFunc::create([spritecache](){spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI3.plist");}),
	// 			DelayTime::create(0.1),
  //       afterFinish,
	// 			nullptr
	// 				));
	spritecache->addSpriteFramesWithFile("MainCity/mainCityInner.plist");
	spritecache->addSpriteFramesWithFile("MainCity/mainCityOuter.plist");
	spritecache->addSpriteFramesWithFile("MainCity/mainCityEffect.plist");

	spritecache->addSpriteFramesWithFile("SingleModule/armyIcon.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/iconBuilding.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/equipUI.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/allianceUI.plist");
	spritecache->addSpriteFramesWithFile("SingleModule/petIcon.plist");

	spritecache->addSpriteFramesWithFile("SingleModule/itemUI1.plist");

	spritecache->addSpriteFramesWithFile("Lucency/xwxuzhuang.plist");
	spritecache->addSpriteFramesWithFile("Lucency/imageEffect.plist");

	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI1.plist");
	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI2.plist");
	spritecache->addSpriteFramesWithFile("NormalUI/NormalUI3.plist");

	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI0.plist");
	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI1.plist");
	spritecache->addSpriteFramesWithFile("CommonUI/CommonUI2.plist");

	spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityNpc.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/diaoxiangFA.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/mainCityOutGfsc.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/commonFAnimation_1.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/commonFAnimation_2.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/NPCAnimation.plist");
	spritecache->addSpriteFramesWithFile("FrameAnimation/yun.plist");

	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI1.plist");
	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI2.plist");
	spritecache->addSpriteFramesWithFile("secondaryUI/soldiersUI3.plist");
}

void BootstrapPlist::loadSpriteSheet(CallFunc* afterFinish)
{
	
	loadCitySpriteSheet(afterFinish);
}