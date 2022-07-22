#include "Base/Base.create.h"
#include "Module/Building/CityBuildingBase.h"

ParticleSystemQuad *BaseCreate::createParticle(const std::string &Part, Vec2 Pos, Vec2 Scl, float rot)
{
  auto Particle = ParticleSystemQuad::create(Part);
  Particle->setPosition(Pos.x, Pos.y);
  Particle->setScaleX(Scl.x);
  Particle->setScaleY(Scl.y);
  Particle->setRotation(rot);
  Particle->setPositionType(ParticleSystem::PositionType::RELATIVE);
  return Particle;
}
Sprite *BaseCreate::createAnimation(GAnimationParm AniPar)
{
  /*auto frames = CityBuildingBase::getAnimation(
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

Vector<SpriteFrame *> BaseCreate::getAnimationFrames(GString Frame, int32 start, int32 end)
{

    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame *> animFrames;
    char str[100];
    for (int i = start; i <= end; i++)
    {
        sprintf(str, Frame.c_str(), i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}
