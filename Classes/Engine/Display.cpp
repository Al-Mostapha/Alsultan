#include "Display.h"
#include "Device.h"
#include "cocos2d.h"
#define CONFIG_SCREEN_WIDTH 640
#define CONFIG_SCREEN_HEIGHT 960
#define CONFIG_SCREEN_AUTOSCALE "FIXED_WIDTH"

DrawNode* GDisplay::NewPolygon(const GVector<Vec2>& p_Points, const RPolygonProps& p_Props, DrawNode* p_DrawNode) {
  GVector<Vec2> l_Points;
  for (int32 i = 0; i < p_Points.size(); i++) {
    l_Points.push_back(Vec2(p_Points[i].x * p_Props.scale, p_Points[i].y * p_Props.scale));
  }
  if (!p_DrawNode) p_DrawNode = DrawNode::create();
  p_DrawNode->drawPolygon(l_Points.data(), l_Points.size(), p_Props.FillColor, p_Props.borderWidth, p_Props.BorderColor);
  return p_DrawNode;
}

void GDisplay::Init() {
  auto l_Director = Director::getInstance();
  auto l_GLView = l_Director->getOpenGLView();
  auto sizeInPixels = l_GLView->getFrameSize();
  auto l_W = sizeInPixels.width;
  auto l_H = sizeInPixels.height;
  auto l_CONFIG_SCREEN_WIDTH = CONFIG_SCREEN_WIDTH;
  auto l_CONFIG_SCREEN_HEIGHT = CONFIG_SCREEN_HEIGHT;
  iPadOffset = GDevice::Get()->IsIpadMode() ? 128 : 0;
  l_CONFIG_SCREEN_WIDTH += iPadOffset;
  auto l_CONFIG_SCREEN_AUTOSCALE = CONFIG_SCREEN_AUTOSCALE;
  if (l_W > l_H) {
    l_CONFIG_SCREEN_AUTOSCALE = "FIXED_HEIGHT";
  } else {
    l_CONFIG_SCREEN_AUTOSCALE = "FIXED_WIDTH";
  }
  float l_Scale, l_ScaleX, l_ScaleY;
  // if CONFIG_SCREEN_AUTOSCALE and CONFIG_SCREEN_AUTOSCALE ~= "NONE" then

  //   if CONFIG_SCREEN_AUTOSCALE == "FILL_ALL" then
  if (l_CONFIG_SCREEN_AUTOSCALE == "FILL_ALL") {
    l_CONFIG_SCREEN_WIDTH = l_W;
    l_CONFIG_SCREEN_HEIGHT = l_H;
    l_Scale = 1;
    l_GLView->setDesignResolutionSize(l_CONFIG_SCREEN_WIDTH, l_CONFIG_SCREEN_HEIGHT, ResolutionPolicy::NO_BORDER);
  } else {
    l_ScaleX = l_W / l_CONFIG_SCREEN_WIDTH;
    l_ScaleY = l_H / l_CONFIG_SCREEN_HEIGHT;
    if (l_CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH") {
      l_Scale = l_ScaleX;
      l_CONFIG_SCREEN_HEIGHT = l_H / l_Scale;
    } else if (l_CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT") {
      l_Scale = l_ScaleY;
      l_CONFIG_SCREEN_WIDTH = l_W / l_Scale;
    } else {
      l_Scale = 1;
    }
    l_GLView->setDesignResolutionSize(l_CONFIG_SCREEN_WIDTH, l_CONFIG_SCREEN_HEIGHT, ResolutionPolicy::NO_BORDER);
  }

  auto l_WinSize = l_Director->getWinSize();
  iPhoneXOffset = GDevice::Get()->IsIphoneXMode() ? 95 : 0;
  iPhoneXBottom = GDevice::Get()->IsIphoneXMode() ? 37 : 0;
  screenScale = 2;
  contentScaleFactor = screenScale;
  realSize = l_WinSize;
  width = size().width;
  height = size().height;
  rwidth = realSize.width;
  rheight = realSize.height;
  cx = width / 2;
  cy = height / 2 + iPhoneXBottom;
  rcy = realSize.height / 2;
  rcx = realSize.width / 2;
  ocy = height / 2;
  // display.c_left = -display.width / 2
  // display.c_right = display.width / 2
  // display.c_top = display.height / 2
  // display.c_bottom = -display.height / 2
  // display.left = 0

  // display.right = display.width
  // display.top = display.height
  // display.bottom = 0
  // display.widthInPixels = display.sizeInPixels.width
  // display.heightInPixels = display.sizeInPixels.height
  // printInfo(string.format("# CONFIG_SCREEN_AUTOSCALE      = %s", CONFIG_SCREEN_AUTOSCALE))
  // printInfo(string.format("# CONFIG_SCREEN_WIDTH          = %0.2f", CONFIG_SCREEN_WIDTH))
  // printInfo(string.format("# CONFIG_SCREEN_HEIGHT         = %0.2f", CONFIG_SCREEN_HEIGHT))
  // printInfo(string.format("# display.widthInPixels        = %0.2f", display.widthInPixels))
  // printInfo(string.format("# display.heightInPixels       = %0.2f", display.heightInPixels))
  // printInfo(string.format("# display.contentScaleFactor   = %0.2f", display.contentScaleFactor))
  // printInfo(string.format("# display.width                = %0.2f", display.width))
  // printInfo(string.format("# display.height               = %0.2f", display.height))
  // printInfo(string.format("# display.cx                   = %0.2f", display.cx))
  // printInfo(string.format("# display.cy                   = %0.2f", display.cy))
  // printInfo(string.format("# display.rcy                  = %0.2f", display.rcy))
  // printInfo(string.format("# display.ocy                  = %0.2f", display.ocy))
  // printInfo(string.format("# display.left                 = %0.2f", display.left))
  // printInfo(string.format("# display.right                = %0.2f", display.right))
  // printInfo(string.format("# display.top                  = %0.2f", display.top))
  // printInfo(string.format("# display.bottom               = %0.2f", display.bottom))
  // printInfo(string.format("# display.c_left               = %0.2f", display.c_left))
  // printInfo(string.format("# display.c_right              = %0.2f", display.c_right))
  // printInfo(string.format("# display.c_top                = %0.2f", display.c_top))
  // printInfo(string.format("# display.c_bottom             = %0.2f", display.c_bottom))
}

Sprite *GDisplay::NewSprite(const char *p_FileName){
  return Sprite::createWithSpriteFrameName(p_FileName);
}

ProgressTimer *GDisplay::NewProgressTimer(const char *p_Image, ProgressTimer::Type p_Type){
  auto l_Sprite = NewSprite(p_Image);
  auto l_Progress = ProgressTimer::create(l_Sprite);
  l_Progress->setType(p_Type);
  return l_Progress;
}

Label *GDisplay::NewBMFontLabel(RBMFontLabelParam p_Param){
  auto l_Label = Label::createWithBMFont(
    p_Param._Font, p_Param._Text, p_Param._TextAlign,
    p_Param._MaxLineW, p_Param._Offset);
  if(!l_Label) return nullptr;
  if (p_Param._Pos != Vec2::ZERO) {
    l_Label->setPosition(p_Param._Pos);
  }
  return l_Label;
}