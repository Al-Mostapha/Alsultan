#include "WorldWar.Def.h"

WorldMapWarDef * WorldMapWarDef::Get()
{
  static WorldMapWarDef * p_WorldMapWarDef = new WorldMapWarDef();
  return p_WorldMapWarDef;
}

GString WorldMapWarDef::GetKingdomClassTips(EKingdomClassType type, int32 p_IdKingdom){
  return "Kingdom Tip";
};

EKingdomClassType WorldMapWarDef::GetKingdomMapClassByKingdomId(int32 p_IdKingdom){
  return EKingdomClassType::Normal;
};

bool WorldMapWarDef::IsInWarForbidBonePoing(EKingdomClassType p_MapType){
  return false;
}

int32 WorldMapWarDef::GetMapRangMaxX(EKingdomClassType p_MapType){
  return 1201;
}