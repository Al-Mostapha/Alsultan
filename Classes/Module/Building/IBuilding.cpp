#include "IBuilding.h"
#include <memory>
#include "Building.Event.h"
#include "Base/Common/Common.City.h"
#include "Module/Army/Army.Ctrl.h"
#include "Module/Building/Building.Logic.h"
#include "Module/Building/BuildingLib/StuffWorkshop.Ctrl.h"
#include "Module/Equip/Equip.Ctrl.h"
#include "Module/Science/Science.Ctrl.h"
#include "Scene/CityScene.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Base/Common/Common.Teml.h"

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
  if (!CityScene::Get()) {
    Logger::Log("Current Scene is not CityScene", ELogLvl::Error, true);
    CCASSERT(CityScene::Get(), "Current Scene is not CityScene");
    return false;
  }

  if (m_BuildingIndex == EBuildingIndex::WallGate) {
    auto l_BuildingLayer = CityScene::Get()->CityBuildingLayer;
    auto l_TipBoxWall = CityScene::Get()->GetNode<Node*>("wallTipBox");
    auto l_JiantaBaseL = CityScene::Get()->GetNode<Node*>("Button_Jiantachengduo_L");
    auto l_JiantaBaseR = CityScene::Get()->GetNode<Node*>("Button_Jiantachengduo_R");
    auto l_ArrowTowerR = CityScene::Get()->GetNode<Node*>("build_1052");
    auto l_ArrowTowerL = CityScene::Get()->GetNode<Node*>("build_1054");
    auto l_BehindArrowTower = CityScene::Get()->GetNode<Node*>("build_1066");

    auto l_JiantaBaseLBtn = GBase::DGetChildByName<Node*>(l_JiantaBaseL, "buildBtn");
    auto l_JiantaBaseRBtn = GBase::DGetChildByName<Node*>(l_JiantaBaseR, "buildBtn");
    auto l_TipBoxGuardSoldier = CityScene::Get()->TipBoxGuardSoldier;
    GVector<Node*> l_BlockingNode = {l_BuildingLayer, l_TipBoxWall,         l_JiantaBaseL,    l_JiantaBaseR,    l_ArrowTowerL,
                                     l_ArrowTowerR,   l_TipBoxGuardSoldier, l_JiantaBaseLBtn, l_JiantaBaseRBtn, l_BehindArrowTower};
    for (auto l_OneNode : l_BlockingNode) {
      if (!l_OneNode) continue;
      if (!l_OneNode->isVisible()) continue;
      if (GBase::IsTouchOnNode(p_Touch->getLocation(), l_OneNode)) return true;
    }
  }

  if (m_BuildingIndex == EBuildingIndex::BehindArrowTowerR) {
    CCASSERT(CityScene::Get()->ButtonMerchante, "Current Scene is not CityScene");
    if (!CityScene::Get()->ButtonMerchante) return false;
    if (!CityScene::Get()->ButtonMerchante->isVisible()) return false;
    if (GBase::IsTouchOnNode(l_TPoint, CityScene::Get()->ButtonMerchante)) return true;
  }

  if (CityScene::Get()->IsMoving()) return true;

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
    auto l_MovePoint = p_T->getLocation();
    auto l_Distance = l_BegainPoint.getDistance(l_MovePoint);
    if (l_Distance > TOUCH_MOVED_ERROR_VALUE) m_TouchIsMoveOnBuild = true;
  };

  l_MouseListiner->onTouchCancelled = [this](Touch* p_T, Event* p_E) { m_TouchIsMoveOnBuild = false; };

  l_MouseListiner->onTouchEnded = [=](Touch* p_Touch, Event* p_E) {
    cocos2d::log("Test is Here");
    if (m_CurrentSelectTip) RemoveBuildingTip();
    CancelTint();
    if (m_TouchIsMoveOnBuild) return;
    if (!m_IsBuildBtnEnabled) return;
    GBase::PlaySound("normalcontrol");
    if (IgnoreClickEvent(p_Touch, p_E)) return;
    if (IsCanSpeedUpStrongFree() && SpeedUpStrongFree()) return;
    if (GetState() == EBuildingState::Building && IsCanSpeedUpFree() && SpeedUpFree()) return;
    if (GetState() == EBuildingState::Demolishing && IsCanSpeedUpFree() && SpeedUpFree()) return;
    if (GetState() == EBuildingState::Training && IsCanHarvest() && HarvestAll()) return;
    if (GetState() == EBuildingState::TrapBuilding && IsCanHarvest() && HarvestAll()) return;
    if (GetState() == EBuildingState::Studying && IsCanSpeedUpResearchFree() && SpeedUpResearchFree()) return;
    if (IsNeedRequestHelp() && RequestHelp()) return;
    if (GetState() == EBuildingState::None && HasAnyAllianceHelpList() && AllianceHelpAll()) return;
    Clicked(p_Touch, p_E);
  };
  _eventDispatcher->addEventListenerWithSceneGraphPriority(l_MouseListiner, this);
}

void IBuilding::onEnter() {
  Node::onEnter();
  CCLOG("Building Entered");
  EndTimer();
  UpdateLvl();
  UpdateStarLvl();
  StartTimer();
  UpdateTimer(0.0f);
  m_HarvestState = EHarvestState::None;
  if (IsOpening()) {
    ShowAnimBuildWorker();
    ShowBuildLock();
  }
  ShowBuildLvl();
  OnAfterInitWithBuildCell();
  // InitEvents();
}

