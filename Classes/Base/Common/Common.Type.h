#pragma once
#include "Base/BaseTypeDef.h"
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