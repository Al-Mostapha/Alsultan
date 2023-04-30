#pragma once
#include "Common.Type.h"
#include "Base/Containers/HashMap.h"

class ITask;
class UICommonSpeedUpBox;
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
  UICommonSpeedUpBox *DShowSpeedUpBox(
    ITask *,const std::function<void(EMsgBoxCallBack)> &p_CB= nullptr, 
    GString Msg = "", GHashMap<GString, GString> = {});
};