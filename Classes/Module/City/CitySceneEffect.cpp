#include "Module/City/CitySceneEffect.h"
#include <cmath>
#include "Module/Building/Building.Lib.h"
#include "Module/Building/Building.Module.h"
#include "Module/Building/IBuilding.h"
#include "Scene/City/CityScene.Enum.h"
#include "Scene/CityScene.h"

// Sould be moved to main city View
cocos2d::Sprite* EffectMainCityView::eagle = nullptr;
cocos2d::Sprite* EffectMainCityView::eagleShadow = nullptr;
cocos2d::Node* EffectMainCityView::eagleEffect = nullptr;

EffectMainCityView *EffectMainCityView::Get(){
  static auto l_Inst = new EffectMainCityView();
  return l_Inst;
}

void EffectMainCityView::showPyramidHonourBuildEffect() {
  auto CitySen = CityScene::getCityScene();
  if (!CitySen) return;
  if (CitySen->getChildByName("et_node_pyramid_lion")) CitySen->removeChildByName("et_node_pyramid_lion");

  Node* EffectNode = Node::create();
  EffectNode->setName("et_node_pyramid_lion");
  EffectNode->setPosition(4480, 2140);

  auto Part1 = BaseCreate::createParticle("Particle/et_diaoxiang_03.plist", Vec2(0.0f, 0.0f), Vec2(0.8f, 0.8f), 21.21f);
  auto Part2 = BaseCreate::createParticle("Particle/et_diaoxiang_02.plist", Vec2(-16, -33), Vec2(0.514f, 1.0f), 27.25f);
  auto Part3 = BaseCreate::createParticle("Particle/et_diaoxiang_01.plist", Vec2(-15, -37), Vec2(1, 1), 0);

  EffectNode->addChild(Part1, 1);
  EffectNode->addChild(Part2, 1);
  EffectNode->addChild(Part3, 1);

  CitySen->CityBuildingLayer->addChild(EffectNode, 1500);
}

void EffectMainCityView::showPyramidBattleEffect() {
  auto CitySen = CityScene::getCityScene();
  if (!CitySen) return;
  if (CitySen->getChildByName("et_node_pyramid_battle")) CitySen->removeChildByName("et_node_pyramid_battle");
  Node* EffectNode = Node::create();
  EffectNode->setName("et_node_pyramid_battle");
  EffectNode->setPosition(4917.5, 2160.5);

  auto Part1 = BaseCreate::createParticle("Particle/et_zhaishengjiecb_02.plist", Vec2(0, 0), Vec2(1.5, 2.08f), 234.38f);
  auto Part2 = BaseCreate::createParticle("Particle/et_jinzita_01.plist", Vec2(-2, -10.5), Vec2(1, 1), 236.64f);

  EffectNode->addChild(Part1, 1);
  EffectNode->addChild(Part2, 1);

  CitySen->CityBuildingLayer->addChild(EffectNode, 1500);
}

void EffectMainCityView::showFireWorks(float xCoord, float yCoord) {
  float frames = 60.0;
  auto parent = Director::getInstance()->getRunningScene();
  auto dh_firework1 = Sprite::createWithSpriteFrameName("dh_gift_fire_03.png");
  dh_firework1->setOpacity(100);
  dh_firework1->setPosition(xCoord - 78.78f - 30.0f, yCoord - 38);
  parent->addChild(dh_firework1, 9);

  auto dh_firework2 = Sprite::createWithSpriteFrameName("dh_gift_fire_01.png");
  dh_firework2->setOpacity(100);
  dh_firework2->setPosition(xCoord + 0.07f, yCoord + 0);
  parent->addChild(dh_firework2, 9);

  auto dh_firework3 = Sprite::createWithSpriteFrameName("dh_gift_fire_02.png");
  dh_firework3->setOpacity(100);
  dh_firework3->setPosition(xCoord + 66.29f + 30, yCoord - 62);
  parent->addChild(dh_firework3, 9);

  auto firework1 = [dh_firework1, frames]() {
    auto Part1 = BaseCreate::createParticle("Particle/et_gift_fire_07.plist", Vec2(0.2f, -1.87f), Vec2(1, 1), 0);
    auto Part2 = BaseCreate::createParticle("Particle/et_gift_fire_08.plist", Vec2(0.2f, -1.87f), Vec2(2, 2), 0);
    auto Part3 = BaseCreate::createParticle("Particle/et_gift_fire_09.plist", Vec2(0.2f, -1.87f), Vec2(3, 3), 0);
    Sequence* actionSeq4 = Sequence::create(DelayTime::create(25 / frames),
                                            CallFunc::create([Part1, Part2, Part3]() {
                                              Part1->resetSystem();
                                              Part2->resetSystem();
                                              Part3->resetSystem();
                                            }),
                                            NULL);
    Part1->runAction(DelayTime::create(25 / frames));
    Part2->runAction(DelayTime::create(25 / frames));
    Part3->runAction(DelayTime::create(20 / frames));
    dh_firework1->addChild(Part1, 2);
    dh_firework1->addChild(Part2, 2);
    dh_firework1->addChild(Part3, 2);
  };
  auto action1 = Spawn::create(MoveBy::create(20 / frames, Vec2(0, Director::getInstance()->getVisibleOrigin().y + 220)),
                               FadeOut::create(21 / frames),
                               CallFunc::create(firework1),
                               nullptr);

  dh_firework1->runAction(
          RepeatForever::create(Sequence::create(DelayTime::create(0.1f),
                                                 action1,
                                                 DelayTime::create(0.5),
                                                 CallFunc::create([dh_firework1]() { dh_firework1->removeFromParentAndCleanup(true); }),
                                                 nullptr)));

  auto firework2 = [frames, dh_firework2]() {
    auto Part1 = BaseCreate::createParticle("Particle/et_gift_fire_01.plist", Vec2(0.2f, -1.87f), Vec2(1, 1), 0);
    auto Part2 = BaseCreate::createParticle("Particle/et_gift_fire_02.plist", Vec2(0.2f, -1.87f), Vec2(2, 2), 0);
    auto Part3 = BaseCreate::createParticle("Particle/et_gift_fire_03.plist", Vec2(0.2f, -1.87f), Vec2(5, 5), 0);
    Sequence* actionSeq4 = Sequence::create(DelayTime::create(25 / frames),
                                            CallFunc::create([Part1, Part2, Part3]() {
                                              Part1->resetSystem();
                                              Part2->resetSystem();
                                              Part3->resetSystem();
                                            }),
                                            NULL);
    Part1->runAction(DelayTime::create(25 / frames));
    Part2->runAction(DelayTime::create(25 / frames));
    Part3->runAction(DelayTime::create(20 / frames));
    dh_firework2->addChild(Part1, 2);
    dh_firework2->addChild(Part2, 2);
    dh_firework2->addChild(Part3, 2);
  };

  auto action2 = Spawn::create(MoveBy::create(20 / frames, Vec2(0, Director::getInstance()->getVisibleOrigin().y + 220)),
                               FadeOut::create(21 / frames),
                               CallFunc::create(firework2),
                               nullptr);
  dh_firework2->runAction(Sequence::create(
          action2, DelayTime::create(0.5), CallFunc::create([dh_firework2]() { dh_firework2->removeFromParentAndCleanup(true); }), nullptr));

  auto firework3 = [dh_firework3, frames]() {
    auto Part1 = BaseCreate::createParticle("Particle/et_gift_fire_04.plist", Vec2(0.2f, -1.87f), Vec2(1, 1), 0);
    auto Part2 = BaseCreate::createParticle("Particle/et_gift_fire_05.plist", Vec2(0.2f, -1.87f), Vec2(2, 2), 0);
    auto Part3 = BaseCreate::createParticle("Particle/et_gift_fire_06.plist", Vec2(0.2f, -1.87f), Vec2(3, 3), 0);
    Sequence* actionSeq4 = Sequence::create(DelayTime::create(25 / frames),
                                            CallFunc::create([Part1, Part2, Part3]() {
                                              Part1->resetSystem();
                                              Part2->resetSystem();
                                              Part3->resetSystem();
                                            }),
                                            NULL);
    Part1->runAction(DelayTime::create(25.0f / frames));
    Part2->runAction(DelayTime::create(25.0f / frames));
    Part3->runAction(DelayTime::create(20.0f / frames));
    dh_firework3->addChild(Part1, 2);
    dh_firework3->addChild(Part2, 2);
    dh_firework3->addChild(Part3, 2);
  };

  auto action3 = Spawn::create(MoveBy::create(20 / frames, Vec2(0, Director::getInstance()->getVisibleOrigin().y + 220)),
                               FadeOut::create(21 / frames),
                               CallFunc::create(firework3),
                               nullptr);

  dh_firework3->runAction(Sequence::create(DelayTime::create(0.2f),
                                           action3,
                                           DelayTime::create(0.5),
                                           CallFunc::create([dh_firework3]() { dh_firework3->removeFromParentAndCleanup(true); }),
                                           nullptr));
}

