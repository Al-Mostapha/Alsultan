#include "CityBuildingBase.h"
#include "Scene/CityScene.h"
USING_NS_CC;

bool CityBuildingBase::init() {
  if (!Node::init()) return false;

  // setAnchorPoint(Vec2(0, 0));
  return true;
}

void CityBuildingBase::Clicked(Touch* p_Touch, Event* p_Event) {}

void CityBuildingBase::InitTouchEvents() {}
void CityBuildingBase::CancelTint() {}
void CityBuildingBase::RemoveBuildingTip() {}

bool CityBuildingBase::IgnoreClickEvent(Touch* p_Touch, Event* p_Event) const {
  auto l_TPoint = p_Touch->getLocation();
  if(!CityScene::Get()){
    Logger::Log("Current Scene is not CityScene", ELogLvl::Error, true);
    CCASSERT(CityScene::Get(), "Current Scene is not CityScene");
    return false;
  }

  if(m_BuildingIndex == EBuildingIndex::WallGate){
    auto l_BuildingLayer = CityScene::Get()->CityBuildingLayer;
    auto l_TipBoxWall    = CityScene::Get()->GetNode<Node *>("wallTipBox");
    auto l_JiantaBaseL   = CityScene::Get()->GetNode<Node *>("Button_Jiantachengduo_L");
    auto l_JiantaBaseR   = CityScene::Get()->GetNode<Node *>("Button_Jiantachengduo_R");
    auto l_ArrowTowerR   = CityScene::Get()->GetNode<Node *>("build_1052");
    auto l_ArrowTowerL   = CityScene::Get()->GetNode<Node *>("build_1054");
    auto l_BehindArrowTower = CityScene::Get()->GetNode<Node *>("build_1066");
    
    auto l_JiantaBaseLBtn = GBase::getChildByName<Node *>(l_JiantaBaseL, "buildBtn");
    auto l_JiantaBaseRBtn = GBase::getChildByName<Node *>(l_JiantaBaseR, "buildBtn");
    auto l_TipBoxGuardSoldier = CityScene::Get()->TipBoxGuardSoldier;
    GVector<Node *> l_BlockingNode = {
      l_BuildingLayer, l_TipBoxWall, l_JiantaBaseL, l_JiantaBaseR, 
      l_ArrowTowerL, l_ArrowTowerR, l_TipBoxGuardSoldier, l_JiantaBaseLBtn,
      l_JiantaBaseRBtn , l_BehindArrowTower
    };
    for(auto l_OneNode : l_BlockingNode){
      if(!l_OneNode)
        continue;
      if(!l_OneNode->isVisible())
        continue;
      if(GBase::IsTouchOnNode(p_Touch->getLocation(), l_OneNode))
        return true;
    }
  }
  
  if(m_BuildingIndex == EBuildingIndex::BehindArrowTowerR){
    CCASSERT(CityScene::Get()->ButtonMerchante, "Current Scene is not CityScene");
    if(!CityScene::Get()->ButtonMerchante)
      return false;
    if(!CityScene::Get()->ButtonMerchante->isVisible())
      return false;
    if(GBase::IsTouchOnNode(l_TPoint, CityScene::Get()->ButtonMerchante))
      return true;
  }
  
  if(CityScene::Get()->IsMoving())
    return true;
    
  return false;
}

void CityBuildingBase::InitEvents() {
  auto l_MouseListiner = EventListenerTouchOneByOne::create();
  l_MouseListiner->setSwallowTouches(true);

  l_MouseListiner->onTouchBegan = [=](Touch* touch, Event* event) -> bool {
    m_TouchIsMoveOnBuild = false;
    return true; 
  };

  l_MouseListiner->onTouchMoved = [=](Touch* p_T, Event* p_E) {

    auto l_BegainPoint = p_T->getPreviousLocation();
    auto l_MovePoint   = p_T->getLocation();
    auto l_Distance    =  l_BegainPoint.getDistance(l_MovePoint);
    if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
      m_TouchIsMoveOnBuild = true;
  };

  l_MouseListiner->onTouchCancelled = [this](Touch* p_T, Event* p_E){
    m_TouchIsMoveOnBuild = false;
  };

  l_MouseListiner->onTouchEnded = [=](Touch* p_Touch, Event* p_E) {
    cocos2d::log("Test is Here");
    if(m_CurrentSelectTip)
      RemoveBuildingTip();
    CancelTint();
    if(m_TouchIsMoveOnBuild)
      return;
    if(!m_IsBuildBtnEnabled)
      return;
    GBase::PlaySound("normalcontrol");
    if(IgnoreClickEvent(p_Touch, p_E))
      return;
    if(IsCanSpeedUpStrongFree() && SpeedUpStrongFree())
      return;
    if(GetState() == EBuildingState::Building && IsCanSpeedUpFree() && SpeedUpFree())
      return;
    if(GetState() == EBuildingState::Demolishing && IsCanSpeedUpFree() && SpeedUpFree())
      return;
    if(GetState() == EBuildingState::Harvesting && HarvestAll())
      return;
    if(GetState() == EBuildingState::Working && IsCanHarvest() && HarvestAll())
      return;
    if(GetState() == EBuildingState::Working && IsCanSpeedUpResearchFree() && SpeedUpResearchFree())
      return;
    if(IsNeedRequestHelp() && RequestHelp())
      return;
    if(GetState() == EBuildingState::Idle && HasAnyAllianceHelpList() && AllianceHelpAll())
      return;
    Clicked(p_Touch, p_E);
  };
  _eventDispatcher->addEventListenerWithSceneGraphPriority(l_MouseListiner, this);
}

