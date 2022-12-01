#pragma once
#include "Activity.Enum.h"

class ClientEventMgr
{
public:
  static ClientEventMgr *Get();
  bool JudgeIsOpen(EActivityTime p_IdEvent, bool p_PopTip = false);
};