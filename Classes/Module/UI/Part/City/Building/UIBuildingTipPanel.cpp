#include "UIBuildingTipPanel.h"
#include "UIBuildingTipButton.h"
#include "Base/Common/Common.City.h"
#include "Module/Building/IBuilding.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Module/Building/Building.Lib.h"
#include "Module/Building/Building.Logic.h"
#include "Module/City/CityBuilding/City.LtCtrl.h"
#include "Module/Activity/ClientEvent.Mgr.h"
#include "Module/Vip/PrivilegeGift.Ctrl.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/PyramidWar/ConquestWar.Ctrl.h"
#include "Game/Config/FunUnLock/FunUnlock.Read.h"


float UIBuildingTipPanel::ACTION_TIME = 0.13f;
float UIBuildingTipPanel::TIME_DELAY_INIT = 0.001f;
int32 UIBuildingTipPanel::tag_act_init_view = 30000;
int32 UIBuildingTipPanel::tag_act_single_btn = 1000;
int32 UIBuildingTipPanel::tag_act_tip_show_end = 999;

UIBuildingTipPanel* UIBuildingTipPanel::Create()
{
  // auto l_TipPanel = Create("UiParts/Parts/Building/buildTip.csb");
  auto l_TipPanel = create();
  l_TipPanel->Ctor();
  return l_TipPanel;
}

void UIBuildingTipPanel::Ctor(){
  CreateUI();
}

void UIBuildingTipPanel::CreateUI(){
  _CircleFrameBg = GDisplay::Get()->NewSprite("frame_main_build_03.png");
  addChild(_CircleFrameBg);
  _CircleFrameBg->setPosition(0, -194);
  _BuildingNameFrame = ui::ImageView::create();
  _BuildingNameFrame->loadTexture("title_main_build.png", ui::Widget::TextureResType::PLIST);
  _BuildingNameFrame->setScale9Enabled(true);
  _BuildingNameFrame->setCapInsets(cocos2d::Rect(50, 26, 92, 4));
  _BuildingNameFrame->setContentSize(Size(192, 56));
  addChild(_BuildingNameFrame);

  _BuildingNameFrame->setPosition(Vec2(0, 165));
  _LabelBuildName = ui::Text::create();
  _LabelBuildName->setFontSize(22);
  _LabelBuildName->setColor(Color3B(208, 181, 126));
  _LabelBuildName->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _BuildingNameFrame->addChild(_LabelBuildName);
  _LabelBuildName->setAnchorPoint(Vec2(0.5, 0.5));
  _LabelBuildName->setPosition(Vec2(100, 28));
  // local starSingle = SoraDCreatePanel("masteryStarSingle")
  // starSingle:addTo(self.circleFrameBg)
  // starSingle:setPosition(cc.p(self.circleFrameBg:getContentSize().width / 2, 130))
  // starSingle:setVisible(false)
  // self.starSingle = starSingle
  // premiumStoreCtrl:sendOpenPage()
  // SoraDShowLoading(self)
}

void UIBuildingTipPanel::SetRelyBuildBtnId(int32 p_Tag){
  _RelyBuildBtnId = p_Tag;
}

void UIBuildingTipPanel::SetRelyBuildUId(int32 p_Tag){
  _RelyBuildUId = p_Tag;
}

void UIBuildingTipPanel::SetRelyBuildCfgId(EBuilding p_Building){
  _RelyBuildCfgId = p_Building;
}

void UIBuildingTipPanel::SetRelyBuildIid(EBuildingIndex p_Index){
  _RelyBuildIid = p_Index;
}

void UIBuildingTipPanel::SetRelyBuildEntity(IBuilding *p_Building){
  _RelyBuildEntity = p_Building;
}

void UIBuildingTipPanel::InitView(){
  if(_CircleFrameBg)
    _CircleFrameBg->setPosition(0, -_CircleRadius + 50 + _CircleOffsetY);
  if(_BuildingNameFrame)
    _BuildingNameFrame->setScaleX(0.1f);
  RecycleAllBtns();
  stopAllActionsByTag(tag_act_tip_show_end);
  stopAllActionsByTag(tag_act_init_view);
  auto l_Seq = Sequence::create(
    DelayTime::create(TIME_DELAY_INIT),
    CallFunc::create([this](){
      DelayInitView();
    }),
    nullptr
  );
  l_Seq->setTag(tag_act_init_view);
  runAction(l_Seq);
}

void UIBuildingTipPanel::RecycleAllBtns(){}

