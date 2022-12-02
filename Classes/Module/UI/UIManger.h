#pragma once
#include "Include/IncludeBase.h"
#include "UIBaseView.h"

class UIManger{
public:
  static UIManger *Get();
  void CloseAllUI(){}
  bool IsShow(const char *p_ViewName){ return true;}
  void Close(const char *p_ViewName){}
  UIBaseView *GetProxy(const char *p_ProxyName){ return nullptr;}
};