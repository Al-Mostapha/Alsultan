#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
#include "Base/Containers/Pair.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
typedef cocostudio::timeline::ActionTimeline XActionTimeLine;

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

struct RCreateWaveLabelParam
{
  Color3B _Color = Color3B(0, 255, 0);
  Vec2 _Pos = Vec2::ZERO;
  int32 _ZOrder = 1;
  int32 _FontSize = 24;
  float _Duration = 1;
  float _MoveH = 80;
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
  GPair<Node *, XActionTimeLine *> DCreateAnimation(const char *p_FilePath, Node *p_Node = nullptr, bool p_Loop = true);
  GPair<Node *, XActionTimeLine *> DCreateAnimationEx(const char *p_FilePath, Node *p_Node = nullptr, bool p_Loop = true, float p_Speed = 1.0f, int32 p_StartIndex = -1, int32 p_EndIndex = -1);
  Sprite *CreateSprite(const char *p_SpritePath);
  Node *DFingerAction(bool p_IsHideEffect, bool p_IsStopAction, int32 p_ActionTimes = 0, bool p_IsHideFinger= false);
  Label *DCreateWaveLabel(const GString &pText, Node *pParent, const RCreateWaveLabelParam &pParam);
};