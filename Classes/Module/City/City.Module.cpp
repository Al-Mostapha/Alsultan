#include "Module/City/City.Module.h"
#include "CitySceneEffect.h"
#include "Scene/CityScene.h"

void CityModule::showCityEffect()
{
  CitySceneEffect::showPyramidHonourBuildEffect();
  CitySceneEffect::showPyramidBattleEffect();
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(3),
          CallFunc::create([]() { CitySceneEffect::showFireWorks(500, 500); }),
          nullptr));
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(5),
          CallFunc::create([]()
            { CitySceneEffect::showFinishEffect(
              CityScene::getCityScene()->CityBuildingLayer->getChildByName("build_30006"),
              Vec2(5, 5));
            }),
          nullptr
      )
  );
  CitySceneEffect::showWaterEffect();
  CitySceneEffect::showXiyiAnimation();
  CitySceneEffect::addActivityCentetNpc();
  CitySceneEffect::addCastleGateNpc();
  CitySceneEffect::addHarborWorker();
  CitySceneEffect::addConquerGateAnimation();
  CitySceneEffect::addSoldierGuard();
  CitySceneEffect::showEagle();
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(5),
          CallFunc::create([](){
              CitySceneEffect::addBuildAnimBoostBottom(GString("build_1058"));
              CitySceneEffect::addBuildAnimBoostBottom(GString("build_1059"));
              CitySceneEffect::addHarvestEffect();
              CitySceneEffect::addTouchParticle(Vec2(350, 350));
            }),
          nullptr
      )
  );
  CitySceneEffect::addHarvestEffect();
  CitySceneEffect::addPortEffect();
  CitySceneEffect::addMatouEffect();
  CitySceneEffect::addWallEffect();
  CitySceneEffect::cloudRunEffect();
  

}

void CityModule::showCityBuilding()
{
  BuildingModule::buildCity();
}