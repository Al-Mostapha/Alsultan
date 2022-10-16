#include "IBuilding.h"
#include "Scene/CityScene.h"
#include "Building.Event.h"
#include "Module/Building/Building.Logic.h"
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
  if(IsOpening()){
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


void IBuilding::ShowTopTip(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg =  std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP", l_ABuildingMsg.get());
}

void IBuilding::HideTopTip(){
  auto l_ABuildingMsg =  std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP", l_ABuildingMsg.get());  
}

void IBuilding::ShowWorkDone(){}

void IBuilding::HideWorkDone(){
  auto l_ABuildingMsg =  std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode  = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_WORK_DONE_EFFECT", l_ABuildingMsg.get());
  HideTopTip(); 
}

void IBuilding::ShowBuildLvl(){
  if(IsLocked())
    return;
  if(IsOpening())
    return;
  if(this->n_BuildingLvText)
    this->n_BuildingLvText->setVisible(true);
  if(this->n_BuildingLvBg)
    this->n_BuildingLvBg->setVisible(true);
}

void IBuilding::UpdateLvl(){
  auto l_BuildingLvl = GetBuildingLvl();
  auto l_StarLvl     = GetStarLvl();
  bool l_IsWarLvl    = BuildingLogic::Get()->IsWarLvl(l_BuildingLvl);
  auto l_WarLvlText = GBase::DGetBuildWarLv(l_BuildingLvl);
  UpdateTextLvl();
  UpdateIsCanUpgrade();
  if(l_IsWarLvl <= 0 && n_BuildingLvBg){
    n_BuildingLvBg->setSpriteFrame("con_main_build_lv.png");
    m_IsSHowWarLv = false;
  }
  if(l_IsWarLvl > 0 && n_BuildingLvBg){
    n_BuildingLvBg->setSpriteFrame("icon_main_build_warlv.png");
    m_IsSHowWarLv = false;
  }
  UpdateViewModel();
  UpdateLvlPos();
}

void IBuilding::UpdateStarLvl(EventCustom *p_Event){
  auto l_ABuildingMsg = static_cast<ABuildingMsg *>(p_Event->getUserData());
  auto l_BuildingCell = GetBuildingCell();
  auto l_StarLvl = GetStarLvl();

  if(!l_ABuildingMsg)
    return;
  if(l_ABuildingMsg->BuildingIndex != m_BuildingIndex)
    return;
  if(!l_BuildingCell) 
    return;
  if(l_StarLvl > 0)
    UpdateStarLvlBgLight();
  UpdateIsCanUpgrade();
  UpdateStarLvlPos();
  RefreshBuildStarState(nullptr);
}

void IBuilding::RefreshBuildStarState(void *p_Temp){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  _eventDispatcher->dispatchCustomEvent(
    "MESSAGE_MAINCITYVIEW_UPDATE_BUILDSTAR_COOLING_PANEL",
    l_ABuildingMsg.get()
  );
}

void IBuilding::InitStateMachine(){
  
}

void IBuilding::UpdateStarLvlBgLight(){
  auto l_StarLvl = GetStarLvl();
  if(!n_BuildingLvBg)
    return;
  n_BuildingLvBg->setSpriteFrame("icon_main_buildstar_lv.png");
  UpdateTextLvl();
  if(!n_SpStarLight){
    n_SpStarLight = Sprite::create();
    n_BuildingLvBg->addChild(n_SpStarLight);
    n_SpStarLight->setPosition(83, 35);
  }
  auto l_IconName = CityCtrl::Get()->GetBuildStarLight(l_StarLvl);
  n_SpStarLight->setSpriteFrame(l_IconName);
  if(!n_BuildStarLight){
    auto l_Action = GBase::CreateAnimation(CsbUiFilePath::NodeBuildStarLight.c_str(), n_BuildStarLight);
    n_BuildingLvBg->addChild(n_BuildStarLight);
    n_BuildingLvBg->setPosition(83, 35);
    for(auto l_OneNode : n_BuildingLvBg->getChildren()){
      l_OneNode->setPosition(0, 0);
    }
  }
  auto l_Lvl = CityCtrl::Get()->GetBuildStarColor(l_StarLvl);
  auto l_NodeName = StringUtils::format("Node_%d", l_Lvl);
  for(auto l_OneNode : n_BuildingLvBg->getChildren()){
    l_OneNode->setVisible(l_OneNode->getName() == l_NodeName);
  }
}

//TODO: This functio may Has Bug
void IBuilding::ChangeState(){
  std::unique_ptr<IState::Event> l_StateEvent = std::make_unique<IState::Event>(this);
  if(GetState() == EBuildingState::Idle && m_States.Contains(EBuildingState::Idle)) // Idle Is reset
    m_States[EBuildingState::Idle]->Enter(l_StateEvent.get());
  else if(GetState() == EBuildingState::Lock && m_States.Contains(EBuildingState::Lock))
    m_States[EBuildingState::Lock]->Enter(l_StateEvent.get());
  else if(GetState() == EBuildingState::Building && m_States.Contains(EBuildingState::Building))
    m_States[EBuildingState::Building]->Enter(l_StateEvent.get());
  else if(GetState() == EBuildingState::Working && m_States.Contains(EBuildingState::Working))
    m_States[EBuildingState::Working]->Enter(l_StateEvent.get());
  else if(GetState() == EBuildingState::Demolishing && m_States.Contains(EBuildingState::Demolishing))
    m_States[EBuildingState::Demolishing]->Enter(l_StateEvent.get());
  else if(GetState() == EBuildingState::Harvesting && m_States.Contains(EBuildingState::Harvesting))
    m_States[EBuildingState::Harvesting]->Enter(l_StateEvent.get());
}

void IBuilding::ShowGlow(){
  auto l_BuildingLvl = GetBuildingLvl();
  auto l_WarLvl = BuildingLogic::Get()->IsWarLvl(l_BuildingLvl);
  if(l_WarLvl > GBase::Const::Get()->CastleMinWarLvl){
    if(!n_BuildGlowWar){
      //TODO: This Node Should Be Spacified for each Building
    }
  }
}

void IBuilding::HideGlow(){
  if(!n_BuildGlowWar)
    return;
  n_BuildGlowWar->stopAllActions();
  n_BuildGlowWar->removeFromParent();
  n_BuildGlowWar = nullptr;
}

void IBuilding::ShowCoolingPanel(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent(
    "MESSAGE_MAINCITYVIEW_ADD_BUILD_COOLING_PANEL",
    l_ABuildingMsg.get()
  );
}

void IBuilding::HideCoolingPanel(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent(
    "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_COOLING_PANEL",
    l_ABuildingMsg.get()
  );
}
//TODO: ADD SHOW AND HIDE BUILDING Glow
void IBuilding::ShowAnimWorking(bool p_ShowGlow){
  
  HideZAnimation();
  if(p_ShowGlow)
    ShowGlow();
  else 
    HideGlow();
  ShowWorkingEffect();
}

void IBuilding::HideAnimWorking(){
  HideGlow();
  HideWorkingEffect();
  HideNormalParticle();
}

void IBuilding::ShowAnimBoost(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent(
    "MESSAGE_MAINCITYVIEW_ADD_BUILD_ANIM_BOOST",
    l_ABuildingMsg.get()
  );
}

void IBuilding::HideAnimBoost(){
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg = std::make_unique<ABuildingMsg>();
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent(
    "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_ANIM_BOOST",
    l_ABuildingMsg.get()
  );
}

void IBuilding::UpdateIsCanUpgradeStar(){
  /*local bid = self:getBuildBid()
  local iid = self:getIid()
  if bid == 0 then
    return
  end
  if bid ~= BUILDID.CASTLE and guideCtrl:isGuideNotCompleted(gGuideModule.CITY_STAR_LV) then
    return
  end
  local isUnlock = buildLogic.isBuildingStarUnlock(bid, iid)
  if not isUnlock then
    self:setIsCanUpgradeStar(false)
    return
  end
  local reduce = buildLogic.getUpgradeStarCostReducePercent()
  local ret, data = buildLogic.isCanUpgradeStar(bid, iid, {isQuick = true, totalReduceRate = reduce})
  if not ret then
    self:setIsCanUpgradeStar(false)
    return
  end
  local err = buildLogic.checkUpgradeStarCond(OPERATE_MODE.NORMAL, data)
  if err == gErrDef.Err_None then
    self:setIsCanUpgradeStar(true)
  else
    self:setIsCanUpgradeStar(false)
  end*/
  SetIsCanUpgradeStar(true);
}

void IBuilding::HideBuildLvl(){}

void IBuilding::UpdateTextLvl(){
  auto l_BuildingLvl = GetBuildingLvl();
  if(GetState() == EBuildingState::Building && l_BuildingLvl == 1){
    SetTextLvl(std::to_string(0));
    return;
  }
  auto l_StarLvl = GetStarLvl();
  auto l_Textvl = GBase::DGetBuildWarLv(l_BuildingLvl);
  if(l_StarLvl > 0){
    SetTextLvl(StringUtils::format("%d-%d", l_Textvl.First, std::to_string(l_StarLvl)));
  }else{
    SetTextLvl(l_Textvl.First);
  }
}


void IBuilding::UpdateIsCanUpgrade(){
  if(IsOpening())
    return;
  auto l_IsCanUpgrade = BuildingLogic::Get()->IsShowUpgrade(m_BuildingIndex);
  SetIsCanUpgrade(l_IsCanUpgrade);
}

void IBuilding::SetIsCanUpgrade(bool p_IsCan){
  m_IsCanUpgrade = p_IsCan;
  if(m_IsCanUpgradeStar)
    return;
  if(!n_UpgradeSprite)
    return;
  if(m_IsCanUpgrade)
    n_UpgradeSprite->setVisible(true);
  else 
    n_UpgradeSprite->setVisible(false);
};

void IBuilding::setBuildingSprite() {
  BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
  BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
  BuildingSprite->setName("buildImg");
  addChild(BuildingSprite);
}

void IBuilding::setUpgradeSprite() {
  n_UpgradeSprite = Sprite::createWithSpriteFrameName("icon_main_build_lv.png");
  n_UpgradeSprite->setPosition(LvlBgOffset.x - 46, LvlBgOffset.y - 22);
  n_UpgradeSprite->setLocalZOrder(5);
  addChild(n_UpgradeSprite);
}

void IBuilding::setBuildingLvBg() {
  n_BuildingLvBg = Sprite::createWithSpriteFrameName("icon_main_build_upgrade.png");
  n_BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
  n_BuildingLvBg->setLocalZOrder(5);
  addChild(n_BuildingLvBg);
}

void IBuilding::setBuildingLvlText() {
  n_BuildingLvText = Label::createWithSystemFont("8", "Arial", 18);
  n_BuildingLvText->setSkewY(25);
  n_BuildingLvText->setAnchorPoint(Vec2(0.5, 0.5));
  n_BuildingLvText->setColor(Color3B(235, 255, 20));
  n_BuildingLvText->setPosition(LvlBgOffset.x - 20, LvlBgOffset.y - 1);
  n_BuildingLvText->setLocalZOrder(6);
  n_BuildingLvText->setAlignment(TextHAlignment::CENTER);
  addChild(n_BuildingLvText);
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

void IBuilding::ShowNormalParticle() {}


void IBuilding::setBuildingUnitData(RCityBuildingUnit& _CBUD) { BuildingUnitData = _CBUD; }

void IBuilding::setBuildingBtn() {}