#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
USING_NS_CC;

class MainScene;

struct RPolygonProps{
    Color4F FillColor{1,1,1,0};
    float borderWidth = 0.5;
    Color4F BorderColor{0,0,0,1};
    float scale = 1.0f;
};

struct RNewSpriteParam{
  GOpt<Size> _Size = Size::ZERO;
  GOpt<Rect> _CapInsets = Rect::ZERO;
};

struct UIFontLabelParam{
  GBase::EUILabelType _UILabelType = GBase::EUILabelType::TTF;
  GString _Text;
  GString _Font;
  TextHAlignment _TextAlign = TextHAlignment::LEFT;
  float _MaxLineW = 0;
  Vec2 _Offset = Vec2::ZERO;
  Vec2 _Pos = Vec2::ZERO;
  float _FontSize = 14;
  Color3B _Color = Color3B::WHITE;
};
class GDisplay
{
public:
    static GDisplay *Get(){
      static GDisplay *l_Instance = new GDisplay();

      l_Instance->height = 960;
      l_Instance->realSize = Director::getInstance()->getWinSize();
      l_Instance->rheight = Director::getInstance()->getWinSize().height;
      l_Instance->width = 640;
      l_Instance->rwidth = Director::getInstance()->getWinSize().width;
      l_Instance->cx = l_Instance->width/2;
      l_Instance->cy = l_Instance->height/2;
      l_Instance->rcx = l_Instance->rwidth/2;
      l_Instance->rcy = l_Instance->rheight/2;

      return l_Instance;
    }
    static Node *NewNode(){
      return Node::create();
    }
    void Init();
    float cx; // CenterX
    float cy;  //CenterY
    float rcy; //realCenterY
    float rcx; //realCenterY
    float height = 960;
    float rheight = Director::getInstance()->getWinSize().width;
    float width = 640;
    float rwidth = Director::getInstance()->getWinSize().width;
    float ocy;
    float iPhoneXOffset = 0;
    float iPhoneXBottom = 0;
    float iPadOffset = 0;
    float screenScale = 0;
    float contentScaleFactor = 0;
    Color3B COLOR_WHITE = Color3B(255, 255, 255);
    Color3B COLOR_BLACK = Color3B(0, 0, 0);
    Color3B COLOR_RED = Color3B(255, 0, 0);
    Color3B COLOR_GREEN = Color3B(0, 255, 0);
    Color3B COLOR_BLUE = Color3B(0, 0, 255);
    Color3B COLOR_YELLOW = Color3B(255, 255, 0);
    Size realSize;
    Size sizeInPixels;
    GString DefaultTTFFont = "Arial";
    float DefaultTTFFontSize = 24;
    Size size(){
      return Size(realSize.width - iPadOffset, realSize.height - iPhoneXOffset);
    }
    void AddSpriteFrames(
      const GString &p_PlistName, const GString &p_ImageName,
      const std::function<void()> &p_CallBack){
      SpriteFrameCache::getInstance()->addSpriteFramesWithFile(p_PlistName);
      p_CallBack();
    }
    void AddSpriteFrames(const GString &p_PlistName){
      SpriteFrameCache::getInstance()->addSpriteFramesWithFile(p_PlistName);
    }
    DrawNode *NewPolygon(
      const GVector<Vec2> &p_Points,
      const RPolygonProps &p_Props = RPolygonProps(),
      DrawNode *p_DrawNode = nullptr);
  template <typename T = Sprite>
  T *NewSprite(GVar<GString, SpriteFrame*, Texture2D *> pFile, GOpt<Vec2> pPos ={}, GOpt<RNewSpriteParam> pParam = {});
  ui::Scale9Sprite *NewScale9Sprite(const GString &p_FileName, Vec2 pPos, Size pSize, GOpt<Rect> pCapInsets = {});
  SpriteFrame *NewSpriteFrame(const char *p_FileName);

  ProgressTimer *NewProgressTimer(const char *p_Image, ProgressTimer::Type p_Type);
  template <typename T = Label>
  T *NewBMFontLabel(UIFontLabelParam);
  template <typename T = Label>
  T *NewTTFLabel(UIFontLabelParam);
  Vector<SpriteFrame *> NewFrames(const char *pPattern, uint32 pBegin, uint32 pLength, bool pIsReversed = false);
  Animation *NewAnimation(const Vector<SpriteFrame *> &pFrames, float pTime = -1);

  MainScene *GetRunningScene();

};

template <typename T>
T *GDisplay::NewBMFontLabel(UIFontLabelParam p_Param){
  return nullptr;
  // T *l_Label = T::createWithBMFont(
  //   p_Param._Font, p_Param._Text, p_Param._TextAlign,
  //   p_Param._MaxLineW, p_Param._Offset);
  // if(!l_Label) return nullptr;
  // if (p_Param._Pos != Vec2::ZERO) {
  //   l_Label->setPosition(p_Param._Pos);
  // }
  // return l_Label;
}

template <typename T>
T *GDisplay::NewTTFLabel(UIFontLabelParam pParam){
  return T::create();
}

template <typename T>
T *GDisplay::NewSprite(GVar<GString, SpriteFrame*, Texture2D *> pFile, GOpt<Vec2> pPos, GOpt<RNewSpriteParam> pParam){
  Size lSize;
  if(pParam){
    lSize = pParam->_Size.value();
  }
  T *lSprite = nullptr;
  if(pFile.index() == 0){ // String
    //   if string.byte(filename) == 35 then
    //     local frame = display.newSpriteFrame(string.sub(filename, 2))
    //     if frame then
    //       if params and params.capInsets then
    //         sprite = spriteClass:createWithSpriteFrame(frame, params.capInsets)
    //       else
    //         sprite = spriteClass:createWithSpriteFrame(frame)
    //       end
    //     end
    auto lFrame = GDisplay::Get()->NewSpriteFrame(std::get<GString>(pFile).c_str());
    if(lFrame){
      if(pParam && pParam->_CapInsets){
        lSprite = ui::Scale9Sprite::createWithSpriteFrame(lFrame, pParam->_CapInsets.value());
      }else{
        lSprite = T::createWithSpriteFrame(lFrame);
      }
    }
    //   elseif display.TEXTURES_PIXEL_FORMAT[filename] then
    //     cc.Texture2D:setDefaultAlphaPixelFormat(display.TEXTURES_PIXEL_FORMAT[filename])
    //     sprite = spriteClass:create(filename)
    //     cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2D_PIXEL_FORMAT_RGBA8888)
    //   elseif params and params.capInsets then
    //     sprite = spriteClass:create(params.capInsets, filename)
    //   else
    //     sprite = spriteClass:create(filename)
    //   end

  } else if(pFile.index() == 1){ // SpriteFrame
    lSprite = T::createWithSpriteFrame(std::get<SpriteFrame*>(pFile));
  } else if(pFile.index() == 2){ // Texture2D
    if constexpr (std::is_same_v<T, Sprite>){
      lSprite = T::createWithTexture(std::get<Texture2D*>(pFile));
    }else if constexpr (std::is_same_v<T, ui::Scale9Sprite>){
      lSprite = dynamic_cast<ui::Scale9Sprite *>(T::createWithTexture(std::get<Texture2D*>(pFile), pParam->_CapInsets.value()));
    }
  }else{
    lSprite = T::create();
  }
  if(lSprite){
    if(pPos){
      lSprite->setPosition(pPos.value());
    }
    if(pParam){
      if(pParam->_Size){
        lSprite->setContentSize(pParam->_Size.value());
      }
    }
  }else{
    lSprite = T::create();
  }
  return lSprite;
}