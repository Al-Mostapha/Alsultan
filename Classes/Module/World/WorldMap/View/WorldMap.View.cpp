#include "WorldMap.View.h"
#include "WorldMap.ViewFactory.h"
#include "WorldMapView.Def.h"
#include "WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/MapSyncUtilClient.h"
#include "Module/Player/Player.Top.h"
#include "Global/Global.h"
#include "Engine/XTiledMap/XTiledMap.h"
#include "Engine/XTiledMap/XTileLayer.h"
#include "Module/City/City.Ctrl.h"
#include "Base/Common/Common.Box.h"
#include "Base/Utils/Utils3D.h"
#include "Base/Base.Geometry.h"

typedef EWorldMapZOrder Z_ORDER;

WorldMapView *WorldMapView::Create(RViewClass p_Config, RViewOtherData p_OtherData){
  WorldMapView *l_View = nullptr;
  if(p_Config._CcsFile == "")
    l_View = Create("UiParts/Scene/World/worldMapViewNormal.csb");
  else  
    l_View = Create("UiParts/Scene/World/" + p_Config._CcsFile + ".csb");
  l_View->Ctor(p_Config, p_OtherData);
  return l_View;
}

void WorldMapView::Ctor(RViewClass p_Config, RViewOtherData  p_Param){
  _Config = p_Config;
  AddComponents(p_Config, this);
  InitParam(p_Param);
  InitView();
  CallComFuncInit();
  CallComFuncOnMessageListener();
  InitOther();
  setLocalZOrder(static_cast<int32>(Z_ORDER::otherTipView));
  setAnchorPoint(Vec2(0, 0));
  setPosition(Vec2(0, 0));
}

void WorldMapView::InitParam(RViewOtherData p_Param){
  if(p_Param){
    _InitTilePoint = p_Param._TilePoint;
    _InitIsSelected = p_Param._IsSelected;
    _LayInstance = p_Param._LayInstance;
    //   self.layInstanceData = param.layInstanceData
  }else{
    _InitIsSelected = false;
    _LayInstance = EWorldMapLayInstance::None;
    //   self.layInstanceData = nil
  }
  if(_InitTilePoint == Vec2::ZERO){
    _InitTilePoint = CityCtrl::Get()->GetCurCityPos();
  }
}

void WorldMapView::InitView(){
  _MapClassType = _Config._MapClassType;
  _CreateCustomLayer = _Config._CreateCustomLayer;
  InitData();
  InitMapCell();
}

void WorldMapView::InitMapCell(){
  if(_Config._MinScale != 0.0f)
    WorldMapViewDef::Get()->MIN_SCALE = _Config._MinScale;
  else if(_Config._NoScaleLimit)
    WorldMapViewDef::Get()->MIN_SCALE = WorldMapViewDef::Get()->MIN_SCALE_NO_LIMIT;
  else
    WorldMapViewDef::Get()->MIN_SCALE = WorldMapViewDef::Get()->MIN_SCALE_DEFAULT;

  if(_Config._NormalScale != 0.0f)
    WorldMapViewDef::Get()->NORMAL_SCALE = _Config._NormalScale;
  else
    WorldMapViewDef::Get()->NORMAL_SCALE = WorldMapViewDef::Get()->NORMAL_SCALE_DEFAULT;
  _ContainerViewNode = GDisplay::Get()->NewNode();
  addChild(_ContainerViewNode, static_cast<int32>(Z_ORDER::containerViewNode));
  _ContainerView = ui::Layout::create();
  _ContainerView->setName("containerView");
  InitTmx();
  InitMapCell_imp();
  InitScrollView();
  //_TmxView->setPosition(_CurrentInMapViewCell->getPosition());
  auto _TmxViewSize = _TmxView->getContentSize();
  _TmxView->setPosition(Vec2(0, 0)); 
}

void WorldMapView::InitOther(){
  _LoadingPos = Vec2(GBase::DFPosX(575.f), 160 + GDisplay::Get()->iPhoneXBottom );
}

void WorldMapView::OnSwitchMapViewCell(){
  if(_CurrentInMapViewCell)
    _TmxView->setPosition(_CurrentInMapViewCell->getPosition());
  getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_CELL_CHANGE);
}

void WorldMapView::OnSwapMapViewCell(){
  if(_CurrentInMapViewCell)
    _TmxView->setPosition(_CurrentInMapViewCell->getPosition());
  getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_CELL_SWAP);
}

void WorldMapView::InitScrollView(){
  _ViewScrollView = Ext::ScrollView::create(Size(GDisplay::Get()->rwidth, GDisplay::Get()->rheight));
  _ViewScrollView->setName("viewScrollView");
  _ViewScrollView->setContainer(_ContainerView);
  _ViewScrollView->setClippingToBounds(false);
  _ViewScrollView->setMinScale(WorldMapViewDef::Get()->MIN_SCALE);
  _ViewScrollView->setMaxScale(WorldMapViewDef::Get()->MAX_SCALE);
  _ViewScrollView->setZoomScale(WorldMapViewDef::Get()->NORMAL_SCALE);
  _ViewScrollView->setBounceable(false);
  // self.viewScrollView:setInertiaValue(1)
  // if self.viewScrollView.setScrollSpeed then
  //   self.viewScrollView:setScrollSpeed(4)
  //   self.viewScrollView:setScrollAcceleration(-3)
  // end
  _ViewScrollView->setPosition(Vec2(0, 0));
  addChild(_ViewScrollView, static_cast<int32>(Z_ORDER::scrollView) + 10);
  InitScrollDid();
}

