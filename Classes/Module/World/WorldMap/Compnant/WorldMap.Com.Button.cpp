#include "WorldMap.Com.Button.h"
#include "Base/Base.Lib.h"
#include "Base/Common/Common.Msg.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/Instance/WorldMapTroopInstance.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldMapTroopInstance.h"

#include "Module/UI/Panel/Lord/UILordView.h"
#include "Module/UI/Panel/Alliance/AllianceBuild/UIAllianceBuildMainInfo.View.h"
#include "Module/UI/Panel/World/WorldMap/Overlay/Troops/UIWorldMapTroopsDetails.View.h"
#include "Module/UI/Panel/World/WorldMap/Overlay/Troops/UIWorldMapEmojiSeal.h"
#include "Module/UI/Panel/Item/Buy/UISpeedUpReCallBuyPop.View.h"


void WorldMapComButton::Ctor()
{

}

void WorldMapComButton::Init()
{

}

void WorldMapComButton::OnMessageListener()
{
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_TIPBUTTON_TOUCHCALL", CC_CALLBACK_1(WorldMapComButton::TipButtonTouchCall, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_REMOVE_TROOPBINDINGPANEL", CC_CALLBACK_1(WorldMapComButton::RemoveTroopBindingPanel, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_ESCORT_REQ_CLOSEST_BUILD", CC_CALLBACK_1(WorldMapComButton::ServerMessage_reqClosestBuild, this));
  GBase::DAddMessage(_Target, "MESSAGE_LORDINFO_BY_UID", CC_CALLBACK_1(WorldMapComButton::ServerMessage_LordInfo, this));
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_GET_BUILDINGINFO_SUCCESS", CC_CALLBACK_1(WorldMapComButton::ServerMessage_AllianceBuildInfo, this));
}

void WorldMapComButton::ServerMessage_LordInfo(EventCustom *pEvent){
  if(pEvent == nullptr)
    return;
  if(pEvent->getUserData() == nullptr)
    return;
  auto lLordInfo = (RLordInfo *)pEvent->getUserData();
  auto lordView = UILordView::Create();
  lordView->InitData(*lLordInfo);
  lordView->Show();
}

void WorldMapComButton::ServerMessage_AllianceBuildInfo(EventCustom *pEvent){
  if(pEvent == nullptr)
    return;
  if(pEvent->getUserData() == nullptr)
    return;
  auto lBuildingInfo = static_cast<RAllianceBuildMainInfo *>(pEvent->getUserData());
  if(lBuildingInfo != nullptr){
    auto infoView = UIAllianceBuildMainInfoView::Create();
    infoView->InitData(*lBuildingInfo);
    infoView->Show();
  }
}

void WorldMapComButton::ServerMessage_reqClosestBuild(EventCustom *pEvent){
  //   SoraDCloseLoading(self.target_)
  GBase::DCloseLoading(_Target);
  if(!_IsReqClosestBuild)
    return;
  _IsReqClosestBuild = false;
  // if data.data and data.data.closestBuild then
  //   do
  //     local closestBuild = data.data.closestBuild
  //     if self.reqEscortId == closestBuild.mapObjId then
  //       local worldEscortBeginView = SoraDCreatePanel("worldEscortBeginView")
  //       worldEscortBeginView:initWithData(self.reqEscortData)
  //       worldEscortBeginView:show()
  //     else
  //       SoraDShowMsgBox(i18n("common_text_2319"), i18n("common_text_054"), i18n("common_text_185"), function(eventType)
  //         if eventType == MSGBOX_CALLBACK_YES then
  //           SoraDGotoWorldMapPoint(cc.p(closestBuild.x, closestBuild.y), true)
  //         end
  //       end)
  //     end
  //   end
  // end
  // self.reqEscortId = 0
  // self.reqEscortData = {}
}

struct RTipButtonTouchCallEvAr{
  union {
    GVector<RMoveLineArmyData> _ArmyData;
    int32 _MoveLineID;
    bool _IsRecall;
  } _TipButtonData;
  EWorldMapTipButtonType _TipButtonType;
  struct{

  } _TipButtonExtra;
  Vec2    _TargetPoint;
  IWorldMapInstance *_MapInstance;
  int32 _KingdomID;
};


void DetectSafeStateFunc(const std::function<void()> &pCallBackHandle){
  if(KingdomMapCtrl::Get()->ReqIsSafe()){
  auto lShowMsg = Translate::i18n("notice_0160");
  GBase::DShowMsgBox(
    lShowMsg, Translate::i18n("common_text_490"), Translate::i18n("common_text_185"),
    [pCallBackHandle](auto pCallType){
      if(pCallType == EMsgBoxCallBack::Yes){
        pCallBackHandle();
      }
    }
  );
  }else{
    pCallBackHandle();
  }
}

void WorldMapComButton::TipButtonTouchCall(EventCustom *pEvent){
  if(!pEvent)
    return;
  if(!pEvent->getUserData())
    return;
  auto lData = (RTipButtonTouchCallEvAr *)pEvent->getUserData();
  
  auto lTipButtonType = lData->_TipButtonType;
  auto lTipButtonExtra = lData->_TipButtonExtra;
  
  auto lEndPoint = Vec2(GMath::Floor(lData->_TargetPoint.x), GMath::Floor(lData->_TargetPoint.y));
  auto lMapInstance = lData->_MapInstance;

  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
  // local dispatchType = tipButtonExtra.dispatchType or tipButtonType
  if(lTipButtonType == EWorldMapTipButtonType::buDui){
    
    auto lMoveLineData = lData->_TipButtonData._ArmyData;
    if(!lMoveLineData.size())
      return;
    auto lPanel = UIWorldMapTroopsDetailsView::Create();
    lPanel->InitData(lMoveLineData, lMapInstance->_LeagueName);
    lPanel->Show();
    lPanel->SetCloseCallBack([this](auto pReason){
      _CurrentTroopBindingPanel = nullptr;
    });
    _CurrentTroopBindingPanel = lPanel;

  }else if(lTipButtonType == EWorldMapTipButtonType::zhaoHui || lTipButtonType == EWorldMapTipButtonType::jiesan){
    
    auto lMoveLineID = lData->_TipButtonData._MoveLineID;
    auto lTroopInstance = dynamic_cast<WorldMapTroopInstance *>(lMapInstance);
    auto lIsMass = lTroopInstance->_MoveLineType == EMapMoveLineType::Mass;
    auto lIsJieSan = lTipButtonType == EWorldMapTipButtonType::jiesan;
    auto lPanel = UISpeedUpReCallBuyPopView::Create();
    lPanel->InitData(EItemType::MARCH_BACK, {
      lMoveLineID,
      lIsMass,
      lTroopInstance->_IsMainQueue,
      lIsJieSan,
      lData->_TipButtonData._IsRecall
    });
    lPanel->Show();

  }else if(lTipButtonType == EWorldMapTipButtonType::jiaSu){

    auto lMoveLineID = lData->_TipButtonData._MoveLineID;
    auto lPanel = UISpeedUpReCallBuyPopView::Create();
    lPanel->InitData(EItemType::MARCH_SPEED_UP, {
      lMoveLineID
    });
    lPanel->Show();

  } else if(lTipButtonType == EWorldMapTipButtonType::yuanzhujiacheng){
    //   local assistData = mapInstance:getAssistData()
    //   if assistData == nil or assistData.assistorInfo == nil or assistData.assistBattlePlus == nil or assistData.assistorInfo.uid == nil then
    //     SoraDShowMsgTip(i18n("common_text_2468"), "#icon_escort_convey.png")
    //     return
    //   end
    //   local worldEscortAidAddition = SoraDCreatePanel("worldEscortAidAddition")
    //   worldEscortAidAddition:initWithData(mapInstance:getAssistData())
    //   worldEscortAidAddition:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::lueduo){
  //   do
  auto lCastleBcell = CityCtrl::Get()->GetBuildingCell(EBuilding::Castle, EBuildingIndex::Castle);
    //     local escortCtrl = gametop.playertop_:getModule("escortCtrl")
    //     local minLv = escortCtrl.dataMgr:getEscortCityLevelMin()
    //     if minLv > tonumber(castleBcell.info.lv) then
    //       SoraDShowMsgTip(i18n("common_text_2483"), "#icon_escort_convey.png")
    //       return
    //     end
    //     local allianceDesRead = include("allianceDesRead")
    //     if allianceDesRead.getPlayerConquestWarMigration() then
    //       return
    //     end
    //     local assistData = mapInstance:getAssistData()
    //     if assistData ~= nil and assistData.assistorInfo ~= nil and assistData.assistorInfo.uid ~= nil then
    //       local selfUid = lordInfoCtrl:getLordInfo().base.uid
    //       if assistData.assistorInfo.uid == selfUid then
    //         SoraDShowMsgTip(i18n("common_text_2498"), "#icon_escort_convey.png")
    //         return
    //       end
    //     end
    //     local function OpenDispatchView()
    //       local moveLineID = tipButtonData.moveLineID
    //       print("\229\188\185\229\135\186\229\135\186\229\190\129\231\149\140\233\157\162, moveLineID = ", moveLineID)
    //       local dispatchPanel = include("worldDispatchArmyView").new()
    //       dispatchPanel:initData({
    //         toPoint = endPoint,
    //         dispatchType = dispatchType,
    //         instanceID = moveLineID
    //       })
    //       dispatchPanel:show()
    //     end
    //     local leagueID = tipButtonData.leagueID
    //     local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(leagueID)
    //     if allianceRelationType == gMapAllianceRelationType.FRIENDLY then
    //       local showMsg = i18n("common_text_3066", {
    //         action = i18n("common_text_2325")
    //       })
    //       SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //         if callType == MSGBOX_CALLBACK_YES then
    //           OpenDispatchView()
    //         end
    //       end)
    //       return
    //     elseif allianceRelationType == gMapAllianceRelationType.ALLY then
    //       local action = i18n("common_text_008")
    //       SoraDShowMsgTip(i18n("common_text_2325", {action = action}))
    //       return
    //     end
    //     if escortCtrl:isReachRobLimit() then
    //       SoraDShowMsgTip(i18n("common_text_2354"), "#icon_escort_convey.png")
    //       return
    //     end
    //     OpenDispatchView()
    //   end
  }else if(lTipButtonType == EWorldMapTipButtonType::yongHuXinxi){

    LordInfoCtrl::Get()->GetLordInfoByUid(lMapInstance->_PlayerID, lData->_KingdomID,  "WorldMapComButton");

  }else if(lTipButtonType == EWorldMapTipButtonType::biaoqingyinzhang){
    auto lPanel = UIWorldMapEmojiSeal::Create();
    auto lMoveLineID = lData->_TipButtonData._MoveLineID;
    lPanel->InitData(lMapInstance, lMoveLineID);
    lPanel->Show();
  }else{
    auto lCurrentMapInstance = _Target->GetShowInstance(lEndPoint);
    if(lMapInstance != lCurrentMapInstance){
      GBase::DShowMsgTip(Translate::i18n("notice_0026"));
      return;
    }
  }
  
  if(lTipButtonType == EWorldMapTipButtonType::shuoMing){
    //       local instanceType = mapInstance:getInstanceType()
    auto lInstanceType = lMapInstance->_InstanceType;
    //       local instanceClassID = mapInstance.resourceClassID or 0
    //       if gMapObjTypeDef.mapObjTypeSuperResource == instanceType then
    if(lInstanceType == EMapObjTypeDef::mapObjTypeSuperResource){
      //         local panel = SoraDCreatePanel("allianceBuildNoticeView")
      //         panel:initData(instanceClassID, mapInstance.leagueID, mapInstance.kingdomID)
      //         panel:show()
    } else if(lInstanceType == EMapObjTypeDef::mapObjTypeAllianceBuild){
      //         local instanceBuildClassID = mapInstance.getBuildClassID and mapInstance:getBuildClassID()
      //         if gMapAllianceBuildType.subTypeAllianceAltar == instanceBuildClassID then
      //           local panel = SoraDCreatePanel("allianceBuildNoticeView")
      //           panel:initData(instanceBuildClassID, mapInstance.leagueID, mapInstance.kingdomID)
      //           panel:show()
      //         end
    } else if(lInstanceType == EMapObjTypeDef::mapTypeATBuilding){
      //         SoraDShowFixWindow(i18n("AncienTreasure_text_80"), {
      //           i18n("AncienTreasure_text_81")
      //         })
    } else if(lInstanceType == EMapObjTypeDef::mapTypeWarTreasure){
      //         SoraDShowHelpMsgTip(i18n("warSecrit_text_01"))
    } else if(lInstanceType == EMapObjTypeDef::mapType20Campfire){
      //         local panel = SoraDCreatePanel("anniversaryFlameExplainView")
      //         panel:initData({
      //           fireNum = mapInstance.flameNum,
      //           owerName = mapInstance.owerName,
      //           createUid = mapInstance.createUid,
      //           flameStage = mapInstance.flameStage
      //         })
      //         panel:show()
    }else{
      //         local panel = SoraDCreatePanel("worldMapExplainView")
      //         panel:initData(instanceType, instanceClassID)
      //         panel:show()
    }
  }else if(lTipButtonType == EWorldMapTipButtonType::xiangqing){
    //       local instanceType = mapInstance:getInstanceType()
    auto lInstanceType = lMapInstance->_InstanceType;
    //       local instanceClassID = mapInstance.resourceClassID or 0

    //       if gMapObjTypeDef.mapObjTypeResource == instanceType then
    if(lInstanceType == EMapObjTypeDef::mapObjTypeResource){
      //         local instanceID = mapInstance:getInstanceID()
      //         local panel = SoraDCreatePanel("worldMapResOccupyView")
      //         panel:initData({
      //           classID = instanceClassID,
      //           resPos = endPoint,
      //           insID = instanceID
      //         })
      //         panel:show()
    } else if(lInstanceType == EMapObjTypeDef::mapTypeWarTreasure){
      //         local instanceID = mapInstance:getInstanceID()
      //         local panel = SoraDCreatePanel("worldMapResOccupyView")
      //         panel:initDataFromWar({
      //           classID = instanceClassID,
      //           resPos = endPoint,
      //           insID = instanceID,
      //           data = tipButtonData,
      //           playerName = mapInstance.playerName,
      //           leagueName = mapInstance.leagueName
      //         })
      //         panel:show()
    }else if(lInstanceType == EMapObjTypeDef::mapTypeRadianceWarResource){
      //         local instanceID = mapInstance:getInstanceID()
      //         local panel = SoraDCreatePanel("radianceWarResOccupyView")
      //         panel:initData({
      //           classID = instanceClassID,
      //           resPos = endPoint,
      //           insID = instanceID,
      //           resourceType = mapInstance.resourceType,
      //           mapInstance = mapInstance
      //         })
      //         panel:show()
    }else if(lInstanceType == EMapObjTypeDef::mapTypeMine){
      //         local panel = SoraDCreatePanel("worldResourceDetailView")
      //         panel:initData({
      //           resPos = endPoint,
      //           resourceType = mapInstance:getBuildClassID(),
      //           mapInstance = mapInstance
      //         })
      //         panel:show()
    }else if(lInstanceType == EMapObjTypeDef::nebulaWarMine){
      //         uiManager:show("NebulaWarMineDetail", {mapInstance = mapInstance})
    }
  }else if(lTipButtonType == EWorldMapTipButtonType::jinruChengshi){
    //       SoraDSendMessage({
    //         msg = "MESSAGE_MAINSCEN_ONSHOW",
    //         viewType = VIEW_TYPE_CITY
    //       })
  }else if(lTipButtonType == EWorldMapTipButtonType::chengshiZengyi){
    //       local panel = SoraDCreatePanel("citybuffView")
    //       panel:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::decorate){
    //       local dressCtrl = gametop.playertop_:getModule("dressCtrl")
    //       local panel = SoraDCreatePanel("castleChangeView")
    //       panel:initData({
    //         isFromWorld = true,
    //         dressID = dressCtrl:getCurDressID(gDressType.CASTLE),
    //         toShop = false
    //       })
    //       panel:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::fanHui){
    //       do
    //         local function sendMsgFun()
    //           local instanceID = mapInstance:getInstanceID()
    //           kingdomMapCtrl:reqBackQueue(endPoint.x, endPoint.y, instanceID)
    //           local instanceType = mapInstance:getInstanceType()
    //           if instanceType == gMapObjTypeDef.mapObjTypeLegendLord or instanceType == gMapObjTypeDef.nebulaWarBuilding then
    //             local hasArmy, queueId = mapInstance:checkHasArmy()
    //             if queueId then
    //               if not _G._returnQueueIdList then
    //                 _G._returnQueueIdList = {}
    //               end
    //               _G._returnQueueIdList[queueId] = true
    //             end
    //           end
    //         end
    //         local showMsg = i18n("notice_0025")
    //         local instanceType = mapInstance:getInstanceType()
    //         if instanceType == gMapObjTypeDef.mapObjTypeTreasure then
    //           showMsg = i18n("common_text_1648")
    //         elseif instanceType == gMapObjTypeDef.mapTypeRadianceWarGate then
    //           showMsg = i18n("brightWar_text_149")
    //         elseif instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon then
    //           if mapInstance and mapInstance:isOccupCompleted() then
    //             showMsg = nil
    //             sendMsgFun()
    //           else
    //             showMsg = i18n("brightWar_text_149")
    //           end
    //         elseif instanceType == gMapObjTypeDef.nebulaWarMine then
    //           showMsg = i18n("nebula_war_text_0282")
    //         end
    //         if showMsg then
    //           SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //             if callType == MSGBOX_CALLBACK_YES then
    //               sendMsgFun()
    //             end
    //           end)
    //         end
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::cancel){
    //       do
    //         local name = mapInstance:getFavoriteName()
    //         local showMsg = i18n("brightWar_text_58", {name = name})
    //         local instanceType = mapInstance:getInstanceType()
    //         SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //           if callType == MSGBOX_CALLBACK_YES then
    //             if instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon then
    //               local objId = mapInstance:getSiteClassID()
    //               local radianceWarCtrl = gametop.playertop_:getModule("radianceWarCtrl")
    //               radianceWarCtrl:reqRadianceWarFreeBeacon(objId)
    //             elseif instanceType == gMapObjTypeDef.mapTypeRadianceWarResource then
    //               local instanceID = mapInstance:getInstanceID()
    //               local radianceWarCtrl = gametop.playertop_:getModule("radianceWarCtrl")
    //               radianceWarCtrl:reqRadianceWarFreeRes(instanceID)
    //             end
    //           end
    //         end)
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::cancel_cancel){
    //       do
    //         local showMsg = i18n("brightWar_text_91")
    //         local instanceType = mapInstance:getInstanceType()
    //         SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //           if callType == MSGBOX_CALLBACK_YES and instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon then
    //             local objId = mapInstance:getSiteClassID()
    //             local radianceWarCtrl = gametop.playertop_:getModule("radianceWarCtrl")
    //             radianceWarCtrl:reqRadianceWarCancelFreeBeacon(objId)
    //           end
    //         end)
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::build_info){
    //       local instanceType = mapInstance:getInstanceType()
    //       if instanceType == gMapObjTypeDef.nebulaWarBuilding then
    //         uiManager:show("NebulaWarAroundBuild", {mapInstance = mapInstance})
    //         return
    //       end
    //       local siteClassID = mapInstance:getSiteClassID()
    //       local panel = SoraDCreatePanel("radianceWarBuildInfo")
    //       panel:initData(mapInstance, {siteClassID = siteClassID})
    //       panel:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::qianCheng){
  //       local kingdomID = data.kingdomID
  //       local mapViewCell = self.target_:getWorldMapCell(kingdomID)
  //       local worldMapEvent = include("worldMapEvent")
  //       local event = {
  //         name = worldMapEvent.EVENT_TRANS,
  //         layInstanceType = worldMapLayInstanceTypeDef.layInstanceCity,
  //         pos = endPoint,
  //         mapViewCell = mapViewCell
  //       }
  //       self:dispatchEvent(event)
  }else if(lTipButtonType == EWorldMapTipButtonType::yaoqingQianCheng){
    //       local tilePoint = tipButtonData.tilePoint
    //       local panel = SoraDCreatePanel("allianceMemberList")
    //       panel:initData(nil, {inviteMoveCityPos = tilePoint})
    //       panel:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::lingdiqianCheng){
    //       print("\233\162\134\229\156\176\232\191\129\229\159\142")
    //       local kingdomID = data.kingdomID
    //       local mapViewCell = self.target_:getWorldMapCell(kingdomID)
    //       local worldMapEvent = include("worldMapEvent")
    //       local event = {
    //         name = worldMapEvent.EVENT_TRANS,
    //         layInstanceType = worldMapLayInstanceTypeDef.layInstanceCity,
    //         pos = endPoint,
    //         mapViewCell = mapViewCell,
    //         isLeagueManorTransfer = true
    //       }
    //       self:dispatchEvent(event)
  }else if(lTipButtonType == EWorldMapTipButtonType::lianmengjianzhu){
    //       print("\232\129\148\231\155\159\229\187\186\231\173\145")
  }else if(lTipButtonType == EWorldMapTipButtonType::lianmengqizhi){
    //       print("\232\129\148\231\155\159\230\151\151\229\184\156")
    //       local checkHasAlliancePlace = function()
    //         local allianceTerritoryAPI = include("allianceTerritoryAPI")
    //         local mainBuilding = allianceTerritoryAPI:getAllianceMainBuildingInfo()
    //         if not mainBuilding or not next(mainBuilding) then
    //           return
    //         end
    //         for _, v in pairs(mainBuilding) do
    //           if v.bid == gAllianceBuilding.PALACE and v.status ~= gAllianceBuildingStatus.NONE then
    //             return true
    //           end
    //         end
    //       end
    //       if not checkHasAlliancePlace() then
    //         SoraDShowMsgTip(i18n("common_text_3065"))
    //         return
    //       end
    //       local allianceTerritoryCtrl = gametop.playertop_:getModule("allianceTerritoryCtrl")
    //       local buildingFlags = allianceTerritoryCtrl:getBuildingFlags() or {}
    //       if #buildingFlags >= include("constantRead").getConstValue("MAX_IN_BUILDING_FLAG_COUNT", 4) then
    //         SoraDShowMsgTip(i18n("alliance_stronghold_text_095"))
    //         return
    //       end
    //       local allianceDesRead = include("allianceDesRead")
    //       if allianceDesRead.checkRank(gAllianceRank.R4, true, i18n("common_text_3011", {rank = "R4"})) then
    //         local layInstanceData = {}
    //         layInstanceData.leagueFlag = allianceMgr:getAllianceProperty("flag")
    //         layInstanceData.buildClassID = gAllianceBuilding.FLAG
    //         local worldMapEvent = include("worldMapEvent")
    //         local event = {
    //           name = worldMapEvent.EVENT_TRANS,
    //           layInstanceType = worldMapLayInstanceTypeDef.layInstanceAllianceManor,
    //           pos = endPoint,
    //           layInstanceData = layInstanceData
    //         }
    //         self:dispatchEvent(event)
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::fangzhi){
    //       local tilePoint = tipButtonData.tilePoint
    //       local allianceLeaderPoint = allianceMgr:getLeaderPos()
    //       if not allianceLeaderPoint then
    //         SoraDShowMsgTip(i18n("common_text_2218"))
    //         return
    //       end
    //       local buildClass = gAllianceBuildUIListType.RESOURCE
    //       local allianceTerritoryAPI = include("allianceTerritoryAPI")
    //       if allianceTerritoryAPI:checkHasRecycleBuilding() then
    //         buildClass = gAllianceBuildUIListType.RECYCLE
    //       elseif not allianceTerritoryAPI:checkHasMainBuilding(gAllianceBuilding.PALACE) or not allianceTerritoryAPI:checkHasMainBuilding(gAllianceBuilding.PRIMARY_PALACE) or not allianceTerritoryAPI:checkHasMainBuilding(gAllianceBuilding.ALTAR) then
    //         buildClass = gAllianceBuildUIListType.MAIN_BUILD
    //       end
    //       local panel = SoraDCreatePanel("allianceBuildView")
    //       panel:setBuildPos(tilePoint, buildClass)
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::caiji){
    //       print("\229\188\185\229\135\186\232\129\148\231\155\159\232\181\132\230\186\144\231\130\185\233\135\135\233\155\134\231\149\140\233\157\162")
    //       local instanceID = mapInstance.instanceID
    //       local instanceType = mapInstance.instanceType
    //       local resourceClassID = mapInstance.resourceClassID
    //       local resourceType = worldMapDefine.getAllianceResourceType(resourceClassID)
    //       local buildLv = cityCtrl:getBuildMaxLv(BUILDID.CASTLE)
    //       local limitBuildLv = 6
    //       local otherData = {}
    //       local tableResID = {
    //         gIDDef.FOOD,
    //         gIDDef.WOOD,
    //         gIDDef.IRON,
    //         gIDDef.MITHRIL,
    //         gIDDef.ALLIANCE_CRYSTAL_MINE
    //       }
    //       otherData.resourceType = tableResID[resourceType]
    //       if resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResFood or resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResWood then
    //         limitBuildLv = 6
    //       elseif resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResIron then
    //         limitBuildLv = 10
    //       elseif resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResMithril then
    //         limitBuildLv = 15
    //       elseif resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResCrystal then
    //         limitBuildLv = 60
    //       end
    //       if SoraDEnoughTroops() then
    //         if buildLv < limitBuildLv then
    //           if resourceType == gMapAllianceResourceTypeDef.subMapObjTypeResCrystal then
    //             SoraDShowMsgTip(i18n("alliance_build_text_03"))
    //           else
    //             local resourceName = worldMapDefine.getAllianceResourceName(resourceClassID)
    //             local showMsg = i18n("common_text_2225", {lv = limitBuildLv, build = resourceName})
    //             SoraDShowMsgBox(showMsg, i18n("common_text_054"), nil, nil)
    //           end
    //         elseif kingdomMapCtrl:hasQueue2AllianceBuild(instanceID) then
    //           SoraDShowMsgTip(i18n("common_text_2223"))
    //         else
    //           local dispatchPanel = include("worldDispatchArmyView").new()
    //           dispatchPanel:initData({
    //             otherData = otherData,
    //             toPoint = endPoint,
    //             dispatchType = dispatchType,
    //             instanceID = instanceID,
    //             instanceType = instanceType
    //           })
    //           dispatchPanel:show()
    //         end
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::jianzao){
    //       print("\229\188\185\229\135\186\232\129\148\231\155\159\232\181\132\230\186\144\231\130\185\229\187\186\233\128\160\231\149\140\233\157\162")
    //       local allianceBuild = gametop.playertop_:getModule("allianceBuild")
    //       local resourceClassID = mapInstance.resourceClassID
    //       local instanceID = mapInstance.instanceID
    //       local instanceType = mapInstance.instanceType
    //       local isCanMarch, remainSoldierNum = allianceBuild:canBuildingMarch(resourceClassID, instanceID)
    //       if instanceType ~= gMapObjTypeDef.mapObjTypeSuperResource then
    //         dump(tipButtonData, "tipButtonData=======", 10)
    //         local guardArmyCapacity = tipButtonData.guardArmyCapacity or 0
    //         local guardArmyTotalNum = tipButtonData.guardArmyTotalNum or 0
    //         local remainSoldierNum = guardArmyCapacity > 0 and guardArmyCapacity - guardArmyTotalNum or nil
    //         if guardArmyCapacity > 0 and remainSoldierNum and remainSoldierNum <= 0 then
    //           SoraDShowMsgTip(i18n("alliance_stronghold_text_109"))
    //         elseif SoraDEnoughTroops() then
    //           if kingdomMapCtrl:hasQueue2AllianceBuild(instanceID) then
    //             SoraDShowMsgTip(i18n("common_text_2223"))
    //           else
    //             local isSelfIn = false
    //             for k, v in ipairs(tipButtonData.guards or {}) do
    //               if v.playerID == gametop.playertop_:getPlayerID() then
    //                 isSelfIn = true
    //                 break
    //               end
    //             end
    //             if isSelfIn then
    //               SoraDShowMsgTip(i18n("alliance_stronghold_text_018"))
    //               return
    //             end
    //             local dispatchPanel = include("worldDispatchArmyView").new()
    //             dispatchPanel:initData({
    //               toPoint = endPoint,
    //               dispatchType = dispatchType,
    //               instanceID = instanceID,
    //               instanceType = instanceType,
    //               maxCount = remainSoldierNum
    //             })
    //             dispatchPanel:show()
    //           end
    //         end
    //       elseif isCanMarch == gErrDef.Err_None then
    //         if SoraDEnoughTroops() then
    //           if kingdomMapCtrl:hasQueue2AllianceBuild(instanceID) then
    //             SoraDShowMsgTip(i18n("common_text_2223"))
    //           else
    //             local dispatchPanel = include("worldDispatchArmyView").new()
    //             dispatchPanel:initData({
    //               toPoint = endPoint,
    //               dispatchType = dispatchType,
    //               instanceID = instanceID,
    //               instanceType = instanceType,
    //               maxCount = remainSoldierNum
    //             })
    //             dispatchPanel:show()
    //           end
    //         end
    //       elseif isCanMarch == gErrDef.Err_ALLIANCE_BUILDING_QUEUE_FULL then
    //         SoraDShowMsgTip(i18n("common_text_2216"))
    //       elseif isCanMarch == gErrDef.Err_ALLIANCE_BUILDING_SOLDIER_FULL then
    //         SoraDShowMsgTip(i18n("common_text_2215"))
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::caijixiangqing){
    //       local instanceType = mapInstance.instanceType
    //       if instanceType == gMapObjTypeDef.nebulaWarMine then
    //         uiManager:show("NebulaWarMineCollDetail", {
    //           mapInstance = mapInstance,
    //           collerMap = tipButtonData.collerMap
    //         })
    //         return
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::chakanxiangqing){
    //       if mapInstance.resourceClassID then
    //         local panel = SoraDCreatePanel("allianceBuildInfoView")
    //         panel:initData(mapInstance.resourceClassID, mapInstance.instanceID)
    //         panel:show()
    //       else
    //         local allianceTerritoryAPI = include("allianceTerritoryAPI")
    //         allianceTerritoryAPI:getAllianceBuildingInfo(mapInstance.buildID or tipButtonData.id, mapInstance.buildClassID)
    //       end
  }else if(
    lTipButtonType == EWorldMapTipButtonType::zhanLing || 
    lTipButtonType == EWorldMapTipButtonType::gongJi || 
    lTipButtonType == EWorldMapTipButtonType::nebula_caiji
    ){
  //       do
  //         local instanceID, instanceType
  //         local otherData = {}
  //         if mapInstance then
  //           instanceID = mapInstance:getInstanceID()
  //           instanceType = mapInstance.instanceType
  //           if instanceType == gMapObjTypeDef.mapObjTypeResource then
  //             local tableResID = {
  //               gIDDef.GOLD,
  //               gIDDef.FOOD,
  //               gIDDef.WOOD,
  //               gIDDef.IRON,
  //               gIDDef.MITHRIL,
  //               gIDDef.CRYSTAL
  //             }
  //             local resourceType = worldMapDefine.getResourceType(mapInstance.resourceClassID)
  //             otherData.resourceType = tableResID[resourceType]
  //             otherData.currentSourceNum = mapInstance.currentSourceNum
  //           end
  //         end
  //         local function localFunction()
  //           if SoraDEnoughTroops() then
  //             local dispatchPanel = include("worldDispatchArmyView").new()
  //             print("dispatchType", dispatchType)
  //             dispatchPanel:initData({
  //               toPoint = endPoint,
  //               dispatchType = dispatchType,
  //               instanceID = instanceID,
  //               instanceType = instanceType,
  //               otherData = otherData
  //             })
  //             dispatchPanel:show()
  //           end
  //         end
  //         if tipButtonType == worldMapDefine.worldMapTipButtonType_gongJi then
  //           if kingdomMapCtrl:isForbitWar() then
  //             SoraDShowMsgTip(i18n("common_text_3445"))
  //             return
  //           end
  //           if self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
  //             SoraDShowMsgTip(i18n("remains_text_142"))
  //             return
  //           end
  //           if self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
  //             SoraDShowMsgTip(i18n("remains_text_158"))
  //             return
  //           end
  //           if (mapInstance.isSafe or mapInstance.isInAllianceWar and mapInstance:isInAllianceWar()) and mapInstance.playerID ~= self.myPlayerID then
  //             SoraDShowMsgTip(i18n("notice_0159"))
  //             return
  //           end
  //           if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //             SoraDShowMsgTip(i18n("worldwar_text_01"))
  //             return
  //           elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //             SoraDShowMsgTip(i18n("worldwar_text_02"))
  //             return
  //           end
  //           if instanceType and instanceType == gMapObjTypeDef.mapTypeATBuilding and SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
  //             SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
  //             return
  //           end
  //           if instanceType and instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild and kingdomMapCtrl:isForbidMapObjWar(instanceType) then
  //             SoraDShowMsgTip(i18n("Battlefield_queue_text_012"))
  //             return
  //           end
  //           if instanceType == gMapObjTypeDef.mapObjTypeSuperResource or instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild then
  //             local radioation = mapInstance.radioation
  //             local size = mapInstance.size
  //             local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  //             local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
  //             if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
  //               SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
  //               return
  //             end
  //           end
  //           if instanceType == gMapObjTypeDef.stronghold then
  //             local radioation = mapInstance.radioation
  //             local size = mapInstance.size
  //             local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  //             local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
  //             if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
  //               SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
  //               return
  //             elseif mapInstance.npc then
  //               if kingdomMapCtrl:hasQueue2HoldBuildNpc(instanceID) then
  //                 SoraDShowMsgTip(i18n("alliance_stronghold_text_097"))
  //                 return
  //               else
  //                 local dispatchData = {
  //                   toPoint = endPoint,
  //                   dispatchType = dispatchType,
  //                   instanceID = instanceID,
  //                   instanceType = instanceType,
  //                   otherData = otherData,
  //                   leftAttackNpcCount = tipButtonData.leftAttackNpcCount,
  //                   attackNpcCountRecoverTime = tipButtonData.attackNpcCountRecoverTime
  //                 }
  //                 local panel = SoraDCreatePanel("worldStrongPointMonsterView")
  //                 panel:initData(mapInstance, dispatchData)
  //                 panel:show()
  //                 return
  //               end
  //             else
  //               detectSafeStateFunc(handler(self, localFunction))
  //               return
  //             end
  //           end
  //           local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  //           if instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild or selfLeagueID > 0 then
  //             local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(mapInstance.leagueID)
  //             local action = i18n("common_text_008")
  //             if selfLeagueID == 0 then
  //               SoraDShowMsgTip(i18n("common_text_3063", {action = action}))
  //               return
  //             elseif allianceRelationType == gMapAllianceRelationType.ALLY then
  //               SoraDShowMsgTip(i18n("common_text_3067", {action = action}))
  //               return
  //             elseif allianceRelationType == gMapAllianceRelationType.FRIENDLY then
  //               local showMsg = i18n("common_text_3066", {action = action})
  //               SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
  //                 if callType == MSGBOX_CALLBACK_YES then
  //                   detectSafeStateFunc(handler(self, localFunction))
  //                 end
  //               end)
  //               return
  //             end
  //           end
  //           if instanceType == gMapObjTypeDef.nebulaWarBuilding then
  //             local nebulaWarUtil = include("nebulaWarUtil")
  //             if not nebulaWarUtil.checkBuildCanAttack(mapInstance) then
  //               return
  //             end
  //             if not tipButtonData.isCanOccupy then
  //               SoraDShowMsgBox(i18n("nebula_war_text_0087"), i18n("common_text_829"), nil, function(callType)
  //                 if callType == MSGBOX_CALLBACK_YES then
  //                   uiManager:show("NebulaWarAroundBuild", {mapInstance = mapInstance})
  //                 end
  //               end)
  //               return
  //             end
  //           end
  //           detectSafeStateFunc(handler(self, localFunction))
  //         else
  //           if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //             SoraDShowMsgTip(i18n("worldwar_text_03"))
  //             return
  //           end
  //           if self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
  //             SoraDShowMsgTip(i18n("remains_text_142"))
  //             return
  //           end
  //           if self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
  //             SoraDShowMsgTip(i18n("remains_text_142"))
  //             return
  //           end
  //           if instanceType and gMapObjTypeDef.mapTypeWarTreasure == instanceType then
  //             local instanceClassID = mapInstance.resourceClassID or 0
  //             if instanceClassID == 4301 then
  //               detectSafeStateFunc(handler(self, localFunction))
  //               return
  //             end
  //           end
  //           if instanceType == gMapObjTypeDef.nebulaWarMine and kingdomMapCtrl:hasMyQueue(nil, nil, nil, mapInstance:getSiteClassID()) then
  //             SoraDShowMsgTip(i18n("nebula_war_text_0287"))
  //             return
  //           end
  //           if self.mapClassType == gKingdomClassType.normal then
  //             local allianceStrongholdMineRead = include("allianceStrongholdMineRead")
  //             if allianceStrongholdMineRead.isInHoldArea(endPoint) then
  //               SoraDShowMsgTip(i18n("alliance_stronghold_text_110"))
  //               return
  //             end
  //           end
  //           localFunction()
  //         end
  //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::ziyuanYuanzhu){
  //       if not include("pyramidWarltCtrl").checkPwXianXiaSai() then
  //         return
  //       end
  //       if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //         SoraDShowMsgTip(i18n("worldwar_text_06"))
  //         return
  //       elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
  //         SoraDShowMsgTip(i18n("remains_text_142"))
  //         return
  //       elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
  //         SoraDShowMsgTip(i18n("remains_text_158"))
  //         return
  //       elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //         SoraDShowMsgTip(i18n("worldwar_text_02"))
  //         return
  //       end
  //       local buildcell = cityCtrl:getBuildCell(BUILDID.MARKET, 0)
  //       if buildcell then
  //         if SoraDEnoughTroops() then
  //           local panel = SoraDCreatePanel("marketView")
  //           panel:initView({
  //             uid = mapInstance.playerID
  //           })
  //           panel:show()
  //         end
  //       else
  //         SoraDShowMsgTip(i18n("common_text_498"))
  //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::shibingYuabzhu){
  //       do
  //         local instanceID = mapInstance:getInstanceID()
  //         if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //           SoraDShowMsgTip(i18n("worldwar_text_06"))
  //           return
  //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
  //           SoraDShowMsgTip(i18n("remains_text_142"))
  //           return
  //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
  //           SoraDShowMsgTip(i18n("remains_text_158"))
  //           return
  //         elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //           SoraDShowMsgTip(i18n("worldwar_text_02"))
  //           return
  //         end
  //         if mapInstance:getInstanceType() == gMapObjTypeDef.stronghold then
  //           local radioation = mapInstance.radioation
  //           local size = mapInstance.size
  //           local selfLeagueID = allianceMgr:getOwnTeamID() or 0
  //           local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
  //           if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
  //             SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
  //             return
  //           end
  //         end
  //         local function localFunction()
  //           local instanceType = mapInstance:getInstanceType()
  //           local panel = SoraDCreatePanel("reinforcementsMsgBox")
  //           panel:initData({
  //             uid = mapInstance.playerID,
  //             instanceID = instanceID,
  //             dispatchType = dispatchType,
  //             instanceType = instanceType
  //           })
  //           panel:show()
  //         end
  //         local instanceType = mapInstance:getInstanceType()
  //         if instanceType == gMapObjTypeDef.mapObjTypeCastale or instanceType == gMapObjTypeDef.mapObjTypeBattery or instanceType == gMapObjTypeDef.mapObjTypeLegendLord or instanceType == gMapObjTypeDef.mapObjTypeRemainsWar or instanceType == gMapObjTypeDef.mapObjTypeFortress then
  //           detectSafeStateFunc(handler(self, localFunction))
  //         elseif not kingdomMapCtrl:hasArmyHelpQueue2Player(mapInstance.playerID, instanceID) then
  //           localFunction()
  //         else
  //           SoraDShowMsgTip(i18n("common_text_704"))
  //         end
  //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::xiefang){
  //       local instanceID = mapInstance:getInstanceID()
  //       if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //         SoraDShowMsgTip(i18n("worldwar_text_01"))
  //         return
  //       elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
  //         SoraDShowMsgTip(i18n("remains_text_142"))
  //         return
  //       elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
  //         SoraDShowMsgTip(i18n("worldwar_text_02"))
  //         return
  //       end
  //       if kingdomMapCtrl:hasArmyHelpQueue2Object(instanceID) then
  //         SoraDShowMsgTip(i18n("common_text_704"))
  //       elseif SoraDEnoughTroops() then
  //         local instanceType = mapInstance:getInstanceType()
  //         local dispatchPanel = include("worldDispatchArmyView").new()
  //         dispatchPanel:initData({
  //           toPoint = endPoint,
  //           dispatchType = dispatchType,
  //           instanceID = instanceID,
  //           instanceType = instanceType
  //         })
  //         dispatchPanel:show()
  //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::chakanYuanjun){
    //       local armyData = tipButtonData.army
    //       if not armyData then
    //         return
    //       end
    //       local otherData = {}
    //       otherData.currentSoliderHelpNum = tipButtonData.currentSoliderHelpNum
    //       otherData.tolalSoliderHelpNum = tipButtonData.tolalSoliderHelpNum
    //       otherData.playerName = mapInstance.playerName
    //       otherData.endPoint = endPoint
    //       otherData.mapInstance = mapInstance
    //       otherData.tipButtonType = tipButtonType
    //       local panel = SoraDCreatePanel("worldMapTroopsDetailsView")
    //       panel:initData(armyData, mapInstance.leagueName, otherData)
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::chakanzhujun){
    //       if not allianceMgr:hasJoinAlliance() then
    //         SoraDSendMessage({
    //           msg = "MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL"
    //         })
    //         return
    //       end
    //       local guardsData = tipButtonData.guards
    //       if not guardsData then
    //         return
    //       end
    //       local showTilePoint = mapInstance:getTilePoint()
    //       local instanceID = mapInstance:getInstanceID()
    //       local kingdomID = mapInstance:getWorldMapCell().kingdomID
    //       if tipButtonData.status == gMapObjStateTypeDef.gMapObjStateTypeWorking then
    //         local panel = SoraDCreatePanel("allianceBuildBuildingView")
    //         local remainSoldierNum
    //         panel:initDispatchData({
    //           toPoint = endPoint,
    //           dispatchType = worldMapDefine.worldMapTipButtonType_jianzao,
    //           instanceID = instanceID,
    //           instanceType = instanceType,
    //           maxCount = remainSoldierNum
    //         })
    //         panel:initData(mapInstance:getBuildClassID(), tipButtonData, {
    //           x = showTilePoint.x,
    //           y = showTilePoint.y,
    //           id = instanceID,
    //           kingdomId = kingdomID
    //         })
    //         panel:show()
    //       else
    //         local panel = SoraDCreatePanel("allianceBuildMainArmyView")
    //         panel:initData(tipButtonData, {
    //           x = showTilePoint.x,
    //           y = showTilePoint.y,
    //           id = instanceID,
    //           kingdomId = kingdomID
    //         })
    //         panel:show()
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::jijieBuduiXinxi){
    //       SoraDCreatePanel("allianceWarView"):show()
  } else if(lTipButtonType == EWorldMapTipButtonType::buDuiXiangqing){
    //       dump(tipButtonData, "worldMapTipButtonType_buDuiXiangqing-tipButtonData", 10)
    //       local armyData = tipButtonData.army
    //       local allianceName = mapInstance.leagueAbbrName or mapInstance.leagueName
    //       local instanceType = mapInstance:getInstanceType()
    //       local isNpc = false
    //       if not armyData then
    //         local mapObjUtil = include("mapObjUtil")
    //         if not mapObjUtil.isAllowArmyEmpty(instanceType) then
    //           return
    //         end
    //         if instanceType == gMapObjTypeDef.mapTypeRadianceWarGate or instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon then
    //           local radianceWarRead = include("radianceWarRead")
    //           local army = radianceWarRead.getBuildArmy(instanceType, 1, mapInstance.level)
    //           local name = i18n("common_text_134", {
    //             lv = mapInstance.level,
    //             name = radianceWarRead.getBuildName(instanceType)
    //           })
    //           local build_data = {
    //             armyList = army,
    //             nickName = name,
    //             buildIcon = radianceWarRead.getBuildIcon(instanceType)
    //           }
    //           if instanceType == gMapObjTypeDef.mapTypeRadianceWarGate then
    //             build_data.hp = mapInstance.hp or 0
    //             build_data.prehp = radianceWarRead.getBuildPerATKHP(instanceType, 1, mapInstance.level)
    //           end
    //           armyData = {build_data}
    //           allianceName = nil
    //           isNpc = true
    //         elseif instanceType == gMapObjTypeDef.mapTypeRadianceWarResource then
    //           local radianceWarRead = include("radianceWarRead")
    //           local army = radianceWarRead.getBuildArmy(instanceType, mapInstance.resourceType, mapInstance.level)
    //           local name = radianceWarRead.getResourceName(mapInstance.siteClassID, true)
    //           local build_data = {
    //             armyList = army,
    //             nickName = name,
    //             buildIcon = radianceWarRead.getResourceSmallImageNameByType(mapInstance.resourceType)
    //           }
    //           armyData = {build_data}
    //           allianceName = nil
    //         end
    //       end
    //       local panel = SoraDCreatePanel("worldMapTroopsDetailsView")
    //       local otherData = {}
    //       otherData.endPoint = endPoint
    //       otherData.mapInstance = mapInstance
    //       otherData.tipButtonType = tipButtonType
    //       otherData.isNpc = isNpc
    //       panel:initData(armyData, allianceName, otherData)
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::zhenCha){
    //       do
    //         local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
    //         if kingdomMapCtrl:isForbitWar() then
    //           SoraDShowMsgTip(i18n("common_text_3445"))
    //           return
    //         end
    //         if (mapInstance.isSafe or mapInstance.isInAllianceWar and mapInstance:isInAllianceWar()) and mapInstance.playerID ~= self.myPlayerID then
    //           SoraDShowMsgTip(i18n("notice_0159"))
    //           return
    //         end
    //         if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
    //           SoraDShowMsgTip(i18n("worldwar_text_01"))
    //           return
    //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
    //           SoraDShowMsgTip(i18n("remains_text_142"))
    //           return
    //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
    //           SoraDShowMsgTip(i18n("remains_text_158"))
    //           return
    //         elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
    //           SoraDShowMsgTip(i18n("worldwar_text_02"))
    //           return
    //         elseif (mapInstance:getInstanceType() == gMapObjTypeDef.stronghold or mapInstance:getInstanceType() == gMapObjTypeDef.mapObjTypeAllianceBuild) and towerLv <= 1 then
    //           SoraDShowMsgTip(i18n("alliance_stronghold_text_111"))
    //           return
    //         end
    //         local instanceID = mapInstance:getInstanceID()
    //         local instanceType = mapInstance:getInstanceType()
    //         local buildClassID = mapInstance.buildClassID
    //         local objId
    //         if instanceType == gMapObjTypeDef.mapObjTypeBattlefieldSite then
    //           objId = mapInstance:getObjId()
    //         end
    //         local function localFunction()
    //           local panel = SoraDCreatePanel("worldMapSpyOnView")
    //           panel:initData({
    //             uid = mapInstance.playerID,
    //             name = mapInstance.playerName,
    //             uPos = endPoint,
    //             instanceID = instanceID,
    //             instanceType = instanceType,
    //             otherData = tipButtonData,
    //             subMapID = buildClassID,
    //             objId = objId
    //           })
    //           panel:show()
    //         end
    //         if instanceType and instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild and kingdomMapCtrl:isForbidMapObjWar(instanceType) then
    //           SoraDShowMsgTip(i18n("Battlefield_queue_text_011"))
    //           return
    //         end
    //         local selfLeagueID = allianceMgr:getOwnTeamID() or 0
    //         if instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild or selfLeagueID > 0 then
    //           local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(mapInstance.leagueID)
    //           local action = i18n("common_text_007")
    //           if selfLeagueID == 0 then
    //             SoraDShowMsgTip(i18n("common_text_3063", {action = action}))
    //             return
    //           elseif allianceRelationType == gMapAllianceRelationType.ALLY then
    //             SoraDShowMsgTip(i18n("common_text_3067", {action = action}))
    //             return
    //           elseif allianceRelationType == gMapAllianceRelationType.FRIENDLY then
    //             local showMsg = i18n("common_text_3066", {action = action})
    //             SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //               if callType == MSGBOX_CALLBACK_YES then
    //                 detectSafeStateFunc(handler(self, localFunction))
    //               end
    //             end)
    //             return
    //           end
    //         end
    //         detectSafeStateFunc(handler(self, localFunction))
    //       end
  } else if (lTipButtonType == EWorldMapTipButtonType::qianru){
    //       local buffCtrl = gametop.playertop_:getModule("buffCtrl")
    //       if buffCtrl:getBuffEffect(gBuffEffect.SNEAK_INTO) then
    //         local kid = mapInstance:getSourceKingdomID()
    //         local uid = mapInstance.playerID
    //         lordInfoCtrl:reqSneakInto(kid, uid)
    //       else
    //         local lordSkillDesRead = include("lordSkillDesRead")
    //         local qianruName = lordSkillDesRead.getName(LORD_SKILL_QIANRU)
    //         local buffid = lordSkillDesRead.getBuffID(LORD_SKILL_QIANRU)
    //         local isOpen, _ = buffCtrl:isBuffOpen(buffid)
    //         local lordSkillModuleAPI = include("lordSkillModuleAPI")
    //         local isInCD, _ = lordSkillModuleAPI:skillInCD(tostring(LORD_SKILL_QIANRU))
    //         if isOpen then
    //         elseif isInCD then
    //           SoraDShowMsgTip(i18n("common_text_4054", {skill = qianruName}))
    //         else
    //           SoraDShowMsgBox(i18n("common_text_4053", {skill = qianruName}), i18n("common_text_054"), nil, function(callType)
    //             if callType == MSGBOX_CALLBACK_YES then
    //               local panel = SoraDCreatePanel("skillNewActiveView")
    //               panel:selectItem(LORD_SKILL_QIANRU)
    //               panel:show()
    //             end
    //           end)
    //         end
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::xuanZhan){
    //       if kingdomMapCtrl:isForbitWar() then
    //         SoraDShowMsgTip(i18n("common_text_3445"))
    //         return
    //       end
    //       if (mapInstance.isSafe or mapInstance.isInAllianceWar and mapInstance:isInAllianceWar()) and mapInstance.playerID ~= self.myPlayerID then
    //         SoraDShowMsgTip(i18n("notice_0159"))
    //         return
    //       end
    //       do
    //         local instanceType = mapInstance:getInstanceType()
    //         local isConWar = conquestWarCtrl:isConquestWarOpenningAndNotInWar()
    //         if lordInfoCtrl:getIsTraitor() and isConWar then
    //           SoraDShowMsgTip(i18n("worldwar_text_01"))
    //           return
    //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
    //           SoraDShowMsgTip(i18n("remains_text_142"))
    //           return
    //         elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.checkIsInBornArea(endPoint) then
    //           SoraDShowMsgTip(i18n("remains_text_158"))
    //           return
    //         elseif mapInstance.betray and 0 < mapInstance.betray and isConWar then
    //           SoraDShowMsgTip(i18n("worldwar_text_02"))
    //           return
    //         end
    //         local instanceID = mapInstance:getInstanceID()
    //         local function localFunction()
    //           local panel = SoraDCreatePanel("worldMapMassView")
    //           panel:bindData({
    //             uPos = endPoint,
    //             dispatchType = dispatchType,
    //             instanceID = instanceID,
    //             instanceType = instanceType
    //           })
    //           panel:show()
    //         end
    //         local selfLeagueID = allianceMgr:getOwnTeamID() or 0
    //         local action = i18n("common_text_009")
    //         if selfLeagueID == 0 then
    //           SoraDShowMsgTip(i18n("common_text_583"))
    //           return
    //         end
    //         if instanceType and instanceType == gMapObjTypeDef.mapTypeATBuilding and SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
    //           SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
    //           return
    //         end
    //         if instanceType and instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild and kingdomMapCtrl:isForbidMapObjWar(instanceType) then
    //           SoraDShowMsgTip(i18n("Battlefield_queue_text_012"))
    //           return
    //         end
    //         if instanceType == gMapObjTypeDef.mapObjTypeSuperResource or instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild then
    //           local radioation = mapInstance.radioation
    //           local size = mapInstance.size
    //           local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
    //           if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
    //             SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
    //             return
    //           end
    //         end
    //         if instanceType == gMapObjTypeDef.stronghold then
    //           local radioation = mapInstance.radioation
    //           local size = mapInstance.size
    //           local selfLeagueID = allianceMgr:getOwnTeamID() or 0
    //           local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
    //           if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
    //             SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
    //             return
    //           end
    //         end
    //         if instanceType == gMapObjTypeDef.nebulaWarBuilding then
    //           local nebulaWarUtil = include("nebulaWarUtil")
    //           if not nebulaWarUtil.checkBuildCanAttack(mapInstance) then
    //             return
    //           end
    //           if not tipButtonData.isCanOccupy then
    //             SoraDShowMsgBox(i18n("nebula_war_text_0087"), i18n("common_text_829"), nil, function(callType)
    //               if callType == MSGBOX_CALLBACK_YES then
    //                 uiManager:show("NebulaWarAroundBuild", {mapInstance = mapInstance})
    //               end
    //             end)
    //             return
    //           end
    //         end
    //         local permissionCtrl = gModuleMgr.getObject("permissionCtrl")
    //         if allianceMgr:getRealTeamID() then
    //           detectSafeStateFunc(handler(self, localFunction))
    //         elseif permissionCtrl:hasPlayerPermission(gAPermission.LAUNCH_WAR) then
    //           if instanceType == gMapObjTypeDef.mapObjTypeAllianceBuild or selfLeagueID > 0 then
    //             local allianceRelationType = allianceRelationCtrl:getRelationTypeWith(mapInstance.leagueID)
    //             if allianceRelationType == gMapAllianceRelationType.ALLY then
    //               SoraDShowMsgTip(i18n("common_text_3067", {action = action}))
    //               return
    //             elseif allianceRelationType == gMapAllianceRelationType.FRIENDLY then
    //               local showMsg = i18n("common_text_3066", {action = action})
    //               SoraDShowMsgBox(showMsg, i18n("common_text_054"), i18n("common_text_185"), function(callType)
    //                 if callType == MSGBOX_CALLBACK_YES then
    //                   detectSafeStateFunc(handler(self, localFunction))
    //                 end
    //               end)
    //               return
    //             end
    //           end
    //           detectSafeStateFunc(handler(self, localFunction))
    //         else
    //           SoraDShowMsgBox(i18n("common_text_2371", {
    //             des = i18n("common_text_2373")
    //           }), i18n("common_text_204"))
    //         end
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::tanXian){
    //       local funUnlockRead = include("funUnlockRead")
    //       local unlockLv = funUnlockRead.getUnlockLevel(gFunBuildKey.EXPLORE)
    //       if unlockLv <= SoraDGetCastleLv() then
    //         if kingdomMapCtrl:hasMyRelicsQueue() then
    //           SoraDShowMsgBox(i18n("common_text_568"), i18n("common_text_204"), nil, nil)
    //         else
    //           if not tipButtonData.leftTime then
    //             return
    //           end
    //           local instanceID = mapInstance:getInstanceID()
    //           local tanXianPanel = SoraDCreatePanel("worldMapRemainsPopMenu")
    //           tanXianPanel:initView({
    //             leftime = tipButtonData.leftTime,
    //             instanceID = instanceID,
    //             parentArgToPoint = endPoint,
    //             parentArgDispatchType = tipButtonType
    //           })
    //           tanXianPanel:show()
    //         end
    //       else
    //         SoraDShowMsgTip(i18n("common_text_2122", {
    //           name = i18n("common_text_459"),
    //           lv = unlockLv
    //         }))
    //       end
  }else if(lTipButtonType == EWorldMapTipButtonType::zhuangTai){
    //       local instanceType = mapInstance:getInstanceType()
    //       local armyData = tipButtonData.army
    //       print("\231\130\185\229\135\187\231\138\182\230\128\129\230\140\137\233\146\174", instanceType)
    //       if instanceType == gMapObjTypeDef.mapObjTypeBattlefieldSite then
    //         local panel = SoraDCreatePanel("worldMapPyramidBatteryStateView")
    //         local siteClassID = mapInstance:getSiteClassID()
    //         panel:initData(mapInstance, {
    //           uPos = endPoint,
    //           instanceType = instanceType,
    //           buildClassID = mapInstance.buildClassID,
    //           armyData = armyData,
    //           siteClassID = siteClassID,
    //           objId = mapInstance:getObjId()
    //         })
    //         panel:show()
    //       elseif instanceType == gMapObjTypeDef.mapObjTypeLegendLord then
    //         local siteClassID = mapInstance:getSiteClassID()
    //         local hegemonRead = include("hegemonRead")
    //         if hegemonRead.isLegendLordBuilding(siteClassID) then
    //           dump(worldMapDefine.currentMapKindomID, "worldMapDefine.currentMapKindomID")
    //           if worldMapDefine.currentMapKindomID == worldMapDefine.LEGENDLORD_KINGDOM_ID then
    //             local legendaryKingView = SoraDCreatePanel("legendaryKingView")
    //             legendaryKingView:show()
    //             legendaryKingView:init({viewType = 2, bid = siteClassID})
    //           else
    //             uiManager:show("KingStarBattle", {viewType = 2, bid = siteClassID})
    //           end
    //         else
    //           local hegemonView = SoraDCreatePanel("hegemonView")
    //           hegemonView:show()
    //           hegemonView:init({bid = siteClassID})
    //         end
    //       elseif instanceType == gMapObjTypeDef.mapObjTypeRemainsWar then
    //         local panel = SoraDCreatePanel("remainsWarStateView")
    //         local siteClassID = mapInstance:getSiteClassID()
    //         panel:show()
    //         panel:initData(mapInstance, {
    //           uPos = endPoint,
    //           instanceType = instanceType,
    //           buildClassID = mapInstance.buildClassID,
    //           armyData = armyData,
    //           siteClassID = siteClassID
    //         })
    //       elseif instanceType == gMapObjTypeDef.mapObjTypeCastale or instanceType == gMapObjTypeDef.mapObjTypeBattery or instanceType == gMapObjTypeDef.mapObjTypeFortress then
    //         local panel = SoraDCreatePanel("batteryStateView")
    //         panel:initData(mapInstance, {
    //           uPos = endPoint,
    //           armyData = armyData,
    //           armyNum = tipButtonData.armyNum,
    //           instanceType = instanceType
    //         })
    //         panel:show()
    //       elseif instanceType == gMapObjTypeDef.mapTypeRadianceWarPalace or instanceType == gMapObjTypeDef.mapTypeRadianceWarGate or instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon then
    //         local siteClassID = mapInstance:getSiteClassID()
    //         local panel = SoraDCreatePanel("radianceWarStateView")
    //         panel:initData(mapInstance, {
    //           uPos = endPoint,
    //           armyData = armyData,
    //           armyNum = tipButtonData.armyNum,
    //           instanceType = instanceType,
    //           siteClassID = siteClassID
    //         })
    //         panel:show()
    //       elseif instanceType == gMapObjTypeDef.mapTypeAtlantisWarBuilding then
    //         local subType = mapInstance:getSubType()
    //         local panel
    //         if gWorldTypeServerDef.subMapTypeAtlantisWarBattery == subType then
    //           panel = SoraDCreatePanelByFixName("atlantisWarBatteryStateView")
    //         else
    //           panel = SoraDCreatePanelByFixName("atlantisWarFortStateView")
    //         end
    //         panel:initData(mapInstance, tipButtonData)
    //         panel:show()
    //       elseif instanceType == gMapObjTypeDef.stronghold then
    //         local panel = SoraDCreatePanel("worldStrongPointView")
    //         panel:initData(mapInstance, armyData, worldMapDefine.currentMapKindomID)
    //         panel:show()
    //       elseif instanceType == gMapObjTypeDef.nebulaWarBuilding then
    //         uiManager:show("NebulaWarBuildInfo", {
    //           subType = mapInstance:getSubType(),
    //           siteClassID = mapInstance:getSiteClassID(),
    //           tipButtonData = tipButtonData,
    //           mapInstance = mapInstance
    //         })
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::guanZhi){
    //       local panel = SoraDCreatePanel("worldMapKingdomCityOfficialManagerView")
    //       panel:initView()
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::intetior){
    //       local kid = mapInstance.kingdomID
    //       local intetiorUtil = include("intetiorUtil")
    //       intetiorUtil:openView(kid)
  } else if(lTipButtonType == EWorldMapTipButtonType::renMing){
    //       local panel = SoraDCreatePanel("worldMapKingdomCityAppointView")
    //       panel:initData(1, mapInstance.playerID)
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::leaguerenMing){
    //       local legendaryKingGrantViewLayer = SoraDCreatePanel("legendaryKingGrantView")
    //       legendaryKingGrantViewLayer:show()
    //       if mapInstance.leagueName then
    //       else
    //       end
    //       local otherInfo = {
    //         uid = mapInstance.playerID,
    //         name = i18n("common_text_186", {
    //           abbr = mapInstance.leagueName,
    //           name = mapInstance.playerName
    //         }) or mapInstance.playerName
    //       }
    //       legendaryKingGrantViewLayer:init({grantType = 2}, otherInfo)
  }else if(lTipButtonType == EWorldMapTipButtonType::kingStar_renMing){
    //       local kingStarGrantViewLayer = SoraDCreatePanel("kingStarGrantView")
    //       kingStarGrantViewLayer:show()
    //       if mapInstance.leagueName then
    //       else
    //       end
    //       local otherInfo = {
    //         uid = mapInstance.playerID,
    //         name = i18n("common_text_186", {
    //           abbr = mapInstance.leagueName,
    //           name = mapInstance.playerName
    //         }) or mapInstance.playerName
    //       }
    //       kingStarGrantViewLayer:init({grantType = 2}, otherInfo)
  } else if(lTipButtonType == EWorldMapTipButtonType::hegemonrenMing){
    //       local grantView = SoraDCreatePanel("hegemonGrantView")
    //       grantView:show()
    //       local bid = hegemonCtrl:getJoinBid()
    //       if mapInstance.leagueName then
    //       else
    //       end
    //       local otherInfo = {
    //         bid = bid,
    //         uid = mapInstance.playerID,
    //         name = i18n("common_text_186", {
    //           abbr = mapInstance.leagueName,
    //           name = mapInstance.playerName
    //         }) or mapInstance.playerName
    //       }
    //       grantView:init({grantType = 2, bid = bid}, otherInfo)
  } else if(lTipButtonType == EWorldMapTipButtonType::prisonerIn){
    //       local kid = mapInstance.kingdomID
    //       local uid = mapInstance.playerID
    //       local panel = SoraDCreatePanel("heroWantedBoard")
    //       panel:req4Info(uid, kid)
    //       if mapInstance:isSysWarProtect() then
    //         panel:setIsSysWarProtect(true)
    //       end
    //       panel:show()
  }else if(lTipButtonType == EWorldMapTipButtonType::remains_buff){
    //       local kid = mapInstance.kingdomID
    //       local uid = mapInstance.playerID
    //       local panel = SoraDCreatePanel("remainsWarBuff")
    //       panel:req4Info(uid, kid)
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::remains_watchTower){
    //       local kid = mapInstance.kingdomID
    //       local uid = mapInstance.playerID
    //       local teamId = mapInstance.leagueID
    //       local anchorUtil = include("anchorUtil")
    //       anchorUtil.doWatchTower(kid, uid, teamId)
  } else if(lTipButtonType == EWorldMapTipButtonType::remains_allianceWar){
    //       local kid = mapInstance.kingdomID
    //       local uid = mapInstance.playerID
    //       local teamId = mapInstance.leagueID
    //       local anchorUtil = include("anchorUtil")
    //       anchorUtil.doAllianceWar(kid, uid, teamId)
  } else if(lTipButtonType == EWorldMapTipButtonType::remains_mail){
    //       local kid = mapInstance.kingdomID
    //       local uid = mapInstance.playerID
    //       local anchorUtil = include("anchorUtil")
    //       anchorUtil.doMail(kid, uid)
  } else if(lTipButtonType == EWorldMapTipButtonType::guanliWangguo){
    //       worldMapDefine.kingdomStatusManager = true
    //       local panel = SoraDCreatePanel("worldMapKingdomCityOfficialManagerView")
    //       panel:initView()
    //       panel:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::zuduiYuanzhu){
    //       do
    //         local instanceType = mapInstance:getInstanceType()
    //         local function localFunction()
    //           local instanceID = mapInstance:getInstanceID()
    //           local panel = SoraDCreatePanel("worldMapMassView")
    //           panel:bindData({
    //             uPos = endPoint,
    //             dispatchType = dispatchType,
    //             instanceID = instanceID,
    //             instanceType = instanceType
    //           })
    //           panel:show()
    //         end
    //         if instanceType == gMapObjTypeDef.mapObjTypeCastale or instanceType == gMapObjTypeDef.mapObjTypeBattery or instanceType == gMapObjTypeDef.mapObjTypeLegendLord or instanceType == gMapObjTypeDef.mapObjTypeRemainsWar or instanceType == gMapObjTypeDef.mapTypeRadianceWarPalace or instanceType == gMapObjTypeDef.mapTypeRadianceWarGate or instanceType == gMapObjTypeDef.mapTypeRadianceWarBeacon or instanceType == gMapObjTypeDef.stronghold or instanceType == gMapObjTypeDef.mapObjTypeFortress then
    //           local selfLeagueID = allianceMgr:getOwnTeamID() or 0
    //           if selfLeagueID == 0 then
    //             SoraDShowMsgTip(i18n("common_text_583"))
    //             return
    //           end
    //           if lordInfoCtrl:getIsTraitor() and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
    //             SoraDShowMsgTip(i18n("worldwar_text_01"))
    //             return
    //           elseif self.mapClassType == gKingdomClassType.remains and remainsWarUtil.isForbitWarByInBorn() then
    //             SoraDShowMsgTip(i18n("remains_text_142"))
    //             return
    //           elseif mapInstance.betray and 0 < mapInstance.betray and conquestWarCtrl:isConquestWarOpenningAndNotInWar() then
    //             SoraDShowMsgTip(i18n("worldwar_text_02"))
    //             return
    //           end
    //           if instanceType == gMapObjTypeDef.stronghold then
    //             local isOwn = include("buildLogic").isOwnBuild(BUILDID.HALL_OF_WAR)
    //             if not isOwn then
    //               SoraDShowMsgTip(i18n("common_text_2125"))
    //               return
    //             end
    //             local radioation = mapInstance.radioation
    //             local size = mapInstance.size
    //             local selfLeagueID = allianceMgr:getOwnTeamID() or 0
    //             local selfManorRect = cc.rect(tonumber(endPoint.x) - radioation, tonumber(endPoint.y) - radioation, 2 * radioation + size - 1, 2 * radioation + size - 1)
    //             if not self.target_:isInSelfLeagueManor(selfLeagueID, selfManorRect) then
    //               SoraDShowMsgTip(i18n("alliance_stronghold_text_096"))
    //               return
    //             end
    //           end
    //           local permissionCtrl = gModuleMgr.getObject("permissionCtrl")
    //           if allianceMgr:getRealTeamID() or permissionCtrl:hasPlayerPermission(gAPermission.LAUNCH_WAR) then
    //             detectSafeStateFunc(handler(self, localFunction))
    //           else
    //             SoraDShowMsgBox(i18n("common_text_2371", {
    //               des = i18n("common_text_2373")
    //             }), i18n("common_text_204"))
    //           end
    //         else
    //           localFunction()
    //         end
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::luomaZhanhunLaixi){
    //       uiManager:show("RomanSoulNew")
  } else if(lTipButtonType == EWorldMapTipButtonType::yayun){
    //       if SoraDGetCastleLv() < 12 then
    //         SoraDShowMsgTip(i18n("common_text_2483"))
    //         return
    //       end
    //       do
    //         local escortCtrl = gametop.playertop_:getModule("escortCtrl")
    //         local hasEscortQueue = escortCtrl:hasEscortQueue()
    //         if hasEscortQueue then
    //           SoraDShowMsgTip(i18n("common_text_2349"), "#icon_escort_convey.png")
    //           return
    //         end
    //         local closestBuild = escortCtrl.dataMgr:getClosestBuild()
    //         dump(closestBuild, "\230\138\188\232\191\144\230\156\128\232\191\145\231\154\132\229\187\186\231\173\145\231\130\185---", 10)
    //         local instanceID = mapInstance.instanceID
    //         print("instanceID    = ", instanceID)
    //         local instanceType = mapInstance:getInstanceType()
    //         if closestBuild and closestBuild.mapObjId == instanceID then
    //           print("\230\152\175\230\156\128\232\191\145\231\154\132\231\130\185----------------")
    //           local worldEscortBeginView = SoraDCreatePanel("worldEscortBeginView")
    //           worldEscortBeginView:initWithData({
    //             dispatchData = {
    //               toPoint = endPoint,
    //               dispatchType = dispatchType,
    //               instanceID = instanceID,
    //               instanceType = instanceType
    //             }
    //           })
    //           worldEscortBeginView:show()
    //         elseif closestBuild and closestBuild.mapObjId ~= nil then
    //           print("\228\184\141\230\152\175\230\156\128\232\191\145\231\154\132\231\130\185")
    //           SoraDShowMsgBox(i18n("common_text_2319"), i18n("common_text_054"), i18n("common_text_185"), function(eventType)
    //             if eventType == MSGBOX_CALLBACK_YES then
    //               SoraDGotoWorldMapPoint(cc.p(closestBuild.x, closestBuild.y), true)
    //             end
    //           end)
    //         else
    //           print("\230\151\160\230\179\149\229\136\164\230\150\173\230\152\175\230\156\128\232\191\145\231\154\132\230\138\188\232\191\144\231\130\185-------------")
    //           SoraDShowLoading(self.target_)
    //           self.isReqClosestBuild = true
    //           self.reqEscortId = instanceID
    //           self.reqEscortData = {
    //             dispatchData = {
    //               toPoint = endPoint,
    //               dispatchType = dispatchType,
    //               instanceID = instanceID,
    //               instanceType = instanceType
    //             }
    //           }
    //           escortCtrl:reqGetClosestBuild()
    //         end
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::tuijianlueduo){
    //       local escortCtrl = gametop.playertop_:getModule("escortCtrl")
    //       if escortCtrl:isReachRobLimit() then
    //         SoraDShowMsgTip(i18n("common_text_2354"), "#icon_escort_convey.png")
    //         return
    //       end
    //       local worldRecommandEscortView = SoraDCreatePanel("worldRecommandEscortView")
    //       worldRecommandEscortView:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::junqing){
    //       local worldEscortLogView = SoraDCreatePanel("worldEscortLogView")
    //       worldEscortLogView:show()
  } else if(lTipButtonType == EWorldMapTipButtonType::baoxiang){
    //       local panel = SoraDCreatePanel("legendaryFirstKill")
    //       local buildID = mapInstance:getSiteClassID()
    //       panel:init(buildID, mapInstance)
    //       panel:show()
  } else if(
    lTipButtonType == EWorldMapTipButtonType::alliancepet_1 ||
    lTipButtonType == EWorldMapTipButtonType::alliancepet_2 ||
    lTipButtonType == EWorldMapTipButtonType::alliancepet_3 ||
    lTipButtonType == EWorldMapTipButtonType::alliancepet_4
  ){
    //       local alliancePetCtrl = gametop.playertop_:getModule("alliancePetCtrl")
    //       local state = alliancePetCtrl:getAlliancePetState()
    //       if state == _G.gAlliancePetState.CALL then
    //         local callTimeCD = alliancePetCtrl:getAlliancePetCallTimeCD()
    //         if callTimeCD <= 0 then
    //           SoraDCreatePanel("alliancePetSelectView"):show()
    //         else
    //           SoraDCreatePanel("alliancePetReduceTimeView"):show()
    //         end
    //       elseif state == _G.gAlliancePetState.TRIAL then
    //         worldMapFunction.GotoTrialMass(endPoint, mapInstance.instanceID)
    //       else
    //         SoraDCreatePanel("alliancePetMainView"):show()
    //       end
  } else if(lTipButtonType == EWorldMapTipButtonType::tanmingmibao){
    //       if SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
    //         SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
    //       elseif not allianceMgr:hasJoinAlliance() then
    //         SoraDShowMsgTip(i18n("common_text_826"))
    //       elseif mapInstance.treasureState == gATBuildingStatus.AT_EXPLORE then
    //         local panel = SoraDCreatePanel("eventAncientSecretExploreView")
    //         panel:initData(mapInstance)
    //         panel:show()
    //       elseif mapInstance.treasureState == gATBuildingStatus.AT_MINNING then
    //         local panel = SoraDCreatePanel("eventAncientSecretDigView")
    //         panel:initData(mapInstance)
    //         panel:show()
    //       end
  } 
  else if(lTipButtonType == EWorldMapTipButtonType::wajuexiangqing){
    //       local panel = SoraDCreatePanel("eventAncientSecretDigDetailView")
    //       panel:initData(mapInstance)
    //       panel:show()
  }
  else if(lTipButtonType == EWorldMapTipButtonType::zuduiwajue){
    //       if not allianceMgr:hasJoinAlliance() then
    //         SoraDShowMsgTip(i18n("common_text_826"))
    //       elseif SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
    //         SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
    //       else
    //         local instanceID = mapInstance:getInstanceID()
    //         local instanceType = mapInstance:getInstanceType()
    //         local panel = SoraDCreatePanel("worldMapMassView")
    //         panel:bindData({
    //           uPos = mapInstance.pos,
    //           dispatchType = dispatchType,
    //           instanceID = mapInstance:getInstanceID(),
    //           instanceType = instanceType
    //         })
    //         panel:show()
    //       end
  }
  else if(lTipButtonType == EWorldMapTipButtonType::wajue){
    //       if not allianceMgr:hasJoinAlliance() then
    //         SoraDShowMsgTip(i18n("common_text_826"))
    //       elseif SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
    //         SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
    //       elseif SoraDEnoughTroops() then
    //         local dispatchPanel = include("worldDispatchArmyView").new()
    //         dispatchPanel:initData({
    //           toPoint = mapInstance:getTilePoint(),
    //           dispatchType = worldMapDefine.worldMapTipButtonType_wajue,
    //           instanceID = mapInstance:getInstanceID()
    //         })
    //         dispatchPanel:show()
    //       end
  }
  else if(lTipButtonType == EWorldMapTipButtonType::treasuremap_wajue){
    //       if SoraDEnoughTroops() then
    //         local dispatchPanel = include("worldDispatchArmyView").new()
    //         dispatchPanel:initData({
    //           toPoint = mapInstance:getTilePoint(),
    //           dispatchType = worldMapDefine.worldMapTipButtonType_treasuremap_wajue,
    //           instanceID = mapInstance:getInstanceID()
    //         })
    //         dispatchPanel:show()
    //       end
  }
  else if(lTipButtonType == EWorldMapTipButtonType::sign){
    //       local gametop = gModuleMgr.getObject("gametop")
    //       local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
    //       local panel = SoraDCreatePanel("worldMapSignRename")
    //       panel:setSignInfo({
    //         signature = lordInfoCtrl:getSignature()
    //       })
    //       panel:show()
  }
  else if(lTipButtonType == EWorldMapTipButtonType::duel){
  //       local instanceID = mapInstance:getInstanceID()
  //       local instanceType = mapInstance:getInstanceType()
  //       local finTime = tipButtonData.antiDuelTimeFin or 0
  //       local duelFinTime = finTime - serviceFunctions.systemTime()
  //       if finTime > 0 and duelFinTime > 0 then
  //         SoraDShowMsgTip(i18n("lordskill_text_12", {
  //           time = SoraDConvertSecondToStringNoDay(duelFinTime)
  //         }))
  //         return
  //       end
  //       if mapInstance.isSafe then
  //         SoraDShowMsgTip(i18n("notice_0159"))
  //         return
  //       end
  //       local dispatchPanel = include("worldDispatchArmyView").new()
  //       dispatchPanel:initData({
  //         toPoint = mapInstance:getTilePoint(),
  //         dispatchType = worldMapDefine.worldMapTipButtonType_duel,
  //         instanceID = mapInstance:getInstanceID()
  //       })
  //       dispatchPanel:show()
  }
  else if(lTipButtonType == EWorldMapTipButtonType::anniversary_flame){
    //       local anniversaryFlameCtrl = SoraDGetCtrl("anniversaryFlameCtrl")
    //       if not anniversaryFlameCtrl:isCampCreated() then
    //         if SoraDGetCastleLv() < CASTLE_LV6_LIMITED then
    //           SoraDShowMsgTip(i18n("common_text_1795", {num = CASTLE_LV6_LIMITED}))
    //         else
    //           local panel = SoraDCreatePanel("anniversaryFlamePopCreate")
    //           panel:show()
    //         end
    //         return
    //       end
    //       if SoraDEnoughTroops() then
    //         local armyData = {
    //           dispatchType = worldMapDefine.worldMapTipButtonType_anniversary_flame,
    //           toPoint = mapInstance:getTilePoint(),
    //           instanceID = mapInstance:getInstanceID()
    //         }
    //         worldMapFunction.gotoDispatch(armyData, true)
    //       end
  }
  else if(lTipButtonType == EWorldMapTipButtonType::explore){
  //       local towerLv = cityCtrl:getBuildMaxLv(BUILDID.WATCH_TOWER)
  //       if towerLv <= 1 then
  //         SoraDShowMsgTip(i18n("alliance_stronghold_text_111"))
  //         return
  //       end
  //       local starTreasureCtrl = SoraDGetCtrl("starTreasureCtrl")
  //       if SoraDEnoughTroops() then
  //         local armyData = {
  //           dispatchType = worldMapDefine.worldMapTipButtonType_explore,
  //           toPoint = mapInstance:getTilePoint(),
  //           instanceID = mapInstance:getInstanceID()
  //         }
  //         worldMapFunction.gotoDispatch(armyData, true)
  //       else
  //         SoraDShowMsgTip(i18n("ramadanTreasure_text02"))
  //         return
  //       end
  }
  else if(lTipButtonType == EWorldMapTipButtonType::ramadan_world_explore){
    //       if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.RAMADAN_WORLD_EXPLORER) then
    //         local taskIdx = mapInstance:getRamdanWorldTaskIndex()
    //         uiManager:show("RamadanWorldExplorerTask", {
    //           taskIdx = taskIdx,
    //           endPoint = endPoint,
    //           instanceID = mapInstance:getInstanceID()
    //         })
    //       else
    //         SoraDShowMsgTip(i18n("common_text_1859"))
    //         return
    //       end
  }
}

void WorldMapComButton::RemoveTroopBindingPanel(EventCustom *pEvent){}