void EffectMainCityView::showWaterEffect() {
  // local _shader = require(cfg.shader)
  // local _meshData = require(cfg.meshData)
  // local _param = require(cfg.param)
  // local effectNode = SoraDCreateMeshNode(_meshData, cc.size(1, 1), _shader, _param.param)
  // effectNode:setName(cfg.name)
  // effectNode:setPosition(cc.p(unpack(cfg.position)))
  // effectNode:setScale(unpack(cfg.scale))
  // effectNode:setVisible(true)
  // effectNode:addTo(mainCity.cityWaterNode, 1)
  // if cfg.rotation then
  //   effectNode:setRotation3D(cc.vec3(unpack(cfg.rotation)))
  // end
  // if cfg.rotation2D then
  //   effectNode:setRotation(cfg.rotation2D)
  // end
  // if cfg.scaleZ then
  //   effectNode:setScaleZ(cfg.scaleZ)
  // end
  // if cfg.notAutoCull then
  //   effectNode:setAutoCull(false)
  // end
  // if cfg.showRect then
  //   local drawNode = cc.DrawNode:create()
  //   drawNode:setPosition(0, 0)
  //   drawNode:drawRect(cc.p(_meshData.bounds.minPos[1], _meshData.bounds.minPos[2]), cc.p(_meshData.bounds.maxPos[1], _meshData.bounds.maxPos[2]),
  //   cc.c4f(1, 0, 1, 1)) drawNode:addTo(effectNode) drawNode:setLocalZOrder(999999) drawNode:setName("effectNodeSize")
  // end
  // if not cfg.sliderPos then
  //   return
  // end
  // local handlerNode = effectNode
  // local sliderOffsetX = 200
  // local sliderOffsetY = 500
  // local sliderX = cc.CSLoader:createNode(getCCSPath("cityBuildSliderChange"))
  // local commonSlider = include("commonSlider")
  // sliderX = commonSlider.new(sliderX)
  // local sliderData = {
  //   maxValue = 5000,
  //   minValue = 1,
  //   curValue = cfg.position[1],
  //   openEditBox = true
  // }
  // sliderX:initData(sliderData)
  // sliderX:addTo(mainCity.containerView)
  // sliderX:setPosition(cc.p(cfg.sliderPos[1] + sliderOffsetX, cfg.sliderPos[2] + 120 + sliderOffsetY))
  // sliderX:setLocalZOrder(10000)
  // sliderX:setSliderCallBack(function(valuechange)
  //   handlerNode:setPositionX(valuechange)
  // end)
  // local sliderY = cc.CSLoader:createNode(getCCSPath("cityBuildSliderChange"))
  // local commonSlider = include("commonSlider")
  // sliderY = commonSlider.new(sliderY)
  // local sliderData = {
  //   maxValue = 3600,
  //   minValue = 1,
  //   curValue = cfg.position[2],
  //   openEditBox = true
  // }
  // sliderY:initData(sliderData)
  // sliderY:addTo(mainCity.containerView)
  // sliderY:setPosition(cc.p(cfg.sliderPos[1] + sliderOffsetX, cfg.sliderPos[2] + 60 + sliderOffsetY))
  // sliderY:setLocalZOrder(10000)
  // sliderY:setSliderCallBack(function(valuechange)
  //   handlerNode:setPositionY(valuechange)
  // end)
  // local scale = cc.CSLoader:createNode(getCCSPath("cityBuildSliderChange"))
  // local commonSlider = include("commonSlider")
  // scale = commonSlider.new(scale)
  // local sliderData = {
  //   maxValue = 300,
  //   minValue = 1,
  //   curValue = cfg.scale[1] * 100,
  //   openEditBox = true
  // }
  // scale:initData(sliderData)
  // scale:addTo(mainCity.containerView)
  // scale:setPosition(cc.p(cfg.sliderPos[1] + sliderOffsetX, cfg.sliderPos[2] + sliderOffsetY))
  // scale:setLocalZOrder(10000)
  // scale:setSliderCallBack(function(valuechange)
  //   handlerNode:setScale(valuechange / 100)
  // end)
}

