#include "IBuilding.h"
#include "Scene/CityScene.h"
#include "Building.Event.h"
USING_NS_CC;

bool IBuilding::init() {
  if (!Node::init()) return false;
  InitStateMachine();
  // setAnchorPoint(Vec2(0, 0));
  return true;
}

void IBuilding::Clicked(Touch* p_Touch, Event* p_Event) {}

void IBuilding::InitTouchEvents() {}
void IBuilding::CancelTint() {}
void IBuilding::RemoveBuildingTip() {}

bool IBuilding::IgnoreClickEvent(Touch* p_Touch, Event* p_Event) const {
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

void IBuilding::InitEvents() {
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
    if(GetState() == EBuildingState::Training && IsCanHarvest() && HarvestAll())
      return;
    if(GetState() == EBuildingState::TrapBuilding && IsCanHarvest() && HarvestAll())
      return;
    if(GetState() == EBuildingState::Studying && IsCanSpeedUpResearchFree() && SpeedUpResearchFree())
      return;
    if(IsNeedRequestHelp() && RequestHelp())
      return;
    if(GetState() == EBuildingState::None && HasAnyAllianceHelpList() && AllianceHelpAll())
      return;
    Clicked(p_Touch, p_E);
  };
  _eventDispatcher->addEventListenerWithSceneGraphPriority(l_MouseListiner, this);
}

void IBuilding::onEnter() { 
  Node::onEnter();
  EndTimer();
  UpdateLvl();
  UpdateStarLvl();
  StartTimer();
  UpdateTimer();
  m_HarvestState = EHarvestState::None;
  if(IsOpen()){
    ShowAnimBuildWorker();
    ShowBuildLock();
  }
  ShowBuildLvl();
  OnAfterInitWithBuildCell();
}

void IBuilding::OnMessageListener(){
  _eventDispatcher->addCustomEventListener("MESSAGE_MAINCITYVIEW_CITYBUFF_DISAPPEAR",
    std::bind(&IBuilding::SMsgRemoveBuff, this, std::placeholders::_1));

  _eventDispatcher->addCustomEventListener("MESSAGE_SERVER_UPDATE_BUILD_CAN_UPGRADE", 
    [this](EventCustom *p_Event){SMsgUpdateBuildCanUpgrade(p_Event);});
    
  _eventDispatcher->addCustomEventListener("MESSAGE_MAINCITYVIEW_TRAIN_ARMY_IMMDIATELY_BACK", 
    std::bind(&IBuilding::SMsgTrainArmyImmediatelyBack, this, std::placeholders::_1));

  _eventDispatcher->addCustomEventListener("MESSAGE_MAINCITYVIEW_BUILD_TRAIN_FAILED", 
    std::bind(&IBuilding::SMsgBuildTrainFailed, this, std::placeholders::_1));

  _eventDispatcher->addCustomEventListener("MESSAGE_MAINCITYVIEW_BUILDSTAR_QUEQUE_CALLBACK", 
    std::bind(static_cast<void(IBuilding::*)(EventCustom *)>(&IBuilding::UpdateStarLvl), this, std::placeholders::_1));

  _eventDispatcher->addCustomEventListener("MESSAGE_BUILD_STAR_UPGRADE", 
    std::bind(static_cast<void(IBuilding::*)(EventCustom *)>(&IBuilding::UpdateStarLvl), this, std::placeholders::_1));
};

void IBuilding::SMsgRemoveBuff(EventCustom *p_Event){

}

void IBuilding::SMsgUpdateBuildCanUpgrade(EventCustom *p_Event){
  bool l_NeedUpdate = true;
  if(m_UdpateIsCanUpGradeTime > 0 && GDateTime::Now() - m_UdpateIsCanUpGradeTime <= 1){
    l_NeedUpdate = false;
    auto l_Sequence = Sequence::create(
      DelayTime::create(0.5),
      CallFunc::create([this](){
        UpdateIsCanUpgrade();
        UpdateStarLvl();
      }),
      nullptr
    );
  }
  if(l_NeedUpdate){
    UpdateIsCanUpgrade();
    UpdateStarLvl();
  }
  m_UdpateIsCanUpGradeTime = GDateTime::Now();
}

