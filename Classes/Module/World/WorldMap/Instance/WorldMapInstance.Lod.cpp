#include "WorldMapInstance.Lod.h"

int32 WorldMapInstanceLod::GetHoldInstance(){
  return 1;
}

void WorldMapInstanceLod::RemoveInstanceSelf(){
  
}

Vec2 WorldMapInstanceLod::GetTilePoint(){
  return Vec2(0, 0);
}

uint32 WorldMapInstanceLod::GetInstanceID(){
  return 1;
}