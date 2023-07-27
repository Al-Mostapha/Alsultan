#include "WorldMap.Com.ManorlineNew.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMapView.Def.h"
#include "Base/Base.Geometry.h"
#include "Module/Guild/Alliance.Mgr.h"
#include "Module/Guild/Relation/AllianceRelation.Ctrl.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/World/WorldMap/Shader/AllianceTerritoryDraw.h"
#include "Module/World/WorldMap/Shader/AllianceTerritoryLineShaderUniform.h"
#include "Module/World/WorldMap/Shader/AllianceTerritoryLineShader.h"

static const int TileBG_Size = 1024;

void WorldMapComManorLineNew::Ctor(){
  IWorldMapComponent::Ctor();
  _IsInNebula = WorldMapDefine::Get()->IsInNebula();
  auto lMapClassType = KingdomMapCtrl::Get()->GetKingdomClass();
  _MapRangMaxX = WorldMapWarDef::Get()->GetMapRangMaxX(lMapClassType);
}


void WorldMapComManorLineNew::Init(){
  IWorldMapComponent::Init();
}

void WorldMapComManorLineNew::OnMessageListener(){
  AddEventListener(WorldMapEvent::Get()->EVENT_TILE_POS, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateMapPos, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_TOOGLE_3D, CC_CALLBACK_1(WorldMapComManorLineNew::Toggle3D, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateLodLevel, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_UPDATE_INFO, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateInfo, this));
  
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_UPDATE_LEAGUEMANOR_INSTANCE", CC_CALLBACK_1(WorldMapComManorLineNew::UpdateLeagueManorInstance, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_UPDATE_LEAGUEMANOR_INSTANCE_RESET", CC_CALLBACK_1(WorldMapComManorLineNew::ResetLeagueManorInstance, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_NODEINFO_SELECT_CHANGE", CC_CALLBACK_1(WorldMapComManorLineNew::UpdateNodeInfoSelect, this));
  
  auto lHandlerChange = CC_CALLBACK_1(WorldMapComManorLineNew::UpdateRelationChange, this);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_RELATION_DATA_CHANGE", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIACNE_BE_KICKED", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_QUIT_SUCCESS", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_JOIN_SUCCESS", lHandlerChange);
}

void WorldMapComManorLineNew::Toggle3D(EventCustom* pEvent){
  if(!_TiledBg){
    return;
  }

  if(GGlobal::Get()->gEnableWorldMap3D && GGlobal::Get()->gEnableWorldMap3D.value()){
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
  }else{
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
  }
}

void WorldMapComManorLineNew::UpdateMapPos(EventCustom* pEvent){
  if(!pEvent)
    return;
  
  auto lTilePos = *static_cast<Vec2 *>(pEvent->getUserData());
  if(lTilePos.x != _TiledBgX || lTilePos.y != _TiledBgY){
    _TiledBgX = lTilePos.x;
    _TiledBgY = lTilePos.y;
    RefreshMapPos(lTilePos);
  }
}

void WorldMapComManorLineNew::RefreshMapPos(Vec2 pTilePos){
  if(!_TiledBg)
    return;
  auto lZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto lScaleX = _TiledBg->getContentSize().width / TileBG_Size / lZoomScale;
  auto lScaleY = _TiledBg->getContentSize().height / TileBG_Size / lZoomScale;

  GVector<RMeshNodeShaderCfg> lParam;
  RMeshNodeShaderCfg lParam1;
  lParam1.Attr = EUniformType::Vec4;
  lParam1.UnifromName = "_Texture_ST";
  lParam1.Vec4Value = Vec4(lScaleX, lScaleY, pTilePos.x, pTilePos.y);
  lParam.push_back(lParam1);
  GBase::DSetProgramStateParam(_Program, _State, lParam);
}

