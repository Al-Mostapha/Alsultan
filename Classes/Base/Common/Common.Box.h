#pragma once
#include "Common.Type.h"

namespace GBase{
  void DShowBuyBox(
    const RShowBuyBoxParam &p_Param, 
    const std::function<void(EMsgBoxCallBack)> &p_Handle = {},
    bool *p_CanBuy = nullptr,
    const std::function<void(EMsgBoxCallBack)> &p_HandleTool = {},
    const GString &p_Tool = ""
    );
  Node *DShowLoading(Node *p_Parent, const Size &p_Size = Size::ZERO, 
  int32 p_Mark = 0, bool p_Transparent = false, GTime p_TimeOut = 0, bool p_IsShadow = false );
};