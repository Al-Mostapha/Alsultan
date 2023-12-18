#include "Module/Building/IBuilding.h"
#include "Base/Base.create.h"
#include "Engine/Display.h"

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
  GPair<Node*, XActionTimeLine*> DCreateAnimation(const char* p_FilePath, Node* p_Node, bool p_Loop) {
    if (!p_FilePath) return {nullptr, nullptr};
    if (p_FilePath == "") return {nullptr, nullptr};
    auto l_Action = CSLoader::createTimeline(p_FilePath);
    if (!p_Node) p_Node = CSLoader::createNode(p_FilePath);
    p_Node->runAction(l_Action);
    l_Action->gotoFrameAndPlay(0, p_Loop);
    return {p_Node, l_Action};
    ;
  }

  Sprite* CreateSprite(const char* p_SpritePath) { return Sprite::create(p_SpritePath); }

  GPair<Node*, XActionTimeLine*> DCreateAnimationEx(const char* p_FilePath, Node* p_Node, bool p_Loop, float p_Speed, int32 p_StartIndex, int32 p_EndIndex) {

    if (!p_FilePath) return {nullptr, nullptr};
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
    return {p_Node, l_Action};
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

Label *GBase::DCreateWaveLabel(const GString &pText, Node *pParent, const RCreateWaveLabelParam &pParam){
  GString lText = "NA";
  if(!pText.empty())
    lText = pText;
  UIFontLabelParam lParam;
  lParam._Text = lText;
  lParam._Color = pParam._Color;
  lParam._FontSize = pParam._FontSize;

  auto lWaveLabel = GDisplay::Get()->NewTTFLabel(lParam);
  pParent->addChild(lWaveLabel, pParam._ZOrder);
  lWaveLabel->setPosition(pParam._Pos);
  auto lMoveBy = MoveBy::create(pParam._Duration, Vec2(0, pParam._MoveH));
  
  auto lCallFunc = CallFunc::create([lWaveLabel](){
    lWaveLabel->removeFromParent();
  });
  
  auto lSeq = Sequence::create(
    {
      lMoveBy, 
      lCallFunc, 
    }
  );

  lWaveLabel->runAction(lSeq);
  return lWaveLabel;
}


Node* GBase::DCreateCSBNode(const char* p_CSBName) { return CSLoader::createNode(p_CSBName); }

Label* GBase::DCreateLabel(RCreateLabelParm p_Parm) {
  auto l_Text = p_Parm._Text;
  auto l_Font = p_Parm.FontName.empty() ? p_Parm.FontName : GDisplay::Get()->DefaultTTFFont;
  auto l_Size = p_Parm._FontSize = 0 ? p_Parm._FontSize : GDisplay::Get()->DefaultTTFFontSize;
  auto l_Color = p_Parm.Color != Color4B::WHITE ? p_Parm.Color : Color4B::WHITE;
  auto l_TextAlign = p_Parm.hAlignment != TextHAlignment::LEFT ? p_Parm.hAlignment : TextHAlignment::LEFT;
  auto l_TextValign = p_Parm.vAlignment != TextVAlignment::TOP ? p_Parm.vAlignment : TextVAlignment::TOP;
  auto l_X = p_Parm.x;
  auto l_Y = p_Parm.y;

  auto l_Label = Label::createWithSystemFont(l_Text, l_Font, l_Size, p_Parm.Dimensions, l_TextAlign, l_TextValign);
  if (l_Label) {
    l_Label->setColor(Color3B(l_Color));
    if (l_X && l_Y) {
      l_Label->setPosition(l_X, l_Y);
    }
  }
  return l_Label;
}

RenderTexture* GBase::DCreateScreenShot(bool p_IsBlur) {
  auto l_Width = GDisplay::Get()->size().width;
  auto l_Height = GDisplay::Get()->size().height;
  // TODO: 35056
  auto l_RenderTexture = RenderTexture::create((int32)l_Width, (int32)l_Height, Texture2D::PixelFormat::RGBA8888 /*,35056*/);
  // renderTexture:setKeepMatrix(true)
  l_RenderTexture->begin();
  l_RenderTexture->setKeepMatrix(true);
  // renderTexture:beginWithClear(0, 0, 0, 0, 1, 0)
  l_RenderTexture->beginWithClear(0, 0, 0, 0, 1, 0);
  // cc.Director:getInstance():getRunningScene():visit()
  Director::getInstance()->getRunningScene()->visit();
  // renderTexture:endToLua()
  l_RenderTexture->end();
  // renderTexture:setPosition(cc.p(display.cx, display.cy))
  l_RenderTexture->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
  // local renderSprite = renderTexture:getSprite()
  auto l_RenderSprite = l_RenderTexture->getSprite();
  // if isBlur then

  // end
  if (p_IsBlur) {
    //   local program = cc.GLProgram:createWithFilenames("Shaders/blur.vsh", "Shaders/blur.fsh")
    //   local state = cc.GLProgramState:create(program)
    //   state:setUniformVec2("resolution", {
    //     x = display.size.width,
    //     y = display.size.height
    //   })
    //   state:setUniformFloat("blurRadius", 20)
    //   state:setUniformFloat("sampleNum", 10)
    //   renderSprite:setGLProgramState(state)
    // auto l_State = GLProgramState::create(l_Program);
    // l_State->setUniformVec2("resolution", Vec2(GDisplay::Get()->size().width, GDisplay::Get()->size().height));
    // l_State->setUniformFloat("blurRadius", 20);
    // l_State->setUniformFloat("sampleNum", 10);
    // l_RenderSprite->setGLProgramState(l_State);
  }
  // return renderTexture
  return l_RenderTexture;
}