void WorldMapComManorLineNew::UpdateLodLevel(EventCustom* pEvent){

  if(!_TiledBg)
    return;
  auto lLodLevel = _Target->GetCurLod();
  auto lParam = GVector<RMeshNodeShaderCfg>();
  RMeshNodeShaderCfg lParam1;
  lParam1.Attr = EUniformType::Float;
  lParam1.UnifromName = "v_lodLevel";
  lParam1.FloatValue = static_cast<float>(lLodLevel);
  GBase::DSetProgramStateParam(_Program, _State, lParam);
  if(lLodLevel <= EWorldLodDef::LOD3){
    ShowManorline(true);
    if(WorldMapDefine::Get()->_CurSelectNodeInfo == WorldMapViewDef::Get()->NODEINFO_TYPE_ALLIANCE){
      UpdateRelationChange(nullptr);
    }
    
  }else{
    _CurSelectNodeInfo = 0;
    UpdateNodeInfoSelect(nullptr);
  }
}

void WorldMapComManorLineNew::ResetLeagueManorInstance(EventCustom* pEvent){
  _CurrentShowLeagueManorLineArrary.clear();
  _LeagueIDArrary.clear();
  _IsNeedRefresh = true;
  _ColorIdArrary.clear();
}

void WorldMapComManorLineNew::UpdateLeagueManorInstance(EventCustom* pEvent){
  if(!pEvent)
    return;
  if(!pEvent->getUserData())
    return;
  auto lData = *static_cast<RLeagueManorInstanceUpdateEvAr *>(pEvent->getUserData());

  if(!_ColorIdArrary.Contains(lData._LeagueID) || lData._ColorId > 0){
    _ColorIdArrary[lData._LeagueID] = lData._ColorId;
  }

  GHashMap<int32, GHashMap<int32, GVector<float>>> lManorDataArrary;
  if(_CurrentShowLeagueManorLineArrary.Contains(lData._LeagueID))
    lManorDataArrary = _CurrentShowLeagueManorLineArrary[lData._LeagueID];

  if(lData._UpdateType == EWorldMapLeagueManorUpdateType::Add){

    GVector<float> lLineData = {
      lData._TilePoint.x - lData._Radioation,
      lData._TilePoint.y - lData._Radioation,
      2.f * lData._Radioation + lData._Size,
      2.f * lData._Radioation + lData._Size
    };
  
    auto lCurLineArray = GetLineArray(lLineData, lData._Sn);
    if(!lManorDataArrary.size()){
      lManorDataArrary[1] = {};
      lManorDataArrary[2] = {};
    }
    if(lData._ActiviyStatus)
      lManorDataArrary[1][lData._InstanceID] = lCurLineArray;
    else 
      lManorDataArrary[2][lData._InstanceID] = lCurLineArray;

    _IsNeedRefresh = true;
  } else if(lData._UpdateType == EWorldMapLeagueManorUpdateType::Remove){
    if(!lManorDataArrary.size())
      return;
    if(lData._ActiviyStatus){
      lManorDataArrary[1].erase(lData._InstanceID);
    } else {
      lManorDataArrary[2].erase(lData._InstanceID);
    }
    _IsNeedRefresh = true;
  } else if(lData._UpdateType == EWorldMapLeagueManorUpdateType::Activity){
    if(!lManorDataArrary.size())
      return;

    if(lData._ActiviyStatus){
      GVector<float> lLineData =  {
        lData._TilePoint.x - lData._Radioation,
        lData._TilePoint.y - lData._Radioation,
        2.f * lData._Radioation + lData._Size,
        2.f * lData._Radioation + lData._Size
      };

      auto lCurLineArray = GetLineArray(lLineData, lData._Sn);
      lManorDataArrary[1][lData._InstanceID] = lCurLineArray;
      lManorDataArrary[2].erase(lData._InstanceID);

    }else{

      if(lManorDataArrary[1].Contains(lData._InstanceID)){
        lManorDataArrary[2][lData._InstanceID] = lManorDataArrary[1][lData._InstanceID];
        lManorDataArrary[1].erase(lData._InstanceID);
      }

    }
    _IsNeedRefresh = true;
  }
  _CurrentShowLeagueManorLineArrary[lData._LeagueID] = lManorDataArrary;
}

