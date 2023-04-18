#include "BuildingTips.Handle.h"
#include <memory>
#include "Module/Building/IBuilding.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/City/City.Func.h"
#include "Module/UI/Part/City/Building/UIBuildingTipButton.h"

#include "Module/UI/Panel/Common/SpeedUp/UICommonSpeedUpBox.h"
#include "Module/UI/Panel/Common/SpeedUp/UICommonSpeedUpByItemBox.h"

#include "Module/UI/Panel/Building/Common/Info/UIBuildingInfoPanel.h"
#include "Module/UI/Panel/Building/Common/Info/UIBuildingStarUpgradePanel.h"
#include "Module/UI/Panel/Building/Common/Info/UIBuildUpgradeStatueBrave.h"
#include "Module/UI/Panel/Building/Common/Train/UISoldiersCampView.h"
#include "Module/UI/Panel/Building/Market/UIMarketNoAlliance.h"
#include "Module/UI/Panel/Building/Market/UITradeBoardView.h"
#include "Module/UI/Panel/Building/Market/UINewTradeBoardView.h"
#include "Module/UI/Panel/Building/Collage/UICollageView.h"
#include "Module/UI/Panel/Building/Embassy/UIEmbassyView.h"
#include "Module/UI/Panel/Building/Embassy/UIReinforcementsView.h"
#include "Module/UI/Panel/Building/TreasureHunt/UITreasureHuntView.h"
#include "Module/UI/Panel/Building/TreasureHunt/UIEndlessTreasureView.h"
#include "Module/UI/Panel/Building/Wall/UIDefend.View.h"
#include "Module/UI/Panel/Building/WatchTower/UIWatchTower.View.h"
#include "Module/UI/Panel/Building/CityInfo/UICityInfo.View.h"
#include "Module/UI/Panel/Building/CityInfo/UICityBuff.View.h"
#include "Module/UI/Panel/Building/Hospital/UIHospital.View.h"
#include "Module/UI/Panel/Building/Hospital/UIResurgenceTree.View.h"
#include "Module/UI/Panel/Building/Hospital/UILifeSprings.View.h"
#include "Module/UI/Panel/Building/BlackSmith/UISmithy.View.h"
#include "Module/UI/Panel/Building/BlackSmith/StorageBox/UIStorageBox.View.h"
#include "Module/UI/Panel/Building/LeisureCenter/Pyramid/UIPyramid.View.h"
#include "Module/UI/Panel/Building/LeisureCenter/Pyramid/UIBadgeBourse.View.h"
#include "Module/UI/Panel/Building/Arena/UIArenaReady.View.h"
#include "Module/UI/Panel/Building/Castle/UICastleChange.View.h"
#include "Module/UI/Panel/Building/PetCenter/UIPet.View.h"
#include "Module/UI/Panel/Building/PetCenter/UIPetMap.View.h"
#include "Module/UI/Panel/Building/PetCenter/UIPetExchange.View.h"
#include "Module/UI/Panel/Building/War/WarGem/UIWarGem.View.h"
#include "Module/UI/Panel/Building/War/WarTech/UIWarTech.View.h"
#include "Module/UI/Panel/Building/WarHall/UIMilitaryFortressMain.View.h"
#include "Module/UI/Panel/Building/StarBraveStatue/UIProcessStudy.View.h"
#include "Module/UI/Panel/Building/StarBraveStatue/UIWarframeForg.View.h"
#include "Module/UI/Panel/Building/StarBraveStatue/UIWarframeStoreroom.h"