void UIBuildingTipPanel::DelayInitView(){
  if(this->_RelyBuildCfgId == EBuilding::None)
    return;
  auto lRelyBuildData = FactionCtrl::Get()->getCityBuildTipsInfo(_RelyBuildCfgId);
  _LabelBuildName->setString(Translate::i18n(lRelyBuildData.BuildingName.c_str()));
  if(_LabelBuildName->getContentSize().width > 160){
    _BuildingNameFrame->setContentSize(Size(_LabelBuildName->getContentSize().width + 30, 56));
    _LabelBuildName->setPositionX(_BuildingNameFrame->getContentSize().width / 2);
  }

  if(_RelyBuildEntity == nullptr){
    if(lRelyBuildData.cityBuildingState == ECityBuildingState::Normal){
      auto lOpList = FillBtnOpList({}, lRelyBuildData.NormalOperateList);
      auto lButtonList = GetButtonArrayByOpList(lOpList);
      RearrangeBtnByCircle(lButtonList);
    }
    return;
  }

  auto lIdBuilding    = _RelyBuildEntity->GetBuildingId();
  auto lBuildingIndex = _RelyBuildEntity->GetBuildingIndex();
  auto lBuildType     = BuildingLib::Get()->DGetBuildTypeByBid(lIdBuilding);
  auto lBuildingState = _RelyBuildEntity->GetState();
  
  if(lBuildingState == EBuildingState::Building){
    if(!_RelyBuildEntity->GetBuildingQueue())
      lBuildingState = EBuildingState::Normal;
  }else if(lBuildingState == EBuildingState::Upgrading){
    if(!_RelyBuildEntity->GetBuildingQueue())
      lBuildingState = EBuildingState::Normal;
  }else if(lBuildingState == EBuildingState::Demolishing){
    if(!_RelyBuildEntity->GetBuildingQueue())
      lBuildingState = EBuildingState::Normal;
  }
  if(lIdBuilding == EBuilding::StarBraveStatue)
    _BuildingNameFrame->setPositionY(230);

  if(lBuildingState == EBuildingState::Normal)
    _CircleOffsetY = _CircleOffsetNormal;

  GString lOperateType = "";
  GHashMap<EBuildingTips, bool> lOpList;
  if(lBuildingState == EBuildingState::Normal){
    if(_RelyBuildEntity->IsTraining()){
      _CircleOffsetY = _CircleOffsetCooling;
      lOperateType = "TrainingOperateList";
    }else{
      lOperateType = "NormalOperateList";
      if(_RelyBuildEntity && _RelyBuildEntity->GetBuildingLvl() >= GBase::Const::Get()->CASTLE_MAXLV_NOWAR){
        lOpList[EBuildingTips::OpUpgrade] = false;
        if(CityLtCtrl::Get()->IsOpenWL(lIdBuilding) && !BuildingLogic::Get()->BuildLvIsFull(lIdBuilding, lBuildingIndex)){
          lOpList[EBuildingTips::OpWar] = true;
        }
        if(!BuildingLogic::Get()->IsBuildingUnlock(lIdBuilding, lBuildingIndex) || BuildingLogic::Get()->BuildLvIsFull(lIdBuilding, lBuildingIndex)){
          lOpList[EBuildingTips::OpWar] = false;
        }
      }
      if(_RelyBuildEntity && BuildingLogic::Get()->BuildLvIsFull(lIdBuilding, lBuildingIndex)){
        if(_RelyBuildEntity && BuildingLogic::Get()->BuildLvIsFull(lIdBuilding, lBuildingIndex)){
          lOpList[EBuildingTips::OpUpgrade] = false;
        }
      }
    }
    
    auto lCastleBcell = CityCtrl::Get()->GetBuildingCell(EBuilding::Castle, EBuildingIndex::None);
    if(lIdBuilding == EBuilding::LeisureHouse){
      if(lCastleBcell->_Info.buildingLvl >= GBase::Const::Get()->CASTLE_MAXLV_NOWAR){
        lOpList[EBuildingTips::OpBadgeBourse] = true;
      }
      lOpList[EBuildingTips::OpFriend] = true;
      if(ClientEventMgr::Get()->JudgeIsOpen(EActivityTime::EXOTIC_PAVILION_ACTIVITY)){
        lOpList[EBuildingTips::OpForeignPavilion] = true;
      }
    }

    if(lIdBuilding == EBuilding::Castle){
      auto lRet = PrivilegeGiftCtrl::Get()->GetCurCanBuyRechargeID();
      auto lStarRet = PrivilegeGiftCtrl::Get()->GetCurStarLvCanBuyRechargeID();
      if(lRet.size() > 0)
        lOpList[EBuildingTips::OpCityGift] = true;
      if(lStarRet.size() > 0)
        lOpList[EBuildingTips::OpCityGift] = true;
    }
    if(lIdBuilding == EBuilding::Prison && GBase::Const::Get()->IsArClient){
      lOpList[EBuildingTips::OpMonument] = true;
    }
    
    auto lIsJoinAlliance = AllianceManager::Get()->HasJoinAlliance();
    auto lDepotBcell = CityCtrl::Get()->GetBuildingCell(EBuilding::Depot, EBuildingIndex::None);

    if(
      lIdBuilding == EBuilding::Depot 
      && lDepotBcell->_Info.buildingLvl >= GBase::Const::Get()->DEPOT_LV_ALLIANCE_TRRASURE 
      && lIsJoinAlliance){
      lOpList[EBuildingTips::OpAllianceTreasure] = true;
    }

    if(lIdBuilding == EBuilding::ResurrectionHall){
      if(LordInfoCtrl::Get()->GetBaseInfo().bIsSrcKingdomWarEnabled){
        lOpList[EBuildingTips::OpResuscitate] = true;
      }
    }
    
    if(lIdBuilding == EBuilding::CargoShip){
      lOpList[EBuildingTips::OpPremiumVipMall] = true;
    }
    if(lIdBuilding == EBuilding::HallOfWar && GBase::DIsMilitaryFOpen()){
      lOpList[EBuildingTips::OpMilitaryFortress] = true;
    }

    if(lBuildType == EBuildingPlace::Outer){
      auto lBid = lIdBuilding;
      if(lBid == EBuilding::Farm || lBid == EBuilding::LumberMill || lBid == EBuilding::IronMine || lBid == EBuilding::SilverMine || lBid == EBuilding::CrystalMine){
        auto lBoostToolNum = _RelyBuildEntity->GetBoostToolNum(lBid);
        if(lBoostToolNum > 0 && !_RelyBuildEntity->GetHasBuff()){
          lOpList[EBuildingTips::OpBoostByTool] = true;
        }
      } else if(lBid == EBuilding::FirstAidTent && _RelyBuildEntity->IsTraining() && GetHasAnySpeedUpTool()){
        lOpList[EBuildingTips::OpSpeedUpByTool] = true;
      }
    }else if(lBuildType == EBuildingPlace::Inner && _RelyBuildEntity->IsTraining() && GetHasAnySpeedUpTool()){
      lOpList[EBuildingTips::OpSpeedUpByTool] = true;
    }

  } else if(lBuildingState == EBuildingState::Building){
    lOperateType = "CoolingOperateList";
    if(GetHasAnySpeedUpTool()){
      lOpList[EBuildingTips::OpSpeedUpByTool] = true;
    }
    _CircleOffsetY = _CircleOffsetCooling;
    auto lButtonList = GetButtonArrayByOpList(lOpList);
    RearrangeBtnByCircle(lButtonList);
    _ButtonList = lButtonList;
  } else if(lBuildingState == EBuildingState::Upgrading){
    lOperateType = "CoolingOperateList";
    if(GetHasAnySpeedUpTool()){
      lOpList[EBuildingTips::OpSpeedUpByTool] = true;
    }
    if(lIdBuilding == EBuilding::Castle){
      auto lRet = PrivilegeGiftCtrl::Get()->GetCurCanBuyRechargeID();
      if(lRet.size() > 0)
        lOpList[EBuildingTips::OpCityGift] = true;
    }

    if(lIdBuilding == EBuilding::Depot){
      auto lIsJoinAlliance = AllianceManager::Get()->HasJoinAlliance();
      auto lDepotBcell = CityCtrl::Get()->GetBuildingCell(EBuilding::Depot, EBuildingIndex::None);
      if(lDepotBcell->_Info.buildingLvl >= GBase::Const::Get()->DEPOT_LV_ALLIANCE_TRRASURE && lIsJoinAlliance){
        lOpList[EBuildingTips::OpAllianceTreasure] = true;
      }
    }
    if(lIdBuilding == EBuilding::HallOfWar && GBase::DIsMilitaryFOpen()){
      lOpList[EBuildingTips::OpMilitaryFortress] = true;
    }
    _CircleOffsetY = _CircleOffsetCooling;
  } else if(lBuildingState == EBuildingState::Demolishing){
    lOperateType = "CoolingOperateList";
    if(GetHasAnySpeedUpTool()){
      lOpList[EBuildingTips::OpSpeedUpByTool] = true;
    }
    _CircleOffsetY = _CircleOffsetCooling;
  } else {
    return;
  }
  
  if(lIdBuilding == EBuilding::Wall){
    auto lRet = PrivilegeGiftCtrl::Get()->GetCurWallGiftRechargeID();
    if(lRet.size() > 0)
      lOpList[EBuildingTips::OpCityLevelGift] = true;
  } 

  if(!GBase::Const::Get()->IsArClient && CheckBuildMastery(lIdBuilding, lBuildingState)){
    lOpList[EBuildingTips::OpMastery] = true;
  }
  if(lIdBuilding == EBuilding::CargoShip && CheckExclusiveVip()){
    lOpList[EBuildingTips::OpExclusiveVip] = true;
  }
  if(lIdBuilding == EBuilding::Blacksmith){
    lOpList[EBuildingTips::OpArtifact] = true;
  }
  if(lIdBuilding == EBuilding::MagicLamp){
    //   local breakQueue, classQueue, strengthQueue = buildEntity:getCoolingQueue()
    //   if breakQueue ~= nil then
    //     OpList[BOP_NAME.BOP_MAGICLAMP_BREAK] = true
    //   end
    //   if classQueue ~= nil then
    //     OpList[BOP_NAME.BOP_MAGICLAMP_CLASS] = true
    //   end
    //   if strengthQueue ~= nil then
    //     OpList[BOP_NAME.BOP_MAGICLAMP_STRENGTH] = true
    //   end
  }
  // local guideCtrl = SoraDGetCtrl("guideCtrl")
  // if commonCheck.BUILD_STAR and (buildBid == BUILDID.CASTLE or not guideCtrl:isGuideNotCompleted(gGuideModule.CITY_STAR_LV)) then
  //   local isFullLv = buildLogic.buildStarLvIsFull(buildBid, iid)
  //   local isUnlock = buildLogic.isBuildingStarUnlock(buildBid, iid)
  //   local isOpenStar = cityltCtrl.isOpenStar(buildBid)
  //   local isEnoughLv = buildEntity:getBuildLv() >= CASTLE_LV90_LIMITED
  //   if tonumber(buildBid) == BUILDID.STAR_BRAVE_STATUE then
  //     isEnoughLv = true
  //   end
  //   print("==isOpenStar,isUnlock,isEnoughLv,isFullLv==", isOpenStar, isUnlock, isEnoughLv, isFullLv)
  //   if isOpenStar and isUnlock and isEnoughLv and not isFullLv then
  //     local buildStarState = tonumber(buildEntity:getBuildStarState())
  //     if buildStarState == BUILD_STAR_STATE.NORMAL then
  //       if tonumber(buildBid) == BUILDID.STAR_BRAVE_STATUE then
  //         OpList[BOP_NAME.BOP_STATUEBRAVE] = true
  //       else
  //         OpList[BOP_NAME.BOP_STARUPGRADE] = true
  //       end
  //     elseif buildStarState == BUILD_STAR_STATE.UPGRADEING then
  //       OpList[BOP_NAME.BOP_STARSPEEDUP] = true
  //     end
  //   end
  // end
  if(lIdBuilding == EBuilding::StarBraveStatue){
    if(!GBase::DIsBrave8Level()){
      lOpList[EBuildingTips::OpWarframeForg] = false;
      lOpList[EBuildingTips::OpWarframeStoreroom] = false;
    }
    if(lOperateType == "TrainingOperateList"){
      lOpList[EBuildingTips::OpstatueBrave] = false;
      if(_RelyBuildEntity->GetQueueType() == ETask::craft_study){
        lOpList[EBuildingTips::OpWarframeForg] = false;
      }else{
        lOpList[EBuildingTips::OpProcessStudy] = false;
      }
    } else if(_RelyBuildEntity->GetBuildingStarState() == EBuildingStarState::UPGRADEING){
      lOpList[EBuildingTips::OpWarframeForg] = false;
      lOpList[EBuildingTips::OpProcessStudy] = false;
    }
  }

  lOpList = FillBtnOpList(lOpList, lOperateType);

  if(lBuildingState == EBuildingState::Normal){
    auto lBID = lIdBuilding;
    if(WorldMapDefine::Get()->IsInWarForbidSoldier(true)){
      if(
        lBID == EBuilding::Stable 
        || lBID == EBuilding::TargetRange 
        || lBID == EBuilding::ChariotPlant 
        || lBID == EBuilding::Barrack 
        || lBID == EBuilding::Fortress 
        || lBID == EBuilding::ElitePalace){
          lOpList.erase(EBuildingTips::OpSpeedUpByGold);
          lOpList.erase(EBuildingTips::OpSpeedUpByTool);
        } else if(lBID == EBuilding::Market){
          lOpList.erase(EBuildingTips::OpTrade);
        }
    }else if(WorldMapDefine::Get()->IsInLegendLord() && lBID == EBuilding::Market){
      lOpList.erase(EBuildingTips::OpTrade);
    }
    if(WorldMapDefine::Get()->IsInRadiance() && lBID == EBuilding::FirstAidTent){
      lOpList.erase(EBuildingTips::OpSpeedUpByGold);
    }
    if(lBID == EBuilding::Embassy && WorldMapDefine::Get()->InInCrossWar()){
      lOpList.erase(EBuildingTips::OpIntetior);
    }
  }
  lOpList.erase(EBuildingTips::OpMeteorMagic);
  
  auto l_ButtonList = GetButtonArrayByOpList(lOpList);
  RearrangeBtnByCircle(l_ButtonList);
  _ButtonList = l_ButtonList;
}