void WorldMapComManorLineNew::UpdateInfo(EventCustom* pEvent){
  if(_IsNeedRefresh){
    _IsNeedRefresh = false;
    SetAllianceTerritoryColor(_CurrentShowLeagueManorLineArrary, _Target->_ContainerView);
  }
}

GVector<float> WorldMapComManorLineNew::GetLineArray(const GVector<float> &pLineData, float pSN){
  GVector<float> lLineArray{
    pLineData[0],
    pLineData[1],
    pSN,
    pLineData[0] + pLineData[2],
    pLineData[1],
    pSN,
    pLineData[0],
    pLineData[1] + pLineData[3],
    pSN,
    pLineData[0] + pLineData[2],
    pLineData[1] + pLineData[3],
    pSN
  };
  return lLineArray;
}

int32 WorldMapComManorLineNew::GetLeagueIDIndex(int32 pLeagueID, bool pIsActivity){
  auto lLeagueIDIndex = -1;
  auto lItr = std::find(_LeagueIDArrary.begin(), _LeagueIDArrary.end(), pLeagueID);
  if(lItr == _LeagueIDArrary.end()){
    _LeagueIDArrary.push_back(pLeagueID);
    lLeagueIDIndex = _LeagueIDArrary.size() -  1;
  }

  if(pIsActivity)
    lLeagueIDIndex = lLeagueIDIndex * 2;
  else
    lLeagueIDIndex = lLeagueIDIndex * 2 - 1;
  return lLeagueIDIndex;
}

GTuple<GHashMap<int32, int32>, int32, int32> WorldMapComManorLineNew::InitSnMap(ManorArray pPointsArray, bool pOnlyShowSelf ){
  GVector<int32> lSnArrary;
  GHashMap<int32, bool> lSnKey;
  auto lNum = 0;
  for(auto [lLeagueID, lManorArray] : pPointsArray){
    if(!pOnlyShowSelf || _MyLeagueID == lLeagueID){
      for(auto [_, lV] : lManorArray){
        for(auto [_, lCurLineArray] : lV){
          auto lSn = lCurLineArray[2];
          if(!lSnKey.Contains(lSn)){
            lSnArrary.push_back(lSn);
            lSnKey[lSn] = true;
          }
          lNum++;
        }
      }
    }
  }
  std::sort(lSnArrary.begin(), lSnArrary.end());
  GHashMap<int32, int32> lSnMap;
  for(auto lI = 0; lI < (int)lSnArrary.size(); lI++){
    lSnMap[lSnArrary[lI]] = lI;
  }
  return {lSnMap, lSnArrary.size() ? lSnArrary[lSnArrary.size() - 1] : 0, lNum};
}

float WorldMapComManorLineNew::GetSnIndex(GHashMap<int32, int32> pSnMap, float pSn, bool pIsActivity){

  int32 lSnIndex = 0;
  if(pSnMap.Contains((int32)pSn))
    lSnIndex = pSnMap[pSn];
  if(pIsActivity)
    return lSnIndex * 0.1 - 1023;
  else
    return lSnIndex * 0.1;
}

int32 WorldMapComManorLineNew::GetCurMaxSn(){
  return _CurMaxSn;
}

