#pragma once
#include "Include/IncludeBase.h"

class UIManger{
public:
  static UIManger *Get();
  void CloseAllUI(){}
  bool IsShow(const char *p_ViewName){ return true;}
  void Close(const char *p_ViewName){}
};