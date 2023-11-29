#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XTuple.h"
#include "ui/CocosGUI.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Base/Containers/HashMap.h"




USING_NS_CC;

class WorldMapView;
class UIWorldMapTip;
class IWorldMapInstance;
class XTileLayer;
class UIBaseView;
class WorldMapCell : public cocos2d::ui::Layout
{
  CREATE_FUNC(WorldMapCell);
  public:
  
  int32 _MapPointIndex = 0;
  int32 _GroupIndex = 0;
  int32 _KingdomID = 0;
  Vec2 _KingdomPoint = Vec2::ZERO;
  int32 _MyKingdomID = 0;
  int32 _RegionID = 0;
  Guid _MyPlayerID = 0;
  GString _MyPlayerName;
  bool _IsTransfering = false;
  // self.transferView = nil
  // self.transferTilesArray = {}
  Rect _CurrentShowRect = Rect::ZERO;
  Size _MapViewSize = Size::ZERO;
  Size _MapSize = Size::ZERO;
  Size _TileSize = Size::ZERO;
  XTileLayer* _TileLayer = nullptr;
  XTileLayer* _MapLayer = nullptr;
  XTileLayer* _GroundLayer = nullptr;
  XTileLayer* _GroundLayerMarsh = nullptr;
  bool _IsSingleMapCell = false;
  ui::Widget::ccWidgetTouchCallback _TouchPlayerCallFun = nullptr;
  EKingdomClassType _MapClassType;
  DrawNode* _DrawNode = nullptr;
  GHashMap<GString, Node *> _CacheNodes;
  // self.cacheLeagueManorNodes = {
  //   [1] = {},
  //   [2] = {}
  // }

  static WorldMapCell *Create(WorldMapView *p_MapView);
  void Ctor(WorldMapView *p_MapView);
  void SetMapPointIndex(int32);
  void SetKingdomId(int32 p_KingdomId, Vec2 p_KingdomPoint = Vec2::ZERO, int32 p_RegionId = 0);

  int32 GetKingdomID() const;
  Vec2 GetKingdomPoint() const;
  int32 GetRegionID() const;

  void AddShowBonePoing(EKingdomClassType);
  void SetTouchPlayerCallFunc(const ui::Widget::ccWidgetTouchCallback&);
  Vec2 TilePositionFromLocation(Vec2, bool p = false);
  Vec2 GetPointWithTile(Vec2 p_TilePoint, int32 p_HoldInstance = 1);
  void ViewOnClick(Ref* p_Target, ui::Widget::TouchEventType p_Event);

  UIWorldMapTip *OnClickMap(Node *p_TileInstance, Vec2 p_TilePos, Node *p_OnShowView );
  GTuple<UIBaseView *, Node *, Node *> 
  OnClickInstance(GOpt<Vec2> p_TilePos, IWorldMapInstance *p_TileInstance,
   Node *p_OnShowView, Node *p_OnShowViewNode);
 
  Node* &operator[](const GString &pLayerName){
    if(!_CacheNodes.Contains(pLayerName))
      _CacheNodes[pLayerName] = nullptr;
    return _CacheNodes[pLayerName];
  }

};