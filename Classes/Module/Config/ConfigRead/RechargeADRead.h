#pragma once
#include "Include/IncludeBase.h"

struct RRechargeAD{
  GString ClassName;
  int32 ADType;
  int32 MenuID;
  RRechargeAD(std::pair<GString, int32> p_Init)
    : ClassName(p_Init.first), MenuID(p_Init.second){}
};

class RechargeADRead{
  static GHashMap<int32, RRechargeAD> m_MapRechargeAD;
public:
  static RechargeADRead *Get();
  RRechargeAD IsADOpen(const GString &p_CCSFile = "");
  int32 VerifyData(int32 p_MenuID);
};