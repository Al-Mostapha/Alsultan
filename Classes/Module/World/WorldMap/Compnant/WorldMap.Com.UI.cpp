#include "WorldMap.Com.UI.h"
#include "WorldMap.Com.Lod.h"
#include "Module/City/City.Ctrl.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.World.h"
#include "Base/Common/Common.Box.h"
#include "Base/Utils/Utils3D.h"
#include "Module/Player/Player.Top.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/World/Kingdom/Kingdom.Ctrl.h"
#include "Module/UI/Part/World/WorldMap/Main/UIWorldMapGotoPointPanel.h"
#include "Module/UI/Part/World/WorldMap/UIWorldMapFaceToDistance.h"
#include "Module/UI/Panel/World/WorldMap/Overlay/UIWorldMapBottomPoint.h"
#include "Module/UI/Panel/World/WorldMap/Overlay/UIWorldMapBookMark.View.h"
#include "Module/UI/Panel/World/WorldMap/Floor/UIWorldMapTroop.Tip.h"

void WorldMapComUI::Ctor(){

}

void WorldMapComUI::Init(){
  // worldMapComUI.super.init(self)
  IWorldMapComponent::Init();
  _MapClassType = _Target->_MapClassType;
  _DisplayCenterPoint = _Target->_DisplayCenterPoint;
  _TileSize = _Target->_TileSize;
  _MyCityTilePoint = CityCtrl::Get()->GetCurCityPos();
  _IsHideDis = false;
  _MapViewCenterPoint = _Target->_MapViewCenterPoint;
  _NodeBottom = GBase::DGetChildByName<Node *>(_Target, "Node_bottom");
  _NodeBottom->setPositionY(160 + GDisplay::Get()->iPhoneXBottom);
  _BottomPointNode = GBase::DGetExtendChildFromCCSByName<UIWorldMapBottomPoint>(_Target, "CCS_worldMapBottomPoint_1");
  _BottomPointNode->addTouchEventListener(CC_CALLBACK_2(WorldMapComUI::BottomPointOnClick, this));
  _FaceToDistanceNode = GBase::DGetWorldMapFaceToDistanceNode();
  _FaceToDistanceNode->addTouchEventListener(CC_CALLBACK_2(WorldMapComUI::FaceToDistanceOnClick, this));
  _ButtonWorldResouce = GBase::DGetChildByName<ui::Button *>(_Target, "Button_worldResource");
  if(_ButtonWorldResouce){
    _ButtonWorldResouce->addTouchEventListener(CC_CALLBACK_2(WorldMapComUI::ButtonWorldResouceCall, this));
    if(_MapClassType == EKingdomClassType::NewTrial){
      _ButtonWorldResouce->setVisible(false);
    }
  }

  _ButtonFavorite = GBase::DGetChildByName<ui::Button *>(_Target, "Button_favorite");
  if(_ButtonFavorite){
    _ButtonFavoriteStar = GBase::DGetChildByName<ui::ImageView *>(_ButtonFavorite, "Image_star");
    _ButtonFavoriteStar->setVisible(false);
    _ButtonFavorite->addTouchEventListener(CC_CALLBACK_2(WorldMapComUI::ButtonFavoriteCall, this));
    //   self:serverMessage_addBookMark(self, {checkData = true})
    if(_MapClassType == EKingdomClassType::NewTrial){
      _ButtonFavorite->setVisible(false);
    }
  }
  
  _ButtonMyCity = GBase::DGetChildByName<ui::Button *>(_Target, "Button_myCity");
  if(_ButtonMyCity){
    _ButtonMyCity->setVisible(false);
    if(_MyKindomID != WorldMapDefine::Get()->CurrentMapKindomID){
      _ButtonMyCity->setVisible(true);
    }
    
    if(_MapClassType == EKingdomClassType::LegendLord){
      auto lTextMyCity = GBase::DGetChildByName<ui::Text *>(_ButtonMyCity, "Text_myCity");
      lTextMyCity->setString(Translate::i18n("common_title_01"));
    }else if(_MapClassType == EKingdomClassType::Remains || _MapClassType == EKingdomClassType::NewTrial){
      _ButtonMyCity->setVisible(false);
    }else{
      auto lTextMyCity = GBase::DGetChildByName<ui::Text *>(_ButtonMyCity, "Text_myCity");
      lTextMyCity->setString(Translate::i18n("common_text_4580"));
    }
    _ButtonMyCity->addTouchEventListener(CC_CALLBACK_2(WorldMapComUI::ButtonMyCityCall, this));
  }

  if(_BottomPointNode){
    ShowOrHideGuideView();
  }
}

void WorldMapComUI::Relogin(){
  IWorldMapComponent::Relogin();
  _MyCityTilePoint = CityCtrl::Get()->GetCurCityPos();
  UpdateFaceToDistance();
}

