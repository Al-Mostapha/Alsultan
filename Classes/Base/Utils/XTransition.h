#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class XTransition{
  public:
    static XTransition * Get();
    Action *Sequence_(const Vector<FiniteTimeAction *> &pActions);
    Action *PlayAnimationOnce(
      Node *pTarget, Animation *pAnimation, bool pIsRemoveSelf = false,
      const std::function<void()> & pOnComplete = nullptr, float pDelay = 0.0f);
    Action *PlayAnimationForever(Node *pTarget, Animation *pAnimation, float pDelay = 0.f);
};