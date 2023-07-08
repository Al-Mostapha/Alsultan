#pragma once
#include "IWorldMap.Com.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Base/Utils/MeshNode.h"

class WorldMapView;
class WorldMapCell;
class UIWorldMapNeighbour;

class WorldMapComBorder : public IWorldMapComponent
{
  WorldMapCell *_CurCell;
  GVector<RBorderLodScale> _LodCfgScale;
  UIWorldMapNeighbour *_NodeNeighbour;
  GOpt<RBorderLodScale> _LodConfig;
  MeshNode *_BorderGray;
  GLProgramState *_BorderGrayState;
  MeshNode *_Border;
  GLProgramState *_BorderState;
public:
  static WorldMapComBorder *Create(RViewClass p_Config, WorldMapView *p_Target);
  void Init() override;
  void OnMessageListener() override;
  void Ctor();
  void UpdateScaleZoom(EventCustom *p_Event);
  void UpdateMapPos(EventCustom *p_Event);
  void CreateGrayBorder(float p_MapWidth);
  void CreateCurCellBorder(float p_MapWidth);
  void InitNeighbourKingdom();
  void UpdateBorderPosition();
  void RefreshNeighbourKingdom();
  void UpdateBorderCfg(RBorderLodScale p_Config);
  UIWorldMapNeighbour *CreateNeighbourKingdomView(int32 p_KingdomId);
  void RefreshNeighbourSingle(Node *p_Node, int32 p_KingdomId);
};