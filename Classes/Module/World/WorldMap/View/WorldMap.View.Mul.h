#pragma once
#include "Base/BaseTypeDef.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class WorldMapCell;

class WorldMapViewMul
{
public:
  bool _IsSingleMapCell = false;
  bool _IsMapCellTransposition = true;
  bool _IsInsingle = false;

  GVector<WorldMapCell *> _MapViewCellArray;
  GVector<cocos2d::Vec2> _MapViewPointArray;
  GVector<cocos2d::Vec2> _MapViewSwapPointArray;
  Size _ContainerViewSize;
  Size _MapViewSize;
  ui::Layout *_ContainerView;
  ClippingNode *_MapViewcliperNode;
  DrawNode *_ShapNode;
  WorldMapCell *_CurrentInMapViewCell;
  WorldMapCell *_SelfInMapView;
  WorldMapCell *_MapViewCell;
public:

  void InitMapCell_imp();
  virtual WorldMapCell *CreateOneMapCell() = 0;
  void InitColorLayer();
  void SetLightMapcell(WorldMapCell *);
  void SetMapcellKingdomID(int32 p_CellIndex);
  void ScrollFromBorder(){}
  void UpdateCheckSetMapViewCellPoint(){}
  bool GetMapTilesData_imp(){ return false; }
  void AddEnterOtherWorldmapCellFilm(){}
  WorldMapCell *GetWorldMapCell(int32 p_KingdomID, bool create = false);
};