void IBuilding::OnMessageListener() {
  getEventDispatcher()->addCustomEventListener("MESSAGE_MAINCITYVIEW_CITYBUFF_DISAPPEAR",
                                           std::bind(&IBuilding::SMsgRemoveBuff, this, std::placeholders::_1));

  getEventDispatcher()->addCustomEventListener("MESSAGE_SERVER_UPDATE_BUILD_CAN_UPGRADE",
                                           [this](EventCustom* p_Event) { SMsgUpdateBuildCanUpgrade(p_Event); });

  getEventDispatcher()->addCustomEventListener("MESSAGE_MAINCITYVIEW_TRAIN_ARMY_IMMDIATELY_BACK",
                                           std::bind(&IBuilding::SMsgTrainArmyImmediatelyBack, this, std::placeholders::_1));

  getEventDispatcher()->addCustomEventListener("MESSAGE_MAINCITYVIEW_BUILD_TRAIN_FAILED",
                                           std::bind(&IBuilding::SMsgBuildTrainFailed, this, std::placeholders::_1));

  getEventDispatcher()->addCustomEventListener(
          "MESSAGE_MAINCITYVIEW_BUILDSTAR_QUEQUE_CALLBACK",
          std::bind(static_cast<void (IBuilding::*)(EventCustom*)>(&IBuilding::UpdateStarLvl), this, std::placeholders::_1));

  getEventDispatcher()->addCustomEventListener(
          "MESSAGE_BUILD_STAR_UPGRADE",
          std::bind(static_cast<void (IBuilding::*)(EventCustom*)>(&IBuilding::UpdateStarLvl), this, std::placeholders::_1));
};

void IBuilding::SMsgRemoveBuff(EventCustom* p_Event) {}

void IBuilding::SMsgUpdateBuildCanUpgrade(EventCustom* p_Event) {
  bool l_NeedUpdate = true;
  if (m_UdpateIsCanUpGradeTime > 0 && GDateTime::Now() - m_UdpateIsCanUpGradeTime <= 1) {
    l_NeedUpdate = false;
    auto l_Sequence = Sequence::create(DelayTime::create(0.5),
                                       CallFunc::create([this]() {
                                         UpdateIsCanUpgrade();
                                         UpdateStarLvl();
                                       }),
                                       nullptr);
  }
  if (l_NeedUpdate) {
    UpdateIsCanUpgrade();
    UpdateStarLvl();
  }
  m_UdpateIsCanUpGradeTime = GDateTime::Now();
}

void IBuilding::SMsgTrainArmyImmediatelyBack(EventCustom* p_Event) {}
void IBuilding::SMsgBuildTrainFailed(EventCustom* p_Event) {}

void IBuilding::ShowTopTip() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP", l_ABuildingMsg.get());
}

void IBuilding::HideTopTip() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP", l_ABuildingMsg.get());
}

void IBuilding::ShowWorkDone() {}

void IBuilding::HideWorkDone() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = this->m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_WORK_DONE_EFFECT", l_ABuildingMsg.get());
  HideTopTip();
}

void IBuilding::ShowBuildLvl() {
  if (IsLocked()) return;
  if (IsOpening()) return;
  if (this->_BuildingLvText) this->_BuildingLvText->setVisible(true);
  if (this->_BuildingLvBg) this->_BuildingLvBg->setVisible(true);
}

void IBuilding::UpdateLvl() {
  auto l_BuildingLvl = GetBuildingLvl();
  auto l_StarLvl = GetStarLvl();
  auto l_IsWarLvl = BuildingLogic::Get()->IsWarLvl(l_BuildingLvl);
  auto l_WarLvlText = GBase::DGetBuildWarLv(l_BuildingLvl);
  UpdateTextLvl();
  UpdateIsCanUpgrade();
  if (l_IsWarLvl <= 0 && _BuildingLvBg) {
    _BuildingLvBg->setSpriteFrame("icon_main_build_lv.png");
    m_IsSHowWarLv = false;
  }
  if (l_IsWarLvl > 0 && _BuildingLvBg) {
    _BuildingLvBg->setSpriteFrame("icon_main_build_warlv.png");
    m_IsSHowWarLv = false;
  }
  UpdateViewModel();
  UpdateLvlPos();
}

void IBuilding::UpdateStarLvl(EventCustom* p_Event) {
  auto l_ABuildingMsg = static_cast<ABuildingMsg*>(p_Event->getUserData());
  auto l_BuildingCell = GetBuildingCell();
  auto l_StarLvl = GetStarLvl();

  if (!l_ABuildingMsg) return;
  if (l_ABuildingMsg->BuildingIndex != m_BuildingIndex) return;
  if (!l_BuildingCell) return;
  if (l_StarLvl > 0) UpdateStarLvlBgLight();
  UpdateIsCanUpgrade();
  UpdateStarLvlPos();
  RefreshBuildStarState(nullptr);
}

void IBuilding::RefreshBuildStarState(void* p_Temp) {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  _eventDispatcher->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_UPDATE_BUILDSTAR_COOLING_PANEL", l_ABuildingMsg.get());
}

void IBuilding::InitStateMachine() {}

void IBuilding::UpdateStarLvlBgLight() {
  auto l_StarLvl = GetStarLvl();
  if (!_BuildingLvBg) return;
  _BuildingLvBg->setSpriteFrame("icon_main_buildstar_lv.png");
  UpdateTextLvl();
  if (!n_SpStarLight) {
    n_SpStarLight = Sprite::create();
    _BuildingLvBg->addChild(n_SpStarLight);
    n_SpStarLight->setPosition(83, 35);
  }
  auto l_IconName = CityCtrl::Get()->GetBuildStarLight(l_StarLvl);
  n_SpStarLight->setSpriteFrame(l_IconName);
  if (!n_BuildStarLight) {
    auto l_Action = GBase::DCreateAnimation(CsbUiFilePath::NodeBuildStarLight.c_str(), n_BuildStarLight).Second;
    _BuildingLvBg->addChild(n_BuildStarLight);
    _BuildingLvBg->setPosition(83, 35);
    for (auto l_OneNode : _BuildingLvBg->getChildren()) {
      l_OneNode->setPosition(0, 0);
    }
  }
  auto l_Lvl = CityCtrl::Get()->GetBuildStarColor(l_StarLvl);
  auto l_NodeName = StringUtils::format("Node_%d", l_Lvl);
  for (auto l_OneNode : _BuildingLvBg->getChildren()) {
    l_OneNode->setVisible(l_OneNode->getName() == l_NodeName);
  }
}

