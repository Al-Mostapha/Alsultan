#include "WiseTutor.Ctrl.h"

WiseTutorCtrl *WiseTutorCtrl::Get(){
  auto static l_Inst = new WiseTutorCtrl();
  return l_Inst;
}


GPair<EActivityState, GTime> WiseTutorCtrl::GetStateInfo(){
  return GPair<EActivityState, GTime>(EActivityState::Open, 0);
}

bool WiseTutorCtrl::IsBuffEffect(){
  return true;
}