void EffectMainCityView::showFinishEffect(Node* nodeFrom, Vec2 posTo, bool isCollege, bool isToBag) {
  auto myPos = nodeFrom->convertToWorldSpace(posTo);
  float mutiple = 0.5;
  auto parent = Director::getInstance()->getRunningScene();
  auto powerPos = Vec2(Director::getInstance()->getVisibleOrigin().x, Director::getInstance()->getWinSize().height - 105);
  if (isToBag) powerPos = Vec2(440, 100);

  auto spriteName = "et_yellow_xlwctx_display_01.png";
  auto plistPath = "Particle/et_yellow_xlwctx_display.plist";
  auto frameFormat = "et_yellow_xlwctx_display_%.2d.png";
  if (isCollege) {
    spriteName = "et_orange_zhandouli_display_01.png";
    plistPath = "Particle/et_orange_zhandouli_display.plist";
    frameFormat = "et_orange_zhandouli_display_%.2d.png";
  }
  auto powerNode = Node::create();
  powerNode->setPosition(myPos);
  parent->addChild(powerNode, 9);
  auto powerSprite = Sprite::createWithSpriteFrameName(spriteName);
  float rotation = (((atan((powerPos.y - myPos.y) / abs(powerPos.x - myPos.x))) * 180.0f) / M_PI) - 180.0f;
  if (myPos.x < Director::getInstance()->getVisibleOrigin().x) rotation = -180 - rotation;
  powerSprite->setRotation(rotation);
  powerNode->addChild(powerSprite);
  auto particle_power = BaseCreate::createParticle(plistPath, Vec2(110, 38), Vec2(1, 1), 180);
  powerSprite->addChild(particle_power);

  auto frames = BaseCreate::getAnimationFrames(frameFormat, 1, 9);
  auto animation = Animation::createWithSpriteFrames(frames, mutiple * 1 / 9);
  powerSprite->runAction(Animate::create(animation));
  auto seq = Sequence::create(
          MoveTo::create(1 * mutiple, powerPos), CallFunc::create([powerNode]() { powerNode->removeFromParentAndCleanup(true); }), nullptr);
  powerNode->runAction(seq);
}

void EffectMainCityView::showXiyiAnimation() {
  GDisplay::Get()->AddSpriteFrames("FrameAnimation/NPCAnimation.plist");
  int32 xiyiSpeed = 50;
  auto runXiyiAnimation = [xiyiSpeed](Sprite* s, Vec2 PosFrom, Vec2 PosTo, float rot, bool isFlippedX) {
    float distance = PosFrom.getDistance(PosTo);
    float dt = distance / xiyiSpeed;
    auto callFunc1 = CallFunc::create([s, isFlippedX]() {
      auto Frames = BaseCreate::getAnimationFrames("xiyi_0%d.png", 1, 8);
      auto animation = Animation::createWithSpriteFrames(Frames, .05f);
      s->setFlippedX(isFlippedX);
      auto forEver = RepeatForever::create(Animate::create(animation));
      forEver->setTag(10);
      s->runAction(forEver);
    });
    MoveBy* moveBy1 = MoveBy::create(dt, PosTo - PosFrom);
    auto callFunc2 = CallFunc::create([s, PosFrom]() {
      auto fadeTo = FadeTo::create(0.3f, 0);
      s->runAction(fadeTo);
    });

    auto callFunReset = CallFunc::create([s, PosFrom]() {
      s->setPosition(PosFrom);
      s->setOpacity(255);
      s->setVisible(true);
      s->stopActionByTag(10);
    });

    auto delay = DelayTime::create(rand() % 5 + 3.0f);
    s->runAction(RepeatForever::create(Sequence::create(callFunc1, moveBy1, callFunc2, delay, callFunReset, nullptr)));
  };
  CityScene* scene = CityScene::getCityScene();
  if (!scene) return;
  Sprite* sprite_1 = Sprite::createWithSpriteFrameName("xiyi_01.png");
  Sprite* sprite_2 = Sprite::createWithSpriteFrameName("xiyi_01.png");
  Sprite* sprite_3 = Sprite::createWithSpriteFrameName("xiyi_01.png");
  scene->_MainCityView->_BatchNodeXiyiNpc->addChild(sprite_1);
  scene->_MainCityView->_BatchNodeXiyiNpc->addChild(sprite_2);
  scene->_MainCityView->_BatchNodeXiyiNpc->addChild(sprite_3);
  sprite_1->setPosition(3706, 789);
  sprite_2->setPosition(3704, 302);
  sprite_3->setPosition(4525, 497);
  sprite_1->setLocalZOrder(1);
  sprite_2->setLocalZOrder(2);
  sprite_3->setLocalZOrder(3);
  runXiyiAnimation(sprite_1, Vec2(3706, 789), Vec2(4103, 1013), 0, false);
  runXiyiAnimation(sprite_2, Vec2(3704, 302), Vec2(3534, 422), 0, true);
  runXiyiAnimation(sprite_3, Vec2(4525, 497), Vec2(4800, 637), 0, false);
}

void EffectMainCityView::addActivityCentetNpc() {
  GDisplay::Get()->AddSpriteFrames("FrameAnimation/mainCityNpc.plist");
  auto sprite = Sprite::createWithSpriteFrameName("funvxiaohai_01.png");
  auto scene = CityScene::getCityScene();
  if (!scene) return;
  scene->_MainCityView->_ContainerView->addChild(sprite, ECityTargetZOrder::Get()->xunluo);
  sprite->setPosition(1842, 1786);
  CallFunc* callFunc1 = CallFunc::create([sprite]() {
    auto frames = BaseCreate::getAnimationFrames("funvxiaohai_0%d.png", 1, 8);
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.175f);
    sprite->setFlippedX(false);
    RepeatForever* repeatForever = RepeatForever::create(Animate::create(animation));
    repeatForever->setTag(20);
    sprite->runAction(repeatForever);
  });

  CallFunc* callFunc2 = CallFunc::create([sprite]() {
    sprite->stopAllActionsByTag(20);
    sprite->setSpriteFrame("funvxiaohai_01.png");
  });
  Sequence* actSeq = Sequence::create(callFunc1, DelayTime::create(2.8f), callFunc2, DelayTime::create(rand() % 4 + 2.0f), nullptr);
  sprite->runAction(RepeatForever::create(actSeq));
}

void EffectMainCityView::addCastleGateNpc() {
  Sprite* sprite = Sprite::createWithSpriteFrameName("shiming_01.png");
  sprite->setScale(0.5);
  sprite->setLocalZOrder(ECityTargetZOrder::Get()->juying);
  CityScene* scene = CityScene::getCityScene();
  if (!scene) return;
  scene->_MainCityView->_ContainerView->addChild(sprite);
  sprite->setPosition(2200, 1762);
  auto Frames = BaseCreate::getAnimationFrames("shiming_%02d.png", 1, 16);
  Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
  sprite->runAction(RepeatForever::create(Animate::create(animation)));
}

