#pragma once
#include "Include/IncludeBase.h"
#include "Global.Enum.h"

#define INIT_FALSE true

struct RViewOtherData{
  int32 kingdomID = 0;
  operator bool() const{
    return true;
  }
};

namespace GBase{
  bool IEquals(const GString& a, const GString& b);
}

struct GGlobal{
  static GGlobal *Get(){
    static GGlobal *s_pInstance = nullptr;
    if (s_pInstance == nullptr)
    {
      s_pInstance = new GGlobal();
    }
    return s_pInstance;
  }
  EMainUIStyle MainUIStyle = EMainUIStyle::None;
  int32 GAME_LOGIN_FAIL_COUNT = 0;
  bool Global_isLoginNeedLoading = false;
};