void WorldMapComManorLineNew::SetAllianceTerritoryColor(ManorArray pPointsArray, Node *pParent){

  if(AllianceManager::Get()->GetOwnAid())
    _MyLeagueID = AllianceManager::Get()->GetOwnAid();
  
  bool lOnlyShowSelf = _Target->GetCurLod() > EWorldLodDef::LOD3 && WorldMapDefine::Get()->_CurSelectNodeInfo == WorldMapViewDef::Get()->NODEINFO_TYPE_ALLIANCE;
  auto [lSnMap, lCurMaxSn, lNum] = InitSnMap(pPointsArray);
  auto lVertices = GVector<float>(lNum * 12);
  auto lTriangles = GVector<unsigned short>(lNum * 6);
  auto lColors = GVector<float>(lNum * 16);
  int32 lIndex = 0;
  _CurMaxSn = lCurMaxSn;
  auto lIndexVertices = 0;
  auto lIndexColors = 0;
  auto lIndexTriangles = 0;

  for(auto [lLeagueID, lManorLineArray] : pPointsArray){
    if(!lOnlyShowSelf || _MyLeagueID == lLeagueID){
      auto lAllaianceRelationType = EMapAllianceRelationType::NORMAL;
      if(_IsInNebula){
      //       allianceRelationType = tonumber(string.sub(leagueID, -1, -1))
      }else{
        lAllaianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(lLeagueID);
        if(lAllaianceRelationType == EMapAllianceRelationType::None)
          lAllaianceRelationType = EMapAllianceRelationType::NORMAL;

        if(_MyLeagueID == lLeagueID)
          lAllaianceRelationType = EMapAllianceRelationType::SELF;
      }

      auto lCIndex = _ColorIdArrary[lLeagueID];
      for(auto [lActivityStatus, lV] : lManorLineArray){
        auto lAs = (lActivityStatus - 1) * 20;
        auto lRIndex = static_cast<float>(lAllaianceRelationType);
        auto lAllianceRType = static_cast<float>(lAllaianceRelationType);
        if(lAllianceRType > 3.5 && lAllianceRType < 5.5 && lCIndex > 0.5){
          lRIndex = lCIndex + 6;
        }
        
        auto lR = lRIndex + lAs;
        auto lIsActivity = lActivityStatus == 1;
        auto lLeagueIDIndex = GetLeagueIDIndex(lLeagueID, lIsActivity);
        auto lG = static_cast<int32>(std::floor(lLeagueIDIndex / 255));
        auto lB = (lLeagueIDIndex - 1) % 255 + 1;
        auto lTableColor = GVector<float>{
          lR / 255.f,
          lG / 255.f,
          lB / 255.f,
          1.f
        };
        
        for(auto [l_, lCurLineArray] : lV){
          auto lI = 0;
          for(auto lM : lCurLineArray){
            if(lI % 3 == 0){
              auto lSnIndex = GetSnIndex(lSnMap, lM, lIsActivity);
              lVertices[lIndexVertices] = lSnIndex;
              lIndexVertices++;
              for(auto lL : lTableColor){
                lColors[lIndexColors] = lL;
                lIndexColors++;
              }
            }else{
              lVertices[lIndexVertices] = lM;
              lIndexVertices++;
            }
          }

          for(auto j : {  0, 2, 1,  1,  2, 3}){
            lTriangles[lIndexTriangles] = j + lIndex * 4;
            lIndexTriangles++;
          }
          lIndex++;
        }
      }
    }
  }

  static RMeshNodeParm lMeshCfg;
  lMeshCfg._Mesh._Bounds._Center = Vec2(0, 0);
  lMeshCfg._Mesh._Bounds._Size = Size(10000, 10000);
  lMeshCfg._Mesh._Bounds._MinPos = Vec2(0, 0);
  lMeshCfg._Mesh._Is3D = true;

  lMeshCfg._Mesh._Vertices = lVertices;
  lMeshCfg._Mesh._Colors = lColors;
  lMeshCfg._Mesh._Triangles = lTriangles;
  if(!_MeshNode1){
    //   local shader = require("app.shader.allianceTerritoryMeshShader")
    //   local meshNode1 = SoraDCreateMeshNode(meshCfg, meshCfg.bounds.size, shader)
    _MeshNode1->setBlendFunc(BlendFunc{GL_ONE, GL_ONE_MINUS_SRC_ALPHA});
    //   meshNode1:setDepthTest(true)
    Director::getInstance()->setDepthTest(true);
    //   meshNode1:setDepthWrite(true)
    _MeshNode1->setForceDepthWrite(true);
    _MeshNode1->retain();
  }else{
    //   self.meshNode1:setMeshData(meshCfg.vertices, meshCfg.colors or {}, meshCfg.uv, meshCfg.triangles, meshCfg.normals or {})
  }

  if(!_RenderTexture1){
    _RenderTexture1 = RenderTexture::create(_MapRangMaxX, _MapRangMaxX, Texture2D::PixelFormat::RGBA8888, GL_DEPTH_COMPONENT16 /**33189*/);
    pParent->addChild(_RenderTexture1);
    _RenderTexture1->setPosition({GDisplay::Get()->cx, GDisplay::Get()->cy});
    //   self.renderTexture1:setProjection(cc.DIRECTOR_PROJECTION2_D)
  }
  
  _RenderTexture1->beginWithClear(0, 0, 0, 0, 1);
  _MeshNode1->Node::visit();
  _RenderTexture1->end();
  _RenderTexture1->setVisible(false);
  
  _TileTexture = _RenderTexture1->getSprite()->getTexture();
  _TileTexture->setTexParameters(Texture2D::TexParams{GL_NEAREST, GL_NEAREST, GL_REPEAT, GL_REPEAT});
  DrawRealAllianceLines(pParent);
}