void EffectMainCityView::addHarborWorker() {
  Vec2 basePos = Vec2(4052, 1720);
  int32 guardSpeed = 20;
  Vec2 baseTarget = Vec2(3663, 1906);
  float distance = basePos.getDistance(baseTarget);
  auto runHarborAnimation = [distance, guardSpeed, basePos, baseTarget](Sprite* sprite, bool rev) {
    float dt = distance / guardSpeed;
    CallFunc* callFunc1 = CallFunc::create([sprite]() {
      auto Frames = BaseCreate::getAnimationFrames("banyungong_wn_0%d.png", 1, 8);
      Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
      Animate* animate = Animate::create(animation);
      sprite->setFlippedX(false);
      RepeatForever* repeatForEver = RepeatForever::create(animate);
      repeatForEver->setTag(10);
      sprite->runAction(repeatForEver);
      sprite->stopActionByTag(20);
    });
    MoveBy* moveBy1 = MoveBy::create(dt, baseTarget - basePos);

    CallFunc* callFunc2 = CallFunc::create([sprite]() {
      auto Frames = BaseCreate::getAnimationFrames("banyungong_es_0%d.png", 1, 8);
      Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
      Animate* animate = Animate::create(animation);
      sprite->setFlippedX(false);
      RepeatForever* repeatForEver = RepeatForever::create(animate);
      repeatForEver->setTag(20);
      sprite->runAction(repeatForEver);
      sprite->stopActionByTag(10);
    });

    MoveBy* moveBy2 = moveBy1->reverse();
    if (!rev) {
      sprite->runAction(RepeatForever::create(Sequence::create(callFunc1, moveBy1, callFunc2, moveBy2, nullptr)));
    } else {
      sprite->runAction(RepeatForever::create(Sequence::create(callFunc2, moveBy2, callFunc1, moveBy1, nullptr)));
    }
  };

  Sprite* sprite_1 = Sprite::createWithSpriteFrameName("banyungong_wn_01.png");
  Sprite* sprite_2 = Sprite::createWithSpriteFrameName("banyungong_wn_01.png");
  CityScene* cityScene = CityScene::getCityScene();
  if (!cityScene) return;
  cityScene->_MainCityView->_BatchNodeNpc->addChild(sprite_1, 1);
  cityScene->_MainCityView->_BatchNodeNpc->addChild(sprite_2, 2);
  sprite_1->setPosition(basePos);
  sprite_2->setPosition(basePos + Vec2(-15, -10));
  runHarborAnimation(sprite_1, false);
  runHarborAnimation(sprite_2, true);
}

void EffectMainCityView::addConquerGateAnimation() {
  GDisplay::Get()->AddSpriteFrames("FrameAnimation/mainCityNpc.plist");
  GDisplay::Get()->AddSpriteFrames("FrameAnimation/commonFAnimation_1.plist");
  struct AnimationTab {
    GString png;
    Vec2 pos;
    GString formate;
    int32 first;
    int32 last;
    bool isAct;
  };
  AnimationTab animTab[10] = {{"shibing1_02.png", Vec2(45, 75), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(-45, 60), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(-10, 45), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(75, 60), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(15, 90), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(25, 30), "", 0, 0, false},
                              {"qibingqizhi_01.png", Vec2(90, 79), "qibingqizhi_%.2d.png", 1, 4, true},
                              {"qibingqizhi_01.png", Vec2(45, 51), "qibingqizhi_%.2d.png", 1, 4, true},
                              {"shibing1_02.png", Vec2(105, 46), "", 0, 0, false},
                              {"shibing1_02.png", Vec2(60, 18), "", 0, 0, false}};
  CityScene* scene = CityScene::getCityScene();
  if (!scene) return;
  Node* BtnConquer = scene->_MainCityView->_ContainerView->getChildByName("Button_conquer");
  if (!BtnConquer) return;

  int32 index = 0;
  for (auto oneTab : animTab) {
    Sprite* shibing = Sprite::createWithSpriteFrameName(oneTab.png);
    shibing->setPosition(oneTab.pos);
    BtnConquer->addChild(shibing, index++);
    if (oneTab.isAct) {
      auto Frames = BaseCreate::getAnimationFrames(oneTab.formate, oneTab.first, oneTab.last);
      Animation* animation = Animation::createWithSpriteFrames(Frames, 0.8f / (float)Frames.size());
      shibing->runAction(RepeatForever::create(Animate::create(animation)));
    }
  }
}

void EffectMainCityView::addBuildTipBoxConquerGate() {
  //   local self = mainCity
  //   local tipBoxName = "ConquerGateTipBox"
  //   if self.tipBoxConquerGate == nil then
  //     local textContent = i18n("common_text_2112")
  //     local cityBuildTipBox = include("cityBuildTipBox")
  //     local cityBuildTipBoxNode = cityBuildTipBox.new()
  //     local data = {
  //       boxType = cityBuildConstDef.TipBoxType.TEXT_TYPE_1,
  //       content = textContent,
  //       handler = handler(self, self.onTipBoxCall),
  //       tag = cityBuildConstDef.OtherBuildDef.ConquerGate,
  //       autoDelete = true
  //     }
  //     cityBuildTipBoxNode:initWithData(data)
  //     cityBuildTipBoxNode:setName(tipBoxName)
  //     cityBuildTipBoxNode:setPosition(cc.p(2700, 1800))
  //     self.containerView:addChild(cityBuildTipBoxNode, mainCityDefine.CITY_TARGET_ZORDER.tips)
  //     self.tipBoxConquerGate = cityBuildTipBoxNode
  //   else
  //     self.tipBoxConquerGate:setVisible(true)
  //     local textContent = i18n("common_text_2112")
  //     local data = {
  //       boxType = cityBuildConstDef.TipBoxType.TEXT_TYPE_1,
  //       content = textContent,
  //       handler = handler(self, self.onTipBoxCall),
  //       tag = cityBuildConstDef.OtherBuildDef.ConquerGate,
  //       autoDelete = true
  //     }
  //     self.tipBoxConquerGate:initWithData(data)
  //   end
}

void EffectMainCityView::addWaveEffect() {
  //  do return end
  // local self = mainCity
  // local uint = 30
  // local function runEffectWave(imageName, beginPos, endPos, delayTime, zOrder, scaleX, scaleY)
  //   if nil == imageName then
  //     return
  //   end
  //   local spriteWave = display.newSprite(imageName)
  //   self.batchNodeCityEffect:addChild(spriteWave, zOrder or 1)
  //   local callFuncWave = cca.callFunc(function()
  //     local callFuncReset = cca.callFunc(function()
  //       spriteWave:setScaleX(scaleX)
  //       spriteWave:setScaleY(scaleY)
  //       spriteWave:setPosition(beginPos)
  //       spriteWave:setOpacity(0)
  //     end)
  //     local fadeIn = cca.fadeIn(30 / uint)
  //     local moveTo = cca.moveTo(80 / uint, endPos.x, endPos.y)
  //     local delay = cca.delay(60 / uint)
  //     local fadeOut = cca.fadeOut(30 / uint)
  //     local seq1 = cca.seq({delay, fadeOut})
  //     local scalTo = cca.scaleTo(80 / uint, 1, 1)
  //     local spawn = cca.spawn({
  //       fadeIn,
  //       scalTo,
  //       moveTo,
  //       seq1
  //     })
  //     local delaySep = cca.delay(6)
  //     local seq2 = cca.seq({
  //       callFuncReset,
  //       spawn,
  //       delaySep
  //     })
  //     spriteWave:runAction(cca.repeatForever(seq2))
  //   end)
  //   local delayWave = cca.delay(delayTime)
  //   spriteWave:runAction(cca.seq({delayWave, callFuncWave}))
  // end
  // for i = 1, 3 do
  //   runEffectWave("#et_hailang_01.png", cc.p(4333.42, 1429.92), cc.p(4347.5, 1423.14), i * (40 / uint), i, 0.5, 0.5)
  // end
  // for i = 1, 3 do
  //   runEffectWave("#et_hailang_02.png", cc.p(4320.88, 1273.45), cc.p(4334.44, 1284.4), i * (40 / uint), i, 0.5, 0.5)
  // end
}

