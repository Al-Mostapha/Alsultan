#include "WorldMapCom.TmxTerrianBg.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Engine/Display.h"
#include "renderer/ccShaders.h"
#include "renderer/backend/Device.h"
#include "Module/World/WorldMap/Shader/Tarrian.Shader.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Base/Utils/MeshNode.h"

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

void WorldMapComTmxTerrianBg::InitMapTiledBg(){

  auto l_Width = GDisplay::Get()->width + 0.5 * GDisplay::Get()->height;
  auto l_Height = GDisplay::Get()->height * 1.4;
  auto l_OffsetX = (GDisplay::Get()->width - l_Width) * 0.5;
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
  auto l_Width = GDisplay::Get()->width + 0.5 * GDisplay::Get()->height;
  auto l_Height = GDisplay::Get()->height * 1.4;
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
  l_OneParam.TexPath = StringUtils::format(_TerrainDir.c_str(), "combine1", "png");
  l_OneParam.TexParam.minFilter = backend::SamplerFilter::LINEAR;
  l_OneParam.TexParam.magFilter = backend::SamplerFilter::LINEAR;
  l_OneParam.TexParam.sAddressMode = backend::SamplerAddressMode::REPEAT;
  l_OneParam.TexParam.tAddressMode = backend::SamplerAddressMode::REPEAT;
  l_Param.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Texture;
  l_OneParam.UnifromName = "_TileTexture";
  l_OneParam.TexPath = _CurTileControl;
  l_OneParam.TexParam.minFilter = backend::SamplerFilter::LINEAR;
  l_OneParam.TexParam.magFilter = backend::SamplerFilter::LINEAR;
  l_OneParam.TexParam.sAddressMode = backend::SamplerAddressMode::REPEAT;
  l_OneParam.TexParam.tAddressMode = backend::SamplerAddressMode::REPEAT;
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
    l_OneParam.TexParam.minFilter = backend::SamplerFilter::NEAREST;
    l_OneParam.TexParam.magFilter = backend::SamplerFilter::NEAREST;
    l_OneParam.TexParam.sAddressMode = backend::SamplerAddressMode::REPEAT;
    l_OneParam.TexParam.tAddressMode = backend::SamplerAddressMode::REPEAT;
    l_OneParam.texForce = true;
    l_Param.push_back(l_OneParam);
  }
  
  auto l_OffsetX = (GDisplay::Get()->width - l_Width) * 0.5;
  if(WorldMapUtil::Get()->IsLodOpen()){
    // defined = "LOD_FADE"
  }
  auto l_Program = backend::Device::getInstance()->newProgram(p_Shader.First, p_Shader.Second/*, defined*/);
  auto l_State = new backend::ProgramState(l_Program);
  GBase::DSetProgramStateParam(l_Program, l_State, l_Param);
  l_TiledBg->setProgramState(l_State);
  _Target->addChild(l_TiledBg, static_cast<int32>(EWorldMapZOrder::scrollView) - 1);
  l_TiledBg->setPositionX(l_OffsetX);
  
  RTerrainCfg l_Cfg = {
    l_TiledBg,
    l_State,
    l_Program,
    p_IsLow
  };
  return l_Cfg;
}
