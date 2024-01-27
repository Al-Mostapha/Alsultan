#include "CityScene.Msg.h"
#include "CityScene.View.h"
#include "Base/Base.Lib.h"
#include "Module/City/City.Func.h"
#include "Base/Common/Common.City.h"
#include "Module/UI/Part/City/Building/UIBuildingTipPanel.h"

MainCityMsg *MainCityMsg::Get(){
  static auto l_Inst = new MainCityMsg();
  return l_Inst;
}

void MainCityMsg::RegisterMessage(MainCityView *p_MainCity){
  _Self = p_MainCity;
// SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_OFFSET_BUILD", handler(self, self.setOffsetContainerWithSelectBuild))
  GBase::DAddMessage(p_MainCity, "MESSAGE_MAINCITYVIEW_OFFSET_BUILD", CC_CALLBACK_1(MainCityMsg::SetOffsetContainerWithSelectBuild, this));
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_OFFSET_BUILD_TIP", handler(self, self.setOffsetContainerWithBuildTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CREATE_BUILD", handler(self, self.createBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD", handler(self, self.removeBuild))
//   SoraDAddMessage(self, "MESSAGE_BUILD_UPGRADE", handler(self, self.upgradeBuild))
//   SoraDAddMessage(self, "MESSAGE_BUILD_WORKING", handler(self, self.workBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP", handler(self, self.addBuildTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP", handler(self, self.removeBuildTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_ANIM_WORKER", handler(self, self.addAnimWorker))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_ANIM_WORKER", handler(self, self.removeAnimWorker))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_WORK_DONE_EFFECT", handler(self, self.addBuildWorkDoneEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_WORK_DONE_EFFECT", handler(self, self.removeBuildWorkDoneEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_COOLING_PANEL", handler(self, self.addBuildCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_BUILDSTAR_COOLING_PANEL", handler(self, mainCityMsg.msgUpdateBuildStarCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_BUILDSTAR_SECOND_QUEUE_COOLING_PANEL", handler(self, mainCityMsg.msgUpdateBuildStarSecondCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_STATUEBRAVE_COOLING_PANEL", handler(self, mainCityMsg.msgUpdateBuildStatueBraveCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_MAGIC_LAMP_COOLING_PANEL", handler(self, mainCityMsg.msgUpdateBuildMagicLampCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_ENDLESSTREASURE_COOLING_PANEL", handler(self, mainCityMsg.msgUpdateEndlessTreasureCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_COOLING_PANEL", handler(self, self.removeBuildCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_STATUEBRAVE_COOLING_PANEL", handler(self, mainCityMsg.removeStarBraveStatueCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_ANIM_BOOST", handler(self, self.addBuildAnimBoost))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_ANIM_BOOST", handler(self, self.removeBuildAnimBoost))
GBase::DAddMessage(_Self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TIP", CC_CALLBACK_1(MainCityMsg::RemoveBuildTip, this));
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_OFFSET_BUILD_TIP_HAND", handler(self, self.setOffsetContainerWithBuildTipHand))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP_HAND", handler(self, self.addBuildTopTipHand))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP_HAND", handler(self, self.removeBuildTopTipHand))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_TROOP_SOLIDER", handler(self, self.addTroopSolider))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_TROOP_SOLIDER", handler(self, self.removeTroopSolider))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ENTER_MOVE_MODE", handler(self, self.enterMoveMode))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_LEAVE_MOVE_MODE", handler(self, self.leaveMoveMode))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_HARVEST_FLOATING", handler(self, self.addHarvestFloating))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_BUILD_QUEQUE_CALLBACK", handler(self, self.buildQueueCallback))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_DEMOLISH_BUILD", handler(self, self.demolishBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CANCEL_DEMOLISH_BUILD", handler(self, self.cancelDemolishBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CANCEL_UPGRADE_BUILD", handler(self, self.cancelUpgradeBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_EXCHANGE_BUILD", handler(self, self.exchangeBuild))
GBase::DAddMessage(_Self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_PREVIEW",CC_CALLBACK_1(MainCityMsg::AddBuildPreview, this));
GBase::DAddMessage(_Self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_PREVIEW", CC_CALLBACK_1(MainCityMsg::RemoveBuildPreview, this));
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_HARVEST_ARMY_RESULT", handler(self, self.showHarvestArmyResult))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_BUILD_BTN_EVENT", handler(self, self.buildBtnEvent))
//   SoraDAddMessage(self, "MESSAGE_SERVER_MAINCITYVIEW_ARMY_QUEUE_CALLBACK", handler(self, self.armyQueueCallback))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_SOLDIER_MATRIXS", handler(self, self.updateSoldierMatrixs))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UNLOCK_AREA", handler(self, self.msgUnLockArea))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_LOCK_AREA", handler(self, self.msgUpdateLockArea))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_ALLIANCE_HELP_LIST", handler(self, self.msgUpdateAllianceHelpList))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SAVE_MAIN_CITY_POS", handler(self, self.msgSaveMainCityPos))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_MATOU_TIP", handler(self, self.addMatouTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_EFFECT", handler(self, self.msgAddBuildEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_EFFECT", handler(self, self.msgRemoveBuildEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_EFFECT_UPGRADE", handler(self, self.msgAddBuildEffectUpgrade))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_DELETE_MATOU_TIP", handler(self, self.removeMatouTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_WALL_VIEW", handler(self, self.msgUpdateWallView))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_WALL_EFFECT", handler(self, self.msgUpdateWallEffect))
//   SoraDAddMessage(self, "MESSAGE_TIME_RECEIVEREWARD_SUCCESS", handler(self, self.msgReceiveOnlineBack))
//   SoraDAddMessage(self, "MESSAGE_TIME_RECEIVEREWARD_CANRECEIVE", handler(self, self.initMatouData))
//   SoraDAddMessage(self, "MESSAGE_CANCLE_TECHNOLOGY", handler(self, self.sMsgCancelTechnology))
//   SoraDAddMessage(self, "MESSAGE_DAILYLOGIN_NOTIFY_DAILYREWARD", handler(self, self.initWithHuoChuangData))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_GO_TO_BUILD", handler(self, self.gotoBuild))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_MOVE_CAMERA_TO", handler(self, self.msgMoveCameraTo))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_BUILD_TIP_BOX", handler(self, self.msgAddBuildTipBox))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HIDE_BUILD_TIP_BOX", handler(self, self.msgHideBuildTipBox))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_BUILD_TIP_BOX", handler(self, self.msgUpdateBuildTipBox))
//   SoraDAddMessage(self, "MESSAGE_SERVER_UPDATE_IDLE_GUIDE", handler(self, self.updateIdlePop))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_LORD_SKILL_EFFECT", handler(self, self.showLordSkillEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_WEATHER_NOTIFY_MSG", handler(self, self.weatherEffect))
//   SoraDAddMessage(self, "MESSAEG_MANCITYYVIEW_SHOW_TURRET_LOCK", handler(self, self.msgShowTurretLock))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HDIE_TURRET_LOCK", handler(self, self.msgHideTurretLock))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_BUILD_LOCK", handler(self, self.msgShowBuildLock))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HIDE_BUILD_LOCK", handler(self, self.msgHideBuildLock))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_COMMUNITYCENTER_MSG", handler(self, self.msgShowCommunityCenterMsg))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HIDE_COMMUNITYCENTER_MSG", handler(self, self.msgHideCommunityCenterMsg))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_FIRST_FIGHT_END", handler(self, self.msgFirstFightEnd))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CLEAN_FIRST_FIGHT", handler(self, self.msgCleanFirstFight))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYGUIDE_ALLEND", handler(self, self.msgCleanMainCityGuide))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_GUARD_SOLDIER_BOX", handler(self, self.msgUpdateGuardSoldierBox))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_RESET_CONTENT_VIEW", handler(self, self.msgResetContentView))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_MERCHANT_VIEW", handler(self, self.msgUpdateMerchantView))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_NEW_COLLECTITEMS", handler(self, self.msgNewCollectItems))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_CELEBRATEGIFT_REFRESH", handler(self, self.initCelebrateGift))
//   SoraDAddMessage(self, "MESSAGE_CASTLE_SKIN_CHANGE", handler(self, self.refreshCastleSkin))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_TOGGLE_DARK", handler(self, self.msgToggleDark))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_COMMUNITY_VIEW", handler(self, self.msgUpdateCommunityView))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_NIGHT_CFG", handler(self, self.msgUpdateNightCfg))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_BRAVESTATUE_VIEW", handler(self, self.msgUpdateBraveStatueView))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_NEBULA_PALACE", handler(self, self.msgUpdateBuildVisible))
//   SoraDAddMessage(self, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", handler(self, self.addHarvestEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITY_UPDATE_HARVEST_EFFECT", handler(self, self.addHarvestEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_AUTO_COLLECT_RES", handler(self, self.msgAutoCollectRes))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHAKE_CONTROL", handler(self, self.msgNotifyShakeControl))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_BULLETINBOARD_MSG", handler(self, self.msgShowBulletInBoardMsg))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HIDE_BULLETINBOARD_MSG", handler(self, self.msgHideBulletInBoardMsg))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_JUMP", handler(self, self.msgJump))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_TOP_TIP_ACTIVITY", handler(self, self.msgShowTopTipActivity))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HIDE_TOP_TIP_ACTIVITY", handler(self, self.msgHideTopTipActivity))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_BOAT_TIP", handler(self, self.addBuildTopTipHuochuang))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_PET_SHOW", handler(self, self.msgUpdatePetShow))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_PET_TIP_BOX", handler(self, self.msgUpdatePetTipBox))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_PYRAMID_BATTLE_MSG", handler(self, self.msgUpdatePyramidBattle))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_MOVETO_BUILDBYBID", handler(self, self.msgOpenBuildByBid))
//   SoraDAddMessage(self, "MESSAGE_MAINSCEN_CHANGE_IMG_QUALITY", handler(self, self.msgChangeQuality))
//   SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINFINSH", handler(self, self.msgLoginFinish))
//   SoraDAddMessage(self, "MESSAGE_MAINSCEN_LUA_WILL_RELOAD", handler(self, self.msgLuaWillReload))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_NPC_TOP_TIP", handler(self, self.msgAddNpcTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_NPC_TOP_TIP", handler(self, self.msgRemoveNpcTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITY_LION_MSG", handler(self, self.msgUpdateLion))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_CASTLE_GIFT_TOP_TIP", handler(self, self.msgAddCastleGiftTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_CASTLE_GIFT_TOP_TIP", handler(self, self.msgRemoveCastleGiftTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_ENDLESSTREASURE_TOP_TIP", handler(self, self.msgUpdateEndlessTreasureTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_ENDLESSTREASURE_TOP_TIP", handler(self, self.msgRemoveEndlessTreasureTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_WAREHOUSE_GIFT_TOP_TIP", handler(self, self.msgUpdateAllianceTreasureTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_WAREHOUSE_GIFT_TOP_TIP", handler(self, self.msgRemoveAllianceTreasureTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_EPICWAR_TOP_TIP", handler(self, self.msgUpdateEpicWarTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_EPICWAR_TOP_TIP", handler(self, self.msgRemoveEpicWarTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_PROMOTE_TOP_TIP", handler(self, self.msgUpdateArmyPromoteTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_PROMOTE_TOP_TIP", handler(self, self.msgRemoveArmyPromoteTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_ADD_DRILL_ARENA_TOP_TIP", handler(self, self.msgAddArenaTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_REMOVE_DRILL_ARENA_TOP_TIP", handler(self, self.msgRemoveArenaTopTip))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_FLAG_COOLING_PANEL", handler(self, self.msgUpdateFlagCoolingPanel))
//   SoraDAddMessage(self, "MESSAGE_MAINCITY_VIEW_REMOVE_HARVEST_EFFECT", handler(self, self.msgRemoveHarvestEffect))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_HORSE_FLAG_UPDATE", handler(self, self.msgUpdateHorseFlag))
//   SoraDAddMessage(self, "MESSAGE_FILE_DOWNLOAD_SUCCESS_BY_KEY", handler(self, self.msgMainCityDownloadSuccess))
//   SoraDAddMessage(self, "MESSAGE_MAINCITY_PLAY_SOUND", handler(self, self.msgPlaySound))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_COLLECT_BATCH_RES", handler(self, self.msgCollectBatchRes))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_KIPCHAKS", handler(self, self.msgKipchaksUpdate))
//   SoraDAddMessage(self, "MESSAGE_MAINSCEN_CURRENT_SHOWVIEW_HIDED", handler(self, self.msgCurrentShowViewHided))
//   SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_SHOW_COMMANDHALL_NPC", handler(self, mainCityMsg.msgShowCommandHallNpc))
//   SoraDAddMessage(self, "MESSAGE_COMMANDHALL_INITDATA_UPDATE", handler(self, mainCityMsg.msgShowCommandHallBox))
//   SoraDAddMessage(self, "MESSAGE_COMMANDHALL_COMMITTASK_UPDATE", handler(self, mainCityMsg.msgShowCommandHallBox))
//   if IsArClient then
//   else
//     SoraDAddMessage(self, "MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_COOLING_PANEL", handler(self, self.msgUpdateMasteryCoolingPanel))
//     SoraDAddMessage(self, "MESSAGE_UPDATE_MASTERY_TOP_TIP", handler(self, self.msgUpdateMasteryTopTip))
//   end
}

void MainCityMsg::SetOffsetContainerWithSelectBuild(EventCustom *p_Event){
  // local self = mainCity
  CCASSERT(p_Event, "Event Cannot Be Null");
  CCAssert(p_Event->getUserData(), "Data cannot be null");
  auto l_Data = static_cast<RDoOffestMoveParam *>(p_Event->getUserData());
  if(l_Data->_OffsetType == EMainCityViewOffsetType::Building){

    if(_Self->_CurrentSelectBuild == nullptr && l_Data->_BuildIndex == EBuildingIndex::None)
      return;
    Node *l_Building = nullptr;
    if(l_Data->_BuildIndex != EBuildingIndex::None){
      auto l_BuildingName = "build_" + std::to_string(static_cast<int32>(l_Data->_BuildIndex));
      l_Building = _Self->GetBufferNodeByName(l_BuildingName.c_str());
    }
    if(l_Building == nullptr)
      l_Building = _Self->_CurrentSelectBuild;
    if(!l_Building){
      CCAssert(l_Building, "Error Building Is null");
      return;
    }
    _Self->_IsNeedRecover = true;
    auto l_BuildingIndex = static_cast<EBuildingIndex>(l_Building->getTag());
    auto l_BuildingType = GBase::DGetBuildingTypeByIndex(l_BuildingIndex);
    auto l_Scale = 1.3f;
    if(l_BuildingType == EBuildingPlace::Inner)
      l_Scale = 1;
    MainCityFunctions::Get()->DoOffsetContainerWithSelectBuild(_Self, l_Building, l_Scale, *l_Data);
  } else if(l_Data->_OffsetType == EMainCityViewOffsetType::LockArea){
    //   local areaid = data.areaid
    //   if areaid then
    //     local lockAreaName = "Panel_Area_Lock_" .. areaid
    //     local panelLockArea = self:getBufferNodeByName(lockAreaName)
    //     if panelLockArea then
    //       self.isNeedRecover = true
    //       self:doOffsetContainerWithSelectBuild(panelLockArea)
    //     end
    //   end
  } else if(l_Data->_OffsetType == EMainCityViewOffsetType::Recover){
    if(!_Self->_IsNeedRecover)
      return;
    auto lScale = _Self->_PreZoomScale;
    auto lOffset = _Self->_PreContainerOffset;
    _Self->SetZoomScale(lScale, true, _Self->_ZoomScaleDuration, true);
    auto lZoomScale = _Self->_ViewScrollView->getZoomScale();
    _Self->RunContainerViewMove(lOffset, _Self->_ZoomScaleDuration);
    _Self->DisableMoveForDuration(_Self->_ZoomScaleDuration);
    _Self->_IsNeedRecover = false;
  }
}

void MainCityMsg::RemoveBuildTip(EventCustom *p_Event){

  auto l_BuildingIndex = EBuildingIndex::None;
  if(p_Event && p_Event->getUserData()){
    l_BuildingIndex = *static_cast<EBuildingIndex *>(p_Event->getUserData());
  }
  if(_Self->_CacheTip)
    _Self->_CacheTip->HideTip();
  //_Self->_CacheTip = nullptr;
  if(l_BuildingIndex != EBuildingIndex::None){
    if(_Self->_CurrentSelectTip != nullptr && _Self->_CurrentSelectTip->_RelyBuildIid == l_BuildingIndex)
      _Self->_CurrentSelectTip = nullptr;
    if(_Self->_CurrentSelectBuild && _Self->_CurrentSelectTip->getTag() == static_cast<int32>(l_BuildingIndex)){
      MainCityFunctions::Get()->CancelBuildTint(_Self->_CurrentSelectBuild);
      _Self->_CurrentSelectBuild = nullptr;
    }
  }else{
    if(_Self->_CacheTip)
      _Self->_CacheTip->HideTip();
    if(_Self->_CurrentSelectTip != nullptr)
      _Self->_CurrentSelectTip = nullptr;
    if(_Self->_CurrentSelectBuild){
      MainCityFunctions::Get()->CancelBuildTint(_Self->_CurrentSelectBuild);
      _Self->_CurrentSelectBuild = nullptr;
    }
  }
}

void MainCityMsg::AddBuildPreview(EventCustom *p_Event){
  if(p_Event == nullptr || p_Event->getUserData() == nullptr)
    return;
  auto l_Data = static_cast<GPair<EBuildingIndex, EBuilding> *>(p_Event->getUserData());
  static auto lBuildingIndex = l_Data->First;
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_REMOVE_BUILD_PREVIEW", &lBuildingIndex);
  _Self->AddBuild(l_Data->First, l_Data->Second);
}


void MainCityMsg::RemoveBuildPreview(EventCustom *p_Event){
  if(p_Event == nullptr || p_Event->getUserData() == nullptr)
    return;
  auto lBuildingIndex = *static_cast<EBuildingIndex *>(p_Event->getUserData());
  auto lBuildBtnName = "build_" + std::to_string(static_cast<int32>(lBuildingIndex));
  auto lBuildButton = _Self->GetBufferNodeByName(lBuildBtnName.c_str());
  if(lBuildButton == nullptr)
    return;
  //   if buildButton then
  //     local buildContentNode = buildButton:getChildByName("buildName")
  //     if nil ~= buildContentNode then
  //       local buildCell = buildContentNode:getBuildCell()
  //       if buildCell ~= nil then
  //         return
  //       end
  //     end
  //   end
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD",
  //     index = buildIndex
  //   })

}
