#include "Player.Static.h"
RPlayer PlayerStatic::SultanPlayer;

RPlayer& PlayerStatic::getPlayer(){
  return SultanPlayer;
}

PlayerStatic *PlayerStatic::Get(){
  static PlayerStatic *instance = new PlayerStatic();
  return instance;
}

GString PlayerStatic::GetPlayerToken(){
  return SultanPlayer._Token;
}