void WorldMapView::InitTmx(){
  
  if(WorldMapDefine::Get()->IsNebulaKingdomID()){
    //   local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
    //   local round = nebulaActivityCtrl:getDataByKey("initData").round
    //   if round <= 3 then
    //     tileMapTmx = tileMapTmx[1]
    //   else
    //     tileMapTmx = tileMapTmx[2]
    //   end
  } else if(WorldMapDefine::Get()->IsLegendLordKingdomID()){
    //   if worldMapDefine.isKingStarMapId(worldMapDefine.currentMapKindomID) then
    //     tileMapTmx = tileMapTmx[2]
    //   else
    //     tileMapTmx = tileMapTmx[1]
    //   end
  }
  
  _TmxView = XTiledMap::create(_Config._TileMapTmx);
  _TmxView->setName("tileMapTmx");
  _TmxView->setIgnoreAnchorPointForPosition(false);
  _TmxView->setAnchorPoint(Vec2(0.5f, 0.5f));
  _TmxView->setCascadeOpacityEnabled(true);
  _TmxView->setCascadeColorEnabled(true);

  if(_MapClassType == EKingdomClassType::Radiance){
    //   local worldMapComTmx = include("worldMapComTmx")
    //   local mapLayer = tmxview:getLayer("desert")
    //   self.mapLayer = worldMapComTmx.new(mapLayer)
    //   self.mapLayer:init(tmxview, {
    //     {name = "grassland", beginGID = 196},
    //     {name = "marsh", beginGID = 294}
    //   })
    //   local groundLayer = tmxview:getLayer("desert-object")
    //   self.groundLayer = worldMapComTmx.new(groundLayer)
    //   self.groundLayer:init(tmxview, {
    //     {
    //       name = "grassland-object",
    //       beginGID = 294
    //     },
    //     {
    //       name = "marsh-object",
    //       beginGID = 392
    //     }
    //   })
    //   self.groundLayer_marsh = tmxview:getLayer("gate")
    //   if self.mapLayer.setBeginShowGid then
    //     self.mapLayer:setBeginShowGid(4)
    //   end
  }else if(_MapClassType == EKingdomClassType::Atlantis){
    //   local worldMapComTmx = include("worldMapComTmx")
    //   self.mapLayer = tmxview:getLayer("tile")
    //   self.mapLayer:setVisible(false)
    //   local groundLayer = tmxview:getLayer("tile01")
    //   self.groundLayer = worldMapComTmx.new(groundLayer)
    //   self.groundLayer:init(tmxview, {
    //     {name = "water", beginGID = 0}
    //   })
  } else if(_MapClassType == EKingdomClassType::Nebula){
   //   self.groundLayer = tmxview:getLayer("tile")
    //   self.mapLayer = self.groundLayer
    //   self.mapLayer:setVisible(false)
  } else if(_MapClassType == EKingdomClassType::Normal){
    //   local worldMapComTmx = include("worldMapComTmx")
    auto l_GroundLayer = _TmxView->getLayer("control");
    //   self.groundLayer = worldMapComTmx.new(groundLayer)
    //   self.groundLayer:init(tmxview, nil, {
    //     name = "control",
    //     beginGID = 0,
    //     mapGID = {
    //       [95] = 5,
    //       [96] = 99
    //     }
    //   })
    _GroundLayer = l_GroundLayer;
    _GroundLayer->setVisible(true);
    _MapLayer = _GroundLayer;
  } else {
    //   self.mapLayer = tmxview:getLayer("tile")
    //   self.mapLayer:setName("tile")
    //   self.groundLayer = tmxview:getLayer("ground")
    //   self.groundLayer:setName("ground")
    //   if self.mapLayer.setBeginShowGid then
    //     self.mapLayer:setBeginShowGid(4)
    //   end
  }

  _TileSize = _TmxView->getTileSize();
  _MapViewSize = _TmxView->getContentSize();
  _MapSize = _TmxView->getMapSize();
  _ContainerView->addChild( _TmxView, static_cast<int32>(Z_ORDER::tmxView));    
  _MapViewCenterPoint = Vec2(_MapViewSize.width / 2, _MapViewSize.height / 2);
  WorldMapDefine::Get()->_WorldMapViewSize = _MapViewSize;
  if(_CreateCustomLayer != ""){
    //   self:createCustomMapLayer(self._tmxview, self.createCustomLayer)
  }
}

WorldMapCell *WorldMapView::CreateOneMapCell(){
  auto l_MapViewCell = WorldMapCell::Create(this);
  l_MapViewCell->ignoreAnchorPointForPosition(false);
  l_MapViewCell->setAnchorPoint(Vec2(0.5f, 0.5f));
  l_MapViewCell->SetKingdomId(WorldMapDefine::Get()->CurrentMapKindomID);
  _ContainerView->addChild(l_MapViewCell, static_cast<int32>(Z_ORDER::containerView));
  if(WorldMapWarDef::Get()->IsInWarForbidBonePoing(_MapClassType)){
    l_MapViewCell->AddShowBonePoing(_MapClassType);
  }
  l_MapViewCell->SetTouchPlayerCallFunc(CC_CALLBACK_2(WorldMapView::ViewOnClick, this));
  return l_MapViewCell;
}

