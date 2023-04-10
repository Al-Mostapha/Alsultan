
#pragma once
#include "Include/IncludeEngine.h"
#include "Module/Building/Building.Enum.h"

class CityCommon{
  public: 
  float _HUITop = 40;
  float _HUIBottom = 115;
  float _MinScale = 0.6f;
  float _MinLimitScale = 0.5f;
  float _DefaultScale = 0.9f;
  float _NormalScale = 0.5;
  float _ZoomScale = 0.5;
  float _PreZoomScale = 0.5;
  float _MaxScale = 1.8f;
  float _MaxLimitScale = 2;
  float _Inertia = 1.4f;
  float _InitScrollViewScale = 1.4f;
  float _NormlScrollViewScale = 1;
  float _ZoomScaleDuration = 0.3f;
  float _InitZoomScaleDuration = 0.6f;
  float _AutoMoveSpeed = 2700;
  float _AutoMoveSpeedSlow = 800;
  float _ZoomMinOffsetX ;
  float _ZoomMinOffsetY ;

  public:
  Node *_ContainerView;
  Node *_MainCityFarCsb ;
  Node *_MainCityMiddleCsb ;
  Size _ViewScrollSize;
  class MainCityView *_CityView;
  Ext::ScrollView *_ViewScrollView ;
  ParallaxNode *_BackPnode;
  ParallaxNode *_FrontPnode;

  Node *_BatchNodeOuterTiles = nullptr;
  Node *_BatchNodeOuterBuilds = nullptr;
  Node *_BatchNodeOuterBuildNpc = nullptr;
  Node *_BatchNodeOuterBuildCommon = nullptr;
  Node *_BatchNodeKipchaks = nullptr;
  Node *_BatchNodeTopTip = nullptr;
  Node *_BatchNodeCityOthers = nullptr;
  Node *_BatchNodeCityEffect = nullptr;
  Node *_BatchNodeSoldierGuards = nullptr;
  Node *_BatchNodeNpc = nullptr;
  Node *_BatchNodeXiyiNpc = nullptr;
  Node *_BatchNodeCollect = nullptr;
  Node *_BatchNodeFightBullet = nullptr;
  Node *_BatchNodeFightBuilds = nullptr;
  Node *_BatchNodeFightBuildWalls = nullptr;
  Node *_BatchNodeFightSoldiers = nullptr;
  Node *_EffectFightNode = nullptr;
  ui::Layout *_Touchlayer;
  struct 
  {
    Node  *MainCityOuter;
    Node  *MainCityNpc;
    Node  *MainCityCommon;
    Node  *MainCityKipchaks;
  } _TblBatchNodesOuter;
  GHashMap<GString, Node *> _TblBatchNodesTopTip;
};