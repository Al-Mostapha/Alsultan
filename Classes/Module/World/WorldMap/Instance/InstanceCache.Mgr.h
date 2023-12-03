#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"


class IWorldMapInstance;

class InstanceCacheMgr
{
  public:
    static InstanceCacheMgr * Get();
    Node *GetInstance(int32 pInstanceType);
    void AddNormalNode(Node *pNode);
};