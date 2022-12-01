#include "WorldMap.Define.h"

WorldMapDefine * WorldMapDefine::Get(){
  static WorldMapDefine * _WorldMapDefine = nullptr;
  if(_WorldMapDefine == nullptr){
    _WorldMapDefine = new WorldMapDefine();
  }
  return _WorldMapDefine;
}