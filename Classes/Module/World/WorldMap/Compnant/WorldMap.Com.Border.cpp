#include "WorldMap.Com.Border.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"
#include "Module/UI/Scene/World/Neighbour/UIWorldMapNeighbour.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/UI/Panel/World/WorldMap/Overlay/UIWorldMapBottomPoint.h"
#include "Module/World/Kingdom/KingdomPoint.Define.h"
#include "Module/World/Kingdom/Kingdom.Ctrl.h"
#include "Module/World/Kingdom/NationalFlag.Read.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Functions/ServiceFunction.h"


float _ScaleBorder = 4;

WorldMapComBorder *WorldMapComBorder::Create(RViewClass p_Config, WorldMapView *p_Target){
  WorldMapComBorder *l_Result = new WorldMapComBorder();
  l_Result->_Config = p_Config;
  l_Result->_Target = p_Target;
  l_Result->Ctor();
  return l_Result;
}

void WorldMapComBorder::Ctor(){
  _LodCfgScale = _Config._BorderLodScale;
}

void WorldMapComBorder::Init(){
  // self.lodConfig = nil
  _CurCell = _Target->_CurrentInMapViewCell;
  CreateGrayBorder(_Target->_MapSize.width);
  InitNeighbourKingdom();
}

void WorldMapComBorder::OnMessageListener(){
  //IWorldMapComponent::OnMessageListener();
  AddEventListener(WorldMapEvent::Get()->EVENT_TILE_POS, CC_CALLBACK_1(WorldMapComBorder::UpdateMapPos, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_ZOOM, CC_CALLBACK_1(WorldMapComBorder::UpdateScaleZoom, this));
}

void WorldMapComBorder::UpdateBorderPosition(){
  _NodeNeighbour->setPosition(_CurCell->getPosition());
  auto l_Kp1 = _CurCell->GetKingdomPoint();
  auto l_Kp2 = _Target->_CurrentInMapViewCell->GetKingdomPoint();
  if(l_Kp1 == l_Kp2)
    return;
  _CurCell = _Target->_CurrentInMapViewCell;
  RefreshNeighbourKingdom();
}

void WorldMapComBorder::UpdateScaleZoom(EventCustom *p_Event){
  if(!p_Event)
    return;
  if(!p_Event->getUserData())
    return;
  auto l_Scale = *(float*)p_Event->getUserData();
  auto l_Config = WorldMapUtil::Get()->GetLodByScale(l_Scale, _LodConfig ? *_LodConfig : _LodCfgScale[0]);
  if(_LodConfig){
    _LodConfig = l_Config;
    UpdateBorderCfg(l_Config);
  }
  
  auto l_NodeScale = GMath::Min(100.f, 1.f / l_Scale * 2);
  for(auto l_Node : _NodeNeighbour->_NodeKingdomList){
    l_Node->setScale(l_NodeScale);
  }
}

void WorldMapComBorder::UpdateMapPos(EventCustom *pEvent){
  auto l_ZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto l_BottomPointNode = _Target->GetBottomPointNode();
  auto l_TilePoint = l_BottomPointNode->_TilePoint;
  auto l_TileMin = GMath::Min(100.f, 1.f / l_ZoomScale * 2);
  auto l_TileMax = 1200 - l_TileMin;
  auto l_TileX = GMath::Clamp(l_TilePoint.x, l_TileMin, l_TileMax);
  auto l_TileY = GMath::Clamp(l_TilePoint.y, l_TileMin, l_TileMax);
  GVector<Vec2> l_TilePointList;
  l_TilePointList.push_back(Vec2(l_TileX, 1200.5));
  l_TilePointList.push_back(Vec2(l_TileX, -0.5));
  l_TilePointList.push_back(Vec2(-0.5, l_TileY));
  l_TilePointList.push_back(Vec2(1200.5, l_TileY));
  GVector<Vec2> l_PosList;
  for(auto l_TilePoint : l_TilePointList){
    auto l_Point = _Target->GetPointWithTile(l_TilePoint);
    l_PosList.push_back(Vec2(l_Point.x - _Target->_MapSize.width / 2, l_Point.y - _Target->_MapSize.height / 2));
  }
  auto index = 0;
  for(auto l_Node : _NodeNeighbour->_NodeKingdomList){
    l_Node->setPosition(l_PosList[index++]);
  }
}

void WorldMapComBorder::UpdateBorderCfg(RBorderLodScale p_Config){
  auto l_State = _BorderGrayState;
  if(_BorderGrayState){
    _BorderGrayState->setUniformFloat("borderHeight", p_Config._BorderHeight * _ScaleBorder);
    _BorderGrayState->setUniformFloat("borderRatio", p_Config._BorderRatio / _ScaleBorder);
  }
}

void WorldMapComBorder::CreateCurCellBorder(float p_MapWidth){
  auto l_TexWidth = 32;
  auto l_Length = p_MapWidth * 128.f;
  Mat4 l_Mat = {
    1, -0.5, 0, 0,
    -1, -0.5, 0, 0,
    0, 0, 1, 0,
    0, l_Length * 0.5f, 0, 1
  };
  RMeshData l_MeshData;
  l_MeshData._Vertices = {
    0, 0, 0, 0,
    l_Length, 0, l_Length, 0,
    0, 0, 0, 0,
    0, l_Length, 0, l_Length,
    0, l_Length, 0, l_Length,
    l_Length, l_Length, l_Length, l_Length,
    l_Length, 0, l_Length, 0,
    l_Length, l_Length, l_Length, l_Length
  };

  auto l_MaxU = l_Length / l_TexWidth;
  
  l_MeshData._UV = {
    0, 0, 0, 1,
    l_MaxU, 1,
    l_MaxU,
    0, 0, 0, 0,
    1, l_MaxU,
    1, l_MaxU,
    0, 0, 0, 0,
    1, l_MaxU,
    1, l_MaxU,
    0, 0, 0, 0,
    1, l_MaxU,
    1, l_MaxU,
    0
  };
  l_MeshData._Normals = {
    -1, -1, -1, 1, 1, 1,
    1, -1, 1, -1, -1, -1,
    -1, 1, 1, 1, -1, -1,
    -1, 1, 1, 1, 1, -1,
    1, -1, -1, -1, -1,
    1,  1, 1
  };
  l_MeshData._Triangles = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11,
    8, 12, 13, 14, 14,
    15, 12
  };
  RMeshNodeShader l_Shader;
  l_Shader.VertPath = "Shaders/worldBorder.vsh";
  l_Shader.FragPath = "Shaders/worldBorder.fsh";

  GVector<RMeshNodeShaderCfg> l_Param;
  RMeshNodeShaderCfg l_OneParam;

  l_OneParam.Attr = EUniformType::Texture;
  l_OneParam.TexPath = "SinglePicture/worldmap_border.png";
  l_OneParam.UnifromName = "texture";
  l_OneParam.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_OneParam.texForce = true;
  l_Param.push_back(l_OneParam);
  
  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.FloatValue = 2 * _ScaleBorder;
  l_OneParam.UnifromName = "borderHeight";
  l_Param.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.FloatValue = 1 / _ScaleBorder;
  l_OneParam.UnifromName = "borderRatio";
  l_Param.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.Vec4Value = Vec4(1, 0.9490196078431372, 0.8156862745098039, 1);
  l_OneParam.UnifromName = "borderColor";
  l_Param.push_back(l_OneParam);
  
  RMeshNodeParm l_MeshNodeParam;
  l_MeshNodeParam._Mesh = l_MeshData;
  l_MeshNodeParam.Shader = l_Shader;
  auto [l_Mesh, l_ShaderTemp, l_State] = GBase::DCreateMeshNode(l_MeshNodeParam, nullptr);
  _Target->_ContainerView->addChild(l_Mesh, static_cast<int32>(EWorldMapZOrder::tmxView) + 1);
  l_Mesh->setName("border");
  l_Mesh->setBlendFunc({GL_ONE, GL_ONE_MINUS_SRC_ALPHA});
  l_Mesh->setAdditionalTransform(l_Mat);
  // mesh:setGroupID(worldMapDefine.GROU_ID.group_border)
  _Border = l_Mesh;
  _BorderState = l_Mesh->getGLProgramState();
}

