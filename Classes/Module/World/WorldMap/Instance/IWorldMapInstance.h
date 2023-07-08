#pragma once
#include "WorldMapInstance.Lod.h"
#include "Module/UI/UIBasePanel.h"

class IWorldMapInstance : public WorldMapInstanceLod
{
public:
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *p_Node);
};