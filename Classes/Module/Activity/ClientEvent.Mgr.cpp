#include "ClientEvent.Mgr.h"
#include "Module/Translation/Translate.h"
#include "ActivityShow.Ctrl.h"
#include "Base/Base.Lib.h"

ClientEventMgr *ClientEventMgr::Get()
{
  static auto s_Instance = new ClientEventMgr();
  return s_Instance;
}

bool ClientEventMgr::JudgeIsOpen(EActivityTime p_IdEvent, bool p_PopTip)
{
  auto l_EventState = ActivityShowCtrl::Get()->SetStateByID(p_IdEvent);
  if(l_EventState == EActivityState::None)
  {
    return false;
  }else if(l_EventState == EActivityState::Open)
  {
    return true;
  }else{
    if(p_PopTip)
    {
      if(l_EventState == EActivityState::Prepare)
      {
        GBase::DShowMsgTip(Translate::i18n("common_text_608"));
      }else if(l_EventState == EActivityState::Close){
        GBase::DShowMsgTip(Translate::i18n("common_text_2486"));
      }
    }
  }
  return false;
}