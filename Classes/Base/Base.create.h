#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
USING_NS_CC;

struct GAnimationParm
{
  struct
  {
    std::string Frame;
    int start;
    int end;
    float delay;
  } AnimateData;
  Vec2 Pos = Vec2(0, 1);
  Vec2 Scale = Vec2(1, 1);
  float rot = 0;
  float opacity = 1;
};

class BaseCreate
{
public:
  static ParticleSystemQuad *createParticle(const std::string &Part, Vec2 Pos, Vec2 Scl, float rot);
  static Sprite *createAnimation(GAnimationParm AnimationParm);
  static Vector<SpriteFrame *> getAnimationFrames(GString Frame, int32 start, int32 end);
  static Sprite *CreateSprite(const char *p_Sprite);
};

namespace GBase{
  Action *CreateAnimation(const char *p_FilePath, Node *p_Node = nullptr, bool p_Loop = false);
};