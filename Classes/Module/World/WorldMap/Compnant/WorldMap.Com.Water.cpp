#include "WorldMap.Com.Water.h"
#include "Module/World/WorldMap/Shader/WorldWater.h"
#include "Module/World/WorldMap/Shader/AtlantisWater.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Base/Utils/MeshNode.h"

void WorldMapComWater::Ctor(){

}

void WorldMapComWater::Init(){

}

void WorldMapComWater::OnMessageListener(){
  if(_Target->_MapClassType == EKingdomClassType::Atlantis || _Target->_MapClassType == EKingdomClassType::Normal)
    InitAtlantisWater();
  else
    InitWater();
}

void WorldMapComWater::InitWater(){
  //   local waterShader = require("app.game.worldMap.shader.worldWater")
  // local program = cc.GLProgram:createWithByteArrays(waterShader.vertBytes, waterShader.fragBytes)
  auto l_Program = GLProgram::createWithByteArrays(WorldWaterShader::Vert, WorldWaterShader::Frag);
  // local state = cc.GLProgramState:create(program)
  auto l_State = GLProgramState::create(l_Program);
  GVector<RMeshNodeShaderCfg> l_WaterParam;
  RMeshNodeShaderCfg l_OneParam;

  RMeshNodeShaderCfg l_OneParam1;
  l_OneParam1.Attr = EUniformType::Texture;
  l_OneParam1.UnifromName = "_texture11";
  l_OneParam1.TexPath = "SinglePicture/citywater3.png";
  l_OneParam1.hasMipmap = false;
  l_OneParam1.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_WaterParam.push_back(l_OneParam1);

  RMeshNodeShaderCfg l_OneParam2; 
  l_OneParam2.Attr = EUniformType::Texture;
  l_OneParam2.UnifromName = "_texture12";
  l_OneParam2.TexPath = "SinglePicture/citywater3.png";
  l_OneParam2.hasMipmap = false;
  l_OneParam2.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_WaterParam.push_back(l_OneParam2);

  RMeshNodeShaderCfg l_OneParam3;
  l_OneParam3.Attr = EUniformType::Texture;
  l_OneParam3.UnifromName = "_textureall";
  l_OneParam3.TexPath = "SinglePicture/citywater5.png";
  l_OneParam3.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_WaterParam.push_back(l_OneParam3);

  RMeshNodeShaderCfg l_OneParam4;
  l_OneParam4.Attr = EUniformType::Texture;
  l_OneParam4.UnifromName = "_zhezhao";
  l_OneParam4.TexPath = "SinglePicture/citywater4.png";
  l_OneParam4.hasMipmap = false;
  l_OneParam4.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  l_WaterParam.push_back(l_OneParam4);

  RMeshNodeShaderCfg l_OneParam5;
  l_OneParam5.Attr = EUniformType::Texture;
  l_OneParam5.UnifromName = "_waterMask";
  l_OneParam5.TexPath = "tileMaps/World_png/World_mask.png";
  l_OneParam5.hasMipmap = false;
  l_WaterParam.push_back(l_OneParam5);


  RMeshNodeShaderCfg l_OneParamFloat;
  l_OneParamFloat.Attr = EUniformType::Float;
  l_OneParamFloat.UnifromName = "_niuqu_qd";  
  l_OneParamFloat.FloatValue = -0.01f;
  l_WaterParam.push_back(l_OneParamFloat);

  l_OneParamFloat.Attr = EUniformType::Float;
  l_OneParamFloat.UnifromName = "_niuqu1_qd";  
  l_OneParamFloat.FloatValue = 0.15f;
  l_WaterParam.push_back(l_OneParamFloat);

  l_OneParamFloat.Attr = EUniformType::Float;
  l_OneParamFloat.UnifromName = "_niuqu2_qd";  
  l_OneParamFloat.FloatValue = 0.03f;
  l_WaterParam.push_back(l_OneParamFloat);

  l_OneParamFloat.Attr = EUniformType::Float;
  l_OneParamFloat.UnifromName = "_niuqu3_qd";  
  l_OneParamFloat.FloatValue = -0.33f;
  l_WaterParam.push_back(l_OneParamFloat);

  l_OneParamFloat.Attr = EUniformType::Float;
  l_OneParamFloat.UnifromName = "_swater_ld";  
  l_OneParamFloat.FloatValue = 5;
  l_WaterParam.push_back(l_OneParamFloat);

  RMeshNodeShaderCfg l_OneParamVec4;
  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_texture11_ST";
  l_OneParamVec4.Vec4Value = {5.f, 10.f, 0.f, 0.f};
  l_WaterParam.push_back(l_OneParamVec4);

  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_texture12_ST";
  l_OneParamVec4.Vec4Value = {12.2f, 15.f, 2.92f, 0.f};
  l_WaterParam.push_back(l_OneParamVec4);


  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_textureall_ST";
  l_OneParamVec4.Vec4Value = {5.66f, 4.77f, 0.f, 0.f};
  l_WaterParam.push_back(l_OneParamVec4);

  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_zhezhao_ST";
  l_OneParamVec4.Vec4Value = {2.f, 1.73f, 0.81f, 0.f};
  l_WaterParam.push_back(l_OneParamVec4);

  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_water_color";
  l_OneParamVec4.Vec4Value = {0.596078431372549f, 0.8823529411764706f, 1.f, 1.f};
  l_WaterParam.push_back(l_OneParamVec4);

  l_OneParam4.Attr = EUniformType::Vec4;
  l_OneParam4.UnifromName = "_swater2_color";
  l_OneParam4.Vec4Value = {0.03529411764705882f, 0.03529411764705882f, 0.03529411764705882f, 1.f};
  l_WaterParam.push_back(l_OneParam4);


  l_OneParamVec4.Attr = EUniformType::Vec4;
  l_OneParamVec4.UnifromName = "_swater3_color";
  l_OneParamVec4.Vec4Value = {0.f, 0.1803921568627451f, 0.22745098039215686f, 1.f};
  l_WaterParam.push_back(l_OneParamVec4);

  RMeshNodeShaderCfg l_OneParamTime;
  l_OneParamTime.Attr = EUniformType::TimeUv;
  l_OneParamTime.UnifromName = "time_uv0";
  l_OneParamTime.Vec2Value = {-0.0024f, 0.0012f};
  l_WaterParam.push_back(l_OneParamTime);

  l_OneParamTime.Attr = EUniformType::TimeUv;
  l_OneParamTime.UnifromName = "time_uv1";
  l_OneParamTime.Vec2Value = {-0.0015f, 0.0015f};
  l_WaterParam.push_back(l_OneParamTime);

  l_OneParamTime.Attr = EUniformType::TimeUv;
  l_OneParamTime.UnifromName = "time_uv2";
  l_OneParamTime.Vec2Value = {-0.012f, 0.0015f};
  l_WaterParam.push_back(l_OneParamTime);

  GBase::DSetProgramStateParam(l_Program, l_State, l_WaterParam);
  GVector<int32> l_FilterGID;
  for(int32 i = 5; i <= 23; i++){
    l_FilterGID.push_back(i);
  }
  _Target->_MapLayer->initFilterLayer(l_FilterGID, l_State);
  _Target->_MapLayer->setFilterBlendFunc({GL_ONE, GL_ONE});
}

