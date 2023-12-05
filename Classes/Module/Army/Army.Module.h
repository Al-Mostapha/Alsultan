#pragma once
#include "Include/IncludeBase.h"

class ArmyModule
{
public:
    static ArmyModule *Get();
    void Init();
    void StartGame();
};