void WorldMapComManorLineNew::DrawRealAllianceLines(Node *pParent){
  static RMeshNodeParm lMeshCfg;
  lMeshCfg._Mesh._Vertices = {
    0, 0, 0,
    _MapRangMaxX,
    _MapRangMaxX,
    0,
    _MapRangMaxX,
    _MapRangMaxX
  };
  lMeshCfg._Mesh._Triangles = {
    0, 2, 1,
    1, 2, 3
  };

  lMeshCfg._Mesh._UV = {
    0, 0, 0, 1, 
    1, 0, 1, 1
  };

  lMeshCfg._Mesh._Bounds._Center = Vec2(0, 0);
  lMeshCfg._Mesh._Bounds._Size = Size(_MapRangMaxX, _MapRangMaxX);
  lMeshCfg._Mesh._Bounds._MinPos = Vec2(0, 0);

  RMeshNodeShaderCfg lOneParam;
  lOneParam.Attr = EUniformType::Texture;
  lOneParam.UnifromName = "_TileTexture";
  lOneParam.Texture = _TileTexture;
  lOneParam.hasMipmap = false;
  lMeshCfg._Param = {lOneParam};

  lOneParam.Attr = EUniformType::Float;
  lOneParam.UnifromName = "step_tile";
  lOneParam.FloatValue = 1 / _MapRangMaxX;
  lMeshCfg._Param.push_back(lOneParam);

  if(!_MeshNode2){
    lMeshCfg.Shader.FragBytesCode = AllianceTerritoryDrawShader::Frag;
    lMeshCfg.Shader.VertBytesCode = AllianceTerritoryDrawShader::Vert;
    lMeshCfg.Shader.IsFile = false;
    std::tie(_MeshNode2, _Shader2, _State2) = GBase::DCreateMeshNode(lMeshCfg);
    _MeshNode2->setBlendFunc(BlendFunc{GL_ONE, GL_ONE_MINUS_SRC_ALPHA});
    _MeshNode2->retain();
  }else{
    GBase::DSetProgramStateParam(_Shader2, _State2, lMeshCfg._Param);
  }

  if(_RenderTexture2){
    _RenderTexture2  = RenderTexture::create(_MapRangMaxX, _MapRangMaxX, Texture2D::PixelFormat::RGBA8888);
    pParent->addChild(_RenderTexture2);
    _RenderTexture2->setPosition({GDisplay::Get()->cx, GDisplay::Get()->cy});
  }
  
  _RenderTexture2->beginWithClear(0, 0, 0, 0, 0);
  _MeshNode2->Node::visit();
  _RenderTexture2->end();
  _RenderTexture2->setVisible(false);
  _TileTexture = _RenderTexture2->getSprite()->getTexture();
  _TileTexture->setTexParameters(Texture2D::TexParams{GL_NEAREST, GL_NEAREST, GL_REPEAT, GL_REPEAT});

  if(!_TiledBg){
    _TiledBg = GDisplay::Get()->NewSprite("SinglePicture/bq_tex3.png");
    auto lWidth = GDisplay::Get()->width + 0.5 * GDisplay::Get()->height;
    auto lHeight = GDisplay::Get()->height * 1.35;
    auto lOffsetX = (GDisplay::Get()->width - lWidth) * 0.5;
    _TiledBg->setContentSize(Size(lWidth, lHeight));
    //   tiledBg:setGroupID(worldMapDefine.GROU_ID.tileEffectBatchNode)
    _Target->addChild(_TiledBg, static_cast<int32>(EWorldMapZOrder::scrollView));
    _TiledBg->setPositionX(lOffsetX);
    _TiledBg->setAnchorPoint(Vec2(0, 0));
    _TiledBg->setName("worldMapComManorlineNew");
    _Resolution = Vec4(TileBG_Size, TileBG_Size, lOffsetX / lWidth, 0);
    _TileInfo = Vec4(_MapRangMaxX, _MapRangMaxX, 256, 128);
    LoadShader();
  }
  
  lOneParam.Attr = EUniformType::Texture;
  lOneParam.UnifromName = "_TileTexture";
  lOneParam.Texture = _TileTexture;
  lOneParam.hasMipmap = false;
  
  GBase::DSetProgramStateParam(_Program, _State, {lOneParam});
  Toggle3D(nullptr);
  RefreshMapPos(Vec2(_TiledBgX, _TiledBgY));
}

