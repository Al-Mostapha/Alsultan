#pragma once
#include "Include/IncludeBase.h"
#include "Global.Enum.h"

#define INIT_FALSE true

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
  GOpt<bool> gEnableWorldMap3D;
  Vec3 gWorldMapRotation3D = Vec3(-20, 0, 0);
  Vec3 gWorldMapRotation2D = Vec3(0, 0, 0);
  float gWorldMapRotation3D_X = -20;
  bool Global_isLoginNeedLoading = false;
};