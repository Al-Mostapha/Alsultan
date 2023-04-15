#include "Base/Base.create.h"
#include "Module/Building/IBuilding.h"

ParticleSystemQuad* BaseCreate::createParticle(const std::string& Part, Vec2 Pos, Vec2 Scl, float rot) {
  auto Particle = ParticleSystemQuad::create(Part);
  Particle->setPosition(Pos.x, Pos.y);
  Particle->setScaleX(Scl.x);
  Particle->setScaleY(Scl.y);
  Particle->setRotation(rot);
  Particle->setPositionType(ParticleSystem::PositionType::RELATIVE);
  return Particle;
}
Sprite* BaseCreate::createAnimation(GAnimationParm AniPar) {
  /*auto frames = IBuilding::getAnimation(
      AniPar.AnimateData.Frame,
      AniPar.AnimateData.start,
      AniPar.AnimateData.end);
  /*auto sprite = Sprite::createWithSpriteFrame(frames.front());

  sprite->setPosition(AniPar.Pos);
  sprite->setScale(AniPar.Scale.x, AniPar.Scale.y);
  sprite->setRotation(AniPar.rot);
  sprite->setOpacity(AniPar.opacity);

  auto animation = Animation::createWithSpriteFrames(frames, AniPar.AnimateData.delay);

  sprite->runAction(RepeatForever::create(Animate::create(animation)));
  return sprite;*/
  return nullptr;
}

Vector<SpriteFrame*> BaseCreate::getAnimationFrames(GString Frame, int32 start, int32 end) {
  auto spritecache = SpriteFrameCache::getInstance();
  Vector<SpriteFrame*> animFrames;
  char str[100];
  for (int i = start; i <= end; i++) {
    sprintf(str, Frame.c_str(), i);
    animFrames.pushBack(spritecache->getSpriteFrameByName(str));
  }
  return animFrames;
}

Sprite* BaseCreate::CreateSprite(const char* p_Sprite) { return Sprite::createWithSpriteFrameName(p_Sprite); }

namespace GBase {
  GPair<Node*, Action*> DCreateAnimation(const char* p_FilePath, Node* p_Node, bool p_Loop) {
    if (!p_FilePath) return GPair<Node*, Action*>(nullptr, nullptr);
    if (p_FilePath == "") return GPair<Node*, Action*>(nullptr, nullptr);
    auto l_Action = CSLoader::createTimeline(p_FilePath);
    if (!p_Node) p_Node = CSLoader::createNode(p_FilePath);
    p_Node->runAction(l_Action);
    l_Action->gotoFrameAndPlay(0, p_Loop);
    return GPair<Node*, Action*>(p_Node, l_Action);
    ;
  }

  Sprite* CreateSprite(const char* p_SpritePath) { return Sprite::create(p_SpritePath); }

  GPair<Node*, Action*> DCreateAnimationEx(const char* p_FilePath, Node* p_Node, bool p_Loop, float p_Speed, int32 p_StartIndex, int32 p_EndIndex) {

    if (!p_FilePath) return GPair<Node*, Action*>(nullptr, nullptr);
    auto l_CssFilePath = p_FilePath;
    if (GBase::GetCCSPath(p_FilePath) != "") l_CssFilePath = GBase::GetCCSPath(p_FilePath).c_str();
    auto l_Action = CSLoader::createTimeline(l_CssFilePath);
    if (!p_Node) p_Node = CSLoader::createNode(l_CssFilePath);
    if (p_Speed != 1.0f) l_Action->setTimeSpeed(p_Speed);
    p_Node->runAction(l_Action);
    if (p_StartIndex != -1 && p_EndIndex != -1)
      l_Action->gotoFrameAndPlay(p_StartIndex, p_EndIndex, p_Loop);
    else
      l_Action->gotoFrameAndPlay(0, p_Loop);
    return GPair<Node*, Action*>(p_Node, l_Action);
  }

}  // namespace GBase



Node *GBase::DFingerAction(
  bool p_IsHideEffect, bool p_IsStopAction, 
  int32 p_ActionTimes, bool p_IsHideFinger
){
  auto l_Node =  GBase::DCreateAnimation("UiParts/Parts/Common/Animation/animationFinger.csb", nullptr, !p_IsStopAction).First;
  if(p_IsHideEffect)
    l_Node->getChildByName("Node_effect")->setVisible(false);
  if(p_IsHideFinger)
    l_Node->getChildByName("shouzhi")->setVisible(false);
  if(p_ActionTimes > 0){
    auto l_Seq = Sequence::create(
      DelayTime::create(p_ActionTimes * 95 / 60),
      CallFunc::create([l_Node](){
        l_Node->stopAllActions();
        l_Node->setVisible(false);
      }),
      nullptr
    );
    l_Node->runAction(l_Seq);
  }
  return l_Node;
}
