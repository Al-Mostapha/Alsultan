#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class FireTimeNode : public Node{
  public:
  CREATE_FUNC(FireTimeNode);
  void Init(GTime pFireTime){}
};
class WorldMapEffect{
  public:
  static WorldMapEffect *Get();
  FireTimeNode *CreateFireTimeNode();
};