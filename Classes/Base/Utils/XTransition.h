#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Base/Type/XFunction.h"


class XTransition{
  public:
    static XTransition * Get();
    Action *Sequence_(const Vector<FiniteTimeAction *> &pActions);
    Action *PlayAnimationOnce(
      Node *pTarget, Animation *pAnimation, bool pIsRemoveSelf = false,
      const GFunc<void()> & pOnComplete = nullptr, float pDelay = 0.0f);
    Action *PlayAnimationForever(Node *pTarget, Animation *pAnimation, float pDelay = 0.f);
};