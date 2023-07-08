#pragma once
#include "IWorldMap.Com.h"
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class WorldMapCell;
class UIWorldMapAllianceMark;

class WorldMapComAllianceMark : public IWorldMapComponent
{
  int32 _MyKindomID;
  WorldMapCell *_WorldMapCell;
  GHashMap<int32, UIWorldMapAllianceMark *> _NodeList;
  GHashMap<int32, UIWorldMapAllianceMark *> _CampMarkList;
  Node *_NodeAllianceMark;
  EWorldLodDef _CurLod = EWorldLodDef::None;
public:
  void Init() override;
  void OnMessageListener() override;
  void Ctor();
  void InitAllianceMark();
  void UpdateScaleZoom(EventCustom *p_Event);
  void UpdateLodLevel(EventCustom *p_Event);
  void UpdateCellSwap(EventCustom *p_Event);
  void Toggle3D(EventCustom *p_Event);
  void RefreshAllianceMark(EventCustom *p_Event);
  void RefreshCampMark(EventCustom *p_Event);
  void RefreshAllianceMarkNode();
};