#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

struct RViewPieceIdEvAr{
  GVector<int32> _ViewPieceIDs;
  EWorldLodDef _Lod;
};

class WorldMapEvent{
  public:
    static WorldMapEvent *Get();
    const char *EVENT_UPDATE_INFO = "EVENT_UPDATE_INFO";;
    const char *EVENT_SCROLL_DID = "EVENT_SCROLL_DID";
    const char *EVENT_UPDATE_PIECE = "EVENT_UPDATE_PIECE";
    const char *EVENT_UPDATE_PIECE_DEL = "EVENT_UPDATE_PIECE_DEL";
    const char *EVENT_TILE_POS = "EVENT_TILE_POS";
    const char *EVENT_TOOGLE_3D = "EVENT_TOOGLE_3D";
    const char *EVENT_TILED_DEBUG = "EVENT_TILED_DEBUG";
    const char *EVENT_TRANS = "EVENT_TRANS";
    const char *EVENT_SCROLL_LOD_CHANGE = "EVENT_SCROLL_LOD_CHANGE";
    const char *EVENT_SCROLL_ZOOM = "EVENT_SCROLL_ZOOM";
    const char *EVENT_CELL_CHANGE = "EVENT_CELL_CHANGE";
    const char *EVENT_CELL_SWAP = "EVENT_CELL_SWAP";
};