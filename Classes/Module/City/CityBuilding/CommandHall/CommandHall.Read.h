#pragma once
#include "Base/BaseTypeDef.h"
#include "CommandHall.Type.h"

class CommandHallRead{
  public:
    static CommandHallRead *Get();
    GString GetTaskNpcResource(ECommandHallTaskType pTaskType);
    ECommandHallTaskType GetTaskType(ECommandHallTaskType pTaskID);
};