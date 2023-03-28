#include "Module/City/City.Module.h"
#include "CitySceneEffect.h"
#include "Scene/CityScene.h"

#include "Module/UI/Panel/Building/UICreateBuildingPanel.h"

void CityModule::showCityEffect()
{
  EffectMainCityView::showPyramidHonourBuildEffect();
  EffectMainCityView::showPyramidBattleEffect();
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(3),
          CallFunc::create([]() { EffectMainCityView::showFireWorks(500, 500); }),
          nullptr));
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(5),
          CallFunc::create([]()
            { EffectMainCityView::showFinishEffect(
              CityScene::getCityScene()->CityBuildingLayer->getChildByName("build_30006"),
              Vec2(5, 5));
            }),
          nullptr
      )
  );
  EffectMainCityView::showWaterEffect();
  EffectMainCityView::showXiyiAnimation();
  EffectMainCityView::addActivityCentetNpc();
  EffectMainCityView::addCastleGateNpc();
  EffectMainCityView::addHarborWorker();
  EffectMainCityView::addConquerGateAnimation();
  EffectMainCityView::addSoldierGuard();
  EffectMainCityView::showEagle();
  Director::getInstance()->getRunningScene()->runAction(
      Sequence::create(
          DelayTime::create(5),
          CallFunc::create([](){
              EffectMainCityView::addBuildAnimBoostBottom(GString("build_1058"));
              EffectMainCityView::addBuildAnimBoostBottom(GString("build_1059"));
              EffectMainCityView::addHarvestEffect();
              EffectMainCityView::addTouchParticle(Vec2(350, 350));
            }),
          nullptr
      )
  );
  EffectMainCityView::addHarvestEffect();
  EffectMainCityView::addPortEffect();
  EffectMainCityView::addMatouEffect();
  EffectMainCityView::addWallEffect();
  EffectMainCityView::cloudRunEffect();

  auto p = UICreateBuildingPanel::create();
  p->InitPanel();
  Scene *scene = Director::getInstance()->getRunningScene();
  scene->addChild(p);

  
  

}

void CityModule::showCityBuilding()
{
  BuildingModule::buildCity();
}