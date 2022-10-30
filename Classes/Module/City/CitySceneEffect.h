#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
#include "Scene/City/CityScene.View.h"

USING_NS_CC;

class CitySceneEffect
{

public:
  static Sprite *eagle;
  static Sprite *eagleShadow;
  static Node *eagleEffect;
  static void showPyramidHonourBuildEffect();
  static void showPyramidBattleEffect();
  static void showFireWorks(float xCoord, float yCoord);
  static void showWaterEffect();
  static void showFinishEffect(Node *node, Vec2 pos, bool isCollege = false, bool isToBag = false);
  // Animation For السحلية
  static void showXiyiAnimation();
  static void addActivityCentetNpc();

  static void addCastleGateNpc();
  static void addHarborWorker();
  static void addConquerGateAnimation();

  static void addBuildTipBoxConquerGate();
  static void addWaveEffect();
  static void addSoldierGuard();
  static void showEagle();

  static void addBuildAnimBoostBottom(const GString& BuildingPlace);
  static void addHarvestEffect();
  static void addPortEffect();
  static void addMatouEffect(); // الخيمة الى جنب السفينة
  static void addWallEffect();
  static void addTouchParticle(Vec2 TouchPos);
  static void cloudRunEffect();
  static void showSkillEffectBySkillID();
  static void showWaterfallCastle();

private:
  static void showEagleSpreadWinds();
  static void showEagleGlide();

};