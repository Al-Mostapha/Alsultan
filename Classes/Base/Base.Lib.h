#pragma once
#include "Include/IncludeEngine.h"
namespace GBase{
  
  template <typename T>
  T getChildByName(Node* p_Node, const char* p_name){
    if(!p_Node)
      return nullptr;
    if(p_Node->getName() == (std::string) p_name)
      return static_cast<T>(p_Node);

    for(auto child : p_Node->getChildren()){
      Node *node = getChildByName<Node *>(child, p_name);
      if(node)
        return static_cast<T>(node);
    }
      
    return nullptr;
  }

  void playSound(const char* p_SoundName, bool p_IsLoop = false, float p_delay = 0.0f);
  const char *getSoundPath(const char *p_SoundName);
  void SoraDFTarget(Node *p_node);
};


