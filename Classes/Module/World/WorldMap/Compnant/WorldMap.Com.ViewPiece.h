#pragma once
#include "IWorldMap.Com.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class WorldMapComViewPiece : public IWorldMapComponent
{
public:
  EWorldLodDef _Lod;
  void Init() override;
  void OnMessageListener() override;
  void ResetData() override;
  void Ctor();
  void SetViewPieceIds(EventCustom *pEvent);
};