void WorldMapComWater::InitAtlantisWater(){

  auto lProgram = GLProgram::createWithByteArrays(AtlantisWaterShader::Vert, AtlantisWaterShader::Frag);
  auto lState = GLProgramState::create(lProgram);
  auto lWaterMask = "tileMaps/commonMap/World_1.png";
  GVector<RMeshNodeShaderCfg> lWaterParam;

  RMeshNodeShaderCfg lTexParam1;
  lTexParam1.Attr = EUniformType::Texture;
  lTexParam1.UnifromName = "_texture11";
  lTexParam1.TexPath = "SinglePicture/citywater3.png";
  lTexParam1.hasMipmap = false;
  lTexParam1.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  lWaterParam.push_back(lTexParam1);

  RMeshNodeShaderCfg lTexParam2;
  lTexParam2.Attr = EUniformType::Texture;
  lTexParam2.UnifromName = "_textureall";
  lTexParam2.TexPath = "SinglePicture/citywater5.png";
  lTexParam2.hasMipmap = false;
  lTexParam2.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  lWaterParam.push_back(lTexParam2);

  RMeshNodeShaderCfg lTexParam3;
  lTexParam3.Attr = EUniformType::Texture;
  lTexParam3.UnifromName = "_zhezhao";
  lTexParam3.TexPath = "SinglePicture/citywater4.png";
  lTexParam3.hasMipmap = false;
  lTexParam3.TexParam = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
  lWaterParam.push_back(lTexParam3);

  RMeshNodeShaderCfg lTexParam4;
  lTexParam4.Attr = EUniformType::Texture;
  lTexParam4.UnifromName = "_waterMask";
  lTexParam4.hasMipmap = false;
  lWaterParam.push_back(lTexParam4);
  
  RMeshNodeShaderCfg lVec2Param;
  lVec2Param.Attr = EUniformType::Vec2;
  lVec2Param.UnifromName = "_texture11_ST";
  lVec2Param.Vec2Value = {5.f, 10.f};
  lWaterParam.push_back(lVec2Param);

  RMeshNodeShaderCfg lVec4Param;
  lVec4Param.Attr = EUniformType::Vec4;
  lVec4Param.UnifromName = "_texture12_ST";
  lVec4Param.Vec4Value = {12.2f, 15.f, 2.92f, 0.f};
  lWaterParam.push_back(lVec4Param);

  lVec2Param.Attr = EUniformType::Vec2;
  lVec2Param.UnifromName = "_textureall_ST";
  lVec2Param.Vec2Value = { 5.66f, 4.77f};
  lWaterParam.push_back(lVec2Param);

  lVec4Param.UnifromName = "_zhezhao_ST";
  lVec4Param.Vec4Value = {2.f, 1.73f, 0.81f, 0.f};
  lWaterParam.push_back(lVec4Param);

  lVec4Param.UnifromName = "_water_color";
  lVec4Param.Vec4Value = {0.596078431372549f, 0.8823529411764706f, 1.f, 1.f};
  lWaterParam.push_back(lVec4Param);

  lVec4Param.UnifromName = "_swater2_color";
  lVec4Param.Vec4Value = {0.03529411764705882f, 0.03529411764705882f, 0.03529411764705882f, 1.f};
  lWaterParam.push_back(lVec4Param);

  lVec4Param.UnifromName = "_swater3_color";
  lVec4Param.Vec4Value = {0.f, 0.1803921568627451f, 0.22745098039215686f, 1.f};
  lWaterParam.push_back(lVec4Param);

  RMeshNodeShaderCfg lTimeParam;
  lTimeParam.Attr = EUniformType::TimeUv;
  lTimeParam.UnifromName = "time_uv0";
  lTimeParam.Vec2Value = {-0.0024f, 0.0012f};
  lWaterParam.push_back(lTimeParam);

  lTimeParam.UnifromName = "time_uv1";
  lTimeParam.Vec2Value = {-0.0015f, 0.0015f};
  lWaterParam.push_back(lTimeParam);
  
  lTimeParam.UnifromName = "time_uv2";
  lTimeParam.Vec2Value = {-0.012f, 0.0015f};
  lWaterParam.push_back(lTimeParam);
  
  GBase::DSetProgramStateParam(lProgram, lState, lWaterParam);
  GVector<int32> lFilterGID = {
    5, 6, 7, 12, 13, 14, 19, 20, 21, 26,
    27, 28, 33, 34, 35, 40, 41, 42, 95
  };

  auto lWaterLayer = _Target->_TmxView->getLayer("water");
  lWaterLayer->setIsFilterEnable(true);
  lWaterLayer->initFilterLayer(lFilterGID, lState);
  lWaterLayer->setFilterBlendFunc({GL_ONE, GL_ONE});
}