#include "WorldMapProtectNode.h"
#include "Base/Base.create.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Utils/XTransition.h"


void WorldMapProtectNode::setVisible(bool pShow){
  if(pShow){
    if(!_Effect){
      _Effect = CreateEffect();
      this->addChild(_Effect);
    }
    if(_Effect){
      _Effect->resume();
    }
  } else if(_Effect){
    _Effect->pause();
  }
  Node::setVisible(pShow);
}

void WorldMapProtectNode::SetGreenColor(bool pIsGreen){
  if(!_Effect)
  return;
  auto lSpOutside = GBase::DGetChildByName<Sprite *>(_Effect, "dh_Texture_sstshd_001_9");
  auto lSpInside = GBase::DGetChildByName<Sprite *>(_Effect, "dh_Texture_XL_sstshd_000_02");
  if(pIsGreen){
    lSpOutside->setColor(Color3B(89, 167, 255));
    lSpInside->setColor(Color3B(30, 112, 240));
  }else{
    lSpOutside->setColor(Color3B(255, 255, 80));
    lSpInside->setColor(Color3B(255, 180, 76));
  }
}

Node *WorldMapProtectNode::CreateEffect(){
  if(_IsNew){
    return CreateEffectNodeNew();
  }else{
    auto lNode = CreateEffectNode();
    SetGreenColor(_IsGreen);
    return lNode;
  }
}

Node *WorldMapProtectNode::CreateEffectNode(){
  auto lEffect = GBase::DCreateAnimation("worldMapProtect");
  auto lSpOutside = GBase::DGetChildByName<Sprite *>(lEffect.First, "dh_Texture_sstshd_001_9");
  auto lSpInside = GBase::DGetChildByName<Sprite *>(lEffect.First, "dh_Texture_XL_sstshd_000_02");
  //   lWidget->setGroupID(WorldMapDefine::GROU_ID::group_protect_new);
  //   lWidget->setGroupID(WorldMapDefine::GROU_ID::group_protect_new);
  GBase::DMixtureGLONE(lSpOutside);
  GBase::DMixtureGLONE(lSpInside);
  return lEffect.First;
}

Node * WorldMapProtectNode::CreateEffectNodeNew(){
  auto lImageKey = "T_XL_Tex_xsbhz01_%03d.png";
  if(_IsGray){
    lImageKey = "T_XL_Tex_zcqcbhz01_%03d.png";
  }
  auto lSprite = GDisplay::Get()->NewSprite(StringUtils::format(lImageKey, 0).c_str());
  lSprite->setPosition(Vec2(0, 5));
  lSprite->setScale(1.76);
  auto lSpriteFrames = GDisplay::Get()->NewFrames(lImageKey, 0, 20);
  auto lAnimation = GDisplay::Get()->NewAnimation(lSpriteFrames, 0.08333333333333333);
  XTransition::Get()->PlayAnimationForever(lSprite, lAnimation);
  // sprite:setGroupID(worldMapDefine.GROU_ID.group_protect_new)
  return lSprite;
}


void WorldMapProtectNode::SetIsGray(bool pIsGray){
  if(_IsGray == pIsGray){
    return;
  }
  _IsGray = pIsGray;
  if(_Effect){
    _Effect->removeFromParent();
    _Effect = nullptr;
  }
}