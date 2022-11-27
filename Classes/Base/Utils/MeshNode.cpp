#include "MeshNode.h"


namespace GBase{

  Mesh *DCreateMeshNode(const RMeshNodeParm &p_MeshData,Mesh *p_Node){
      // if(!p_Node)
      //   p_Node = Mesh::create();
      auto l_MeshNode = Sprite3D::create("3d/box.c3b");
      l_MeshNode->setContentSize(p_MeshData.size);
      //p_Node->setContentSize(size)
      backend::Program *l_Shader;
      if(!p_MeshData.Shader.IsFile){
        l_Shader = backend::Device::getInstance()->newProgram(p_MeshData.Shader.VertBytesCode.c_str(), p_MeshData.Shader.FragBytesCode.c_str());
      }else{
        auto vertSource = FileUtils::getInstance()->getStringFromFile(p_MeshData.Shader.VertPath.c_str());
        auto fragSourceRaw = FileUtils::getInstance()->getStringFromFile(p_MeshData.Shader.FragPath.c_str());
        l_Shader = backend::Device::getInstance()->newProgram(p_MeshData.Shader.VertBytesCode.c_str(), p_MeshData.Shader.FragBytesCode.c_str());
      }
      CCASSERT(l_Shader, "SoraDCreateMeshNode shader is null !");
      // local state = cc.GLProgramState:create(shader)
      auto l_State = new backend::ProgramState(l_Shader);
      // meshNode:setGLProgramState(state)
      p_Node->setProgramState(l_State);

      // local sharedTextureCache = cc.Director:getInstance():getTextureCache()
      auto l_SharedTextureCache = Director::getInstance()->getTextureCache();
      // SoraDSetProgramStateParam(shader, state, param)
      DSetProgramStateParam(l_Shader, l_State, p_MeshData.Param);
      // if mesh.is3d then
      //   meshNode:setIs3D(true)
      // end
      // meshNode:setMeshData(mesh.vertices, mesh.colors or {}, mesh.uv, mesh.triangles, mesh.normals or {})
      //l_MeshNode->setMeshData
      // MeshIndexData l_IndexData;
      // l_IndexData.setAABB()
      // p_Node->setMeshIndexData(&l_IndexData);
      // if mesh.bounds and meshNode.setBounds then
      
      //   meshNode:setBounds(cc.rect(mesh.bounds.minPos[1], mesh.bounds.minPos[2], mesh.bounds.size[1], mesh.bounds.size[2]), cc.p(unpack(mesh.bounds.center)))
      //   meshNode:setAutoCull(true)
      // end
      // return meshNode, shader, state
      return nullptr;
  }


  void DSetProgramStateParam(backend::Program *p_Program, backend::ProgramState *p_State, const GVector<RMeshNodeShaderCfg> &p_Param, Mesh *p_Mesh){

    for(auto l_OneParam : p_Param){
      if(l_OneParam.Attr == EUniformType::Texture){
        auto l_SharedTextureCache = Director::getInstance()->getTextureCache();
        auto l_Texture = l_SharedTextureCache->addImage(l_OneParam.TexPath);
        if(l_Texture){
          if(l_OneParam.hasMipmap && !l_Texture->hasMipmaps()){
            l_Texture->generateMipmap();
          }
          p_State->setTexture(
            p_Program->getUniformLocation(l_OneParam.UnifromName.c_str()),
            0, l_Texture->getBackendTexture());
          auto l_Size = l_Texture->getContentSize();
          if(l_Size.height == l_Size.width && ((int)l_Size.height & (int)(l_Size.height - 1)) == 0 || l_OneParam.texForce){
            l_Texture->setTexParameters(l_OneParam.TexParam);
          }
        }
      }else if(l_OneParam.Attr == EUniformType::HashTexture){
          if(l_OneParam.hasMipmap && !l_OneParam.Texture.hasMipmaps()){
            l_OneParam.Texture.generateMipmap();
          }
          p_State->setTexture(
            p_Program->getUniformLocation(l_OneParam.UnifromName.c_str()),
            0, l_OneParam.Texture.getBackendTexture());
        }else if(l_OneParam.Attr == EUniformType::MeshTexture){
          if(!p_Mesh) return;
          auto l_Tex = p_Mesh->getTexture()->getPath();
          if(l_Tex.empty()) return;
          GStringUtils::Replace(l_Tex, "_d.png", "_s.png");
          RMeshNodeShaderCfg l_NewParam ;
          l_NewParam.Attr = EUniformType::Texture;
          l_NewParam.TexPath = l_Tex;
          l_NewParam.UnifromName = l_OneParam.UnifromName;
          DSetProgramStateParam(p_Program, p_State, {l_NewParam});
        }else if(l_OneParam.Attr == EUniformType::Float){
          auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
          p_State->setUniform(l_Unifrom, &l_OneParam.FloatValue, sizeof(l_OneParam.FloatValue));
        }else if(l_OneParam.Attr == EUniformType::FloatVector){
          auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
          p_State->setUniform(l_Unifrom, &l_OneParam.FloatVec, l_OneParam.FloatVec.size());
        }else if(l_OneParam.Attr == EUniformType::Vec2){
          auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
          p_State->setUniform(l_Unifrom, &l_OneParam.Vec2Value, sizeof(l_OneParam.Vec2Value));
        }else if(l_OneParam.Attr == EUniformType::Vec3){
          auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
          p_State->setUniform(l_Unifrom, &l_OneParam.Vec2Value, sizeof(l_OneParam.Vec3Value));
        }else if(l_OneParam.Attr == EUniformType::Vec4){
          auto l_Unifrom = p_Program->getUniformLocation(l_OneParam.UnifromName.c_str());
          p_State->setUniform(l_Unifrom, &l_OneParam.Vec4Value, sizeof(l_OneParam.Vec4Value));
        }else if(l_OneParam.Attr == EUniformType::Function){
          //     if program:getUniform(v.name) then
          //       programState[v.value.setFun](programState, program:getUniform(v.name).location, v.value.paramFun())
          //     end
        }else if(l_OneParam.Attr == EUniformType::TimeUv){
          //     programState:setUniformTimeAnimation(v.name, v.value.kU or va.value.ku, v.value.kV or v.value.kv)
        }
      }
  }

};