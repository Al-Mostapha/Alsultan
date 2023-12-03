#pragma once
#include "Base/BaseTypeDef.h"
#include "CommandHall.Enum.h"
#include "Base/Type/XEngine.h"

class CommandHallTaskNode : public Node{
  public:
    Sprite *_BgSprite = nullptr;
    Sprite *_IconSprite = nullptr;
    CREATE_FUNC(CommandHallTaskNode);
    void Ctor(){}
    void SetTaskID(ECommandHallTaskType pTaskID){}
};

class CommandHallUtil{
  public:
    static CommandHallUtil *Get();
    CommandHallTaskNode *CreateTaskNode();
};