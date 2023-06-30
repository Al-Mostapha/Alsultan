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

bool WorldMapDefine::InInCrossWar(){
  return false;
}

bool WorldMapDefine::IsInKingdomBattle(){
  return false;
}

bool WorldMapDefine::IsInWarForbid(bool p_NoShowTips, bool p_Activity){
  return false;
}

bool WorldMapDefine::IsInWarForbidSoldier(bool p_NoShowTips, bool p_Activity){
  return false;
}

void WorldMapDefine::ShowWarTips(bool p_Activity){
  
}

bool WorldMapDefine::IsNebulaKingdomID(){
  return false;
}

bool WorldMapDefine::IsInNebula(){
  return false;
}

bool WorldMapDefine::IsLegendLordKingdomID(){
  return false;
}