void EffectMainCityView::addSoldierGuard() {
  Vec2 basePos = Vec2(3716, 977);
  float guardSpeed = 16;
  Vec2 baseTarget = Vec2(3564, 1075);
  float distance = basePos.getDistance(baseTarget);
  std::function<void(Sprite*)> runGuardAnimation = [distance, guardSpeed, baseTarget, basePos](Sprite* sprite) {
    float dt = distance / guardSpeed;
    CallFunc* callFunc1 = CallFunc::create([sprite]() {
      auto Frames = BaseCreate::getAnimationFrames("xunluo_wn_0%d.png", 1, 8);
      Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
      Animate* animate = Animate::create(animation);
      sprite->setFlippedX(false);
      RepeatForever* repeatForEver = RepeatForever::create(animate);
      repeatForEver->setTag(10);
      sprite->runAction(repeatForEver);
      sprite->stopActionByTag(20);
    });
    MoveBy* moveBy1 = MoveBy::create(dt, baseTarget - basePos);
    CallFunc* callFunc2 = CallFunc::create([sprite]() {
      auto Frames = BaseCreate::getAnimationFrames("xunluo_ws_0%d.png", 1, 8);
      Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
      Animate* animate = Animate::create(animation);
      sprite->setFlippedX(true);
      RepeatForever* repeatForEver = RepeatForever::create(animate);
      repeatForEver->setTag(20);
      sprite->runAction(repeatForEver);
      sprite->stopActionByTag(10);
    });
    MoveBy* moveBy2 = moveBy1->reverse();
    sprite->runAction(RepeatForever::create(Sequence::create(callFunc1, moveBy1, callFunc2, moveBy2, nullptr)));
  };
  CityScene* scene = CityScene::getCityScene();
  if (!scene) return;
  for (int32 i = 1; i <= 4; i++) {
    Sprite* sprite = Sprite::createWithSpriteFrameName("xunluo_wn_01.png");
    scene->_MainCityView->_BatchNodeSoldierGuards->addChild(sprite);
    if (i == 2) {
      sprite->setName("soldier_guard_2");
      scene->_MainCityView->AddToBufferNodeArrayByName("soldier_guard_2", sprite);
    }
    sprite->setPosition(basePos + Vec2((float)i * 20, -(float)i * 10));
    sprite->setLocalZOrder(i);
    runGuardAnimation(sprite);
  }
}

void EffectMainCityView::showEagleGlide() {
  eagle->stopAllActions();
  eagleShadow->stopAllActions();
  eagle->setSpriteFrame("juying_01.png");
  eagleShadow->setSpriteFrame("juying2_01.png");
  DelayTime* delay = DelayTime::create(random(2.0f, 3.0f) + random(0.0f, 1.0f));
  CallFunc* callFunc = CallFunc::create([]() { showEagleSpreadWinds(); });
  eagle->runAction(Sequence::create(delay, callFunc, nullptr));
}

void EffectMainCityView::showEagleSpreadWinds() {
  eagle->stopAllActions();
  auto Frames = BaseCreate::getAnimationFrames("juying_%02d.png", 1, 8);
  Animation* animation = Animation::createWithSpriteFrames(Frames, 0.125);
  eagle->runAction(RepeatForever::create(Animate::create(animation)));
  eagleShadow->stopAllActions();
  auto Frames2 = BaseCreate::getAnimationFrames("juying2_%02d.png", 1, 8);
  Animation* animaotion2 = Animation::createWithSpriteFrames(Frames2, 0.125);
  eagleShadow->runAction(RepeatForever::create(Animate::create(animaotion2)));
  DelayTime* delay = DelayTime::create(random(2.0f, 3.0f) + random(0.0f, 1.0f));
  CallFunc* callFunc = CallFunc::create([]() { showEagleGlide(); });
  eagle->runAction(Sequence::create(delay, callFunc, nullptr));
}

void EffectMainCityView::showEagle() {
  if (eagle == nullptr && eagleEffect == nullptr) eagleEffect = Node::create();
  eagle = Sprite::createWithSpriteFrameName("juying_01.png");
  eagle->setPosition(0, 0);
  eagleEffect->addChild(eagle, 1);
  eagleShadow = Sprite::createWithSpriteFrameName("juying2_01.png");
  auto Frames2 = BaseCreate::getAnimationFrames("juying2_%02d.png", 1, 8);
  Animation* animation2 = Animation::createWithSpriteFrames(Frames2, 0.125);
  eagleShadow->runAction(RepeatForever::create(Animate::create(animation2)));
  eagleShadow->setPosition(-70, -190);
  eagleShadow->setOpacity(102);
  eagleShadow->setScale(0.8f);
  eagleEffect->addChild(eagleShadow, 1);
  CityScene* cityScene = CityScene::getCityScene();
  if (!cityScene) return;
  cityScene->_ContainerView->addChild(eagleEffect, ECityTargetZOrder::Get()->juying);
  showEagleSpreadWinds();
  Vec2 beginPos(190, 3300);
  Vec2 endPos(3133, -50);
  float dt = beginPos.distance(endPos) / 100.0f;
  CallFunc* resetPos = CallFunc::create([beginPos]() { eagleEffect->setPosition(beginPos); });
  MoveTo* moveTo = MoveTo::create(dt, endPos);
  DelayTime* delay = DelayTime::create(3);
  Sequence* seq = Sequence::create(resetPos, moveTo, delay, nullptr);
  eagleEffect->runAction(RepeatForever::create(seq));
}