#include "Module/UI/Panel/Alliance/Member/UIAllianceMemberList.h"
#include "Module/UI/Panel/Alliance/AllianceWar/UIAllianceWar.View.h"
#include "Module/UI/Panel/Alliance/StoreHouse/UIAllianceStoreHouse.View.h"
#include "Module/UI/Panel/Alliance/CounterSys/UIAllianceCounterSys.View.h"
#include "Module/UI/Panel/Alliance/Create/UIAllianceJoin.View.h"
#include "Module/UI/Panel/Hero/Monument/UIHeroMonument.View.h"
#include "Module/UI/Panel/Hero/Train/UIHeroTrainList.View.h"
#include "Module/UI/Panel/Hero/Jail/UIHeroJailList.View.h"
#include "Module/UI/Panel/Legend/Monument/UILegendM.View.h"
#include "Module/UI/Panel/Interior/UIIntetiorMain.View.h"
#include "Module/UI/Panel/Lord/Rank/UIMilitaryRankSkill.View.h"
#include "Module/UI/Panel/View/Friend/UIFriend.View.h"
#include "Module/UI/Panel/View/Recharge/UIRecharge.View.h"
#include "Module/UI/Panel/View/Recharge/UIRechargeCastleGift.View.h"
#include "Module/UI/Panel/View/Recharge/UIRechargeStarCastleGift.View.h"
#include "Module/UI/Panel/View/Recharge/UIRechargeVipFrame.h"
#include "Module/UI/Panel/View/Quest/UIQuest.View.h"
#include "Module/UI/EventCenter/EventTemplate/ExclusiveVip/UIExclusiveVip.View.h"

BuildingTipsHandle *BuildingTipsHandle::Get(){
  static auto l_Inst = new BuildingTipsHandle();
  return l_Inst;
}

void BuildingTipsHandle::Handle(
  UIBuildingTipButton* p_Ref, ui::Widget::TouchEventType p_Touch,
  EBuildingTips p_Op){
    ButtonUpgradeCall(p_Ref, p_Touch);
    return;
  switch (p_Op)
  {
    case EBuildingTips::OpDetails: ButtonInfoCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpUpgrade: ButtonUpgradeCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpStarUpgrade: ButtonStarUpgradeCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpTrain: ButtonTrainCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpTrade: ButtonTradeCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpAuction: ButtonAuctionCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpResearch: ButtonResearchCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpBuild: ButtonBuildTrapCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpHelp: ButtonHelpCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpReinforcements: ButtonReinforcementsCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWish: ButtonWishCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpEndlessTreasure: ButtonETreasureCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpAllianceBattle: ButtonAllianceBattleCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpDefend: ButtonDefendCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMilitaryInfo: ButtonMilitaryInfoCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCityInfo: ButtonCityInfoCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCityBuff: ButtonCityBuffCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpHeal: ButtonHealCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCollect: ButtonCollectCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpForging: ButtonForgingCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpStoragebox: ButtonStorageBoxCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpBoost: ButtonBoostCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpBoostByTool: ButtonBoostByToolCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPyramid: ButtonPyramidCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpAllianceTreasure: ButtonAllianceTreasureCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpArena: ButtonArenaCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpDiscuss: ButtonDiscussCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpSupport: ButtonSupportCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpInfoCenter: ButtonInfoCenterCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMonument: ButtonMonumentCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpTrainHall: ButtonTrainHallCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMonumentLegend: ButtonMonumentLegendCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpIntetior: ButtonIntetiorCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpExclusiveVip: ButtonVipCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPrison: ButtonPrisonCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMastery: ButtonMasteryCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMainMastery: ButtonMainMasteryCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpDrawing: ButtonDrawingCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpFriend: ButtonFriendCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpBadgeBourse: ButtonBadgeBourseCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCityDecorate: ButtonCityDecorateCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCityGift: ButtonCityGiftCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWar: ButtonWarCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMilitaryPoint: ButtonMilitaryPointCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpCounterSys: ButtonCounterSysCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpDailySign: ButtonDailySignCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMonthGift: ButtonMonthGiftCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpResuscitate: ButtonResuscitateCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpDailyReward: ButtonDailyRewardCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPet: ButtonPetCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPetMap: ButtonPetMapCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPetExchange: ButtonPetExchangeCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpSpringOfLife: ButtonSpringOfLifeCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpPremiumVipMall: ButtonPremiumVipMallCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWarGem: ButtonWarGemCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWarTechnology: ButtonWarTechnologyCall(p_Ref, p_Touch); break;
    // case EBuildingTips::OpGodE: ButtonGodEquipmentCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpArtifact: ButtonArtifactCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpStarSpeedUp: ButtonStarSpeedUpCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpProcessStudy: ButtonProcessStudyCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWarframeForg: ButtonWarframeForgCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpWarframeStoreroom: ButtonWarframeStoreroomCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpstatueBrave: ButtonUpStatueBraveCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpMilitaryFortress: ButtonMilitaryFortressCall(p_Ref, p_Touch); break;
    case EBuildingTips::OpForeignPavilion: ButtonForeignPavilionCall(p_Ref, p_Touch); break;
    
    default:
    ButtonUnDefinedCall(p_Ref, p_Touch);
      break;
  }
}