void WorldMapComUI::ResetData(){
  _MyKindomID = PlayerTop::Get()->GetMapID();
}

void WorldMapComUI::OnMessageListener(){
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_WORLD_RESOURCE_MAP_MEMBERS", CC_CALLBACK_1(WorldMapComUI::ServerMessage_LeagueMembersInfo, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_COLLECTMAP_SUCCESS", CC_CALLBACK_1(WorldMapComUI::ServerMessage_AddBookMark, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_WORLD_MAP_UPDATE_SELF_POINT", CC_CALLBACK_1(WorldMapComUI::ServerMessage_UpdateSelfPoint, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_GUIDE_HIDE_AND_SHOW", CC_CALLBACK_1(WorldMapComUI::ShowOrHideGuideView, this));
  GBase::DAddMessage(_Target, "MESSAGE_SERVER_WORLD_MAP_DISTANCE_VISIBLE", CC_CALLBACK_1(WorldMapComUI::ShowOrHideDistance, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_DID, CC_CALLBACK_1(WorldMapComUI::UpdateFaceToDistance, this));
  UpdateFaceToDistance();
}

void WorldMapComUI::ShowOrHideDistance(EventCustom *pEvent){
  if(!pEvent){
    _IsHideDis = false;
  }else if(!pEvent->getUserData()){
    _IsHideDis = false;
  }
  else{
    _IsHideDis = *(bool *)pEvent->getUserData();
  }
  UpdateFaceToDistance();
}

void WorldMapComUI::ServerMessage_UpdateSelfPoint(EventCustom *pEvent){
  _MyCityTilePoint = *static_cast<Vec2 *>(pEvent->getUserData());
  _Target->MoveTilePointToCenter(_MyCityTilePoint);
}

void WorldMapComUI::ServerMessage_LeagueMembersInfo(EventCustom *pEvent){
  // if data and (not data.clientData or data.clientData.from ~= "worldMapComUI") then
  //   return
  // end
  // local currentInMapViewCell = self.target_.currentInMapViewCell
  // SoraDCloseLoading(self.buttonWorldResouce)
  // local centerPoint = currentInMapViewCell:convertToNodeSpace(self.displayCenterPoint)
  // centerPoint = SoraDCoverToPoint2DOr3D(currentInMapViewCell, centerPoint, currentInMapViewCell)
  // local subPoint = cc.pSub(self.mapViewCenterPoint, centerPoint)
  // local ratio = worldMapDefine.worldResourceMapSize.width / worldMapDefine.worldMapViewSize.width
  // subPoint = cc.p(subPoint.x * ratio, subPoint.y * ratio)
  // local memberArray = {}
  // if data and data.data then
  //   local dataArray = data.data
  //   for _, v in pairs(dataArray) do
  //     if v.x and v.y then
  //       local tilePoint = cc.p(v.x - 1, v.y - 1)
  //       local point = self.target_:getPointWithTile(tilePoint)
  //       local subPt = cc.pSub(self.mapViewCenterPoint, point)
  //       v.x = subPt.x * ratio
  //       v.y = subPt.y * ratio
  //       table.insert(memberArray, v)
  //     end
  //   end
  // end
  // local warType_config = {
  //   [gKingdomClassType.pyramid] = "pyramidBattleMapView",
  //   [gKingdomClassType.legendLord] = "legendLordMapView",
  //   [gKingdomClassType.remains] = "remainsMapView",
  //   [gKingdomClassType.atlantis] = "atlantisResourceMap"
  // }
  // local panelName = warType_config[self.mapClassType]
  // if panelName then
  //   local panel = SoraDSearchPanelFromManagerByName(panelName)
  //   if not panel then
  //     panel = SoraDCreatePanel(panelName)
  //     panel:show()
  //     panel:setLeagueMembersInfo(memberArray)
  //     SoraDSendMessage({
  //       msg = "MESSAGE_WORLD_RESOURCEMAP_MOVETOCENTER",
  //       subPoint = subPoint
  //     })
  //   end
  // elseif self.mapClassType == gKingdomClassType.radiance then
  //   local panel = SoraDSearchPanelFromManagerByName("radianceWarMapView")
  //   if not panel then
  //     local radianceWarMapView = SoraDCreatePanelByFixName("radianceWarMapView")
  //     radianceWarMapView:show()
  //     radianceWarMapView:setLeagueMembersInfo(memberArray)
  //     radianceWarMapView:setEnterType("worldMapView")
  //     SoraDSendMessage({
  //       msg = "MESSAGE_WORLD_RESOURCEMAP_MOVETOCENTER",
  //       subPoint = subPoint
  //     })
  //     SoraDGetCtrl("radianceWarCtrl"):radianceWarMatchResult()
  //   end
  // else
  //   local resourceMap = SorDShowWorldResourceMap()
  //   resourceMap:setLeagueMembersInfo(memberArray)
  //   resourceMap:setWrathBeastInfo()
  //   resourceMap:setEndlessTrialsInfo()
  //   SoraDSendMessage({
  //     msg = "MESSAGE_WORLD_RESOURCEMAP_MOVETOCENTER",
  //     subPoint = subPoint
  //   })
  // end
}


void WorldMapComUI::ServerMessage_AddBookMark(EventCustom *pEvent){
  // if not data.checkData then
  //   SoraDShowMsgTip(i18n("common_text_494"))
  // end
  // local haveLook = false
  // for _, v in pairs(gCollectTempData) do
  //   if v.isLook == false then
  //     haveLook = true
  //   end
  // end
  // self.buttonFavoriteStar:setVisible(haveLook)
}

void WorldMapComUI::ShowOrHideGuideView(EventCustom *pEvent){
  // local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  // local guideStep = guideCtrl:getCurForceGuideStep()
  // self.bottomPointNode:setVisible(false)
  // if self.buttonFavorite then
  //   self.buttonFavorite:setVisible(false)
  // end
  // self.buttonWorldResouce:setVisible(false)
  // if not guideStep then
  //   self.bottomPointNode:setVisible(true)
  //   if self.mapClassType ~= gKingdomClassType.newTrial then
  //     if self.buttonFavorite then
  //       self.buttonFavorite:setVisible(true)
  //     end
  //     self.buttonWorldResouce:setVisible(true)
  //   end
  // end
}

void WorldMapComUI::BottomPointOnClick(Ref* pSender, ui::Widget::TouchEventType pType){
  if(pType != ui::Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  auto lHideKingIDTextField = false;
  if(_Target->_IsSingleMapCell)
    lHideKingIDTextField = true;
  
  auto lGotoPanel = UIWorldMapGotoPointPanel::Create(lHideKingIDTextField);
  lGotoPanel->Show();
  auto lCovertCenterTilePoint = _BottomPointNode->_TilePoint;
  if(lHideKingIDTextField){
    lGotoPanel->UpdateData(WorldMapDefine::Get()->CurrentMapKindomID, lCovertCenterTilePoint);
  }else{
    lGotoPanel->UpdateData(_MyKindomID, lCovertCenterTilePoint);
  }
}

void WorldMapComUI::FaceToDistanceOnClick(Ref* pSender, ui::Widget::TouchEventType pType){
  if(pType != ui::Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  if(_CurrentTroopTip){
    auto lMoveLineID = _CurrentTroopTip->GetMoveLineID();
    static RRemoveTroopTipData sRemoveTroopTipData;
    sRemoveTroopTipData._MoveLineID = lMoveLineID;
    GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_TROOPTIP", &sRemoveTroopTipData);
  }
  _Target->MoveTilePointToCenter(_MyCityTilePoint);
}

void WorldMapComUI::ButtonWorldResouceCall(Ref* pSender, ui::Widget::TouchEventType pType){
  if(pType != ui::Widget::TouchEventType::ENDED)
    return;

  GBase::PlaySound();

  if(_Target->GetComponent<WorldMapComLod>("WorldMapComLod")){
    RGotoTilePointNewEvAr lGotoTilePointEvArgs;
    lGotoTilePointEvArgs._ToScale = WorldMapViewDef::Get()->MIN_SCALE;
    lGotoTilePointEvArgs._NeedAction = true;
    _Target->GotoTilePointNew(lGotoTilePointEvArgs);
    return;
  }

  if(!GBase::DGetLoading(_ButtonWorldResouce)){
    auto lLoading = GBase::DShowLoading(_ButtonWorldResouce, Size(50, 50));
    lLoading->setPosition(Vec2(60, 60));
  }

  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");

  auto lReqMember = true;
  if(_MapClassType == EKingdomClassType::LegendLord){
    //     bReqMember = false
    //     local teamCtrl = include("legendTeamUtil").getCurTeamCtrl(worldMapDefine.currentMapKindomID)
    //     if teamCtrl:isHasTeam() then
    //       kingdomMapCtrl:reqAllianceMember(worldMapDefine.currentMapKindomID, teamCtrl:getTeamID(), {
    //         from = "worldMapComUI"
    //       })
    //     else
    //       self:serverMessage_LeagueMembersInfo()
    //     end
  }else if(_MapClassType == EKingdomClassType::Pyramid){
    //     if not worldMapDefine.isInPyramid() then
    //       self:serverMessage_LeagueMembersInfo()
    //       bReqMember = false
    //     end
  } else if(_MapClassType == EKingdomClassType::Nebula) {
    //     self:serverMessage_LeagueMembersInfo()
    //     bReqMember = false
  }
  //   if bReqMember then
  //     kingdomMapCtrl:reqAllianceMember(nil, nil, {
  //       from = "worldMapComUI"
  //     })
  //   end
}

void WorldMapComUI::ButtonFavoriteCall(Ref* pSender, ui::Widget::TouchEventType pType){
  if(pType != ui::Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
  auto lPanel = UIWorldMapBookMarkView::Create();
  lPanel->Show();
}

void WorldMapComUI::ButtonMyCityCall(Ref* pSender, ui::Widget::TouchEventType pType){
  if(pType != ui::Widget::TouchEventType::ENDED)
    return;
    
  GBase::PlaySound();
  if(WorldMapDefine::Get()->IsLegendLordKingdomID() && WorldMapDefine::Get()->IsInLegendLord()){
    auto lKID = PlayerTop::Get()->GetKingdomID();
    GBase::DGotoWorldMapPoint(Vec2(600, 600), false, lKID ? lKID : _MyKindomID);
  }else if(WorldMapDefine::Get()->IsPyramidKingdomID() && !WorldMapDefine::Get()->IsInPyramid()){
    GBase::DGotoWorldMapPoint(_MyCityTilePoint, false, _MyKindomID, EWorldMapLayInstance::None, {}, true);
  }else {
    GBase::DGotoWorldMapPoint(_MyCityTilePoint, false, _MyKindomID);
  }
}

void WorldMapComUI::UpdateFaceToDistance(EventCustom *pEvent){

  auto lCurrentInMapViewCell = _Target->_CurrentInMapViewCell;
  auto lCovertCenterTilePoint = lCurrentInMapViewCell->TilePositionFromLocation(_DisplayCenterPoint);

  if(lCovertCenterTilePoint.x >= 0 && 0 <= lCovertCenterTilePoint.y){
    int32 lKingdomID;
    if(_MyKindomID != lCurrentInMapViewCell->_KingdomID){
      lKingdomID = lCurrentInMapViewCell->_KingdomID;
      auto lIsK = KingdomCtrl::Get()->IsFoundKingdomID(lKingdomID);
      if(!lIsK){
        lKingdomID = 0;
      }
    }
    _BottomPointNode->UpdateData(lCovertCenterTilePoint, _MyKindomID);
  }

  if(_MyKindomID != lCurrentInMapViewCell->_KingdomID){
    if(_MapClassType != EKingdomClassType::Remains && _MapClassType != EKingdomClassType::NewTrial){
    _FaceToDistanceNode->setVisible(false);
    _ButtonMyCity->setVisible(true);
    }else{
      _FaceToDistanceNode->setVisible(false);
      _ButtonMyCity->setVisible(false);
    }
    return;
  }else if(!WorldMapDefine::Get()->IsLegendLordKingdomID(lCurrentInMapViewCell->_KingdomID)){
    _ButtonMyCity->setVisible(false);
  }

  _FaceToDistanceNode->setVisible(!_IsHideDis);
  auto lDistance = std::ceil(_MyCityTilePoint.getDistance(lCovertCenterTilePoint));
  if(!_FaceToDistanceNode)
  return;
  if(lCovertCenterTilePoint.x >= 0 && 0 <= lCovertCenterTilePoint.y)
    _FaceToDistanceNode->UpdateData(lDistance);
  
  auto lMyCityPoint = lCurrentInMapViewCell->GetPointWithTile(_MyCityTilePoint);
  lMyCityPoint.y -= _TileSize.height / 2;

  Vec2 lMyCityDisplayPoint;
  if(lDistance < 20)
    lMyCityDisplayPoint = GBase::DProjec2ScreenPos2DOr3D(lCurrentInMapViewCell, {lMyCityPoint.x, lMyCityPoint.y, 0});
  else
    lMyCityDisplayPoint = GBase::DVerticalProject2ScreenPos2DOr3D(lCurrentInMapViewCell, lMyCityPoint);

  auto lShowRect = Rect(60, 150, GDisplay::Get()->width - 120, GDisplay::Get()->height - 240);
  auto [lIsIntersect, lIntersectPointArray] = GBase::DLineIntersectRect(_DisplayCenterPoint, lMyCityDisplayPoint, lShowRect);
  if(lIsIntersect && lIntersectPointArray.size() > 0){
    _FaceToDistanceNode->setVisible(!_IsHideDis);
    _FaceToDistanceNode->setPosition(lIntersectPointArray[0]);
    auto lRotation = GBase::DGetAngleByPos(_DisplayCenterPoint, lMyCityDisplayPoint);
    _FaceToDistanceNode->SetArrowRotation(-lRotation);
  }else{
    _FaceToDistanceNode->setVisible(false);
  }
}