void EffectMainCityView::addBuildAnimBoostBottom(const GString& BuildingPlace) {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  Node* buildBtn = mainCity->bufferNodeArray.at(BuildingPlace);
  if (buildBtn != nullptr) return;
  Node* BuildingNode = mainCity->CityBuildingLayer->getChildByName(BuildingPlace);
  if (!BuildingNode) return;
  GString etBoostBottomName = "et_boost_bottom_" + BuildingPlace;
  Node* etBoostNode = mainCity->bufferNodeArray.at(etBoostBottomName);
  if (etBoostNode != nullptr) return;
  Node* et_node = Node::create();
  et_node->addChild(BaseCreate::createParticle("Particle/et_fanbei_display_04.plist", Vec2(), Vec2(3.5f, 1.54f), 0.0f));
  et_node->addChild(BaseCreate::createParticle("Particle/et_fanbei_display_01.plist", Vec2(3, 21), Vec2(3.12f, 2.4f), 0.0f));
  et_node->addChild(BaseCreate::createParticle("Particle/et_fanbei_display_02.plist", Vec2(1, 24), Vec2(1, 1), 20.3f));
  et_node->addChild(BaseCreate::createParticle("Particle/et_fanbei_display_03.plist", Vec2(3, 16), Vec2(1.7, 1.7), 0.0f));
  et_node->setPosition(BuildingNode->getPosition() - Vec2(0, 12));
  et_node->setLocalZOrder(BuildingNode->getLocalZOrder() + 1);
  mainCity->_ContainerView->addChild(et_node);
  mainCity->bufferNodeArray.insert(etBoostBottomName, et_node);
}

void EffectMainCityView::addHarvestEffect() {
  GVector<RCityBuildingUnit> BuildingList = BuildingLib::getBuildingResList();
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  for (RCityBuildingUnit& oneBuilding : BuildingList) {
    Node* Building = mainCity->_ContainerView->getChildByName(oneBuilding.NodeName);
    GString etBoostHarvestName = "et_boost_harvest_" + oneBuilding.NodeName;
    if (mainCity->_ContainerView->getChildByName(etBoostHarvestName)) continue;
    if (!Building) continue;
    Node* et_node = Node::create();
    et_node->addChild(BaseCreate::createParticle("Particle/et_fs_01.plist", Vec2(0, 0), Vec2(1.71f, 1.71f), 0));
    et_node->addChild(BaseCreate::createParticle("Particle/et_fs_02.plist", Vec2(0, 0), Vec2(1.71f, 1.71f), 0));
    et_node->setName(etBoostHarvestName);
    et_node->setPosition(Building->getPosition());
    mainCity->_MainCityView->_ContainerView->addChild(et_node);
  }
}

void EffectMainCityView::addPortEffect() {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  if (!mainCity->_MainCityView->_ContainerView->getChildByName("et_particle_chuang_1")) {
    auto Part_1 = BaseCreate::createParticle("Particle/et_chuang_02.plist", Vec2(3869, 1993), Vec2(1, 1), 0);
    Part_1->setName("et_particle_chuang_1");
    mainCity->_MainCityView->_ContainerView->addChild(Part_1, 1001);
  }
  if (!mainCity->_MainCityView->_ContainerView->getChildByName("et_particle_chuang_2")) {
    auto Part_2 = BaseCreate::createParticle("Particle/et_chuang_03.plist", Vec2(3883, 2030), Vec2(1, 1), 0);
    Part_2->setName("et_particle_chuang_2");
    mainCity->_MainCityView->_ContainerView->addChild(Part_2, 1001);
  }
}

void EffectMainCityView::addMatouEffect() {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  if (mainCity->_ContainerView->getChildByName("et_node_matou")) return;
  Node* et_node_matou = Node::create();
  auto Part_1 = BaseCreate::createParticle("Particle/et_lqlbjz_01.plist", Vec2(0, 0), Vec2(1, 1), 0);
  auto Part_2 = BaseCreate::createParticle("Particle/et_lqlbjz_02.plist", Vec2(0, 0), Vec2(1.165f, 1.165f), 0);
  et_node_matou->addChild(Part_1);
  et_node_matou->addChild(Part_2);
  et_node_matou->setPosition(4145, 1857);
  et_node_matou->setName("et_node_matou");
  mainCity->_ContainerView->addChild(et_node_matou, 1001);
}

void EffectMainCityView::addWallEffect() {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  GString etWallEffectName = "BG_wall_broken";
  if (mainCity->_ContainerView->getChildByName(etWallEffectName)) mainCity->_ContainerView->getChildByName(etWallEffectName)->setVisible(true);
  Sprite* spriteWallEffect = Sprite::createWithSpriteFrameName("BG_wall_broken.png");
  spriteWallEffect->setName(etWallEffectName);
  mainCity->_ContainerView->addChild(spriteWallEffect, ECityTargetZOrder::Get()->lower_wall);
  spriteWallEffect->setPosition(3424, 1051);

  // local tipBoxName = "wallTipBox"
  // local tipBoxNode = self:getBufferNodeByName(tipBoxName)
  // local isInRecoveryCD = wallsCtrl:isInRecoveryCD()
  // if isInRecoveryCD then
  //   if tipBoxNode ~= nil and tipBoxNode ~= nil then
  //     self:delBufferNodeByName(tipBoxName)
  //     tipBoxNode:removeFromParent()
  //   end
  // elseif tipBoxNode ~= nil then
  // else
  //   local cityBuildTipBox = include("cityBuildTipBox")
  //   local cityBuildTipBoxNode = cityBuildTipBox.new()
  //   local data = {
  //     boxType = cityBuildConstDef.TipBoxType.IMG,
  //     content = "icon_building_def.png",
  //     needFade = true,
  //     handler = handler(self, self.onTipBoxCall),
  //     tag = cityBuildConstDef.OtherBuildDef.Wall,
  //     imgSize = cc.size(90, 80)
  //   }
  //   cityBuildTipBoxNode:initWithData(data)
  //   cityBuildTipBoxNode:setName(tipBoxName)
  //   cityBuildTipBoxNode:setPosition(cc.p(3390, 1120))
  //   self.containerView:addChild(cityBuildTipBoxNode, mainCityDefine.CITY_TARGET_ZORDER.drill)
  //   self:addToBufferNodeArrayByName(tipBoxName, cityBuildTipBoxNode)
  // end
}

void EffectMainCityView::addTouchParticle(Vec2 TouchPos) {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  Node* TouchEtNode = mainCity->_MainCityView->_ContainerView->getChildByName("touch_et_node");
  if (TouchEtNode) {
    TouchEtNode->setPosition(TouchPos);
    return;
  }
  TouchEtNode = Node::create();
  auto Part_1 = BaseCreate::createParticle("Particle/et_dianji_button_01.plist", Vec2(0, 0), Vec2(1, 1), 0);
  auto Part_2 = BaseCreate::createParticle("Particle/et_dianji_button_02.plist", Vec2(0, 0), Vec2(1, 1), 0);
  TouchEtNode->addChild(Part_1);
  TouchEtNode->addChild(Part_2);
  TouchEtNode->setPosition(TouchPos);
  TouchEtNode->setName("touch_et_node");
  mainCity->_MainCityView->_ContainerView->addChild(TouchEtNode, 1002);
}