GHashMap<EBuildingTips, bool>
UIBuildingTipPanel::FillBtnOpList(GHashMap<EBuildingTips, bool> pOpList, const GString &pBaseConfig){
  auto lRelyBuildData = FactionCtrl::Get()->getCityBuildTipsInfo(_RelyBuildCfgId);
  //pOpList should remove all false values
  if(pBaseConfig == "NormalOperateList")
    return FillBtnOpList(pOpList, lRelyBuildData.NormalOperateList);
  if(pBaseConfig == "CoolingOperateList")
    return FillBtnOpList(pOpList, lRelyBuildData.CoolingOperateList);
  if(pBaseConfig == "TrainingOperateList")
    return FillBtnOpList(pOpList, lRelyBuildData.TrainingOperateList);
  return pOpList;
}

GHashMap<EBuildingTips, bool>
UIBuildingTipPanel::FillBtnOpList(GHashMap<EBuildingTips, bool> pOpList, GVector<EBuildingTips> pBaseConfig){
  for(auto lOneOp : pBaseConfig){
    pOpList[lOneOp] = true;
  }
  
  for(auto lOneOp : pOpList.Keys()){
    if(!pOpList[lOneOp])
      pOpList.erase(lOneOp);
  }
  for(auto lOneOp : pOpList.Keys()){
    auto lUnlockLv = FunUnlockRead::Get()->GetLvByOpName(lOneOp);
    if(lUnlockLv > GBase::DGetCastleLv())
      pOpList.erase(lOneOp);
  }
  return pOpList;
}