void WorldMapView::InitData(){
  _DisplayCenterPoint = Vec2(GDisplay::Get()->rcx, GDisplay::Get()->rcy);
  _ReqMapCenterPoint = Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy);
  if( KingdomMapCtrl::Get()->GetKingdomClass() != EKingdomClassType::None)
    _MapKingdomClassType = KingdomMapCtrl::Get()->GetKingdomClass();
  _MyKindomID = PlayerTop::Get()->GetMapID();
  _MinTime = WorldMapViewDef::Get()->MIN_TIME_DRAG;
}

void WorldMapView::InitTimer(){
  static bool l_IsMoved;
  GBase::DCreateTimer(this, [this](float p_Dt){
    if(_IsNeedRefreshScroll > 0){
      RefreshScroll();
    }
    UpdateShowTileInstance();
    l_IsMoved = _IsMoved;
    getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_UPDATE_INFO, &l_IsMoved);
    UpdateDelayFrame();
  }, true, 1);
}

void WorldMapView::OnMessageListener(){
  if(_IsFinishInit)
    OnMessageListener_FinishLoadImage();
}

void WorldMapView::FinishLoadImages(){
  _IsFinishInit = true;
  InitTimer();
  InitEvent();
  OnMessageListener_FinishLoadImage(true);
  MoveTilePointToCenter(_InitTilePoint, _InitIsSelected, _LayInstanceType, _LayInstanceData);
  GBase::DCloseSwitcherView();
  GBase::DCloseLoginView();
  EndShow();
}

void WorldMapView::InitEvent(){
  getEventDispatcher()->addCustomEventListener(WorldMapEvent::Get()->EVENT_TOOGLE_3D, CC_CALLBACK_1(WorldMapView::Toggle3D, this));
  // self:addEventListener(worldMapEvent.EVENT_TILED_DEBUG, function()
  //   self._tmxview:toggleDebugLayer()
  // end)
}

void WorldMapView::OnMessageListener_FinishLoadImage(bool p_Add){
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_GOTO_FOREG_BACK_GROUD", CC_CALLBACK_1(WorldMapView::GotoForeBackGroud, this));\
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", CC_CALLBACK_1(WorldMapView::RefreshRelogin, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_GOTO_TILEPOINT", CC_CALLBACK_1(WorldMapView::GotoTilePointOld, this));
  GBase::DAddMessage(this, "MESSAGE_WORLD_MAP_MOVETOCENTER_SUBPOINT", CC_CALLBACK_1(WorldMapView::MoveSubPointToCenter, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_WORLD_MAP_GET_RECT_DATA", CC_CALLBACK_1(WorldMapView::ServerMessage_GetRectData, this));
  if(p_Add){
    CallComFuncOnMessageListener();
    getEventDispatcher()->addCustomEventListener(
      WorldMapEvent::Get()->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapView::UpdateLodChange, this));
  }
}

void WorldMapView::RefreshScroll(){
  _IsNeedRefreshScroll = 0;
  ScrollFromBorder();
  UpdateCenterAreaTiles();
  UpdateMapPos();
  getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_SCROLL_DID);
}

void WorldMapView::scrollViewDidScroll(Ext::ScrollView* view){
  _IsNeedRefreshScroll++;
  static bool l_IsMoved;
  if(_IsNeedRefreshScroll > 0){
    RefreshScroll();
  }
  UpdateShowTileInstance();
  l_IsMoved = _IsMoved;
  getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_UPDATE_INFO, &l_IsMoved);
  UpdateDelayFrame();
}

void WorldMapView::scrollViewDidZoom(Ext::ScrollView* view){
}

void WorldMapView::InitScrollDid(){
  _ViewScrollView->setDelegate(this);
}

auto DELAY_SPEED = 10;
auto LODCHECK = EWorldLodDef::LOD4;

