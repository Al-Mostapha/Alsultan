#include "InstanceCache.Mgr.h"
#include "IWorldMapInstance.h"

InstanceCacheMgr * InstanceCacheMgr::Get()
{
  static InstanceCacheMgr *sInstance = nullptr;
  if (sInstance == nullptr)
  {
    sInstance = new InstanceCacheMgr();
  }
  return sInstance;
}

Node *InstanceCacheMgr::GetInstance(int32 pInstanceType){
  return nullptr;
}

void InstanceCacheMgr::AddNormalNode(Node *pNode){
 
}