GVector<UIBuildingTipButton *>
UIBuildingTipPanel::GetButtonArrayByOpList(GHashMap<EBuildingTips, bool> pTipsHash){
  GVector<UIBuildingTipButton *> lArrButtonList;
  // local arrOpList = {}
  // for k, v in pairs(opList) do
  //   table.insert(arrOpList, {OpName = k, btnId = v})
  // end
  auto lArrOpList = pTipsHash.Keys();
  std::sort(lArrOpList.begin(), lArrOpList.end(), [](EBuildingTips lhs, EBuildingTips rhs){
    auto lLhsData = FactionCtrl::Get()->GetBuildTipButtonCfgById(lhs);
    auto lRhsData = FactionCtrl::Get()->GetBuildTipButtonCfgById(rhs);
    return 0;
    if(GBase::DFIsRA()){
      return (int)lLhsData.OpSortIndex - (int)lRhsData.OpSortIndex;
    }else{
      return (int)lRhsData.OpSortIndex - (int)lLhsData.OpSortIndex;
    }
  });

  for(auto l_OneTip : lArrOpList){
    lArrButtonList.emplace_back(CreateButtonByOpType(l_OneTip));
  }
  
  return lArrButtonList;
}

UIBuildingTipButton *UIBuildingTipPanel::CreateButtonByOpType(EBuildingTips p_Tip){
  //   local buildTipButtonNode
  // if #self.tbBtnNotUse > 0 then
  //   buildTipButtonNode = table.remove(self.tbBtnNotUse, #self.tbBtnNotUse)
  // else
  //   local buildTipButton = include("buildTipButton")
  //   buildTipButtonNode = buildTipButton.new(getCCSPath("buildTipButton"))
  //   buildTipButtonNode:addTo(self, 1)
  // end
  // buildTipButtonNode:initWithData(opType)
  // table.insert(self.tbBtnInuse, buildTipButtonNode)
  // return buildTipButtonNode
  auto l_buildTipButtonNode = UIBuildingTipButton::Create();
  addChild(l_buildTipButtonNode, 1);
  l_buildTipButtonNode->InitWithData(p_Tip, _RelyBuildEntity);
  return l_buildTipButtonNode;
}

