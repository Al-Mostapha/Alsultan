#include "WorldMap.Com.NormalFog.h"
#include "Base/Utils/MeshNode.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/Kingdom/Kingdom.Ctrl.h"
#include "Module/Player/Player.Top.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/World/WorldMap/Lod/WorldMapLodCfg.h"
#include "Module/World/WorldMap/Shader/FogNormalShader.h"


static const int32 TileBG_Size = 1024;

void WorldMapComNormalFog::Init(){
  _MyKindomID = PlayerTop::Get()->GetMapID();
  UpdateCellSwap(nullptr);
  AddEventListener(WorldMapEvent::Get()->EVENT_TOOGLE_3D, CC_CALLBACK_1(WorldMapComNormalFog::Toggle3D, this));
} 

void WorldMapComNormalFog::OnMessageListener(){
  AddEventListener(WorldMapEvent::Get()->EVENT_CELL_SWAP, CC_CALLBACK_1(WorldMapComNormalFog::UpdateMapPos, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_ZOOM, CC_CALLBACK_1(WorldMapComNormalFog::UpdateCellSwap, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_ZOOM, CC_CALLBACK_1(WorldMapComNormalFog::UpdateScaleZoom, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLDMAP_UNLOCK_NORMAL_FOG", CC_CALLBACK_1(WorldMapComNormalFog::UnLockWarFog, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLDMAP_REFRESH_OTHER_KINGDOMINFO", CC_CALLBACK_1(WorldMapComNormalFog::RefreshOtherKingdominfo, this));
}

void WorldMapComNormalFog::Toggle3D(EventCustom *p_Event){
  if(!_TiledBg)
    return;
  if(GGlobal::Get()->gEnableWorldMap3D)
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
  else 
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
}

void WorldMapComNormalFog::UpdateCellSwap(EventCustom *p_Event){
  auto lCurrentInMapViewCell = _Target->GetCurrentInMapViewCell();
  auto lCurMapID = lCurrentInMapViewCell->_KingdomID;
  if(_MyKindomID == lCurMapID){
    _FogData = KingdomMapCtrl::Get()->GetNormalFogData();
  }else{
    //   self.fogData = {}
    _FogData = {};
    if(KingdomCtrl::Get()->IsFoundKingdomID(lCurMapID)){
      KingdomMapCtrl::Get()->OnSwitchWorldMap(ESwitchWorldMapTypeDef::In, lCurMapID);
    }
  }
  RefreshWarFog();
}

void WorldMapComNormalFog::UnLockWarFog(EventCustom *p_Event){
  auto lCurrentInMapViewCell = _Target->GetCurrentInMapViewCell();
  auto lCurMapID = lCurrentInMapViewCell->_KingdomID;
  if(_MyKindomID != lCurMapID)
    return;
  _FogData = KingdomMapCtrl::Get()->GetNormalFogData();
  RefreshWarFog();
}

void WorldMapComNormalFog::RefreshWarFog(){
  if(_FogData){
    if(!_TiledBg){
      InitWarFog();
      Toggle3D(nullptr);
      RefreshMapPos(Vec2(_TiledBgX, _TiledBgY));
    }else{
      auto lRect = _FogData->_Rect;
      RMeshNodeShaderCfg lShaderCfg;
      lShaderCfg.Attr = EUniformType::Vec4;
      lShaderCfg.UnifromName = "_fogRect";
      lShaderCfg.Vec4Value = Vec4(lRect.ltX - 1, lRect.ltY - 1, lRect.rbX - 1, lRect.rbY - 1);
      GBase::DSetProgramStateParam(_Program, _State, { lShaderCfg });
    }
  } else if(_TiledBg){
    _TiledBg->removeFromParent();
    _TiledBg = nullptr;
  }
}

void WorldMapComNormalFog::RefreshOtherKingdominfo(EventCustom *p_Event){
  _FogData = KingdomMapCtrl::Get()->GetOtherKingdomInfo()._Fog;
  RefreshWarFog();
}

void WorldMapComNormalFog::InitWarFog(){
  
  _TiledBg = GDisplay::Get()->NewSprite("SinglePicture/bq_tex3.png");
  auto lWidth = GDisplay::Get()->width+ 0.5 * GDisplay::Get()->height;
  auto lHeight = GDisplay::Get()->height * 1.35;
  auto lOffsetX = (GDisplay::Get()->width - lWidth) * 0.5;
  _TiledBg->setContentSize(Size(lWidth, lHeight));
  _Target->addChild(_TiledBg, static_cast<int32>(EWorldMapZOrder::scrollView));
  _TiledBg->setPositionX(lOffsetX);
  _TiledBg->setAnchorPoint(Vec2(0, 0));
  _Resolution = Vec4(TileBG_Size, TileBG_Size, lOffsetX / lWidth, 0);
  
  _TileInfo = Vec4(1201, 1201, 256, 128);
  _TiledBg->setBlendFunc({ GL_ONE, GL_ONE_MINUS_SRC_ALPHA });
  _TiledBg->setName("tiledFog");

  ReloadTmxFogShader();
  UpdateScaleZoom(nullptr);
}

void WorldMapComNormalFog::UpdateMapPos(EventCustom *pEvent){
  if(!pEvent)
    return;
  
  auto lTilePos = *static_cast<Vec2 *>(pEvent->getUserData());
  if(lTilePos.x != _TiledBgX || lTilePos.y != _TiledBgY){
    _TiledBgX = lTilePos.x;
    _TiledBgY = lTilePos.y;
    RefreshMapPos(lTilePos);
  }
}

void WorldMapComNormalFog::RefreshMapPos(Vec2 pPos){

  if(!_TiledBg)
    return;
    
  auto lZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto lScaleX = _TiledBg->getContentSize().width / TileBG_Size / lZoomScale;
  auto lScaleY = _TiledBg->getContentSize().height / TileBG_Size / lZoomScale;
  auto lPosX = fmod(pPos.x , TileBG_Size) / TileBG_Size;
  auto lPosY = fmod(pPos.y , TileBG_Size) / TileBG_Size;

  RMeshNodeShaderCfg lShaderCfg;
  lShaderCfg.Attr = EUniformType::Vec4;
  lShaderCfg.UnifromName = "_Texture_ST";
  lShaderCfg.Vec4Value = Vec4(lScaleX, lScaleY, pPos.x, pPos.y);

  GBase::DSetProgramStateParam(_Program, _State, { lShaderCfg });
}

void WorldMapComNormalFog::UpdateScaleZoom(EventCustom *p_Event){

  if(!_TiledBg)
    return;

  auto lZoomScale = p_Event ? *static_cast<float *>(p_Event->getUserData()) : _Target->_ViewScrollView->getZoomScale();
  auto [level, scale, scaleNext] = WorldMapLodCfg::Get()->GetFogMapScale(lZoomScale);
  GVector<RMeshNodeShaderCfg> lShaderCfgs(3);

  lShaderCfgs[0].Attr = EUniformType::Float;
  lShaderCfgs[0].UnifromName = "_mapScale";
  lShaderCfgs[0].FloatValue = scale;
  
  lShaderCfgs[1].Attr = EUniformType::Float;
  lShaderCfgs[1].UnifromName = "_mapScale_next";
  lShaderCfgs[1].FloatValue = scaleNext;
  
  lShaderCfgs[2].Attr = EUniformType::Float;
  lShaderCfgs[2].UnifromName = "_mapLevel";
  lShaderCfgs[2].FloatValue = level;
  
  GBase::DSetProgramStateParam(_Program, _State, lShaderCfgs);
}

void WorldMapComNormalFog::ReloadTmxFogShader(){
  if(!_TiledBg)
    return;
  _Program = GLProgram::createWithByteArrays(FogNormalShader::Vert, FogNormalShader::Frag);
  _State = GLProgramState::create(_Program);
  GVector<RMeshNodeShaderCfg> lShaderCfgs(5);

  lShaderCfgs[0].Attr = EUniformType::Texture;
  lShaderCfgs[0].UnifromName = "_Texture";
  lShaderCfgs[0].TexPath = "tileMaps/atlantis_png/fog_normal.png";
  lShaderCfgs[0].TexParam = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

  lShaderCfgs[1].Attr = EUniformType::Vec4;
  lShaderCfgs[1].UnifromName = "_Texture_ST";
  lShaderCfgs[1].Vec4Value = Vec4(1, 1, 0, 0);

  lShaderCfgs[2].Attr = EUniformType::Vec4;
  lShaderCfgs[2].UnifromName = "_resolution";
  lShaderCfgs[2].Vec4Value = _Resolution;

  lShaderCfgs[3].Attr = EUniformType::Vec4;
  lShaderCfgs[3].UnifromName = "_tileInfo";
  lShaderCfgs[3].Vec4Value = _TileInfo;

  auto lRect = _FogData->_Rect;
  lShaderCfgs[4].Attr = EUniformType::Vec4;
  lShaderCfgs[4].UnifromName = "_fogRect";
  lShaderCfgs[4].Vec4Value = Vec4(lRect.ltX - 1, lRect.ltY - 1, lRect.rbX - 1, lRect.rbY - 1);
  
  GBase::DSetProgramStateParam(_Program, _State, lShaderCfgs);
  _TiledBg->setGLProgramState(_State);
}

void WorldMapComNormalFog::Ctor(){}

