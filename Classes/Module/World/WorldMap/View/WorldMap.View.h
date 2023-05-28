#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "WorldMap.View.Mul.h"
#include "WorldMap.View.Object.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Global/Global.h"

#include "Engine/XTiledMap/XTiledMap.h"
#include "2d/CCFastTMXTiledMap.h"
#include "2d/CCFastTMXLayer.h"


struct RViewClass;
class WorldMapView : public UIBasePanel, public WorldMapViewMul, public WorldMapViewObject{
  CREATE_FUNC(WorldMapView);
  CreateUIPanel(WorldMapView);
  CreateUICCSView(WorldMapView);

  bool _InitIsSelected = false;
  EWorldMapLayInstanceTypeDef _LayInstanceType = EWorldMapLayInstanceTypeDef::LayInstanceNone;
  EKingdomClassType _MapClassType = EKingdomClassType::None;
  GString _CreateCustomLayer;
  Vec2 _DisplayCenterPoint;
  Vec2 _ReqMapCenterPoint;
  Vec2 _ReqcenterTilePos = Vec2::ZERO;
  Vec2 _SendTilePos = Vec2::ZERO;
  bool _IsWaitForData = false;
  Vec2 _GotoSelectTilePoint;
  Vec2 _MapViewCenterPoint;
  bool _CanDoSelected = false;
  bool _NeedShowHand = false;
  // self.gotoTransferCityPoint = nil
  bool _CanDoTransfer = false;
  bool _IsMoved = false;
  bool _IsDelay = false;
// self.preCenterPoint = nil
  int32 _DelayFrame = 0;
  int32 _IsNeedRefreshScroll = 0;
  EKingdomClassType _MapKingdomClassType = EKingdomClassType::Normal;
  int32 _MyKindomID = 0;
  float _MinTime = 0.4f;

  Size _TileSize;
  Size _MapViewSize;
  Size _MapSize;

  Node *_ContainerViewNode = nullptr;
  ui::Layout *_ContainerView = nullptr;

  XTiledMap *_TmxView = nullptr;
  XTiledLayer *_GroundLayer = nullptr;
  XTiledLayer *_MapLayer = nullptr;
  Ext::ScrollView *_ViewScrollView = nullptr;
public: 
  RViewClass _Config;
  RViewOtherData _Param;
  static WorldMapView *Create(RViewClass, RViewOtherData);
  void Ctor() override {}
  void Ctor(RViewClass, RViewOtherData);
  float GetBottomQuestBtnsOffsetY();
  void InitParam();
  void InitView();
  void InitData();
  void InitMapCell();
  void InitTmx();
  void InitScrollView();
  void InitScrollDid();
};