void WorldMapComManorLineNew::OnExit(){
  // worldMapComManorlineNew.super.onExit(self)
  if(_MeshNode1)
    _MeshNode1->release();
  _MeshNode1 = nullptr;
  if(_MeshNode2)
    _MeshNode2->release();
  _MeshNode2 = nullptr;
}

void WorldMapComManorLineNew::LoadShader(){
  GVector<RMeshNodeShaderCfg> lAllianceAreaParam(6);

  lAllianceAreaParam[0].Attr = EUniformType::Texture;
  lAllianceAreaParam[0].UnifromName = "_TileTexture";
  lAllianceAreaParam[0].Texture = _TileTexture;
  lAllianceAreaParam[0].hasMipmap = false;

  lAllianceAreaParam[1].Attr = EUniformType::Vec4;
  lAllianceAreaParam[1].UnifromName = "_Texture_ST";
  lAllianceAreaParam[1].Vec4Value = Vec4(1, 1, 0, 0);

  lAllianceAreaParam[2].Attr = EUniformType::Vec4;
  lAllianceAreaParam[2].UnifromName = "_resolution";
  lAllianceAreaParam[2].Vec4Value = _Resolution;

  lAllianceAreaParam[3].Attr = EUniformType::Vec4;
  lAllianceAreaParam[3].UnifromName = "_tileInfo";
  lAllianceAreaParam[3].Vec4Value = _TileInfo;

  lAllianceAreaParam[4].Attr = EUniformType::Float;
  lAllianceAreaParam[4].UnifromName = "step_tile";
  lAllianceAreaParam[4].FloatValue = 1 / _MapRangMaxX;

  lAllianceAreaParam[5].Attr = EUniformType::Float;
  lAllianceAreaParam[5].UnifromName = "f_dottedLod";
  lAllianceAreaParam[5].FloatValue = _IsInNebula ? 4 : 2;


  GString lVert;
  GString lFrag;

  if(true /*cc.GLProgramState.setUniformFloatv*/){
    
    lVert = AllianceTerritoryLineShaderUniform::Vert;
    lFrag = AllianceTerritoryLineShaderUniform::Frag;

    auto lNewCorlorArray =AllianceRead::Get()->GetManorlineColorArray();

    auto lOneParam = RMeshNodeShaderCfg();
    lOneParam.Attr = EUniformType::FloatVector;
    lOneParam.UnifromName = "newCorlorArray";
    lOneParam.FloatVec = lNewCorlorArray;

    lAllianceAreaParam.push_back(lOneParam);
  }else{
    lVert = AllianceTerritoryLineShader::Vert;
    lFrag = AllianceTerritoryLineShader::Frag;
  }

  _Program = GLProgram::createWithByteArrays(lVert.c_str(), lFrag.c_str());
  _State = GLProgramState::create(_Program);
  GBase::DSetProgramStateParam(_Program, _State, lAllianceAreaParam);

  _TiledBg->setGLProgramState(_State);
  UpdateLodLevel(nullptr);
}

