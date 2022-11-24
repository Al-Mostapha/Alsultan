#include "MeshNode.h"

namespace GBase{

  Mesh *DCreateMeshNode(Size size,Mesh *p_Node){
      // if(!p_Node)
      //     p_Node = Mesh::create();
      // meshNode:setContentSize(size)
      auto l_MeshNode = Sprite3D::create("3d/box.c3b");
      l_MeshNode->setContentSize(size);
      //p_Node->setContentSize(size)
      // local shaderCache = cc.GLProgramCache:getInstance()
     // auto l_ShaderCache = GLProgramCache::getInstance();
      // if shader.vert then
      //   shader = cc.GLProgram:createWithFilenames(shader.vert, shader.frag, defined)
      // elseif shader.vertBytes then
      //   print("defined", tostring(defined))
      //   shader = cc.GLProgram:createWithByteArrays(shader.vertBytes, shader.fragBytes, defined)
      // else
      //   return
      // end
      // if shader == nil then
      //   assert(shader, "SoraDCreateMeshNode shader is null !")
      // end
      // local state = cc.GLProgramState:create(shader)
      // meshNode:setGLProgramState(state)
      // local sharedTextureCache = cc.Director:getInstance():getTextureCache()
      // SoraDSetProgramStateParam(shader, state, param)
      // if mesh.is3d then
      //   meshNode:setIs3D(true)
      // end
      // meshNode:setMeshData(mesh.vertices, mesh.colors or {}, mesh.uv, mesh.triangles, mesh.normals or {})
      // if mesh.bounds and meshNode.setBounds then
      //   meshNode:setBounds(cc.rect(mesh.bounds.minPos[1], mesh.bounds.minPos[2], mesh.bounds.size[1], mesh.bounds.size[2]), cc.p(unpack(mesh.bounds.center)))
      //   meshNode:setAutoCull(true)
      // end
      // return meshNode, shader, state
  }

};