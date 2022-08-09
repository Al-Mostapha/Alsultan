#pragma once
#include "Include/IncludeEngine.h"
class GBase{
public:
  /*
    this Function Recursivly loop in all children to find the mean of the children's position
  */
  static Node *getChildByName(Node* p_Node, const char* p_name);
};