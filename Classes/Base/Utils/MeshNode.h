#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"

typedef Sprite3D MeshNode;

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
  GOpt<GString> VertBytesCode;
  GOpt<GString> VertPath;
  GOpt<GString> FragBytesCode;
  GOpt<GString> FragPath;
  bool IsFile = false;
};

struct RMeshNodeShaderCfg{
  EUniformType Attr;
  GString TexPath = "";
  Texture2D *Texture;
  GString UnifromName = "";
  bool hasMipmap = false;
  Texture2D::TexParams TexParam;
  bool texForce = false;
  float FloatValue = 0.0f;
  GVector<float> FloatVec;
  Vec2 Vec2Value;
  Vec3 Vec3Value;
  Vec4 Vec4Value;
};

struct RMeshData{
  GVector<float> _Vertices;
  GVector<unsigned short> _Triangles;
  GVector<float> _Colors;
  GVector<float> _TexCoords;
  GVector<float> _Normals;
  GVector<float> _UV;
  struct {
    Size _Size;
    Vec2 _Center;
    Vec2 _MinPos;
  } _Bounds;
  bool _Is3D = false;
};

struct RMeshNodeParm{
  RMeshData _Mesh;
  RMeshNodeShader Shader;
  GVector<RMeshNodeShaderCfg> _Param;
  Size size;
  GString _Defined;

};

namespace GBase{
  GTuple<MeshNode *, GLProgram *, GLProgramState *> 
    DCreateMeshNode(const RMeshNodeParm &p_MeshData, MeshNode *p_Node = nullptr);
  void DSetProgramStateParam(
    GLProgram *p_Program, GLProgramState *p_State,
    const GVector<RMeshNodeShaderCfg> &p_ShaderParam, MeshNode *p_Mesh = nullptr);
};