void IBuilding::SMsgTrainArmyImmediatelyBack(EventCustom *p_Event){}
void IBuilding::SMsgBuildTrainFailed(EventCustom *p_Event){}
void IBuilding::UpdateStarLvl(EventCustom *p_Event){}


void IBuilding::ShowTopTip(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg =  std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP", l_ABuildingMsg.get());
}

void IBuilding::HideTopTip(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg =  std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP", l_ABuildingMsg.get());  
}

void IBuilding::ShowWorkDone(){
  // local bid = tonumber(self:getBuildBid())
  //if bid == BUILDID.MATERIAL_WORKSHOP then
  //   self:hideAnimWorking()
  //   self:showTopTipEffect()
  //   self:showBrightParticle()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP",
  //     buildIndex = self.buildIndex
  //   })
  // elseif bid == BUILDID.FARM or bid == BUILDID.SAWMILL or bid == BUILDID.IRON_MINE or bid == BUILDID.STEEL or bid == BUILDID.CRYSTAL_MINE then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP",
  //     buildIndex = self.buildIndex
  //   })
  //   self:showTopTipEffect()
  // elseif bid == BUILDID.STAR_BRAVE_STATUE then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP",
  //     buildIndex = self.buildIndex
  //   })
  // end
}

void IBuilding::setBuildingSprite() {
  BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
  BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
  BuildingSprite->setName("buildImg");
  addChild(BuildingSprite);
}

void IBuilding::setUpgradeSprite() {
  UpgradeSprite = Sprite::createWithSpriteFrameName("icon_main_build_lv.png");
  UpgradeSprite->setPosition(LvlBgOffset.x - 46, LvlBgOffset.y - 22);
  UpgradeSprite->setLocalZOrder(5);
  addChild(UpgradeSprite);
}

void IBuilding::setBuildingLvBg() {
  BuildingLvBg = Sprite::createWithSpriteFrameName("icon_main_build_upgrade.png");
  BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
  BuildingLvBg->setLocalZOrder(5);
  addChild(BuildingLvBg);
}

void IBuilding::setBuildingLvlText() {
  BuildingLvText = Label::createWithSystemFont("8", "Arial", 18);
  BuildingLvText->setSkewY(25);
  BuildingLvText->setAnchorPoint(Vec2(0.5, 0.5));
  BuildingLvText->setColor(Color3B(235, 255, 20));
  BuildingLvText->setPosition(LvlBgOffset.x - 20, LvlBgOffset.y - 1);
  BuildingLvText->setLocalZOrder(6);
  BuildingLvText->setAlignment(TextHAlignment::CENTER);
  addChild(BuildingLvText);
}

void IBuilding::setBuildingSleepSprite() {
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

void IBuilding::setBuildingIconMiracle() {
  auto SleepSprite2 = Sprite::createWithSpriteFrameName(BuildingIconMiracle);
  SleepSprite2->setPosition(80, 18);
  SleepSprite2->setLocalZOrder(3);
  addChild(SleepSprite2);
}

Vector<SpriteFrame*> IBuilding::getAnimation(GString Frame, int32 start, int32 end) {
  auto spritecache = SpriteFrameCache::getInstance();
  Vector<SpriteFrame*> animFrames;
  char str[100];
  for (int i = start; i <= end; i++) {
    sprintf(str, Frame.c_str(), i);
    animFrames.pushBack(spritecache->getSpriteFrameByName(str));
  }
  return animFrames;
}

void IBuilding::setBuildingParticle() {}

void IBuilding::setBuildingAnimation() {}

void IBuilding::setBuildingUnitData(RCityBuildingUnit& _CBUD) { BuildingUnitData = _CBUD; }

void IBuilding::setBuildingBtn() {}