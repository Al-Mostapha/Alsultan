#include "XTransition.h"

XTransition *XTransition::Get(){
  static XTransition * _XTransition = nullptr;
  if(_XTransition == nullptr){
    _XTransition = new XTransition();
  }
  return _XTransition;
}

Action *XTransition::Sequence_(const Vector<FiniteTimeAction *> &pActions){

  if(pActions.size() < 1){
    return nullptr;
  }
  if(pActions.size() == 1){
    return pActions.at(0);
  }
  auto lPrev = pActions.at(0);
  for(int32 i = 1; i < pActions.size(); i++){
    lPrev = Sequence::create(lPrev, pActions.at(i), nullptr);
  }
  return lPrev;
}

Action *XTransition::PlayAnimationOnce(Node *pTarget, Animation *pAnimation, bool pIsRemoveSelf, const std::function<void()> & pOnComplete, float pDelay){
  Vector<FiniteTimeAction*> lActions;
  if(pDelay > 0.0f){
    pTarget->setVisible(false);
    lActions.pushBack(DelayTime::create(pDelay));
    lActions.pushBack(Show::create());
  }
  lActions.pushBack(Animate::create(pAnimation));
  if(pIsRemoveSelf){
    lActions.pushBack(RemoveSelf::create());
  }
  if(pOnComplete){
    lActions.pushBack(CallFunc::create(pOnComplete));
  }

  Action *lAction = nullptr;
  if(lActions.size() > 1)
    lAction = Sequence_(lActions);
  else
    lAction = lActions.at(0);
  pTarget->runAction(lAction);
  return lAction;
}

Action *XTransition::PlayAnimationForever(Node *pTarget, Animation *pAnimation, float pDelay){
  auto lAnimate = Animate::create(pAnimation);
  Action *lAction = nullptr;
  if(pDelay > 0){
    pTarget->setVisible(false);
    auto lSequence = Sequence::create(
      DelayTime::create(pDelay),
      Show::create(),
      lAnimate,
      nullptr
    );
    lAction = RepeatForever::create(lSequence);
  }else{
    lAction = RepeatForever::create(lAnimate);
  }
  pTarget->runAction(lAction);
  return lAction;
}