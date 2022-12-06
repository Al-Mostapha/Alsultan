#pragma once
#include "Base/BaseTypeDef.h"
namespace GBase{


bool DManagerFindTimerByTarget(const GString &p_Id);
void DManagerRemoveTimerByTarget(const GString &p_Id);
void DManagerAddTimer(const GString &p_Id);
};