void EffectMainCityView::cloudRunEffect() {
  CityScene* mainCity = CityScene::getCityScene();
  if (!mainCity) return;
  static float beginY = mainCity->_MainCityView->_ContainerView->getContentSize().height + 200;
  static float endY = -200;
  static float lean = 0.44f;
  static float disX = 800;
  static float dt = cocos2d::random<float>(60.0f, 100.0f);
  static float dPosX = 0;
  int32 totalTime = 120;
  Sprite* cloud1 = Sprite::createWithSpriteFrameName("et_yunduo01_01.png");
  Sprite* cloud2 = Sprite::createWithSpriteFrameName("et_yunduo02_01.png");
  cloud1->setName("cloud1");
  cloud1->setScale(2);
  mainCity->_ContainerView->addChild(cloud1, 750);
  auto Frames = BaseCreate::getAnimationFrames("et_yunduo01_%.2d.png", 1, 10);
  Animation* animation = Animation::createWithSpriteFrames(Frames, 0.1f);
  cloud1->runAction(RepeatForever::create(Animate::create(animation)));
  CallFunc* callFunc = CallFunc::create([mainCity, cloud1]() {
    dPosX = cocos2d::random<float>(-1000, mainCity->_ContainerView->getContentSize().width - 1000);
    dt = cocos2d::random<float>(60, 100);
    cloud1->setPosition(dPosX, beginY);
  });
  Sequence* seq1 = Sequence::create(
          callFunc, MoveTo::create(dt, Vec2(cloud1->getPositionX() + abs(endY - beginY) / lean, endY)), DelayTime::create(totalTime - dt), nullptr);
  cloud1->runAction(RepeatForever::create(seq1));
  cloud2->setName("cloud2");
  cloud2->setScale(2);
  mainCity->_ContainerView->addChild(cloud2, 750);
  auto Frames2 = BaseCreate::getAnimationFrames("et_yunduo02_%.2d.png", 1, 10);
  Animation* animation2 = Animation::createWithSpriteFrames(Frames2, 0.1f);
  cloud2->runAction(RepeatForever::create(Animate::create(animation2)));
  Sequence* seq2 = Sequence::create(CallFunc::create([cloud2]() { cloud2->setPosition(dPosX - disX, beginY); }),
                                    MoveTo::create(dt, Vec2(cloud2->getPositionX() + abs(endY - beginY) / lean - disX, endY)),
                                    DelayTime::create(totalTime - dt),
                                    nullptr);
  cloud2->runAction(RepeatForever::create(seq2));
}

void EffectMainCityView::showSkillEffectBySkillID() {
  //   function effectMainCityView.showSkillEffectBySkillID(mainCity, skillID, trapType)
  //   local self = mainCity
  //   local skillTable = {
  //     [lordSkillIDDefine.trapAction] = {
  //       [1] = {
  //         plist = "et_jn_xj_01.plist",
  //         scale = {x = 1.3463, y = 0.9134}
  //       },
  //       [2] = {
  //         plist = "et_jn_xj_02.plist",
  //         scale = {x = 1.05, y = 1.05}
  //       }
  //     },
  //     [lordSkillIDDefine.harvest] = {
  //       [1] = {
  //         plist = "et_fs_01.plist"
  //       },
  //       [2] = {
  //         plist = "et_fs_02.plist",
  //         pos = {x = -2, y = -1.4}
  //       }
  //     }
  //   }
  //   local resourceAnimation = {
  //     [BUILDID.FARM] = {
  //       pattern = "et_fs_dc_%.2d.png",
  //       beginp = 1,
  //       endp = 8,
  //       sprite = "#et_fs_dc_01.png"
  //     },
  //     [BUILDID.SAWMILL] = {
  //       pattern = "et_fs_mc_%.2d.png",
  //       beginp = 1,
  //       endp = 8,
  //       sprite = "#et_fs_mc_01.png"
  //     },
  //     [BUILDID.IRON_MINE] = {
  //       pattern = "et_fs_tk_%.2d.png",
  //       beginp = 1,
  //       endp = 8,
  //       sprite = "#et_fs_tk_01.png"
  //     },
  //     [BUILDID.STEEL] = {
  //       pattern = "et_fs_my_%.2d.png",
  //       beginp = 1,
  //       endp = 8,
  //       sprite = "#et_fs_my_01.png"
  //     },
  //     [BUILDID.CRYSTAL_MINE] = {
  //       pattern = "et_fs_sj_%.2d.png",
  //       beginp = 1,
  //       endp = 8,
  //       sprite = "#et_fs_sj_01.png"
  //     }
  //   }
  //   if skillID == lordSkillIDDefine.trapAction and skillTable[lordSkillIDDefine.trapAction] then
  //     local buildIndex = self:getBuildIndexByBid(BUILDID.FORTRESS)
  //     if buildIndex then
  //       do
  //         local place = self:getBuildBtnByIndex(buildIndex)
  //         if place then
  //           SoraDSendMessage({
  //             msg = "MESSAGE_MAINCITYVIEW_GO_TO_BUILD",
  //             buildID = BUILDID.FORTRESS,
  //             delay = 0,
  //             needRecover = true
  //           })
  //           do
  //             local armyDesRead = include("armyDesRead")
  //             local seq = transition.sequence({
  //               cca.delay(0.5),
  //               cca.callFunc(function()
  //                 local parNode = SoraDCreateEffectNode(skillTable[lordSkillIDDefine.trapAction])
  //                 parNode:setPosition(cc.p(place:getContentSize().width / 2, place:getContentSize().height / 2))
  //                 parNode:addTo(place, 5)
  //               end),
  //               cca.delay(0.5),
  //               cca.callFunc(function()
  //                 local trapSprite = display.newSprite(armyDesRead.getIcon(trapType, true))
  //                 trapSprite:setAnchorPoint(cc.p(0.5, 0))
  //                 trapSprite:setName("trapSprite")
  //                 trapSprite:setPosition(cc.p(place:getContentSize().width / 2, place:getContentSize().height + 100))
  //                 trapSprite:addTo(place, 5)
  //                 trapSprite:runAction(cca.moveTo(0.3, cc.p(place:getContentSize().width / 2, 0)))
  //               end),
  //               cca.delay(0.3),
  //               cca.callFunc(function()
  //                 SoraDShowMsgTip(i18n("notice_0114"))
  //                 place:removeChildByName("trapSprite", true)
  //               end)
  //             })
  //             place:runAction(seq)
  //           end
  //         else
  //         end
  //       end
  //     end
  //   elseif skillID == lordSkillIDDefine.harvest and skillTable[lordSkillIDDefine.harvest] then
  //     local resourcePlaces = self:getAllResBuildBtn()
  //     if #resourcePlaces > 0 then
  //       self:gotoOuterCity(true)
  //       for i, v in ipairs(resourcePlaces) do
  //         do
  //           local rType = v[1]
  //           local place = v[2]
  //           local entity = v[3]
  //           if entity:getIsLocked() then
  //           else
  //             local seq = transition.sequence({
  //               cca.delay(1.5),
  //               cca.callFunc(function()
  //                 local parNode = SoraDCreateEffectNode(skillTable[lordSkillIDDefine.harvest])
  //                 parNode:setPosition(cc.p(place:getContentSize().width / 2, place:getContentSize().height / 2))
  //                 parNode:addTo(place, 5)
  //               end),
  //               cca.delay(0.2),
  //               cca.callFunc(function()
  //                 local sprite = display.newSprite(resourceAnimation[rType].sprite)
  //                 sprite:setName("getResourceAnimation")
  //                 sprite:setPosition(cc.p(place:getContentSize().width / 2, place:getContentSize().height))
  //                 sprite:addTo(place, 5)
  //                 local frames = display.newFrames(resourceAnimation[rType].pattern, resourceAnimation[rType].beginp,
  //                 resourceAnimation[rType].endp) local animation = display.newAnimation(frames, 0.125) sprite:playAnimationOnce(animation)
  //               end),
  //               cca.callFunc(function()
  //                 local output = buildLogic.getResOutputHour(rType, entity:getBuildLv(), entity:getIid())
  //                 local totalOutput = output.total or 0
  //                 local floatingLabel = display.newTTFLabel({
  //                   text = "+" .. totalOutput,
  //                   color = display.COLOR_GREEN,
  //                   size = 26
  //                 })
  //                 floatingLabel:addTo(self.containerView, 500)
  //                 floatingLabel:setPosition(cc.p(place:getPositionX(), place:getPositionY()))
  //                 local moveBy = cca.moveBy(0.5, 0, 80)
  //                 local delay = cca.delay(0.5)
  //                 local callFunc = cca.callFunc(function()
  //                   floatingLabel:removeFromParent()
  //                 end)
  //                 local seq = cca.seq({
  //                   moveBy,
  //                   delay,
  //                   callFunc
  //                 })
  //                 floatingLabel:runAction(seq)
  //               end),
  //               cca.delay(1),
  //               cca.callFunc(function()
  //                 SoraDShowMsgTip(i18n("notice_0113"))
  //                 place:removeChildByName("getResourceAnimation", true)
  //               end)
  //             })
  //             place:runAction(seq)
  //           end
  //         end
  //       end
  //     end
  //   elseif skillID == lordSkillIDDefine.rescue or skillID == lordSkillIDDefine.collectprotect or skillID == lordSkillIDDefine.fastmarch then
  //     local panel = SoraDCreatePanel("commonUseSkill")
  //     panel:initData(skillID)
  //     panel:show()
  //   end
  // end
}