void WorldMapComManorLineNew::ReloadShader(){
  if(!_TiledBg)
    return;
  // if cc.GLProgramState.setUniformFloatv then
  //   package.loaded["app.shader.allianceTerritoryLineShaderUniform"] = nil
  // else
  //   package.loaded["app.shader.allianceTerritoryLineShader"] = nil
  // end
  LoadShader();
  RefreshMapPos(Vec2(_TiledBgX, _TiledBgY));
}

void WorldMapComManorLineNew::UpdateNodeInfoSelect(EventCustom* pEvent){
  
  if(_CurSelectNodeInfo && _CurSelectNodeInfo == WorldMapDefine::Get()->_CurSelectNodeInfo)
    return;

  _CurSelectNodeInfo = WorldMapDefine::Get()->_CurSelectNodeInfo;
  auto lIsShow = false;
  if(_CurSelectNodeInfo == WorldMapViewDef::Get()->NODEINFO_TYPE_MANORLINE || _CurSelectNodeInfo == WorldMapViewDef::Get()->NODEINFO_TYPE_ALLIANCE){
    lIsShow = true;
  }

  ShowManorline(lIsShow);
  UpdateRelationChange(nullptr);
}

void WorldMapComManorLineNew::ShowManorline(bool pIsShow){
  if(_TiledBg)
    _TiledBg->setVisible(pIsShow);
}

bool WorldMapComManorLineNew::IsInselfOrAllyLeagueManor(Vec2 pTilePoint, bool pIsCheckScore){
  auto lIsIn = false;
  auto lIsScoreEnough = false;

  Rect lRect {0, 0, 0, 0};

  for(auto [lLeagueID, lDataArray] : _CurrentShowLeagueManorLineArrary){
    if(lIsIn)
      break;
    
    auto lAllianceRelationType = AllianceRelationCtrl::Get()->GetRelationTypeWith(lLeagueID);
    if(_MyLeagueID == lLeagueID || lAllianceRelationType == EMapAllianceRelationType::ALLY){
      auto lData = lDataArray[1];
      for(auto [l_, lV] : lData){
        if(lIsIn)
          break;

        auto lSn = lV[2];
        if(lSn >= 0){
          auto lWidth = lV[9] - lV[0];
          auto lHeight = lV[10] - lV[1];
          lRect.origin.x = lV[0];
          lRect.origin.y = lV[1];
          lRect.size.width = lWidth - 1;
          lRect.size.height = lHeight - 1;
          if(lRect.containsPoint(pTilePoint)){
            lIsIn = true;
            if(pIsCheckScore){
              if(_MyLeagueID == lLeagueID){
                if(AllianceRelationCtrl::Get()->GetTerrScore(_MyLeagueID) > 15000)
                  lIsScoreEnough = true;
                break;
              }
              if(AllianceRelationCtrl::Get()->GetTerrScore(_MyLeagueID) > 15000 && AllianceRelationCtrl::Get()->GetTerrScore(lLeagueID) > 15000)
                lIsScoreEnough = true;
            }
            break;
          }
        }
      }
    }
  }
  
  if(lIsScoreEnough)
    return lIsIn && lIsScoreEnough;
  return lIsIn;
}

