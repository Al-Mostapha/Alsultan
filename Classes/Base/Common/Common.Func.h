#pragma once
#include "Common.Type.h"


namespace GBase{
  Node *DCreateEffectNode(
    const GVector<RCreatEffctParam> &p_Parm, 
    const char *p_Folder = nullptr, 
    bool p_IsAutoRemoveOnfinish = false);
};