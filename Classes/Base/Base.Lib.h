#pragma once
#include "Include/IncludeEngine.h"
class GBase{
public:
  /*
    this Function Recursivly loop in all children to find the mean of the children's position
  */
  template <typename T>
  static T getChildByName(Node* p_Node, const char* p_name);

  static void playSound(const char* p_SoundName, bool p_IsLoop = false, float p_delay = 0.0f);
  static const char *getSoundPath(const char *p_SoundName);
  static void SoraDFTarget(Node *p_node){}
};


template <typename T>
T GBase::getChildByName(Node* p_Node, const char* p_name){
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