void EffectMainCityView::showWaterfallCastle() {}

void EffectMainCityView::UpdateCommunityView(MainCityView *p_MainCity, int32 p_CastleLvl){
  // local self = mainCity
  // local castleLv = 1
  // local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  // castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
  // if castleBcell then
  //   castleLv = tonumber(castleBcell.info.lv)
  // end
  // if data and data.castleLv then
  //   castleLv = data.castleLv
  // end
  // SoraDSendMessage({
  //   msg = "MESSAGE_MAINCITYVIEW_UPDATE_SERVICECENTER"
  // })
  // if castleLv >= CASTLE_LV25_LIMITED then
  //   local btn_30005 = self:getBufferNodeByName("build_30005")
  //   if nil ~= btn_30005 then
  //     btn_30005:setPosition(cc.p(2640.93, 1559.21))
  //     if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //       btn_30005:setPosition(cc.p(2432.76, 1347.36))
  //     end
  //   end
  //   local img_bg_miracle = self:getBufferNodeByName("BG_miracle")
  //   if img_bg_miracle then
  //     img_bg_miracle:setVisible(IsArClient)
  //   end
  //   local btn_1200 = self:getBufferNodeByName("build_1200")
  //   if nil ~= btn_1200 then
  //     btn_1200:setVisible(true)
  //   end
  // else
  //   local btn_30005 = self:getBufferNodeByName("build_30005")
  //   if nil ~= btn_30005 then
  //     btn_30005:setPosition(cc.p(2946.4, 1610.56))
  //     if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //       btn_30005:setPosition(cc.p(2776.4, 1373.56))
  //     end
  //   end
  //   local img_bg_miracle = self:getBufferNodeByName("BG_miracle")
  //   if img_bg_miracle then
  //     img_bg_miracle:setVisible(false)
  //   end
  //   local btn_1200 = self:getBufferNodeByName("build_1200")
  //   if nil ~= btn_1200 then
  //     btn_1200:setVisible(false)
  //   end
  // end
  // local buttonCommunityCenter = self:getBufferNodeByName("build_30005")
  // if not buttonCommunityCenter then
  //   return
  // end
  // local btnCommunityPos = cc.p(buttonCommunityCenter:getPosition())
  // if self.tipBoxCommunity ~= nil then
  //   local deltaOffsetY = castleLv >= CASTLE_LV25_LIMITED and 73 or 83
  //   local deltaOffsetX = castleLv >= CASTLE_LV25_LIMITED and 43 or 0
  //   self.tipBoxCommunity:setPosition(cc.p(btnCommunityPos.x + deltaOffsetX, btnCommunityPos.y + deltaOffsetY))
  // end
  // if self.tipTopCommunity ~= nil then
  //   local deltaOffsetY = castleLv >= CASTLE_LV25_LIMITED and 76 or 76
  //   local deltaOffsetX = castleLv >= CASTLE_LV25_LIMITED and 43 or 0
  //   local buildTopTipPosition = cc.p(btnCommunityPos.x + deltaOffsetX, btnCommunityPos.y + deltaOffsetY)
  //   self.tipTopCommunity:setPosition(buildTopTipPosition)
  //   self.tipTopCommunity:setBasePos(buildTopTipPosition)
  //   self.tipTopCommunity:udpateViewWithBasePos()
  // end
}


void EffectMainCityView::UpdateStarBraveStatueView(MainCityView *p_MainCity, int32 p_CastleLvl){
  //   local self = mainCity
  // local castleLv = 1
  // local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  // castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
  // if castleBcell then
  //   castleLv = tonumber(castleBcell.info.starLv)
  // end
  // dump(castleBcell.info, "effectMainCityView.updateStarBraveStatueView")
  // if data and data.castleLv then
  //   castleLv = data.castleLv
  // end
  // if SoraDIsBraveOpen() then
  //   local dh_yzdxyz = self:getBufferNodeByName("dh_yzdxyz")
  //   if dh_yzdxyz then
  //     dh_yzdxyz:setVisible(true)
  //   end
  //   local btn_1205 = self:getBufferNodeByName("build_1205")
  //   if btn_1205 then
  //     btn_1205:setVisible(true)
  //   end
  // else
  //   local dh_yzdxyz = self:getBufferNodeByName("dh_yzdxyz")
  //   if dh_yzdxyz then
  //     dh_yzdxyz:setVisible(false)
  //   end
  //   local btn_1205 = self:getBufferNodeByName("build_1205")
  //   if btn_1205 then
  //     btn_1205:setVisible(false)
  //   end
  // end
}