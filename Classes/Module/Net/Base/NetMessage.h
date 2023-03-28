#pragma once
#include "Base/BaseTypeDef.h"

class NetMessage {
  public:
  static NetMessage* Get() {
    static auto l_Inst = new NetMessage();
    return l_Inst;
  }
  static GString Decode(const GVector<char>* p_Res) { return ""; }
};