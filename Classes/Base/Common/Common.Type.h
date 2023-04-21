#pragma once
#include "Base/BaseTypeDef.h"
#include "Common.Enum.h"
#include "cocos2d.h"

using namespace cocos2d;

struct RCreatEffctParam{

  enum class FileType{
    None = 0,
    Particle = 1, 
    Csb = 2,
    Frames = 3
  };

  FileType _FileType = FileType::Particle;
  Vec2 _Pos;
  float _Rotate{0.0f};
  int32 _ZOrder{0};
  Vec2 _Scale{1, 1};
  GString _PList;
  float _Delay{0.0f};
  float _TpScale = 1;
  int32 _Tp = 0;
  GString _Name = "";
  ParticleSystem::PositionType _PosType = ParticleSystem::PositionType::RELATIVE;
};

struct RShowBuyBoxParam{
    RShowBuyBoxParam(GString p_Msg, int32 p_Gold, GString p_Title, GTime p_CostTime = 0):
    _Msg(p_Msg), _Gold(p_Gold), _Title(p_Title), _CostTime(p_CostTime){};
    GString _Msg;
    int32 _Gold;
    GString _Title;
    struct {
      bool _IsNeedJudge = false;
      const char *_Icon;
      float _Width = 0;
      bool _IsEnough = false;
    } _Parameter;
    GTime _CostTime;
    GString _CheckTip;
    bool _IsCheck;
    bool _IsInmediaGold;
    const char *_PanelName;
    struct {
      int32 _CurItemNum;
      GString _CurItemName;
      int32 _ExchangeNum;
      GString _ToItemName;
    } _HtmlParam;

};