void WorldMapView::UpdateCenterAreaTiles(){
  EWorldLodDef l_Lod = GetCurLod();
  auto l_LodCheck = l_Lod > LODCHECK ? l_Lod : LODCHECK;
  if(_PreCenterPoint == 0){
    UpdateCheckSetMapViewCellPoint();
    _ReqcenterTilePos = _CurrentInMapViewCell->TilePositionFromLocation(_ReqMapCenterPoint, true);
    _SendTilePos = _ReqcenterTilePos;
    _PreCenterPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_Lod);
    _PreCheckPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_LodCheck);
    GetMapTilesData();
    DelUnshowMoveLine();
    // SetDisplayCenterTilePoint(_ReqcenterTilePos);
    return;
  }

  auto l_ReqcenterTilePos = _CurrentInMapViewCell->TilePositionFromLocation(_ReqMapCenterPoint);
  auto l_PiecePos = MapSyncUtilClient::Get()->GetPieceId(l_ReqcenterTilePos, _MapClassType, l_LodCheck);
  if(l_PiecePos != _PreCheckPoint){
    _PreCheckPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_LodCheck);
    UpdateCheckSetMapViewCellPoint();
  }
  //SetDisplayCenterTilePoint(_ReqcenterTilePos);
  l_ReqcenterTilePos = _CurrentInMapViewCell->TilePositionFromLocation(_ReqMapCenterPoint, true);
  l_PiecePos = MapSyncUtilClient::Get()->GetPieceId(l_ReqcenterTilePos, _MapClassType, l_Lod);
  if(l_PiecePos != _PreCenterPoint){
    _ReqcenterTilePos = _CurrentInMapViewCell->TilePositionFromLocation(_ReqMapCenterPoint, true);
    auto l_Distance = _SendTilePos.distance(l_ReqcenterTilePos);
    if(_PreClockTime){
      auto l_CurTime = GOS::Get()->GetTime();
      auto l_Time = l_CurTime - _PreClockTime;
      if(l_Time == 0)
        return;
      else if(l_Time > 0){
        auto l_V = l_Distance / l_Time;
        if(l_V > DELAY_SPEED){
          _PreCenterPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_Lod);
          _IsDelay = true;
          _DelayTime = _MinTime;
          _PreClockTime = l_CurTime;
          return;
        }else if(l_Time < _MinTime){
          _PreCenterPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_Lod);
          _IsDelay = true;
          _DelayTime = _MinTime;
          return;
        }
      }else{
        _PreClockTime = l_CurTime;
      }
    }
    _PreCenterPoint = MapSyncUtilClient::Get()->GetPieceId(_ReqcenterTilePos, _MapClassType, l_Lod);
    _SendTilePos = _ReqcenterTilePos;
    _IsDelay = false;
    GetMapTilesData();
    DelUnshowMoveLine();
  }
}

void WorldMapView::UpdateDelayFrame(float p_Dt){
  if(!_IsDelay)
    return;
  _DelayTime -= p_Dt;
  if(_DelayTime <= 0){
    _IsDelay = false;
    _PreCenterPoint = 0;
    UpdateCenterAreaTiles();
  }
}

void WorldMapView::CloseLoading(){
  if(!_LoadView)
    return;
  GBase::DCloseLoading();
  _LoadView = nullptr;
}

void WorldMapView::UpdateShowTileInstance(){
  if(HasShowTilesData())
    return;
  if(_IsWaitForData){
    GBase::DCloseLoading();
    CloseLoading();
  }
  if(
    _GotoSelectTilePoint != Vec2::ZERO && 
    (_CanDoSelected || _NeedShowHand) && 
    !_IsDelay && GetCurLod() == EWorldLodDef::LOD1 
    /*&& ( !_IsWaitForData || GetShowInstance(_GotoSelectTilePoint))*/){
    GBase::DCreateDelayTimer(this, [this](){
      OnClickInstance(_GotoSelectTilePoint);
      _GotoSelectTilePoint = Vec2::ZERO;
    }, 1);
    ShowHandTip();
    _CanDoSelected = false;
  }

  if(_GotoTransferCityPoint  == Vec2::ZERO && _CanDoTransfer){
    GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
    GBase::DCreateDelayTimer(this, [this](){
      //       local event = {
      //         name = worldMapEvent.EVENT_TRANS,
      //         layInstanceType = self.layInstanceType,
      //         pos = self.gotoTransferCityPoint,
      //         layInstanceData = self.layInstanceData
      //       }
      //       self:dispatchEvent(event)
      _GotoTransferCityPoint = Vec2::ZERO;
    }, 1);
    _CanDoTransfer = false;
  }
}

void WorldMapView::ShowHandTip(){
  // if self.needShowHand then
  //   if not self.fingerNode then
  //     self.fingerNode = SoraDCreatAnimationEx("animationFinger", nil, true)
  //     self.fingerNode:getChildByName("Node_effect"):setVisible(false)
  //     self.fingerNode:getChildByName("shouzhi"):setVisible(true)
  //     self.fingerNode:setName("fingerNode")
  //     self.fingerNode:addTo(self.containerViewNode)
  //   else
  //     self.fingerNode.action:gotoFrameAndPlay(0, true)
  //   end
  //   self.fingerNode:stopActionByTag(233)
  //   self.fingerNode:setVisible(true)
  //   local seq = cca.seq({
  //     cca.delay(5),
  //     cca.callFunc(function()
  //       self.fingerNode:stopActionByTag(233)
  //       self.fingerNode:setVisible(false)
  //     end)
  //   })
  //   seq:setTag(233)
  //   self.fingerNode:runAction(seq)
  //   local showPoint = self:getPointWithTile(self.gotoSelectTilePoint)
  //   local screenPoint = SoraDConvertoScreenPos2DOr3D(self.currentInMapViewCell, showPoint)
  //   local coverShowPoint = self.containerViewNode:convertToNodeSpace(screenPoint)
  //   self.fingerNode:setPosition(coverShowPoint)
  //   self.gotoSelectTilePoint = nil
  // end
}

void WorldMapView::HideHandTip(){
  // if self.fingerNode then
  //   self.fingerNode:setVisible(false)
  //   self.fingerNode:stopActionByTag(233)
  // end
}


