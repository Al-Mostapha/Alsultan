#pragma once
#include "IWorldMap.Com.h"
#include "Base/BaseTypeDef.h"
#include "renderer/ccShaders.h"
#include "renderer/backend/Device.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Base/Containers/Pair.h"

USING_NS_CC_MATH;
USING_NS_CC;

class WorldMapView;
class RViewClass;


class WorldMapComTmxTerrianBg : public IWorldMapCompnant
{
  private:
    RViewClass _Config;
    GString _TerrainDir = "tileMaps/commonMap/%s.%s";
    int32 _TiledBgX = 0;
    int32 _TiledBgY = 0;
    Vec4 _Resolution;

    Vec4 _TileInfo;
    GString _CurTileControl;
    Sprite *_TiledBg;

  public:
    struct RTerrainCfg{
      Sprite *_TiledBg;
      backend::ProgramState *_State;
      backend::Program *_Shader;
      bool _IsLow;
    };
    RTerrainCfg _NoramlCfg;
    RTerrainCfg _LowCfg;
    static WorldMapComTmxTerrianBg *Create(WorldMapView *p_Target);
    void Init();
    void Ctor();
    void InitMapTiledBg();
    GString GetTileControl(bool l_Lod = false);
    RTerrainCfg CreateTerrainBg(GPair<const char *, const char *> p_Shader, bool p_IsLow = false);
};