// TODO: This functio may Has Bug
void IBuilding::ChangeState() {
  std::unique_ptr<IState::Event> l_StateEvent(new IState::Event(this));
  if (GetState() == EBuildingState::Idle && m_States.Contains(EBuildingState::Idle))  // Idle Is reset
    m_States[EBuildingState::Idle]->Enter(l_StateEvent.get());
  else if (GetState() == EBuildingState::Lock && m_States.Contains(EBuildingState::Lock))
    m_States[EBuildingState::Lock]->Enter(l_StateEvent.get());
  else if (GetState() == EBuildingState::Building && m_States.Contains(EBuildingState::Building))
    m_States[EBuildingState::Building]->Enter(l_StateEvent.get());
  else if (GetState() == EBuildingState::Working && m_States.Contains(EBuildingState::Working))
    m_States[EBuildingState::Working]->Enter(l_StateEvent.get());
  else if (GetState() == EBuildingState::Demolishing && m_States.Contains(EBuildingState::Demolishing))
    m_States[EBuildingState::Demolishing]->Enter(l_StateEvent.get());
  else if (GetState() == EBuildingState::Harvesting && m_States.Contains(EBuildingState::Harvesting))
    m_States[EBuildingState::Harvesting]->Enter(l_StateEvent.get());
}

void IBuilding::ShowGlow() {
  auto l_BuildingLvl = GetBuildingLvl();
  auto l_WarLvl = BuildingLogic::Get()->IsWarLvl(l_BuildingLvl);
  if (l_WarLvl > GBase::Const::Get()->CastleMinWarLvl) {
    if (!n_BuildGlowWar) {
      // TODO: This Node Should Be Spacified for each Building
    }
  }
}

void IBuilding::HideGlow() {
  if (!n_BuildGlowWar) return;
  n_BuildGlowWar->stopAllActions();
  n_BuildGlowWar->removeFromParent();
  n_BuildGlowWar = nullptr;
}

void IBuilding::ShowCoolingPanel() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_COOLING_PANEL", l_ABuildingMsg.get());
}

void IBuilding::HideCoolingPanel() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_COOLING_PANEL", l_ABuildingMsg.get());
}
// TODO: ADD SHOW AND HIDE BUILDING Glow
void IBuilding::ShowAnimWorking(bool p_ShowGlow) {
  HideZAnimation();
  if (p_ShowGlow)
    ShowGlow();
  else
    HideGlow();
  ShowWorkingEffect();
}

void IBuilding::HideAnimWorking() {
  HideGlow();
  HideWorkingEffect();
  HideNormalParticle();
}

void IBuilding::ShowAnimBoost() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_ANIM_BOOST", l_ABuildingMsg.get());
}

void IBuilding::HideAnimBoost() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_ANIM_BOOST", l_ABuildingMsg.get());
}

void IBuilding::ShowAnimBuildWorker(bool p_HideHammer) {
  HideZAnimation();
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  l_ABuildingMsg->IsHideHammer = p_HideHammer;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_ANIM_WORKER", l_ABuildingMsg.get());
}

void IBuilding::HideAnimBuildWorker() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_ANIM_WORKER", l_ABuildingMsg.get());
}

// TODO: Should be added from Building Config
void IBuilding::ShowNormalParticle() {
  // for i = 1, 10 do
  //   local nodeName = "buildParticleNormal_" .. i
  //   local nodeCfgItem = self:getCfgItemByName(nodeName)
  //   if nodeCfgItem ~= nil and self[nodeName] ~= nil then
  //     break
  //   end
  //   local node = self:loadNodeByName(nodeName)
  //   if node == nil then
  //     break
  //   end
  // end
  // self:loadNodeByName("buildCsdNormal")
}

void IBuilding::HideNormalParticle() {
  // for i = 1, 10 do
  //   local nodeName = "buildParticleNormal_" .. i
  //   local node = self[nodeName]
  //   if node ~= nil then
  //     self[nodeName] = nil
  //     node:removeFromParent()
  //   else
  //     break
  //   end
  // end
  // local nodeName = "buildCsdNormal"
  // local node = self[nodeName]
  // if node ~= nil then
  //   self[nodeName] = nil
  //   node:removeFromParent()
  // end
}

void IBuilding::ShowBrightParticle() {
  // for i = 1, 10 do
  //   local nodeName = "buildParticleBright_" .. i
  //   local nodeCfgItem = self:getCfgItemByName(nodeName)
  //   if nodeCfgItem ~= nil and self[nodeName] ~= nil then
  //     break
  //   end
  //   local node = self:loadNodeByName(nodeName)
  //   if node == nil then
  //     break
  //   end
  // end
  // self:loadNodeByName("buildCsdBright")
}

void IBuilding::HideBrightParticle() {
  // for i = 1, 10 do
  //   local nodeName = "buildParticleBright_" .. i
  //   local node = self[nodeName]
  //   if node ~= nil then
  //     self[nodeName] = nil
  //     node:removeFromParent()
  //   else
  //     break
  //   end
  // end
  // local nodeName = "buildCsdBright"
  // local node = self[nodeName]
  // if node ~= nil then
  //   self[nodeName] = nil
  //   node:removeFromParent()
  // end
}

void IBuilding::ShowEffectUpgrade() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = m_BuildingIndex;
  l_ABuildingMsg->BuildingNode = this;
  l_ABuildingMsg->PosEtUpgradeOffset = m_PosEtUpgradeOffset;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_BUILD_EFFECT_UPGRADE", l_ABuildingMsg.get());
}

void IBuilding::HideEffectUpgrade() {}

void IBuilding::StartTimer() {
  if (m_TimeHandler != nullptr) {
    GBase::DRemoveTimer(this, m_TimeHandler);
    m_TimeHandler = nullptr;
    return;
  }

  // m_TimeHandler = GBase::DCreateTimer(this, CC_CALLBACK_1(IBuilding::UpdateTimer, 0.0f));
  UpdateTimer(0.0f);
}

void IBuilding::EndTimer() {
  if (m_TimeHandler != nullptr) {
    GBase::DRemoveTimer(this, m_TimeHandler);
    m_TimeHandler = nullptr;
  }
}

