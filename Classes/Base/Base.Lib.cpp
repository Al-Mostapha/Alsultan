#include "Base.Lib.h"

Node *GBase::getChildByName(Node* p_Node, const char* p_name){
  if(!p_Node)
    return nullptr;
  std::string t =   p_Node->getName();
  if(p_Node->getName() == (std::string) p_name){
    auto tt = 0;
    return p_Node;
  }
  for(auto child : p_Node->getChildren()){
    Node *node = getChildByName(child, p_name);
    if(node)
      return node;
  }
    
  return nullptr;
}