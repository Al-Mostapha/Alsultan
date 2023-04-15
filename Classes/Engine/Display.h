#pragma once
#include "cocos2d.h"
#include "Include/IncludeBase.h"
USING_NS_CC;

struct RPolygonProps{
    Color4F FillColor{1,1,1,0};
    float borderWidth = 0.5;
    Color4F BorderColor{0,0,0,1};
    float scale = 1.0f;
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

  Sprite *NewSprite(const char *p_FileName);

  ProgressTimer *NewProgressTimer(const char *p_Image, ProgressTimer::Type p_Type);

};