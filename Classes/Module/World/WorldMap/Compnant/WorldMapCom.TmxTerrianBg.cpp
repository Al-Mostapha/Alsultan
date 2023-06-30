#include "WorldMapCom.TmxTerrianBg.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Engine/Display.h"
#include "renderer/ccShaders.h"
#include "Module/World/WorldMap/Shader/Terrian.Shader.h"
#include "Module/World/WorldMap/Shader/Terrian.Shader.Low.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Base/Utils/MeshNode.h"
#include "Module/World/WorldMap/WorldMap.Event.h"

const int32 TileBG_Size = 1024;

WorldMapComTmxTerrianBg *WorldMapComTmxTerrianBg::Create(WorldMapView *p_Target){
  WorldMapComTmxTerrianBg *l_View = new WorldMapComTmxTerrianBg();
  l_View->_Target = p_Target;
  l_View->Ctor();
  return l_View;
}


void WorldMapComTmxTerrianBg::Ctor(){

}

void WorldMapComTmxTerrianBg::Init(){
  _Config = _Target->_Config;
  // self.lodControl = 0
  InitMapTiledBg();
  // self:addEventListener(worldMapEvent.EVENT_TOOGLE_3D, handler(self, self.toggle3D))
}

void WorldMapComTmxTerrianBg::OnMessageListener(){
  AddEventListener(WorldMapEvent::Get()->EVENT_TILE_POS, CC_CALLBACK_1(WorldMapComTmxTerrianBg::UpdateMapPos, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_ZOOM, CC_CALLBACK_1(WorldMapComTmxTerrianBg::UpdateScaleZoom, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapComTmxTerrianBg::UpdateLodChange, this));
}

void WorldMapComTmxTerrianBg::Toggle3D(){

  GGlobal::Get()->gEnableWorldMap3D = true;
  if(GGlobal::Get()->gEnableWorldMap3D){
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
  if(_LowCfg){
    _LowCfg._TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
  }
  }else{
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
    if(_LowCfg){
      _LowCfg._TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
    }
  }
}

void WorldMapComTmxTerrianBg::InitMapTiledBg(){

  auto l_Width = GDisplay::Get()->width + 0.5f * GDisplay::Get()->height;
  auto l_Height = GDisplay::Get()->height * 1.4f;
  auto l_OffsetX = (GDisplay::Get()->width - l_Width) * 0.5f;
  auto l_MapSize = _Target->_MapSize;
  auto l_TileSize = _Target->_TileSize;
  _TiledBgX = 0;
  _TiledBgY = 0;
  _Resolution.x = TileBG_Size;
  _Resolution.y = TileBG_Size;
  _Resolution.z = l_OffsetX / l_Width;
  _Resolution.w = 0;
  _TileInfo.x = l_MapSize.width;
  _TileInfo.y = l_MapSize.height;
  _TileInfo.z = 1 / l_TileSize.width;
  _TileInfo.w = 1 / l_TileSize.height;
  _CurTileControl = GetTileControl();
  
  const static auto l_Shader = GPair<const char *, const char *>(TarrianShader::Vert, TarrianShader::Freg);
  _NoramlCfg = CreateTerrainBg(l_Shader);
  _NoramlCfg._TiledBg->setName("tiledBg");
  _TiledBg = _NoramlCfg._TiledBg;
}

GString WorldMapComTmxTerrianBg::GetTileControl(bool l_Lod){
  return "tileMaps/World_png/worldTileControl.png";
}

WorldMapComTmxTerrianBg::RTerrainCfg WorldMapComTmxTerrianBg::CreateTerrainBg(GPair<const char *, const char *> p_Shader, bool p_IsLow){
  auto l_Width = GDisplay::Get()->width + 0.5f * GDisplay::Get()->height;
  auto l_Height = GDisplay::Get()->height * 1.4f;
  auto l_TiledBg = GBase::CreateSprite("SinglePicture/bq_tex3.png");
  l_TiledBg->setContentSize(Size(l_Width, l_Height));
  l_TiledBg->setAnchorPoint(Vec2(0, 0));
  auto l_ZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto l_ScaleX = l_Width / TileBG_Size / l_ZoomScale;
  auto l_ScaleY = l_Height / TileBG_Size / l_ZoomScale;
  GVector<RMeshNodeShaderCfg> l_Param;

  auto l_OneParam = RMeshNodeShaderCfg();
  l_OneParam.Attr = EUniformType::Texture;
  l_OneParam.UnifromName = "_Texture";
  l_OneParam.TexPath = "tileMaps/commonMap/combine1.png";
  l_OneParam.TexParam.minFilter = GL_LINEAR;
  l_OneParam.TexParam.magFilter = GL_LINEAR;
  l_OneParam.TexParam.wrapS = GL_REPEAT;
  l_OneParam.TexParam.wrapT = GL_REPEAT;
  l_Param.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Texture;
  l_OneParam.UnifromName = "_TileTexture";
  l_OneParam.TexPath = _CurTileControl;
  l_OneParam.TexParam.minFilter = GL_LINEAR;
  l_OneParam.TexParam.magFilter = GL_LINEAR;
  l_OneParam.TexParam.wrapS = GL_REPEAT;
  l_OneParam.TexParam.wrapT = GL_REPEAT;
  l_OneParam.texForce = true;
  l_Param.push_back(l_OneParam);
  
  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.UnifromName = "_Texture_ST";
  l_OneParam.Vec4Value.x = l_ScaleX;
  l_OneParam.Vec4Value.y = l_ScaleY;
  l_OneParam.Vec4Value.z = _TiledBgX;
  l_OneParam.Vec4Value.w = _TiledBgY;
  l_Param.push_back(l_OneParam);
  
  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.UnifromName = "_resolution";
  l_OneParam.Vec4Value = _Resolution;
  l_Param.push_back(l_OneParam);
  
  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.UnifromName = "_tileInfo";
  l_OneParam.Vec4Value = _TileInfo;
  l_Param.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.UnifromName = "v_lodLevel";
  l_OneParam.FloatValue = 0;
  l_Param.push_back(l_OneParam);
  
  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.UnifromName = "_fade";
  l_OneParam.FloatValue = 0;
  l_Param.push_back(l_OneParam);
  if(p_IsLow){
    l_OneParam.Attr = EUniformType::Texture;
    l_OneParam.UnifromName = "_TileTextureLod";
    l_OneParam.TexPath = GetTileControl(true);
    l_OneParam.TexParam.minFilter = GL_NEAREST;
    l_OneParam.TexParam.magFilter = GL_NEAREST;
    l_OneParam.TexParam.wrapS = GL_REPEAT;
    l_OneParam.TexParam.wrapT = GL_REPEAT;
    l_OneParam.texForce = true;
    l_Param.push_back(l_OneParam);
  }
  
  auto l_OffsetX = (GDisplay::Get()->width - l_Width) * 0.5f;
  auto l_Defined = "";
  if(WorldMapUtil::Get()->IsLodOpen()){
    l_Defined = "LOD_FADE";
  }
  auto l_Program = GLProgram::createWithByteArrays(p_Shader.First, p_Shader.Second, l_Defined);
  auto l_State = GLProgramState::create(l_Program);
  GBase::DSetProgramStateParam(l_Program, l_State, l_Param);
  l_TiledBg->setGLProgramState(l_State);
  _Target->addChild(l_TiledBg, static_cast<int32>(EWorldMapZOrder::scrollView) - 1);
  l_TiledBg->setPositionX(l_OffsetX);
  
  RTerrainCfg l_Cfg = {
    l_TiledBg,
    l_State,
    l_Program,
    p_IsLow
  };
  l_Cfg._IsValid = true;
  return l_Cfg;
}

void WorldMapComTmxTerrianBg::UpdateMapPos(EventCustom *p_Event){
  auto l_TilePos = static_cast<Vec2 *>(p_Event->getUserData());
  if(_TiledBgX != l_TilePos->x || _TiledBgY != l_TilePos->y){
    _TiledBgX = l_TilePos->x;
    _TiledBgY = l_TilePos->y;
    UpdateTerrain(_NoramlCfg);
    if(_LowCfg){
      UpdateTerrain(_LowCfg);
    }
  }
}


void WorldMapComTmxTerrianBg::UpdateTerrain(const RTerrainCfg &p_Cfg){
  
  auto l_ZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto l_ScaleX = p_Cfg._TiledBg->getContentSize().width / TileBG_Size / l_ZoomScale;
  auto l_ScaleY = p_Cfg._TiledBg->getContentSize().height / TileBG_Size / l_ZoomScale;
  auto l_Lod = GetLodLevel(l_ZoomScale);
  auto l_LodLevel = l_Lod.First;
  auto l_LodFade = l_Lod.Second;
  // local worldLod = self.target_:getCurLod()
  GVector<RMeshNodeShaderCfg> l_Param;
  auto l_OneParam = RMeshNodeShaderCfg();

  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.UnifromName = "_Texture_ST";
  l_OneParam.Vec4Value = {l_ScaleX, l_ScaleY, _TiledBgX, _TiledBgY};
  l_Param.push_back(l_OneParam);
  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.UnifromName = "v_lodLevel";
  l_OneParam.FloatValue = l_LodLevel;
  l_Param.push_back(l_OneParam);
  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.UnifromName = "_fade";
  l_OneParam.FloatValue = l_LodFade;
  l_Param.push_back(l_OneParam);
  GBase::DSetProgramStateParam(p_Cfg._Shader, p_Cfg._State, l_Param);
}

GPair<int32, float> WorldMapComTmxTerrianBg::GetLodLevel(float p_Zoom){
  auto l_Level = 0;
  auto l_Fade = 0.0f;
  struct{
    int32 level;
    float rangeMin;
    float rangeMax;
    float fadeEnd;
  } zoomCfg[4] = {
    {0, 0.5, 1, 0},
    {1, 0.2, 0.5, 0.4},
    {2, 0.1, 0.2, 0.15},
    {3, 0.05, 0.1, 0.08}
  };
  for(auto &v : zoomCfg){
    auto l_Zoom = p_Zoom;
    if(l_Zoom > v.rangeMin && l_Zoom <= v.rangeMax){
      l_Level = v.level;
      if(v.fadeEnd != 0 && l_Zoom > v.fadeEnd){
        l_Fade = std::max(std::min((l_Zoom - v.fadeEnd) / (v.rangeMax - v.fadeEnd), 1.0f), 0.0f);
        break;
      }
    }
  }
  return {l_Level, l_Fade};
}

void WorldMapComTmxTerrianBg::UpdateScaleZoom(EventCustom *p_Event){
  UpdateTileVisible();
}

void WorldMapComTmxTerrianBg::UpdateLodChange(EventCustom *p_Event){

}

void WorldMapComTmxTerrianBg::UpdateTileVisible(){
  auto l_ZomeScale = _Target->_ViewScrollView->getZoomScale();
  // local worldLod = self.target_:getCurLod()
  auto l_ShowNormal = l_ZomeScale > 0.1;
  _NoramlCfg._TiledBg->setVisible(l_ShowNormal);
  if(!l_ShowNormal && !_LowCfg){
    _LowCfg = CreateTerrainBg(GPair<const char *, const char *>(TarrianShaderLow::Vert, TarrianShaderLow::Freg), true);
    _LowCfg._TiledBg->setName("lowTiledBg");
    Toggle3D();
  }
  if(_LowCfg){
    _LowCfg._TiledBg->setVisible(!l_ShowNormal);
  }
}