void WorldMapView::OnClickInstance(Vec2 p_TilePos, WorldMapCell *p_MapCell){

  // mapViewCell = mapViewCell or self.currentInMapViewCell
  if(!p_MapCell)
    p_MapCell = _CurrentInMapViewCell;
  if(RemoveSelectShowPanel() && !_CanDoSelected)
    return;
  // local tileInstance = self:getShowInstance(tilePos)
  // if (not tileInstance or tileInstance:getInstanceType() ~= gMapObjTypeDef.mapObjTypeKingdomLevelBuild) and kingdomMapCtrl:checkIsInNormalFog(tilePos, mapViewCell.kingdomID) then
  //   SoraDPlaySound()
  //   if mapViewCell.kingdomID == self.myKindomID then
  //     SoraDShowMsgBoxNew(i18n("alliance_stronghold_text_072"), i18n("common_text_477"), nil, function(exitType, target)
  //       if exitType == MSGBOX_CALLBACK_YES then
  //         local mildGuideManager = gModuleMgr.sharedMgr("mildGuideManager")
  //         mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.ANNALS)
  //       end
  //     end)
  //   else
  //     SoraDShowMsgTip(i18n("alliance_stronghold_text_094"))
  //   end
  //   return
  // end
  // self:hideHandTip()
  // local returnData = mapViewCell:onClickInstance(tilePos, tileInstance, self.containerView, self.containerViewNode)
  // if not returnData then
  //   return
  // end
  // self:onClickInstance_imp(returnData)
}

Vec2 WorldMapView::GetPointWithTile(Vec2 p_TilePoint){
  auto l_TileWidth = _TileSize.width;
  auto l_TileHeight = _TileSize.height;
  auto l_TilePoint = _MapLayer->getPositionAt(p_TilePoint);
  auto l_Point = Vec2(l_TilePoint.x + l_TileWidth / 2, l_TilePoint.y + l_TileHeight / 2);
  return l_Point;
}

void WorldMapView::GetMapTilesData(){
  auto l_SendMsg = GetMapTilesData_imp();
  if(l_SendMsg){
    _IsWaitForData = true;
    if(_MapClassType != EKingdomClassType::NewTrial && !GBase::DGetLoading(this)){
      auto  l_Loading = GBase::DShowLoading(this, Size(50, 50));
      l_Loading->setSwallowTouches(false);
      l_Loading->setPosition(_LoadingPos);
    }
    _PreClockTime = GOS::Get()->GetTime();
  }
}

void WorldMapView::ViewOnClick(Ref *p_Ref, ui::Widget::TouchEventType p_Type){
  auto p_MapView = dynamic_cast<WorldMapCell *>(p_Ref);
  if(p_MapView)
    return;
  RemoveLodClickTip();
  if(p_Type ==  ui::Widget::TouchEventType::ENDED){
    if(IsTransferShow())
      ResetTransferView();
    else if(!_IsMoved){
      auto l_TouchEndPoint = p_MapView->getTouchEndPosition();
      auto l_TilePos = p_MapView->TilePositionFromLocation(l_TouchEndPoint);
      if(WorldMapDefine::Get()->IsInAtlantis()){
        //     local atlantisWarUtil = include("atlantisWarUtil")
        //     if atlantisWarUtil.checkIsBattleAreaAndNotOpen(tilePos) then
        //       SoraDShowMsgTip(i18n("atlantiswar_text_0256"))
        //       SoraDSendMessage({
        //         msg = "MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL"
        //       })
        //       return
        //     end
      }
      
      auto l_Lod = GetCurLod();
      if(l_Lod >= EWorldLodDef::LOD2){
        GBase::PlaySound();
        ShowLodClickTip(l_TilePos, l_TouchEndPoint, p_MapView->_KingdomID);
        return;
      }
      if(!CheckClickMoveLine(l_TouchEndPoint) && l_TilePos.x >= 0 && l_TilePos.y >= 0){
        OnClickInstance(l_TilePos, p_MapView);
      }
    }
    _IsMoved = false;
  }else if(p_Type == ui::Widget::TouchEventType::MOVED){
      auto l_TouchBeganPoint = p_MapView->getTouchBeganPosition();
      auto l_TouchMovePoint = p_MapView->getTouchMovePosition();
      auto l_Distance = l_TouchBeganPoint.getDistance(l_TouchMovePoint);
      if(l_Distance > TOUCH_MOVED_ERROR_VALUE)
        _IsMoved = true;
      if(IsTransferTouchIn())
        moveTransferView(l_TouchMovePoint, p_MapView);
  }
}

