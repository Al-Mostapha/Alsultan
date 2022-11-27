#include "RechargeADRead.h"

GHashMap<int32, RRechargeAD> RechargeADRead::m_MapRechargeAD ;

RechargeADRead *RechargeADRead::Get(){
  static auto l_Inst = new RechargeADRead();
  return l_Inst;
}

RRechargeAD RechargeADRead::IsADOpen(const GString &p_CCSFile){
  RRechargeAD l_Ret = std::make_pair(GString(""), 0);
  l_Ret.ADType = 0;
  for(auto &l_Pair : m_MapRechargeAD){
    if(l_Pair.second.ClassName == p_CCSFile){
        l_Ret.ADType = 1;
        l_Ret.MenuID = l_Pair.second.MenuID;
    }
  }
  if(l_Ret.ADType){
    l_Ret.ADType = VerifyData(l_Ret.MenuID);
  }
  return l_Ret;
}

int32 RechargeADRead::VerifyData(int32 p_MenuID){
  return 0;
}