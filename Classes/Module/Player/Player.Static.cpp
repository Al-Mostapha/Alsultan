#include "Player.Static.h"
TPlayer PlayerStatic::SultanPlayer;

TPlayer& PlayerStatic::getPlayer(){
  return SultanPlayer;
}