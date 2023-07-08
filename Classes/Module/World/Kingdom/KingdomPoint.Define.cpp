#include "KingdomPoint.Define.h"

KingdomPointDefine * KingdomPointDefine::Get(){
  static KingdomPointDefine * _Instance = nullptr;
  if(_Instance == nullptr){
    _Instance = new KingdomPointDefine();
  }
  return _Instance;
}

GTuple<int32, int32, int32, int32> GetNeighbourKingdomsByPoint(Vec2 p_KingdomId, int32 p_RegionId){
  return { 0, 0, 0, 0};
}