void WorldMapView::MoveTilePointToCenter(
  Vec2 p_TilePoint, bool p_IsSelected, EWorldMapLayInstance p_LayInstance, RLayInstanceData p_LayInstanceData,
  float p_Duration, WorldMapCell *p_MapViewCell, bool p_IsSHowHand){

  if(!p_MapViewCell)
    p_MapViewCell = _CurrentInMapViewCell;

  auto l_Duration = p_LayInstanceData._Duration;
  if(p_MapViewCell->_KingdomID != _CurrentInMapViewCell->_KingdomID){
    AddEnterOtherWorldmapCellFilm();
    CloseLoading();
    _LoadView = dynamic_cast<UICommonLoading *>(GBase::DShowLoading(nullptr, Size::ZERO, 0, false, 10));
  }
  
  auto l_MapViewPoint = p_MapViewCell->GetPointWithTile(p_TilePoint);
  // mapViewPoint = SoraDCoverToPoint2DOr3D(mapViewCell, mapViewPoint, self.containerView)
  auto l_3DPoint = GBase::DCoverToPoint2DOr3D(p_MapViewCell, l_MapViewPoint, _ContainerView);
  l_MapViewPoint.x = l_3DPoint.x;
  l_MapViewPoint.y = l_3DPoint.y;
  MoveMapPointToCenter(l_MapViewPoint, p_Duration);
  
  if(p_IsSelected){
    _GotoSelectTilePoint = p_TilePoint;
    _CanDoSelected = true;
  }
  
  if(p_IsSHowHand){
    _GotoSelectTilePoint = p_TilePoint;
    _NeedShowHand = true;
  }else{
    _NeedShowHand = false;
  }
  
  if(p_LayInstance != EWorldMapLayInstance::None){
    _GotoTransferCityPoint = p_TilePoint;
    _CanDoTransfer = true;
    _LayInstance = p_LayInstance;
    _LayInstanceData = p_LayInstanceData;
  }
}

void WorldMapView::MoveMapPointToCenter(Vec2 p_Point, float p_Duration, bool p_Container){
  auto l_ZoomScale = _ViewScrollView->getZoomScale();
  auto l_CenterPoint = _DisplayCenterPoint;
  auto l_ConvertPoint = GBase::DConvertScreenPoint2NodePos2DOr3D(_ContainerView, l_CenterPoint);
  auto l_OffsetPoint = _ViewScrollView->getContentOffset();
  auto l_SubPoint = Vec2(l_ConvertPoint.value().x, l_ConvertPoint.value().y) - p_Point;
  l_SubPoint *= l_ZoomScale;
  auto l_newOffsetPoint = l_OffsetPoint + l_SubPoint;
  
  if(p_Container){
    _ContainerView->setPosition(l_newOffsetPoint);
  }else if(p_Duration > 0){
    _ViewScrollView->setContentOffsetInDuration(l_newOffsetPoint, p_Duration);
  }else{
    _ViewScrollView->setContentOffset(l_newOffsetPoint);
  }
}

void WorldMapView::MoveSubPointToCenter(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Data = static_cast<GPair<int32, Vec2> *>(p_Event->getUserData());
  auto l_MapViewCell = GetWorldMapCell(l_Data->First, true);
  auto l_SubPoint = l_Data->Second;
  auto l_TargetPoint = _MapViewCenterPoint - l_SubPoint;
  auto l_TargetPoint3d = GBase::DCoverToPoint2DOr3D(l_MapViewCell, l_TargetPoint, _ContainerView);
  MoveMapPointToCenter(Vec2(l_TargetPoint3d.x, l_TargetPoint3d.y));
}

void WorldMapView::GotoTilePointOld(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Data = static_cast<RGotoTilePointEvAr *>(p_Event->getUserData());
  GotoTilePoint(*l_Data);
  SetZoomScale(WorldMapViewDef::Get()->NORMAL_SCALE);
  RemoveLodClickTip();
  if(IsTransferShow())
    ResetTransferView(nullptr, true);
}

void WorldMapView::GotoTilePoint(RGotoTilePointEvAr &p_Data){
  MoveTilePointToCenter(
    p_Data._TilePoint,  p_Data._IsSelected, 
    p_Data._LayInstance,  p_Data._LayInstanceData,
    0,  GetWorldMapCell(p_Data._KingdomID), p_Data._IsShowHand
  );
}

void WorldMapView::SetZoomScale(float p_Scale, float p_Duration, bool p_IsAnimated){
  if(p_Duration > 0)
    _ViewScrollView->setZoomScaleInDuration(p_Scale, p_Duration);
  else if(p_IsAnimated)
    _ViewScrollView->setZoomScale(p_Scale, true);
  else 
    _ViewScrollView->setZoomScale(p_Scale);
}

void WorldMapView::GotoTilePointNew(RGotoTilePointNewEvAr &p_Param){
  if(!p_Param._NeedAction){
    p_Param._MoveTime = 0;
    p_Param._ScaleTime = 0;
  }
  
  Vector<FiniteTimeAction *> l_ActionList;
  if(p_Param._ToTilePos != Vec2::ZERO || p_Param._OldData){
    l_ActionList.pushBack(
      CallFunc::create([&p_Param, this](){
        if(p_Param._OldData){
        auto l_LayInstanceData = p_Param._OldData._LayInstanceData;
        if(l_LayInstanceData._Duration == 0)
          l_LayInstanceData._Duration = p_Param._MoveTime;
          GotoTilePoint(p_Param._OldData);
        }else{
          auto l_OldData = RGotoTilePointEvAr();
          l_OldData._TilePoint = p_Param._ToTilePos;
          l_OldData._IsSelected = p_Param._IsSelected;
          l_OldData._LayInstanceData._Duration = p_Param._MoveTime;
          l_OldData._KingdomID = p_Param._KingdomID;
          GotoTilePoint(l_OldData);
        }
      })
    );
    l_ActionList.pushBack(DelayTime::create(p_Param._MoveTime));
  }
  
  auto l_CurScale = _ViewScrollView->getZoomScale();
  if(p_Param._ToScale && p_Param._ToScale != l_CurScale){
    l_ActionList.pushBack(CallFunc::create([p_Param, this](){
      SetZoomScale(p_Param._ToScale, p_Param._ScaleTime);
    }));
    l_ActionList.pushBack(DelayTime::create(p_Param._ScaleTime));
  }

  l_ActionList.pushBack(
    CallFunc::create([this](){
      CloseLoading();
    })
  );
  
  GBase::DShowLoading(this, Size::ZERO, 0, true);
  _ViewScrollView->runAction(Sequence::create(l_ActionList));
  CleanShowPanel();
}

