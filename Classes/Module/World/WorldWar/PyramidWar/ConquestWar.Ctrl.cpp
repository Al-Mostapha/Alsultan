#include "ConquestWar.Ctrl.h"

ConquestWarCtrl* ConquestWarCtrl::Get()
{
  static ConquestWarCtrl *l_ConquestWarCtrl = nullptr;
  if(!l_ConquestWarCtrl){
    l_ConquestWarCtrl = new ConquestWarCtrl();
  }
  return l_ConquestWarCtrl;
}

EConquestWarState ConquestWarCtrl::GetConquestWarState()
{
  return EConquestWarState::None;
}

bool ConquestWarCtrl::IsMatchKingdom(int32 pKid1, int32 pKid2)
{
  return false;
}