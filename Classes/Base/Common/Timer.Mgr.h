#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

namespace GBase{

bool DManagerFindTimerByTarget(const GString &p_Id);
void DManagerRemoveTimerByTarget(const GString &p_Id);
void DManagerAddTimer(const GString &p_Id);
int32 DCreateDelayTimer(Node *p_Target, const std::function<void()> &p_Func, float p_Delay);

};