void WorldMapView::RefreshRelogin(EventCustom *p_Event){
  auto l_MapKingdomClassType = KingdomMapCtrl::Get()->GetKingdomClass();
  if(l_MapKingdomClassType != _MapKingdomClassType){
    static RShowMainCityView lShowMainCityView;
    lShowMainCityView.ViewType = EScene::World;
    GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &lShowMainCityView);
    return;
  }
  _MyKindomID = PlayerTop::Get()->GetMapID();
  InitTimer();
  RefreshMapDataAndView();
  UpdateCheckSetMapViewCellPoint();
  CallComFuncRelogin();
}

void WorldMapView::RefreshMapDataAndView(){
  KingdomMapCtrl::Get()->OnSwitchWorldMap(
    ESwitchWorldMapTypeDef::Out, WorldMapDefine::Get()->CurrentMapKindomID
  );
  DoClearData();
  KingdomMapCtrl::Get()->OnSwitchWorldMap(
    ESwitchWorldMapTypeDef::In, WorldMapDefine::Get()->CurrentMapKindomID
  );
  DoRequestData();
}

void WorldMapView::DoRequestData(){
  _PreCenterPoint = -1;
  UpdateCenterAreaTiles();
  CallComFuncDoRequest();
}

void WorldMapView::UpdateLodChange(EventCustom *p_Event){
  _IsDelay = true;
  _DelayTime = 0.25;
  CleanShowPanel();
}

void WorldMapView::CleanShowPanel(){
  GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
  RemoveLodClickTip();
  if(IsTransferShow())
    ResetTransferView(nullptr, true);
}

void WorldMapView::DoClearData(){
  CallComFuncDoClearData();
  _MinTime = WorldMapViewDef::Get()->MIN_TIME_DRAG;
}

void WorldMapView::GotoForeBackGroud(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_GroundType = *static_cast<EGoTo *>(p_Event->getUserData());
  if(l_GroundType == EGoTo::ForeGround){
    DoRequestData();
  }else if(l_GroundType == EGoTo::BackGround){
    DoClearData();
  }
}

void WorldMapView::SetViewPieceIds(GVector<int32> p_ViewPieceIDs, EWorldLodDef p_Lod){
  static RViewPieceIdEvAr p_EventPar;
  p_EventPar._ViewPieceIDs = p_ViewPieceIDs;
  p_EventPar._Lod = p_Lod;
  getEventDispatcher()->dispatchCustomEvent(
    WorldMapEvent::Get()->EVENT_UPDATE_PIECE , &p_EventPar);
}

void WorldMapView::ServerMessage_GetRectData(EventCustom *p_Event){
  // if data.dataEnd then
  //   self.isWaitForData = false
  // end
  _IsWaitForData = false;
}

void WorldMapView::UpdateMapPos(){
  auto l_Pos = _ContainerView->getPosition();
  auto l_Scale = _ContainerView->getScale();
  _ContainerViewNode->setPosition(l_Pos);
  _ContainerViewNode->setScale(l_Scale);
  auto l_TilePos = _CurrentInMapViewCell->convertToNodeSpace(Vec2::ZERO);
  static Vec2 l_EventTilePos;
  l_EventTilePos = l_TilePos;
  getEventDispatcher()->dispatchCustomEvent(WorldMapEvent::Get()->EVENT_TILE_POS, &l_EventTilePos);
}

void WorldMapView::SetTmxCulledRect(XTiledMap *p_TmxView){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    auto l_Width = GDisplay::Get()->width;
    auto l_Height = GDisplay::Get()->rheight;
    auto [l_Ret, l_TouchPos] = GBase::DGet3DTouchPos(_ViewScrollView, Vec2(l_Width, l_Height));
    if(l_Ret){
      auto l_Point = GBase::ConvertToNodeSpace3D(_ViewScrollView, {l_TouchPos.x, l_TouchPos.y, l_TouchPos.z, 0});
      auto l_OffsetX = GMath::Max(l_Point.x - l_Width, 0);
      auto l_OffsetY = GMath::Max(l_Point.y - l_Height, 0);
      auto l_Rect = Rect(0, 0, l_Width + l_OffsetX, l_Height + l_OffsetY);
      //     tmxView:setCulledRect(rect)
    }
  }else{
    //   local rect = cc.rect(0, 0, display.width, display.rheight)
    //   tmxView:setCulledRect(rect)
  }
}

