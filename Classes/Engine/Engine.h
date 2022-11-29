#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
USING_NS_CC;

class GEngine{
  public: 
    static GEngine *Get();
    void Init();
    void PrintNodeTree(Node *p_Node, int p_Depth = 0);
};