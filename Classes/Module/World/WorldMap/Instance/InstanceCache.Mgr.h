#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class IWorldMapInstance;

class InstanceCacheMgr
{
  public:
    static InstanceCacheMgr * Get();
    Node *GetInstance(int32 pInstanceType);
    void AddNormalNode(Node *pNode);
};