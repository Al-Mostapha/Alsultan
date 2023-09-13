#pragma once
#include "Base/BaseTypeDef.h"
#include "Common.Enum.h"

struct RStyleFormat;
class UICommonPromptBox;

namespace GBase{
  void DShowHelpMsgTip(GString p_Msg);
  void DShowHelpMsgTip(GString p_Msg, RStyleFormat p_Format);
  UICommonPromptBox* DShowMsgBox(GString p_Msg,
                              GString p_YesBtnTitle = "",
                              GString p_NoBtnTitle = "",
                              const GFunc<void(EMsgBoxCallBack)> &p_CallBack = nullptr,
                              void* p_Data = nullptr,
                              int p_Align = 0,
                              bool p_NoSound = false);
  UICommonPromptBox *DShowLoginFailBox(const char *p_FailType, 
    GString p_ShowMsg, bool p_HaveCancelBtn, GFunc<void()> p_CallBack);
  void ShowServerTip(const GString &pTitle, const GString &pContent);
};  