void WorldMapComBorder::CreateGrayBorder(float p_MapWidth){
  auto l_TexWidth = 32;
  auto l_Length = p_MapWidth * 128.f;
  auto l_MaxU = l_Length / l_TexWidth;
  auto l_TempIndex = 0;
  Mat4 l_Mat = {
    1, -0.5, 0, 0,
    -1, -0.5, 0, 0,
    0, 0, 1, 0,
    0, l_Length, 0, 1
  };

  GVector<float> l_Vertices;
  GVector<float> l_UV;
  GVector<float> l_Normals;
  GVector<unsigned short> l_Triangles;
  
  for(int x = 0; x < 4; x++){
    for(int y = 0; y < 4; y++){
      auto l_TempX = x - 1;
      auto l_TempY = y - 1;
      auto l_VerticesIndex = l_Vertices.size();
      auto l_UvIndex = l_UV.size();
      auto l_NormalIndex = l_Normals.size();
      auto l_TrianglesIndex = l_Triangles.size();
      auto l_BeginX = l_TempX * l_Length;
      auto l_BeginY = l_TempY * l_Length;
      auto l_EndX = (l_TempX/*+ 1*/) * l_Length;
      auto l_EndY = (l_TempY/*+ 1*/) * l_Length;
      l_Vertices[l_VerticesIndex + 0] = l_BeginX;
      l_Vertices[l_VerticesIndex + 1] = l_BeginY;
      l_Vertices[l_VerticesIndex + 2] = l_BeginX;
      l_Vertices[l_VerticesIndex + 3] = l_BeginY;
      l_Vertices[l_VerticesIndex + 4] = l_EndX;
      l_Vertices[l_VerticesIndex + 5] = l_BeginY;
      l_Vertices[l_VerticesIndex + 6] = l_EndX;
      l_Vertices[l_VerticesIndex + 7] = l_BeginY;
      l_Vertices[l_VerticesIndex + 8] = l_BeginX;
      l_Vertices[l_VerticesIndex + 9] = l_BeginY;
      l_Vertices[l_VerticesIndex + 10] = l_BeginX;
      l_Vertices[l_VerticesIndex + 11] = l_BeginY;
      l_Vertices[l_VerticesIndex + 12] = l_BeginX;
      l_Vertices[l_VerticesIndex + 13] = l_EndX;
      l_Vertices[l_VerticesIndex + 14] = l_BeginX;
      l_Vertices[l_VerticesIndex + 15] = l_EndX;

      for(int tempUvIndex = 0; tempUvIndex < 2; tempUvIndex++){
        l_UV[l_UvIndex + tempUvIndex * 8 + 0] = 0;
        l_UV[l_UvIndex + tempUvIndex * 8 + 1] = 0;
        l_UV[l_UvIndex + tempUvIndex * 8 + 2] = 0;
        l_UV[l_UvIndex + tempUvIndex * 8 + 3] = 1;
        l_UV[l_UvIndex + tempUvIndex * 8 + 4] = l_MaxU;
        l_UV[l_UvIndex + tempUvIndex * 8 + 5] = 1;
        l_UV[l_UvIndex + tempUvIndex * 8 + 6] = l_MaxU;
        l_UV[l_UvIndex + tempUvIndex * 8 + 7] = 0;
      }

      l_Normals[l_NormalIndex + 0] = -1;
      l_Normals[l_NormalIndex + 1] = -1;
      l_Normals[l_NormalIndex + 2] = -1;
      l_Normals[l_NormalIndex + 3] = 1;
      l_Normals[l_NormalIndex + 4] = 1;
      l_Normals[l_NormalIndex + 5] = 1;
      l_Normals[l_NormalIndex + 6] = 1;
      l_Normals[l_NormalIndex + 7] = -1;
      l_Normals[l_NormalIndex + 8] = 1;
      l_Normals[l_NormalIndex + 9] = -1;
      l_Normals[l_NormalIndex + 10] = -1;
      l_Normals[l_NormalIndex + 11] = -1;
      l_Normals[l_NormalIndex + 12] = -1;
      l_Normals[l_NormalIndex + 13] = 1;
      l_Normals[l_NormalIndex + 14] = 1;
      l_Normals[l_NormalIndex + 15] = 1;

      l_Triangles[l_TrianglesIndex + 0] = l_TempIndex * 8 + 0;
      l_Triangles[l_TrianglesIndex + 1] = l_TempIndex * 8 + 1;
      l_Triangles[l_TrianglesIndex + 2] = l_TempIndex * 8 + 2;
      l_Triangles[l_TrianglesIndex + 3] = l_TempIndex * 8 + 2;
      l_Triangles[l_TrianglesIndex + 4] = l_TempIndex * 8 + 3;
      l_Triangles[l_TrianglesIndex + 5] = l_TempIndex * 8 + 0;
      l_Triangles[l_TrianglesIndex + 6] = l_TempIndex * 8 + 4;
      l_Triangles[l_TrianglesIndex + 7] = l_TempIndex * 8 + 5;
      l_Triangles[l_TrianglesIndex + 8] = l_TempIndex * 8 + 6;
      l_Triangles[l_TrianglesIndex + 9] = l_TempIndex * 8 + 6;
      l_Triangles[l_TrianglesIndex + 10] = l_TempIndex * 8 + 7;
      l_Triangles[l_TrianglesIndex + 11] = l_TempIndex * 8 + 4;
      l_TempIndex++;
    }
  }

  RMeshData l_MeshData;
  l_MeshData._Vertices = l_Vertices;
  l_MeshData._UV = l_UV;
  l_MeshData._Normals = l_Normals;
  l_MeshData._Triangles = l_Triangles;

  RMeshNodeShader l_Shader;
  l_Shader.VertPath = "Shaders/worldBorder.vsh";
  l_Shader.FragPath = "Shaders/worldBorder.fsh";

  GVector<RMeshNodeShaderCfg> l_Params;
  RMeshNodeShaderCfg l_OneParam;

  l_OneParam.Attr = EUniformType::Texture;
  l_OneParam.TexPath = "SinglePicture/worldmap_border.png";
  l_OneParam.UnifromName = "texture";
  l_OneParam.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_OneParam.texForce = true;
  l_Params.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.FloatValue = 2 * _ScaleBorder;
  l_OneParam.UnifromName = "borderHeight";
  l_Params.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Float;
  l_OneParam.FloatValue = 1 / _ScaleBorder;
  l_OneParam.UnifromName = "borderRatio";
  l_Params.push_back(l_OneParam);

  l_OneParam.Attr = EUniformType::Vec4;
  l_OneParam.Vec4Value = Vec4(1, 0.9490196078431372, 0.8156862745098039, 1);
  l_OneParam.UnifromName = "borderColor";
  l_Params.push_back(l_OneParam);

  RMeshNodeParm l_MeshNodeParam;
  l_MeshNodeParam._Mesh = l_MeshData;
  l_MeshNodeParam.Shader = l_Shader;
  l_MeshNodeParam.Param = l_Params;
  
  auto [l_Mesh, l_ShaderTemp, l_State] = GBase::DCreateMeshNode(l_MeshNodeParam, nullptr);
  l_Mesh->setBlendFunc({GL_ONE, GL_ONE_MINUS_SRC_ALPHA});
  l_Mesh->setName("borderGray");
  _Target->_ContainerView->addChild(l_Mesh, static_cast<int32>(EWorldMapZOrder::tmxView) + 1);
  l_Mesh->setAdditionalTransform(l_Mat);
  // mesh:setGroupID(worldMapDefine.GROU_ID.group_border)
  auto l_ContainerViewSize = _Target->_ContainerView->getContentSize();
  l_Mesh->setPosition(l_ContainerViewSize.width / 2, l_ContainerViewSize.height / 2);
  _BorderGray = l_Mesh;
  _BorderGrayState = l_Mesh->getGLProgramState();
}

