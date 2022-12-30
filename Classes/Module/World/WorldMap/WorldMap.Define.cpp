#include "WorldMap.Define.h"

WorldMapDefine * WorldMapDefine::Get(){
  static WorldMapDefine * _WorldMapDefine = nullptr;
  if(_WorldMapDefine == nullptr){
    _WorldMapDefine = new WorldMapDefine();
  }
  return _WorldMapDefine;
}

bool WorldMapDefine::IsInWar(){
  return false;
}

bool WorldMapDefine::IsInLegendLord(){
  return false;
}

bool WorldMapDefine::IsInRemains(){
  return false;
}

bool WorldMapDefine::IsInRadiance(){
  return false;
}

bool WorldMapDefine::IsInAtlantis(){
  return false;
}