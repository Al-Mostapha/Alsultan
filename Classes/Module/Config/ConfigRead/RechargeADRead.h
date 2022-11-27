#pragma once
#include "Include/IncludeBase.h"

struct RRechargeAD{
  GString ClassName = "";
  int32 ADType = 0;
  int32 MenuID = 0;
  RRechargeAD(std::pair<GString, int32> p_Init)
    : ClassName(p_Init.first), MenuID(p_Init.second){}
  RRechargeAD &operator=(std::pair<GString, int32> p_Init){
    ClassName = p_Init.first;
    MenuID = p_Init.second;
    return *this;
  }
  RRechargeAD &operator=(RRechargeAD &p_Init){
    ClassName = p_Init.ClassName;
    MenuID = p_Init.MenuID;
    ADType = p_Init.ADType;
    return *this;
  }

  RRechargeAD &operator=(const RRechargeAD &p_Init){
    ClassName = p_Init.ClassName;
    MenuID = p_Init.MenuID;
    ADType = p_Init.ADType;
    return *this;
  }
};

class RechargeADRead{
  static GHashMap<int32, RRechargeAD> m_MapRechargeAD;
public:
  static RechargeADRead *Get();
  RRechargeAD IsADOpen(const GString &p_CCSFile = "");
  int32 VerifyData(int32 p_MenuID);
};