void CityBuildingBase::onEnter() { Node::onEnter(); }

void CityBuildingBase::setBuildingSprite() {
  BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
  BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
  BuildingSprite->setName("buildImg");
  addChild(BuildingSprite);
}

void CityBuildingBase::setUpgradeSprite() {
  UpgradeSprite = Sprite::createWithSpriteFrameName("icon_main_build_lv.png");
  UpgradeSprite->setPosition(LvlBgOffset.x - 46, LvlBgOffset.y - 22);
  UpgradeSprite->setLocalZOrder(5);
  addChild(UpgradeSprite);
}

void CityBuildingBase::setBuildingLvBg() {
  BuildingLvBg = Sprite::createWithSpriteFrameName("icon_main_build_upgrade.png");
  BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
  BuildingLvBg->setLocalZOrder(5);
  addChild(BuildingLvBg);
}

void CityBuildingBase::setBuildingLvlText() {
  BuildingLvText = Label::createWithSystemFont("8", "Arial", 18);
  BuildingLvText->setSkewY(25);
  BuildingLvText->setAnchorPoint(Vec2(0.5, 0.5));
  BuildingLvText->setColor(Color3B(235, 255, 20));
  BuildingLvText->setPosition(LvlBgOffset.x - 20, LvlBgOffset.y - 1);
  BuildingLvText->setLocalZOrder(6);
  BuildingLvText->setAlignment(TextHAlignment::CENTER);
  addChild(BuildingLvText);
}

void CityBuildingBase::setBuildingSleepSprite() {
  int32 offsetX = 50;
  int32 offsetY = 40;
  int32 oriX = 44;
  int32 oriY = 97;

  auto actionMoveTo = MoveTo::create(0, Vec2(oriX, oriY));
  auto actionFadeTo = FadeTo::create(0, 1);
  auto actionRotateTo = RotateTo::create(0, 0);
  auto actionMoveBy = MoveBy::create(1.6, Vec2(offsetX, offsetY));
  auto actionFadeTo2 = FadeTo::create(1.6, 0.5);
  auto actionRotateBy = RotateBy::create(1.6, 30);

  Spawn* actionSpawn = Spawn::create(actionMoveBy, actionFadeTo2, actionRotateBy, NULL);
  Sequence* sequenceAction = Sequence::create(actionMoveTo, actionFadeTo, actionRotateTo, actionSpawn, NULL);

  DelayTime* actionDelay1 = DelayTime::create(0.2);

  Sequence* actionSeq2 =
          Sequence::create(MoveTo::create(0, Vec2(oriX, oriY)),
                           FadeTo::create(0, 1),
                           RotateTo::create(0, 0),
                           Spawn::create(MoveBy::create(1.6, Vec2(offsetX, offsetY)), FadeTo::create(1.6, 0.5), RotateBy::create(1.6, -30), NULL),
                           NULL);

  DelayTime* actionDelay2 = DelayTime::create(0.2);

  Sequence* actionSeq3 =
          Sequence::create(MoveTo::create(0, Vec2(oriX, oriY)),
                           FadeTo::create(0, 1),
                           RotateTo::create(0, 0),
                           Spawn::create(MoveBy::create(1.6, Vec2(offsetX, offsetY)), FadeTo::create(1.6, 0), RotateBy::create(1.6, 30), NULL),
                           NULL);

  DelayTime* actionDelay3 = DelayTime::create(3.8);

  Sequence* actionSeq4 = Sequence::create(actionDelay1, actionSeq2, actionDelay2, actionSeq3, actionDelay3, NULL);

  RepeatForever* actionRepeat = RepeatForever::create(actionSeq4);

  auto SleepSprite = Sprite::createWithSpriteFrameName("z.png");
  SleepSprite->setPosition(oriX, oriY);
  SleepSprite->setLocalZOrder(5);
  addChild(SleepSprite);
  SleepSprite->runAction(actionRepeat);
}

void CityBuildingBase::setBuildingIconMiracle() {
  auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
  SleepSprite2->setPosition(80, 18);
  SleepSprite2->setLocalZOrder(3);
  addChild(SleepSprite2);
}

Vector<SpriteFrame*> CityBuildingBase::getAnimation(GString Frame, int32 start, int32 end) {
  auto spritecache = SpriteFrameCache::getInstance();
  Vector<SpriteFrame*> animFrames;
  char str[100];
  for (int i = start; i <= end; i++) {
    sprintf(str, Frame.c_str(), i);
    animFrames.pushBack(spritecache->getSpriteFrameByName(str));
  }
  return animFrames;
}

void CityBuildingBase::setBuildingParticle() {}

void CityBuildingBase::setBuildingAnimation() {}

void CityBuildingBase::setBuildingUnitData(RCityBuildingUnit& _CBUD) { BuildingUnitData = _CBUD; }

void CityBuildingBase::setBuildingBtn() {}