void UIBuildingTipPanel::RearrangeBtnByCircle(GVector<UIBuildingTipButton *> p_BtnList){
  auto l_NumberOfBtns = (int32) p_BtnList.size();
  auto l_Sep = 6;
  if(l_NumberOfBtns >= 4)
    l_Sep = 7;
  auto l_DeltaAngle = 180 / l_Sep;
  auto l_DeltaAngleRadius = CC_DEGREES_TO_RADIANS(l_DeltaAngle);
  auto l_BeginAngleRadius = -M_PI + (M_PI - l_DeltaAngleRadius * (l_NumberOfBtns - 1)) / 2;

  for(int32  i = 1; i <= l_NumberOfBtns ;i++){
    float l_ItemAngleRad = l_BeginAngleRadius + (i -1) * l_DeltaAngleRadius;
    float l_XPosBegin = std::cos(l_ItemAngleRad) * _CircleRadius / 2;
    float l_yPosBegin = std::sin(l_ItemAngleRad) * _CircleRadius / 2 + _CircleOffsetY;
    float l_XPosEnd = std::cos(l_ItemAngleRad) * _CircleRadius;
    float l_YPosEnd = std::sin(l_ItemAngleRad) * _CircleRadius + _CircleOffsetY;
    p_BtnList[i - 1]->setPosition({l_XPosBegin, l_yPosBegin});
    p_BtnList[i - 1]->setScale(0.5);
    p_BtnList[i - 1]->setLocalZOrder(l_NumberOfBtns - i + 1);
    auto l_ScaleAction = ScaleTo::create(ACTION_TIME, 1);
    auto l_MoveToAction = MoveTo::create(ACTION_TIME, {l_XPosEnd, l_YPosEnd});
    auto l_SpawnAction = Spawn::create(
      l_MoveToAction, l_ScaleAction, nullptr
    );
    l_SpawnAction->setTag(tag_act_single_btn);
    p_BtnList[i - 1]->stopAllActionsByTag(tag_act_single_btn);
    p_BtnList[i - 1]->runAction(l_SpawnAction);
    p_BtnList[i - 1]->setVisible(true);
  }
  
  if(_CircleFrameBg){
    _CircleFrameBg->stopAllActions();
    _CircleFrameBg->setPosition({0, -_CircleRadius + 50 + _CircleOffsetY});
    _CircleFrameBg->runAction(MoveBy::create(ACTION_TIME, {0, -30}));
  }

  if(_BuildingNameFrame){
    _BuildingNameFrame->stopAllActions();
    _BuildingNameFrame->setScaleX(0.1f);
    _BuildingNameFrame->runAction(ScaleTo::create(ACTION_TIME, 1));
  }
  
  stopAllActionsByTag(tag_act_tip_show_end);
  auto l_Delay = DelayTime::create(ACTION_TIME + 0.02f);
  auto l_CallFun = CallFunc::create([](){
      //   self:buildTipShowEnd()
  });
  auto l_SeqAct = Sequence::create(
    l_Delay, l_CallFun, nullptr
  );

  l_SeqAct->setTag(tag_act_tip_show_end);
  runAction(l_SeqAct);
  auto l_Mid = std::ceil((float)l_NumberOfBtns/2.f);
  if(l_Mid > 1){
    for(int32 iii = 1; iii <= l_NumberOfBtns; iii++){
      p_BtnList[iii - 1]->setLocalZOrder(l_NumberOfBtns - std::abs(iii - l_Mid));
    }
  }
}

void UIBuildingTipPanel::HideTip(){
  stopAllActionsByTag(tag_act_tip_show_end);
  setVisible(false);
  RecycleAllBtns();
}

bool UIBuildingTipPanel::CheckBuildMastery(EBuilding pBuildingID, EBuildingState pState){
  return false;
}

bool UIBuildingTipPanel::CheckExclusiveVip(){
  return false;
}

bool UIBuildingTipPanel::GetHasAnySpeedUpTool(){
  return true;
}