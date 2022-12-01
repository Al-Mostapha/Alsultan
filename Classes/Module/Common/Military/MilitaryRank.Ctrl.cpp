#include "MilitaryRank.Ctrl.h"

MilitaryRankCtrl *MilitaryRankCtrl::Get()
{
  static MilitaryRankCtrl *s_MilitaryRankCtrl = new MilitaryRankCtrl();
  return s_MilitaryRankCtrl;
}


void MilitaryRankCtrl::SendMarshalLoginTip()
{
  // Do something
}