void WorldMapComBorder::InitNeighbourKingdom(){
  auto l_MapViewCell = _Target->_CurrentInMapViewCell;
  auto l_KingdomID = l_MapViewCell->GetKingdomID();
  _NodeNeighbour = CreateNeighbourKingdomView(l_KingdomID);
  _NodeNeighbour->setPosition(l_MapViewCell->getPosition());
  RefreshNeighbourKingdom();
}

UIWorldMapNeighbour *WorldMapComBorder::CreateNeighbourKingdomView(int32 p_KingdomId){
  GVector<Vec2> l_PosList = {
    Vec2(-76800, -38400),
    Vec2(76800, 38400),
    Vec2(-76800, 38400),
    Vec2(76800, -38400)
  };
  
  auto l_WorldMapNeighbour = UIWorldMapNeighbour::Create();
  _Target->_ContainerView->addChild(l_WorldMapNeighbour, static_cast<int32>(WorldMapDefine::Z_ORDER_CELL::objView) + 1);
  GVector<Node *> l_NodeKingdomList;
  auto index = 1;
  for(auto l_Pos : l_PosList){
    auto l_NodeKingdom = GBase::DGetChildByName<Node *>(l_WorldMapNeighbour, GString("Node_kingdom" + std::to_string(index++)).c_str());
    l_NodeKingdom->setScale(100);
    l_NodeKingdom->setPosition(l_Pos);
    //   SoraDGetAllChildFromWidget(Node_kingdom, Node_kingdom)
    l_NodeKingdomList.push_back(l_NodeKingdom);
  }
  l_WorldMapNeighbour->_NodeKingdomList = l_NodeKingdomList;
  return l_WorldMapNeighbour;
}

