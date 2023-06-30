#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"
#include "WorldMap.View.Mul.h"
#include "WorldMap.View.Object.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Module/World/WorldMap/View/WorldMapView.Type.h"
#include "Module/World/WorldMap/IWorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMapView.Def.h"
#include "Global/Global.h"
#include "Module/UI/Part/Common/UICommonLoading.h"
#include "Scene/Scene.Type.h"
#include "Engine/XTiledMap/XTiledMap.h"
#include "Engine/XTiledMap/XTileLayer.h"


struct RViewClass;
class WorldMapView : public IWorldMapView,  public WorldMapViewMul, public WorldMapViewObject,  public Ext::ScrollViewDelegate{
  CREATE_FUNC(WorldMapView);
  CreateUIPanel(WorldMapView);
  CreateUICCSView(WorldMapView);
public:
  EWorldMapLayInstance _LayInstanceType = EWorldMapLayInstance::None;
  EKingdomClassType _MapClassType = EKingdomClassType::None;
  GString _CreateCustomLayer;
  Vec2 _DisplayCenterPoint;
  Vec2 _ReqMapCenterPoint;
  Vec2 _ReqcenterTilePos = Vec2::ZERO;
  Vec2 _SendTilePos = Vec2::ZERO;
  Vec2 _LoadingPos = Vec2::ZERO;
  bool _IsWaitForData = false;
  Vec2 _GotoSelectTilePoint;
  Vec2 _GotoTransferCityPoint;
  Vec2 _MapViewCenterPoint;
  bool _CanDoSelected = false;
  bool _NeedShowHand = false;
  // self.gotoTransferCityPoint = nil
  bool _CanDoTransfer = false;
  bool _IsMoved = false;
  bool _IsDelay = false;
  bool _IsFinishInit = false;
// self.preCenterPoint = nil
  int32 _DelayFrame = 0;
  int32 _IsNeedRefreshScroll = 0;
  EKingdomClassType _MapKingdomClassType = EKingdomClassType::Normal;
  int32 _MyKindomID = 0;
  float _MinTime = 0.4f;
  float _DelayTime = 0.4f;

  Size _TileSize;
  Size _MapSize;

  Node *_ContainerViewNode = nullptr;

  XTiledMap *_TmxView = nullptr;
  XTileLayer *_GroundLayer = nullptr;
  XTileLayer *_MapLayer = nullptr;
  XTileLayer *_GroundLayer_marsh = nullptr;
  Ext::ScrollView *_ViewScrollView = nullptr;
  UICommonLoading *_LoadView;

  Vec2 _InitTilePoint = Vec2::ZERO;
  bool _InitIsSelected = false;
  EWorldMapLayInstance _LayInstance;
  RLayInstanceData _LayInstanceData;

  int32 _PreCenterPoint = 0;
  int32 _PreCheckPoint = 0;
  GTime _PreClockTime;

public: 

  void scrollViewDidScroll(Ext::ScrollView* view) override;
  void scrollViewDidZoom(Ext::ScrollView* view) override ;

  RViewClass _Config;
  RViewOtherData _Param;
  static WorldMapView *Create(RViewClass, RViewOtherData);
  void Ctor() override {}
  void Ctor(RViewClass, RViewOtherData);
  float GetBottomQuestBtnsOffsetY();
  void InitParam(RViewOtherData);
  void InitView();
  void InitData();
  void InitTimer();
  void RefreshScroll();
  void UpdateShowTileInstance();
  void UpdateDelayFrame(float p_Dt = 0);
  void InitMapCell();
  void OnSwitchMapViewCell();
  void OnSwapMapViewCell();
  void OnMessageListener();
  void OnMessageListener_FinishLoadImage(bool p_Add = false);
  void OnClickInstance(Vec2 p_TilePoint, WorldMapCell *p_MapCell = nullptr);
  void InitTmx();
  void InitOther();
  void InitScrollView();
  void InitScrollDid();
  void InitEvent();
  void FinishLoadImages();

  void MoveTilePointToCenter(
    Vec2 p_TilePoint, bool p_IsSelected = false, EWorldMapLayInstance p_LayInstance = EWorldMapLayInstance::None,
    RLayInstanceData p_Data = RLayInstanceData(), float p_Duration = 0.0f, WorldMapCell *p_MapCell = nullptr,
    bool p_IsHowHand = false);
  WorldMapCell *CreateOneMapCell() override;

  void ViewOnClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type);

  void Toggle3D(EventCustom *p_Event);
  void GotoForeBackGroud(EventCustom *p_Event);
  void RefreshRelogin(EventCustom *p_Event);
  void GotoTilePointOld(EventCustom *p_Event);
  void GotoTilePoint(RGotoTilePointEvAr &p_Data);
  void GotoTilePointNew(RGotoTilePointNewEvAr &p_Data);
  void MoveSubPointToCenter(EventCustom *p_Event);
  void ServerMessage_GetRectData(EventCustom *p_Event);
  void UpdateLodChange(EventCustom *p_Event);

  void UpdateCenterAreaTiles();
  void UpdateMapPos();


  void CloseLoading();
  void ShowHandTip();
  void HideHandTip();
  Vec2 GetPointWithTile(Vec2 p_TilePoint); 
  Vec2 GetDisplayCenterTilePoint();
  void GetMapTilesData();
  void MoveMapPointToCenter(Vec2 p_Point, float p_Duration = 0, bool p_Container = false);
  void SetZoomScale(float p_Scale = WorldMapViewDef::Get()->NORMAL_SCALE, float p_Duration = 0, bool p_Animated = false);
  void CleanShowPanel();
  void RefreshMapDataAndView();

  void DoClearData();
  void DoRequestData();

  void SetViewPieceIds(GVector<int32> p_ViewPieceIDs, EWorldLodDef p_Lod);
  void SetTmxCulledRect(XTiledMap *p_TmxView);
  Vec2 GetRadianceGatePos();

  void EndShow();
  WorldMapCell *GetCurrentInMapViewCell();
};