void BuildingTipsHandle::ButtonInfoCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != ui::Widget::TouchEventType::ENDED)
    return;
  if(p_Ref->_BuildEntity->GetBuildingId() == EBuilding::StarBraveStatue){
  //     local panel = SoraDCreatePanelByFixName("buildStatueBraveInfoPanel")
  //     panel:initData({
  //       bid = self.relyBuildCfgId,
  //       iid = self.relyBuildIid,
  //       btype = SoraDGetBuildTypeByBid(self.relyBuildCfgId),
  //       bstate = self:getBuildState(),
  //       buildEntity = self.relyBuildEntity
  //     })
  //     panel:show()
  } else {
    auto l_Panel = UIBuildingInfoPanel::Create();
    l_Panel->InitData(p_Ref->_BuildEntity->GetBuildingIndex(), p_Ref->_BuildEntity);
    l_Panel->Show();
    std::unique_ptr<RDoOffestMoveParam> Param(new RDoOffestMoveParam());
    Param->_OffsetType = EMainCityViewOffsetType::Building;
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_OFFSET_BUILD", Param.get());
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonUpgradeCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIBuildingCreateInfoPanel::Create();
  l_Panel->InitUpgradeData(p_Ref->_BuildEntity);
  l_Panel->Show();
  auto Param = RDoOffestMoveParam();
  Param._OffsetType = EMainCityViewOffsetType::Building;
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_OFFSET_BUILD", &Param);
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonStarUpgradeCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIBuildingStarUpgradePanel::Create();
  l_Panel->InitUpgradeStarData(p_Ref->_BuildEntity->GetBuildingIndex(), p_Ref->_BuildEntity);
  l_Panel->Show();
  //   local posX, posY = buildLogic.getBuildStarJumpOffset(self.relyBuildBtnId)
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //     offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD,
  //     xOffset = posX,
  //     yOffset = posY
  //   })
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonTrainCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UISoldiersCampView::Create();
  l_Panel->InitData(p_Ref->_BuildEntity->GetBuildingIndex(), p_Ref->_BuildEntity);
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonTradeCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    
  if(AllianceManager::Get()->HasJoinAlliance()){
    auto l_Panel = UIAllianceMemberList::Create();
    l_Panel->InitData();
    l_Panel->Show();
  }else{
    auto l_Panel = UIMarketNoAlliance::Create();
    l_Panel->Show();
  }
  GBase::DSendMessage("MESSAGE_BUILD_TRADE");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonAuctionCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    
    // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
    //   return
    // end
    // if SoraDGetCtrl("salesRoomAgCtrl"):checkOpenCond() then
    //   local guideCtrl = SoraDGetCtrl("guideCtrl")
    //   if guideCtrl:isGuideNotCompleted(gGuideModule.AUCTION_INSIDE) then
    //     SoraDCreatePanel("tradeBoardView"):show()
    //   elseif SoraDGetCtrl("activityShowCtrl"):isActivityOpen(gActivityTimeActivityID.NEW_SALESROOM_ACTIVITY) then
    //     SoraDCreatePanel("newTradeBoardView"):show()
    //   elseif SoraDGetCtrl("activityShowCtrl"):isActivityOpen(gActivityTimeActivityID.SALESROOM_ACTIVITY) then
    //     SoraDCreatePanel("tradeBoardView"):show()
    //   else
      auto l_Panel = UITradeBoardView::Create();
      l_Panel->Show();
    //     SoraDCreatePanel("newTradeBoardView"):show()
    //   end
    // end

  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonResearchCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UICollageView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonBuildTrapCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UISoldiersCampView::Create();
  l_Panel->InitData(p_Ref->_BuildEntity->GetBuildingIndex(), p_Ref->_BuildEntity);
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonHelpCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIEmbassyView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonReinforcementsCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIReinforcementsView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWishCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UITreasureHuntView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonETreasureCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // print("buttonETreasureCall Click!")
    // local unlockLv = funUnlockRead.getUnlockLevel(gFunBuildKey.ENDLESS_TREASURE)
    // if unlockLv > SoraDGetCastleLv() then
    //   SoraDShowMsgTip(i18n("common_text_2122", {
    //     name = i18n("endless_treasures_text_01"),
    //     lv = unlockLv
    //   }))
    // else
    //   local panel = SoraDCreatePanel("endlessTreasureView")
    //   panel:show()
    //   SoraDSendMessage({
    //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    //   })
    // end
  auto l_Panel = UIEndlessTreasureView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonAllianceBattleCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;

    // local allianceMgr = gametop.playertop_:getModule("allianceMgr")
    // if not allianceMgr:hasJoinAlliance(true) then
    //   SoraDShowMsgTip(i18n("common_text_3692"))
    // else
    //   SoraDCreatePanel("allianceWarView"):show()
    // end
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    // })
  auto l_Panel = UIAllianceWarView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonDefendCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIDefendView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMilitaryInfoCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIWatchTowerView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCityInfoCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UICityInfoView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCityBuffCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UICityBuffView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonHealCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // local lv = 0
  // local buildEntity = self.relyBuildEntity
  // if nil ~= buildEntity then
  //   lv = buildEntity:getBuildLv()
  // end
  // local panel = SoraDCreatePanel("hospitalView")
  auto l_Panel = UIHospitalView::Create();
 // panel:setLV(lv)
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCollectCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  if(p_Ref && p_Ref->_BuildEntity)
    p_Ref->_BuildEntity->DoHarvesting();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonForgingCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UISmithyView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonStorageBoxCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIStorageBoxView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonBoostCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonBoostByToolCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPyramidCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    //     local cityCtrl = gametop.playertop_:getModule("cityCtrl")
    // local castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
    // if not castleBcell then
    //   SoraDSendMessage({
    //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    //   })
    //   return
    // end
    // local castleLV = castleBcell.info.lv
    // if tonumber(castleLV) < CASTLE_LV8_LIMITED then
    //   local spriteName = "#btn_pyramid.png"
    //   SoraDShowMsgTip(i18n("common_text_1151", {blv = CASTLE_LV8_LIMITED}), spriteName)
    // else
    //   local pyramidView = include("pyramidView").new()
    auto l_Panel = UIPyramidView::Create();
    l_Panel->Show();
    //   pyramidView:show()
    // end
    
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonAllianceTreasureCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // if not worldMapDefine.isInWarForbid(false, true) then
    //   local gametop = gModuleMgr.getObject("gametop")
    //   local allianceMgr = gametop.playertop_:getModule("allianceMgr")
    //   local isJoinAllliance = allianceMgr:hasJoinAlliance()
    //   local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
    //   local isInConquestWar = conquestWarCtrl:isPlayerConquestWarMigration()
    //   if isInConquestWar then
    //     SoraDShowMsgTip(i18n("common_text_2166"))
    //   elseif isJoinAllliance then
    //     SoraDCreatePanel("allianceStoreHouseView"):show()
    //     userSDKManager.logEvent(gSDKDef.TDonEvent.click_alliance_treasure, {position = 1})
    //   else
    //     uiManager:show("AllianceJoinView")
    //   end
    // end

    UIAllianceJoinView::Create()->Show();
    
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonArenaCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
    //   return
    // end
    // local activityShowCtrl = gametop.playertop_:getModule("activityShowCtrl")
    // local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
    // local isOpen = activityShowCtrl:isActivityOpen(gActivityTimeActivityID.ARENA_ACTIVITY)
    // if lordInfoCtrl:getSourceKid() > 0 then
    //   SoraDShowMsgTip(i18n("common_text_3041"))
    // elseif worldMapDefine.isInWarForbid(false, true) then
    // elseif not isOpen then
    //   SoraDShowMsgTip(i18n("common_text_699"))
    // else
    //   local unlockLv = funUnlockRead.getUnlockLevel(gFunBuildKey.ARENA)
    //   if unlockLv <= SoraDGetCastleLv() then
    //     local kingdomCtrl = gametop.playertop_:getModule("kingdomCtrl")
    //     if kingdomCtrl:getCanMoveOut(gametop.playertop_:getKingdomID()) then
    //       SoraDShowMsgTip(i18n("migrate_notice_05"))
    //     else
    //       local panel = SoraDCreatePanel("arenaReadyView")
    //       panel:show()
    //     end
    //   else
    //     SoraDShowMsgTip(i18n("common_text_2122", {
    //       name = i18n("buildDes_name_121"),
    //       lv = unlockLv
    //     }))
    //   end
    // end

    UIArenaReadyView::Create()->Show();
    
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonDiscussCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // if userSDKManager.sdkMessageCount then
    //   userSDKManager.sdkMessageCount.bbsCount = 0
    //   userSDKManager_sdkMessageCallBack()
    // end
    // local activityCenterUICtrl = SoraDGetCtrl("activityCenterUICtrl")
    // activityCenterUICtrl:sendClearNewMsg(gActivityCenterUIEnum.MAIN_CITY_BILLBOARD)
    // userSDKManager.showSocial()
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    // })
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonSupportCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if userSDKManager.sdkMessageCount then
  //   userSDKManager.sdkMessageCount.serviceCount = 0
  //   userSDKManager_sdkMessageCallBack()
  // end
  // userSDKManager.showFAQs()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonInfoCenterCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if userSDKManager.sdkMessageCount then
  //   userSDKManager.sdkMessageCount.serviceCount = 0
  //   userSDKManager_sdkMessageCallBack()
  // end
  // if userSDKManager.isEN() then
  //   userSDKManager.openSDKLink("https://ros.onemt.com/index/home")
  // else
  //   userSDKManager.openNoticeBorad()
  // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMonumentCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if SoraDGetCastleLv() < CASTLE_LV19_LIMITED then
  //   SoraDShowMsgTip(i18n("common_text_3868", {lv = CASTLE_LV19_LIMITED}), "#btn_main_monument.png")
  // else
  //   SoraDCreatePanel("heroMonumentView"):show()
  // end
  UIHeroMonumentView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonTrainHallCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // local worldMapWarDef = include("worldMapWarDef")
  // worldMapWarDef.openHeroTrainListView()
  UIHeroTrainListView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMonumentLegendCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UILegendMView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonIntetiorCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
  //   return
  // end
  UIIntetiorMainView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonVipCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
  //   return
  // end
  UIExclusiveVipView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPrisonCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
  //   return
  // end
  UIHeroJailListView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMasteryCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // local bid = self.relyBuildCfgId
  // local iid = self.relyBuildIid
  // local mid = specializationRead.getMasteryID(bid)
  // local state = specializationRead.getMasteryState(bid, mid)
  // if state == specializationRead.MASTERY_STATE.canLock then
  //   local penal = SoraDCreatePanel("masteryMainView")
  //   penal:show()
  //   penal:doDelayAction(mid)
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //   })
  //   return
  // end
  // SoraDSendMessage({
  //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  // })
  // local mainCityFunctions = include("mainCityFunctions")
  // mainCityFunctions.masteryJumpToDetailView(bid, iid, false)
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMainMasteryCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  //SoraDCreatePanel("masteryMainView"):show()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonDrawingCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  //SoraDCreatePanel("masteryDrawView"):show()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonFriendCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UIFriendView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonBadgeBourseCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // local cityCtrl = gametop.playertop_:getModule("cityCtrl")
    // local badgeExchangeCtrl = gametop.playertop_:getModule("badgeExchangeCtrl")
    // local openLV = badgeExchangeCtrl:getOpenLv()
    // local castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
    // if not castleBcell then
    //   SoraDSendMessage({
    //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    //   })
    //   return
    // end
    // local castleLV = castleBcell.info.lv
    // if openLV > tonumber(castleLV) then
    //   local spriteName = "#301101.png"
    //   SoraDShowMsgTip(i18n("common_text_1151", {blv = openLV}), spriteName)
    // else
    //   local badgeBourseView = SoraDCreatePanel("badgeBourseView")
    //   badgeBourseView:show()
    // end
  UIBadgeBourseView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCityDecorateCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // local panel = SoraDCreatePanel("castleChangeView")
    // panel:initData()
    // panel:show()
    // local xOffset = display.size.width * 0.5
    // xOffset = xOffset + 60
    // local scale = 0.4
    // print("xOffset = ", xOffset)
    // print("display.size.height = ", display.size.height, ", yOffset = ", display.size.height - 375)
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
    //   offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD,
    //   scale = scale,
    //   xOffset = xOffset,
    //   yOffset = display.rheight - 375
    // })
  UICastleChangeView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCityGiftCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
    //   return
    // end
    // local gametop = gModuleMgr.getObject("gametop")
    // local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
    // local gift = privilegeGiftCtrl:getCurCanBuyRechargeID()
    // local starGift = privilegeGiftCtrl:getCurStarLvCanBuyRechargeID()
    // if not next(starGift) then
    //   local panel = SoraDCreatePanel("rechargeCastleGiftView")
    //   panel:initData(tonumber(gift[1]), gRechargeActiveFromEnum.ROAD15)
    //   panel:show()
    // else
    //   local panel = SoraDCreatePanel("rechargeStarCastleGiftView")
    //   panel:initData(tonumber(gift[1]), tonumber(starGift[1]), gRechargeActiveFromEnum.ROAD15)
    //   panel:show()
    // end
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    // })
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_CASTLE_GIFT_TOP_TIP"
    // })
  UIRechargeStarCastleGiftView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWallGiftCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // local gametop = gModuleMgr.getObject("gametop")
    // local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
    // local gift = privilegeGiftCtrl:getCurWallGiftRechargeID()
    // local panel = SoraDCreatePanel("rechargeWallGiftView")
    // panel:initData(tonumber(gift[1]), gRechargeActiveFromEnum.ROAD15)
    // panel:show()
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    // })
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWarCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIBuildingCreateInfoPanel::Create();
  l_Panel->InitUpgradeData(p_Ref->_BuildEntity);
  l_Panel->Show();
  // SoraDSendMessage({
  //   msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //   offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD
  // })
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMilitaryPointCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UIMilitaryRankSkillView::Create();
  l_Panel->SwitchScroll(true);
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonCounterSysCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    //  if worldMapDefine.inInCrossWar() then
    //   SoraDShowMsgTip(i18n("common_text_3302"))
    // else
    //   local panel = SoraDCreatePanel("allianceCounterSysView")
    //   panel:tabChange(2)
    //   panel:show()
    // end
  auto l_Panel = UIAllianceCounterSysView::Create();
  l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonDailySignCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    //  uiManager:show("LuckyCard")
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonMonthGiftCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    auto l_Panel = UIRechargeView::Create();
    // panel:expect2SelectTab(gRechargeCenterCategory.MONTH)
    l_Panel->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonResuscitateCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    auto l_Panel = UIResurgenceTreeView::Create();
    l_Panel->Show();
    // if self.relyBuildCfgId == BUILDID.HOSTPITAL then
    //   local cityBuildConstDef = include("cityBuildConstDef")
    //   SoraDSendMessage({
    //     msg = "MESSAGE_MAINCITYVIEW_GO_TO_BUILD",
    //     buildID = cityBuildConstDef.fixedBuildDef.ResurrectionHall,
    //     delay = 0.5,
    //     isSelected = true,
    //     isShowHand = true
    //   })
    // else
    //   if not worldMapDefine.isInWarForbid(false, false) then
    //     SoraDCreatePanel("resurgenceTreeView"):show()
    //   end
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonDailyRewardCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    auto l_Panel = UIQuestView::Create();
    l_Panel->Show();
  //   local panel = SoraDCreatePanel("questView")
  //   panel:expect2SelectTab(2)
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //   })
  // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonUnDefinedCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  //   local panel = SoraDCreatePanel("questView")
  //   panel:expect2SelectTab(2)
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //   })
  // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPetCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UIPetView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPetMapCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UIPetMapView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonSpringOfLifeCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  //  if not worldMapDefine.isInWarForbid(false, false) then
  //     SoraDCreatePanel("lifeSpringsView"):show()
  //   end
  UILifeSpringsView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPremiumVipMallCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIRechargeVipFrame::Create()->Show();
    // local clickTime = SoraDConfigGet("Game:MainCityView:clickPremiumVipMallBtn~integer", {byUID = true})
    // if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
    //   SoraDConfigSet("Game:MainCityView:clickPremiumVipMallBtn~integer", serviceFunctions.systemTime(), {byUID = true})
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWarGemCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIWarGemView::Create()->Show();
    // local clickTime = SoraDConfigGet("Game:MainCityView:clickPremiumVipMallBtn~integer", {byUID = true})
    // if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
    //   SoraDConfigSet("Game:MainCityView:clickPremiumVipMallBtn~integer", serviceFunctions.systemTime(), {byUID = true})
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWarTechnologyCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIWarTechView::Create()->Show();
    // local clickTime = SoraDConfigGet("Game:MainCityView:clickPremiumVipMallBtn~integer", {byUID = true})
    // if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
    //   SoraDConfigSet("Game:MainCityView:clickPremiumVipMallBtn~integer", serviceFunctions.systemTime(), {byUID = true})
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonGodEquipmentCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if eventType == ccui.TouchEventType.ended then
  //   if SoraDGetCastleLv() < CASTLE_LV40_LIMITED then
  //     SoraDShowMsgTip(i18n("common_text_4094", {level = 1}))
  //     return
  //   end
  //   local panel = SoraDCreatePanel("godEquipmentView")
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //   })
  // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonArtifactCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  // if eventType == ccui.TouchEventType.ended then
  //   local unlockLv = funUnlockRead.getUnlockLevel(gFunBuildKey.ARTIFACT)
  //   if unlockLv > SoraDGetCastleLv() then
  //     SoraDShowMsgTip(i18n("common_text_2417", {level = unlockLv}))
  //     return
  //   end
  //   local panel = SoraDCreatePanel("artifactInfoView")
  //   panel:initData(1)
  //   panel:show()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //   })
  // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonPetExchangeCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    //  local panel = SoraDCreatePanel("petExchangeView")
    UIPetExchangeView::Create()->Show();
    // if target.selTabIndex then
    //   panel:init({
    //     selTabIndex = target.selTabIndex
    //   })
    //   target.selTabIndex = nil
    // else
    //   panel:init()
    // end
    // panel:show()
    // SoraDSendMessage({
    //   msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    // })
    // local clickTime = SoraDConfigGet("Game:MainCityView:clickPetExchangeBtn~integer", {byUID = true})
    // if clickTime == 0 or not serviceFunctions.isSameDay(clickTime) then
    //   local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
    //   local ret = backpackCtrl:getPetPointItemList()
    //   if ret and #ret > 0 then
    //     SoraDConfigSet("Game:MainCityView:clickPetExchangeBtn~integer", serviceFunctions.systemTime(), {byUID = true})
    //   end
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonStarSpeedUpCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UICommonSpeedUpBox::Create()->Show();
  //  local buildEntity = self:getBuildEntity()
  //   local buildBid = buildEntity:getBuildBid()
  //   local iid = buildEntity:getIid()
  //   local queue
  //   for _, _queueType in ipairs({
  //     gQueueTypeDef.build_star_queue,
  //     gQueueTypeDef.build_star_queue_privilege,
  //     gQueueTypeDef.glorious_upgrade
  //   }) do
  //     local _queue = queueCtrl:queryQueue(_queueType)
  //     if _queue and tonumber(_queue.data.bid) == tonumber(buildBid) and tonumber(_queue.data.iid) == tonumber(iid) then
  //       queue = _queue
  //       break
  //     end
  //   end
  //   if queue == nil then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
  //     })
  //     return
  //   end
  //   local speedUpItemList = self:getSpeedUpItemList(queue.qtype)
  //   if #speedUpItemList > 0 then
  //     local panel = SoraDCreatePanel("commonSpeedUpByItemBox")
  //     panel:initData(queue.qtype)
  //     panel:show()
  //   else
  //     local msgDes = i18n("Glory_text_30")
  //     dump(queue.data, "queue.data")
  //     if tonumber(queue.data.bid) == BUILDID.STAR_BRAVE_STATUE then
  //       msgDes = i18n("Soldiers_armor_text_69")
  //     end
  //     SoraDShowSpeedUpBox(queue, nil, msgDes)
  //   end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonProcessStudyCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIProcessStudyView::Create()->Show();
    // panel:setBuildEntity(self.relyBuildEntity)
    // panel:initData()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonWarframeForgCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIWarframeForgView::Create()->Show();
    // panel:setBuildEntity(self.relyBuildEntity)
    // panel:initData()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}


void BuildingTipsHandle::ButtonWarframeStoreroomCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    UIWarframeStoreroom::Create()->Show();
    // panel:setBuildEntity(self.relyBuildEntity)
    // panel:initData()
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonUpStatueBraveCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UIBuildUpgradeStatueBrave::Create()->Show();
    //   panel:initUpgradeStarData({
    //   bid = self.relyBuildCfgId,
    //   iid = self.relyBuildIid,
    //   index = self.relyBuildBtnId,
    //   buildEntity = self:getBuildEntity()
    // })
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}


