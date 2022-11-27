#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "renderer/backend/Device.h"

enum class EUniformType{
  Node,
  Texture,
  HashTexture,
  MeshTexture,
  Float,
  FloatVector,
  Vec2,
  Vec3,
  Vec4,
  Function,
  TimeUv
};

struct RMeshNodeShader{
  GString VertBytesCode;
  GString VertPath;
  GString FragBytesCode;
  GString FragPath;
  bool IsFile = false;
};

struct RMeshNodeShaderCfg{
  EUniformType Attr;
  GString TexPath = "";
  Texture2D Texture;
  GString UnifromName = "";
  bool hasMipmap = false;
  backend::SamplerDescriptor TexParam;
  bool texForce = false;
  float FloatValue = 0.0f;
  GVector<float> FloatVec;
  Vec2 Vec2Value;
  Vec3 Vec3Value;
  Vec4 Vec4Value;
};
struct RMeshNodeParm{
  RMeshNodeShader &Shader;
  GVector<RMeshNodeShaderCfg> &Param;
  Size size;

};

namespace GBase{
  Mesh *DCreateMeshNode(const RMeshNodeParm &p_MeshData, Mesh *p_Node = nullptr);
  void DSetProgramStateParam(
    backend::Program *p_Program, backend::ProgramState *p_State,
    const GVector<RMeshNodeShaderCfg> &p_ShaderParam, Mesh *p_Mesh = nullptr);
};