void IBuilding::UpdateTimer(float p_Delta) {
  if (GetState() == EBuildingState::Building || GetState() == EBuildingState::Upgrading || GetState() == EBuildingState::Demolishing ||
      GetState() == EBuildingState::Lock) {
    return;
  }
  auto l_BuildingType = GetBuildingId();
  auto l_BuidingIndex = GetBuildingIndex();
  UpdateBuff();
  auto l_CurrentHarvest = GetCurrentHarvest();
  auto l_MaxHarvest = GetMaxHarvest();
  auto l_HarvestState = GetHarvestState();
  if (l_CurrentHarvest == 0 && GetState() != EBuildingState::Working) {
    SetBlockState(EBuildingState::Working);
    ChangeState();
  }
  if (l_CurrentHarvest > 0 && l_HarvestState == EHarvestState::None) {
    if (GetState() != EBuildingState::Working) {
      SetBlockState(EBuildingState::Working);
      ChangeState();
    }
    SetHarvestState(EHarvestState::Some, true);
  }
  if (IsHarvestMuch((float)l_CurrentHarvest, (float)l_MaxHarvest) && l_HarvestState == EHarvestState::Some) {
    SetHarvestState(EHarvestState::Much, true);
    SetBlockState(EBuildingState::Harvesting);
    ChangeState();
    //   if self.turnToHarvestView then
    //     self:turnToHarvestView(true)
    //   end
  }
}

EHarvestState IBuilding::GetHarvestState() { return m_HarvestState; }

void IBuilding::SetHarvestState(EHarvestState p_HarvestState, bool p_IsAnim) {
  if (m_HarvestState == p_HarvestState) return;
  m_HarvestState = p_HarvestState;
}

bool IBuilding::IsNeedRequestHelp() { return GetReqHelpQueueTypeList().size() > 0; }

GVector<ETask> IBuilding::GetReqHelpQueueTypeList() {
  GVector<ETask> l_ReqHelpQueueTypeList;
  auto l_QueueType = GetQueueType();
  auto l_StarQueueType = GetBuildStarQueueType();
  if (l_QueueType != ETask::None) {
    l_ReqHelpQueueTypeList.push_back(l_QueueType);
  }
  if (l_StarQueueType != ETask::None) {
    l_ReqHelpQueueTypeList.push_back(l_StarQueueType);
  }
  return l_ReqHelpQueueTypeList;
}

void IBuilding::DoReqHelp() {
  for (auto l_QueueType : GetReqHelpQueueTypeList()) {
    DoReqHelpByQueueType(l_QueueType);
  }
}

void IBuilding::DoReqHelpByQueueType(ETask p_Task) {
  struct {
    int Id;
    uint32 Lvl;
  } l_Data;
  auto l_BuildingType = GetBuildingId();
  if (p_Task == ETask::BuildStarQueue || p_Task == ETask::BuildStarQueuePrivilege || p_Task == ETask::GloriousUpgrade) {
    l_Data.Id = static_cast<int>(GetBuildingId());
    l_Data.Lvl = GetStarLvl() + 1;
  } else if (GetState() == EBuildingState::None) {
    if (l_BuildingType == EBuilding::FirstAidTent) {
      //       data = nil
    } else if (l_BuildingType == EBuilding::Institute) {
      //l_Data.Id = static_cast<int>(ScienceCtrl::Get()->StudyingTechnology());
    } else if (l_BuildingType == EBuilding::Miracle) {
      //l_Data.Id = static_cast<int>(ScienceCtrl::Get()->StudyingTechnology());
    } else if (l_BuildingType == EBuilding::Blacksmith) {
      //  local eid, count = self:getTrainingAidAndCount()
      //  data = {equipid = eid}
    } else if (l_BuildingType == EBuilding::StarBraveStatue) {
     // l_Data.Id = static_cast<int>(ScienceCtrl::Get()->StudyingTechnology());
    }
  } else if (GetState() == EBuildingState::Building || GetState() == EBuildingState::Upgrading) {
    l_Data.Id = static_cast<int>(GetBuildingId());
    l_Data.Lvl = GetBuildingLvl() + 1;
  }

  GuildHelp::Get()->ReqAllianceHelp(p_Task, l_Data.Id, l_Data.Lvl);
}

bool IBuilding::SpeedUpFree() {
  TaskCtrl::Get()->SpeedUpQueueReq(GetQueueType(), ESpeedType::Free);
  return true;
}

bool IBuilding::SpeedUpStrongFree() {
  TaskCtrl::Get()->SpeedUpQueueReq(GetBuildStarQueueType(), ESpeedType::Free);
  return true;
}

bool IBuilding::SpeedUpResearchFree() {
  TaskCtrl::Get()->SpeedUpQueueReq(GetQueueType(), ESpeedType::Gold);
  return true;
}

bool IBuilding::IsCanHarvest() {
  bool l_IsCanHarvest = false;
  auto l_BuildingType = GetBuildingId();
  if (l_BuildingType == EBuilding::Blacksmith) {
    return EquipCtrl::Get()->IsCanGetEquip();
  } else if (l_BuildingType == EBuilding::MaterialWorkShop) {
    return StuffWorkshopCtrl::Get()->GetDoneID() != 0;
  }
  if (l_BuildingType == EBuilding::ElitePalace) {
    //   print("elite")
  }
  auto l_TrainedType = ArmyCtrl::Get()->GetTrainArmy(l_BuildingType);
  if (l_TrainedType != EArmy::None) {
    m_IsCanHarvestTrain = true;
    m_TrainedArmy = l_TrainedType;
  }
  return m_IsCanHarvestTrain;
}

bool IBuilding::IsTraining() {
  bool l_IsTraining = false;
  auto l_BuildingType = GetBuildingId();
  auto l_QueueType = BuildingRead::Get()->GetQueueType(l_BuildingType);
  auto l_Queue = TaskCtrl::Get()->QueryQueue(l_QueueType);
  if (l_Queue == nullptr) return false;
  l_IsTraining = false;
  if (GetState() == EBuildingState::None) {
    auto l_RemainTime = l_Queue->GetRemainTime();
    if (l_RemainTime <= 0) {
      l_IsTraining = false;
    } else {
      l_IsTraining = true;
    }
  }
  return l_IsTraining;
}

ITask* IBuilding::GetPromotingQueue() { return TaskCtrl::Get()->QueryQueue(ETask::PromptArmy); }