void BuildingTipsHandle::ButtonMilitaryFortressCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  UIMilitaryFortressMainView::Create()->Show();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

void BuildingTipsHandle::ButtonForeignPavilionCall(UIBuildingTipButton *p_Ref, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
    // if SoraDGetCastleLv() < CASTLE_LV4_LIMITED then
    //   SoraDShowMsgTip(i18n("common_text_1973", {lv = CASTLE_LV4_LIMITED}))
    //   return
    // end
    // local cityCtrl = gametop.playertop_:getModule("cityCtrl")
    // local castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
    // if not castleBcell then
    //   SoraDSendMessage({
    //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP"
    //   })
    //   return
    // end
    // if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.EXOTIC_PAVILION_ACTIVITY) then
    //   local exoticPavilionCtrl = SoraDGetCtrl("exoticPavilionCtrl")
    //   if exoticPavilionCtrl:getCurStage() == 1 and exoticPavilionCtrl:getCurStep() <= 3 then
    //     local noticeData = {
    //       {
    //         img = "girl",
    //         str = i18n("exitic_pavillion_text_0147")
    //       },
    //       {
    //         callback = function()
    //           uiManager:show("ForeignPavilionActivity")
    //         end
    //       }
    //     }
    //     gModuleMgr.sharedMgr("mildGuideManager"):createNoticeLine(noticeData)
    //   else
    //     uiManager:show("ForeignPavilionActivity")
    //   end
    // else
    //   SoraDShowMsgTip(i18n("common_text_2486"))
    // end
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP");
}

