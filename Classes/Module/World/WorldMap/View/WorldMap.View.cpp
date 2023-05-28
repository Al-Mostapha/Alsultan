#include "WorldMap.View.h"
#include "WorldMap.ViewFactory.h"
#include "WorldMapView.Def.h"
#include "WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/Player/Player.Top.h"
#include "Global/Global.h"
#include "Engine/XTiledMap/XTiledLayer.h"

typedef EWorldMapZOrder Z_ORDER;

WorldMapView *WorldMapView::Create(RViewClass p_Config, RViewOtherData p_OtherData){
  WorldMapView *l_View = nullptr;
  if(p_Config._CcsFile == "")
    l_View = Create("UiParts/Panel/World/WorldMap/worldMapViewNormal.csb");
  else  
    l_View = Create("UiParts/Panel/World/WorldMap/" + p_Config._CcsFile + ".csb");
  l_View->Ctor(p_Config, p_OtherData);
  return l_View;
}

void WorldMapView::Ctor(RViewClass p_Config, RViewOtherData p_OtherData){
  _Config = p_Config;
  AddComponents(p_Config);
  InitParam();
  InitView();
  // self:callComFunc("init")
  // self:initOther()
  // self._ccsView:setLocalZOrder(Z_ORDER.otherTipView)
  // self:setAnchorPoint(cc.p(0, 0))
  // self:setPosition(cc.p(0, 0))
}

void WorldMapView::InitParam(){
  // if param then
  //   self.initTilePoint = param.tilePoint
  //   self.initIsSelected = param.isSelected or false
  //   self.layInstanceType = param.layInstance or worldMapLayInstanceTypeDef.layInstanceNone
  //   self.layInstanceData = param.layInstanceData
  // else
  //   self.initIsSelected = false
  //   self.layInstanceType = worldMapLayInstanceTypeDef.layInstanceNone
  //   self.layInstanceData = nil
  // end
  // if not self.initTilePoint then
  //   local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //   self.initTilePoint = cityCtrl:getCurCityPos()
  // end
}

void WorldMapView::InitView(){
  _MapClassType = _Config._MapClassType;
  _CreateCustomLayer = _Config._CreateCustomLayer;
  InitData();
  InitMapCell();
}

void WorldMapView::InitData(){
  _DisplayCenterPoint = Vec2(GDisplay::Get()->rcx, GDisplay::Get()->rcy);
  _ReqMapCenterPoint = Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy);
  if( KingdomMapCtrl::Get()->GetKingdomClass() != EKingdomClassType::None)
    _MapKingdomClassType = KingdomMapCtrl::Get()->GetKingdomClass();
  _MyKindomID = PlayerTop::Get()->GetMapID();
  _MinTime = WorldMapViewDef::Get()->MIN_TIME_DRAG;
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
  this->addChild(_ContainerViewNode, static_cast<int32>(Z_ORDER::containerViewNode));
  _ContainerView = ui::Layout::create();
  _ContainerView->setName("containerView");
  InitTmx();
  InitMapCell_imp();
  InitScrollView();
  //_TmxView->setPosition(_CurrentInMapViewCell->getPosition());
  auto _TmxViewSize = _TmxView->getContentSize();
  _TmxView->setPosition(Vec2(-_TmxViewSize.width/2, -_TmxViewSize.height/2)); 
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
    // _GroundLayer->setVisible(false);
    // _MapLayer = _GroundLayer;
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
  this->addChild(_ViewScrollView, static_cast<int32>(Z_ORDER::scrollView));
  InitScrollDid();
}

void WorldMapView::InitScrollDid(){

}

float WorldMapView::GetBottomQuestBtnsOffsetY(){
  return 0.0f;
}