ITask* IBuilding::GetTrainingQueue() {
  auto l_QueueType = BuildingRead::Get()->GetQueueType(GetBuildingId());
  return TaskCtrl::Get()->QueryQueue(l_QueueType);
}

void IBuilding::SetQueueDirty(bool p_IsDirty) { m_QueueDirty = p_IsDirty; }

ITask* IBuilding::GetQueue() {
  if (m_Queue != nullptr && m_QueueDirty == true) return m_Queue;
  if (IsTraining())
    m_Queue = GetTrainingQueue();
  else
    m_Queue = GetBuildingQueue();
  return m_Queue;
}

ITask* IBuilding::GetBuildingQueue() {
  auto l_QueueType = BuildingLogic::Get()->GetQueueType(GetBuildingIndex());
  return l_QueueType;
}

ETask IBuilding::GetQueueType() {
  auto l_QueuType = ETask::None;
  if (IsTraining()) {
    l_QueuType = GetTrainingQueueType();
  } else {
    l_QueuType = GetBuildQueueType();
  }
  return l_QueuType;
}

ETask IBuilding::GetBuildQueueType() {
  auto l_QueueType = BuildingLogic::Get()->GetQueueType(GetBuildingIndex());
  if (!l_QueueType) return ETask::None;
  return l_QueueType->GetQueueType();
}

ETask IBuilding::GetTrainingQueueType() {
  auto l_QueueType = BuildingRead::Get()->GetQueueType(GetBuildingId());
  return l_QueueType;
}

ETask IBuilding::GetBuildStarQueueType() {
  auto l_Queue = GetBuildStarQueue();
  if (l_Queue == nullptr) l_Queue = GetBuildStarSecondQueue();
  if (l_Queue == nullptr) l_Queue = GetBuildStatueBraveQueue();
  if (l_Queue != nullptr) return l_Queue->GetQueueType();
  return ETask::None;
}

ITask* IBuilding::GetBuildStarQueue() {
  auto l_BuildingType = GetBuildingId();
  auto l_BuildingIndex = GetBuildingIndex();
  ITask* l_Queue = TaskCtrl::Get()->QueryQueue(ETask::BuildStarQueue);
  auto l_BuildingQueue = static_cast<RBuildingTask*>(l_Queue);
  if (l_BuildingQueue == nullptr) return nullptr;
  if (l_BuildingQueue->GetBuildingType() != l_BuildingType) return nullptr;
  if (l_BuildingQueue->GetBuildingIndex() != l_BuildingIndex) return nullptr;
  return l_BuildingQueue;
}

ITask* IBuilding::GetBuildStarSecondQueue() {
  auto l_BuildingType = GetBuildingId();
  auto l_BuildingIndex = GetBuildingIndex();
  ITask* l_Queue = TaskCtrl::Get()->QueryQueue(ETask::BuildStarQueuePrivilege);
  auto l_BuildingQueue = static_cast<RBuildingTask*>(l_Queue);
  if (l_BuildingQueue == nullptr) return nullptr;
  if (l_BuildingQueue->GetBuildingType() != l_BuildingType) return nullptr;
  if (l_BuildingQueue->GetBuildingIndex() != l_BuildingIndex) return nullptr;
  return l_BuildingQueue;
}

ITask* IBuilding::GetBuildStatueBraveQueue() {
  auto l_BuildingType = GetBuildingId();
  auto l_BuildingIndex = GetBuildingIndex();
  ITask* l_Queue = TaskCtrl::Get()->QueryQueue(ETask::GloriousUpgrade);
  auto l_BuildingQueue = static_cast<RBuildingTask*>(l_Queue);
  if (l_BuildingQueue == nullptr) return nullptr;
  if (l_BuildingQueue->GetBuildingType() != l_BuildingType) return nullptr;
  return l_BuildingQueue;
}

ITask* IBuilding::GetBuildDiggingQueue() {
  auto l_BuildingType = GetBuildingId();
  ITask* l_Queue = TaskCtrl::Get()->QueryQueue(ETask::EndlessTreasureQueue);
  if (!l_Queue) return nullptr;
  if (l_BuildingType != EBuilding::TreasurePool) return nullptr;
  return l_Queue;
}

bool IBuilding::HasSpeedUpCooling() {
  if (GetBuildingId() == EBuilding::FirstAidTent /*and worldMapDefine.isInPyramid()*/) {
    auto l_CdQueue = ArmyCtrl::Get()->GetHostpitalPyramidWarCDQueueTime();
    if (l_CdQueue > 0) return true;
  }
  return false;
}

GTime IBuilding::GetSpeedUpCoolingTime() {
  if (GetBuildingId() == EBuilding::FirstAidTent) {
    return ArmyCtrl::Get()->GetHostpitalPyramidWarCDQueueTime();
  }
  return 0;
}

void IBuilding::DoHarvesting() {
  auto l_BuildingPlace = GBase::DGetBuildingTypeByIndex(GetBuildingIndex());
  auto l_BuildingId = GetBuildingId();
  if (l_BuildingPlace == EBuildingPlace::Inner) {
    if (l_BuildingId == EBuilding::Stable || l_BuildingId == EBuilding::TargetRange || l_BuildingId == EBuilding::Barrack ||
        l_BuildingId == EBuilding::Fortress || l_BuildingId == EBuilding::ChariotPlant || l_BuildingId == EBuilding::MaterialWorkShop ||
        l_BuildingId == EBuilding::ElitePalace) {
      HarvestTrainArmy();
    } else {
      //     self.fsm_:doEvent("reset")
    }
  } else {
    HarvestRes();
  }
}

void IBuilding::HarvestTrainArmy() {
  auto l_BuildingId = GetBuildingId();
  GBase::PlaySound("trainsoilder" /**, l_BuildingId*/);
  if (l_BuildingId == EBuilding::Blacksmith)
    GBase::DGetEquip();
  else if (l_BuildingId == EBuilding::MaterialWorkShop)
    StuffWorkshopCtrl::Get()->SendGetStuff();
  else {
    if ((l_BuildingId == EBuilding::Stable || l_BuildingId == EBuilding::TargetRange || l_BuildingId == EBuilding::Barrack ||
        l_BuildingId == EBuilding::Fortress || l_BuildingId == EBuilding::ChariotPlant ||
        l_BuildingId == EBuilding::ElitePalace) && WorldMapDefine::Get()->IsInWarForbidSoldier())
      return;
    ArmyCtrl::Get()->GetTrainArmyReq(l_BuildingId);
  }
}

