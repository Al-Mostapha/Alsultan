#include "MeshNode.h"




GTuple<MeshNode *, GLProgram *, GLProgramState *> 
GBase::DCreateMeshNode(const RMeshNodeParm &p_MeshData, Sprite3D *p_Node){
  auto l_MeshNode = p_Node ? p_Node : Sprite3D::create();
  l_MeshNode->setContentSize(p_MeshData.size);
  auto l_ShaderCache = GLProgramCache::getInstance();
  GLProgram *l_Shader = nullptr;
  if(p_MeshData.Shader.VertPath){
    auto l_Vert = p_MeshData.Shader.VertPath.value();
    auto l_Frag = p_MeshData.Shader.FragPath.value();
    l_Shader = GLProgram::createWithFilenames(l_Vert, l_Frag, p_MeshData._Defined);
  }else if(p_MeshData.Shader.VertBytesCode){
    auto l_Vert = p_MeshData.Shader.VertBytesCode.value().c_str();
    auto l_Frag = p_MeshData.Shader.FragBytesCode.value().c_str();
    l_Shader = GLProgram::createWithByteArrays(l_Vert, l_Frag, p_MeshData._Defined);
  }else{
    return {};
  }

  CCASSERT(l_Shader, "SoraDCreateMeshNode shader is null !");
  auto l_State = GLProgramState::create(l_Shader);
  l_MeshNode->setGLProgramState(l_State);
  auto l_SharedTextureCache = Director::getInstance()->getTextureCache();
  DSetProgramStateParam(l_Shader, l_State, p_MeshData.Param);
  if(p_MeshData._Mesh._Is3D){
    //l_MeshNode->setIs3D(true);
  }
  // meshNode:setMeshData(mesh.vertices, mesh.colors or {}, mesh.uv, mesh.triangles, mesh.normals or {})
  // if mesh.bounds and meshNode.setBounds then
  //   meshNode:setBounds(cc.rect(mesh.bounds.minPos[1], mesh.bounds.minPos[2], mesh.bounds.size[1], mesh.bounds.size[2]), cc.p(unpack(mesh.bounds.center)))
  //   meshNode:setAutoCull(true)
  // end
  // return meshNode, shader, state
  return {l_MeshNode, l_Shader, l_State};
}


void GBase::DSetProgramStateParam(GLProgram *p_Program, GLProgramState *p_State, const GVector<RMeshNodeShaderCfg> &p_Param, MeshNode *p_Mesh){

  for(auto l_OneParam : p_Param){
    if(l_OneParam.Attr == EUniformType::Texture){
      auto l_SharedTextureCache = Director::getInstance()->getTextureCache();
      auto l_Texture = l_SharedTextureCache->addImage(l_OneParam.TexPath);
      if(l_Texture){
        if(l_OneParam.hasMipmap && !l_Texture->hasMipmaps()){
          l_Texture->generateMipmap();
        }
        p_State->setUniformTexture(l_OneParam.UnifromName.c_str(), l_Texture);
        auto l_Size = l_Texture->getContentSize();
        if(l_Size.height == l_Size.width && ((int)l_Size.height & (int)(l_Size.height - 1)) == 0 || l_OneParam.texForce){
          l_Texture->setTexParameters(l_OneParam.TexParam);
        }
      }
    }else if(l_OneParam.Attr == EUniformType::HashTexture){
        if(l_OneParam.hasMipmap && !l_OneParam.Texture->hasMipmaps()){
          l_OneParam.Texture->generateMipmap();
        }
        p_State->setUniformTexture(l_OneParam.UnifromName, l_OneParam.Texture);
      }else if(l_OneParam.Attr == EUniformType::MeshTexture){
        if(!p_Mesh) return;
        auto l_Tex = p_Mesh->getMesh()->getTexture()->getPath();
        if(l_Tex.empty()) return;
        GStringUtils::Replace(l_Tex, "_d.png", "_s.png");
        RMeshNodeShaderCfg l_NewParam ;
        l_NewParam.Attr = EUniformType::Texture;
        l_NewParam.TexPath = l_Tex;
        l_NewParam.UnifromName = l_OneParam.UnifromName;
        DSetProgramStateParam(p_Program, p_State, {l_NewParam});
      }else if(l_OneParam.Attr == EUniformType::Float){
        auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
        p_State->setUniformFloat(l_Unifrom, l_OneParam.FloatValue);
      }else if(l_OneParam.Attr == EUniformType::FloatVector){
        auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
        p_State->setUniformFloatv(l_Unifrom, l_OneParam.FloatVec.size(), l_OneParam.FloatVec.data());
      }else if(l_OneParam.Attr == EUniformType::Vec2){
        auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
        p_State->setUniformVec2(l_Unifrom, l_OneParam.Vec2Value);
      }else if(l_OneParam.Attr == EUniformType::Vec3){
        auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
        p_State->setUniformVec3(l_Unifrom, l_OneParam.Vec3Value);
      }else if(l_OneParam.Attr == EUniformType::Vec4){
        auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
        p_State->setUniformVec4(l_Unifrom, l_OneParam.Vec4Value);
      }else if(l_OneParam.Attr == EUniformType::Function){
        //     if program:getUniform(v.name) then
        //       programState[v.value.setFun](programState, program:getUniform(v.name).location, v.value.paramFun())
        //     end
      }else if(l_OneParam.Attr == EUniformType::TimeUv){
        //     programState:setUniformTimeAnimation(v.name, v.value.kU or va.value.ku, v.value.kV or v.value.kv)
      }
    }
}
