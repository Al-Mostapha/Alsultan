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
    float height;
    float rheight;
    float width;
    float rwidth;
    float ocy;
    float iPhoneXOffset = 0;
    float iPhoneXBottom = 0;
    float iPadOffset = 0;
    float screenScale = 0;
    float contentScaleFactor = 0;
    Size realSize;
    Size sizeInPixels;
    Size size(){
      return Size(realSize.width - iPadOffset, realSize.height - iPhoneXOffset);
    }
    void AddSpriteFrames(
      const GString &p_PlistName, const GString &p_ImageName,
      const std::function<void()> &p_CallBack){
      SpriteFrameCache::getInstance()->addSpriteFramesWithFile(p_PlistName);
      p_CallBack();
    }
    DrawNode *NewPolygon(
      const GVector<Vec2> &p_Points,
      const RPolygonProps &p_Props = RPolygonProps(),
      DrawNode *p_DrawNode = nullptr);
};