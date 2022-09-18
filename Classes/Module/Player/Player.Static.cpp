#include "Player.Static.h"
RPlayer PlayerStatic::SultanPlayer;

RPlayer& PlayerStatic::getPlayer(){
  return SultanPlayer;
}