#include "WorldWar.Def.h"

WorldMapWarDef * WorldMapWarDef::Get()
{
  static WorldMapWarDef * p_WorldMapWarDef = new WorldMapWarDef();
  return p_WorldMapWarDef;
}

GString WorldMapWarDef::GetKingdomClassTips(EKingdomClassType type, int32 p_IdKingdom){
  return "Kingdom Tip";
};