bool WorldMapComManorLineNew::IsInSelfLeagueManor(int32 pLeagueID, Rect _SelfManorRect){

  Rect lSelfRect {
    _SelfManorRect.origin.x - 1,
    _SelfManorRect.origin.y - 1,
    _SelfManorRect.size.width + 2,
    _SelfManorRect.size.height + 2
  };
  Rect lRect {0, 0, 0, 0};
  
  if(_CurrentShowLeagueManorLineArrary.Contains(pLeagueID))
    return false;
  for(auto [lK, lV] : _CurrentShowLeagueManorLineArrary[pLeagueID][1]){
    auto lSn = lV[2];
    if(lSn >= 0){
      auto lWidth = lV[9] - lV[0];
      lRect.origin.x = lV[0];
      lRect.origin.y = lV[1];
      lRect.size.width = lWidth - 1;
      lRect.size.height = lWidth - 1;
      auto lIsIn = GBase::DRectIntersectsRect(lSelfRect, lRect, true);
      if(lIsIn)
        return true;
    }
  }
  return false;
}

bool WorldMapComManorLineNew::IsInSelfHoldManor(int32 LeagueID, Rect _SelfManorRect){

  Rect lSelfRect {
    _SelfManorRect.origin.x - 1,
    _SelfManorRect.origin.y - 1,
    _SelfManorRect.size.width + 2,
    _SelfManorRect.size.height + 2
  };
  Rect lRect {0, 0, 0, 0};
  if(!_CurrentShowLeagueManorLineArrary.Contains(LeagueID))
    return false;

  auto lSelfLeagueManorDataArrary = _CurrentShowLeagueManorLineArrary[LeagueID];
  for(auto [lK, lV] : lSelfLeagueManorDataArrary[1]){
    auto lSn = lV[2];
    if(lSn == static_cast<int32>(EManorlineSn::strongHold)){
      auto lWidth = lV[9] - lV[0];
      auto lHeight = lV[10] - lV[1];
      lRect.origin.x = lV[0];
      lRect.origin.y = lV[1];
      lRect.size.width = lWidth - 1;
      lRect.size.height = lHeight - 1;
      auto lIsIn = GBase::DRectIntersectsRect(lSelfRect, lRect, true);
      if(lIsIn)
        return true;
    }
  }
  return false;
}

bool WorldMapComManorLineNew::IsFullInOtherLeagueManor(int32 pLeagueID, Rect _SelfManorRect, Rect pSelfBuildRect){

  auto lData = _Target->GetInstanceMapFromManager();
  Rect lRect {0, 0, 0, 0};
  
  for(auto [lK, lV] : lData){
    if(lV->_LeagueID > 0 && lV->_LeagueID != pLeagueID){
      lRect.origin.x = lV->_TilePoint.x;
      lRect.origin.y = lV->_TilePoint.y;
      lRect.size.width = lV->_Size.width - 1;
      lRect.size.height = lV->_Size.height - 1;
      auto lIsIn = GBase::DRectIntersectsRect(lRect, _SelfManorRect, true);
      if(lIsIn)
        return true;
    }
  }
  
  for(auto [lK, lV] : _CurrentShowLeagueManorLineArrary){
    if(lK != pLeagueID){
      for(auto [l_1, lM] : lV){
        for(auto [l_2, lN] : lM){
          auto lSn = lN[2];
          if(lSn >= 0){
            auto lWidth = lN[9] - lN[0];
            auto lHeight = lN[10] - lN[1];
            lRect.origin.x = lN[0];
            lRect.origin.y = lN[1];
            lRect.size.width = lWidth - 1;
            lRect.size.height = lHeight - 1;
            auto lIsIn = GBase::DRectIntersectsRect(pSelfBuildRect, lRect, true);
            if(lIsIn)
              return true;
          }
        }
      }
    }
  }
  return false;
}




void WorldMapComManorLineNew::UpdateRelationChange(EventCustom* pEvent){

}