void IBuilding::HarvestRes() {
  auto l_BuildingId = GetBuildingId();
  auto l_BuildingIndex = GetBuildingIndex();
  auto l_BuildingPlace = GBase::DGetBuildingTypeByIndex(l_BuildingIndex);
  if (l_BuildingPlace != EBuildingPlace::Inner) {
    std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
    l_ABuildingMsg->BuildingIndex = l_BuildingIndex;
    l_ABuildingMsg->BuildingNode = this;
    getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_ADD_HARVEST_FLOATING", l_ABuildingMsg.get());
    SetHarvestState(EHarvestState::None, false);
  }

  GBase::PlaySound("trainsoilder" /*, l_BuildingId*/);
  CityCtrl::Get()->CollectResReq(l_BuildingId, l_BuildingIndex);
  // self.fsm_:doEvent("reset")
  // if self.turnToNormalView then
  //   self:turnToNormalView(true)
  // end
}

void IBuilding::HarvestBatchRes() {
  std::unique_ptr<ABuildingMsg> l_ABuildingMsg(new ABuildingMsg());
  l_ABuildingMsg->BuildingIndex = GetBuildingIndex();
  l_ABuildingMsg->BuildingNode = this;
  getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_COLLECT_BATCH_RES", l_ABuildingMsg.get());
}

bool IBuilding::CanHarvestBatchRes() {
  if (GetBuildingId() == EBuilding::Farm) return true;
  if (GetBuildingId() == EBuilding::LumberMill) return true;
  if (GetBuildingId() == EBuilding::IronMine) return true;
  if (GetBuildingId() == EBuilding::SilverMine) return true;
  if (GetBuildingId() == EBuilding::CrystalMine) return true;
  return false;
}

void IBuilding::BuildButtonCallFun(Touch* p_Touch, Event* p_Event, ETouchEventType p_Type) {
  std::unique_ptr<ABuildingTouchMsg> l_ABuildingMsg(new ABuildingTouchMsg());
  l_ABuildingMsg->BuildingIndex = GetBuildingIndex();
  l_ABuildingMsg->BuildingNode = this;
  l_ABuildingMsg->TouchEvent = p_Event;
  l_ABuildingMsg->TouchEventType = p_Type;
  if (p_Type == ETouchEventType::Begin) {
    getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_BUILDING_BUTTON_TOUCH_BEGIN", l_ABuildingMsg.get());
  } else if (p_Type == ETouchEventType::End) {
    if (m_SingleIsMoved) {
      l_ABuildingMsg->TouchEventType = ETouchEventType::Cancel;
      getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_BUILD_BTN_EVENT", l_ABuildingMsg.get());
      return;
    }
    m_SingleIsMoved = false;
    getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_BUILD_BTN_EVENT", l_ABuildingMsg.get());
  } else if (p_Type == ETouchEventType::Move) {
    auto l_TouchBeganPoint = p_Touch->getStartLocation();
    auto l_TouchMovePoint = p_Touch->getLocation();
    auto l_Distance = l_TouchBeganPoint.getDistance(l_TouchMovePoint);
    if (l_Distance > TOUCH_MOVED_ERROR_VALUE) {
      m_SingleIsMoved = true;
    }
  } else if (p_Type == ETouchEventType::Cancel) {
    getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITYVIEW_BUILD_BTN_EVENT", l_ABuildingMsg.get());
    m_SingleIsMoved = false;
  }
}

void IBuilding::ShowLock() {
  if (!n_ImgLock) return;
  n_ImgLock->setVisible(true);
}

void IBuilding::HideLock() {
  if (!n_ImgLock) return;
  n_ImgLock->setVisible(false);
}

bool IBuilding::IsLockVisible() {
  auto l_IsLockVisible = false;
  if (GetBuildingId() != EBuilding::CrystalMine) return l_IsLockVisible;
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCell(EBuilding::Castle, EBuildingIndex::None);
  if (l_BuildingCell->_Info.buildingLvl < 30) l_IsLockVisible = true;
  return l_IsLockVisible;
}

bool IBuilding::IsLocked() {
  bool l_IsLocked = false;
  auto l_BuildingId = GetBuildingId();
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCell(EBuilding::Castle, EBuildingIndex::None);
  auto l_CastleLv = l_BuildingCell->_Info.buildingLvl;

  if (l_BuildingId == EBuilding::ArrowTower) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl7)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::Blacksmith) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl10)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::MaterialWorkShop) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl10)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::PetHouse) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl4)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::ElitePalace) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl16)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::TrainHall) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl7)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  }

  // elseif bid == BUILDID.HERO_CENOTAPH then
  //   local castleBid = BUILDID.CASTLE
  //   local buildCell = cityCtrl:getBuildCell(castleBid, 0)
  //   if nil == buildCell then
  //     return isLocked
  //   end
  //   local castleLv = tonumber(buildCell.info.lv)
  //   if castleLv >= CASTLE_LV19_LIMITED then
  //     isLocked = false
  //   else
  //     isLocked = true
  //   end
  //   print("\231\186\170\229\191\181\231\162\145\239\188\140\233\156\128\232\166\129\229\159\142\229\160\16119\231\186\167\232\167\163\233\148\129===",
  //   castleLv, CASTLE_LV19_LIMITED, isLocked)
  else if (l_BuildingId == EBuilding::Prison) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl16)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::EpicBattle) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl7)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::Monument) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl6)
      l_IsLocked = false;
    else
      l_IsLocked = true;
  } else if (l_BuildingId == EBuilding::ResurrectionHall) {
    if (l_CastleLv >= (int32)GBase::Const::Get()->CastleLvl6)
      l_IsLocked = false;
    else
      l_IsLocked = true;

    //   if isLocked ~= true then
    //     local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
    //     print("lordInfoCtrl:getBaseInfo().isSrcKingWarEnabled ", lordInfoCtrl:getBaseInfo().isSrcKingWarEnabled)
    //     if not lordInfoCtrl:getBaseInfo().isSrcKingWarEnabled then
    //       isLocked = true
    //     end
    //   end
  } else if (l_BuildingId == EBuilding::CrystalMine) {
    //   local castleLv = tonumber(buildCell.info.lv)
    //   local isShowWarLv, textLv = SoraDGetBuildWarLv(castleLv)
    //   print("isShowWarLv = ", isShowWarLv, ", textLv = ", textLv)
    //   if not isShowWarLv or textLv < 3 then
    //     isLocked = true
    //   else
    //     isLocked = false
    //   end
  }
  return l_IsLocked;
}

