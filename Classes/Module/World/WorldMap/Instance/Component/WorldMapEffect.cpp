#include "WorldMapEffect.h"

WorldMapEffect *WorldMapEffect::Get()
{
  static WorldMapEffect *s_WorldMapEffect = nullptr;
  if (!s_WorldMapEffect)
  {
    s_WorldMapEffect = new WorldMapEffect();
  }
  return s_WorldMapEffect;
}

FireTimeNode *WorldMapEffect::CreateFireTimeNode(){
  return FireTimeNode::create();
}