void WorldMapComBorder::RefreshNeighbourKingdom(){
  auto [l_UpID, l_DownID, l_LeftID, l_RightID] = KingdomPointDefine::Get()->GetNeighbourKingdomsByPoint(_CurCell->GetKingdomPoint(), _CurCell->GetRegionID());
  GVector<int32> l_KindomList = {
    l_DownID,
    l_UpID,
    l_LeftID,
    l_RightID
  };
  auto index = 0;
  for(auto l_Node : _NodeNeighbour->_NodeKingdomList){
    auto l_KingdomID = l_KindomList[index++];
    RefreshNeighbourSingle(l_Node, l_KingdomID);
  }
}

void WorldMapComBorder::RefreshNeighbourSingle(Node *p_Node, int32 p_KingdomId){
    
  auto l_TextName = GBase::DGetChildByName<ui::Text *>(p_Node, "Text_name");
  auto l_SpriteFlag = GBase::DGetChildByName<Sprite *>(p_Node, "Sprite_flag");
  auto l_KInfo = KingdomCtrl::Get()->IsFoundKingdomID(p_KingdomId);
  if(l_KInfo){
    l_TextName->setString(l_KInfo->_KName);
  }else{
    auto l_KingdomName =  GServiceFunction::Get()->GetKingdomFormatName();
    l_TextName->setString(l_KingdomName);
  }
  auto l_FlagImg = NationalFlagRead::Get()->GetImgByID(l_KInfo ? l_KInfo->_KFlagId : 0);
  l_SpriteFlag->setSpriteFrame(l_FlagImg);
  l_SpriteFlag->setVisible(true);

  GBase::DToCenter(GBase::DGetChildByName<Sprite *>(p_Node, "Node_info"));
}