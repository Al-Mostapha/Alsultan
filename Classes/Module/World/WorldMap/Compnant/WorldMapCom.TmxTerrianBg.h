#pragma once
#include "IWorldMap.Com.h"
#include "Base/BaseTypeDef.h"
#include "renderer/ccShaders.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
#include "Base/Containers/Pair.h"

USING_NS_CC_MATH;
USING_NS_CC;

class WorldMapView;
class RViewClass;


class WorldMapComTmxTerrianBg : public IWorldMapComponent
{
  private:
    GString _TerrainDir = "tileMaps/commonMap/%s.%s";
    float _TiledBgX = 0;
    float _TiledBgY = 0;
    Vec4 _Resolution;

    Vec4 _TileInfo;
    GString _CurTileControl;
    Sprite *_TiledBg;

  public:
    struct RTerrainCfg{
      Sprite *_TiledBg;
      GLProgramState *_State;
      GLProgram *_Shader;
      bool _IsLow;
      bool _IsValid = false;
      operator bool(){
        return _IsValid;
      }
    };
    RTerrainCfg _NoramlCfg;
    RTerrainCfg _LowCfg;

    void Init() override;
    void OnMessageListener() override;

    void Ctor();
    void InitMapTiledBg();
    GString GetTileControl(bool l_Lod = false);
    RTerrainCfg CreateTerrainBg(GPair<const char *, const char *> p_Shader, bool p_IsLow = false);


    void UpdateTerrain(const RTerrainCfg &p_Cfg);

    void UpdateMapPos(EventCustom *p_Event);
    void UpdateScaleZoom(EventCustom *p_Event);
    void UpdateLodChange(EventCustom *p_Event);

    void UpdateTileVisible();
    void Toggle3D();

    GPair<int32, float> GetLodLevel(float p_Zoom);
};
