#include "Player.Top.h"

PlayerTop* PlayerTop::Get(){
  static PlayerTop* s_PlayerTop = nullptr;
  if(s_PlayerTop == nullptr){
    s_PlayerTop = new PlayerTop();
  }
  return s_PlayerTop;
}

int32 PlayerTop::GetMapID(){
  return 0;
}

Guid PlayerTop::GetPlayerID(){
  return Guid();
}