void IBuilding::UpdateIsLock() {
  //   function cityBuildBaseEntity:updateIsLock()
  //   local bid = self:getBuildBid()
  //   local checkLockVisible = {
  //     BUILDID.CRYSTAL_MINE
  //   }
  //   local isNeedCheckVisible = false
  //   for i = 1, #checkLockVisible do
  //     if checkLockVisible[i] == bid then
  //       isNeedCheckVisible = true
  //       break
  //     end
  //   end
  //   if isNeedCheckVisible then
  //     if self:getIsLockVisible() then
  //       self:setVisible(false)
  //       return
  //     else
  //       self:setVisible(true)
  //     end
  //   end
  //   if bid == BUILDID.TURRET then
  //     local isLocked = self:getIsLocked()
  //     if isLocked then
  //       if self.showLock then
  //         self:showLock()
  //       end
  //     else
  //       if self.hideLock then
  //         self:hideLock()
  //       end
  //       self:showBuildLv()
  //     end
  //   end
  //   local checkLockTb = {
  //     BUILDID.BLACK_SMITH,
  //     BUILDID.MATERIAL_WORKSHOP,
  //     cityBuildConstDef.fixedBuildDef.PetCenter,
  //     BUILDID.ELITE_PALACE,
  //     cityBuildConstDef.fixedBuildDef.ResurrectionHall,
  //     BUILDID.CRYSTAL_MINE,
  //     cityBuildConstDef.fixedBuildDef.EpicBattle,
  //     BUILDID.HERO_TRAIN_GROUND,
  //     BUILDID.HERO_PRISON,
  //     BUILDID.MONUMENT,
  //     cityBuildConstDef.fixedBuildDef.Mastery
  //   }
  //   local isNeedCheck = false
  //   for i = 1, #checkLockTb do
  //     if checkLockTb[i] == bid then
  //       isNeedCheck = true
  //       break
  //     end
  //   end
  //   if isNeedCheck then
  //     local isLocked = self:getIsLocked()
  //     if isLocked then
  //       if self.showBuildLock then
  //         self:showBuildLock()
  //       end
  //     else
  //       if self.hideBuildLock then
  //         self:hideBuildLock()
  //       end
  //       local isNeedRefreshHarvestEffect = false
  //       local checkHarvestTb = {
  //         BUILDID.CRYSTAL_MINE
  //       }
  //       for i, v in ipairs(checkHarvestTb) do
  //         if bid == v then
  //           isNeedRefreshHarvestEffect = true
  //           break
  //         end
  //       end
  //       if isNeedRefreshHarvestEffect then
  //         SoraDSendMessage({
  //           msg = "MESSAGE_MAINCITY_UPDATE_HARVEST_EFFECT"
  //         })
  //       end
  //     end
  //   end
  // end
}

bool IBuilding::HasAnyAllianceHelpList() {
  auto l_Has = false;
  auto l_BuildingId = GetBuildingId();
  if (l_BuildingId != EBuilding::Embassy) return l_Has;
  return GuildHelp::Get()->IsCanHelp();
}

void IBuilding::UpdateAllianceHelpList() {
  if (GetBuildingId() != EBuilding::Embassy) return;
  auto l_IsCanHelp = GuildHelp::Get()->IsCanHelp();
  auto l_BuildingState = GetState();
  if (l_IsCanHelp) {
    if (l_BuildingState == EBuildingState::None) ShowTopTip();
  } else if (l_BuildingState == EBuildingState::None) {
    HideTopTip();
  }
}

bool IBuilding::AllianceHelpAll() {
  GuildHelp::Get()->ReqHelpAll();
  return true;
}