void WorldMapView::Toggle3D(EventCustom *p_Event){
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    _ViewScrollView->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
    //   if self.viewScrollView.setEnable3d then
    //     self.viewScrollView:setEnable3d(true)
    //   end
    auto l_Width = GDisplay::Get()->cx;
    auto l_Height = GDisplay::Get()->rheight;
    auto [l_Ret, l_Touch3DPos] = GBase::DGet3DTouchPos(this, Vec2(l_Width, l_Height));
    auto [l_Ret1, l_Touch3DPosZero] = GBase::DGet3DTouchPos(this, Vec2(l_Width, 0));
    if(l_Ret && l_Ret1){
      auto l_Center = Vec3(
        l_Touch3DPos.x,
        (l_Touch3DPos.y - l_Touch3DPosZero.y) * 0.45f,
        (l_Touch3DPos.z - l_Touch3DPosZero.z) * 0.45f
      );
      _ReqMapCenterPoint = GBase::DProject2ScreenPos3D(this, l_Center);
    }
  }else{
    _ViewScrollView->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
    //   if self.viewScrollView.setEnable3d then
    //     self.viewScrollView:setEnable3d(false)
    //   end
    _ReqMapCenterPoint = Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy);
  }
  SetTmxCulledRect(_TmxView);
  UpdateMapPos();
}

Vec2 WorldMapView::GetRadianceGatePos(){
  // local cityCtrl = SoraDGetCtrl("cityCtrl")
  // myPoint = cityCtrl:getCurCityPos()
  // local radianceWarRead = include("radianceWarRead")
  // local gateList = radianceWarRead.getBuildingList()
  // local point, minLength
  // for i, v in pairs(gateList) do
  //   if v.mapType == gWorldTypeServerDef.mapTypeRadianceWarGate then
  //     if not minLength then
  //       local offsetX = v.x - myPoint.x
  //       local offsetY = v.y - myPoint.y
  //       minLength = offsetX * offsetX + offsetY * offsetY
  //       point = cc.p(v.x - 1, v.y - 1)
  //     else
  //       local offsetX = v.x - myPoint.x
  //       local offsetY = v.y - myPoint.y
  //       local tmp = offsetX * offsetX + offsetY * offsetY
  //       if minLength > tmp then
  //         point = cc.p(v.x - 1, v.y - 1)
  //       end
  //       if minLength > tmp then
  //         minLength = tmp or minLength
  //       end
  //     end
  //   end
  // end
  // return point
  return Vec2::ZERO;
}

void WorldMapView::EndShow(){
  // local moudle = gModuleMgr.sharedMgr("mildGuideManager"):getVariate(self.__cname, "gGuideModule")
  // local guideCtrl = SoraDGetCtrl("guideCtrl")
  // print(gGuideModule.ESCORT)
  // local isMoudleDone = guideCtrl:isGuideNotCompleted(gGuideModule.ESCORT)
  // local step = guideCtrl:isStep(gGuideStep.ESCORT_STEP_1)
  // print(isMoudleDone, step)
  // dump(moudle, "\228\184\150\231\149\140\229\156\176\229\155\190\229\188\177\229\188\149\229\175\188")
  // if isstring(moudle) and #moudle > 0 and isMoudleDone and step then
  //   print("worldMapView", moudle)
  //   local View = include("gameGuideView").new()
  //   View:show()
  //   View:startGuideWithStep(67001)
  //   guideCtrl:CompleteGuideStep(67001)
  // end
}

// function worldMapView:gameGuide_callFunc(callFunc, data)
//   dump(data, "gameGuide_callFunc", 10)
//   if callFunc == "buttonWorldResouceCall" then
//     self:callComFuncArgs(callFunc, nil, ccui.TouchEventType.ended)
//     return
//   end
//   if self[callFunc] then
//     self[callFunc](self, data)
//   else
//     self:callComFunc(callFunc)
//   end
// end
// function worldMapView:gameGuide_callFunc_JumpToBuilding(data)
//   dump(data, "gameGuide_callFunc_JumpToBuilding", 10)
//   local findMonsterCtrl = SoraDGetCtrl("findMonsterCtrl")
//   if data.mapID == gWorldTypeServerDef.mapTypeRadianceWarPalace then
//     SoraDGotoWorldMapPoint({x = 599, y = 599}, true)
//   elseif data.mapID == gWorldTypeServerDef.mapTypeRadianceWarGate then
//     SoraDGotoWorldMapPoint(self:getRadianceGatePos(), true)
//   elseif data.mapID == gWorldTypeServerDef.mapTypeRadianceWarBeacon then
//     findMonsterCtrl:sendSearchRadianceWarBeaconMsg()
//   elseif data.mapID == gWorldTypeServerDef.mapTypeRadianceWarResource then
//     findMonsterCtrl:sendSearchRadianceResourcesMsg(data.subMapID, data.minLv)
//   elseif data.pos then
//     SoraDGotoWorldMapPoint(data.pos, true)
//   end
// end

WorldMapCell *WorldMapView::GetCurrentInMapViewCell(){
  return _CurrentInMapViewCell;
}



Vec2 WorldMapView::GetDisplayCenterTilePoint(){
  return _CurrentInMapViewCell->TilePositionFromLocation(_DisplayCenterPoint);
}

float WorldMapView::GetBottomQuestBtnsOffsetY(){
  return 0.0f;
}