void IBuilding::UpdateIsCanUpgradeStar() {
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

void IBuilding::HideBuildLvl() {}

void IBuilding::UpdateTextLvl() {
  auto l_BuildingLvl = GetBuildingLvl();
  if (GetState() == EBuildingState::Building && l_BuildingLvl == 1) {
    SetTextLvl(std::to_string(0));
    return;
  }
  auto l_StarLvl = GetStarLvl();
  auto [lIsWar, lWarLv, lDes] = GBase::DGetBuildWarLv(l_BuildingLvl);
  if (l_StarLvl > 0) {
    SetTextLvl(std::to_string(lWarLv) + "-" + std::to_string(l_StarLvl));
  } else {
    SetTextLvl(std::to_string(lWarLv));
  }
}

void IBuilding::UpdateIsCanUpgrade() {
  if (IsOpening()) return;
  auto l_IsCanUpgrade = BuildingLogic::Get()->IsShowUpgrade(m_BuildingIndex);
  SetIsCanUpgrade(l_IsCanUpgrade);
}

void IBuilding::SetIsCanUpgrade(bool p_IsCan) {
  _IsCanUpgrade = p_IsCan;
  if (_IsCanUpgradeStar) return;
  if (!_UpgradeSprite) return;
  if (_IsCanUpgrade)
    _UpgradeSprite->setVisible(true);
  else
    _UpgradeSprite->setVisible(false);
};

void IBuilding::setBuildingSprite() {
  BuildingSprite = Sprite::createWithSpriteFrameName(BuildingSpriteImage);
  BuildingSprite->setPosition(this->BuildingSpriteOffset.x, this->BuildingSpriteOffset.y);
  BuildingSprite->setName("buildImg");
  addChild(BuildingSprite);
}

void IBuilding::setUpgradeSprite() {
  _UpgradeSprite = Sprite::createWithSpriteFrameName("icon_main_build_lv.png");
  _UpgradeSprite->setPosition(LvlBgOffset.x - 46, LvlBgOffset.y - 22);
  _UpgradeSprite->setLocalZOrder(5);
  addChild(_UpgradeSprite);
}

void IBuilding::setBuildingLvBg() {
  _BuildingLvBg = Sprite::createWithSpriteFrameName("icon_main_build_upgrade.png");
  _BuildingLvBg->setPosition(LvlBgOffset.x, LvlBgOffset.y);
  _BuildingLvBg->setLocalZOrder(5);
  addChild(_BuildingLvBg);
}

void IBuilding::setBuildingLvlText() {
  _BuildingLvText = Label::createWithSystemFont("8", "Arial", 18);
  _BuildingLvText->setSkewY(25);
  _BuildingLvText->setAnchorPoint(Vec2(0.5, 0.5));
  _BuildingLvText->setColor(Color3B(235, 255, 20));
  _BuildingLvText->setPosition(LvlBgOffset.x - 20, LvlBgOffset.y - 1);
  _BuildingLvText->setLocalZOrder(6);
  _BuildingLvText->setAlignment(TextHAlignment::CENTER);
  addChild(_BuildingLvText);
}

void IBuilding::setBuildingSleepSprite() {
  float offsetX = 50;
  float offsetY = 40;
  float oriX = 44;
  float oriY = 97;

  auto actionMoveTo = MoveTo::create(0, Vec2(oriX, oriY));
  auto actionFadeTo = FadeTo::create(0, 1);
  auto actionRotateTo = RotateTo::create(0, 0);
  auto actionMoveBy = MoveBy::create(1.6f, Vec2(offsetX, offsetY));
  auto actionFadeTo2 = FadeTo::create(1.6f, 0.5f);
  auto actionRotateBy = RotateBy::create(1.6f, 30);

  Spawn* actionSpawn = Spawn::create(actionMoveBy, actionFadeTo2, actionRotateBy, NULL);
  Sequence* sequenceAction = Sequence::create(actionMoveTo, actionFadeTo, actionRotateTo, actionSpawn, NULL);

  DelayTime* actionDelay1 = DelayTime::create(0.2f);

  Sequence* actionSeq2 =
          Sequence::create(MoveTo::create(0, Vec2(oriX, oriY)),
                           FadeTo::create(0, 1),
                           RotateTo::create(0, 0),
                           Spawn::create(MoveBy::create(1.6f, Vec2(offsetX, offsetY)), FadeTo::create(1.6f, 0.5f), RotateBy::create(1.6f, -30), NULL),
                           NULL);

  DelayTime* actionDelay2 = DelayTime::create(0.2f);

  Sequence* actionSeq3 =
          Sequence::create(MoveTo::create(0, Vec2(oriX, oriY)),
                           FadeTo::create(0, 1),
                           RotateTo::create(0, 0),
                           Spawn::create(MoveBy::create(1.6f, Vec2(offsetX, offsetY)), FadeTo::create(1.6f, 0), RotateBy::create(1.6f, 30), NULL),
                           NULL);

  DelayTime* actionDelay3 = DelayTime::create(3.8f);

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
/**
const GHashMap<EBuilding, uint32> IBuilding::m_SearchBoostToolTable = {
  {EBuilding::Farm,        501501},
  {EBuilding::LumberMill,  501401},
  {EBuilding::IronMine,    501601},
  {EBuilding::SilverMine,  501701},
  {EBuilding::CrystalMine, 503201},
};*/

void IBuilding::setBuildingUnitData(RCityBuildingUnit& _CBUD) { Info = _CBUD; }

void IBuilding::setBuildingBtn() {}

void IBuilding::InitWithUIType() {
  auto l_DefaultNode  = GDisplay::Get()->NewNode();
  addChild(l_DefaultNode);
  m_ViewNodes.n_Default = l_DefaultNode;
}

void IBuilding::InitWithUIType(RBuildingViewNodes p_ViewNodes, Vec2 p_BasePos) {
    m_ViewNodes = p_ViewNodes;
    m_BasePos = p_BasePos;
}

void IBuilding::LoadView(){
  LoadBaseView();
}

void IBuilding::LoadBaseView(){
  LoadBaseViewByBid(m_BID);
}

void IBuilding::LoadBaseViewByBid(EBuilding p_Bid){
  
}

bool IBuilding::CheckCanTrainOrUpgrade(){
  //   local canTrainOrUpgrade = true
  // if self.isWaitTraining == true then
  //   self:showIsTrainningTip()
  //   canTrainOrUpgrade = false
  //   return canTrainOrUpgrade
  // end
  // local bid = self:getBuildBid()
  // if bid == BUILDID.STABLES or bid == BUILDID.RANGE or bid == BUILDID.BARRACKS or bid == BUILDID.FORTRESS or bid == BUILDID.CHARIOT_PLANT or bid == BUILDID.BLACK_SMITH or bid == BUILDID.HOSTPITAL then
  //   if true == self:getIsTraining() then
  //     self:showIsTrainningTip()
  //     canTrainOrUpgrade = false
  //     return canTrainOrUpgrade
  //   end
  //   if "working" == self:getState() then
  //     self:showIsTrainningTip()
  //     canTrainOrUpgrade = false
  //     return canTrainOrUpgrade
  //   end
  //   if "harvesting" == self:getState() then
  //     self:showIsTrainningTip()
  //     canTrainOrUpgrade = false
  //     return canTrainOrUpgrade
  //   end
  //   if "building" == self:getState() then
  //     self:showIsBuildingTip()
  //     canTrainOrUpgrade = false
  //     return canTrainOrUpgrade
  //   end
  // end
  // return canTrainOrUpgrade
  return true;
}

int32 IBuilding::GetBoostToolNum(EBuilding pBuilding){
  // if bid == nil then
  //   bid = self:getBuildBid()
  // end
  // local gametop = gModuleMgr.getObject("gametop")
  // local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
  // local itemId = self:getBoostToolId(bid)
  // local itemCount = 0
  // if itemId ~= nil then
  //   itemCount = backpackCtrl:getItemCount(itemId)
  // end
  // return itemCount
  return 0;
}